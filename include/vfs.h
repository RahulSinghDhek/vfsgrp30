#define MAX_FILE_SYSTEM_LABLE_SIZE 10
#define MAX_FILE_NAME_SIZE 40
#define MAX_FULL_PATH_SIZE 100
#define MAX_FILE_TYPE_SIZE 10
#define MAX_BLOCK_SIZE 1024
#define MAX_NO_FILE_DESCRIPTORS 1024
#define PATH_NOT_FOUND 101
#define FILE_NOT_FOUND 102
#define CANNOT_CREATE_FILE 103
#define FUNCTION_NOT_FOUND 104
#define FILE_ALREADY_EXISTS 105
#define NOT_ENOUGH_MEMORY 106

long vfs_size;

int FreeList[MAX_NO_FILE_DESCRIPTORS];

typedef struct fileDes{
	char fileName[MAX_FILE_NAME_SIZE];
	char fullPath[MAX_FULL_PATH_SIZE];
	char fileType[MAX_FILE_TYPE_SIZE];
	long fileSize;
	int locationBlockNo;
}FileDescriptor;


typedef struct block{
	unsigned char buffer[MAX_BLOCK_SIZE];
}Block;

typedef struct mainHeader{
	char fileSystemLabel[MAX_FILE_SYSTEM_LABLE_SIZE];
	int maxNoOfFileDescriptors;
	int noOfFileDescriptors;
}MetaHeader;


