int join(char srcrel1[ATTR_SIZE],char srcrel2[ATTR_SIZE],char targetrel[ATTR_SIZE], char attr1[ATTR_SIZE], char attr2[ATTR_SIZE]){
	
    // get the srcrel1's open relation id(let it be srcrelid1), using getRelid() method of Openreltable in cache layer
    // if srcrel1 is not opened in open relation table, return E_RELNOTOPEN

	// get the srcrel2's open relation id(let it be srcrelid2), using getRelid() method of Openreltable in cache layer
    // if srcrel2 is not opened in open relation table, return E_RELNOTOPEN
    
    //get the AttrCatEntry of attr1 in rel1 and attr2 in rel2 using getAttrCatEntry() method of Openreltable in cache layer.
    
    // if attr1 is not present in rel1 or attr2 not present in rel2 (failure of call to Openreltable) return E_ATTRNOTEXIST.
    
    // if attr1 and attr2 are of different types return E_ATTRTYPEMISMATCH
    
    // let nAttrs1 = no_of_attrs in rel1 ( can be found using getrelcatEntry() of Openreltable in cache layer).
    // let nAttrs2 = no_of_attrs in rel1 ( can be found using getrelcatEntry() of Openreltable in cache layer). 
    
    //Next step ensures that an index exists for atleast one of the relations
    /* if both the attributes of src rels have B+ tree:
    	  if rel1 has more records than rel2 swap srcrel1, srcrel2(swap srcrelname, relid, target attribute names)  
    	else if none of target attrs has bplus tree:
    	  if rel1 has more records than rel2 swap srcrel1, srcrel2(swap srcrelname, relid, target attribute names)
    	  create bplus tree on attr2 in rel2 (using create_bplus() method of bplus layer)
          If create fails return E_DISKFULL
    */
    
    //let tar_attrs[nAttrs1+nAttrs2-1][ATTR_SIZE] be an array of type char
    //let tar_attrtypes[nAttrs1+nAttrs2-1] be an array of type int
    //Note: The target relation has number of attributes less than nAttrs1+nAttrs2 (Why?)
    
    /* iterate through all the attributes in both the source rels and update tar_attrs[],tar_attrtype[] arrays (except for attr2 in srcrel2),
     by getting attribute catalog of each attribute from Openreltable(using method getattrcat() in cache layer) */  
       
	// retval= createrel(targetrel,nAttrs1+nAttrs2-1,tar_attrs,tar_attrtypes);
    // where createrel is a function in schema layer
    // if create fails return retval
    
    //int targetrelid = openRel(targetrel) 
    //where openRel is a function in schema layer
    /* if open fails
        delete targetrelation by calling deleterel(targetrel) of schema layer
        return error value targetrelid
    */
    
    //var: Union Attribute rec1[nAttrs1]
    /* while ba_search(srcrelid1,rec1, ,oper=PROJ, no_val) returns success:
    		var: union Attribute Record[nAttrs2]
     		while ba_search(srcrelid2,Record, attr2, oper=EQ, rel1 record's attr1 value) returns SUCCESS:
     			 var: union Attribute tar_record[nAttrs1+nAttrs2-1]
     			 copy the rel1's, rel2's record to tar_record[] (except for attr2 offset in rel2)
     			 call ba_insert(targetrelid,tar_record);
     			 if insert fails:
                    close the targetrel(by calling closeRel(targetrel) method of schema layer)
                    delete targetrel(by calling deleterel(targetrel) of schema layer)
                    return E_DISKFULL
     		
     */

    //close the target relation by calling closeRel() of schema layer.
     //return SUCCESS;
    
}
