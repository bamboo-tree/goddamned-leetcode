#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


void printLinkedList(struct ListNode *head);
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);


int main() {

    struct ListNode *first1  = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third1  = (struct ListNode *)malloc(sizeof(struct ListNode));

    struct ListNode *first2  = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third2  = (struct ListNode *)malloc(sizeof(struct ListNode));

    first1->val = 9;
    first1->next = second1;
    second1->val = 9;
    second1->next = third1;
    third1->val = 9;
    third1->next = NULL;

    first2->val = 1;
    first2->next = second2;
    second2->val = 1;
    second2->next = third2;
    third2->val = 1;
    third2->next = NULL;
  
    struct ListNode *sum = (struct ListNode *)malloc(sizeof(struct ListNode));
    sum = addTwoNumbers(first1, first2);
    printLinkedList(sum);

    return 0;
}

void printLinkedList(struct ListNode *head) {
   
    if(head == NULL) {
        printf("head node is NULL, exiting\n");
        return;
    }
    
    printf("Linked list:\n");
    struct ListNode *current = head;
    while(current != NULL) {
        printf("value = %d, next = %p\n", current->val, current->next);
        current = current->next;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    
    struct ListNode *sumHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    sumHead = NULL;

    int carry = 0;
    struct ListNode *currentL1 = l1;
    struct ListNode *currentL2 = l2;
    
    while(currentL1 != NULL || currentL2 != NULL || carry != 0) {
        /*
        printf("L1 ");
        printLinkedList(currentL1);
        printf("L2 ");
        printLinkedList(currentL2);
        */
        
        // calculate sum
        int sum = carry;
        if(currentL1 != NULL) {
            sum += currentL1->val;
            currentL1 = currentL1->next;
        }
        if(currentL2 != NULL) {
            sum += currentL2->val;
            currentL2 = currentL2->next;
        }
       
        // initialize new empty node
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum%10;
        node->next = NULL;
       
        // append linked list
        if(sumHead == NULL) {
            sumHead = node;
        }
        else {
            struct ListNode *last = sumHead;
            while(last->next != NULL) {
                last = last->next;
            }
            last->next = node;
        }

        // update carry value
        carry = sum / 10;
    }
   
    return sumHead;
}
