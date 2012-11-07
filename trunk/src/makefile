OBJECTS = nAryTree.o create_vfs.o mount_vfs.o makedir.o unmount_vfs.o vfsdriver.o binarySearchTree.o list.o hashTable.o addFile.o list_dir.o deletedir.o copyfile.o exportfile.o updateFile.o listFile.o movedir.o movefile.o removefile.o

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

deletedir.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h deletedir.c
	gcc -c deletedir.c -I "../include"

mount_vfs.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h mount_vfs.c
	gcc -c mount_vfs.c -I "../include"

removefile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h mount_vfs.c
	gcc -c removefile.c -I "../include"

movefile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h mount_vfs.c
	gcc -c movefile.c -I "../include"

listFile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h mount_vfs.c
	gcc -c listFile.c -I "../include"

updateFile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h mount_vfs.c
	gcc -c updateFile.c -I "../include"

exportfile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h exportfile.c
	gcc -c exportfile.c -I "../include"

copyfile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h copyfile.c
	gcc -c copyfile.c -I "../include"

movedir.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h movedir.c
	gcc -c movedir.c -I "../include"

makedir.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h makedir.c
	gcc -c makedir.c -I "../include"

list_dir.o: ../include/list.h ../include/vfs.h ../include/commands.h ../include/nAryTree.h makedir.c
	gcc -c list_dir.c -I "../include"

addFile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h addFile.c
	gcc -c addFile.c -I "../include"

unmount_vfs.o: ../include/vfs.h ../include/commands.h unmount_vfs.c
	gcc -c unmount_vfs.c -I "../include"

vfsdriver.o: ../include/commands.h vfsdriver.c
	gcc -c vfsdriver.c -I "../include"

clean:
	rm *.o
	rm finalout

#run_vfs.o: ../include/commands.h run_vfs.c
#	gcc -c run_vfs.c -I "../include"
