#define MAX_LENGTH 100
struct task {
  char command[MAX_LENGTH];
  int required_time;
};

struct node {
  struct task taskinfo;
  struct node *firstchild;
  struct node *nextsibling;
};

