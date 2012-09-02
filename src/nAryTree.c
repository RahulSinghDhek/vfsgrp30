#include "nAryTree.h"
//#include "vfs.h"
#define MAX_NAME 10
#define MAX_DIR 10
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//char tokens[MAX_DIR][MAX_NAME];

struct dirNode* getNode()
{
	struct dirNode *p;
	p=(struct dirNode*)malloc(sizeof(struct dirNode));
	p->firstChild=NULL;
	p->rightSibling=NULL;
}

/*int parsePath(char* path)
{
	int l,i,j=0,dec=1,k;
	char *temp;
	temp=(char*)malloc(sizeof(MAX_NAME));
	l=strlen(path);
	for(i=0;i<l;i++)
	{		
		if(dec==1)
		{
			k=0;
			dec=0;
		}	
		if(path[i]=='/')	
		{
			*(temp+k)='\0';
			strcpy(tokens[j],temp);		//Copy the token when you get '/'
			j++;
			dec=1;
		}
		else
		{
			*(a+k)=path[i];	//Append to temp until '/' in the path
			k++;
		}
	}
	*(a+k)='\0';
	strcpy(*(p+j),a);
	return ++j;
}
*/
struct dirNode* insertNAry(struct dirNode* root,char *path)
{
	struct dirNode *p,*parent;
	char *ref;
	int exitStatus=FALSE;
	p=getNode();
	(p->fileDesc).fullPath=path;
	if(p==NULL)
	{
		printf("Sorry NO SUFFICIENT MEMORY");
		exit(0);
	}
	if(root==NULL)
	{
		root=p;
		exitStatus=TRUE;
	}
	else
	{
			parent=root;
			while(exitStatus==FALSE)
			{
				puts(path);
				puts(parent->fileDesc.fullPath);	
				if(strstr(path,(parent->fileDesc).fullPath)==NULL)
				{
					if(parent->rightSibling==NULL)
					{
						parent->rightSibling=p;
						exitStatus=TRUE;
					}
					else
						parent=parent->rightSibling;
				}
				else
				{
					if(parent->firstChild==NULL)
					{
						parent->firstChild=p;
						exitStatus=TRUE;
					}	
					else
					{
						parent=parent->firstChild;
					}	
				}
			}
	  }
      return root;
}

void displayNAry(struct dirNode* root)
{
	struct dirNode* parent=root;
	while(parent!=NULL)
	{
		puts((parent->fileDesc).fullPath);
		if(parent->rightSibling==NULL)
			parent=parent->firstChild;
		else
			parent=parent->rightSibling;
	}		
}
	
int main()
{
	int i;
	//fileDescriptor *fd;
	//fd=(fileDescriptor*)malloc(sizeof(fileDescriptor));
	char fullPath[20];
	struct dirNode* root=NULL;
	for(i=0;i<5;i++)
	{
		printf("Enter filename,fullpath,filetype,filesize,blk_no");
	//	scanf("%s",fd->fileName);
	//	scanf("%s",fd->fullPath);
	//	scanf("%s",fd->fileType);
	//	scanf("%ld",&fd->fileSize);
	//	scanf("%d",&fd->locationBlockNo);
		scanf("%s",fullPath);
		root=insertNAry(root,fullPath);
	}
	displayNAry(root);
	/*int l=parsePath("D:/Sush/hat");
	for(i=0;i<l;i++)
		puts(*(p+i));*/
	return 0;
			
}
