#include "hash.h"

#define LOAD_FACTOR 0.75

#define INITIAL_SIZE 10
int max_size = 10;

hashmap_t* create_hashmap(hashmap_t* m){
	m = (hashmap_t*) malloc(sizeof(hashmap_t));
	m->max_size = max_size;
	m->current_size = 0;
	m->data = malloc(INITIAL_SIZE * sizeof(bucket_t));
	return m;
}

void put(char *str, hashmap_t* hashmap, int data){
	
	unsigned long index = get_index(hash(str),10);

	hashmap->data[index].key = malloc(strlen(str));

	printf("trying to get by index %d\n", (int)index);
	hashmap->data[index].hash = hash(str);
	strcpy(hashmap->data[index].key, str);
	hashmap->data[index].next = NULL;
	hashmap->data[index].data = data;

	printf("memory for key '%s' bucket was allocated\n", str);
}

unsigned long get(char* str, hashmap_t* hashmap){
	unsigned long index = get_index(hash(str),10);
	return index;
}

unsigned long get_index(unsigned long h, unsigned long length){
	return h % (length - 1);
}

unsigned long hash(char* str){
    unsigned long hash = 5381;
	int c;

	while (c = *str++)
	hash = ((hash << 5) + hash) + c; 

	return hash;
}
