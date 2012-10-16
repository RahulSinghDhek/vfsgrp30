#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list.h"
#include "vfs.h"
#include "commands.h"
#define TEMP_SIZE 10
void unmount_vfs(char label[])
{
	printf("%s unmounted\n",label);
	char temp[TEMP_SIZE];	
	strcpy(temp,label);
	strcat(temp,".dat");	//add path
	int i;
	FILE *fp;
	

	/*if((fp=fopen("inputfiledesc.txt","r"))==NULL)		//Open dummy i/p file
		printf("Cannot open file");
	
	else
	{
		i=0;
		FileDescriptor *fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
		while(fscanf(fp,"%s",fd->fileName)!=EOF && *flag==100)
		{
			fscanf(fp,"%s",fd->fullPath);
			fscanf(fp,"%s",fd->fileType);
			fscanf(fp,"%ld",&fd->fileSize);
			fscanf(fp,"%d",&fd->locationBlockNo);
			strcpy(metaHeader.filedescArray[i].fileName,fd->fileName);
			strcpy(metaHeader.filedescArray[i].fullPath,fd->fullPath);
			strcpy(metaHeader.filedescArray[i].fileType,fd->fileType);
			metaHeader.filedescArray[i].fileSize=fd->fileSize;
			metaHeader.filedescArray[i].locationBlockNo=fd->locationBlockNo;
			printf("%d\n",*(flag));
			i++;
			fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
		}
	}
	fclose(fp);*/
	
	
	/*metaHeader.noOfFileDescriptors=i;
	if((fp=fopen(temp,"wb"))==NULL)		//Open binary file in write mode
	{	
		printf("Cannot create file");
		*flag=CANNOT_CREATE_FILE;
	}
	else
	{
		fwrite(&metaHeader,sizeof(MetaHeader),1,fp);
		for(i=0;i<(vfs_size/sizeof(Block));i++)
		{
			Block block;
			fwrite(&block,sizeof(Block),1,fp);
		}
		if(i*sizeof(Block)<vfs_size){
			Block block;
			fwrite(&block,sizeof(Block),1,fp);
		}
	}*/
}

