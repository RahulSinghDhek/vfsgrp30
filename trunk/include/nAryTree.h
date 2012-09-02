#include "vfs.h"
struct dirNode {
  fileDescriptor fileDesc;
  struct dirNode *firstChild;
  struct dirNode *rightSibling;
};

struct dirNode* getNode();
