#include"list.h"
#include "vfs.h"
#include"binarySearchTree.h"

struct BSTnode * insertBST(struct BSTnode * root, FileDescriptor *fdesc, int * flag)
{
	int f=1;
	struct BSTnode * ref=NULL;
	struct BSTnode *temp=root;
	struct BSTnode * newNode=getBSTNode();
	
	if(newNode==NULL)
	{
		printf("INSUFFICIENT");
		exit(0);
	}
	newNode->filedesc= fdesc;
	if(root==NULL)
	{
		root=newNode;
		
	}
	else
	{
		
		while(temp)
		{
			//printf("%s\n",fdesc->fullPath );
			if(strcmp(fdesc->fullPath,temp->filedesc->fullPath)>0)
			{
				ref=temp;
				temp=temp->right;
				f=1;
			}
			else if(strcmp(fdesc->fullPath,temp->filedesc->fullPath)<0)
			{
				ref=temp;
				temp=temp->left;
				f=0;
			}
			else
			{
				*flag=110;
				return root;
			}
				
		}
		if(f==1)
		{
			ref->right=newNode;
		}
		else
		{
			ref->left=newNode;
			
		}
	}
	return root;
}


struct BSTnode * getBSTNode()
{
	struct BSTnode * temp;
	temp= (struct BSTnode *)malloc(sizeof(struct BSTnode));
	(*temp).left=NULL;
	(*temp).right=NULL;
	return (temp);
}


void displayBST(struct BSTnode * temp)
{
	if(temp)
	{
		displayBST(temp->left);
		printf("%s\n",temp->filedesc->fullPath);
		displayBST(temp->right);
	}
}


BSTnode * min(BSTnode * temp, int *f)
{
	BSTnode *t = temp;	
	BSTnode * ref=temp;	
	while(t->left)
	{	
		 *f=1;		
		ref = temp;
		t=t->left;
	}
	return ref;
}


void deleteBST(BSTnode *root, char filepath[])
{
	BSTnode * ref, *tempnode, *minNode;
	BSTnode * temp;
	int a=0;
	int *flag;
	flag=&a;
	int f=1;
	if(root==NULL)
	{
		printf("EMPTY!!");
		return;
	}
	if(root->left==NULL && root->right==NULL && (strcmp(filepath, root->filedesc->fullPath)==0))	
	{
		free(root);
		printf("\nSUCCESSFULLY DELETED");
		return;
	}
	temp=root;
	while(temp)
	{
		if(strcmp(filepath, root->filedesc->fullPath)>0)
		{
			ref = temp;
			temp=temp->right;
			f=1;
		}
		else if(strcmp(filepath, root->filedesc->fullPath)<0)
		{		
			ref=temp;			
			temp=temp->left;
			f=0;
		}	
		else if(temp->left && temp->right)
		{
			minNode=min(temp->right, flag);
			if(*flag==0)
			{
				strcpy(temp->filedesc->fullPath,minNode->filedesc->fullPath);
				temp->right=minNode->right;
				free(minNode);
			}
			else
			{
				strcpy(temp->filedesc->fullPath,minNode->left->filedesc->fullPath);
				if(minNode->left->right)
				{
					tempnode=minNode->left	;
					free(tempnode);			
					minNode->left=minNode->left->right;
				}
				else
				{
					free(minNode->left);
					minNode->left=NULL;
				}
				
			}
			printf("\nSUCCESSFULLY DELETED");
		}	
		else
		{
			if(temp->left)
			{
				if(f==0)
					ref->left=temp->left;
				else
					ref->right=temp->left;
			}
			else if (temp->right)
			{
				if(f==0)
					ref->left=temp->left;
				else
					ref->right=temp->right;
			}
			else
			{
				if(f==0)
					ref->left=NULL;
				else
					ref->right=NULL;
			}
			free(temp);
			printf("\n File Path SUCCESSFULLY DELETED\n");
				
		}
		
	}
}



BSTnode * searchBST(BSTnode *root , char path[] )
{
	
	
	if(root==NULL)
	{
		printf("BST is empty");
		return NULL;
	}
	else
	{
		while(root)
		{
			
			if(strcmp(path,(root->filedesc->fullPath))==0)
			{
				//printf("\nFile successfully found");
				return root;
			}
			else if(strcmp(path,root->filedesc->fullPath)>0)
			{
				root=root->right;
			}
			else
			{
				root=root->left;
			}
		}
	}
	//*fla=ERROR;
	return NULL;

}

