int OpenRelTable::setRelCatEntry(relId relid, RelCatEntry *relcat_buf){
	if(rel_id< 0 || rel_id>= MAXOPEN){	//check relation id (relid) lies in the range
		return E_OUTOFBOUND;
	}
	if(Rel_Table[relid].free){ //slot corresponding to the relid in the relation is free
		return E_NOTOPEN;
	}
	
	//copy the relcat_buf to the relation catalog in the relation cache
	//set the dirty flag corresponding to the relation with Id relid in the relation cache
	return SUCCESS;
}
