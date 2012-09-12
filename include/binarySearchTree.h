# define PATH_SIZE 50
#include<stdio.h>
#include<stdlib.h>
#include "vfs.h"
#include<string.h>
struct BSTnode
{
	FileDescriptor filedesc;
	struct BSTnode * left;
	struct BSTnode * right;
};

typedef struct BSTnode BSTnode;


BSTnode * insertBST(BSTnode * , FileDescriptor * );
void displayBST(BSTnode *);
BSTnode * getBSTNode();
//void delete(node *root, char []);
FileDescriptor * searchBST(BSTnode * , char []);
BSTnode * min(BSTnode *);
