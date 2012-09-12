#include "nAryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define MAX_NAME 10
#define MAX_DIR 10

struct dirNode* getNode()
{
	struct dirNode *p;
	p=(struct dirNode*)malloc(sizeof(struct dirNode));
	p->firstChild=NULL;
	p->rightSibling=NULL;	
}

struct dirNode* insertNAry(FileDescriptor *fd,struct dirNode* root)
{
	struct dirNode *p,*parent;
	char *ref;
	int exitStatus=FALSE;
	p=getNode();
	if(p==NULL)
	{
		printf("Sorry NO SUFFICIENT MEMORY");
		exit(0);
	}
	
	strcpy(p->fileDesc.fileName,fd->fileName);
	strcpy(p->fileDesc.fullPath,fd->fullPath);
	strcpy(p->fileDesc.fileType,fd->fileType);
	p->fileDesc.fileSize=fd->fileSize;
	p->fileDesc.locationBlockNo=fd->locationBlockNo;
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
				if(strstr(p->fileDesc.fullPath,(parent->fileDesc).fullPath)==NULL)
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

/*void displayNAry(struct dirNode *root)
{
	if(root!=NULL)
	{
		puts(root->fileDesc.fullPath);
		displayNAry(root->rightSibling);	//Pre-order traversal
		displayNAry(root->firstChild);
	}
			
}*/

void saveToFile(struct dirNode *root,FILE *fstore)
{
	if(root!=NULL)
	{
		fwrite(&(root->fileDesc),sizeof(fileDescriptor),1,fstore);
		saveToFile(root->rightSibling,fstore);
		saveToFile(root->firstChild,fstore);
	}
	
}

/*int main()
{
	int i;
	char ch;
	FILE *fp,*fstore,*fp2;
	struct dirNode* root=NULL;
	FileDescriptor *fd;
	fstore=fopen("nary_store.dat","wb");
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
	if((fp=fopen("inputfiledesc.txt","r"))==NULL)
		printf("Cannot open file");
	else
	{
		while(fscanf(fp,"%s",fd->fileName)!=EOF)
		{
			fscanf(fp,"%s",fd->fullPath);
			fscanf(fp,"%s",fd->fileType);
			fscanf(fp,"%ld",&fd->fileSize);
			fscanf(fp,"%d",&fd->locationBlockNo);
			root=insertNAry(fd,root);
		}
	}
	fclose(fp);
	//displayNAry(root);
	saveToFile(root,fstore);
	fclose(fstore);	
	root=NULL;
	if((fp2=fopen("nary_store.dat","rb"))==NULL)
		printf("Cannot open file");
	else
	{
		while(fread(fd,sizeof(FileDescriptor),1,fp2))
		{			
			root=insertNAry(fd,root);
		}
	}
	displayNAry(root);
	fclose(fp);
	
	return 0;
}*/



