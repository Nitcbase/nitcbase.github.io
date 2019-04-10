struct recId linear_search(relId relid, char attrName[ATTR_SIZE], union Attribute attrval, int op){
	//get the previous record id from the relation cache corresponding to the relation with Id=relid
	OpenRelTabel::getPrevRecId(relid, prev_recid);
	if(prev_recid == {-1, -1}){ //It is the first time that linear search search for the record with the attribute value attrval
		//get the first record block of the relation from the relation cache 
		//using getRelCatEntry() method of OpenRelTable in cache layer
		//block = the first record block of the relation
		//slot = 0
	}
	else{ //if the linear search knows the  hit from previous search
		// block = the previous record id block
		// slot = the previous record id slot
	}
	
	//The following code searches for the next record in the relation that satisfies the given condition
	//Start from block and iterate over the records of the relation{
		//get the record of the relation using the following buffer layer functions
		rec_buffer = Buffer::getRecBuffer(block);
		rec_buffer->getRecord(record, slot);
		//If slot is free skip the loop and continue to the next record slot
		
		//compare the record's attribute value to the given attrval corresponding to the attribute name attrName
		// Compare the record
		// 
		//flag = compare(AttrVal, record[attr_offset], attr_type);
		
		//cond = UNSET
		
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
