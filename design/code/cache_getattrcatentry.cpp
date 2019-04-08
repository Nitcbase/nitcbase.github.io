int OpenRelTable::getRelCatEntry(relId relid, char attr_name[ATTR_SIZE/int attr_offset, AttrCatEntry *attrcat_buf){
	if(rel_id< 0 || rel_id>= MAXOPEN){	//check relation id (relid) lies in the range
		return E_OUTOFBOUND;
	}
	if(Rel_Table[relid].free){ //slot corresponding to the relid in the relation is free
		return E_NOTOPEN;
	}
	
	//Iterate over all the attributes in the attribute cache corresponding to the relation with Id relid{
		//if the attrName/attr_offset of the attribute equals to the given attrName/attr_offset{
			//copy the attribute catalog in the attribute cache to the attrcat_buf
			return SUCCESS;
		//}
	//}
	return E_ATTRNOTEXIST;
}
