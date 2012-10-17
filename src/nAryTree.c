#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"

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

char* parsePath(char *path)
{
	int l,i,j=0,dec=1,k=0;
	char *temp;
	char *pat;
	pat=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));
	char tokens[MAX_DIR][MAX_FULL_PATH_SIZE];
	temp=(char*)malloc(sizeof(10));			//CHAGE IT
	l=strlen(path);
	for(i=1;i<l;i++)
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
			*(temp+k)=path[i];	//Append to temp until '/' in the path
			k++;
		}
	}
	*(temp+k)='\0';
	strcpy(tokens[j],temp);
	strcat(pat,"/");
	for(i=0;i<j;i++){
		strcat(pat,tokens[i]);
		strcat(pat,"/");
	}
	return pat;
}
struct dirNode* isValidPath(FileDescriptor *fd,struct dirNode* root,int *flag)
{
	int l,exitStatus;
	struct dirNode *parent;
	char temp_path[MAX_FULL_PATH_SIZE];
	char *path_part;
	path_part==(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));	
	strcpy(temp_path,fd->fullPath);
	//strcpy(path_part,parsePath(temp_path));
	path_part=parsePath(temp_path);
	if(root==NULL)
	{
		if(strcmp(path_part,"/")!=0)		//for root path
			*flag=101;			//wrong path trying to insert at root
	}
	else
	{
		exitStatus=FALSE;
		parent=root;
		while(exitStatus==FALSE)
		{
			if(strstr(path_part,parent->fileDesc->fullPath)==NULL)
			{
				if(parent->rightSibling==NULL)
				{
					if(strncmp(path_part,parent->fileDesc->fullPath,strlen(path_part)-1)!=0){
						// *flag=PATH_NOT_FOUND;
						FileDescriptor *tempfd1=(FileDescriptor*)malloc(sizeof(FileDescriptor));
						strncpy(tempfd1->fullPath,path_part,strlen(path_part)-1);
						insertNAry(tempfd1,root,flag);
					}
						exitStatus=TRUE;
				}
				else
						parent=parent->rightSibling;
			}
			else
			{
				if(parent->firstChild==NULL)
				{
					if(strncmp(path_part,parent->fileDesc->fullPath,strlen(path_part)-1)!=0){
					//	*flag=PATH_NOT_FOUND;
					FileDescriptor *tempfd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
					strncpy(tempfd->fullPath,path_part,strlen(path_part)-1);
					insertNAry(tempfd,root,flag);	
					}
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

struct dirNode* insertNAry(FileDescriptor *fd,struct dirNode* root,int *flag)
{
	struct dirNode *p;
	struct dirNode *parent;
	char *ref;
	int exitStatus=FALSE;
	p=getNode();
	if(p==NULL)
	{
		printf("Sorry NO SUFFICIENT MEMORY");
		*flag=NOT_ENOUGH_MEMORY;
		exit(0);
	}
	//printf("before");
	root=isValidPath(fd,root,flag);
	//printf("after");
	if(*flag==101)
		printf("\nwrong path entered\n");
	if(*flag==100)
	{	
		p->fileDesc=fd;
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
					printf("%s\n",p->fileDesc->fullPath);
				if(strstr(p->fileDesc->fullPath,parent->fileDesc->fullPath)==NULL)
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
	  }
      return root;
}

void displayNAry(struct dirNode *root)
{
	if(root!=NULL)
	{
		puts(root->fileDesc->fullPath);
		displayNAry(root->rightSibling);	//Pre-order traversal
		displayNAry(root->firstChild);
	}
			
}

void saveToFile(struct dirNode *root,FILE *fstore)
{
	if(root!=NULL)
	{
		//fwrite(&(root->fileDesc),sizeof(FileDescriptor),1,fstore);
		saveToFile(root->rightSibling,fstore);
		saveToFile(root->firstChild,fstore);
	}
	
}

void saveToArray(struct dirNode *root,FileDescriptor filedescArray[],int *count)
{
	//static int fd_count=0;
	if(root!=NULL)
	{
		filedescArray[(*count)++]=*(root->fileDesc);
		saveToArray(root->rightSibling,filedescArray,count);
		saveToArray(root->firstChild,filedescArray,count);
	}	
}
/*int main()
{
	int i;
	char ch;
	int *flag,f=100;
	flag=(int*)malloc(sizeof(int));
	flag=&f;
	FILE *fp,*fstore,*fp2;
	struct dirNode* root=NULL;
	FileDescriptor *fd;
	fstore=fopen("nary_store.dat","wb");
	//fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
	if((fp=fopen("inputfiledesc.txt","r"))==NULL)
		printf("Cannot open file");
	
	else
	{
		fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
		while(fscanf(fp,"%s",fd->fileName)!=EOF && *flag==100)
		{
			fscanf(fp,"%s",fd->fullPath);
			fscanf(fp,"%s",fd->fileType);
			fscanf(fp,"%ld",&fd->fileSize);
			fscanf(fp,"%d",&fd->locationBlockNo);
			root=insertNAry(fd,root,flag);
			printf("%d\n",*(flag));
			fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
		}
	}
	fclose(fp);
	displayNAry(root);
	saveToFile(root,fstore);
	fclose(fstore);	*/
	/*root=NULL;
	if((fp2=fopen("nary_store.dat","rb"))==NULL)
		printf("Cannot open file");
	else
	{
		fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
		while(fread(fd,sizeof(FileDescriptor),1,fp2))
		{			
			root=insertNAry(fd,root);
			fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
			//printf("%s",root->fileDesc->fullPath);
		}
	}
	displayNAry(root);
	fclose(fp2);*/
	
	//return 0;
//}



