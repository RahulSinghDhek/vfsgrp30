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
#define MAX_DIR 10

void delete_dir(char path[])
{
	FileDescriptor *fd;	
	char tempPath[MAX_FULL_PATH_SIZE], dirName[MAX_FULL_PATH_SIZE], tempDir[MAX_FULL_PATH_SIZE];
	int l,i,k,j,exitStatus,dec=1,f=0;
	//char* parentDir;
	char* t;
	char* pat;
	pat=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));
	//char* currentFullPath;
	char tokens[MAX_DIR][MAX_FULL_PATH_SIZE];
	struct dirNode* temp;
	struct dirNode* temp1;
	strcpy(tempPath,path);
	strcat(tempPath,"/x");		//parsepath returns only parent directory	
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
	strcpy(fd->fullPath,tempPath);
	temp = checkValidPath(fd,naryRoot,&flag);
	//printf("\n%s\n",temp->fileDesc->fullPath);
	//printf("\n%s\n",naryRoot->fileDesc->fullPath);
	//printf("\n%s\n",naryRoot->firstChild->fileDesc->fullPath);
	//char* a=temp->firstChild->firstChild->fileDesc->fullPath;
	//strcat(a,"/");
	//printf("\n%s\n",a);
	//temp=temp->firstChild->firstChild;
	//printf("\n%s\n",temp->firstChild->rightSibling->rightSibling->fileDesc->fileName);
	l=strlen(path);
	printf("\nl = %d\n",l);
	t=(char*)malloc(sizeof(10));
	
	if(flag==101)		//invalid path
	{
		printf("\ndeletedir_FAILURE: DIRECTORY DOES NOT EXIST\n");
	}
	
	else 		//valid path
	{
	
		
		k=0;
		for(i=l-1;i>=0;i--)	//extract directory name
		{		
	
			if(path[i]=='/')	
			{
				break;
			}
			else
			{
				tempDir[k]=path[i];	
				k++;
			}
		}
				
		
		j=k-1;
		for(i=0;i<=k;i++)
		{
			dirName[i]=tempDir[j];
			j--;
		}
		printf("\ndir is %s",dirName);
		
		
		
		////////////////////////////////////////////////
		j=0;
		for(i=1;i<l;i++)
		{		
			if(dec==1)
			{
				k=0;
				dec=0;
			}	
			if(path[i]=='/')	
			{

				*(t+k)='\0';
				strcpy(tokens[j],t);		//Copy the token when you get '/'
				j++;
				dec=1;
			}
			else
			{
				*(t+k)=path[i];	 //Append to temp until '/' in the path
				k++;
			}
		}
		*(t+k)='\0';
		strcpy(tokens[j],t);
		//printf("\ntokens");
		//for(i=0;i<j;i++)
			//printf("\n%s",tokens[i]);
		////////////////////////////////////////////////////////////////
		strcat(pat,"/");		
		//printf("\npat = %s",pat);
		k=0;
		while(k<j)
		{
			if(strcmp(pat,temp->fileDesc->fullPath)==0)
			{
				if(f==1)
					strcat(pat,"/");
				strcat(pat,tokens[k]);
				temp=temp->firstChild;
				k++;
				f=1;
			}
			
			else
			{
				temp=temp->rightSibling;
			}
		}
		
		//printf("\nafter while");
		//printf("\npat = %s",pat);
		//printf("\ntemp = %s",temp->firstChild->fileDesc->fullPath);
		
		exitStatus=FALSE; 
		//parentDir = parsePath(path);
		//strcpy(temp1->fileDesc->fullPath,parentDir);
		//printf("\nfirst child of parent directory: ",temp1->firstChild->fileDesc->fileName);
		//printf("\nParent Directory is %s",parentDir);
		temp1=temp->firstChild;
		while(exitStatus==FALSE)
		{
		

				
			if(strcmp(temp1->fileDesc->fileName,dirName)==0)
			{
				if(strcmp(temp1->fileDesc->fileType,"dir")==0)
				{
					temp->firstChild=temp1->rightSibling;
					exitStatus=TRUE;
			}

			}
				
			else
			{

				while(exitStatus==FALSE)
				{
					temp=temp1;
					temp1=temp1->rightSibling;
					if(strcmp(temp1->fileDesc->fileName,dirName)==0)
					{
						if(strcmp(temp1->fileDesc->fileType,"dir")==0)
						{
							temp->rightSibling=temp1->rightSibling;
							exitStatus=TRUE;
						}

					}
				}
			}
			

		}
		
		printf("\n naryTree display  :  ");	
		displayNAry(naryRoot);
		printf("\nValid Path\n");	
	}

}


