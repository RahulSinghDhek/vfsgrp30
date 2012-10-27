#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"

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
		if(strcmp(root->fileDesc->fullPath,src_path)==0)
			return root;
		searchNary(root->rightSibling,src_path);
		searchNary(root->firstChild,src_path);
	}	
}

void listdirs(char src_path[],int flag,char dest_path[])
{
	FILE *fptr;
	fptr=fopen(dest_path,"w");
	if(fptr==NULL)
		printf("Cannot open file");
	else
	{
	struct dirNode *tempRoot;
	tempRoot=searchNary(naryRoot,src_path);
	if(tempRoot==NULL)
		printf("\nNo file found\n");
	tempRoot=tempRoot->firstChild;
	if(tempRoot!=NULL&&flag==0)
		displayNonRecursive(tempRoot,fptr);
	else
	if(tempRoot!=NULL&&flag==1)
		displayRecursive(tempRoot,fptr);
	else
		printf("ERROR:Path not found");
	}	
}

