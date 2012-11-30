#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"
#include "hashTable.h"

int mount_vfs(char label[])
{
	int check = 0;
	FILE *fp;
	//MetaHeader metaHeader;
	int index=0;
	//BSTnode *rootBST;
	int no_of_files,i;
	char lb[MAX_FILE_SYSTEM_LABLE_SIZE];	
	//flag=(int*)malloc(sizeof(int)); 
	flag=ERROR_FREE;
	//printf("Flag %d",flag);	
	if(strlen(label) > MAX_FILE_SYSTEM_LABLE_SIZE)
		printf(ERR_VFS_MOUNT_01);		//DATA_FILE_NOT_FOUND
	else
	{
		strcpy(lb,label);
		strcat(lb,".dat");
	
		if(naryRoot != NULL)
			printf(ERR_VFS_MOUNT_03);		//VFS_ALREADY_MOUNTED
		else if(( fp = fopen(lb,"rb"))==NULL)
			printf(ERR_VFS_MOUNT_01);		//DATA_FILE_NOT_FOUND
		else
		{	naryRoot=NULL;
			rootBST=NULL;
			for(i=0;i<HASH_TAB;i++)
			{
				array[i]=NULL;
			}	
		
			if( fread(&mhd,sizeof(MetaHeader),1,fp) )
			{
				no_of_files=mhd.noOfFileDescriptors;
		
				for(i=0;i<no_of_files;i++)
				{
					FileDescriptor *fd;
					fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
					strcpy(fd->fileName,mhd.filedescArray[i].fileName);
					strcpy(fd->fullPath,mhd.filedescArray[i].fullPath);
					//printf("in mount path:%s",fd->fullPath);
					strcpy(fd->fileType,mhd.filedescArray[i].fileType);	//Access fileDescriptors
					fd->fileSize=mhd.filedescArray[i].fileSize;
					fd->locationBlockNo=mhd.filedescArray[i].locationBlockNo;

					naryRoot=insertNAry(fd,naryRoot,&flag);		//insert into n-Ary Tree

					rootBST=insertBST(rootBST,fd,&flag);		//insert into BST

					index = fun_Hash(fd->fileName[0]);
					array[index] = insertnode(array[index], fd);
			
				}
			check = 1;
			}
			else
				printf(ERR_VFS_MOUNT_02);			//CANNOT_READ_FROM_FILE
	
			fclose(fp);
		}
	}
	/*printf("\n naryTree display  :  ");	
	displayNAry(naryRoot);
	printf("\n BSTree display  :  ");
	displayBST(rootBST);
	printf("\n HTable display  :  ");
	display_Hash();
	printf("%s mounted\n",label);
	*/
//printf("Flag %d",flag);
//free(fd);
return check;
}
