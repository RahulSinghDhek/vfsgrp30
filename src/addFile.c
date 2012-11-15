#include<stdio.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"
#include "hashTable.h"

void addFile(char directoryPath[], char fileName[], char sourceFilePath[])
{
	FILE *fp,*fp1;
	FileDescriptor *fd;
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));	
	int index=0;
	char sourcePath[MAX_FULL_PATH_SIZE];
	char c;
	char str[MAX_BLOCK_SIZE];
	int i,j;
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	//MetaHeader *md;
	strcpy(sourcePath,sourceFilePath);
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	printf("label:%s",label);
	fp = fopen(sourcePath, "r");
	if(fp==NULL)
	{
			printf("ERROR");
	}
	str[0]=fgetc(fp);
	i=0;
	while(str[i]!=EOF)
	{
		str[++i]=fgetc(fp);
		
		
	}
	str[i]='\0';
	fclose(fp);
	printf("str:%s",str);
	if((fp1=fopen(label,"rb+"))==NULL)
	{
		printf("Error in opening abc.dat file\n");
	}
	else
	{
		fseek(fp1,sizeof(MetaHeader),SEEK_SET);
		for(j=0;mhd.FreeList[j]!=0;j++);
		fseek(fp1,j*sizeof(Block),SEEK_CUR);
		fwrite(str,i*sizeof(char),1,fp1);
		mhd.FreeList[j]=1;
	}
	strcat(directoryPath,"/");
	strcat(directoryPath,fileName);
	printf("dirPath:%s",directoryPath);
	strcpy(fd->fileName,fileName);
	strcpy(fd->fullPath,directoryPath);
	strcpy(fd->fileType,"file");
	fd->fileSize=i;
	fd->locationBlockNo=j;
	printf("\n locationBlock no is %d \n ",j);
	rootBST=insertBST(rootBST,fd,&flag);
		printf("\n i m in1\n");
	
	naryRoot=insertNAry(fd,naryRoot,&flag);
			printf("\n i m in2\n");
	index = fun_Hash(fd->fileName[0]);
			printf("\n i m in3\n");
	array[index] = insertnode(array[index], fd);
				printf("\n i m in4\n");
	//fclose(fp1);
	printf("\n i m in\n");

	//-----------------------------------reading----------------------------------
	if((fp=fopen(label,"rb+"))==NULL)		//Open binary file in read mode
	{	
			
		printf("Cannot mount");
		flag=CANNOT_CREATE_FILE;
	}
	else
	{
		
		fseek(fp,sizeof(MetaHeader),SEEK_SET);
		for(j=0;mhd.FreeList[j]!=1;j++);
		fseek(fp,j*sizeof(Block),SEEK_CUR);
		fread(str,i*sizeof(char),1,fp);
		printf("string read:%s",str);
		//mhd.FreeList[j]=1;
	}
	//fclose(fp);
}

