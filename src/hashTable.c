#include<stdio.h>
#include<stdlib.h>
#include<string.h>										//In struct, name is of fixed size,
												//1D hashing
struct hash_link *insertnode(struct hash_link *start, char str_val[], char str_path[])
{	
	struct hash_link *temp,*ptr;
	int i;
	int size;
	
	size=sizeof(str_val);
	ptr = malloc(sizeof(struct hash_link));
	for(i=0; i< size; i++)
		ptr->name[i]=str_val[i];
	ptr->next =NULL;
	strcpy(ptr->fullPath,str_path);
		//Store the file name and Fullpath in the node... and insert it in the write location..

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

void serchStartPoint(char name_File[])
{	int index = fun_Hash(name_File[0]);
	if(array[index] == NULL)
		printf("0 Files Found. Search Ended...\n");	
	else if(index == -1)
		printf("Invalid file name\n");
	else
		char Result[] = searchFile(array[index],name_File);
}

void searchFile(struct hash_link *start, char name_File[])
{	int count = 0;	
	while(start->next!=NULL)
	{	if (strcmp(start->name,name_File)==0)
		{	printf("Loc: %s\n",start->fullpath);
			count++;
		}
		start = start->next;
	}
	if(count == 0)
		printf("%d Files Found. Search Ended...\n",count);
}

int fun_Hash(char FirstAlpha)
{	int hashFunc, asciival = tolower(FirstAlpha);
	if(asciival >=97 && asciival <=122)
		hashFunc = asciival - 97 + 1;
	else if(asciival == 32)
		hashFunc = -1;
	else											//Validate File names need to handle spaces in file name
		hashFunc = 0;
	return hashFunc;
}

void display_Hash()
{	for(i=0; i<27; i++)
	{	if(array[i]==NULL)
			printf("Hash Table Empty...\n");
		else
		{	temp=array[i];
			while(temp!=NULL)
			{
				printf("%s",temp->name);
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

int main()
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
	*/
	return 1;
}
	









