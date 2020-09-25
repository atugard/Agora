#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//to mkdir in program
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "book.h"

int
get_data(char *s, char *val){
  printf("Enter the books %s: \n", val);
  fgets(s, 25, stdin);
  return 1;
}

book
new_book(char* title, char* author, char* year, char* publisher, char* symbolic_link)
{
  book b = malloc(sizeof(char*) * 5);
  strcp(b.title, title);
  strcp(b.author, author);
  strcp(b.year, year);
  strcp(b.publisher, publisher);
  strcp(b.symbolic_link, symbolic_link);

  return b;
}


int add_book()
{
  const char* title         =         malloc(sizeof(char) * 25);
  const char* author        =         malloc(sizeof(char) * 25);
  const char* year          =         malloc(sizeof(char) * 25);
  const char* publisher     =         malloc(sizeof(char) * 25);
  const char* symbolic_link =         malloc(sizeof(char) * 25);
  const char* final         =         malloc(sizeof(char) * 100);
  const char *temp1         =         malloc(sizeof(char)*  50);
  const char *temp2         =         malloc(sizeof(char)*  50);
  const struct stat st      =         {0};
  book b;

  int i;
  for(i=0;i<4;i++)
    switch(i){
    case 0:
      get_data("title", title);
      strcat(final, title);
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
    case 4:
      get_data("symbolic link", symbolic_link);
      strcat(final, symbolic_link);
      break;
    }
  b = new_book(title, author, year, publisher, symbolic_link);

  free(title);
  free(author);
  free(year);
  free(publisher);
  free(symbolic_link);

  i=0;
  while(final[i+1]){
    if(final[i] == '\n')
      final[i] = '-';
    i++;
  }
  //mkdir books/title/notes/ books/title/exercises/
  //echo final >> ../info

  strcat(temp1, "/books/");
  strcat(temp1, b.title);
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

int
symbolically_link(char* symbolic_link){
}

int
remove_book(char* name, char* author)
{
}

int
list_books()
{
}

