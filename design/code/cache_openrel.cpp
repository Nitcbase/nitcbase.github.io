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
	
	//Iterate over all the attributes corresponding to the relation with relation name relName{
		//search for the attributes with relation name relName in the attribute catalog 
		attrcat_recid = linear_search(ATTRCAT_RELID, "RelName", relName, EQ);
		
		//get the attribute catalog record corresponding to attrcat_recid from the attribute catalog
		rec_buffer = Buffer::getRecBuffer(attrcat_recid.block);
		rec_buffer->getRecord(attrcat_record, attrcat_recid.slot);
		
		//since attribute cache is implemented as a linked list
		//For each attribute create separate new node of type Attribute Cache
		/*Convert the attribute catalog entry from the record structure
		  to the structure AttrCatEntry */
		new_node.attrcat_entry = RecordtoAttrCatEntry(record);
		//initialize the meta information of the attribute cache node
		initializeAttrCacheNode(new_node);
		//Add the node to the attribute cache linked list.
	//}
	AttrCacheEntry *attrlist_head = head of the linked list of Attribute Cache entries.

	//get the relation catalog entry with relation name relName from the relation catalog
	rec_buffer = Buffer::getRecBuffer(relcat_recid.block); //(recid of the relation record = relcat_recid)
	rec_buffer->getRecord(&relcat_entry, relcat_recid.slot); 
													    
	//initialize the meta information of the relation cache node
	initializeRelCacheNode(relid, attrlist_head);
	
	return relid;
}
