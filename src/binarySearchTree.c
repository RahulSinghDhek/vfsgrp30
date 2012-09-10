#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

main()
{
	char filepath[path_size],filepathToBeSearched[path_size],filepathToBeDeleted[path_size] ;
	int choice;
	node * root=NULL;
	while(1)
	{
		printf("\n 1: INSERT");
		printf("\n 2: DELETE");
		printf("\n 3: DISPLAY(SORTED)");
		printf("\n 4: SEARCH");
		printf("\n 5: QUIT \n");
		printf("Enter your choice:  \n");
		scanf(" %d",&choice);		
		switch(choice)
		{
			case 1: printf("Enter the file path \n");
				scanf(" %s",&filepath);
				root = insert(root,filepath);
				break;
			case 2: printf("Enter the file path to be deleted\n");
				scanf(" %s", &filepathToBeDeleted);
				delete(root,filepathToBeDeleted);
				break;
			case 3: inorder(root);
				break;
			case 4: printf("Enter the file path to b searched\n");
				scanf(" %s", &filepathToBeSearched);
				search(root, filepathToBeSearched);
				break;
			case 5: exit(0);
			default : printf("Please enter right choice:  ");
		}
	}

}

node * insert(node * root, char filepaths[])
{
	int f=1;
	node * ref=NULL;
	node *temp=root;
	node * newNode=getNode();
	if(newNode==NULL)
	{
		printf("INSUFFICIENT");
		exit(0);
	}
	if(root==NULL)
	{
		root=newNode;
		strcpy(root->filepath,filepaths);
	}
	else
	{
		
		while(temp)
		{
			if(strcmp(filepaths,temp->filepath)>=0)
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
			strcpy((ref->right)->filepath,filepaths);
		}
		else
		{
			ref->left=newNode;
			strcpy((ref->left)->filepath,filepaths);	
		}
	}
	return root;
}


node * getNode()
{
	node * temp;
	temp= (node *)malloc(sizeof(node));
	(*temp).left=NULL;
	(*temp).right=NULL;
	return (temp);
}


void inorder(node * root)
{
	if(root)
	{
		inorder(root->left);
		printf("%s\n",root->filepath);
		inorder(root->right);
	}
}


node * min(node * temp)
{
	while(temp->left)
		temp=temp->left;
	return temp;
}


void delete(node *root, char filepath[])
{
	if(root==NULL)
	{
		printf("EMPTY!!");
		return;
	}
	if(root->left==NULL && root->right==NULL && (strcmp(filepath, root->filepath)==0))	
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
		if(strcmp(filepath, temp->filepath)>0)
		{
			ref = temp;
			temp=temp->right;
			f=1;
		}
		else if(strcmp(filepath, temp->filepath)<0)
		{		
			ref=temp;			
			temp=temp->left;
			f=0;
		}	
		else if(temp->left && temp->right)
		{
			minNode=min(temp->right);
			strcpy(temp->filepath,minNode->filepath);
			while(minNode->right)
			{
				strcpy(minNode->filepath,minNode->right->filepath);
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



void search(node *root, char filepaths[])
{
	node * temp;
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
			if(strcmp(filepaths,temp->filepath)==0)
			{
				printf("\nFile successfully found");
				return;
			}
			else if(strcmp(filepaths,temp->filepath)>=0)
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

}


