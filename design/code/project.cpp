
int project(char srcrel[ATTR_SIZE],char targetrel[ATTR_SIZE],int tar_nAttrs, char tar_attrs[][ATTR_SIZE]){
    // get the src relation's open relation id, using getRelid() method of Openreltable.
    // if source not opened in open relation table, return FAILURE

    //get the no. of attributes present in relation, from RelcatEntry present in Openreltable(using getRelCatEntry() method).
    //if tar_nAttrs > no_of_attrs in relation, return FAILURE(unequal no.of attrs).

    // array int attr_offset[tar_nAttrs] (attr_offset[i]=offset of i'th tar. rel's attribute in src rel's attributes)
    // array int attr_types[tar_nAttrs]

    /*iterate through nAttrs:
        get the AttributeCat entry (using getAttrcatEntry() of Openreltable) of attribute with name tar_attrs[i]
        fill the attr_offset,attr_types arrays of target relation from the corresonding Attribute catalog entries
    */

    // create target relation using createrel(targetrel,tar_nAttrs,tar_attrs,attr_types);
    // if create fails return FAILURE.

    //open targetrel(call to Openreltable)
    // if open fails return FAILURE(Openreltable full).

    /*
    while (1):
        var: union Attribute record[no_of_attrs_srcrel];
        if ba_search(srcrelid,record,attr,val,op=PROJ_op) returns SUCCESS:
            union Attribute proj_record[tar_nAttrs] (record which need to be inserted into target rel)
            fill proj_record with respect to attr_offset array from record of src rel.
            call ba_insert(targetrelid,proj_record);
            if(insert fails):
                close the target rel(call closerel() method of Openreltable)
                delete targetrelation by calling ba_delete(targetrel)
                return FAILURE(DISK_FULL)
        else: stop
    */

    // return SUCCESS.

}