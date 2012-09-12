
#include"binarySearchTree.h"

BSTnode * insertBST(BSTnode * root, FileDescriptor *fdesc)//, int * flag)
{
	int f=1;
	BSTnode * ref=NULL;
	BSTnode *temp=root;
	BSTnode * newNode=getBSTNode();
	
	if(newNode==NULL)
	{
		printf("INSUFFICIENT");
		exit(0);
	}
	if(root==NULL)
	{
		root=newNode;
		strcpy((root->filedesc).fullPath,fdesc->fullPath);
		strcpy((root->filedesc).fileName,fdesc->fileName);
		strcpy((root->filedesc).fileType,fdesc->fileType);
		root->filedesc.fileSize=fdesc->fileSize;
		root->filedesc.locationBlockNo=fdesc->locationBlockNo;
	}
	else
	{
		
		while(temp)
		{
			if(strcmp(fdesc->fullPath,(temp->filedesc).fullPath)>=0)
			{
				ref=temp;
				temp=temp->right;
				f=1;
			}
			else
			{
				ref=temp;
				temp=temp->left;
				f=0;
			}
		}
		if(f==1)
		{
			ref->right=newNode;
			strcpy(((ref->right)->filedesc).fullPath,fdesc->fullPath);
			strcpy((ref->right)->filedesc.fileName,fdesc->fileName);
			strcpy((ref->right)->filedesc.fileType,fdesc->fileType);
			(ref->right)->filedesc.fileSize=fdesc->fileSize;
			(ref->right)->filedesc.locationBlockNo=fdesc->locationBlockNo;
			
		}
		else
		{
			ref->left=newNode;
			strcpy(((ref->left)->filedesc).fullPath,fdesc->fullPath);
			strcpy((ref->left)->filedesc.fileName,fdesc->fileName);
			strcpy((ref->left)->filedesc.fileType,fdesc->fileType);
			(ref->left)->filedesc.fileSize=fdesc->fileSize;
			(ref->left)->filedesc.locationBlockNo=fdesc->locationBlockNo;
		}
	}
	return root;
}


BSTnode * getBSTNode()
{
	BSTnode * temp;
	temp= (BSTnode *)malloc(sizeof(BSTnode));
	(*temp).left=NULL;
	(*temp).right=NULL;
	return (temp);
}


void displayBST(BSTnode * root)
{
	if(root)
	{
		displayBST(root->left);
		printf("%s\n",(root->filedesc).fullPath);
		displayBST(root->right);
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


FileDescriptor * searchBST(BSTnode *root , char path[])
{
	
	BSTnode * temp;
	temp=root;
	if(root==NULL)
	{
		printf("BST is empty");
		return;
	}
	else
	{
		while(temp)
		{
			if(strcmp(path,(temp->filedesc).fullPath)==0)
			{
				printf("\nFile successfully found");
				return &(temp->filedesc);
			}
			else if(strcmp(path,(temp->filedesc).fullPath)>=0)
			{
				temp=temp->right;
			}
			else
			{
				temp=temp->left;
			}
		}
	}
	printf("\nSorry the following path does not exist:");
	return NULL;

}


