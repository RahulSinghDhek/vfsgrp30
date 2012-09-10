#include "vfs.h"
struct dirNode {
  FileDescriptor fileDesc;
  struct dirNode *firstChild;
  struct dirNode *rightSibling;
};

struct dirNode* getNode();
