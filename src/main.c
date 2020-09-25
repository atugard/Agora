int
get_data(char *s, char *val){
  printf("Enter the books %s: \n", val);
  fgets(s, 25, stdin);
  return 1;
}

int main()
{
  char* s = malloc(sizeof(char) * 25);

  printf("What is the subject?: \n");
  fgets(s, 25, stdin);



  free(name);
  free(author);
  free(year);
  free(publisher);
  free(subject);


}

