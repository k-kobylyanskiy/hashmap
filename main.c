#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


void check_string(){
    unsigned int len_max = 128;
    unsigned int current_size = 0;

    char *pStr = malloc(len_max);
    current_size = len_max;

    if(pStr != NULL){
    
		int c = EOF;
   		unsigned int i = 0;

    	while ((c = getchar()) != '\n' && c != EOF){
        	pStr[i++]=(char)c;

        	if(i == current_size){
            	current_size = i+len_max;
            	pStr = realloc(pStr, current_size);
        	}
    	}

    	pStr[i] = '\0';
		
		put(pStr);
		printf("hash for string '%s' is %ld, index is %ld\n",pStr, hash(pStr),  get_index(hash(pStr), 100));
    	free(pStr);
    	pStr = NULL;

    }
}


int main(){
	
	create_hashmap();

  	for (int i = 0; i < 5; i++){
		check_string();
	}
	return 0;
}
