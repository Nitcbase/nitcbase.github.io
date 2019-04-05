class RecBuffer *getRecBlock(int block_num){
    /*iterate in buffer blocks to know if one of the blocks in buffer already contains a disk block,
     #block_num(you can use a helper function getbufferblock(#block_num) to know if buffer contains a disk block corresond
      to #block_num).
    */

	/* if buffer doesn't conain disk block #block_num, load it to buffer and do necessary initialisations in buffer meta info
    (one can use load(#block_num) as helper function in buffer class to load the disk block to one of the free block(blocks[i]) in 
    buffer and do necessary initialisations in buffer meta info)*/

    //if the block corresponding to #block_num is not a REC block return NULL

    class RecBuffer* newRecBuffer= new RecBuffer(block_num);

    // return the RecBuffer object pointer.
}