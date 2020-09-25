#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//to mkdir in program
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int
get_data(char *val, char *s){
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
  char* subject   = malloc(sizeof(char) * 25);
  char* name      = malloc(sizeof(char) * 25);
  char* author    = malloc(sizeof(char) * 25);
  char* year      = malloc(sizeof(char) * 25);
  char* publisher = malloc(sizeof(char) * 25);
  char* final     = malloc(sizeof(char) * 100);
  char *temp1 = malloc(sizeof(char)*50);
  char *temp2 = malloc(sizeof(char)*50);
  struct stat st = {0};
  int i;

  printf("What is the subject?: \n");
  fgets(subject, 25, stdin);
  strcat(temp1, "subjects/");
  strcat(temp1, subject);
  remove_trailing_newline(temp1);
  printf("%s", temp1);


  if(stat(temp1, &st) == -1) //if the subject doesn't exist return error code, will change this to something useful later.
    return -1;

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

  free(name);
  free(author);
  free(year);
  free(publisher);
  free(final);
  free(subject);
  free(temp2);
  free(temp1);
}
