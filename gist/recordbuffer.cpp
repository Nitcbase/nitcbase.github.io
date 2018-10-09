struct Slot{
	union Attribute attribute[16];
};

class RecordBuffer{
public:
	int blocktype;
	int pblock,lblock,rblock;
	int entriesCount;
	unsigned char reserved[12];
	unsigned char slotmap[7];
	unsigned char unused[217];
	struct Slot records[7];
};