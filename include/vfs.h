#define MAX_FILE_SYSTEM_LABLE_SIZE 10
#define MAX_FILE_NAME_SIZE 20
#define MAX_FULL_PATH_SIZE 100
#define MAX_FILE_TYPE_SIZE 10
#define MAX_BUFFER_SIZE 100

struct mainHeader{
	char fileSystemLabel[MAX_FILE_SYSTEM_SIZE];
	int maxNoOfFileDiscriptors;
	int noOfFileDescriptors;
	struct fileDescriptor *fdHead;
	struct freeList *listHead;
};


struct fileDescriptor{
	char fileName[MAX_FILE_NAME_SIZE];
	char fullPath[MAX_FULL_PATH_SIZE];
	char fileType[MAX_FILE_TYPE_SIZE];
	long fileSize;
	int locationBlockNo;
};

struct freeList{
	int blockNo;
	struct feeList *next;
};

struct block{
	int buffer[MAX_BUFFER_SIZE];
};

