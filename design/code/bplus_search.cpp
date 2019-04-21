struct recId bplus_search(relId relid, char AttrName[ATTR_SIZE], union Attribute AttrVal, int op){
	AttrCatEntry attrcat_entry;
	
	//get the previous index id from the attribute cache (corresponds to relid, AttrName) by calling
	OpenRelTable::getAttrCatEntry(relid, AttrName, &attrcat_entry);
	prev_indexid = OpenRelTable::::getPrevIndexId(relid, AttrName);
	
	//prev_indexid is set only if the search proccessed through leaf index blocks (search has been done before atleast once)
	//otherwise prev_indexid is unset ({-1,-1})
	
	//if prev_indexid is unset then assign block as root block and index as 0 (i.e seach from the root block)
	//if prev_indexid is set then assign block as prev_indexid's block and index as prev_indexid's index + 1
	
	//if assigned index exceeds the indices present in the leaf index block{
		//assign block as block right's block (i.e next leaf index block)
		//if(block == -1) (i.e, search is done )then return {-1,-1}
	//} 
	
	//if(block_num == root_block && index == 0){
		//traverse through all the internal nodes according to the attribute value AttrVal and the operator op
		//Accordingly update block and index variables
	//}
	
	//NOTE: From Index blocks are leaf index blocks (WHY!!!)	 
	
	//Traverse through leaf index entries in the leaf index block (block) from index entry numbered as index
	
	//if no index entry in the leaf block satisfies the given condition{
		//then there are two possiblities:
		// 1. Search is Completed 
		// 2. No record in the relation with relid satisfies the given condition
		// update prev_recid in the attribute cache as {-1, -1}
		// return recid = {-1, -1}
	//} 
	
	//otherwise{
		//update prev_recid in the attribute cache as 
		//prev_recid = {block (leaf index block), index (index entry that satisfied the given conditon)}
		//get record id (recid) from the index entry
		//return record id
	//}
}
