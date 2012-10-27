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
	strcpy(temp,label);
	strcat(temp,".dat");	//add path
	int i,count=0;
	//MetaHeader metaHeader;
	FILE *fp;
	if((fp=fopen(temp,"rb+"))==NULL)		//Open binary file in write mode
	{	
		printf("Cannot create file");
		flag=CANNOT_CREATE_FILE;
	}
	else
	{
		saveToArray(naryRoot,filedescArray,&count);
		//strcpy(mhd.fileSystemLabel,label);
		mhd.noOfFileDescriptors=count;
		for(i=0;i<count;i++){
				mhd.filedescArray[i]=filedescArray[i];
		}		
		fwrite(&mhd,sizeof(MetaHeader),1,fp);
		
	}
}
	
