#include "linkedList.h"

/*struct node
{
    void * data;
    struct node * next;
};
typedef struct node Node;


struct linkedlist
{
    Node * head;
    int size;
};
typedef struct linkedlist LinkedList;*/


LinkedList * linkedList()
{
   LinkedList * myList = (LinkedList*)calloc(1, sizeof(LinkedList));
   myList -> size = 0;
   
   return myList;
}

void addLast(LinkedList * theList, Node * nn)
{
   Node * cur = theList -> head;
   
   if (theList -> size == 0)
   {
      addFirst(theList, nn);
   }
   
   else
   {
      while (cur -> next != NULL)
      {
         cur = cur -> next;
      }
      
      nn -> next = cur -> next;
      cur -> next = nn;
      theList -> size = theList -> size + 1;
      
   }
}

void addFirst(LinkedList * theList, Node * nn)
{
   nn -> next = theList -> head;
   theList -> head = nn;
   theList -> size = theList -> size + 1;
}

void removeItem(LinkedList * theList, Node * nn, void (*removeData)(void *), int (*compare)(const void *, const void *))
{
   Node * prev = NULL;
   Node * cur = theList -> head;
   int count = 0;
   
   while (cur != NULL && count == 0)
   {
      if (compare(nn -> data, cur -> data) == 0 && cur == theList -> head)
      {
         removeData(cur -> data);
         theList -> head = cur -> next;
         theList -> size = theList -> size - 1;
         count++;
      }
      else if (compare(nn -> data, cur -> data) == 0)
      {
         removeData(cur -> data);
         prev -> next = cur -> next;
         theList -> size = theList -> size - 1;
         count++;
      }
      if (count == 0)
      {
         prev = cur;
         cur = cur -> next;
      }
   }
   if (count == 0)
   {
      printf("\nData was not found in list\n");
   }
   
   removeData(nn -> data);
   free(nn);
   free(cur);
   cur = NULL;
   nn = NULL;
}

void clearList(LinkedList * theList, void (*removeData)(void *))
{
   if (theList -> size != 0)
   {
      Node * cur = theList -> head;
      Node * temp;
      
      while (cur != NULL)
      {
         temp = cur;
         cur = cur -> next;
         if (temp -> data != NULL)
         {
            removeData(temp -> data);
            free(temp);
         }
      }
   }
   
   theList -> head = NULL;
   theList -> size = 0;
}

void printList(const LinkedList * theList, void (*convertData)(void *))
{
   if (theList -> size == 0)
   {
      printf("Empty List\n");
   }
   else
   {
      Node * cur = theList -> head;
      //printf("\nSize: %d\n\n", theList -> size);
      while ( cur != NULL)
      {
         //printWord(cur -> data);
         convertData(cur -> data);
         cur = cur -> next;
      }
      
      printf("\n");
   }
}