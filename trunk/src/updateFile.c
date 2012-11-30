#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "commands.h"
#include "list.h"
#include "vfs.h"
#include "nAryTree.h"
#include "binarySearchTree.h"

int updateFile ( char filePath[], char dataFilePath[] )
{
	struct BSTnode *Node;
	FileDescriptor *fd;
	FILE *fp ,*fp1;
	int i,blockNo;
	char label[MAX_FILE_SYSTEM_LABLE_SIZE];
	int size,sizeUpdate, check=0;
	char strupdate[MAX_BLOCK_SIZE];
	//char label1[MAX_FILE_SYSTEM_LABLE_SIZE];
	Node=(struct BSTnode *)malloc(sizeof(struct BSTnode));
	fd=(FileDescriptor *)malloc(sizeof(FileDescriptor));
	size=strlen(dataFilePath);
	strcpy(label,mhd.fileSystemLabel);
	strcat(label,".dat");
	if(naryRoot==NULL)
		printf(ERR_VFS_UPDATEFILE_04);					//VFS_NOT_MOUNTED
	else if((Node=searchBST(rootBST,filePath)) == NULL)	
		printf(ERR_VFS_UPDATEFILE_01);					//INTERNAL_FILE_NOT_FOUND
	else
	{
		blockNo = Node->filedesc->locationBlockNo;
		//printf("\n the block no is:%d",blockNo);
		
		if((fp=fopen(dataFilePath,"r"))!=NULL)
		{	fseek(fp,0,SEEK_END);
			sizeUpdate=ftell(fp);
			fseek(fp,0,SEEK_SET);
			//printf("sizeupdate is  %d",sizeUpdate);
			//printf("sizeupdate:%d",sizeUpdate);
			if(sizeUpdate>1024)
			{
				printf(ERR_VFS_UPDATEFILE_03);			//EXTERNAL_FILE_TOO_LARGE
				return check;
			}
			//rewind(fp);
			fread(strupdate,sizeof(char)*sizeUpdate,1,fp);
			strupdate[sizeUpdate-1]='\0';
			//printf("sizeupdate is  %s",strupdate);
			fclose(fp);
		}
		else
		{
			printf(ERR_VFS_UPDATEFILE_02);				//EXTERNAL_FILE_NOT_FOUND
			return check;
		
		}

		if((fp1=fopen(label,"rb+"))!=NULL)
		{
			//fwrite(strupdate,sizeUpdate,1,fp);	
			fseek(fp1,sizeof(MetaHeader),SEEK_SET);
			fseek(fp1,blockNo*sizeof(Block),SEEK_CUR);
			fwrite(strupdate,sizeUpdate,1,fp1);
			//printf("%s",strupdate);
			Node->filedesc->fileSize=sizeUpdate;
			check = 1;
			fclose(fp1);		
		}
		else
			printf(ERR_VFS_UPDATEFILE_05);				//COULD_NOT_UPDATE_FILE
	
	}
return check;
}

