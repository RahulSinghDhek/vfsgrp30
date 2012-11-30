#include<stdio.h>
#include<string.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"
#include "hashTable.h"

int make_dir(char path[],char dir[])
{
	/*printf("\n BSTree display mkdir begining :  ");
	displayBST(rootBST);*/
	FileDescriptor *fd;
	int index=0, check = 0;
	char path1[MAX_FULL_PATH_SIZE],path2[MAX_FULL_PATH_SIZE];
	strcpy(path1,path);
	strcpy(path2,path);

	if(strcmp(path,"/")!=0)	
		strcat(path2,"/");
	//printf("Flag %d",flag);	
	if(naryRoot == NULL)
		printf(ERR_VFS_MAKEDIR_05);			//VFS_NOT_MOUNTED
	else if(strstr(dir,"/")!=NULL)
		printf(ERR_VFS_MAKEDIR_02);			//INVALID_CHARACTER_IN_DIRNAME
	else if(searchBST(rootBST , strcat(path2,dir) ))
		printf(ERR_VFS_MAKEDIR_03);			//DIRECTORY_ALREADY_EXISTS
	else
	{	
		if(strcmp(path,"/")!=0)
			strcat(path,"/");
		if(mhd.noOfFileDescriptors == MAX_NO_OF_FILE_DESCRIPTORS)
			printf(ERR_VFS_MAKEDIR_01);				//FILESYSTEM_FULL
		else
		{
			fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
			strcpy(fd->fileName,dir);
			strcpy(fd->fullPath,strcat(path,dir));
			strcpy(fd->fileType,"dir");
			fd->fileSize=0;
			fd->locationBlockNo=-1;

			naryRoot=insertNAry(fd,naryRoot,&flag);

			rootBST=insertBST(rootBST,fd,&flag);		//insert into BST
	
			index = fun_Hash(fd->fileName[0]);
			array[index] = insertnode(array[index], fd);
				check = 1;
				//free(fd);
			//printf("-----------------------------------------------------------------------------------");
			//printf("\n naryTree display after make :  ");	
			//displayNAry(naryRoot);
			//printf("-----------------------------------------------------------------------------------");
			/*printf("\n BSTree display after make :  ");
			displayBST(rootBST);
			//printf("\n BSTree display  :  ");
			//displayBST(rootBST);
			/*printf("\n HTable display  :  ");
			display_Hash();*/
		}
	}
return check;
}

