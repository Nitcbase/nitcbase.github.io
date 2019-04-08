int OpenRelTable::CloseRel(relId relid){
	if(rel_id< 0 || rel_id>= MAXOPEN){	//check relation id (relid) lies in the range
		return E_OUTOFBOUND;
	}
	if(Rel_Table[relid].free){ //slot corresponding to the relid in the relation is free
		return E_NOTOPEN;
	}
	
	//Iterate over all the attributes in the attribute cache corresponding to the relation with Id relid{
		//if the attribute catalog entry is modified (i.e, dirty flag is set){
			//commit the attribute catalog entry in the attribute cache to the disk
			rec_buffer= Buffer::getRecBlock(block_num);	/*block_num corrsponding to the record of the attribute catalog entry
														  in the attribute catalog, we will get block_num from meta informatiom*/
			//copy the attribute catalog entry to the record
			buffer->setRecord(record, slot_num); //commit the attribute catalog entry in the attribute catalog
		//}
		//free the attribute catlog node in the attribute cache since attribute cache is organised as linked list
	//}
	
	//if the relation catalog entry in the relation cache corresponding to the relation with Id relid is modified{
		//commit the relation catalog entry to the disk
		rec_buffer= Buffer::getRecBlock(block_num);	/*block_num corrsponding to the record of the relatiom catalog entry
													  in the relation catalog, we will get the block_num from meta informatiom*/
		//copy the relation catalog entry to the record
		buffer->setRecord(record, slot_num); //commit the relation catalog entry in the relation catalog
	//}
	return SUCCESS;
}
