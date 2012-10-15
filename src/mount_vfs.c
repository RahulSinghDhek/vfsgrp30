#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "commands.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"

void mount_vfs(char label[])
{
	FILE *fp;
	MetaHeader metaHeader;
	int index=0;
	BSTnode *rootBST;
	int no_of_files,i;
	char lb[MAX_FILE_SYSTEM_LABLE_SIZE];	
	printf("%s mounted\n",label);
	strcpy(lb,label);
	strcat(lb,".dat");
	if((fp=fopen(lb,"rb"))==NULL)		//Open binary file in read mode
	{	
		printf("Cannot mount");
		*flag=CANNOT_CREATE_FILE;
	}
	else
	{
		naryRoot=NULL;
		rootBST=NULL;
		fread(&metaHeader,sizeof(MetaHeader),1,fp);
		no_of_files=metaHeader.noOfFileDescriptors;
		for(i=0;i<no_of_files;i++)
		{
			FileDescriptor *fd;
			fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
			strcpy(fd->fileName,metaHeader.filedescArray[i].fileName);
			strcpy(fd->fullPath,metaHeader.filedescArray[i].fullPath);
			strcpy(fd->fileType,metaHeader.filedescArray[i].fileType);	//Access fileDescriptors
			fd->fileSize=metaHeader.filedescArray[i].fileSize;
			fd->locationBlockNo=metaHeader.filedescArray[i].locationBlockNo;
			
			naryRoot=insertNAry(fd,naryRoot,flag);		//insert into n-Ary Tree

			//rootBST=insertBST(rootBST,fd,&flag);		//insert into BST

			//index = fun_Hash(fd->filename);
			//array[index] = insertnode(array[index], &fd);

			
		}
	}
	displayNAry(naryRoot);	
	
}