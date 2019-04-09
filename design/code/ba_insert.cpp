int ba_insert(int relid, union Attribute *record){
	//get the relaction catalog entry from relation cache
	RelCatEntry relcat_entry;
	OpenRelTable::getRelCatEntry(relid, &relcat_entry);
	
	//get a free slot from the existing record blocks of the relation with Id=relid
	//This can be done by performing a linear search on the linked list of records and checking slotmap.

	if(no free slot is found in existing record blocks){
		//get a new record block and free slot of the new record  from disk by calling
		rec_buffer = Buffer::getFreeRecBuffer();
		if(rec_buffer == NULL){ //disk is full (i.e unable to get new record block from the disk)
			return E_DISKFULL;
		}
		//Update the header of the new record block such that it links with existing record blocks of the relation 
	} 
	
	// The next action is to get the pointer to the RecBuffer object containing the free slot
	// and store it into rec_buffer using getRecBuffer() method of the class Buffer.
	//Insert the record into the free slot by calling
	rec_buffer->setRecord(record,free_slot);

	//update the slotmap of the block (contains free slot)
	
	//update the num_entries field in the header of the block (to which record was inserted) by increasing the number of entries by 1
	//Incremet the number of records in the relation cache entry for the relation.
	
	//Iterate over all the attributes of the relation{
		//get the attribute catalog entry for the attribute from the attribute cache
		AttrCatEntry attrcat_entry;
		OpenRelTable::getAttrCatEntry(relid, attr_offset, &attrcat_entry);
		//get the root block from the attribute catalog entry
		if(root_block != -1){ //if index exists for the attribute
			bplus_insert(relid, attrcat_entry.attrName, attrval, recid); 
			       //where recid specifies the block# and slot# of the newly inserted record.
		}
	//}
	
	return SUCCESS;
}
