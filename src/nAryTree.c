#include "nAryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define MAX_NAME 10
#define MAX_DIR 10

struct dirNode* getNode()
{
	struct dirNode *p;
	p=(struct dirNode*)malloc(sizeof(struct dirNode));
	p->firstChild=NULL;
	p->rightSibling=NULL;	
}


