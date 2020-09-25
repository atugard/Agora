
int
check_subject(char* subject)
{
  char* temp1 = malloc(sizeof(char)*100); 
strcat(temp1, "subjects/");
strcat(temp1, subject);
remove_trailing_newline(temp1);
printf("%s", temp1);

if(stat(temp1, &st) == -1) //if the subject doesn't exist return error code, will change this to something useful later.
    return -1;
 return 1;
}


int
add_subject()
{
}

int
remove_subject()
{
}

int
list_subjects()
{
}

