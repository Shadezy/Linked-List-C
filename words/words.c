#include "words.h"

/*struct words
{
   char * word;
   int length;
};

typedef struct words Words;*/

void printWord(void * passedIn)
{
   Words * aWord = (Words*)(passedIn);
   printf("%s-%d, ", aWord -> word, aWord -> length);
}

void * buildWord(FILE * fin)
{
   char temp[100];
   
   fgets(temp, 100, fin);
   strip(temp);
   
   Words * aWord = (Words*)calloc(1, sizeof(Words));
   aWord -> word = (char*)calloc(strlen(temp)+1, sizeof(char));
   strcpy(aWord -> word, temp);
   aWord -> length = strlen(temp);
   
   return aWord;
}

void * buildWord_Prompt(FILE * fin)
{
   char temp[100];
   
   printf("Please enter a word: ");
   fgets(temp, 100, fin);
   strip(temp);
   
   Words * aWord = (Words*)calloc(1, sizeof(Words));
   aWord -> word = (char*)calloc(strlen(temp)+1, sizeof(char));
   strcpy(aWord -> word, temp);
   aWord -> length = strlen(temp);
   
   return aWord;
}

int compareTwoWords(const void * p1, const void * p2)
{
   Words * w1 = (Words*)(p1);
   Words * w2 = (Words*)(p2);
   
   return strcmp(w1 -> word, w2 -> word);
}

void cleanWord(void * ptr)
{
   Words * temp = (Words*)(ptr);
   
      free(temp -> word);
      temp -> word = NULL;
      temp -> length = 0;
      free(temp);
}
