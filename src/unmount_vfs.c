#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list.h"
#include "vfs.h"
#include "commands.h"
#define TEMP_SIZE 10
void unmount_vfs(char label[])
{
	//printf("%s unmounted\n",label);
	char temp[TEMP_SIZE];	
	FileDescriptor filedescArray[MAX_NO_OF_FILE_DESCRIPTORS];
	//strcpy(temp,label);
	//strcat(temp,".dat");	//add path
	int i,count=0;
	//MetaHeader metaHeader;
	//FILE *fp;
	/*if((fp=fopen(temp,"rb+"))==NULL)		//Open binary file in write mode
	{	
		printf("Cannot create file");
		flag=CANNOT_CREATE_FILE;
	}*/
	//else
	//{


		if(flag!=200)
		{
			printf(ERR_VFS_UNMOUNT_02);
			flag=302;
		}
		else if(strcmp(mhd.fileSystemLabel,label)!=0)
			{
				printf(ERR_VFS_UNMOUNT_01);
				flag=301;
			}		
		else
		{
		flag=300;	
		saveToArray(naryRoot,filedescArray,&count);
		//strcpy(mhd.fileSystemLabel,label);
		mhd.noOfFileDescriptors=count;
		for(i=0;i<count;i++){
				mhd.filedescArray[i]=filedescArray[i];
		}		
		if(fwrite(&mhd,sizeof(MetaHeader),1,vfs_file)==0)
		{
			printf(ERR_VFS_UNMOUNT_03);
			flag=303;
		}
	}
	//fclose(vfs_file);
}
	
