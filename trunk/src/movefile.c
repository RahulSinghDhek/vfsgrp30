#include<stdio.h>
#include<string.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"
#include "hashTable.h"

#define TRUE 1
#define FALSE 0
#define MAX_NAME 10
#define MAX_DIR 10

char* part1(char *path)
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
	
	return temp;
}


void move_file(char path1[],char path2[]){
	
	FILE *fp,*fp1;
	int index=0;char c;	
	int flag=ERROR_FREE;
	char pathcpy[MAX_FULL_PATH_SIZE];
	strcpy(pathcpy,path1);
	char path11[MAX_FULL_PATH_SIZE];
	char str[MAX_BLOCK_SIZE];
	strcpy(path11,path1);
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	char sourcePath[MAX_FULL_PATH_SIZE];
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	char path22[MAX_FULL_PATH_SIZE];
	strcpy(path22,path2);
	FileDescriptor *fd;
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
        strcpy(fd->fullPath,strcat(path11,"/d")); 
	 flag=iscorrectPath1(fd,naryRoot,flag);
	strcpy(fd->fullPath,strcat(path22,"/d"));
         flag=iscorrectPath1(fd,naryRoot,flag);
	
	if(flag ==PATH_NOT_FOUND)
		{
			printf(" wrong path, please enter correct path \n\n\n");
		}
	else
		{	
			int i=0;int bno=0;int size=0;int j=0;
			FileDescriptor *fd1;
			fd1=(FileDescriptor*)malloc(sizeof(FileDescriptor));
			
		
									

				
				
				if((fp1=fopen(label,"rb+"))==NULL)
					{
						printf("Error in opening  file\n");
					}
					else
					{
						struct BSTnode *p=(struct BSTnode *)malloc(sizeof(struct BSTnode));
							p=searchBST(rootBST,path1);
						if(p!=NULL){
						bno=p->filedesc->locationBlockNo;
						size=p->filedesc->fileSize;
						
                                           		}
						printf("\n%d %d\n",bno,size);

								char *fileName;
								fileName=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));
								fileName=part1(path1);
								strcat(path2,"/");
							strcat(path2,fileName);							
								
								FileDescriptor *fd=NULL;
								fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
								strcpy(fd->fileName,fileName);
								strcpy(fd->fullPath,path2);
								strcpy(fd->fileType,"file");
								
								fd->fileSize=size;
								fd->locationBlockNo=bno;
								insertNAry(fd,naryRoot,&flag);
									//displayNAry(naryRoot);
								//printf("deleted path should be %s\n",pathcpy);
								
								//removeFile(pathcpy);
						}
				fclose(fp1);						
			}

						
}
					

				     
					
					
					
					
					
					
			

		



					





















			






int iscorrectPath1(FileDescriptor *fd,struct dirNode* root,int flag)
{
	int l,exitStatus;
	struct dirNode *parent;
	char temp_path[MAX_FULL_PATH_SIZE];
	char *path_part;
	path_part==(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));	
	strcpy(temp_path,fd->fullPath);
	//strcpy(path_part,parsePath(temp_path));
	path_part=part1(temp_path);
	if(root==NULL)
	{
		if(strcmp(path_part,"/")!=0)		//for root path
			flag=PATH_NOT_FOUND;			//wrong path trying to insert at root
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
						 flag=PATH_NOT_FOUND;
						
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
						flag=PATH_NOT_FOUND;
						
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
     return flag;		
}




