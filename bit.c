#include<strings.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>

void printB(uint32_t n) {
    int a[sizeof(uint32_t)], i;

    // Loop to calculate and store the binary format
    for (i = 0; i < sizeof(n) ; i++) {
        a[i] = n % 2;
        n = n / 2;
    }

    printf("\nBinary Format:");

    // Loop to print the binary format of given number
    for (i = i - 1; i >= 0; i--) 
    {
        printf("%d", a[i]);
    }
}



int* countBits(int n, int* returnSize){
    int *pRet=NULL;
    *returnSize = n+1;
    pRet = (int*) malloc(sizeof(pRet)*(n+1));
    //returnSize[0] = 0;
    for(int i=0; i < (n+1); i++) {
        int cnt = 0;
	int b = i;
	while(b) {
            uint32_t bmap=1;
	    bmap = b % 2;
            if(bmap) {
                cnt++;
            }
	    b = b/2;
	}
        pRet[i] = cnt;
	//printf("%d,", returnSize[i]);
    }
    //printf(" - %p\n", returnSize);
    return pRet;
}


/*
2220. Minimum Bit Flips to Convert Number
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

Example 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
*/
int minBitFlips(int start, int goal){
    int i=0;
    uint32_t bmap=1;
    for(int j=0; j<32; j++) {
        if((start & bmap)^(goal & bmap)) {
            i++;
	    printf("%d,",j);
        }
	else {
	    //printf("\n bmap %d, %x %x -",j,(start & bmap), (goal & bmap));
	}
	bmap = bmap << 1;
    }
    return i;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t bitr,bit_r = 0;
    printf("%d\n", n);
    for (int i=31; i>=0;i--) {
	bitr = n % 2;
	n = n / 2;
	printf("%d",bitr);
	bit_r |= bitr << i;
    }
    printf("\n%d\n", bit_r);
    return bit_r;
}

bool hasAlternatingBits(int n){
    if (n < 2)
        return false;
    int prev_bmap = n % 2;
    n = n/2;
    while(n) {
        int bmap = n % 2;
        if (prev_bmap == bmap) {
            return false;
        }
	prev_bmap = bmap;
        n = n/2;
    }
    return true;
}

int count1s(int num) {
    int cnt = 0;
    int b = num;
    while(b) {
        uint32_t bmap=1;
        bmap = b % 2;
        if(bmap) {
            cnt++;
        }
        b = b/2;
    }
    printf("num %d, cnt %d\n", num, cnt);
    return cnt;
}

void printArray(int* arr, int arrSize) {
   printf("printArray\n");
   for(int j=0; j < arrSize; j++) {
        printf(" %d,", arr[j]);
   }

}

int bubbleSortArr(int* arr, int arrSize, int* ptr){
    int pos;
    // copy
    for(int i=0; i < arrSize; i++) {
        ptr[i] = arr[i];
    }
    // sort ptr array
    for(pos=0; pos < arrSize; pos++) {
        for(int j=pos; j < arrSize; j++) {
            // swap position with small numbers
            if (ptr[j] < ptr[pos])  {
                int temp = ptr[pos];
                ptr[pos] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    printArray(ptr,arrSize);
    // sort by num of 1s
    int prev=ptr[0], shifted=0, cnt, next_cnt;
    for(pos=0; pos < arrSize; pos++) {
	if(shifted != 0) {
            //ptr[pos]=prev;
	}
	shifted = 0;
	printf("\n");
	cnt = count1s(ptr[pos]);
        for(int j=pos+1; j < arrSize; j++) {
            // if count matches, shift array
	    next_cnt = count1s(ptr[j]);
            if (next_cnt <= cnt)
	    {
		int k=j;
		//if ((j != (pos+1)) || (next_cnt < cnt))
		if (j != (pos+1)) 
		{
		    printf("j %d pos %d %d,", j, pos, ptr[j]);
		    shifted = 1;
                    // shift
                    for(k=j; k > pos+1;k--) {
                    	prev = ptr[k];
                        ptr[k] = ptr[k-1];
		        ptr[k-1]=prev;
		        //printf("ptr[k] %d,", ptr[k]);
                    }
		 printArray(ptr,arrSize);
		}
		else {
		    for(k=j; k > pos;k--) {
                        prev = ptr[k];
                        ptr[k] = ptr[k-1];
                        ptr[k-1]=prev;
                        //printf("ptr[k] %d,", ptr[k]);
                    }
		}
		break;
            }
        }
    }
    if(shifted != 0) {
	ptr[pos-1]=prev;
    }

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){
    int *ptr=NULL;
    ptr = calloc(arrSize, sizeof(int));
    if(ptr == NULL) {
        returnSize = 0;
        return NULL;
    }
    *returnSize = arrSize;
    bubbleSortArr(arr, arrSize, ptr);
    return ptr;
}

void printBits()
{
   uint32_t n = 43261596;
   printf(" reverseBits = %d\n", reverseBits( n));
   printf(" minBitFlips = %d\n", minBitFlips(100,7));
   int *pcountBits = NULL;
   int Size=0;
   n = 25;
   pcountBits = countBits(n,&Size);
   printf(" countBits = %p, %d\n", pcountBits, Size);
   for (int i=0; i < (n+1); i++) {
	printf("%d,",pcountBits[i]);
   }
   printf("\n");
   free(pcountBits);
   printf(" hasAlternatingBits = %d\n", hasAlternatingBits(5));

   int arr[] = {0,1,2,3,9,5,6,7,8};
  // int arr[] = {1024,512,256,128,64,32,16,8,3,3,5,4,2,1};
   //int arr[] = {10,100,1000,10000};
   int len = sizeof(arr) / sizeof(arr[0]);
   int returnSize = 0;
   printf("sortByBits\n");
   int* ptr = sortByBits(arr, len, &returnSize);
   for(int j=0; j < len; j++) {
	printf(" %d,", ptr[j]);
   }
   free(ptr);
}

