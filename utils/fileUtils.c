#include "fileUtils.h"

FILE * openInputFile()
{
   FILE * fin = NULL;
   char name[100];
   //char * name = (char*) calloc(100, sizeof(char));
   
   printf("Enter name of file: ");
   fgets(name, 100, stdin);
   strip(name);
   
   do
   {
      fin = fopen(name, "r");   
   } while (fin == NULL);
   
   //cleanUp(name);
   //name = NULL;
   return fin;
}

FILE * openOutputFile()
{
   FILE * fout = NULL;
   char fn[100];
   //char * fn = (char*) calloc(100, sizeof(char));
   
   printf("Enter output file name: ");
   fgets(fn, 100, stdin);
   strip(fn);
   fout = fopen(fn, "w");
   
   if (fout == NULL)
   {
      perror("error");
      exit(-1);
   }
   
   //free(fn);
   //fn = NULL;
   return fout;
}
FILE * openOutputFileArgs(char * fn)
{
   int x;
   FILE * fout = NULL;
   
   fout = fopen(fn, "w");
   
   if (fout == NULL)
   {
      perror("error");
      exit(-1);
   }
   
   //free(fn);
   //fn = NULL;
   
   return fout;
}