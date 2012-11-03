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

#define ERR_VFS_MOVEDIR_01 "CANNOT_FIND_SPECIFIED_SOURCEDIR"
#define ERR_VFS_MOVEDIR_02 "CANNOT_FIND_SPECIFIED_DESTINATIONDIR"
//--hv to do dis on driver file..#define ERR_VFS_MOVEDIR_03 "SOURCE_PATH_MISSING"
//--hv to do dis on driver file..#define ERR_VFS_MOVEDIR_04 "DESTINATION_PATH_MISSING"
#define ERR_VFS_MOVEDIR_05 "DESTINATION_ALREADY_HAVE_SOURCE_DIR"

char* parse_Path(char *path)
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
int chkNonRecursive(struct dirNode* root, char currDirName[])
{
	if(root!=NULL)
	{
		//fprintf(fp,"%s\n",root->fileDesc->fileName);
		if(strcmp(root->fileDesc->fileName,currDirName)==0)
			return FALSE;
		chkNonRecursive(root->rightSibling, currDirName);
	}
}

int checkSrcExistsInDest(char src_path[], char dest_dir_path[])
{	struct dirNode *temp;
	char *currDirName;
	
	strcat(src_path,"/z");
	currDirName = parse_Path(src_path);
	temp=searchNary(naryRoot, dest_dir_path);		//Globle
	temp= temp->firstChild;
	return chkNonRecursive(temp, currDirName);
}

struct dirNode * rmvFrmSrcNode(char source_dir_path[])
{	struct dirNode *curr=NULL, *prev=NULL;
	curr = naryRoot;
	int exitStatus;
	struct dirNode *parent;
	
	if(naryRoot->firstChild==NULL)
	{
		if(strcmp(source_dir_path,"/")!=0)	
			printf("wrong path");			
	}
	else
	{
		exitStatus=FALSE;
		parent=naryRoot;
		while(exitStatus==FALSE)
		{	
			if(strstr(source_dir_path,parent->fileDesc->fullPath)==NULL)
			{	
				if(parent->rightSibling==NULL)
					exitStatus=TRUE;
				else
				{	prev = parent;
					parent=parent->rightSibling;
					curr = parent;
				}
			}
			else
			{	
				if(parent->firstChild==NULL)
					exitStatus=TRUE;	
				else
				{	if(strcmp(source_dir_path,parent->fileDesc->fullPath)==0)
						exitStatus=TRUE;
					else
					{	prev = parent;
						parent=parent->firstChild;
						curr = parent;
					}
				}	
			}
		}
		if(prev->firstChild == curr)
			prev->firstChild = curr->rightSibling;
		else if(prev->rightSibling == curr)
			prev->rightSibling = curr->rightSibling;
	}
return curr;
}

struct dirNode * returnDesNode(char source_dir_path[])
{	struct dirNode *curr=NULL;
	curr = naryRoot;
	int exitStatus;
	struct dirNode *parent;
	
		exitStatus=FALSE;
		parent=naryRoot;
		while(exitStatus==FALSE)
		{	
			if(strstr(source_dir_path,parent->fileDesc->fullPath)==NULL)
			{	parent=parent->rightSibling;
				curr = parent;	
			}
			else
			{	if(strcmp(source_dir_path,parent->fileDesc->fullPath)==0)
					return curr;
				else
				{	parent=parent->firstChild;
					curr = parent;
				}
			}
		}
}

void addToDestNode(struct dirNode *subRoot, char dest_dir_path[])
{	struct dirNode* desRoot;
	desRoot = returnDesNode(dest_dir_path);	
	subRoot->rightSibling = desRoot->firstChild;
	desRoot->firstChild = subRoot;
}

void changeFD(struct dirNode *subRoot, char dest_dir_path[])
{	char newPath[MAX_FULL_PATH_SIZE];
	if(subRoot != NULL)
	{	strcpy(newPath, dest_dir_path);
		strcat(newPath, "/");
		strcat(newPath, subRoot->fileDesc->fileName);
		strcpy(subRoot->fileDesc->fullPath, newPath);
		//printf("name: %s\tpath: %s\n",subRoot->fileDesc->fileName, subRoot->fileDesc->fullPath);
		changeFD(subRoot->rightSibling, dest_dir_path);	//Pre-order traversal
		changeFD(subRoot->firstChild, newPath);
	}
}

char* move_dir (char source_dir_path[],char dest_dir_path[])
{	char currName[]="";
	char result[]={};
	struct dirNode *subRoot;
	
	/*if (!searchBST(rootBST, source_dir_path))
		return ERR_VFS_MOVEDIR_01;
	else if(!searchBST(rootBST , dest_dir_path))
		return ERR_VFS_MOVEDIR_02;
	else if(!checkSrcExistsInDest(source_dir_path, dest_dir_path))
		return ERR_VFS_MOVEDIR_05;
	else
	{*/
	subRoot = rmvFrmSrcNode(source_dir_path);
	if(subRoot != NULL)
	{	addToDestNode(subRoot, dest_dir_path);
		changeFD(subRoot, dest_dir_path);
		return "success";
	}
}

