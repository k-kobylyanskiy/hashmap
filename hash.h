#ifndef _HASH_FUNCTIONS_

#define _HASH_FUNCTIONS_

#include <stdio.h>
#include <stdlib.h>

typedef struct bucket bucket_t;

struct bucket {
	unsigned long hash;
	char* key;
	int data;
	bucket_t* next;
};

typedef struct hashmap hashmap_t;

struct hashmap {
	int max_size;
	int current_size;
	bucket_t* data;
};

hashmap_t* create_hashmap();
void put();
unsigned long hash();
unsigned long get_index();

#endif

