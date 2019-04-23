Blockbuffer::BlockBuffer(int block_num){
    // set the block_num field of this object to blk_no;
}

virtual BlockBuffer::~BlockBuffer(int blk_no){y
    //release the block corresponding to block_no from buffer calling releaseBlock() method of buffer class.
}

struct HeadInfo BlockBuffer::getheader(){
    /* get the data pointer(char *) corresponds to the block(of current object) from Buffer (a private function get_dataptr() 
    can be implemented and called for this purpose*/

    struct HeadInfo head;

    // fill the fields of head from the header of block to which object is corresponding to(using data pointer obtained).
    //NOTE: one can use type casting to copy different types of data in memory (here, char array is copied to struct HeadInfo)

	return head;
}

void BlockBuffer::setheader(struct HeadInfo head){
	/* get the data pointer(char *) corresponds to the block(of current object) from Buffer (a private function get_dataptr() 
    can be implemented and called for this purpose*/


	// fill the fields of the header of the block to which object is corresponding to, with head(use data pointer obtained).
    // use appropriate type casting to copy head to Header in block.

	return;
}