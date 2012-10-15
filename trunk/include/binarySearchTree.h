# define PATH_SIZE 50
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BSTnode
{
	FileDescriptor * filedesc;
	struct BSTnode * left;
	struct BSTnode * right;
};

typedef struct BSTnode BSTnode;


struct BSTnode * insertBST(struct BSTnode * , FileDescriptor * , int *);
void displayBST(BSTnode *);
BSTnode * getBSTNode();
//void delete(node *root, char []);
//void searchBST(BSTnode * , char []);
BSTnode * min(BSTnode *);
