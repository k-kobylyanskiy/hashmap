#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

char* check_string(char* p_str){
    unsigned int len_max = 128;
    unsigned int current_size = 0;

    p_str = malloc(len_max);
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
    	return p_str;
    }
}

void put_element(hashmap_t* hashmap){
	printf("Enter the key:\n");
	char* key = check_string(key);
	int data;
	printf("Enter the data:\n");
	char* str = check_string(key);
	data = strtoul(str, NULL, 10);
	put(key, hashmap, data);

	free(key);
	free(str);
}


int main(){
	
	hashmap_t* m = create_hashmap(m);

	printf("Enter count of buckets: ");
	char* str = check_string(str);
	int n = strtoul(str, NULL, 10);

  	for (int i = 0; i < n; i++){
		put_element(m);
	}

	printf("Enter a string to get information about bucket\n");
	char s[5];
	
	while (scanf("%s", s)!= EOF){
	
	int* data = get(s,m);
	if(data != NULL)
		printf("data is %d\n", *data);
	else 
		printf("there is no such element\n");
	}
	
	printf("\nHashmap contains %d buckets\n", m->current_size);

	return 0;
}
