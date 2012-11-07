#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"

void updateFile ( char filePath[], char data[] )
{
	struct BSTnode *Node;
	FileDescriptor *fd;
	FILE *fp;
	int i,blockNo;
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	int size;
	
	Node=(struct BSTnode *)malloc(sizeof(struct BSTnode));
	fd=(FileDescriptor *)malloc(sizeof(FileDescriptor));
	size=strlen(data);
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	Node=searchBST(rootBST,filePath);
	
	if(Node!=NULL)
	{
		blockNo = Node->filedesc->locationBlockNo;
		printf("\n the block no is:%d",blockNo);
	}
	else
	{
		//error reporting
	}
	if((fp=fopen(label,"rb+"))==NULL)
	{
		printf("Error cud not open  file");
	}
	else
	{	
		fseek(fp,sizeof(MetaHeader),SEEK_CUR);
		fseek(fp,blockNo*sizeof(Block),SEEK_CUR);
		fwrite(data,size*sizeof(char),1,fp);
		Node->filedesc->fileSize=size;
		
	}
	fclose(fp);

}
