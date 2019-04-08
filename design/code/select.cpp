int select(char srcrel[ATTR_SIZE],char targetrel[ATTR_SIZE], char attr[ATTR_SIZE], int op, char strval[ATTR_SIZE]){

    // get the src relation's open relation id, using getRelid() method of Openreltable
    // if source rel is not opened in open relation table, return FAILURE

    // get the attribute catalog entry of attribute correspoding to attr(as argument), from Openreltable(using getAttrcatEntry() method).
    // if gatAttrcatEntry() call fails return FAILURE.

    //convert strval in to union Attribute (let the var. name be val)(using type found from attribute catalog entry)
    //if convert fails, return FAILURE(type mismatch).

    //get the no. of attributes present in src relation, from RelcatEntry present in Openreltable(using getRelCatEntry() method).

    // array char attr_name[nAttrs][ATTR_SIZE]
    // array int attr_types[tar_nAttrs]

    /*iterate through nAttrs:
        get the i'th AttributeCat entry (using getAttrcatEntry() of Openreltable )
        fill attr_name, attr_types of corresponding attributes using Attribute catalog found.
    */

    // create target relatino by calling createrel(targetrel,no_of_attrs_srcrel,attr_name array,attr_type array);
    // if create fails return FAILURE(targetrelalreadyexist,diskfull)

    //open targetrel
    /* if open fails
        delete targetrelation by calling deleterel(targetrel)
        return FAILURE(CACHE_FULL)
    */
   
    /*
    while (1):
        var: union Attribute record[no_of_attrs_srcrel];
        if ba_search(srcrelid,record,attr,val,op) returns SUCCESS:
            call ba_insert(targetrelid,record);
            if(insert fails):
                close the target rel(call closerel() method of Openreltable class)
                delete targetrelation by calling deleterel(targetrel)
                return FAILURE(DISK_FULL)

        else: stop
    */

    // return SUCCESS;
    
}