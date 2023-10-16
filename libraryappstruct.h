#include<stdio.h>
struct Book{
	int id;
	char tob[100];
	char Author[100];
	char pub[100];
	int p;
	int flag;
	struct Book *next;
	
};
struct Book *head=NULL;
