#include "vfs.h"
#include<stdio.h>
#include<string.h>
void create_vfs(char label[],long systemSize)
{
	
	char lb[10];	//re-name
	strcpy(lb,label);
	strcat(lb,".dat");	//add path
	int i;
	FILE *fp;
	
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
}

int main()
{
	create_vfs("pandav",40960);
}
