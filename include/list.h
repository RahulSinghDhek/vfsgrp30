typedef struct node  {
	void *data;
	struct node *next;	
} NODE;


NODE *create(void *data);
NODE *insert_after(NODE *node, void *data);
NODE *insert_beginning(NODE *start, void *data);
void delnode(NODE *start, NODE *node);
void printnode(NODE *p, void (*f)(void *));
void printstr(void *str);
void printint(void *n);
void printchar(void *c);
NODE *attach(NODE *, NODE *);

