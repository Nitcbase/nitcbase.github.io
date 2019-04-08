int OpenRelTable::setPrevRecId(relId rel_id, recId *recid){
	if(rel_id< 0 || rel_id>= MAXOPEN){	//check relation id (relid) lies in the range
		return E_OUTOFBOUND;
	}
	if(Rel_Table[relid].free){ //slot corresponding to the relid in the relation is free
		return E_NOTOPEN;
	}
	
	/*copy the previous record id (in meta informatiom) corresponding to the
	  relation with Id relid in the relation cache to the recid*/
	return SUCCESS;
}
