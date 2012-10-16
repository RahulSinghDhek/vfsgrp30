void insertData(FileDescriptor fdArray[])
{
	int i;
	struct dirNode* nAryroot=NULL;
	for(i=0;i<MAX_NO_OF_FILE_DESCRIPTORS && fdArray[i]!=NULL;i++)
	{
		FileDescriptor *fd;
		fd=(FileDescriptor*)malloc(sizeof(FileDescriptor));
		strcpy(fd->fileName,fdArray[i]->fileName);
		strcpy(fd->filePath,fdArray[i]->filePath);
		strcpy(fd->fileType,fdArray[i]->fileType);
		fd->fileSize=fdArray[i]->fileSize;
		fd->locationBlockNo=fdArray[i]->locationBlockNo;
	
		nAryroot=insertNAry(fd,nAryroot,&flag);
		bstRoot=insertBST(bstRoot,fd,&flag);
		hashRoot=insertHashTable(hashRoot,fd,&flag);
	}
}
