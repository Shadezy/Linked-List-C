#include "myUtils.h"

int menu()
{
   int num;
   printf("Please choose from the options below:\n(1) Print\n(2) addFirst\n(3) addLast\n(4) Sort\n(5) Delete a word\n(6) Quit\n");
   scanf("%d", &num);
   stripInputBuffer(stdin);
   
   while (num < 1 || num > 6)
   {
      printf("Please enter a valid number:\n");
      scanf("%d", &num);
      stripInputBuffer(stdin);
   }
   
   return num;
}

int countRecords(FILE * fin, int per)
{
   char temp[100];
   int line = 0;
   
   fgets(temp, 100, fin); //Prime read
   
   while(!feof(fin))
   {
      strip(temp);
      line++;
      
      fgets(temp, 100, fin);
   }
   
   line = line / per;
   
   rewind(fin);
   return line;
}