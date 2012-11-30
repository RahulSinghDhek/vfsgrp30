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

char* part2(char *path)
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

char* parsePath2(char *path)
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
			//printf("toke%d:%s\n",j,temp);
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
		//printf("pat%d:%s\n",i,pat);
		strcat(pat,"/");
	}
	return pat;
}

int export_file(char path1[],char path2[]){
	
	FILE *fp,*fp1;
	int index=0;char c;	int check=0;int j;
	//printf("root:%s\n",naryRoot->fileDesc->fullPath);
	int flag=ERROR_FREE;//printf("%d",flag);	
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
	 flag=iscorrectPath2(fd,naryRoot,flag);
	//printf("%s\n",path11);
	//printf("%d",flag);
	if(naryRoot == NULL)
		printf(ERR_VFS_EXPORTFILE_04);	
	
	else if(flag ==PATH_NOT_FOUND)
		{
		printf(ERR_VFS_EXPORTFILE_01);
		}


	else 

		{	
					int i=0;int bno1=10;
					int size=0;char type[10];
					if((fp1=fopen(label,"rb+"))==NULL)
					{
						//printf("Error in opening  file\n");
					}
					else
					{
						//printf("exporting....\n");
						struct BSTnode *p=(struct BSTnode *)malloc(sizeof(struct BSTnode));
						p=searchBST(rootBST,path1);
                                              //printf("\n export path : %s\n",path1);
							if(p!=NULL){
							bno1=p->filedesc->locationBlockNo;
							size=p->filedesc->fileSize;
							strcpy(type,p->filedesc->fileType);
							int x=strcmp(type,"file");
		                                      	if(x) 
							printf(ERR_VFS_EXPORTFILE_03);
							else if(x==0)
								{
						
											
									fseek(fp1,sizeof(MetaHeader),SEEK_SET);
									fseek(fp1,bno1*sizeof(Block),SEEK_CUR);
									str[0]=fgetc(fp1);
									 int i=0;
						
									while(i<=size)
									{
									str[++i]=fgetc(fp1);
									
									}
									str[i-1]='\0';						
									fclose(fp1);			
									//printf(" \n %s this is from export file\n",str);



						
						
							
		
									
									
					
					
					char *fileName=NULL;
					fileName=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));
					fileName=part2(path1);
				       
					
					
					strcat(path2,"/");
					strcat(path2,fileName);
					
 					strcat(path2,".txt");
					
					fp=fopen(path2,"w");
					if(fp==NULL)	
					printf(ERR_VFS_EXPORTFILE_02);
					else
					{
					fprintf(fp,"%s",str);//printf("%s", str);
					check=1;
					fclose(fp);
					}
					}
				}
		}

}
return check;
}




int iscorrectPath2(FileDescriptor *fd,struct dirNode* root,int flag)
{
	int l,exitStatus;
	struct dirNode *parent;
	
char temp_path1[MAX_FULL_PATH_SIZE];
	char *path_part1;
	path_part1==(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));	
	strcpy(temp_path1,fd->fullPath);
	//strcpy(path_part,parsePath(temp_path));
//printf("%s\n",temp_path1);		
path_part1=parsePath2(temp_path1);
//printf("%s\n",path_part1);





/*char temp_path[MAX_FULL_PATH_SIZE];
	char path_part[MAX_FULL_PATH_SIZE];
	//path_part==(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));	
	strcpy(temp_path,fd->fullPath);
	strcpy(path_part,parsePath(temp_path));
printf("%s",temp_path);	
//path_part=parsePath(temp_path);
printf("%s\n",path_part);*/
	if(root==NULL)
	{
		if(strcmp(path_part1,"/")!=0)		//for root path
			flag=PATH_NOT_FOUND;			//wrong path trying to insert at root
	}
	else
	{
		exitStatus=FALSE;
		parent=root;
		while(exitStatus==FALSE)
		{
			if(strstr(path_part1,parent->fileDesc->fullPath)==NULL)
			{
				if(parent->rightSibling==NULL)
				{
					if(strncmp(path_part1,parent->fileDesc->fullPath,strlen(path_part1)-1)!=0){
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
					if(strncmp(path_part1,parent->fileDesc->fullPath,strlen(path_part1)-1)!=0){
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




