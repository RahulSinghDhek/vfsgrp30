OBJECTS = ../bin/nAryTree.o ../bin/create_vfs.o ../bin/mount_vfs.o ../bin/makedir.o ../bin/unmount_vfs.o ../bin/vfsdriver.o ../bin/binarySearchTree.o ../bin/list.o ../bin/hashTable.o ../bin/addFile.o ../bin/list_dir.o ../bin/deletedir.o ../bin/copyfile.o ../bin/exportfile.o ../bin/updateFile.o ../bin/listFile.o ../bin/movedir.o ../bin/movefile.o ../bin/removefile.o

#create final executable
../bin/vfs_group30:$(OBJECTS)
	gcc  $(OBJECTS) -o "../bin/vfs_group30"

#create nAry object
../bin/nAryTree.o: ../include/list.h ../include/vfs.h ../include/nAryTree.h ../src/nAryTree.c
	gcc -g -c ../src/nAryTree.c -I "../include" -o "../bin/nAryTree.o"

#create BST object
../bin/binarySearchTree.o: ../include/vfs.h ../include/binarySearchTree.h ../src/binarySearchTree.c
	gcc -c ../src/binarySearchTree.c -I "../include" -o "../bin/binarySearchTree.o"

#create hash table objects
../bin/list.o: ../include/vfs.h ../src/list.c
	gcc -g -c ../src/list.c -I "../include" -o "../bin/list.o"

../bin/hashTable.o: ../include/vfs.h ../include/hashTable.h  ../src/hashTable.c
	gcc -g -c ../src/hashTable.c -I "../include" -o "../bin/hashTable.o"

#create objects for commands
../bin/create_vfs.o: ../include/vfs.h ../include/commands.h ../src/create_vfs.c
	gcc -c ../src/create_vfs.c -I "../include" -o "../bin/create_vfs.o"

../bin/deletedir.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/deletedir.c
	gcc -c ../src/deletedir.c -I "../include" -o "../bin/deletedir.o"

../bin/mount_vfs.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/mount_vfs.c
	gcc -c ../src/mount_vfs.c -I "../include" -o "../bin/mount_vfs.o"

../bin/removefile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/removefile.c
	gcc -c ../src/removefile.c -I "../include" -o "../bin/removefile.o"

../bin/movefile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/movefile.c
	gcc -c ../src/movefile.c -I "../include" -o "../bin/movefile.o"

../bin/listFile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/listFile.c
	gcc -c ../src/listFile.c -I "../include" -o "../bin/listFile.o"

../bin/updateFile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/updateFile.c
	gcc -c ../src/updateFile.c -I "../include" -o "../bin/updateFile.o"

../bin/exportfile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/exportfile.c
	gcc -c ../src/exportfile.c -I "../include" -o "../bin/exportfile.o"

../bin/copyfile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/copyfile.c
	gcc -c ../src/copyfile.c -I "../include" -o "../bin/copyfile.o"

../bin/movedir.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/movedir.c
	gcc -g -c ../src/movedir.c -I "../include" -o "../bin/movedir.o"

../bin/makedir.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/makedir.c
	gcc -g -c ../src/makedir.c -I "../include" -o "../bin/makedir.o"

../bin/list_dir.o: ../include/list.h ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../src/list_dir.c
	gcc -g -c ../src/list_dir.c -I "../include" -o "../bin/list_dir.o"

../bin/addFile.o: ../include/vfs.h ../include/commands.h ../include/nAryTree.h ../include/binarySearchTree.h ../include/hashTable.h ../src/addFile.c
	gcc -c ../src/addFile.c -I "../include" -o "../bin/addFile.o"

../bin/unmount_vfs.o: ../include/vfs.h ../include/commands.h ../src/unmount_vfs.c
	gcc -c ../src/unmount_vfs.c -I "../include" -o "../bin/unmount_vfs.o"

../bin/vfsdriver.o: ../include/commands.h ../src/vfsdriver.c
	gcc -g -c ../src/vfsdriver.c -I "../include" -o "../bin/vfsdriver.o"

clean:
	rm ../bin/*.o
	rm ../bin/vfs_group30

#run_vfs.o: ../include/commands.h run_vfs.c
#	gcc -c run_vfs.c -I "../include"
