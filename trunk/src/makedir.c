#include<stdio.h>
#include<string.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"
#include "hashTable.h"

void make_dir(char path[],char dir[])
{
	FileDescriptor *fd;
	int index=0;
	printf("%s",path);
	printf("%s",dir);
	if(strcmp(path,"/")!=0)
		strcat(path,"/");
	printf("\n%s",path);
	printf("%s",dir);
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
	strcpy(fd->fileName,dir);
	strcpy(fd->fullPath,strcat(path,dir));
	printf("\n%s",fd->fullPath);
	//printf("%s",dir);
	strcpy(fd->fileType,"dir");
	fd->fileSize=0;
	fd->locationBlockNo=-1;

	naryRoot=insertNAry(fd,naryRoot,&flag);

	rootBST=insertBST(rootBST,fd,&flag);		//insert into BST
	
	index = fun_Hash(fd->fileName[0]);
	array[index] = insertnode(array[index], fd);

	printf("\n naryTree display  :  ");	
	displayNAry(naryRoot);
	printf("\n BSTree display  :  ");
	displayBST(rootBST);
	printf("\n HTable display  :  ");
	display_Hash();
}

