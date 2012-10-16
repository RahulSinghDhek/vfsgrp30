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

void searchFile(char []);

void searchFile_internal(NODE *, char []);

void display_Hash();
