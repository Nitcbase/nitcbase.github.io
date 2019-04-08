relId OpenRelTable::OpenRel(char relName[ATTR_SIZE]){
	//check if the relation with relation name relName already opened
	relid = OpenRelTable::getRelId(relName);
	if(relid != E_NOTOPEN){
		return relid;
	}
	
	//find the free slot in the relation cache
	//if free slot is not found in the relation cache
		return E_CACHEFULL;
	
	//search for the relation catalog entry with relation name relName in the relation catalog 
	relcat_recid = linear_search(RELCAT_RELID, "RelName", relName, EQ);
	if(relcat_recid == {-1, -1}){ //if relation is not found in the relation catalog
		return E_RELNOTEXIST;
	}
	
	//get the relation catalog entry with relation name relName from the relation catalog
	rec_buffer = Buffer::getRecBuffer(relcat_recid.block); //(recid of the relation record = relcat_recid)
	rec_buffer->getRecord(&relcat_entry, relcat_recid.slot); 
													    
	//update the free slot of the relation cache with the relation catalog entry (relac_entry)
	//update the corresponding meta information corresponding to the free slot in the relation cache
	
	//Iterate over all the attributes corresponding to the relation with relation name relName{
		//search for the attributes with relation name relName in the attribute catalog 
		attrcat_recid = linear_search(ATTRCAT_RELID, "RelName", relName, EQ);
		
		//get the attribute catalog record from the attribute catalog (recid of the attribute record = attrcat_recid)
		rec_buffer = Buffer::getRecBuffer(attrcat_recid.block);
		rec_buffer->getRecord(attrcat_record, attrcat_recid.slot);
		
		//since attribute cache is implemented as linked list, create separate new node of type Attribute Cache
		//update the new node of the attribute cache with the attribute catalog entry
		//update the corresponding meta information in the new node of the attribute cache
		//update Attribute Cache head in the relation cache as the new node
	//}
	
	return relid;
}
