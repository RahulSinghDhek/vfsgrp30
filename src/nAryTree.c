#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "hashTable.h"

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
	char pat[MAX_FULL_PATH_SIZE]="";
	//char *pat;
	//pat =(char *)malloc(sizeof(char) * MAX_FULL_PATH_SIZE);
	char tokens[MAX_DIR][MAX_FULL_PATH_SIZE]={};
	temp=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));			//CHAGE IT
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
	//pat[0]='/';
	for(i=0;i<j;i++){
		strcat(pat,tokens[i]);
		strcat(pat,"/");
	}
	return  pat;
}
struct dirNode* isValidPath(FileDescriptor *fd,struct dirNode* root,int *flag)
{
	int l,exitStatus;
	int index=0;
	struct dirNode *parent;
	char temp_path[MAX_FULL_PATH_SIZE],path_part[MAX_FULL_PATH_SIZE];
	char *tmp;
	char st[MAX_FULL_PATH_SIZE],prev[MAX_FULL_PATH_SIZE];
	char *tk;
	tmp=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));	
	strcpy(temp_path,fd->fullPath);
	//strcpy(path_part,parsePath(temp_path));
	tmp=parsePath(temp_path);
	//printf("\ntmp:%s\n",tmp);
	strcpy(path_part,tmp);
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
					    if(mhd.noOfFileDescriptors == MAX_NO_OF_FILE_DESCRIPTORS)
						{
							printf(ERR_VFS_MAKEDIR_01);
							*flag=401;
							return root;
						}	
						else
						{
							FileDescriptor *tempfd1=(FileDescriptor*)malloc(sizeof(FileDescriptor));
							strncpy(tempfd1->fullPath,path_part,strlen(path_part)-1);
							strcpy(st,path_part);
							tk=strtok(st,"/");
							while(tk!=NULL)
							{

								strcpy(prev,tk);
								//printf("\nprev:%s ",prev);
								tk=strtok(NULL,"/");
							}	
							
							strcpy(tempfd1->fileName,prev);
							strcpy(tempfd1->fileType,"dir");
							tempfd1->fileSize=0;
							tempfd1->locationBlockNo=-1;
							mhd.noOfFileDescriptors++;

							insertNAry(tempfd1,root,flag);
							insertBST(rootBST,tempfd1,&flag);
							index = fun_Hash(tempfd1->fileName[0]);
							array[index] = insertnode(array[index], tempfd1);
							
						}
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
					if(strncmp(path_part,parent->fileDesc->fullPath,strlen(path_part)-1)!=0)
					{
						if(mhd.noOfFileDescriptors == MAX_NO_OF_FILE_DESCRIPTORS)
						{
							printf(ERR_VFS_MAKEDIR_01);
							*flag=401;
							return root;
						}		
						else
						{	
							FileDescriptor *tempfd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
							strncpy(tempfd->fullPath,path_part,strlen(path_part)-1);
							strcpy(st,path_part);
							tk=strtok(st,"/");
							while(tk!=NULL)
							{
								strcpy(prev,tk);
								//printf("\nprev:%s ",prev);
								tk=strtok(NULL,"/");
							}	
							
							strcpy(tempfd->fileName,prev);
							strcpy(tempfd->fileType,"dir");
							tempfd->fileSize=0;
							tempfd->locationBlockNo=-1;	
							mhd.noOfFileDescriptors++;	

							insertNAry(tempfd,root,flag);
							insertBST(rootBST,tempfd,&flag);
							index = fun_Hash(tempfd->fileName[0]);
							array[index] = insertnode(array[index], tempfd);
	
						}							
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

struct dirNode* checkValidPath(FileDescriptor *fd,struct dirNode* root,int *flag)
{
	int l,exitStatus;
	struct dirNode *parent;
	char temp_path[MAX_FULL_PATH_SIZE];
	char *path_part;
	path_part==(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));
	strcpy(temp_path,fd->fullPath);
	path_part=parsePath(temp_path);
	if(root==NULL)
	{
		if(strcmp(path_part,"/")!=0) //for root path
			*flag=101; //wrong path trying to insert at root
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
						*flag=PATH_NOT_FOUND;
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
						*flag=PATH_NOT_FOUND;
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
		//*flag=NOT_ENOUGH_MEMORY;
		exit(0);
	}
	//printf("before");
	root=isValidPath(fd,root,flag);
	//printf("after");
	if(*flag==101){
		printf(ERR_VFS_MAKEDIR_03);
		*flag=401;
		//printf("\nwrong path entered\n");		
	}
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
					//printf("%s\n",p->fileDesc->fullPath);
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
		puts(root->fileDesc->fileName);
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
		//printf("\nin save:%s\n",root->fileDesc->fullPath);
		saveToArray(root->rightSibling,filedescArray,count);
		saveToArray(root->firstChild,filedescArray,count);
	}	
}
//-------------------------------------------List directoriers---------------------------------------------------------

/*void list_dir(char src_path[],int flag,char dest_path[])
{
	FILE *fp;
	fp=fopen("list_dir_output.txt","w");
	if(fp==NULL)
		printf("Cannot open file");
	else
	{
	dirNode *tempRoot=NULL;
	tempRoot=searchNary(naryRoot,src_path);
	if(tempRoot!=NULL&&flag==0)
		displayNonrecursive(tempRoot->leftChild,fp);
	else
	if(tempRoot!=NULL&&flag==1)
		displayRecursive(tempRoot->leftChild,fp);
	else
		printf("ERROR:Path not found");
	}	
}

void displayNonRecursive(dirNode* root,FILE *fp)
{
	if(root!=NULL)
	{
		fprintf(fp,"%s",root->fileDesc->fileName);
		displayNonRecursive(root->rightSibling);
	}
}

void displayRecursive(dirNode* root,FILE *fp)
{
	if(root!=NULL)
	{
		fprintf(fp,"%s",root->fileDesc->fileName);
		displayNonRecursive(root->rightSibling);
		displayNonRecursive(root->leftChild);
	}
}

dirNode* searchNary(dirNode* root,char src_path[])
{
	if(root!=NULL){
		if(strcmp(root->fileDesc->fullPath,src_path)==0&&(strcmp(root->fileDesc->fileType,"dir")==0))
			return root;
		searchNary(root->rightSibling);
		searchNary(root->leftSibling);
	}	
}
*/


//void list_dir(

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



