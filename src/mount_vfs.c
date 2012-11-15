#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"
#include "hashTable.h"

void mount_vfs(char label[])
{
	
	//FILE *fp;
	//MetaHeader metaHeader;
	int index=0;
	//BSTnode *rootBST;
	int no_of_files,i;
	char lb[MAX_FILE_SYSTEM_LABLE_SIZE];	
	//flag=(int*)malloc(sizeof(int)); 
	//flag=ERROR_FREE;
	
	strcpy(lb,label);
	strcat(lb,".dat");
	
	if(flag==100||flag==0)
	{
	flag=200;	
	if((vfs_file=fopen(lb,"rb"))==NULL)
	{	
		flag=201;
		printf(ERR_VFS_MOUNT_01);
		//fclose(vfs_file);
		return;	
	}
	else
			fclose(vfs_file);
	
	 if((vfs_file=fopen(lb,"rb+"))==NULL)		//Open binary file in read mode
	{	
		printf(ERR_VFS_MOUNT_02);
		flag=202;
	}
	else
	{
		naryRoot=NULL;
		rootBST=NULL;
		for(i=0;i<HASH_TAB;i++)
		{
			array[i]=NULL;
		}	
		fread(&mhd,sizeof(MetaHeader),1,vfs_file);
		no_of_files=mhd.noOfFileDescriptors;
		
		for(i=0;i<no_of_files;i++)
		{
			FileDescriptor *fd;
			fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
			strcpy(fd->fileName,mhd.filedescArray[i].fileName);
			strcpy(fd->fullPath,mhd.filedescArray[i].fullPath);
			strcpy(fd->fileType,mhd.filedescArray[i].fileType);	//Access fileDescriptors
			fd->fileSize=mhd.filedescArray[i].fileSize;
			fd->locationBlockNo=mhd.filedescArray[i].locationBlockNo;
			
			naryRoot=insertNAry(fd,naryRoot,&flag);		//insert into n-Ary Tree

			rootBST=insertBST(rootBST,fd,&flag);		//insert into BST

			index = fun_Hash(fd->fileName[0]);
			array[index] = insertnode(array[index], fd);
			flag=200;			
		}
	}
	printf("\n naryTree display  :  ");	
	displayNAry(naryRoot);
	printf("\n BSTree display  :  ");
	displayBST(rootBST);
	printf("\n HTable display  :  ");
	display_Hash();
	//printf("%s mounted\n",label);

	}
}
