int ba_renameattr(char relName[ATTR_SIZE], char oldName[ATTR_SIZE], char newName[ATTR_SIZE]){
	//search for the relation with name relName in relation catalog 
	relcat_recid = linear_search(RELCAT_RELID, "RelName", relName, EQ);
	
	if(relcat_recid == {-1,-1}){ //If relation with name relName does not exits
		return E_RELNOTEXIST;
	}
	
	//Iterate over all the attributes corresponding to the relation{
		//search for the attributes with relation name relName in attribute catalog 
		attrcat_recid = linear_search(ATTRCAT_RELID, "RelName", relName, EQ);
		
		//get the attribute catalog record from the attribute catalog (recid of the attribute catalog record = attrcat_recid)
		rec_buffer = Buffer::getRecBuffer(attrcat_recid.block);
		rec_buffer->getRecord(attrcat_record, attrcat_recid.slot);
		
		//get attrName from attrcat_record
		if(attrName == newName){ //if the attribute with name newName already exists
			return E_ATTREXIST;
		}	
	}
	//Iterate over all the attributes corresponding to the relation{
		//search for the attributes with relation name relName in attribute catalog 
		attrcat_recid = linear_search(ATTRCAT_RELID, "RelName", relName, EQ);
		
		//get the attribute catalog record from the attribute catalog (recid of the attribute record = attrcat_recid)
		rec_buffer = Buffer::getRecBuffer(attrcat_recid.block);
		rec_buffer->getRecord(attrcat_record, attrcat_recid.slot);
		
		//get attrName from attrcat_record
		if(attrName == oldName){ //if the attribute is attribute with oldName
			//update the attribute catalog record in the attribute catalog with attribute name newName
			rec_buffer->setRecord(attrcat_record, attrcat_recid.slot);
			return SUCCESS;
		}
	//}	
	return E_ATTRNOTEXIST;
}		 
