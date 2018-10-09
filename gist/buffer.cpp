class Buffer{
public:
	unsigned char data[2048];
	
	class IndexBuffer* getIndexBlock(){
		return (class IndexBuffer*)this;
	}
	class RecordBuffer* getRecordBlock(){
		return (class RecordBuffer*)this;
	}
};