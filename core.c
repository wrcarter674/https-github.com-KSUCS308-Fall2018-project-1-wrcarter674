//
//  core.c
//  Project 1 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "core.h"

#define CHARACTER_COUNT (LAST_CHARACTER - FIRST_CHARACTER + 1) 
#define FIRST_CHARACTER 'A'
#define LAST_CHARACTER 'Z'

#define TRUE 1;
#define FALSE 0;

int is_number_convertable(const char * string) {
    int len = strlen(string);
    const char * s = string;
    
    for (int i = 0; i < len; i++) {
        if (!isdigit(*s)) {
            return FALSE;
        }
        s++;
    }
     return TRUE;
}

char encrypt_character(char source, int key) {
	if(key <= 0){
		return source;
	}
	source = source + (key % CHARACTER_COUNT);
	if(source > LAST_CHARACTER){
		source = (source-LAST_CHARACTER)+FIRST_CHARACTER -1;
	}
	return source;
}

void encrypt_string(char * message, int key, int step) {
	int count =0;
	while(*message != '\0'){
		if(*message != ' '){
			*message = encrypt_character(*message, (key+(step*count)));
		}
		count++;
		message++;
	}
}

char decrypt_character(char source, int key) {
	if(key <=0){
		return source;
	}
	source = source - (key % CHARACTER_COUNT);
	if(source < FIRST_CHARACTER){
		source = LAST_CHARACTER-(FIRST_CHARACTER-source)+1;
	}

	 return source;
}

void decrypt_string(char * message, int key, int step) {
	int count =0;
	while(*message != '\0'){
		if(*message != ' '){
			*message = decrypt_character(*message, (key+(step*count)));
		}
		count++;
		message++;
	}

}

void print_usage() {
    printf("Usage:\n");
    printf("\t./main encrypt message key key_offset\n");
    printf("\t./main decrypt message key key_offset\n");
}

int isValid(const char * value){
	while(*value != '\0'){
		if(!(*value >= '0') || !(*value <= '9')){
			return FALSE;
		}
		value++;
	}
	return TRUE;
}

int core_main(int argc, const char * argv[]){
	if(argc < 5){
		printf("Missing arguements\n");
		return 1;
	}

	if(!isValid(argv[3])){
		printf("Key must be an integer.");
		return 1;
	}

	if(!isValid(argv[4])){
		printf("Key offset must be an integer\n");
		return 1;
	}
	if(strlen(argv[2]) > 100){
		printf("Max message length is 100 characters\n");
		return 1;
	}

	char op[100];
	strcpy(op, argv[1]);
	char message[100];
	strcpy(message, argv[2]);
	
	int key = atoi(argv[3]);
	int step = atoi(argv[4]);
	if(strncmp(op, "encrypt", 7) ==0){
		encrypt_string(message, key, step);
	}else if(strncmp(op, "decrypt", 7) ==0){
		decrypt_string(message, key, step);
	}
	else{
		printf("Unknown command: %s\n", op);
		return 1;
	}
	
	printf("%s\n", message);
	return 0;
}
