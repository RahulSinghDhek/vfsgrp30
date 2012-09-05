#define MAX_FILE_SYSTEM_LABLE_SIZE 10
#define MAX_FILE_NAME_SIZE 20
#define MAX_FULL_PATH_SIZE 100
#define MAX_FILE_TYPE_SIZE 10
#define MAX_BUFFER_SIZE 100
#define MAX_NO_OF_FILE_DESC 10
#define MAX_FREE_LIST_SIZE 20

typedef struct fileDes{
	char fileName[MAX_FILE_NAME_SIZE];
	char fullPath[MAX_FULL_PATH_SIZE];
	char fileType[MAX_FILE_TYPE_SIZE];
	long fileSize;
	int locationBlockNo;
}fileDescriptor;


typedef struct freeLis{
	int blockNo;
	struct feeList *next;
}freeList;



struct block{
	unsigned char* buffer[MAX_BUFFER_SIZE];
};



struct mainHeader{
	char fileSystemLabel[MAX_FILE_SYSTEM_LABLE_SIZE];
	int maxNoOfFileDescriptors;
	int noOfFileDescriptors;
	fileDescriptor filedesc[MAX_NO_OF_FILE_DESC];
	freeList freelist[MAX_FREE_LIST_SIZE];
};

