void RecBuffer::getRecord(union Attribute *rec,int slot_num){ 
    /* get the data pointer(chat *) corresponds to the block(of current object) from Buffer (a private function get_dataptr() 
    can be implemented and called for this purpose*/

    // get number of attributes(in corresponding relation) from the block.(obtained directly from correspoding offset in block)
    // get number of slots from the block, which is present header.

    // if slotnum is out of size of slot map or slot corresponding to slot_num is free return FAILURE

    // copy the memory contents of slot_num'th record block to memory pointing by rec.

    // return SUCCESS
	
}