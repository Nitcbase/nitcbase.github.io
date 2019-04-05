static class RecBuffer *getFreeRecBlock(){

    // search for the free block in disk iterating through block_alloc_map array.

    //if no disk block is free return NULL

    //get the free buffer block (you can use a helper function like getfreebuffer() in bufferclass)

    //if no free buffer block in memory return NULL

    //update the metainfo array corresponding to free buffer. block_alloc_map correspoding to free disk block.

    class RecBuffer* newRecBuffer= new RecBuffer(disk_free_block); //disk_free_block is the free disk block obtained from block_alloc_map.

    // return the RecBuffer object pointer.
}