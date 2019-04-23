Buffer::~Buffer(){
    // copy all block_alloc_map blocks from buffer disk to(using writeblock() of disk)

    /*iterate through all the buffer blocks, blocks with meta info as free:false,dirty:true
        should be commited/written back to disk(using writeblock() of disk)*/
}