#include<strings.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>
#include <cstring>

char* largestOddNumber(char* numS) {
    unsigned int numA = 0;
    int odd = 0;
    char *num = numS;
    while(*num != 0) {
        if((*num < 48) || (*num > 57) ) {
            return "";
        }
        int digit = *num - 48;
        if (digit %2) {
            if(odd < digit){
                odd = digit;
            }
        }
        numA = numA *10;
        numA += digit;
        num++;
    }

    if ((numA < 0) || (numA > 1000000)) {
        return "";
    }

    if (numA % 2) {
        return numS;
    } 
    else if (odd) {
	char* arr = (char*) malloc(3);
	arr[0] = odd+48;
	arr[1] = 0;
        return arr;
    }
    else {
        return "";
    }
}

bool match_len(int len, char* s){
    char *base = s;
    int size = strlen(s);
    if(size < len){
        return false;
    }
    printf("len %d, s=%s\n", len, s);
    for(int i=0; i < len;i++) {
        for(int j=i+1; j < len;j++) {
            if(s[i] == s[j]){
                return false;
            }
        }
    }
    return true;
}

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int size = len;
    
    while(len > 1) {
        for(int i=0; i < size;i++) {
            if(match_len(len, &s[i])){
                return len;
            }
        }
        len--;
    }
    return len;
}


void printStr()
{
   uint32_t n = 43261596;
   printf(" largestOddNumber = %s\n", largestOddNumber("52"));
   printf(" largestOddNumber = %s\n", largestOddNumber("4206"));
   printf(" largestOddNumber = %s\n", largestOddNumber("35427"));
   printf(" lengthOfLongestSubstring = %d\n", lengthOfLongestSubstring("abcabcbb"));

}

