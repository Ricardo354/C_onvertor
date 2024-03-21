#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void decimal_to_binary(long number);
int binary_to_decimal(char* binary);

int main(int argc, char *argv[]){

    if (argc < 3){
        printf("Usage: %s [btod/dtob] [number]n\n", argv[0]);
        return 1;
    }
    

    if (strcmp(argv[1], "btod") == 0){
        printf("%d\n", binary_to_decimal(argv[2]));
    } 
    else if (strcmp(argv[1], "dtob") == 0){
        decimal_to_binary(atoi(argv[2]));
    }
    
    

}

int binary_to_decimal(char* binary){

    int result = 0;
    
    for (int i = 0; i < strlen(binary); i++){
        if (binary[i] == '1'){
            result = (result << 1) | 1;
        }
        else if (binary[i] == '0'){
            result = (result << 1) | 0;
        }
        else if(binary[i] == 'b'){
            continue;
        }
        else{
            printf("Invalid binary number: %d", binary[i]);
            return -1;
        }
    }
    return result;
}

void decimal_to_binary(long number){

    int mask = 0b00000001;
    int binary = 0;
    long double binarySize = log((long double) number) / log((long double) 2);
    for (int i = binarySize; i >= 0 ;i--){
        int temp = number >> i;
        if (temp & mask){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    
    printf("\n");
    
}

