#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//to mkdir in program
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int add_book()
{
  const char* name =      malloc(sizeof(char) * 25);
  const char* author =    malloc(sizeof(char) * 25);
  const char* year =      malloc(sizeof(char) * 25);
  const char* publisher = malloc(sizeof(char) * 25);
  const char* final     = malloc(sizeof(char) * 100);
  const char *temp1     = malloc(sizeof(char)*  50);
  const char *temp2     = malloc(sizeof(char)*  50);
  const struct stat st  = {0};

  int i;

  
  for(i=0;i<4;i++)
    switch(i){
    case 0:
      get_data("name", name);
      strcat(final, name);
      break;
    case 1:
      get_data("author", author);
      strcat(final, author);
      break;
    case 2:
      get_data("year of publication", year);
      strcat(final, year);
      break;
    case 3:
      get_data("publisher", publisher);
      strcat(final, publisher);
      break;
    }

  i=0;
  while(final[i+1]){
    if(final[i] == '\n')
      final[i] = '-';
    i++;
  }
  //mkdir books/name/notes/ books/name/exercises/
  //echo final >> ../info

  strcat(temp1, "/books/");
  strcat(temp1, name);
  remove_trailing_newline(temp1);
  
  if(stat(temp1, &st) == -1){
    mkdir(temp1, 0700);
    strcpy(temp2 , temp1);
    strcat(temp1, "/notes/");
    strcat(temp2,"/exercises/");
    mkdir(temp1, 0700);
    mkdir(temp2, 0700);
  }

  free(final);
  free(temp2);
  free(temp1);

}

int remove_book()
{
}

int list_books()
{
}

