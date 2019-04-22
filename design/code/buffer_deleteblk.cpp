void Buffer::deleteBlock(int block_num){
    // if block_num < 0 OR block_num >= DISK_BLOCKS return

    /* iterate through buffer blocks to know if disk block #block_num is present in Buffer(getbufferblock(block_num) method call can
    be used for the same).*/

    //if buffer does not contain disk block #block_num release the buffer block using releaseBlock(int block_num) method call

    //set the block_alloc_map array element correspond to block_num as UNUSED
}
