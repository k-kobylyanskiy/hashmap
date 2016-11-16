#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


void check_string(hashmap_t* hashmap){
    unsigned int len_max = 128;
    unsigned int current_size = 0;

    char *p_str = malloc(len_max);
    current_size = len_max;

    if(p_str != NULL){
    
		int c = EOF;
   		unsigned int i = 0;

    	while ((c = getchar()) != '\n' && c != EOF){
        	p_str[i++]=(char)c;

        	if(i == current_size){
            	current_size = i+len_max;
            	p_str = realloc(p_str, current_size);
        	}
    	}

    	p_str[i] = '\0';
		
		put(p_str, hashmap);
		printf("hash for string '%s' is %ld, index is %ld\n",p_str, hash(p_str),  get_index(hash(p_str), 10));
    	free(p_str);
    	p_str = NULL;

    }
}


int main(){
	
	hashmap_t* m = create_hashmap(m);
	printf("memory for hashmap was allocated, max_size is %d elements\n", m->max_size);

  	for (int i = 0; i < 5; i++){
		check_string(m);
	}
  	for (int i = 0; i < 10; i++){
		printf("index is %d\nhash is %ld\n", i, m->data[i].hash);
		printf("key is %s\n\n", m->data[i].key);
	}

	printf("Enter a string to get information about bucket\n");
	char s[5];
	scanf("%s", s);
	printf("hash is %ld", m->data[get(s, m)].hash);

	return 0;
}
