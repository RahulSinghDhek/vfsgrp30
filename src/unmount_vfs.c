#include<stdio.h>
#include "commands.h"
#define TEMP_SIZE 10
void unmount_vfs(char vfs_label[])
{
	printf("%s unmounted\n",vfs_label);
	/*char temp[TEMP_SIZE];	
	strcpy(temp,label);
	strcat(temp,".dat");	//add path
	int i;
	FILE *fp;

	if((fp=fopen(lb,"wb"))==NULL)
		printf("Cannot create file");
	else
	{
		fwrite(&metaHeader,sizeof(MetaHeader),1,fp);
		fseek(fp,sizeof(MetaHeader),SEEK_SET);
		saveToFile(root,fp);
		fseek(fp,sizeof(FileDescriptor)*(metaHeader->noOfFileDescriptors),SEEK_SET);
		fwrite(&FreeList,sizeof(FreeList),1,fp);
		fseek(fp,sizeof(FreeList),SEEK_SET);
		fwrite(&block,sizeof(Block),MAX_NO_FILE_DESCRIPTORS,fp
	}*/
}

