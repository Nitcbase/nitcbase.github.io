int bplus_insert(union Attribute val,recId rec_id, int relid, int attr_offset){

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
              let child_block be value of rchild of nEntries-1'th entry of head.
              free the head object
              head=Buffer::getIndBlock(child_block);
          else:
              let child_blk be value of lchild of i'th entry of head.
              Delete head. (calls destructor)
              head=Buffer::getIndBlock(child_block);
    */

    //now head is the leaf block to which we need to insert Index into.
    
    /*let indexval be of type struct Index(Index which need to be inserted in to b+ tree)
    update indexval with as that of recid, val.*/

    //let header be of type struct HeadInfo 
    //update header with HeadInfo of block pointed by head using getheader() method of blockbuffer class.
    //let nEntries be no. of entries in head block(can be found from header)

    //let indices[nEntries+1] be an array of type struct Index.

    //iterate through 0 to nEntries-1:
        //update the i'th entry of indices with ith entry in head, using head->getEntry() method.

    //do linear search on indices to know the position of val in leaf.
    //insert indexval appropriately into indices array.

    /*
    if nEntries!= 63 ( max. no of entries in leaf)
        //iterate through 0 to nEntries-1:
           //set the i'th entry of head with ith entry in indices arrary, using head->setEntry() method.

        update header.num_entries=nEntries+1
        set Headinfo of head with as that of header, using head->setheader() method.
        Delete head. (calls destructor)
        return SUCCESS.
    else:
        class IndBuffer* new_blk=Buffer::getFreeIndInternal();
        let newblkheader be of type struct HeadInfo 
        update newblkheader with HeadInfo of new_blk using getheader() method of blockbuffer class.

        iterate through 0 to 31:
            set first 32 entries of indices in to 32 entries of head,
            set next 32 entries of indices in to 32 entries of new_blk
        
        let par_block be the pblock in header.

        update newblkheader.num_entries=32
        set Headinfo of head with as that of header, using head->setheader() method.

        update header.num_entries=32, header.pblock=par_block
        set Headinfo of new_blk with as that of header, using new_blk->setheader() method.

        let new_attrval be of type union Attribute. (which need to be inserted in to parent)
        update new_attrval with attrval of indices[31] (i.e 32nd entry)

        // let done be a bool with value false.
        while(!done):
            get the offset of head in par_block, iterating through the entries of par_block
            if i is the offset of head in parent block,
    

    
    */

    


    struct Index indexval;
    indexval.attrval=val;
    indexval.block=rec_id.block;
    indexval.slot=rec_id.slot;
    if(root_block==-1){
        return FAILURE;
    }

    class IndBuffer *head=Buffer::getIndBlock(root_block);
    struct HeadInfo header=head->getheader();

    if(header.block_type==IND_INTERNAL){
        int nEntries=header.num_entries;
        int child_head;

        struct InternalEntry elem;
        int getter;
        getter=head->getEntry((void *)(&elem),0);
        
        
        int iter;
        for(iter=0;iter<nEntries;iter++){
            getter=head->getEntry((void *)(&elem),iter);
            int compare_val1=compareAttr(indexval.attrval,elem.attrval,type_attr);
            if(compare_val1<=1){
                child_head=elem.lchild;
                break;
            }

        }
        if(iter==nEntries){
            child_head=elem.rchild;
        }
        
        bplus_insert(child_head,val,rec_id,type_attr,relid,attr_offset);

    }else{
        int nEntries=header.num_entries;
        bool success = false;
        int getter,setter;
        if(nEntries!=63){
            struct Index elem;
            int iter;
            for(iter=0;iter<nEntries;iter++){
                getter=head->getEntry((void *)(&elem),iter);
                int compare_val=compareAttr(indexval.attrval,elem.attrval,type_attr);
                if(compare_val<=1){
                    break;
                }
            }
            int ind=iter;
            for(iter=nEntries;iter>ind;iter--){
                getter=head->getEntry((void *)(&elem),iter-1);
                setter=head->setEntry((void *)(&elem),iter);
            }

            setter=head->setEntry((void *)(&indexval),ind);
            header.num_entries=nEntries+1;
            head->setheader(header);
            success=true;
        }else{
            int par_block=header.pblock;
            struct Index attrs[nEntries+1];
            int iter;
            int ind;

            struct Index elem;
            for(iter=0;iter<nEntries;iter++){
                getter=head->getEntry((void *)(&elem),iter);
                int compare_val=compareAttr(indexval.attrval,elem.attrval,type_attr);
                if(compare_val==0||compare_val==2){
                    ind=iter;
                }
                attrs[iter]=elem;
            }
            ind++;
            for(iter=nEntries;iter>ind;iter--){
                attrs[iter]=attrs[iter-1];
            }
            attrs[ind]=indexval;

            class IndBuffer* new_blk=Buffer::getFreeIndInternal();
            struct HeadInfo newblkheader=new_blk->getheader();

            for(iter=0;iter<32;iter++){
                setter=head->setEntry((void *)(&attrs[iter]),iter);
                setter=new_blk->setEntry((void *)(&attrs[iter]),32+iter);
            }
            union Attribute new_attrval;
            new_attrval=attrs[31].attrval;
            header.num_entries=32;
            newblkheader.num_entries=32;
            newblkheader.pblock=par_block;
            newblkheader.rblock=header.rblock; // change lblock of header.rblock as well if not -1
            newblkheader.lblock=root_block;
            header.rblock=new_blk->getblocknum();
            class IndBuffer *right_blk=Buffer::getIndBlock(newblkheader.rblock);
            struct HeadInfo rblk_header=right_blk->getheader();
            rblk_header.lblock=new_blk->getblocknum();
            right_blk->setheader(rblk_header);
            delete right_blk;

            
            head->setheader(header);
            new_blk->setheader(newblkheader);
            int new_blocknum=new_blk->getblocknum();
            int child_block=root_block;

            delete new_blk;

            while(success==false){
                if(par_block!=-1){
                    class IndBuffer *parblk=Buffer::getIndBlock(par_block);
                    struct HeadInfo parheader=parblk->getheader();
                    
                    struct InternalEntry internal_entries[parheader.num_entries+1];
                    int iter;
                    int tar_ind=parheader.num_entries;

                    for(iter=0;iter<parheader.num_entries;iter++){
                        getter=head->getEntry((void *)(&internal_entries[iter]),iter);//internal_entries[iter]=parblk->getInternalEntry(iter);
                        if(internal_entries[iter].lchild==child_block){
                            tar_ind=iter;
                        }
                    }
                    for(iter=parheader.num_entries;iter>tar_ind;iter++){
                        internal_entries[iter]=internal_entries[iter-1];
                    }
                    internal_entries[tar_ind].attrval=new_attrval;
                    internal_entries[tar_ind].lchild=child_block;
                    internal_entries[tar_ind].rchild=new_blocknum;

                    if(tar_ind!=parheader.num_entries){
                        internal_entries[tar_ind+1].lchild=internal_entries[tar_ind].rchild;
                    }

                    if(parheader.num_entries!=100){
                        for(iter=0;iter<=parheader.num_entries;iter++){
                            setter=parblk->setEntry((void *)(&internal_entries[iter]),iter);//parblk->setInternalEntry(internal_entries[iter],iter);
                        }
                        parheader.num_entries=parheader.num_entries+1;
                        parblk->setheader(parheader);
                        newblkheader.pblock=par_block;  //might have to change this line to load new_blocknum or even might not need this.
                        new_blk->setheader(newblkheader);
                        success=true;
                        
                        delete parblk;
                    }else{
                        class IndBuffer* new_blk=Buffer::getFreeIndInternal();
                        newblkheader=new_blk->getheader();

                        for(iter=0;iter<50;iter++){
                            setter=parblk->setEntry((void *)(&internal_entries[iter]),iter);//parblk->setattrval(internal_entries[iter],iter);
                            setter=new_blk->setEntry((void *)(&internal_entries[51+iter]),iter);//new_blk->setattrval(internal_entries[51+iter],iter);
                        }
                        parheader.num_entries=50;
                        newblkheader.num_entries=50;
                        //newblkheader.pblock=parheader.pblock;
                        parblk->setheader(parheader);
                        new_blk->setheader(newblkheader);
                        new_blocknum=new_blk->getblocknum();
                        //set the pblock of all childs appropriately
                        for(iter=0;iter<newblkheader.num_entries;iter++){
                            setparent(internal_entries[iter].lchild,new_blocknum);
                        }
                        setparent(internal_entries[newblkheader.num_entries-1].rchild,new_blocknum);

                        child_block=par_block;
                        par_block=parheader.pblock;
                        struct InternalEntry internalval;
                        new_attrval=internal_entries[50].attrval;
                        //close parblk
                        delete parblk;
                        delete new_blk;
                    }


                }else{
                    //get new internal block 
                    class IndBuffer* new_head=Buffer::getFreeIndInternal();
                    struct HeadInfo newhead_header=new_blk->getheader();

                    struct InternalEntry internalval;
                    internalval.attrval=new_attrval;
                    internalval.lchild=child_block;
                    internalval.rchild=new_blocknum;
                    new_head->setEntry((void *)&internalval,0);

                    newhead_header.pblock=-1;
                    newhead_header.num_entries=1;
                    new_head->setheader(newhead_header);

                    //update head of respective cache element
                    AttrCatEntry attrib_cat;
                    int flag= OpenRelTable::getAttrCatEntry(relid,attr_offset,&attrib_cat);
                    attrib_cat.root_block=new_head->getblocknum();
                    int flag= OpenRelTable::setAttrCatEntry(relid,attr_offset,&attrib_cat);
                    
                    //update par of both rblock and lblock
                    setparent(child_block,new_head->getblocknum());
                    setparent(new_blocknum,new_head->getblocknum());

                    delete new_head;
                    success=true;
                }
            }

        }

        
    }
    delete head;
    return SUCCESS;
}