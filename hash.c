unsigned long get_index(unsigned long h, unsigned long length){
	return h % (length - 1);
}

unsigned long hash(char *str){
    unsigned long hash = 5381;
	int c;

	while (c = *str++)
	hash = ((hash << 5) + hash) + c; 

	return hash;
}
