void releaseBlock(int block_num){
    // if block_num < 0 OR block_num >= DISK_BLOCKS return FAILURE

    /* iterate through buffer blocks to know if disk block #block_num is present in Buffer(getbufferblock(block_num) method call can
    be used for the same).*/

    //if buffer does not contain disk block #block_num return FAILURE

    // if the dirty field in metainfo of buffer block correspond to #block_num is set to true, commit the block back to disk.

    // free the buffer block correspond to #block_num in metainfo array.

    //return SUCCESS

}