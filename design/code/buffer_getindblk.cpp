class IndBuffer* Buffer::getIndBlock(int block_num){
    /*iterate in buffer blocks to know if one of the blocks in buffer already contains a disk block,
     #block_num(you can use a helper function getbufferblock(#block_num) to know if buffer contains a disk block corresond
      to #block_num).
    */

	/* if buffer doesn't conain disk block #block_num, load it to buffer and do necessary initialisations in buffer meta info
    (one can use load(#block_num) as helper function in buffer class to load the disk block to one of the free block(blocks[i]) in 
    buffer and do necessary initialisations in buffer meta info)*/
    //let buffer_block be the offset(block) in buffer to which disk block is loaded.

    // let int blk_type = getblocktype(buffer_block) /* a helper function getblocktype(buffer_block) can be used to know block type, by accessing header                                                     of block from buffer*/

    if(blk_type==IND_INTERNAL){
			class IndBuffer* newIndBuffer= new IndInternal(block_num);
			return newIndBuffer;
		}else if(blk_type==IND_LEAF){
			class IndBuffer* newIndBuffer= new IndLeaf(block_num);
			return newIndBuffer;
		}else{
			return NULL; //returns NULL if block found to be other than internal or leaf block(i.e recblock)
		}

    //if the block corresponding to #block_num is not a INDLEAF/INDINTERNAL block return NULL

    class IndBuffer* newIndBuffer= new IndBuffer(block_num);

    // return the IndBuffer object pointer.
}