#include "list.h"
#include "vfs.h"
#include "commands.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void create_vfs(char label[],long systemSize)
{
	
	char lb[MAX_FILE_SYSTEM_LABLE_SIZE];	//re-name
	strcpy(lb,label);
	strcat(lb,".dat");	//add path
	int i;
	FILE *fp;
	MetaHeader metaHeader;
	flag=100;		//NO_ERRORS;
	
	vfs_size=systemSize;

	if(systemSize>MAX_VFS_MEMORY)
	{
		flag=103;
		printf(ERR_VFS_CREATE_03);		
	}
	else if(systemSize % MAX_BLOCK_SIZE != 0)
	{
		flag=105;
		printf(ERR_VFS_CREATE_05);		
	}
	else if((fp=fopen(lb,"rb"))!=NULL)
	{	
		flag=101;
		printf(ERR_VFS_CREATE_01);
		fclose(fp);	
	}
	else{
		//fclose(fp);	
		if((fp=fopen(lb,"wb"))==NULL)
		{	
			printf("Cannot create file");
			//*flag=CANNOT_CREATE_FILE;
			flag=102;
			printf(ERR_VFS_CREATE_02);	
		}
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
			{
				metaHeader.FreeList[i]=0;
			}
		
			fwrite(&metaHeader,sizeof(MetaHeader),1,fp);
			for(i=0;i<(systemSize/sizeof(Block));i++)
			{
				Block block;
				fwrite(&block,sizeof(Block),1,fp);
			}
		}
	}
}
/*int main()
{
	create_vfs("zzz",1024);
}*/
