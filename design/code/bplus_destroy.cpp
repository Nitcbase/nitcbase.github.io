int bplus_destroy(int block_num){
	//all the index blocks are deleted recursively
	
	if(block_num < 0 || block_num >= DISK_BLOCKS){ //if the block_num is invalid
		E_OUTOFBOUND;
	}
	
	//get the block_type from header of the block
	if(block_type != INDINT || block_type != INDLEAF){ //if the block is not index block
		return E_INVALIDBLOCK;
	}
	
	if(block_type == INDLEAF){ //if the block is leaf index block
		//delete the block from the disk
	}
	else if(block_type == INDINT){ 	//if the block is internal index block
		//iterate over all the internal index entries{
			//delete all the child index blocks corresponding to each internal index block by calling
			bplus_destroy(child_block);
		//}
	}	
	
	return SUCCESS;
}
