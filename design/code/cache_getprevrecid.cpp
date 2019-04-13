int OpenRelTable::getPrevRecId(relId relid, recId *recidbuff_ptr){
	if(relid< 0 || relid>= MAXOPEN){//check whether relation id (relid) lies in the range
		return E_OUTOFBOUND;
	}
	if(Rel_Table[relid].free){ //slot corresponding to the relid in the relation is free
		return E_NOTOPEN;
	}
	
	/*copy the previous record id of the relation in the relation cache to the recidbuff_ptr*/
	return SUCCESS;
}
