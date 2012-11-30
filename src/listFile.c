#include<stdio.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "binarySearchTree.h"


int listFile ( char filePath[], char outputFile[]  )
{
	
	struct BSTnode *Node;
	FileDescriptor *fd;
	FILE *fp,*fp1;
	int i,blockNo,j,check=0;
	char label[MAX_FILE_SYSTEM_LABLE_SIZE]="";
	int size;
	char str[MAX_BLOCK_SIZE]="";
	char strIp[MAX_BLOCK_SIZE]="";
	char strOp[MAX_BLOCK_SIZE]="";
	char strOppath[4],strIppath[4];
	int sizeOfOpPath,sizeOfIpPath;
	sizeOfOpPath=strlen(outputFile)-4;
	sizeOfIpPath=strlen(filePath)-4;
	for(j=0,i=sizeOfOpPath;i<strlen(outputFile);i++)
		strOppath[j++]=outputFile[i];
	for(j=0,i=sizeOfIpPath;i<strlen(filePath);i++)
		strIppath[j++]=filePath[i];
	//printf("path is %s",strOppath );	
	//printf("path is %s",strIppath );
	Node=(struct BSTnode *)malloc(sizeof(struct BSTnode));
	fd=(FileDescriptor *)malloc(sizeof(FileDescriptor));
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	Node=searchBST(rootBST,filePath);
	if(naryRoot == NULL)
		printf(ERR_VFS_LISTFILE_04);						//VFS_NOT_MOUNTED
	else if(Node==NULL)
		printf(ERR_VFS_LISTFILE_01);						//SOURCE_FILE_PATH_NOT_FOUND		
	else if(strcmp(strIppath,".txt"))
		printf(ERR_VFS_LISTFILE_02);						//NOT_A_TEXT_FILE
	else
	{
		blockNo=Node->filedesc->locationBlockNo;
		size=Node->filedesc->fileSize;
		//printf("\n the block no is:%d",blockNo);
		//printf("\n the size is:%d",size);
		if((fp=fopen(label,"rb+"))==NULL)
			printf(ERR_VFS_LISTFILE_01);						//CANNOT_CREATE_OUTPUTFILE
		else
		{
			fseek(fp,sizeof(MetaHeader),SEEK_SET);
			fseek(fp,blockNo*sizeof(Block),SEEK_CUR);
			fread(str,size,1,fp);	
			//fclose(fp);		
			if((fp1=fopen(outputFile,"w+"))==NULL)
				printf(ERR_VFS_LISTFILE_01);						//CANNOT_CREATE_OUTPUTFILE
			else
			{
				fprintf(fp1,"%s",str);
				//printf("\nThe data written to o/p file is:  %s\n",str);
				//fclose(fp1);
				check=1;
			}
			
		}
	}
	return check;
}
