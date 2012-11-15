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











void copy_file(char paths1[],char paths2[]){
	
	//printf("hi");
	FILE *fp,*fp1;
	int index=0;char c;	
	int flag=ERROR_FREE;	
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
	// flag=iscorrectPath(fd,naryRoot,flag);
	strcpy(fd->fullPath,strcat(path22,"/d"));
        // flag=iscorrectPath(fd,naryRoot,flag);
	//printf("79");
	if(flag ==PATH_NOT_FOUND)
		{
			printf(" wrong path, please enter correct path \n\n\n");
		}
	else
		{	
			int i=0;int bno1=10;int size=0;int j=0;
			FileDescriptor *fd1;
			fd1=(FileDescriptor*)malloc(sizeof(FileDescriptor));
			
		
									
//printf("92");
				
				
				if((fp1=fopen(label,"rb+"))==NULL)
					{
						printf("Error in opening  file\n");
					}
					else
					{
						


					struct BSTnode *p=(struct BSTnode *)malloc(sizeof(struct BSTnode));
							p=searchBST(rootBST,paths1);
						if(p!=NULL){
						bno1=p->filedesc->locationBlockNo;
						size=p->filedesc->fileSize;
                                              	 }



						/*for(i=0;i<MAX_NO_OF_FILE_DESCRIPTORS;i++)
						{
						
						

						if(strcmp(mhd.filedescArray[i].fullPath,path1)==0)
								{
															
								bno=mhd.filedescArray[i].locationBlockNo;
							size=mhd.filedescArray[i].fileSize;
						}
						
						
						}*/
						printf(" copy file block %d\n",bno1);
						printf("size of %d",size);
						fseek(fp1,sizeof(MetaHeader),SEEK_SET);
						
						
						fseek(fp1,bno1*sizeof(Block),SEEK_CUR);

						//fseek(fp1,-1,SEEK_CUR);	
						
						//i=0;
						//str[0]=fgetc(fp1);
						
						//str[i]='\0';
									
						//fscanf(fp1,"%s",str);


					str[0]=fgetc(fp1);
					i=0;
						
					while(i<=size)
						{
						str[++i]=fgetc(fp1);
							
								}
						str[i]='\0';						

					}
					

				    printf("%s\n",str); 
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
					//printf("%s",fd1->fullPath);
					fd1->fileSize=size;
					fd1->locationBlockNo=j;
					naryRoot=insertNAry(fd1,naryRoot,&flag);
					
					rootBST=insertBST(rootBST,fd1,&flag);
					
					index = fun_Hash(fd1->fileName[0]);
					array[index] = insertnode(array[index], fd1);
					//fclose(fp1);
			

		}

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




