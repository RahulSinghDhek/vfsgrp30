//#include"vfs.h"
void create_vfs(char[],long);
void mount_vfs(char[]);
void unmount_vfs(char[]);
void make_dir(char path[],char dir[]);
void listdirs(char[],int,char[]);
void addFile(char[], char[], char[]);
char* move_dir(char source_dir_path[],char dest_dir_path[]);
void delete_dir(char path[]);
void copy_file(char path1[],char path2[]);
void export_file(char path1[],char path2[]);

struct dirNode* searchNary(struct dirNode* root,char src_path[]);
