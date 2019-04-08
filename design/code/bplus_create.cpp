int bplus_create(relId relid, char attrName[ATTR_SIZE]){
	/*get the root block from the attribute cache correponding to the
	  relation with Id relid and the attribute with attribute name attrName*/
	  
	if(root_block != -1){ //Index already exists for the attribute
		return SUCCESS;
	}
	
	//get the free leaf index for the root block
	leaf_buffer = Buffer::getFreeIndLeaf();
	if(leaf_buffer == NULL){ //disk is full (i.e unable to get new record block from the disk)
		return E_DISKFULL;
	}
	
	//get the root block number corresponding to the leaf_buffer (free leaf index) from the buffer
	root_block = leaf_buffer->getBlockNum();
	
	/*update the root block in the attribute cache correponding to the
	  relation with Id relid and the attribute with attribute name attrName*/
	  
	//Iterate over all the records of the relation with Id relid{
		//insert the index entries for each record in the bplus tree
		flag = bplus_insert(relid, attrName, attrval, recid); //where the recid is record id corresponding to the record
		if(flag == E_DISKFULL){ //unable to insert the record in bplus tree since disk is full
			//destroy all the index blocks created so far corresponding to the record
			bplus_destroy(root_block);
			return E_DISKFULL;
		}
	//}
	
	return SUCCESS;
}
