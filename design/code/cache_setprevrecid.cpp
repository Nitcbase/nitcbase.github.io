int OpenRelTable::setPrevRecId(relId rel_id, recId *recidbuff_ptr){
	if(rel_id< 0 || rel_id>= MAXOPEN){	//check relation id (relid) lies in the range
		return E_OUTOFBOUND;
	}
	if(Rel_Table[relid].free){ //slot corresponding to the relid in the relation is free
		return E_NOTOPEN;
	}
	
	/*copy the previous record id of the relation from the recidbuff_ptr to the relation cache*/
	return SUCCESS;
}
