int ba_delete(char relName[ATTR_SIZE]){
	/* search for relation with name relName in relation catalog */
	relcat_recid = linear_search(RELCAT_RELID, "RelName", relName, EQ);
	
	if(relcat_recid == {-1,-1}){ //If relation with relName does not exits
		return E_RELNOTEXIST;
	}
	
	/*getting the relation catalog entry corresponding to relation with relName*/
	rec_buffer = Buffer::getRecBuffer(relcat_recid.block);
	rec_buffer->getRecord(relcat_rec, relcat_recid.slot);
	
	//get the first record block of the relation (first_block)
	//get the number of attributes corresponding to the relation (num_attrs)
	
	//Delete all the record blocks of the relation by getting the next record blocks (rblock) from header and by calling
	Buffer::deleteBlock(block_num);
	
	
	/*deleting index blocks corresponding to the the relation with relName and 
	attribute catalog entries corresponding the relation*/
	//Iterate over all the attributes corresponding to the relation{
		//search for all the attributes corresponding to the relation with relName in attribute catalog
		//delete the attribute catalog entry corresponding to the attribute from attribute catalog
		//Adjusting the number of entries in the block (decrease by 1) corresponding to the attribute catalog entry
	
		//get the root_block from attribute catalog 
		if(root_block != -1){ //index exists for the attribute
			bplus_destrot(root_block); //delete the index blocks corresponding to the attribute
		}
	//}
	
	//delete the relation catalog entry corresponding to the relation from relation catalog
	//Adjusting the number of entries in the block (decrease by 1) corresponding to the relation catalog entry
	
	//update relation catalog (i.e number of records in relation catalog is decreased by 1)
	//update attribute catalog (i.e number of records in attribute catalog is decreased by num_attrs)
	return SUCCESS;
}
