int OpenRelTable::CloseRel(relId relid){

	if(rel_id< 0 || rel_id>= MAXOPEN){	//check whether relation id (relid) lies in the range
		return E_OUTOFBOUND;
	}
	if(Rel_Table[relid].free){ //slot corresponding to the relid in the relation is free
		return E_NOTOPEN;
	}
	
	//Iterate over all the attributes in the attribute cache of the relation{
		//if the attribute catalog entry is modified (i.e, dirty flag is set){
			//The following code commits the attribute catalog entry into the disk
			/*We can extract the (block_num, slot_num) of the attribute catalog entry
			using meta information in the attribute cache*/
			rec_buffer= Buffer::getRecBlock(block_num);	

			/*Convert the cached attribute catalog entry from the structure AttrCatEntry 
			  to the format of the record structure*/
			record = AttrCatEntrytoRecord(attrcat_entry);

			//commit the attribute catalog entry to the disk(buffer)
			rec_buffer->setRecord(record, slot_num); 
		//}
		//free the attribute catlog node in the attribute cache linked list
	//}
	
	//if the relation catalog entry in the relation cache of the relation is modified{
		//commit the relation catalog entry to the disk
		/*We can extract the (block_num, slot_num) of the relation catalog entry
		  using meta information in the relation cache*/
		rec_buffer= Buffer::getRecBlock(block_num);	

		/*Convert the cached relation catalog entry from the structure RelCatEntry 
		  to the format of the record structure*/
		record = RelCatEntrytoRecord(relcat_entry);

		//commit the relation catalog entry to the disk(buffer)
		buffer->setRecord(record, slot_num); 
	//}
	return SUCCESS;
}
