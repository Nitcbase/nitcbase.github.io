
int project(char srcrel[ATTR_SIZE],char targetrel[ATTR_SIZE],int tar_nAttrs, char tar_attrs[][ATTR_SIZE]){
    
    // get the srcrel's open relation id(let it be srcrelid), using getRelid() method of cache layer
    // if srcrel is not open in open relation table, return E_RELNOTOPEN

    //get RelCatEntry of srcrel using getRelCatEntry() of OpenRelTable in cache layer
    //get the no. of attributes present in relation from the fetched RelcatEntry.

    // let attr_offset[tar_nAttrs] be an array of type int.
    // where ith entry corresponds to the offset in the srcrel of ith attribute in the target relation.
    // let attr_types[tar_nAttrs] be an array of type int.
    // where ith entry corresponds to the type ith attribute in the target relation.
    //(type can be one of INT, FLOAT or STRING)

    /*iterate through 0 to nAttrs-1 :
        get the AttributeCat entry (using getAttrcatEntry() of Openreltable in cache layer)
        of the attribute with name tar_attrs[i]
        fill the attr_offset,attr_types arrays of target relation from the corresonding Attribute catalog entries
    */

    // retval= createrel(targetrel,tar_nAttrs,tar_attrs,attr_types);
    // if create fails return retval.

    //int targetrelid = openRel(targetrel) 
    //where openRel is a function in schema layer
    /* if open fails 
    delete target relation by calling deleterel(targetrel) of schema layer
    return retval. */

    /*
    while (1):
        var: union Attribute record[no_of_attrs_srcrel];
        if ba_search(srcrelid,record,attr,val,op=PROJ_op) returns SUCCESS{
            declare: union Attribute proj_record[tar_nAttrs] (buffer for record which need to be inserted into target rel)
            iterate through 0 to tar_attrs-1:
                proj_record[i]=record[attr_offset[i]]
            retval= ba_insert(targetrelid,proj_record);
            if(insert fails){
                close the targetrel (by calling closeRel(targetrel) method of schema layer)
                delete targetrel (by calling deleterel(targetrel) of schema layer)
                return retval
            }
        }
        else: break
    */

    //Close the targetrel by calling closeRel() method of schema layer
    // return SUCCESS.

}
