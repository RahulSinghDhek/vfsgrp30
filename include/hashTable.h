	//In struct, name is of fixed size,
//#define HASH_TAB 27
//#include "list.h"
//#include "vfs.h"

/*struct hash_link
{	char name[FILE_NAME_SIZE];
	char fullPath[FILE_PATH];
	struct hash_link *next;
};
*/

//NODE *array[HASH_TAB]={};

struct HashTable{
	NODE *hashNodes[HASH_TAB];
};			

NODE *insertnode(NODE *, FileDescriptor *);

int fun_Hash(char);

//int searchFile(char [], char []);

int searchFile_internal(NODE *, char [], char []);

void display_Hash();

NODE * deletenode(NODE *start, FileDescriptor *fDesc);
