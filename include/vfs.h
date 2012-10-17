#define MAX_FILE_SYSTEM_LABLE_SIZE 30
#define MAX_FILE_NAME_SIZE 40
#define MAX_FULL_PATH_SIZE 100
#define MAX_FILE_TYPE_SIZE 10
#define MAX_BLOCK_SIZE 1024
#define MAX_NO_OF_FILE_DESCRIPTORS 1024
#define ERROR_FREE 100
#define PATH_NOT_FOUND 101
#define FILE_NOT_FOUND 102
#define CANNOT_CREATE_FILE 103
#define FUNCTION_NOT_FOUND 104
#define FILE_ALREADY_EXISTS 105
#define NOT_ENOUGH_MEMORY 106
#define HASH_TAB 27


long vfs_size;

int flag;
//int index;
struct dirNode *naryRoot;
struct BSTnode *rootBST;

NODE *array[HASH_TAB];

/*typedef struct inMemory{
	struct dirNode *naryRoot;
	BSTnode *rootBST;
	NODE *array[HASH_TAB];
	int *flag;		
}InMemoryStruct;*/

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
	int noOfFileDescriptors;
	int FreeList[MAX_NO_OF_FILE_DESCRIPTORS];
	FileDescriptor filedescArray[MAX_NO_OF_FILE_DESCRIPTORS];
}MetaHeader;

//MetaHeader mhd;

