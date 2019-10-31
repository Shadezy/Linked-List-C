#include "listUtils.h"

Node * buildNode(FILE * in, void *(*buildData)(FILE * in) )
{
   Node * nn = (Node*)calloc(1, sizeof(Node));
   nn -> data = buildData(in);
   return nn;
}

void sort(LinkedList * theList, int (*compare)(const void *, const void *))
{
   int x, y;
   void * temp = NULL;
   Node * cur = theList -> head;
   
   for (x = 0; x < theList -> size - 1; x++)
   {
      for (y = 0; y < theList -> size - x - 1; y++)
      {
         if (compare(cur -> data, cur -> next -> data) > 0)
         {
            temp = cur -> data;
            cur -> data = cur -> next -> data;
            cur -> next -> data = temp;
         }
         
         cur = cur -> next;
      }
      
      cur = theList -> head;
   }
}

/**
 * Builds the list by calling addLast
 */
void buildList(LinkedList * myList, FILE * fin, int total, void * (*buildData)(FILE * in))
{
   int x;
   rewind(fin);
   
   for (x = 0; x < total; x++)
   {
      addLast(myList, buildNode(fin, *buildData));
   }
}