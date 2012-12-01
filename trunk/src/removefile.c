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

int removeFile(char path[])
{
	printf("\n naryTree display beg of delete: fivvvj   ");	
	displayBST(rootBST);
	displayNAry(naryRoot);		
	char tempPath[MAX_FULL_PATH_SIZE], dirName[MAX_FULL_PATH_SIZE], tempDir[MAX_FULL_PATH_SIZE];
	int l,i,k,j,exitStatus,dec=1,f=0,check=0 ;	
	char* t;
	char pat[MAX_FULL_PATH_SIZE]="";
	//pat=(char*)malloc(sizeof(MAX_FULL_PATH_SIZE));	
	char tokens[MAX_DIR][MAX_FULL_PATH_SIZE]={"",""};
	struct dirNode* temp=NULL;
	struct dirNode* temp1=NULL;
	struct BSTnode *root;
	//strcpy(tempPath,path);
	//strcat(tempPath,"/x");					 
	//fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
	//strcpy(fd->fullPath,tempPath);
	//printf("temp path = %s\n",tempPath);
	
	
	
	if(naryRoot == NULL)
		printf(ERR_VFS_REMOVEFILE_02);                                                 //VFS NOT MOUNTED
	else
	{ 
		root = searchBST(rootBST ,path);
		if(root!=NULL)
		{
			printf(ERR_VFS_REMOVEFILE_01); 
			return check;
		}
		//temp = checkValidPath(fd,naryRoot,&flag);
		
		else 		
		{
			temp = naryRoot;
			//printf("\ntemp = %s\n",temp->fileDesc->fullPath);
			//printf("\ntemp1 = %s\n",temp1->fileDesc->fullPath);
			l=strlen(path);	
			t=(char*)malloc(sizeof(10));
			//printf("\nBefore deletion\n");
			//printf("\n naryTree display  :  ");	
			//displayNAry(naryRoot);
	
	//*************************************EXTRACT DIRECTORY NAME************************************//
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
			dirName[i-1]='\0';	
			//printf("dir name = %s\n",dirName);	
			
			//printf("\nbefore generation of tokens\n");
			//for(i=0;i<1;i++)
				//printf("\ntokens = %s\n",tokens[i]);
			//for(i=0;i<l;i++)
				//printf("\n%s",path);	
				
	//***********************************GENERATE TOKENS*********************************//
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
	//******************************Copy the token when you get '/'****************************//
					strcpy(tokens[j],t);		
					//printf("\nj = %d token = %s\n",j,tokens[j]);
					j++;
					dec=1;
				}
				else
				{
	//************************************Append to temp until '/' in the path*****************************//
					*(t+k)=path[i];	 	
					k++;
				}
			}
			*(t+k)='\0';
			strcpy(tokens[j],t);
			strcat(pat,"/");			
			
			//printf("\nj=%d\n",j);
			//printf("\nafter tokens");
			//for(i=0;i<j;i++)
				//printf("\ni = %d tokens = %s\n",i,tokens[i]);
			//printf("path of parent dir = %s\n",pat);
			
			
				
			f=0;
			k=0;
			//printf("\ntoken = %s\n",tokens[k]);
			
			
	//**********************************TRAVERSE TO PARENT DIRECTORY BEGIN*************************//
			while(k<=j)
			{
				if(strcmp(pat,temp->fileDesc->fullPath)==0)
				{
					if(f==1)
						strcat(pat,"/");
					strcat(pat,tokens[k]);
					temp1=temp;
					//printf("\ntemp1 = %s\n",temp1->fileDesc->fullPath);
					temp=temp->firstChild;
					k++;
					f=1;
					
					//printf("\n in if cond. value of k is %d\n",k);
					//printf("\npat = %s\n",pat);
					//printf("\ntemp = %s\n",temp->fileDesc->fullPath);
				}
			
				else
				{
					temp1=temp;
					temp=temp->rightSibling;
					//printf("\n in else cond.\n");
				}
			}
			
			//strcpy(temp->fileDesc->fullPath,pat);
			printf("\ntemp.... = %s\n",temp1->fileDesc->fullPath);
			//printf("%s\n",temp->fileDesc->fileName);
			//printf("\nparent dir = %s\n",temp1->firstChild->fileDesc->fullPath);
			temp=temp1;

	//*********************************TRAVERSE TO PARENT DIRECTORY END*******************************//
	
	
			exitStatus=FALSE; 
			if(temp->firstChild==NULL)
			{
				printf(ERR_VFS_DELETEDIR_01);	
				
				displayBST(rootBST);	
				
		//**********************************CANNOT_FIND_SPECIFIED_DIR2**********************************//
				
				
				
				printf("not error code: CANNOT_FIND_SPECIFIED_DIR2");	
				//printf("(temp->firstChild==NULL)");			
				exitStatus=TRUE;
			}
			else
			{	
				temp1=temp->firstChild;
			}
			while(exitStatus==FALSE)
			{
		
	//*************************Delete first child******************************//
				printf("%s\n",temp1->fileDesc->fileName);
				printf("%s\n",dirName);
				
				if(strcmp(temp1->fileDesc->fileName,dirName)==0)
				{
					if(strcmp(temp1->fileDesc->fileType,"file")==0)
					{
						if(temp1->firstChild==NULL)
						{
							temp->firstChild=temp1->rightSibling;
							check = 1;
							mhd.noOfFileDescriptors=mhd.noOfFileDescriptors-1;
							mhd.FreeList[temp1->fileDesc->locationBlockNo]=0;
							deleteBST(rootBST, path);
							exitStatus=TRUE;
						}
					
						else
						{
							printf(ERR_VFS_DELETEDIR_02);	
							
								                    
							
							
		//**********************************DIRECTORY_IS_NOT_EMPTY1**********************************//
			
			
							
							printf("not error code: DIRECTORY_IS_NOT_EMPTY1");
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
							printf(ERR_VFS_DELETEDIR_01);	
							
							displayBST(rootBST);	                  
			
		//**********************************CANNOT_FIND_SPECIFIED_DIR3**********************************//
			
			
			
							printf("not error code: CANNOT_FIND_SPECIFIED_DIR3");
							//printf("(temp1->rightSibling==NULL)\n");
							printf("%s\n",temp1->fileDesc->fileName);
							exitStatus=TRUE;
						}
					
						else
						{
						
	//*******************************Delete right sibling************************************//
							temp=temp1;
							temp1=temp1->rightSibling;			
					
							if(strcmp(temp1->fileDesc->fileName,dirName)==0)

								if(strcmp(temp1->fileDesc->fileType,"file")==0)
								{	
										temp->rightSibling=temp1->rightSibling;
										check = 1;
										mhd.noOfFileDescriptors=mhd.noOfFileDescriptors-1;
										mhd.FreeList[temp1->fileDesc->locationBlockNo]=0;
										deleteBST(rootBST, path);
										exitStatus=TRUE;
								}

							}
						}
					}
				}
			

			}
		
			
		
		
	//printf("\nAfter deletion\n");
	//printf("\nnaryTree display  :  \n");	
	//displayNAry(naryRoot);
	}

return check;

	
}


