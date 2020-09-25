int
remove_trailing_newline(char *s)
{
  while(*s)
    if(*(s++) == '\n')
      *(s-1) = '\0';
  return -1;
}
