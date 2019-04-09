int select(char srcrel[ATTR_SIZE],char targetrel[ATTR_SIZE], char attr[ATTR_SIZE], int op, char strval[ATTR_SIZE]){

    // get the srcrel's open relation id(let it be srcrelid), using getRelid() method of cache layer
    // if srcrel is not opened in open relation table, return E_RELNOTOPEN

    // get the attribute catalog entry for attr, using getAttrcatEntry() method of cache layer.
    // if getAttrcatEntry() call fails return E_ATTRNOTEXIST

    //convert strval into union Attribute (let the var. name be val)(using type found from attribute catalog entry)
    // let type=attrcatentry.attr_type;

    if(type==INT){  
        //The input contains a string representation of the integer attribute value.
        attrval[iter].ival=atoi(attr[iter]);
        //if conversion fails(i.e string can not be converted to integer) return E_ATTRTYPEMISMATCH. 

    }else if(type==FLOAT){
        //do accordingly to float
    }else if(type==STRING){
        //No type conversion needed here.
    }
    //if convert fails, return E_ATTRTYPEMISMATCH


    //get the no. of attributes present in src relation, from RelcatEntry using getRelCatEntry() method).

    // let attr_name[nAttrs][ATTR_SIZE] be a 2d array of type char
    // let attr_types[tar_nAttrs] be an array of type int

    /*iterate through 0:nAttrs :
        get the i'th attribute's AttrCatEntry (using getAttrcatEntry() of Openreltable )
        fill attr_name, attr_types of corresponding attributes using Attribute catalog found.
    */

    // let retval= createrel(targetrel,no_of_attrs_srcrel,attr_name,attr_type)
    // if create fails return retval

    //open targetrel (using retval=openRel() in Openreltable)
    /* if open fails
        delete targetrelation by calling deleterel(targetrel)
        return retval
    */
   
    /*
    while (1):
        var: union Attribute record[no_of_attrs_srcrel];
        if ba_search(srcrelid,record,attr,val,op) returns SUCCESS:
            retval = ba_insert(targetrelid,record);
            if(insert fails):
                close the target rel(call closerel() method of Openreltable class)
                delete targetrelation by calling deleterel(targetrel)
                return retval

        else: stop
    */

    // return SUCCESS;
    
}
