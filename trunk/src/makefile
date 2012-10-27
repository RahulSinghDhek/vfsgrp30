OBJECTS = nAryTree.o create_vfs.o mount_vfs.o makedir.o unmount_vfs.o vfsdriver.o binarySearchTree.o list.o hashTable.o list_dir.o
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

list_dir.o: ../include/list.h ../include/vfs.h ../include/commands.h ../include/nAryTree.h makedir.c
	gcc -c list_dir.c -I "../include"

unmount_vfs.o: ../include/vfs.h ../include/commands.h unmount_vfs.c
	gcc -c unmount_vfs.c -I "../include"

vfsdriver.o: ../include/commands.h vfsdriver.c
	gcc -c vfsdriver.c -I "../include"

clean:
	rm *.o
	rm finalout

#run_vfs.o: ../include/commands.h run_vfs.c
#	gcc -c run_vfs.c -I "../include"
