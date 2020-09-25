#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//to mkdir in program
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int
helper(char *val, char *s){
  printf("Enter the books %s: \n", val);
  fgets(s, 25, stdin);
  return 1;
}
int
remove_trailing_newline(char *s)
{
  while(*s)
    if(*(s++) == '\n')
      *(s-1) = '\0';
  return -1;
}

int main()
{
  char* name      = malloc(sizeof(char) * 25);
  char* author    = malloc(sizeof(char) * 25);
  char* year      = malloc(sizeof(char) * 25);
  char* publisher = malloc(sizeof(char) * 25);
  char* final     = malloc(sizeof(char) * 100);
  int i;

  for(i=0;i<4;i++)
    switch(i){
    case 0:
      helper("name", name);
      strcat(final, name);
      break;
    case 1:
      helper("author", author);
      strcat(final, author);
      break;
    case 2:
      helper("year of publication", year);
      strcat(final, year);
      break;
    case 3:
      helper("publisher", publisher);
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
  struct stat st = {0};
  char *temp1 = malloc(sizeof(name) + (sizeof(char) * 19));
  char *temp2 = malloc(sizeof(name) + (sizeof(char) * 19));
  strcat(temp1, "../books/");
  strcat(temp1, name);
  remove_trailing_newline(temp1);
  
  if(stat(temp1, &st) == -1){
    printf("temp1: %s", temp1);
    mkdir(temp1, 0700);
    strcpy(temp2 , temp1);
    strcat(temp1, "/notes");
    strcat(temp2,"/exercises");
    printf("temp1: %s \n", temp1);
    printf("temp2: %s \n", temp2);
    mkdir(temp1, 0700);
    mkdir(temp2, 0700);
  }

  free(name);
  free(author);
  free(year);
  free(publisher);
  free(final);
  free(temp2);
  free(temp1);
}
