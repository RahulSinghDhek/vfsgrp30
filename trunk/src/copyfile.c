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


char* parsePath1(char *path)
{
	int l,i,j=0,dec=1,k=0;
	char *temp;
	char *pat=NULL;
	pat=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));
	char tokens[MAX_DIR][MAX_FULL_PATH_SIZE];
	temp=(char*)malloc(sizeof(20));			//CHAGE IT
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
	strcpy(pat,"");	
	strcat(pat,"/");
	for(i=0;i<j;i++){
		strcat(pat,tokens[i]);
		strcat(pat,"/");
	}
	return pat;
	
}




















char* part(char *path)
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











int copy_file(char paths1[],char paths2[]){
	int check=0;
	
	FILE *fp,*fp1;
	int index=0;char c;	
	int flag=ERROR_FREE;
	int flag1=ERROR_FREE; int flag2=ERROR_FREE;	
	char path11[MAX_FULL_PATH_SIZE];
	char str[MAX_BLOCK_SIZE];
	strcpy(path11,paths1);
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	char sourcePath[MAX_FULL_PATH_SIZE];
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	char path22[MAX_FULL_PATH_SIZE];
	strcpy(path22,paths2);
	FileDescriptor *fd;
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
        strcpy(fd->fullPath,strcat(path11,"/d")); 
	flag1=iscorrectPath(fd,naryRoot,flag);
	strcpy(fd->fullPath,strcat(path22,"/d"));
         flag2=iscorrectPath(fd,naryRoot,flag);
	
	if(naryRoot == NULL)
		printf(ERR_VFS_COPYFILE_05);	
	else if(flag1 ==PATH_NOT_FOUND)
		{
		printf(ERR_VFS_COPYFILE_01);
		}
	else if(flag2==PATH_NOT_FOUND)
		{
		printf(ERR_VFS_COPYFILE_02);	
		}
	
	else 
		{
			int i=0;int bno1=10;int size=0;int j=0;	char type[10];
			FileDescriptor *fd1;
			
			fd1=(FileDescriptor*)malloc(sizeof(FileDescriptor));
			if((fp1=fopen(label,"rb+"))==NULL)
				{
				 printf("Error in opening FILE SYSTEM \n");
				}
			else
				{
					struct BSTnode *p=(struct BSTnode *)malloc(sizeof(struct BSTnode));
					p=searchBST(rootBST,paths1);
					if(p!=NULL)	
					{
						bno1=p->filedesc->locationBlockNo;
						size=p->filedesc->fileSize;
						strcpy(type,p->filedesc->fileType);
						int x=strcmp(type,"file");
						//printf("%d raju \n",x);
						//printf("%d",bno1);
						if(x) 
						printf(ERR_VFS_COPYFILE_03);
						else if(x==0)
						{
		                                  	fseek(fp1,sizeof(MetaHeader),SEEK_SET);
							fseek(fp1,bno1*sizeof(Block),SEEK_CUR);
							str[0]=fgetc(fp1);
							i=0;
						
							while(i<=size)
								str[++i]=fgetc(fp1);
							str[i-1]='\0';						    
							fseek(fp1,sizeof(MetaHeader),SEEK_SET);
						        for(j=0;mhd.FreeList[j]!=0;j++);
					
							fseek(fp1,j*sizeof(Block),SEEK_CUR);
							fwrite(str,i*sizeof(char),1,fp1);
							mhd.FreeList[j]=1;
					
							char *fileName;
							fileName=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));
							fileName=part(paths1);
							strcat(paths2,"/");
							strcat(paths2,fileName);
							strcpy(fd1->fileName,fileName);
							strcpy(fd1->fullPath,paths2);
							strcpy(fd1->fileType,"file");
							fd1->fileSize=size;
							fd1->locationBlockNo=j;
							naryRoot=insertNAry(fd1,naryRoot,&flag);
							rootBST=insertBST(rootBST,fd1,&flag);
							index = fun_Hash(fd1->fileName[0]);
							array[index] = insertnode(array[index], fd1);
							check=1;
									
					}
				
				}
		fclose(fp1);			
		}

}
return check;
}



int iscorrectPath(FileDescriptor *fd,struct dirNode* root,int flag)
{


FileDescriptor *fd2;
			fd2=fd;
			
	int l,exitStatus;
	struct dirNode *parent;
	char temp_path[MAX_FULL_PATH_SIZE];
	char *path_part;
	path_part==(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));	
	strcpy(temp_path,fd2->fullPath);
	//strcpy(path_part,parsePath(temp_path));
	//printf("%s\n",temp_path);		
	path_part=parsePath1(temp_path);
	//printf("%s\n",path_part);
	if(root==NULL)
	{
		if(strcmp(path_part,"/")!=0)		//for root path
			flag=PATH_NOT_FOUND;		//wrong path trying to insert at root
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




