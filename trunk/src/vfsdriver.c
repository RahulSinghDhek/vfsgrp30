/*
 * File: vfsdriver.c
 *
 * Description: This is a driver program for testing your VFS system using an interaction script as input
 * You need to make additional calls to your respective functions as noted in the comments below
 * Make sure the output you display is exactly as per the given specifications for you. Do NOT print
 * any extra output (like debug messages) in the final version of your driver program. You can use this driver program
 * in a in incremental manner as you keep implementing one operator after another. For operators not yet implemented,
 * you can leave the output as given ("TO_BE_SUCCESS"). So you can use this program as your "main" program for testing purposes.
 *
 * DO NOT write the full code for operators in the driver program! You must only CALL your functions from here.
 *
 * Usage: vfsdriver <scriptfilename>
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
#include "vfs.h"
#include "commands.h"
#define BUFSIZE 200
#define CMDSIZE 30
#define PARSIZE 100

void createvfs ( char *P1, int P2 );
void mountvfs ( char *P1 );
void unmountvfs ( char *P1 );
void makedir ( char *P1, char *P2 );
void deletedir ( char *P1 );
void movedir ( char *P1, char *P2 );
void listdir ( char *P1, int P2, char *P3 );
void addfile ( char *P1, char *P2, char *P3 );
void listfile ( char *P1, char *P2 );
void updatefile ( char *P1, char *P2 );
void removefile ( char *P1 );
void movefile ( char *P1, char *P2 );
void copyfile ( char *P1, char *P2 );
void exportfile ( char *P1, char *P2 );
void searchfile ( char *P1, char *P2 );

void processcommand( char *command, char *P1, char *P2, char *P3 );

int main( int argc, char *argv[] )
{
	FILE *scriptfp;
	char linebuffer[BUFSIZE];
	char command[CMDSIZE], par1[PARSIZE], par2[PARSIZE], par3[PARSIZE];
	char *token;

	if( argc != 2 ){
		fprintf(stderr,"Usage: vfsdriver <scriptfile>\n");
		return(1);
	}

	if( (scriptfp=fopen(argv[1],"r")) == NULL ){
		fprintf(stderr,"Unable to open script file: %s\n", argv[1]);
		return(2);
	}

	while( fgets(linebuffer, sizeof(linebuffer), scriptfp) != NULL ){
		/* This output is for debugging... do not uncomment in final version */
		/*
		printf("==================================================\n");
		printf("Processing: %s", linebuffer);
		printf("==================================================\n");
		*/

		/* Remove the extra newline character in the end of line */
		linebuffer[ strlen(linebuffer)-1 ] = '\0';
		
		/* Get the command and the parameters using tokenizer */
		strcpy( command, (token = strtok(linebuffer, " ")) == NULL ? "" : token );
		
		strcpy( par1, (token = strtok(NULL, " ")) == NULL ? "" : token );
		strcpy( par2, (token = strtok(NULL, " ")) == NULL ? "" : token );
		strcpy( par3, (token = strtok(NULL, " ")) == NULL ? "" : token );
		 //printf("Command:%s:p1:%s:p2:%s:p3:%s\n",command, par1, par2, par3); 

		processcommand( command, par1, par2, par3 );
	}
}

