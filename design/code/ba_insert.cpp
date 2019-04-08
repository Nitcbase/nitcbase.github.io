int ba_insert(relId relid, union Attribute *record){
	//get the relaction catalog entry from relation cache
	OpenRelTable::getRelCatEntry(relid, &relcat_entry);
	
	//get the free slot from the existing record blocks of the relation with Id relid
	if(no free slot is found in existing record blocks){
		//get the new record block and free slot of the new record from disk by calling
		rec_buffer = Buffer::getFreeRecBuffer();
		if(rec_buffer == NULL){ //disk is full (i.e unable to get new record block from the disk)
			return E_DISKFULL;
		}
		//Update the header of the new record block such that it links with existing record blocks of the relation 
	} 
	
	//insert the record into free slot by calling
	rec_buffer = Buffer::getRecBuffer(block); //block corresponds to the free slot
	rec_buffer->setRecord(record,free_slot);
	//update the slotmap of the block (contains free slot)
	
	//update the header (i.e num_entries) of the block (contains free slot) by increasing the number of entries by 1
	//update the number of records (i.e increased by 1) corresponding to the relation with Id relid in relation cache
	
	//Iterate over all the attributes corresponding to the relation with Id relid{
		//get the attribute catalog entry for the attribute from attribute cache
		OpenRelTable::getAttrCatEntry(relid, attr_offset, &attrcat_entry);
		//get the root block from the attribute catalog entry
		if(root_block != -1){ //if index exists for the attribute
			bplus_insert(relid, attrcat_entry.attrName, attrval, recid); //where recid is the recid where record
																		 //is inserted in record block
		}
	//}
	
	return SUCCESS;
}
