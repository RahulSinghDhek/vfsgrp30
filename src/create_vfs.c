//changed on 28th November,2012
#include "list.h"
#include "vfs.h"
#include "commands.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int create_vfs(char label[],long systemSize)
{
	int check = 0;
	char lb[MAX_FILE_SYSTEM_LABLE_SIZE];	//re-name
	if(strlen(label) > MAX_FILE_SYSTEM_LABLE_SIZE)
		printf(ERR_VFS_CREATE_05);			//VFS_LABEL_TOO_LARGE
	else
	{
		strcpy(lb,label);
		strcat(lb,".dat");	//add path
		int i;
		FILE *fp;
		MetaHeader metaHeader;
		vfs_size=systemSize;
	
		if((fp=fopen(lb,"rb"))!=NULL)
		{       printf(ERR_VFS_CREATE_01);			//DATA_FILE_ALREADY_EXISTS
		        //fclose(fp);    
		}
		else if(systemSize>MAX_VFS_MEMORY || systemSize<MIN_VFS_MEMORY)
		    	printf(ERR_VFS_CREATE_04);              	//INVALID_SIZE
		else if(strstr(label,"/")!=NULL)
			printf(ERR_VFS_CREATE_03);			//INVALID_CHARACTER_IN_NAME
		else if((fp=fopen(lb,"wb"))==NULL)
			printf(ERR_VFS_CREATE_02);  			//CANNOT_CREATE_DATAFILE		
		else
		{
			FileDescriptor *fdroot;
			fdroot=(FileDescriptor*)malloc(sizeof(FileDescriptor));
			strcpy(fdroot->fileName,"root");
			strcpy(fdroot->fullPath,"/");
			strcpy(fdroot->fileType,"dir");
			fdroot->fileSize=0;
			fdroot->locationBlockNo=-1;
			metaHeader.filedescArray[0]=*fdroot;
			strcpy(metaHeader.fileSystemLabel,label);
			metaHeader.noOfFileDescriptors=1;
			for(i=0;i<MAX_NO_OF_FILE_DESCRIPTORS;i++)
				metaHeader.FreeList[i]=0;
		
			fwrite(&metaHeader,sizeof(MetaHeader),1,fp);
			for(i=0;i<(systemSize);i++)
			{	Block block;
				fwrite(&block,sizeof(Block),1,fp);
			}
			fclose(fp);
			check = 1;
		}
	}
	return check;
}
