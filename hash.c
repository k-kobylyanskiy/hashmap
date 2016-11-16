#include "hash.h"

#define LOAD_FACTOR 0.75

#define INITIAL_SIZE 10

hashmap_t* create_hashmap(hashmap_t* m){
	m = (hashmap_t*) malloc(sizeof(hashmap_t));
	m->max_size = INITIAL_SIZE;
	m->current_size = 0;
	m->data = malloc(INITIAL_SIZE * sizeof(bucket_t*));
	return m;
}

void put(char *str, hashmap_t* hashmap, int data){

	//creating bucket
	
	bucket_t* this = (bucket_t*) malloc(sizeof(bucket_t));
	this->hash = hash(str);

	this->key = malloc(strlen(str));
	strcpy(this->key, str);
	this->next = NULL;
	this->data = data;

	// solving collision with chaining

	unsigned long index = get_index(hash(str),10);

	if(hashmap->data[index] == NULL){
		hashmap->data[index] = this;
	} else {
		
		bucket_t* p = hashmap->data[index]; 		

		while(p->next != NULL){
			p = p->next; 
		}
		
		p->next = this;
	}
	
	hashmap->current_size++;
}

int* get(char* str, hashmap_t* hashmap){
	
	unsigned long index = get_index(hash(str),10);
	bucket_t* p = hashmap->data[index];

	if(p == NULL){
		return NULL;
	}

	if(!strcmp(p->key ,str)){
		return &(p->data);
	}

	while(p->next != NULL){
		p = p->next;
		if(!strcmp(p->key, str))
			return &(p->data);
	}
	
	return NULL;
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
