#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"libraryappstruct.h"
//#include"libraryfunc.h"

//Function for adding new book
 void add()
 {
 	
 	if(head==NULL)
 	{
 		head=(struct Book*)malloc(sizeof(Book));
		printf("\nEnter id for book: ");
		scanf("%d",&head->id);	
		printf("\nEnter title of book: ");
		scanf("%s",&head->tob);
		printf("\nEnter Author of book: ");
		scanf("%s",&head->Author);
		printf("\nEnter publication of book: ");
		scanf("%s",&head->pub);
		printf("\nEnter price of book: ");
		scanf("%d",&head->p);
		head->flag=0;
		head->next=NULL;
	}
	else
	{
		int v,flg=1;
		char ch[100];
		struct Book *temp1,*temp2;
		struct Book *temp3=head;
		printf("\nEnter id for book: ");
		scanf("%d",&v);	
		printf("\nEnter Title of book: ");
		scanf("%s",&ch);	
		//logic for checking if id or name is already givien to any book or not
 		while(temp3!=NULL)
 		{
 			if(temp3->id==v || strcmp(temp3->tob,ch)==0)
 			{
 				printf("Id or Name is already present...");
 				flg=0;	//If id or name is already used flag will change
 				break;
			}
			temp3=temp3->next;
 		}	
 	if(flg==1)
	 	{
 		temp1=(struct Book*)malloc(sizeof(Book));
 		temp1->id=v;
		strcpy(temp1->tob,ch);
		printf("\nEnter Author of book: ");
		scanf("%s",&temp1->Author);
		printf("\nEnter publication of book: ");
		scanf("%s",&temp1->pub);
		printf("\nEnter price of book: ");
		scanf("%d",&temp1->p);
		temp1->flag=0;
		temp2=head;
		while(temp2->next!=NULL)
		{
			temp2=temp2->next;
		}
		temp2->next=temp1;
		temp1->next=NULL;
	   }
	}
 }
 
 //Function for printing all books of library
 void view()
 {
 	struct Book *temp1=head;
 	if(head==NULL)
 	{
 		printf("Library is empty...");
 	}
	else{
 		while(temp1!=NULL)
 		{
		printf("\n%4d\t%4s\t%4s\t%4s\t%4d\t%4d",temp1->id,temp1->tob,temp1->Author,temp1->pub,temp1->p,temp1->flag);
		temp1=temp1->next;	 		
		}
	}
 }
 
//Function for searching book by name
void sbook(char c[])
 {
 	int flg=1;
	struct Book *temp1=head;
 	while(temp1!=NULL)
 	{
 		if(strcmp(c,temp1->tob)==0){
 		flg=0;
		printf("\n%d\t%s\t%s\t%s\t%d\t%d",temp1->id,temp1->tob,temp1->Author,temp1->pub,temp1->p,temp1->flag);
		break;
	    }
		temp1=temp1->next;	 		
	}
	if(flg==1)
	printf("Book not found...");
 }
 
//Function for deleting book by using id
 void did(int gid)
 {
 	int flg=1;
 	struct Book *temp1=head;
 	if(head->next==NULL)
 	{
 		if(gid==head->id)
 		{
 			flg=0;
 			printf("\nDeleted book id is: %d",head->id);
 			head=NULL;
 			free(temp1);
 			temp1=NULL;
 		}
	}
	else if(gid==head->id)
	{
		flg=0;
 		printf("\nDeleted book id is: %d",head->id);
 		head=head->next;
 		free(temp1);
 		temp1=NULL;	
	}
	else{
		temp1=head;
		struct Book *temp2=head;
 		while(temp1!=NULL)
 		{
 			if(gid==temp1->id)
 			{
 				flg=0;
 				temp2->next=temp1->next;
 				temp1->next=NULL;
 				printf("\nDeleted book id is: %d",temp1->id);
 				free(temp1);
 				temp1=NULL;
 				break;
			}
				temp2=temp1;
				temp1=temp1->next;
 			}
 	}
 	if(flg==1)
 	printf("\nBook id not found...");
 }
 
 //Function for updating book information by using its id
 void upid(int id2)
 {
 	int flg=1;
 	struct Book *temp1=head;
 	while(temp1!=NULL)
 		{
 			if(id2==temp1->id)
 			{
 				flg=0;
				printf("\nEnter updated title of book: ");
				scanf("%s",&temp1->tob);
				printf("\nEnter Updated Author of book: ");
				scanf("%s",&temp1->Author);
				printf("\nEnter Updated publication of book: ");
				scanf("%s",&temp1->pub);
				printf("\nEnter Updated price of book: ");
				scanf("%d",&temp1->p);
				break;
 			}
 			temp1=temp1->next;
 			
 		}
 	if(flg==1)
 	printf("\nId Not found...");
 }
 
