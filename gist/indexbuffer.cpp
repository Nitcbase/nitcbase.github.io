struct Index{
	union Attribute Attrvalue;
	int block;
	int slot;
	unsigned char unused[8];	
};

class IndexBuffer{
public:
	int blocktype;
	int pblock,lblock,rblock;
	int entriesCount;
	unsigned char reserved[12];
	struct Index index[55];
	int child[56];
	unsigned char unused[32];
};