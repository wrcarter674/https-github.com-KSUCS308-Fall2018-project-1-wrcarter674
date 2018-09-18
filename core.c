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
   if(source){
	char encrypted;
	if(source+key >= 'Z'){
		encrypted = source+key-CHARACTER_COUNT;
		return encrypted;
	}
	else{
		encrypted = source+key;
		return encrypted;
	}
   }
	return FALSE
}

void encrypt_string(char * message, int key, int step) {
	if(message){
		char encrypted[strlen(*message)];
		for(int i = 0; message[i] != '\0'; i++){
			encrypted[i] = encrypt_character(message[i], key+(step*i));
		}
	printf("%s", encrypted);
	}

}

char decrypt_character(char source, int key) {
	if((source-key)< 'A'){
		source = CHARACTER_COUNT-(abs(source-key));
	}
	else{
		source = source-key;
	}
	 return source;
}

void decrypt_string(char * message, int key, int step) {
	int count=0;
	for(count; message[count] != '/0'; count++);
	char decrypted[count];
	int length = count;
	for(count; count>=0; count--){
		decrypted[length-count]= decrypt_character(message[count], (step+key*count));
	}
	printf("%s", decrypted);

}

void print_usage() {
    printf("Usage:\n");
    printf("\t./main encrypt message key key_offset\n");
    printf("\t./main decrypt message key key_offset\n");
}

int core_main(int argc, const char * argv[]) {
	if(argv[1] = "encrypt"){
		encrypt_string(* argv[2],(int) *argv[3], (int) *argv[4]);
	}
	else if(argv[1] = "decrypt"){
		decrypt_string(* argv[2],(int) *argv[3],(int) *argv[4]);
	}
	else{
		printf("%s %d", "Unknown command error: ", *argv[1]);
	}

    print_usage();
    return 0;
}
