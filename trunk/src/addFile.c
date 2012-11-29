#include<stdio.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"
#include "hashTable.h"

int addFile(char directoryPath[], char fileName[], char sourceFilePath[])
{
	FILE *fp,*fp1;
	FileDescriptor *fd;
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));	
	int index=0,check=0;
	char sourcePath[MAX_FULL_PATH_SIZE],path2[MAX_FULL_PATH_SIZE];;
	char c;
	char str[MAX_BLOCK_SIZE];
	int i,j;
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	long sizeOfSource; 
	strcpy(path2,directoryPath);	
	strcat(path2,"/");

	//MetaHeader *md;
	//FILE *fpp;
	
	if(naryRoot == NULL)
		printf(ERR_VFS_ADDFILE_07);				//VFS_NOT_MOUNTED
	else if(strstr(fileName,"/"))
		printf(ERR_VFS_ADDFILE_02);				//INVALID_CHARACTER_IN_FILENAME
	else if(searchBST(rootBST , strcat(path2,fileName) ))
		printf(ERR_VFS_ADDFILE_03);				//FILE_ALREADY_EXISTS
	else if(mhd.noOfFileDescriptors == MAX_NO_OF_FILE_DESCRIPTORS || vfs_size <= blocks_written)
			printf(ERR_VFS_ADDFILE_04);			//FILE_SYSTEM_FULL		
	else 
	{	
		strcpy(sourcePath,sourceFilePath);
		strcpy(label,mhd.fileSystemLabel);
		strcat(label,".dat");
		//printf("label:%s",label);
		fp = fopen(sourcePath, "r");
		if(fp==NULL)
		{
				printf(ERR_VFS_ADDFILE_05);		//CANNOT_WRITE_TO_DATAFILE
				return check;
		}
		fseek(fp, 0, SEEK_END);
		sizeOfSource = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		if(sizeOfSource>1024)
		{
			//fclose(fp);
			printf(ERR_VFS_ADDFILE_06);			//FILE_TOO_LARGE
				return check;	
		}
		str[0]=fgetc(fp);
		i=0;
		while(str[i]!=EOF)
		{
			str[++i]=fgetc(fp);
		
		
		}
		str[i]='\0';
		fclose(fp);
		//printf("str:%s",str);
		if((fp1=fopen(label,"rb+"))==NULL)
		{
			printf("Error in opening abc.dat file\n");
		}
		else
		{
			fseek(fp1,sizeof(MetaHeader),SEEK_SET);
			for(j=0;mhd.FreeList[j]!=0;j++);
			fseek(fp1,j*sizeof(Block),SEEK_CUR);
			if(!(fwrite(str,i*sizeof(char),1,fp1)))
			{
				//fclose(fp1);
				printf(ERR_VFS_ADDFILE_05);		//CANNOT_WRITE_TO_DATAFILE	
 				return check;
			}				
			mhd.FreeList[j]=1;
		}
		strcat(directoryPath,"/");
		strcat(directoryPath,fileName);
	//	printf("dirPath:%s",directoryPath);
		strcpy(fd->fileName,fileName);
		strcpy(fd->fullPath,directoryPath);
		strcpy(fd->fileType,"file");
		fd->fileSize=i;
		fd->locationBlockNo=j;
		//printf("\n locationBlock no is %d \n ",j);
		blocks_written=j+1;
		naryRoot=insertNAry(fd,naryRoot,&flag);
		rootBST=insertBST(rootBST,fd,&flag);
		index = fun_Hash(fd->fileName[0]);
		array[index] = insertnode(array[index], fd);
		check=1;
		fclose(fp1);
		//-----------------------------------reading----------------------------------
		/*if((fp=fopen(label,"rb+"))==NULL)		//Open binary file in read mode
		{	
			printf("Cannot mount");
			flag=CANNOT_CREATE_FILE;
		}
		else
		{
		
			fseek(fp1,sizeof(MetaHeader),SEEK_SET);
			for(j=0;mhd.FreeList[j]!=1;j++);
			fseek(fp1,j*sizeof(Block),SEEK_SET);
			fread(str,i*sizeof(char),1,fp1);
			printf("string read:%s",str);
			//mhd.FreeList[j]=1;
		}
		fclose(fp);*/
	}
	return check;
}

