struct recId linear_search(relId relid, char attrName[ATTR_SIZE], union Attribute attrval, int op){
	//get the previous record id from the relation cache corresponding to the relation with Id relid
	OpenRelTabel::getPrevRecId(relid, prev_recid);
	if(prev_recid == {-1, -1}){ //It is the first time that linear search search for the record with the attribute value attrval
		//get the first record block of the relation from the relation cache 
		//assign block as the first record block of the relation
		//assign slot as 0
	}
	else{ //if the linear search knows the previous hit search from the previous hit
		//assign block as the previous record id block
		//assign slot as the previous record id slot
	}
	
	//search for the record in the relation that satisfies the given condition
	//Start from the assigned block and iterate over the records of the relation from the assigned block{
		//get the record of the relation
		rec_buffer = Buffer::getRecBuffer(block);
		rec_buffer->getRecord(record, slot); //where slot is not free
		
		//compare the record's attribute value to the given attrval corresponding to the attribute name attrName
		//assign the compared value to the flag variable
		
		//assign the cond variable as UNSET
		
		//Set the cond variable as per the op and the flag variable
		switch(op){
		
			case NE: //if op is not equal to
				if(flag != 0){ //i.e if the record's attribute value is not equal to the given attrval
					//SET the cond variable
				}
				break;
				
			case LT: //if op is less than
				if(flag < 0){ //i.e if the record's attribute value is less than the given attrval
					//SET the cond variable 
				}
				break;
			
			case LE: //if op is less than or equal to
				if(flag <= 0){ //i.e if the record's attribute value is less than or equal to the given attrval
					//SET the cond variable 
				}
				break;
			
			case EQ: //if op is equal to
				if(flag == 0){ //i.e if the record's attribute value is equal to the given attrval
					//SET the cond variable 
				}
				break;
			
			case GT: //if op is greater than
				if(flag > 0){ //i.e if the record's attribute value is greater than the given attrval
					//SET the cond variable 
				}
				break;
			
			case GE: //if op is greater than or equal to
				if(flag >= 0){ //i.e if the record's attribute value is greater than or equal to the given attrval
					//SET the cond variable 
				}
				break;
		}
		
		if(cond == SET){
			recid = {block, slot} //record id of the record that satisfies the given condition
			/*set the previous record id in the relation cache as 
			the record id of the record that sastifies the given condition*/		
			OpenRelTable::setPrevRecId(relid, recid);
			return recid;
		}
		
		//get the next record id by adjusting the block and slot
	//}
	
	return {-1, -1}; //i.e., no record in the relation with Id relid satisfies the given condition
}			
