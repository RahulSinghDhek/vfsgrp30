#include<stdio.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "binarySearchTree.h"


void listFile ( char filePath[], char outputFile[]  )
{
	
	struct BSTnode *Node;
	FileDescriptor *fd;
	FILE *fp;
	int i,blockNo;
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	int size;
	char str[MAX_BLOCK_SIZE];
	Node=(struct BSTnode *)malloc(sizeof(struct BSTnode));
	fd=(FileDescriptor *)malloc(sizeof(FileDescriptor));
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	Node=searchBST(rootBST,filePath);
	if(Node!=NULL)
	{
		blockNo=Node->filedesc->locationBlockNo;
		size=Node->filedesc->fileSize;
		printf("\n the block no is:%d",blockNo);
	}
	else
	{
		//error reporting
	}
	if((fp=fopen(label,"rb+"))==NULL)
	{
		//through error
	}
	else
	{
		fseek(fp,sizeof(MetaHeader),SEEK_CUR);
		fseek(fp,blockNo*sizeof(Block),SEEK_CUR);
		fread(str,size*sizeof(char),1,fp);
	}
	fclose(fp);
	if((fp=fopen(outputFile,"w+"))==NULL)
	{
		//error reprting
	}
	else
	{
		printf("\nThe data written to o/p file is:  %s\n",str);
		fprintf(fp,"%s",str);
	}
	fclose(fp);

}
