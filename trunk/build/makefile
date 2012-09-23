finalout: ../bin/create_vfs.o ../bin/mount_vfs.o ../bin/unmount_vfs.o ../bin/run_vfs.o
	gcc ../bin/create_vfs.o ../bin/mount_vfs.o ../bin/unmount_vfs.o ../bin/run_vfs.o -o finalout
create_vfs.o: ../src/create_vfs.c
	gcc -c ../src/create_vfs.c -o ../bin/create_vfs.o
mount_vfs.o: ../src/mount_vfs.c
	gcc -c ../src/mount_vfs.c -o ../bin/mount_vfs.o
unmount_vfs.o: ../src/unmount_vfs.c
	gcc -c ../src/unmount_vfs.c -o ../bin/unmount_vfs.o
run_vfs.o: ../src/run_vfs.c
	gcc -c ../src/run_vfs.c -o ../bin/run_vfs.o

