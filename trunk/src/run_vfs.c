#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "commands.h"
void main()
{
        while(1)
		{
		char arg1[MAX_FILE_SYSTEM_LABLE_SIZE];int k=0;char arg2[10];int l=0;
		long filesize;
		char create[]="create_vfs";
		char mount[]="mount_vfs";
		char unmount[]="unmount_vfs";
		char exitStatus[]="exit";
		int i=0,j=0;
		char command[50];
		char cmd1[15],cmd2[50];
        	printf("$");
               scanf("%s",command);
               
               	while(command[i]!='(')
		{
                cmd1[i]=command[i];
                i++;

		}
               		
                cmd1[i]='\0';
                 i++;
                
		while(command[i]!=')')
		{
                cmd2[j]=command[i];
                i++;
		j++;

               }                 
                   cmd2[j]='\0';
               if(strncmp(create,cmd1,10)==0 )
                {
			
			while(cmd2[k]!=',')

			{
				arg1[k]=cmd2[k];
					k++;
			}
			arg1[k]='\0';
			k++;
			while(cmd2[k]!='\0')
                        {
				arg2[l]=cmd2[k];	
					k++;
					l++;
			}
			filesize=strtol(arg2,NULL,10);
			
			create_vfs(arg1,filesize);

			//printf("\nvfs %s is created of size %ld\n",arg1,filesize);
		}
		
			

		else if(strncmp(mount,cmd1,9)==0)
                {
			
			while(cmd2[k]!='\0')

			{
				arg1[k]=cmd2[k];
					k++;
			}
			arg1[k]='\0';
			mount_vfs(arg1);
			//printf("vfs %s mounted\n",arg1);

			
		}



		

		else if(strncmp(unmount,cmd1,11)==0)
                {
			
			while(cmd2[k]!='\0')

			{
				arg1[k]=cmd2[k];
				k++;
			}
			arg1[k]='\0';
                       unmount_vfs(arg1);
			
			//printf("vfs %s unmounted\n",arg1);

			
		}
		
     		else if(strncmp(exitStatus,cmd1,4)==0)
			{
				printf("Exited from vfs system\n");
				exit(1);
			}
		else
		{
		printf("enter correct command\n");
		}

	}

           
}     






















