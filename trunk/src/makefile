OBJECTS = nAryTree.o create_vfs.o mount_vfs.o makedir.o unmount_vfs.o run_vfs.o binarySearchTree.o list.o hashTable.o
#binarySearchTree.o

#create final executable
finalout:$(OBJECTS)
	gcc  $(OBJECTS) -o finalout

#create nAry object
nAryTree.o: ../include/list.h ../include/vfs.h ../include/nAryTree.h nAryTree.c
	gcc  -c nAryTree.c -I "../include"

#create BST object
binarySearchTree.o: ../include/vfs.h ../include/binarySearchTree.h binarySearchTree.c
	gcc -c binarySearchTree.c -I "../include"

#create hash table objects
list.o: ../include/vfs.h list.c
	gcc -c list.c -I "../include"

hashTable.o: ../include/vfs.h ../include/hashTable.h  hashTable.c
	gcc -c hashTable.c -I "../include"

#create objects for commands
create_vfs.o: ../include/vfs.h ../include/commands.h create_vfs.c
	gcc -c create_vfs.c -I "../include"

mount_vfs.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h mount_vfs.c
	gcc -c mount_vfs.c -I "../include"

makedir.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h makedir.c
	gcc -c makedir.c -I "../include"

unmount_vfs.o: ../include/vfs.h ../include/commands.h unmount_vfs.c
	gcc -c unmount_vfs.c -I "../include"

run_vfs.o: ../include/commands.h run_vfs.c
	gcc -c run_vfs.c -I "../include"
