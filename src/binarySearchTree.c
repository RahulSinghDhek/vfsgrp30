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


BSTnode * min(BSTnode * temp)
{
	while(temp->left)
		temp=temp->left;
	return temp;
}


/*void delete(node *root,fileDescriptor fdesc)
{
	if(root==NULL)
	{
		printf("EMPTY!!");
		return;
	}
	if(root->left==NULL && root->right==NULL && (strcmp(fdesc->fullPath, root->filedesc->fullPath)==0))	
	{
		free(root);
		printf("\nSUCCESSFULLY DELETED");
		return;
	}
	node * ref, *tempnode, *minNode;
	node *temp=root;
	int f=1;
	while(temp)
	{
		if(strcmp(fdesc->fullPath, temp->filedesc->fullPath)>0)
		{
			ref = temp;
			temp=temp->right;
			f=1;
		}
		else if(strcmp(fdesc->fullPath, temp->filedesc->fullPath)<0)
		{		
			ref=temp;			
			temp=temp->left;
			f=0;
		}	
		else if(temp->left && temp->right)
		{
			minNode=min(temp->right);
			strcpy(temp->filedesc->fullPath,minNode->filedesc->fullPath);
			while(minNode->right)
			{
				strcpy(minNode->filedesc->fullPath,minNode->right->filedesc->fullPath);
				minNode=minNode->right;
			}
						
			free(minNode);
			temp=NULL;
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
			tempnode=temp;
			temp=NULL;
			free(tempnode);
			printf("\n File Path SUCCESSFULLY DELETED\n");
				
		}
		
	}
}




*/


/*FileDescriptor * searchBST(BSTnode *root , char path[] )
{
	
	
	if(root==NULL)
	{
		printf("BST is empty");
		return;
	}
	else
	{
		while(root)
		{
			
			if(strcmp(path,(root->filedesc->fullPath))==0)
			{
				printf("\nFile successfully found");
				return;
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
	return;

}

*/
