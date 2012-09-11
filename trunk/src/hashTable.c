#include<stdio.h>
#include<stdlib.h>
#include<string.h>										//In struct name is of fixed size,
										//1D hashing
struct hash_tab
{	char name[100];
	struct hash_tab *next;
};

struct hash_tab *insertnode(struct hash_tab *start, char str_val[])
{	
	struct hash_tab *temp,*ptr;
	int i;
	int size;
	
	size=sizeof(str_val);
	ptr = malloc(sizeof(struct hash_tab));
	for(i=0; i< size; i++)
		ptr->name[i]=str_val[i];
	ptr->next =NULL;

	if(start==NULL)
		start=ptr;
	else
	{	temp=start;							//shorting shd be applied here afterwards
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
	}
	return start;
}
	
int main()
{	struct hash_tab *array[5]={};						//change it to 26 or some value afterwards...
	char input[50]; 
	struct hash_tab *temp;
	//char chk[]='-1';
	int i;
	
	//do{
		for(i=0; i<5; i++){		
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

	for(i=0; i<4; i++)
	{	if(array[i]==NULL)
			printf("empty\n");
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
	

	

	return 1;
}
	









