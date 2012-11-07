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
	char* t;
	char* pat;
	pat=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));	
	char tokens[MAX_DIR][MAX_FULL_PATH_SIZE];
	struct dirNode* temp;
	struct dirNode* temp1;
	strcpy(tempPath,path);
	strcat(tempPath,"/x");		//parsepath returns only parent directory	
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
	strcpy(fd->fullPath,tempPath);
	temp = checkValidPath(fd,naryRoot,&flag);
	l=strlen(path);
	printf("\nl = %d\n",l);
	t=(char*)malloc(sizeof(10));
	
	if(flag==101)		//invalid path
	{
		printf("\nCANNOT_FIND_SPECIFIED_PATH_OR_DIR\n");
	}
	
	else 		//valid path
	{
	
		//extract directory name
		k=0;
		for(i=l-1;i>=0;i--)	
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
				
				
				
		//Generate tokens
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
		strcat(pat,"/");			
		k=0;
		//traverse to the parent directory		
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

		
		exitStatus=FALSE; 
		if(temp->firstChild==NULL)
		{
			printf("\nINVALID_DIRNAME\n");
			exitStatus=TRUE;
		}
		else
		{	
			temp1=temp->firstChild;
		}
		while(exitStatus==FALSE)
		{
		

				
			if(strcmp(temp1->fileDesc->fileName,dirName)==0)
			{
				if(strcmp(temp1->fileDesc->fileType,"dir")==0)
				{
					if(temp1->firstChild==NULL)
					{
						temp->firstChild=temp1->rightSibling;
						exitStatus=TRUE;
					}
					
					else
					{
						printf("\nDIRECTORY_IS_NOT_EMPTY\n");
						exitStatus=TRUE;					
					}
				}

			}
				
			else
			{

				while(exitStatus==FALSE)
				{
					if(temp1->rightSibling==NULL)
					{
						printf("\nINVALID_DIRNAME\n");
						exitStatus=TRUE;
					}
					
					else
					{
						temp=temp1;
						temp1=temp1->rightSibling;			
					
						if(strcmp(temp1->fileDesc->fileName,dirName)==0)
						{
							if(strcmp(temp1->fileDesc->fileType,"dir")==0)
							{
								if(temp1->firstChild==NULL)
								{
									temp->rightSibling=temp1->rightSibling;
									exitStatus=TRUE;
								}
							
								else
								{
									printf("\nDIRECTORY_IS_NOT_EMPTY\n");
									exitStatus=TRUE;					
								}
							}

						}
					}
				}
			}
			

		}
		
		printf("\n naryTree display  :  ");	
		displayNAry(naryRoot);
			
	}

}


