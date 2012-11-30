#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
#include "vfs.h"

#include "hashTable.h"
#define size 2

											//1D hashing
NODE *insertnode(NODE *start, FileDescriptor *fd)
{	
	NODE *ptr;

	ptr = create(fd);
	/*int i;
	int size;
	
	size=strlen(str_val);
	ptr = malloc(sizeof(struct hash_link));
	for(i=0; i< size; i++)
		ptr->name[i]=str_val[i];
	ptr->next =NULL;
	strcpy(ptr->fullPath,str_path);
		//Store the file name and Fullpath in the node... and insert it in the write location..
	*/
	/*if(start==NULL)
		start=ptr;
	else
	{	temp=start;									//shorting shd be applied here afterwards
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
	}*/
	return attach(start, ptr);
}

int searchFile(char name_File[], char outFile[])
{	//NODE *headFile = NULL;
	int index = fun_Hash(name_File[0]);
	/*if(array[index] == NULL)				//Global object shd be used to access the array item
		printf("0 Files Found. Search Ended...\n");	
	else if(index == -1)
		printf("Invalid file name\n");
	else
		headFile = */ 
return	searchFile_internal(array[index], name_File, outFile);	//Global object shd be used to access the array item

	//return headFile;
//return check;
}

int searchFile_internal(NODE *start, char name_File[], char outFile[])
{	//int count = 0;
	int check = 0, cnt_File = 0, cnt_Dir = 0;
	NODE *temp, *tmpFile, *tmpDir;	
	NODE *headFile[2]={} , *ptr = NULL;
	int len = strlen(name_File);
	FILE *fp;

	//headFile = (NODE **)malloc(size * sizeof(NODE *));
	//NODE *headFile[2]={};
	
	if(naryRoot==NULL)
		printf(ERR_VFS_SEARCHFILE_02);					//VFS_NOT_MOUNTED
	else
	{	temp = start;
		fp=fopen(outFile,"w");
		while(temp!=NULL)
		{	if (strncmp( ((FileDescriptor *)(temp->data))->fileName ,name_File, len)==0 )
			{	ptr = create(((FileDescriptor *)(temp->data)));
				if( strcmp( ((FileDescriptor *)(temp->data))->fileType, "dir") )
				{	headFile[0] = attach(headFile[0], ptr);
					cnt_File++;
				}
				else
				{	headFile[1] = attach(headFile[1], ptr);
					cnt_Dir++;
				}
			
				//printf("Loc: %s\n",((FileDescriptor *)(temp->data))->fullPath);
				//count++;
			}
			temp = temp->next;
		}
		if(fp != NULL)
		{	fprintf(fp,"%d Files Found\n",cnt_File);
			tmpFile = headFile[0];
			tmpDir = headFile[1];
			while(tmpFile != NULL)
			{	fprintf(fp,"%s\n", ((FileDescriptor *)(tmpFile->data))->fullPath);
				tmpFile = tmpFile->next;
			}
			fprintf(fp,"\n%d Folders Found\n",cnt_Dir);
			while(tmpDir != NULL)
			{	fprintf(fp,"%s\n", ((FileDescriptor *)(tmpDir->data))->fullPath);
				tmpDir = tmpDir->next;
			}
			check = 1;
		}
	}
return check;
}

NODE * deletenode(NODE *start, FileDescriptor *fDesc)		// node is the node which is to be removed
{	NODE *temp, *prev= start;
	temp = start;
	while(temp!=NULL && ((FileDescriptor *)(temp->data)) != fDesc) 
	{	prev = temp;
		temp=temp->next; 	// move the pointer up to that node
	}
	
	if(temp == start) 
	{	start = temp->next;
	} 
	else
		prev->next = temp->next;
return start;
}          

int fun_Hash(char FirstAlpha)
{	int hashFunc =-1;
	int asciival = tolower(FirstAlpha);
	if(asciival >=97 && asciival <=122)
		hashFunc = asciival - 97 + 1;
	else if(asciival == 32)
		hashFunc = -1;
	else							//Validate File names need to handle spaces in file name
		hashFunc = 0;
	return hashFunc;
}

void display_Hash()						//Global object shd be used to access the array item
{	int i;
	NODE *temp;

	for(i=0; i<27; i++)
	{	if(array[i]==NULL)
			;//printf("Hash Table Empty...\n");
		else
		{	temp=array[i];
			while(temp!=NULL)
			{
				printf("%s",((FileDescriptor *)(temp->data))->fileName);
				if(temp->next!=NULL)
				{
					printf("-->");
				}
				temp=temp->next;
			}
			printf("\n");
		}
	}
}
