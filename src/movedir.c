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
/*int chkNonRecursive(struct dirNode* root, char currDirName[])
{
	if(root!=NULL)
	{
		//fprintf(fp,"%s\n",root->fileDesc->fileName);
		if(strcmp(root->fileDesc->fileName,currDirName)==0)
			return FALSE;
		chkNonRecursive(root->rightSibling, currDirName);
	}
return TRUE;
}*/

int checkSrcExistsInDest(char src_path[], char path[])
{	//struct dirNode *temp;
	char *currDirName;
	int check =0;
	BSTnode *result;
	
	//strcat(src_path,"/z");
	currDirName = parse_Path(src_path);
	//temp=searchNary(naryRoot, path);		//Globle
	//temp= temp->firstChild;
	//return chkNonRecursive(temp, currDirName);
	if(strcmp(path,"/")!=0)
		strcat(path,"/");
	strcat(path,currDirName);
	result = searchBST(rootBST, path);

	if(result != NULL)
		check =1;
return check;
}

int del_dir_new(char path[])
{	int check=0, dec=2;
	BSTnode *source_path;
	struct dirNode *subRoot;
	
	source_path = searchBST(rootBST, path);

	if(naryRoot == NULL)
		printf(ERR_VFS_DELETEDIR_04);				//VFS_NOT_MOUNTED
	else if (source_path == NULL)
		printf(ERR_VFS_DELETEDIR_01);				//CANNOT_FIND_SPECIFIED_DIR
	else if(source_path != NULL && strcmp(source_path->filedesc->fileType,"dir"))
		printf(ERR_VFS_DELETEDIR_01);				//CANNOT_FIND_SPECIFIED_DIR
	else
	{	subRoot = rmvFrmSrcNode(path, dec);
		if(subRoot == NULL)
			check = 1;
		/*if(subRoot->firstChild->firstChild != NULL)
			printf(ERR_VFS_DELETEDIR_02);				//DIRECTORY_IS_NOT_EMPTY	
		else
		{	temp = subRoot->firstChild;
			subRoot->firstChild = subRoot->firstChild->rightSibling;
		}*/
	}
return check;
}

int rmv_file(char path[])
{	int check=0, dec=1;
	BSTnode *source_path;
	struct dirNode *subRoot;
	
	source_path = searchBST(rootBST, path);

	if(naryRoot == NULL)
		printf(ERR_VFS_REMOVEFILE_02);				//VFS_NOT_MOUNTED
	else if (source_path == NULL)
		printf(ERR_VFS_REMOVEFILE_01);				//CANNOT_FIND_SPECIFIED_FILE
	else if(source_path != NULL && strcmp(source_path->filedesc->fileType,"file"))
		printf(ERR_VFS_REMOVEFILE_01);				//CANNOT_FIND_SPECIFIED_FILE
	else
	{	subRoot = rmvFrmSrcNode(path, dec);
		if(subRoot != NULL)
		{	mhd.noOfFileDescriptors--;
			mhd.FreeList[subRoot->fileDesc->locationBlockNo]=0;
			check = 1;
		}
	}
return check;
}

struct dirNode * rmvFrmSrcNode(char source_dir_path[], int decision)
{	struct dirNode *curr=NULL, *prev=NULL;
	curr = naryRoot;
	int exitStatus, index=0;
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
		if(decision == 1)
		{	if(prev->firstChild == curr)
				prev->firstChild = curr->rightSibling;
			else if(prev->rightSibling == curr)
				prev->rightSibling = curr->rightSibling;
		}
		else if(decision == 2)
		{	if(curr->firstChild != NULL)
				printf(ERR_VFS_DELETEDIR_02);				//DIRECTORY_IS_NOT_EMPTY
			else
			{	if(prev->firstChild == curr)
					prev->firstChild = curr->rightSibling;
				else if(prev->rightSibling == curr)
					prev->rightSibling = curr->rightSibling;

				rootBST=NULL;
				constructBST(naryRoot);
			
				index =  fun_Hash(curr->fileDesc->fileName[0]);
				array[index] = deletenode(array[index], curr->fileDesc);
				curr = NULL;

				mhd.noOfFileDescriptors--;
			}
		}
		
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
		if(strcmp(dest_dir_path,"/")!=0)
			strcat(newPath, "/");
		strcat(newPath, subRoot->fileDesc->fileName);
		strcpy(subRoot->fileDesc->fullPath, newPath);
		//printf("name: %s\tpath: %s\n",subRoot->fileDesc->fileName, subRoot->fileDesc->fullPath);
		changeFD(subRoot->rightSibling, dest_dir_path);	//Pre-order traversal
		changeFD(subRoot->firstChild, newPath);
	}
}
void constructBST(struct dirNode *root)
{	
	if(root!=NULL)
	{
		rootBST=insertBST(rootBST, root->fileDesc, &flag);
		constructBST(root->rightSibling);	//Pre-order traversal
		constructBST(root->firstChild);
	}
			
}

int move_dir (char source_dir_path[],char dest_dir_path[])
{	flag=ERROR_FREE;
	char currName[]={};
	char result[]={};
	int check = 0, dec=1;
	struct dirNode *subRoot;
	BSTnode *source_path, *dest_path;
	char tmp[MAX_FULL_PATH_SIZE]="";
	
	if(naryRoot == NULL)
	{	printf(ERR_VFS_MOVEDIR_08);				//VFS_NOT_MOUNTED
		return check;
	}

	strcpy(tmp,dest_dir_path);
	source_path = searchBST(rootBST, source_dir_path);
	dest_path = searchBST(rootBST , dest_dir_path);
	//printf("Src:%s\tDes:%s\n",source_dir_path, dest_dir_path);
	//printf("SP:%p\t DP:%p",source_path, dest_path);

	
	
	if (source_path == NULL)
		printf(ERR_VFS_MOVEDIR_01);				//CANNOT_FIND_SPECIFIED_SOURCEDIR
	else if(source_path != NULL && strcmp(source_path->filedesc->fileType,"dir"))
			printf(ERR_VFS_MOVEDIR_04);			//SOURCE_CANNOT_BE_FILE
	else if (dest_path == NULL)
		printf(ERR_VFS_MOVEDIR_02);				//CANNOT_FIND_SPECIFIED_DESTINATIONDIR
	else if(dest_path != NULL && strcmp(dest_path->filedesc->fileType,"dir"))
			printf(ERR_VFS_MOVEDIR_07);			//DESTINATION_CANNOT_BE_FILE
	else
	{	if(strstr(dest_dir_path, source_dir_path)!=NULL)
			printf(ERR_VFS_MOVEDIR_06); 				//CANNOT_MOVE_PARENT_TO_CHILD_DIR
		else if(checkSrcExistsInDest(source_dir_path, tmp))
			printf(ERR_VFS_MOVEDIR_05);				//DESTINATION_ALREADY_HAVE_SOURCE_DIR
		else
		{
			subRoot = rmvFrmSrcNode(source_dir_path,dec);
			addToDestNode(subRoot, dest_dir_path);
			changeFD(subRoot, dest_dir_path);
			rootBST=NULL;
			constructBST(naryRoot);
			check = 1;
		}

	}
return check;
}

