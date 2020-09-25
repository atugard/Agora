#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void
helper(char *inp, char *s){
  printf("Enter the books %s: \n", inp);
  fgets(s, 25, stdin);
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

  free(name);
  free(author);
  free(year);
  free(publisher);
  free(final);
}
