#include"vfs.h"
#include<stdio.h>

struct dirNode {
  FileDescriptor *fileDesc;
  struct dirNode *firstChild;
  struct dirNode *rightSibling;
};

struct dirNode* getNode();
struct dirNode* insertNAry(FileDescriptor *,struct dirNode*);
void saveToFile(struct dirNode * , FILE *);
