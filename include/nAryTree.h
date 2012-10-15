//#include"vfs.h"
#include<stdio.h>

struct dirNode {
  FileDescriptor *fileDesc;
  struct dirNode *firstChild;
  struct dirNode *rightSibling;
};

struct dirNode* getNode();
char* parsePath(char *);
struct dirNode* isValidPath(FileDescriptor *,struct dirNode* ,int *);
struct dirNode* insertNAry(FileDescriptor *,struct dirNode*,int *);
void saveToFile(struct dirNode * , FILE *);
void displayNAry(struct dirNode *);