void processcommand( char *command, char *P1, char *P2, char *P3 )
{
	if( strcmp(command, "createvfs") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){
			
			printf(ERR_VFS_CREATE_00);
		}	
		else
		{
			int size = atoi(P2);
			createvfs (P1,size);
		}	
	}
	else if( strcmp(command, "mountvfs") == 0 )
		if(strcmp(P1,"")==0){
			
			printf(ERR_VFS_MOUNT_00);
		}
		else
			mountvfs (P1);
	else if( strcmp(command, "unmountvfs") == 0 )
		if(strcmp(P1,"")==0){

			printf(ERR_VFS_UNMOUNT_00);
		}	
		else
			unmountvfs(P1);
	else if( strcmp(command, "makedir") == 0 )
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_MAKEDIR_00);
		}
		else
			makedir (P1,P2);
	else if( strcmp(command, "deletedir") == 0 )
		if(strcmp(P1,"")==0){

			printf(ERR_VFS_DELETEDIR_00);
		}
		else
			deletedir (P1);		
	else if( strcmp(command, "movedir") == 0 )
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_MOVEDIR_00);
		}
		else   
			movedir (P1,P2);
		
	else if( strcmp(command, "listdir") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_LISTDIR_00);
		}
		else   
		{
			int flag = atoi(P2);
			listdir (P1,flag,P3);
		}
	}
	else if( strcmp(command, "addfile") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0||strcmp(P3,"")==0){

			printf(ERR_VFS_ADDFILE_00);
		}
		else  
			addfile (P1,P2,P3);		
		}
	else if( strcmp(command, "listfile") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_LISTFILE_00);
		}	
		else  
			listfile (P1,P2);		
		}
		
	else if( strcmp(command, "updatefile") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_UPDATEFILE_00);
		}	
		else 
			updatefile (P1,P2);
		}
	else if( strcmp(command, "removefile") == 0 ){
		if(strcmp(P1,"")==0){

			printf(ERR_VFS_REMOVEFILE_00);
		}	
		else 
			removefile (P1);
		}	
	else if( strcmp(command, "movefile") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_MOVEFILE_00);
		}
		else  
			movefile (P1,P2);		
		}
	else if( strcmp(command, "copyfile") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_COPYFILE_00);
		}
		else  
			copyfile (P1,P2);
		}			
	else if( strcmp(command, "exportfile") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_EXPORTFILE_00);
		}
		else  
			exportfile (P1,P2);	
		}	
	else if( strcmp(command, "searchfile") == 0 ){
		if(strcmp(P1,"")==0||strcmp(P2,"")==0){

			printf(ERR_VFS_SEARCHFILE_00);
		}	
		else  
			searchfile (P1,P2);
		}	
		
	else
		printf("Ignoring invalid command %s\n", command);
}

void createvfs ( char *P1, int P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(create_vfs(P1,P2))
		printf("createvfs_SUCCESS\n");		
}

void mountvfs ( char *P1 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(mount_vfs(P1))
		printf("mountvfs_SUCCESS\n");
}

void unmountvfs ( char *P1 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(unmount_vfs(P1))
		printf("unmountvfs_SUCCESS\n");
}

void makedir ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if((strcmp(P1,"/")!=0) && (P1[strlen(P1)-1]=='/'))
		P1[strlen(P1)-1]='\0';
	if(make_dir(P1,P2))
		printf("makedir_SUCCESS\n");	
}

void deletedir ( char *P1 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if((strcmp(P1,"/")!=0) && (P1[strlen(P1)-1]=='/'))
		P1[strlen(P1)-1]='\0';
	if(del_dir_new(P1))
		printf("deletedir_SUCCESS\n");
}

void movedir ( char *P1, char *P2 )
{	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if((strcmp(P1,"/")!=0) && (P1[strlen(P1)-1]=='/'))
		P1[strlen(P1)-1]='\0';
	if((strcmp(P2,"/")!=0) && (P2[strlen(P2)-1]=='/'))
		P2[strlen(P2)-1]='\0';
	if(move_dir(P1,P2))	
		printf("movedir_SUCCESS\n");	
}

void listdir ( char *P1, int P2, char *P3 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if((strcmp(P1,"/")!=0) && (P1[strlen(P1)-1]=='/'))
		P1[strlen(P1)-1]='\0';
	if(listdirs(P1,P2,P3))
		printf("listdir_SUCCESS\n");
}

void addfile ( char *P1, char *P2, char *P3 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if((strcmp(P1,"/")!=0) && (P1[strlen(P1)-1]=='/'))
		P1[strlen(P1)-1]='\0';
	if(addFile(P1,P2,P3))
		printf("addfile_SUCCESS\n");
}

void listfile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(listFile (P1,P2))
		printf("listfile_SUCCESS\n");
}

void updatefile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(updateFile(P1,P2))
		printf("updatefile_SUCCESS\n");
}	

void removefile ( char *P1 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(rmv_file(P1))
		printf("removefile_SUCCESS\n");	
}

void movefile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(move_file(P1,P2))	
		printf("movefile_SUCCESS\n");
}

void copyfile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(copy_file(P1,P2))
		printf("copyfile_SUCCESS\n");
}

void exportfile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(export_file(P1,P2))
		printf("exportfile_SUCCESS\n");
}

void searchfile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	if(searchFile(P1,P2))
		printf("searchfile_SUCCESS\n");		
}


