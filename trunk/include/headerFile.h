struct mainHeader{
	char fileSystemLabel[10];
	int maxNoOfFileDiscriptors;
	int noOfFileDescriptors;
	struct fileDescriptor *fdHead;
	struct freeList *listHead;
};


struct fileDescriptor{
	char fileName[20];
	char fullPath[100];
	char fileType[10];
	long fileSize;
	int locationBlockNo;
};

struct freeList{
	int blockNo;
	struct feeList *next;
};

struct block{
	int buffer[100];
};

