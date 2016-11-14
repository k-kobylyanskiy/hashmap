#include "hash.h"

#define LOAD_FACTOR 0.75

int max_size = 10;

typedef struct hashmap_t {
	int max_size;
	int current_size;
} hashmap;

typedef struct bucket_t {
	char* key;
	int data;
	struct bucket_t* next;
} bucket;

void create_hashmap(){
	struct hashmap_t* m = (hashmap*) malloc(sizeof(hashmap));

	printf("memory for hashmap was allocated\n");
}

void put(char *str){
	struct bucket_t* b = (bucket*) malloc(sizeof(bucket));
	printf("memory for bucket was allocated\n");
}

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
