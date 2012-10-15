#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "vfs.h"
#include "hashTable.h"
#include "list.h"

											//1D hashing
NODE *insertnode(NODE *start, FileDescriptor *fd)
{	
	NODE *temp,*ptr;

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
	if(start==NULL)
		start=ptr;
	else
	{	temp=start;									//shorting shd be applied here afterwards
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
	}
	return start;
}

void searchFile(char name_File[])
{	int index = fun_Hash(name_File[0]);
	if(array[index] == NULL)				//Global object shd be used to access the array item
		printf("0 Files Found. Search Ended...\n");	
	else if(index == -1)
		printf("Invalid file name\n");
	else
		searchFile_internal(array[index],name_File);	//Global object shd be used to access the array item
}

void searchFile_internal(NODE *start, char name_File[])
{	int count = 0;	
	while(start!=NULL)
	{	if (strcmp((FileDescriptor *)(temp->data)->fileName,name_File)==0)
		{	printf("Loc: %s\n",(FileDescriptor *)(temp->data)->filePath);
			count++;
		}
		start = start->next;
	}
	printf("%d Files Found. Search Ended...\n",count);
}

int fun_Hash(char FirstAlpha)
{	int hashFunc =-1;
	int asciival = tolower(FirstAlpha);
	if(asciival >=97 && asciival <=122)
		hashFunc = asciival - 97 + 1;
	else if(asciival == 32)
		hashFunc = -1;
	else											//Validate File names need to handle spaces in file name
		hashFunc = 0;
	return hashFunc;
}

void display_Hash()						//Global object shd be used to access the array item
{	int i;
	NODE *temp;

	for(i=0; i<27; i++)
	{	if(array[i]==NULL)
			printf("Hash Table Empty...\n");
		else
		{	temp=array[i];
			while(temp!=NULL)
			{
				printf("%s",(FileDescriptor *)(temp->data)->fileName);
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

/*int main()
{	
	char nameFile[], pathFile[];
	int index = 0;

	//reads from the file descriptor.



	//call hash fun
	index = fun_Hash(nameFile[0]);

	//call create a node funtion and gets its address.
	array[index] = insertnode(array[index],nameFile,pathFile);


	struct hash_link *array[5]={};									//change it to 26 or some value afterwards...
	char input[50]; 
	struct hash_link *temp;
	//char chk[]='-1';
	int i;
	
	//do{
	/*	for(i=0; i<5; i++){		
		printf("\nEnter a name of file or press -1 to terminate :");
		scanf("%s",input);
		//if(!strcmp(input,chk))
		//{	
		switch (input[0])
			{
			case ('a'):	array[0]=insertnode(array[0],input);
						break;
			case ('b'):	array[1]=insertnode(array[1],input);
						break;
			case ('c'):	array[2]=insertnode(array[2],input);
						break;
			case ('d'):	array[3]=insertnode(array[3],input);
						break;
			}
	//}
		}

	return 1;
}
	
*/








