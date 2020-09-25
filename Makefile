  CC = gcc

  CFLAGS  = -g -Wall

  TARGET = agora

  BOOK = ./src/book
  STRING = ./src/string
  SUBJECT = ./src/subject
  MAIN = ./src/main

  all: $(TARGET)

  $(TARGET): $(BOOK).c $(STRING).c $(SUBJECT).c $(MAIN) $(CC) $(CFLAGS) -o $(TARGET) 

  clean: $(RM) $(TARGET)
