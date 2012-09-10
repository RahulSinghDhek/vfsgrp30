#define path_size 50

struct node
{
	char filepath[path_size];
	struct node * left;
	struct node * right;
};

typedef struct node node;


node * insert(node * root, char filepath[]);
void inorder(node *root);
node * getNode();
void delete(node *root, char file[]);
void search(node *root, char filepath[]);
node * min(node *);
