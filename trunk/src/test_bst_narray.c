#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
//#define error 1
//#define ok 0

int main()
{
	int i;
	char ch;
	char pathToBeSearched[PATH_SIZE];
	FILE *fp,*fstore,*fp2;
	struct dirNode* root=NULL;
	BSTnode *rootBST=NULL;
	BSTnode *tempBST = NULL;
	FileDescriptor *fd;
	FileDescriptor *fd1;
	FileDescriptor *filedes;
	int flag= 0;
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
	rootBST=NULL;
	if((fp=fopen("inputfiledesc.txt","r"))==NULL)
		printf("Cannot open file");
	else
	{
		while(fscanf(fp,"%s",fd->fileName)!=EOF)
		{
			fscanf(fp,"%s",fd->fullPath);
			fscanf(fp,"%s",fd->fileType);
			fscanf(fp,"%ld",&fd->fileSize);
			fscanf(fp,"%d",&fd->locationBlockNo);
			rootBST=insertBST(rootBST,fd,&flag);
			if(flag)
				printf("\n DUPLCATE FILEPATHS NOT ALLOWED");
			
		}
	}
	fclose(fp);
	flag= 0;
	tempBST= rootBST;
	displayBST(tempBST);
	
	printf("\n enter the path to be Serched:\n");
	scanf("%s", pathToBeSearched);
	searchBST(rootBST,pathToBeSearched, &flag);
	if(flag)
		printf("\n Sorry the Path Could not be Found");
	else
	{
		//printf("\nFILE_NAME:%s\n FULL_PATH:%s\n FILE_TYPE:%s\n FILE_SIZE:%ld bytes\n BLOCK_NO:%d",filedes->fileName,filedes->fullPath,filedes->fileType,filedes->fileSize,filedes->locationBlockNo );
	}
		
	fclose(fp);
	
	return 0;
}



