#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
  int value;
  struct Node *next;
};

char *addBinary(char *a, char *b);
struct Node *toReversedLinkedList(char *arr);
void printLinkedList(struct Node *head);

int main()
{
  // input values (binary strings)
  char *a = "1101";
  char *b = "110";

  // convert to linked lists
  struct Node *llA = toReversedLinkedList(a);
  struct Node *llB = toReversedLinkedList(b);

  printLinkedList(llA);
  printLinkedList(llB);

  /**
   * SOLUTION:
   * create linked list head node and calculate its value
   * update input linked lists
   * create sum carry variable (overengineered solution but i like it :D)
   * repeat the process for remaining nodes unless original linked lists and carry value are empty
   */
  struct Node *sumHead = (struct Node *)malloc(sizeof(struct Node));
  sumHead->value = llA->value + llB->value;
  sumHead->next = NULL;

  llA = llA != NULL ? llA->next : NULL;
  llB = llB != NULL ? llB->next : NULL;

  int carry = (sumHead->value + 1) % 2; // if: 1 -> 0, if: 2 -> 1

  struct Node *sumTemp;
  sumTemp = sumHead;

  while (llA != NULL || llB != NULL || carry == 1)
  {
    int aVal = llA != NULL ? llA->value : 0;
    int bVal = llB != NULL ? llB->value : 0;
    int colSum = aVal + bVal + carry;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = colSum % 2;
    newNode->next = NULL;

    sumTemp->next = newNode;
    sumTemp = newNode;

    carry = carry >= 2 ? 1 : 0;

    llA = llA != NULL ? llA->next : NULL;
    llB = llB != NULL ? llB->next : NULL;
  }

  printLinkedList(sumHead);

  return 0;
}

struct Node *toReversedLinkedList(char *arr)
{
  int index = strlen(arr) - 1;

  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  head->value = arr[index] - '0';
  head->next = NULL;

  struct Node *temp;
  temp = head;

  index--;

  while (index >= 0)
  {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = arr[index] - '0';
    newNode->next = NULL;

    temp->next = newNode;
    temp = newNode;

    index--;
  }

  return head;
}

void printLinkedList(struct Node *head)
{
  struct Node *t = head;
  while (t != NULL)
  {
    printf("%d ", t->value);
    t = t->next;
  }
  printf("\n");
}

char *addBinary(char *a, char *b)
{
}
