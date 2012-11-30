#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"
#include"vfs.h"

NODE *create(void *data)    //creates the node
{
	NODE *node;
	if(!(node=malloc(sizeof(NODE)))) return NULL;
	node->data=data;
	node->next=NULL;
	return node;
}

NODE *attach(NODE *start, NODE *NewPtr)
{	NODE *temp;
	if(start==NULL)
		start=NewPtr;
	else
	{	temp=start;						//shorting shd be applied here afterwards
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=NewPtr;
	}
	return start;
}

NODE *insert_after(NODE *node, void *data) // here the node refers to the node after which we want to insert new node. 
{
	NODE *newnode;
        newnode=create(data);
        newnode->next = node->next;
        node->next = newnode;
	return newnode;
}
NODE *insert_beginning(NODE *start, void *data)// if we want to insert in the begining,
{
	NODE *newnode;
        newnode=create(data);
        newnode->next =start;
	return newnode;
}
void delnode(NODE *start, NODE *node)		// node is the node which is to be removed
{	NODE *temp;
	temp = start;
	while(temp->next && temp->next!=node) 
		temp=temp->next; 	// move the pointer up to that node
	if(temp->next) {
		temp->next=node->next;
		free(node);
	} 
}                                                 

void printnode(NODE *p, void (*f)(void *)) 	//while printing elements use prototype as printnode( node,printint) or 											    printnode(node,printstr);
{
   while (p)
   {
      (*f)(p->data);
      p = p->next;
   }
}

void printstr(void *str)
{  printf("%s\t", (char *)str);

}


void printint(void *n)
{ printf(" %d\t",*(int*)n);

}
void printchar(void *c)
{   printf(" %c\t", *(char*)c);

}