//Function for counting books of each Author
 void cbAuthor()
 {
 	struct Book *temp1=head;
 	while(temp1!=NULL)
 	{
 		struct Book *temp2=head;
 		struct Book *temp4=head;
 		//logic for counting books of author
 		int c=0;
     	while(temp2!=NULL)
 		{
 			if(strcmp(temp1->Author,temp2->Author)==0)
 			{
 				c++;
 			}
 			temp2=temp2->next;
 		}
 		//logic for checking if author is already printed or not
 		if(temp1==head){
 			printf("\n %s has %d books",temp1->Author,c);
		 }
 		else{
 		int flg=1;
 		while(temp4!=temp1)
 		{
 			if(strcmp(temp1->Author,temp4->Author)==0)
 			{
 				flg=0;
 				break;
			 }
 			temp4=temp4->next;
 		}
 		if(flg==1)
 		printf("\n %s has %d books",temp1->Author,c);
 		}
 		temp1=temp1->next;
 	}
 }

//Function for counting books according to their prizes 
void cbprice()
 {
 	struct Book *temp1=head;
 	while(temp1!=NULL)
 	{
 		struct Book *temp2=head;
 		struct Book *temp4=head;
 		//logic for counting same priced books
 		int c=0;
     	while(temp2!=NULL)
 		{
 			if(temp1->p==temp2->p)
 			{
 				c++;
 			}
 			temp2=temp2->next;
 		}
 		//logic for checking if price is already printed or not
 		if(temp1==head){
 			printf("\nBooks with %d are %d",temp1->p,c);
		 }
 		else{
 		int flg=1;
 		while(temp4!=temp1)
 		{
 			if(temp4->p==temp1->p)
 			{
 				flg=0;
 				break;
			 }
 			temp4=temp4->next;
 		}
 		if(flg==1)
 		printf("\nBooks with %d are %d",temp1->p,c);
 		}
 		temp1=temp1->next;
 	}
 }

//Fuction for counting books of all publication
void cbpub()
 {
 	struct Book *temp1=head;
 	while(temp1!=NULL)
 	{
 		struct Book *temp2=head;
 		struct Book *temp4=head;
 		int c=0;
 		//counting of books
     	while(temp2!=NULL)
 		{
 			if(strcmp(temp1->pub,temp2->pub)==0)
 			{
 				c++;
 			}
 			temp2=temp2->next;
 		}
 		//logic for checking if publication already printed or not
 		if(temp1==head){
 			printf("\n %s publication has %d books",temp1->pub,c);
		 }
 		else{
 		int flg=1;
 		while(temp4!=temp1)
 		{
 			if(strcmp(temp4->pub,temp1->pub)==0)
 			{
 				flg=0;
 				break;
			 }
 			temp4=temp4->next;
 		}
 		if(flg==1)
 		printf("\n %s publication has %d books",temp1->pub,c);
 		}
 		temp1=temp1->next;
 	}
 }
 
void desc()
 {
 	struct Book *temp20=head;
 	//Logic for counting total number of books
 	int c=0;
     	while(temp20!=NULL)
 		{
 			c++;
 			temp20=temp20->next;
 		}
 	int bcou[c],aid[c],k1=0,k2=0;
 	struct Book *temp1=head;
 	while(temp1!=NULL)
 	{
 		struct Book *temp2=head;
 		struct Book *temp4=head;
 		//logic for counting books of author
 		int c1=0;
     	while(temp2!=NULL)
 		{
 			if(strcmp(temp1->Author,temp2->Author)==0)
 			{
 				c1++;
 			}
 			temp2=temp2->next;
 		}
 		//logic for checking if author is already added in array or not
 		if(temp1==head){
 			bcou[k1++]=c1;
 			aid[k2++]=temp1->id;
		 }
 		else{
 		int flg=1;
 		while(temp4!=temp1)
 		{
 			if(strcmp(temp1->Author,temp4->Author)==0)
 			{
 				flg=0;
 				break;
			}
 			temp4=temp4->next;
 		}
 		if(flg==1){
 		bcou[k1++]=c1;
 		aid[k2++]=temp1->id;
 		}
 		}
 		temp1=temp1->next;
 	} 	
 	//Logic for sorting count of books pressent in array by using selection sort
 	int mind;
 	for(int m1=0;m1<k1;m1++)
 	{
 		mind=-1;
 		for(int m2=m1+1;m2<k1;m2++)
 		{
 			if(bcou[m1]<bcou[m2])
 			mind=m2;
		}
		if(mind!=-1)
		{
			int tat1=bcou[m1];
			bcou[m1]=bcou[mind];
			bcou[mind]=tat1;
			
			int tat2=aid[m1];
			aid[m1]=aid[mind];
			aid[mind]=tat2;
		}
	}	
	//logic for printing authors according to count of books	
	struct Book *temp11=NULL;	
	for(int l1=0;l1<k1;l1++)
 	{
 		temp11=head;
 		while(temp11!=NULL)
 		{
 			if(temp11->id == aid[l1])
 			{
 				printf("\n %s has %d books",temp11->Author,bcou[l1]);
 				break;
			}
			temp11=temp11->next;
		}
 	}
	
 }
