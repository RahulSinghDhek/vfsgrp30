#include "../include/vfs.h"
#include "../include/commands.h"
#include<stdio.h>
#include<string.h>
void create_vfs(char label[],long systemSize)
{
	
	char lb[MAX_FILE_SYSTEM_LABLE_SIZE];	//re-name
	strcpy(lb,label);
	strcat(lb,".dat");	//add path
	int i;
	FILE *fp;
	MetaHeader metaHeader;
	
	vfs_size=systemSize;
	if((fp=fopen(lb,"wb"))==NULL)
		printf("Cannot create file");
	else
	{
		for(i=0;i<=(systemSize/sizeof(Block));i++)
		{
			Block block;
			fwrite(&block,sizeof(Block),1,fp);
			fseek(fp,sizeof(Block)*i,SEEK_SET);
		}
	}
	
	fseek(fp,0,SEEK_SET);
	fwrite(&metaHeader,sizeof(MetaHeader),1,fp);
}
