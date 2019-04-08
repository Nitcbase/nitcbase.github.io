int ba_search(relId relid, union Attribute *record, char attrName[ATTR_SIZE], union Attribute attrval, int op){
	/*get the attribute catalog entry from the attribute cache corresponding 
	  to the relation with Id relid and with attribute name attrName*/
	OpenRelTable::getAttrCatEntry(relid, attrName, &attrcat_entry);
	//get root_block from the attribute catalog entry (attrcat_entry)
	
	if(root_block == -1){ //if Index does not exist for the attribute
		if(op == RST){ //the op is reset
			//assign the previous record id (prev_recid) to {-1, -1}
			//update the previous record id (prev_recid) in the relation cache corresponding to the relation with Id relid
			OpenRelTable::setPrevRecId(relid, prev_recid);
			return SUCCESS;
		}
		
		//search for the record id (recid) correspoding to the attribute with attribute name attrName and with value attrval  
		recid = linear_search(relid, attrName, attrVal, op);
	}
	else{ //if Index exists for the attribute
		if(op == RST){ // the op is reset
			//assign the previous index id (prev_indexid) to {-1, -1}
			/*update the previous index id (prev_recid) in the attribute cache corresponding 
			  to the relation with Id relid and attribute name with attrName*/
			OpenRelTable::setSearchIndexId(relid, attrName, prev_indexid);
			return SUCCESS;
		}
		//search for the record id (recid) correspoding to the attribute with attribute name attrName and with value attrval
		recid = bplus_search(relid, attrName, attval, op);
	}
	
	if(recid == {-1, -1}){ //if it fails to find a record satisfying the given condition
		return E_NOTFOUND;
	}
	
	//copying the record with record id (recid) to the record (buffer)
	rec_buffer = Buffer::getRecBuffer(recid.block); //recid.block is the block that contains record
	rec_buffer->getRecord(record, recid.slot); //recid.slot is the slot that contains record
	
	return SUCCESS;
}
	
	ret
