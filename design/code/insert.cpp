int insert(char relname[ATTR_SIZE], int nAttrs, char attr[][ATTR_SIZE]){

    // get the relation's open relation id, using getRelid() method of Openreltable
    // if relation not opened in open relation table, return FAILURE

    //get the no. of attributes present in relation, from RelcatEntry present in Openreltable(using getRelCatEntry() method).
    //if nAttrs!=no_of_attrs in relation, return FAILURE(unequal no.of attrs).

    // array union Attribute attrval[nAttrs]

    /*iterate through nAttrs:
        get the i'th AttributeCat entry (using getAttrcatEntry() of Openreltable )
        get the attribute type of i'th attribute.
        fill attrval array respectively.(using type of ith attribute found)
        if type of ith attribute mismatches converting from string(attr[i]) to corresponding type(ex:int, float) return FAILURE.
    */ 

    call ba_insert(relation_id,attrval)

    //if ba_insert fails return FAILURE(DISK_FULL)

    //return SUCCESS.        
}