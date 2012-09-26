OBJECTS = nAryTree.o create_vfs.o mount_vfs.o unmount_vfs.o run_vfs.o

#create final executable
finalout:$(OBJECTS)
	gcc  $(OBJECTS) -o finalout

#create nAry object
nAryTree.o: ../include/vfs.h ../include/nAryTree.h nAryTree.c
	gcc  -c nAryTree.c -I "../include"

#here create BST n HashTable objects

#create objects for commands
create_vfs.o: ../include/vfs.h ../include/commands.h create_vfs.c
	gcc -c create_vfs.c -I "../include"

mount_vfs.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h mount_vfs.c
	gcc -c mount_vfs.c -I "../include"

unmount_vfs.o: ../include/vfs.h ../include/commands.h unmount_vfs.c
	gcc -c unmount_vfs.c -I "../include"

run_vfs.o: ../include/commands.h run_vfs.c
	gcc -c run_vfs.c -I "../include"
