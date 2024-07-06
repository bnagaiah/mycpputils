#include<iostream>
#include "list.h"
#include <cstring>
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

void ddisp_list(ListNode_T *pHeadList) {
   int count = 0;
    cout << "in disp_list" << endl;
   while(pHeadList) {
     cout << pHeadList << "->" << pHeadList->data.val << " ,";
     pHeadList = pHeadList->next;
        count++;
        if (count > 100) {
            return;
        }

   }
   cout << endl;
}

void inst_list(ListNode_T **pHead, Datas_T data) {
   ListNode_T *pHeadList = *pHead;
   if(pHeadList) {
	//cout << pHeadList << "->" << pHeadList->data.val << " ,";
	inst_list(&(pHeadList->next), data);
   } else {
	ListNode_T *temp = new ListNode_T;
	cout << "new member " << endl;
	memcpy(&(temp->data), &data, sizeof(Datas_T));
	//memcpy(temp->data, &data, sizeof(Datas_T));
	temp->next = NULL;
	if(pHeadList != NULL) {
	   pHeadList->next = temp;
	}
	*pHead = temp;
   }
}


void disp_list(ListNode_T *pHeadList) {
   if(pHeadList) {
	cout << pHeadList << "->" << pHeadList->data.val << " ,";
	disp_list(pHeadList->next);
   } else {
	cout << endl;
   }
}

void reverse_disp_list(ListNode_T *pHeadList) {
   if(pHeadList) {
	reverse_disp_list(pHeadList->next);
	cout << pHeadList << "->" << pHeadList->data.val << " ,";
   }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
ListNode_T* swapPairs(ListNode_T* head) {
     ListNode_T* TPTR = head;
    ListNode_T* nodeA=NULL;
    ListNode_T* nodeB=NULL;
    ListNode_T* nodeC=NULL;
    ListNode_T* pPTR=NULL;
    int count = 0;
    cout << "in swapPairs" << endl;
    while(TPTR) {
        if(nodeA == NULL) {
            nodeA = TPTR;
            if(nodeB == NULL) {
                if(TPTR->next != NULL) {
                    head = TPTR->next;
		    //cout << head->data.val << endl;
		    //cout << TPTR->data.val << endl;
		}
            }
        }
        else {
            nodeB = TPTR;
	    nodeC = TPTR->next;
            //nodeB->next = nodeA;
            nodeA->next = nodeC;
	    nodeB->next = nodeA;
	    if (pPTR != NULL) {
	    	pPTR->next = nodeB;
	    }
            TPTR = nodeA;
            pPTR = nodeA;
	    //cout << nodeA->data.val << ",A ";
	    //cout << nodeB->data.val << ",B  ";
            nodeA = NULL;
        }
	    //cout << TPTR->data.val << ", ";
	//cout << TPTR->data.val << endl;
	disp_list(head);
        TPTR = TPTR->next;
        count++;
        if (count > 100) {
            return NULL;
        }
    }
    return head;
}



void print_lst() {
  ListNode_T *pList = NULL;
  int arr[] = {1,2,3,4,5,4,3,2,1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i=0;
  while(i < n) {
    Datas_T data;
    data.val = arr[i];
    cout << "plist: " << pList << endl;
    inst_list(&pList, data);
    i++;
  }
  disp_list(pList);

  cout << "print_lst mssg: " << isPalindrome(pList) << endl;
  pList = swapPairs(pList);
  cout << "swapped" << endl;
  disp_list(pList);
  cout << "displayed" << endl;
  ddisp_list(pList);
  reverse_disp_list(pList);
   cout << endl;
}
