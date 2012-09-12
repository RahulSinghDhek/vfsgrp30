create_vfs.o:../src/create_vfs.c ../include/vfs.h
	gcc -c ../src/create_vfs.c
mount_vfs.o:../src/mount_vfs.c ../include/vfs.h
	gcc -c ../src/mount_vfs.c
unmount_vfs.o:../src/unmount_vfs.c ../include/vfs.h
	gcc -c ../src/unmount_vfs.c
run_vfs.o:../src/run_vfs.c ../include/commands.h
	gcc -c ../src/run_vfs.c

finalout:create_vfs.o mount_vfs.o unmount_vfs.o run_vfs.o
	gcc run_vfs.o finalout
