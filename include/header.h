# define PATH_SIZE 50
#include<stdio.h>
#include "vfs.h"
# define PATH_SIZE 50
#include<stdlib.h>
#include<string.h>
struct BSTnode
{
	FileDescriptor * filedesc;
	struct BSTnode * left;
	struct BSTnode * right;
};

typedef struct BSTnode BSTnode;


BSTnode * insertBST(BSTnode * , FileDescriptor * , int *);
void displayBST(BSTnode *);
BSTnode * getBSTNode();
//void delete(node *root, char []);
void searchBST(BSTnode * , char [], int *);
BSTnode * min(BSTnode *);





