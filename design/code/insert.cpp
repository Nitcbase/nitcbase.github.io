int insert(char relname[ATTR_SIZE], int nAttrs, char record[][ATTR_SIZE]){

    // get the relation's open relation id(let it be rel_id), using getRelid() method of Openreltable
    // if relation is not opened in Openreltable, return E_RELNOTOPEN

    //get the no. of attributes present in relation, from RelcatEntry present in Openreltable(using getRelCatEntry() method).
    //if nAttrs!=no_of_attrs in relation, return E_NATTRMISMATCH

    // let recval[nAttrs] be an array of type union Attribute

    /*iterate through 0 to nAttrs-1 :
        get the i'th attribute's AttrCatEntry (using getAttrcatEntry() of Openreltable )
    */
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


    int retval= ba_insert(rel_id,attrval)

    //return retval        
}
