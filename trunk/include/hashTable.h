//In struct, name is of fixed size,
#define HASH_TAB 27
#define FILE_NAME_SIZE 100
#define FILE_PATH 1000


/*struct hash_link
{	char name[FILE_NAME_SIZE];
	char fullPath[FILE_PATH];
	struct hash_link *next;
};
*/

NODE *array[HASH_TAB]={};				

NODE *insertnode(NODE*, char [], char []);

int fun_Hash(char);

void searchFile(NODE *, char[]);

void serchStartPoint(char[]);

void display_Hash();
