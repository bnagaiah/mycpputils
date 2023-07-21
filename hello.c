#include<strings.h>
#include<stdio.h>
#include <stdbool.h>
#include<stdint.h>

  struct ListNode {
      int val;
      struct ListNode *next;
  };

bool isPalindrome(struct ListNode* head){
    struct ListNode* CPTR = head;
    struct ListNode* TPTR = head->next;
    struct ListNode* NPTR = NULL;
    int count=1, midpt=0;
    while(TPTR != NULL) {
        count++;
        CPTR = TPTR;
        TPTR = CPTR->next;        
    }
    if(count < 3)
        return false;
    midpt = (count/2);


    // easy find ??
    CPTR = head;
    TPTR = head->next;
    int itr = 0;
    while(TPTR != NULL) {
        itr++;
        if (midpt == itr) {
            if(count%2) {
                NPTR = TPTR->next;
                if (NPTR) {
                    if (CPTR->val == NPTR->val)
                    return true;
                }
            }
            else {
                if (CPTR->val == TPTR->val)
                    return true;
            }
        }
        CPTR = TPTR;
        TPTR = CPTR->next;
    }
    
    return false;
}

void printBits();

int main()
{
   int count=5, midpt=0;
   midpt = (count/2) ;
   printf(" midpt = %d\n", midpt);
   printBits();
  return 0;
}
