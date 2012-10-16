#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//char tokens[10][10];
char* parsePath(char *path)
{
	int l,i,j=0,dec=1,k;
	char *temp;
	char *pat;
	pat=(char*)malloc(sizeof(10));
	char tokens[10][10];
	temp=(char*)malloc(sizeof(10));
	l=strlen(path);
	for(i=1;i<l;i++)
	{		
		if(dec==1)
		{
			k=0;
			dec=0;
		}	
		if(path[i]=='/')	
		{
			*(temp+k)='\0';
			strcpy(tokens[j],temp);		//Copy the token when you get '/'
			j++;
			dec=1;
		}
		else
		{
			*(temp+k)=path[i];	//Append to temp until '/' in the path
			k++;
		}
	}
	*(temp+k)='\0';
	strcpy(tokens[j],temp);
	strcat(pat,"/");
	for(i=0;i<j;i++){
		strcat(pat,tokens[i]);
		strcat(pat,"/");
	}
	return pat;
}

int main()
{
	char p[10];
	//char tokens[10][10]
	strcpy(p,"/he");
	int i;
	char *pat;
	pat=(char*)malloc(sizeof(10));
	strcpy(pat,parsePath(p));
	printf("%s\n",pat);
	//printf("%d\n",l);
	//for(i=0;i<l;i++)
	//	printf("%s\n",tokens[i]);
}
	
