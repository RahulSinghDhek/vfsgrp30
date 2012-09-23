#include "../include/hashTable.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{	FILE *fp;
	char nameFile[500], pathFile[1000], type[50];
	int sz,lc;
	int index = 0;

	//reads from the file descriptor.
	if((fp=fopen("inputfiledesc.txt","r"))==NULL)
		printf("Cannot open file");
	else
	{
		while(fscanf(fp,"%s",nameFile)!=EOF)	//I am readinga all the details frm File Discriptors but i am using only Name and path for inserting into HashTable.... :)
		{	fscanf(fp,"%s",pathFile);
			fscanf(fp,"%s",type);
			fscanf(fp,"%d",&sz);
			fscanf(fp,"%d",&lc);

			//hashFunction Called... and Then inserted into hashtable
			index = fun_Hash(nameFile[0]);
			array[index] = insertnode(array[index],nameFile,pathFile);
		}
		
	}
	fclose(fp);

	
	display_Hash();

	return 1;
}
