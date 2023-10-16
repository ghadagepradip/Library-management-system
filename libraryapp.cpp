#include"libraryapp.h"

int main()
{
	int ch;
	do{
		printf("\n-----------------------------------------------");	
		printf("\n1:Add Book Information");	
		printf("\n2:View all Books");
		printf("\n3:Search book by name");
		printf("\n4:Delete book by id");
		printf("\n5:Update book info using id");
		printf("\n6:Count book author wise");
		printf("\n7:Count book price wise");
		printf("\n8:Count book publication wise");
		printf("\n9:Arrange authors name as per book count in descending order");
		printf("\n10:Exit");
		printf("\n-----------------------------------------------");		
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:{
						add();
						break;
				   }
			case 2:{
						view();
						break;
				   }
			case 3:{
						char c[100];
						printf("Enter name of book: ");
						scanf("%s",&c);
						sbook(c);
						break;
				   }
			case 4:{
						int temp;
						printf("\nEnter id of book: ");
						scanf("%d",&temp);
						did(temp);
						break;
				   }
			case 5:{
						int temp;
						printf("\nEnter id of book: ");
						scanf("%d",&temp);
						upid(temp);
						break;
				   }
			case 6:{
						cbAuthor();
						break;
				   }
			case 7:{
						cbprice();
						break;
				   }
			case 8:{
						cbpub();
						break;
				   }
			case 9:{
						desc();
						break;
				   }
			case 10:{
						printf("Thank you....");
						break;
				   }
			default: printf("\nEnter correct choice...");
		}	
	  }while(ch!=10);
	  return 0;
}


