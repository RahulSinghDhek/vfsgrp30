//changed on 28th Nov,2012
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"


struct dirNode *tempRoot;
void displayNonRecursive(struct dirNode* root,FILE *fp)
{
	if(root!=NULL)
	{
		fprintf(fp,"%s\n",root->fileDesc->fileName);
		displayNonRecursive(root->rightSibling,fp);
	}
}

void displayRecursive(struct dirNode* root,FILE *fp)
{
	if(root!=NULL)
	{
		fprintf(fp,"%s\n",root->fileDesc->fileName);
		displayRecursive(root->rightSibling,fp);
		displayRecursive(root->firstChild,fp);
	}
}

struct dirNode* searchNary(struct dirNode* root,char src_path[])
{
	if(root!=NULL){
		if(strcmp(root->fileDesc->fullPath,src_path)==0){
			//printf("%s",root->fileDesc->fileName);
			tempRoot=root;
		}
		searchNary(root->rightSibling,src_path);
		searchNary(root->firstChild,src_path);
	}	
}

int listdirs(char src_path[],int flag,char dest_path[])
{
	//printf("\n naryTree display at begining :  ");	
	//displayNAry(naryRoot);	
	tempRoot=NULL;
	int check=0;
	if(naryRoot==NULL)
		printf(ERR_VFS_LISTDIR_03);	//VFS_NOT_MOUNTED
	else if(!(flag==0||flag==1))
		printf(ERR_VFS_LISTDIR_02);	//INVALID_FLAG
	else
	{
		FILE *fptr;
		fptr=fopen(dest_path,"w");
		if(fptr==NULL)
			printf(ERR_VFS_LISTDIR_04);	//CANNOT_CREATE_OUTPUTFILE
		else
		{
			searchNary(naryRoot,src_path);
			if(tempRoot==NULL)
				printf(ERR_VFS_LISTDIR_01);	//CANNOT_FIND_SPECIFIED_PATH_OR_DIR	
			else
			{
				tempRoot=tempRoot->firstChild;	
				if(tempRoot!=NULL&&flag==0)
				{	check=1;
					displayNonRecursive(tempRoot,fptr);
				}
				else if(tempRoot!=NULL&&flag==1)
				{	displayRecursive(tempRoot,fptr);
					check=1;
				}
				else
					printf(ERR_VFS_LISTDIR_01);	//CANNOT_FIND_SPECIFIED_PATH_OR_DIR
			}		     
		}	
	}
	return check;	
}
	
