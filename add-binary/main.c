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
  char *a = "11";
  char *b = "1";

  printf("%s\n", addBinary(a, b));

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
  int size = 1;

  // convert to linked lists
  struct Node *llA = toReversedLinkedList(a);
  struct Node *llB = toReversedLinkedList(b);

  struct Node *sumHead = (struct Node *)malloc(sizeof(struct Node));
  int colSum = llA->value + llB->value;
  sumHead->value = colSum % 2;
  sumHead->next = NULL;

  llA = llA != NULL ? llA->next : NULL;
  llB = llB != NULL ? llB->next : NULL;

  int carry = colSum >= 2 ? 1 : 0;

  struct Node *sumTemp;
  sumTemp = sumHead;

  while (llA != NULL || llB != NULL || carry == 1)
  {
    int aVal = llA != NULL ? llA->value : 0;
    int bVal = llB != NULL ? llB->value : 0;
    colSum = aVal + bVal + carry;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = colSum % 2;
    newNode->next = NULL;

    sumTemp->next = newNode;
    sumTemp = newNode;

    carry = colSum >= 2 ? 1 : 0;

    llA = llA != NULL ? llA->next : NULL;
    llB = llB != NULL ? llB->next : NULL;

    size++;
  }

  char *solution = (char *)malloc(sizeof(char) * size + 1);
  solution[size] = '\0';

  size--;

  while (size >= 0)
  {
    solution[size] = sumHead->value + '0';
    sumHead = sumHead->next;
    size--;
  }

  return solution;
}
