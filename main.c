#include <stdio.h>
#include <stdlib.h>

unsigned long hash();
unsigned long get_index();
char* enter_key();

int main(){
    
    unsigned int len_max = 128;
    unsigned int current_size = 0;

    char *pStr = malloc(len_max);
    current_size = len_max;

    printf("\nEnter a very very very long String value:");

    if(pStr != NULL){
    
	int c = EOF;
    unsigned int i = 0;
        //accept user input until hit enter or end of file
    while ((c = getchar()) != '\n' && c != EOF)
    {
        pStr[i++]=(char)c;

        //if i reached maximize size then realloc size
        if(i == current_size){
            current_size = i+len_max;
            pStr = realloc(pStr, current_size);
        }
    }

    pStr[i] = '\0';

	printf("hash for string '%s' is %ld, index is %ld\n",pStr, hash(pStr),  get_index(hash(pStr), 10LU));
    free(pStr);
    pStr = NULL;


    }



	char str[10];

	return 0;
}

char* enter_key(char* str){

	scanf("%s", str);
	printf("hash for string is %ld, index is %ld\n", hash(str),  get_index(hash(str), 10LU));

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
