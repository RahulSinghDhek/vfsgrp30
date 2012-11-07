#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include"binarySearchTree.h"

void removeFile (char filePath[])
{
	printf("in removefile");
	struct BSTnode *Node;
	struct dirNode *NodeN;
	FileDescriptor *fd;
	FILE *fp;
	int i,blockNo;
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	int size;
	Node=(struct BSTnode *)malloc(sizeof(struct BSTnode));
	NodeN=(struct dirNode *)malloc(sizeof(struct dirNode));
	fd=(FileDescriptor *)malloc(sizeof(FileDescriptor));
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	Node=searchBST(Node, filePath);
	printf("in removefile");
	if(Node!=NULL)
	{
		if(strcmp(Node->filedesc->fileType,"file")==0)
		{
			NodeN=rmvFrmSrcNode(filePath);
			if(Node!=NULL)
			{
				mhd.FreeList[NodeN->fileDesc->locationBlockNo]=0;
		
			}
			else
			{
				//error reprting filepath not found
			}
		}
		else
		{
			//error reporting can't delete directory
		}
	}
	else
	{
		//error reporting filepath not found
	}
	
}
	
	
