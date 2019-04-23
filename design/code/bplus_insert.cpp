int bplus_insert(int relid,char attrname[ATTR_SIZE],union Attribute val,recId rec_id){
    //get the AttrCatEntry of target attribute using getAttrCatEntry() of cache layer.
    //let root_block_num be the root_block of AttrCatEntry 
    //if root_block_num of target attribute is -1, return E_NOINDEX
    //let attr_type be int (storing type of AttrCatEntry)
    class IndBuffer *head=Buffer::getIndBlock(root_block_num);
    /* while head is not LEAF:
          let header be of type struct HeadInfo 
          update header with HeadInfo of head using getheader() method of blockbuffer class.
          
          let nEntries be no. of entries in head block(can be found from header)
          
          iterating through 0 to nEntries-1, to get the offset i, such that 'i' is the min. offset satisfying
          i'th entry value >= val  //helper function compare() can be used to compare two Union attribute values, based on attr_type.

          if no such offset is found:
              update root_block_num with value of rchild of nEntries-1'th(last) entry of head.
              free the head object
              head=Buffer::getIndBlock(root_block_num);
          else:
              update root_block_num with value of lchild of i'th entry of head.
              Delete head. (calls destructor)
              head=Buffer::getIndBlock(root_block_num);
    */

    //now head is the leaf block to which we need to insert Index into.
    
    /*let indexval be of type struct Index(Index which need to be inserted in to b+ tree)
    update indexval with as that of recid, val.*/

    //update header with HeadInfo of block pointed by head using getheader() method of blockbuffer class.
    //let nEntries be no. of entries in block pointing by head(can be found from header)

    //let indices[nEntries+1] be an array of type struct Index.

    //iterate through 0 to nEntries-1:
        //update the i'th entry of indices with ith entry in head, using head->getEntry() method.

    //do linear search on indices to know the position of val in leaf.
    //insert indexval appropriately into indices array.

    /*
    if nEntries!= 63 ( max. no of entries in leaf)
        //iterate through 0 to nEntries-1:
           //set the i'th entry of head with ith entry in indices array, using head->setEntry() method.

        update header.num_entries=nEntries+1
        set Headinfo of head with as that of header, using head->setheader() method.
        Delete head. (calls destructor)
        return SUCCESS.
    else:
        class IndBuffer* new_blk=Buffer::getFreeIndLeaf();
        let newblkheader be of type struct HeadInfo 
        update newblkheader with HeadInfo of new_blk using getheader() method of blockbuffer class.

        iterate through 0 to 31:
            set first 32 entries of indices in to 32 entries of head,
            set next 32 entries of indices in to 32 entries of new_blk
        
        let par_block(int) be the pblock in header.
        
        update header.num_entries=32
        set Headinfo of head with as that of header, using head->setheader() method.

        update newblkheader.num_entries=32, newblkheader.pblock=par_block
        set Headinfo of new_blk with as that of newblkheader, using new_blk->setheader() method.

        let new_attrval be of type union Attribute. (which need to be inserted in to parent)
        update new_attrval with attrval of indices[31] (i.e 32nd entry)

        delete head;
        delete new_blk; // delete calls destructor.
        
        int child_block=root_block_num;

        // let done be a bool with value false.
        while(!done):
            if par_block!=-1
                class IndBuffer *parblk=Buffer::getIndBlock(par_block);
                let parheader be of type struct HeadInfo 
                update parheader with HeadInfo of head using getheader() method of blockbuffer class.

                struct InternalEntries internal_entries[parheader.num_entries+1];
                //iterate through 0 to parheader.num_entries-1:
                    //update the i'th entry of internal_entries with ith entry in parblk, using parblk->getEntry() method.


                get the offset of head in par_block, iterating through the internal_entries of par_block (by checking the entry which contain lblock as child_block)
                let tar_ind (int) be the offset of child_block.

                iterating iter from parheader.num_entries to tar_ind+1 (in decreamenting order):
                    internal_entries[iter]=internal_entries[iter-1];
                
                //update the internal_entries[tar_ind] with lchild:child_block,rchild:new_blocknum,attrval=new_attrval
                (update the rchild,lchild of entries adjacent to tar_ind approriately).

                if(parheader.num_entries!=100) //par_block not full
                    update the InternalEntries in parblk with as that of internal_entries array.(using setEntry() of IndBuffer class)
                    update parheader accordingly and copy this to parblk HeadInfo (using parblk->setheader() method of blockbuffer class.
                    delete parblk
                    done=true;
                else
                    class IndBuffer* new_blk=Buffer::getFreeIndInternal();
                    newblkheader=new_blk->getheader();
                    new_blocknum=new_blk->getblocknum();
                    
                    iterating through 0 to 50:
                        update parblk,bew_blk such that first 50 entries of internal_entries get into parblk, next 50 into new_blk
                        (use setEntry() of IndBuffer class)
                    update parheader,newblkheader appropriately
                    update HeadInfo of parblk,new_blk with parheader,newblkheader using setHeader() of BlockBuffer class.
                    iterating through 2nd 50 entries of internal_entries
                        update pblock field(in Header) of all child blocks with new_blocknum
                        (load each child using Buffer::getIndBlock(childblock), update HeadInfo of each block using setHeader() of BlockBuffer class)
                    
                    delete parblk,delete new_blk;
                    child_block=par_block,par_block=parheader.pblock;
                    new_attrval=internal_entries[50].attrval;
            else //if par_block==-1
                class IndBuffer* new_head=Buffer::getFreeIndInternal(); //if fails..delete indexing
                struct HeadInfo newhead_header=new_blk->getheader();
                int new_hblk_num=new_head->getblocknum();

                add only entry to new_head with lblock:child_block, rblock:new_blocknum, attrval:new_attrval
                update Headinfo of new_head appropriately (using setheader() of blockBufferclass)
                similarly update headers of child_block, new_blocknum with pblock=new_hblk_num

                get the attribute catalog entry of attribute attr_name(using OpenRelTable::getAttrCatEntry(relid,attr_offset,&attrib_cat))
                update root_block of AttrCatEntry with new_hblk_num
                set the attribute catalog entry of attribute attr_name(using OpenRelTable::getAttrCatEntry(relid,attr_offset,&attrib_cat)) with updated one.

                delete new_head;
                done=true;
    */
   return SUCCESS;
}