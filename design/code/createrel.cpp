int createRel(char relname[],int nAttrs, char attrs[][ATTR_SIZE],int attrtype[]){

    // let union Attribute relname_val
    // copy the relname into relname_val(type = string)

    // let recId targetrelid
    /* using ba_search() of ba_layer, search the relation relcat (with Openrelid = 0), for attribute value of attribute "RelName" to be
     equal to relname_val. let the return value of ba_search be retval*/

    // if relcat==SUCCESS (i.e "relcat" relation already contains a relation with relation name as relname) 
        // return E_RELEXIST

    // by iterating though all the attributes of attrs[] array 
        // if any two strings of attrs[] array have same string value, return E_DUPLICATEATTR (i.e 2 attributes having same value)

    // let union Attribute relcatrecord[6] (this is the record in relationcatalog corresponding to new relation)
    // fill relcatrecord appropriately with as that of new relation.

    //retval = ba_insert(0,relcatrecord);
    // if ba_insert fails return retval

    // iterate through 0 to nAttrs-1 :
        // let union Attribute attrcatrec[6] (this is the record in attrcatalog corresponding to i'th Attribute)
        /* update attrcatrec corresponding to i'th attribute of the relation
         (Relation name = relname, Attribute name=attrs[i], type= attrtype[i], pflag=-1, rootblock= -1, offset= i).*/

        // retval = ba_insert(1,attrcatrec);
        /* if ba_insert fails:
            delete targetrelation by calling deleterel(targetrel) of schema layer
            return E_DISKFULL
        */

    // return SUCCESS
}