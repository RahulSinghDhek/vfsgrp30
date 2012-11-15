#include<stdio.h>
#include<stdlib.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "binarySearchTree.h"


void listFile ( char filePath[], char outputFile[]  )
{
	printf("\nI m Here inside here.....from raju\n");
	struct BSTnode *Node;
	FileDescriptor *fd;
	FILE *fp,*fp1;
	int i,blockNo,j;
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	int size;
	char str[MAX_BLOCK_SIZE];
	Node=(struct BSTnode *)malloc(sizeof(struct BSTnode));
	fd=(FileDescriptor *)malloc(sizeof(FileDescriptor));
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	Node=searchBST(rootBST,filePath);
	if(Node!=NULL)
	{
		blockNo=Node->filedesc->locationBlockNo;
		size=Node->filedesc->fileSize;
		printf("\n the block no is:%d",blockNo);
		printf("\n the size is:%d",size);
	}
	else
	{
		//error reporting
	}
	if((fp=fopen(label,"rb+"))==NULL)
	{
		//through error
	}
	else
	{
		printf("\nI m Here inside here.....\n");
		fseek(fp,sizeof(MetaHeader),SEEK_SET);
		fseek(fp,blockNo*sizeof(Block),SEEK_CUR);
		//fread(str,size*sizeof(char),1,fp);
			int i=0;
		printf("size from list file %d\n",size);
			while(i<=size)
						{
						str[i++]=fgetc(fp);
						printf("%c",str[i-1]);	
						}
						//str[i]='\0';						

							
		str[i-1]='\0';




		
		
	}
	fclose(fp);
	if((fp1=fopen(outputFile,"w+"))==NULL)
	{
		//error reprting
	}
	else
	{
	
		printf("\nThe data written to o/p file is:  %s\n",str);
		fprintf(fp1,"%s",str);
	}
	fclose(fp1);

}
