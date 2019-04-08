int insert(char relname[ATTR_SIZE], int nAttrs, char attr[][ATTR_SIZE]){

    // get the relation's open relation id(let it be rel_id), using getRelid() method of Openreltable
    // if relation is not opened in Openreltable, return E_RELNOTOPEN

    //get the no. of attributes present in relation, from RelcatEntry present in Openreltable(using getRelCatEntry() method).
    //if nAttrs!=no_of_attrs in relation, return E_NATTRMISMATCH

    // let attrval[nAttrs] be an array of type union Attribute

    /*iterate through 0:nAttrs :
        get the i'th attribute's AttrCatEntry (using getAttrcatEntry() of Openreltable )
        fill attrval array respectively.(using type of ith attribute found)
        if type of ith attribute mismatches converting from string(attr[i]) to corresponding type(ex:string to int ) return E_ATTRTYPEMISMATCH.
    */ 

    int retval= ba_insert(rel_id,attrval)

    //return retval        
}
