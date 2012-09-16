#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
#define error 1
#define ok 0

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
	int flag=ok;
	fstore=fopen("nary_store.dat","wb");
	fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
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
			root=insertNAry(fd,root);
			
		}
	}
	fclose(fp);
	//displayNAry(root);
	saveToFile(root,fstore);
	fclose(fstore);	
	root=NULL;
	rootBST=NULL;
	if((fp2=fopen("nary_store.dat","rb"))==NULL)
		printf("Cannot open file");
	else
	{
		while(fread(fd,sizeof(FileDescriptor),1,fp2))
		{			
			rootBST=insertBST(rootBST,fd,&flag);
			if(flag)
				printf("\n DUPLCATE FILEPATHS NOT ALLOWED");
			
		}
	}
	
	tempBST= rootBST;
	displayBST(tempBST);
	
	printf("\n enter the path to b serched");
	scanf("%s", pathToBeSearched);
	fd1 = searchBST(rootBST,pathToBeSearched);
	if(fd1!=NULL)
	printf("\nFILE_NAME:%s\n FULL_PATH:%s\n FILE_TYPE:%s\n FILE_SIZE:%ld bytes\n BLOCK_NO:%d",fd1->fileName,fd1->fullPath,fd1->fileType,fd1->fileSize,fd1->locationBlockNo );
	fclose(fp);
	
	return 0;
}



