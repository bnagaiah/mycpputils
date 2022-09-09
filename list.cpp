#include<iostream>
#include "list.h"
using namespace std;

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
                    if (CPTR->data.val == NPTR->data.val)
                    return true;
                }
            }
            else {
                if (CPTR->data.val == TPTR->data.val)
                    return true;
            }
        }
        CPTR = TPTR;
        TPTR = CPTR->next;
    }
    
    return false;
}

void ins_list(ListNode_T **pHead, Datas_T data) {
   ListNode_T *temp = new ListNode_T;
   ListNode_T *pHeadList = *pHead;
   temp->data = data;
   temp->next = NULL;
   if(pHeadList == NULL)
	*pHead = temp;
   else {
	while(pHeadList->next != NULL)
	   pHeadList = pHeadList->next;
	pHeadList->next = temp;
	//cout << "insert" << data.val << endl;
   }
}

void disp_list(ListNode_T *pHeadList) {
   while(pHeadList) {
     cout << pHeadList->data.val << " ,";
     pHeadList = pHeadList->next;
   }
   cout << endl;
}

void print_lst() {
  ListNode_T *pList = NULL;
  int arr[] = {1,2,3,4,5,4,3,2,1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i=0;
  while(i < n) {
    Datas_T data;
    data.val = arr[i];
    ins_list(&pList, data);
    i++;
  }
  disp_list(pList);

  cout << "print_lst mssg: " << isPalindrome(pList) << endl;
}
