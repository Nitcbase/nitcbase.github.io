int select(char srcrel[ATTR_SIZE],char targetrel[ATTR_SIZE], char attr[ATTR_SIZE], int op, char strval[ATTR_SIZE]){

    // get the srcrel's open relation id(let it be srcrelid), using getRelid() method of cache layer
    // if srcrel is not open in open relation table, return E_RELNOTOPEN

    // get the attribute catalog entry for attr, using getAttrcatEntry() method of cache layer.
    // if getAttrcatEntry() call fails return E_ATTRNOTEXIST

    //convert strval into union Attribute (let it be val) as shown in the following code:
    // let type=attrcatentry.attr_type;

    if(type==INT){  
        //The input contains a string representation of the integer attribute value.
        val.ival=atoi(attr[iter]);
        //if conversion fails(i.e string can not be converted to integer) return E_ATTRTYPEMISMATCH. 

    }else if(type==FLOAT){
        //do accordingly to float
    }else if(type==STRING){
        //No type conversion needed here.
    }
    //if convert fails, return E_ATTRTYPEMISMATCH

    //Next task is to create the destination relation.
    //Prepare arguments for createrel() in the following way:
    //get RelcatEntry of srcrel from cache using getRelCatEntry() method of cache layer.
    //get the no. of attributes present in src relation, from RelcatEntry.(let it be nAttrs)

    // let attr_name[nAttrs][ATTR_SIZE] be a 2D array of type char(attribute names of rel).
    // let attr_types[nAttrs] be an array of type int

    /*iterate through 0 to nAttrs-1 :
        get the i'th attribute's AttrCatEntry (using getAttrcatEntry() of cache layer )
        fill attr_name, attr_types of corresponding attributes using Attribute catalog found.
    */

    /* let retval= createrel(targetrel,no_of_attrs_srcrel,attr_name,attr_type)
       where createrel is a function in schema layer
       if create fails return retval */

    //open targetrel (using retval=openRel() of OpenRelTable class in cache layer)
    /* if open fails
        delete target relation by calling deleterel(targetrel) of schema layer
        return retval
    */
    
    //Note: Before calling the search function, reset the search to start from the first hit
    // by calling ba_search of block access layer with op=RST.
    /*
    while (1):
        var: union Attribute record[no_of_attrs_srcrel];
        if ba_search(srcrelid,record,attr,val,op) returns SUCCESS:
            retval = ba_insert(targetrelid,record);
            if(insert fails):
                close the target rel(call closerel() method of OpenRelTable class in cache layer)
                delete targetrelation by calling deleterel(targetrel) of schema layer
                return retval

        else: break
    */

    //Close the target relation
    // return SUCCESS;
    
}
