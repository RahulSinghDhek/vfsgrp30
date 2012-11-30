#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list.h"
#include "vfs.h"
#include "commands.h"

int unmount_vfs(char label[])
{	char temp[MAX_FILE_SYSTEM_LABLE_SIZE];	
	FileDescriptor filedescArray[MAX_NO_OF_FILE_DESCRIPTORS];
	int i,count=0, check =0;

	FILE *fp;

	if(strlen(label) > MAX_FILE_SYSTEM_LABLE_SIZE)
		printf(ERR_VFS_UNMOUNT_01);		//DATA_FILE_NOT_FOUND
	else
	{
		strcpy(temp,label);
		strcat(temp,".dat");	//add path
	

		if(naryRoot == NULL || strcmp(mhd.fileSystemLabel,label) )
			printf(ERR_VFS_UNMOUNT_03);		//VFS_NOT_MOUNTED
		else if((fp=fopen(temp,"rb+"))==NULL)
			printf(ERR_VFS_UNMOUNT_01);		//DATA_FILE_NOT_FOUND
		else
		{	saveToArray(naryRoot,filedescArray,&count);

			mhd.noOfFileDescriptors=count;

			for(i=0;i<count;i++){
				mhd.filedescArray[i]=filedescArray[i];
				//printf("\nin unmount:%s\n",filedescArray[i].fullPath);
			}
				
			if(fwrite(&mhd,sizeof(MetaHeader),1,fp)==0)
				printf(ERR_VFS_UNMOUNT_02);		//CANNOT_WRITE_TO_FILE
			else
			{
				//printf("\n naryTree display after unmount : \n");	
				//displayNAry(naryRoot);
				//printf("\n BSTree display  : \n ");
				//displayBST(rootBST);
				check = 1;
				naryRoot=NULL;
				rootBST=NULL;
				flag=ERROR_FREE;
			}
		}
	}

return check;
}
	
