//#include"vfs.h"
int create_vfs(char[],long);
int mount_vfs(char[]);
int unmount_vfs(char[]);
int make_dir(char path[],char dir[]);
int listdirs(char[],int,char[]);
int addFile(char[], char[], char[]);
int move_dir(char source_dir_path[],char dest_dir_path[]);
int delete_dir(char path[]);
int copy_file(char path1[],char path2[]);
int export_file(char path1[],char path2[]);
int updateFile ( char filePath[], char data[] );
int listFile ( char filePath[], char outputFile[]);
int move_file(char path1[],char path2[]);
int removeFile ( char filePath[]);
int searchFile(char [], char []);

struct dirNode* searchNary(struct dirNode* root,char src_path[]);
struct dirNode * rmvFrmSrcNode(char source_dir_path[], int);
void constructBST(struct dirNode *root);
int del_dir_new(char path[]);
int rmv_file(char path[]);
