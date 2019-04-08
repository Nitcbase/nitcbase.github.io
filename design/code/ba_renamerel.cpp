int ba_renamerel(char oldName[ATTR_SIZE], char newName[ATTR_SIZE]){
	//search for the relation with name newName in relation catalog 
	relcat_recid = linear_search(RELCAT_RELID, "RelName", newName, EQ);
	if(relcat_recid != {-1,-1}){ //If relation with name newName already exits
		return E_RELEXIST;
	}
	
	//search for the relation with name oldName in relation catalog 
	relcat_recid = linear_search(RELCAT_RELID, "RelName", oldName, EQ);
	if(relcat_recid == {-1,-1}){ //If relation with name relName does not exits
		return E_RELNOTEXIST;
	}
	
	//get the relation catalog record from the relation catalog (recid of the relation catalog record = relcat_recid)
	rec_buffer = Buffer::getRecBuffer(relcat_recid.block);
	rec_buffer->getRecord(relcat_record, relcat_recid.slot);
	
	//update the relation catalog record in the relation catalog with relation name newName
	rec_buffer->setRecord(relcat_record, attrcat_recid.slot);
	
	/*update all the attribute catalog entries in the attribute catalog corresponding to the 
	  relation with relation name oldName to the relation name newName*/
	
	return SUCCESS;
}
