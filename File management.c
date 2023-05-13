#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct book
{
char book_serial_number[30];
int isbn;
char bookname[40];
int edition;
char author[30];
char is_reserved[30];
};

void addBook();
void deleteBook();
void searchBook();
void updateBook();
void displayBooks();
void issueBook();

int main()
{

  char choice;
  printf("Welcome to Comsats Library!\n\n");
  while(1)
  {
  printf("Enter the number associated with the desired action\n");
  printf("---------------------------\n");
  printf("1. Add Book               |\n");
  printf("2. Delete Book            |\n");
  printf("3. Search Book            |\n");
  printf("4. Update Book            |\n");
  printf("5. Display all Books      |\n");
  printf("6. Issue Book             |\n");
  printf("7. Exit                   |\n");
  printf("---------------------------\n");
  choice = getche();
  printf("\n");

  if(choice=='1')
    {
    addbook();
    }
  else if(choice=='2')
    {
    deleteBook();
    }
   else if(choice=='3')
    {
    searchBook();
    }
   else if(choice=='4')
    {
    updateBook();
    }
   else if(choice=='5')
    {
    displayBooks();
    }
   else if(choice=='6')
    {
    issueBook();
    }
   else if(choice=='7')
    {
    printf("You have exited this program!\n");
    break;
    }
   else
    {
    printf("You pressed a wrong number!");
    }
   getche();
   system("cls");
  }

}




 addbook()
{
    struct book b;
    char choice = 'y';

    FILE *fp;
    fp=fopen("E:\Lib.txt","a");
    while(choice=='y')
        {
    printf("Enter book serial number: ");
    scanf("%s",b.book_serial_number);
    printf("Enter ISBN number: ");
    scanf("%d",&b.isbn);
    printf("Enter name of book: ");
    scanf("%s",b.bookname);
    printf("Enter edition of book: ");
    scanf("%d",&b.edition);
    printf("Enter author name: ");
    scanf("%s",b.author);
    strcpy(b.is_reserved,"None");

    fprintf(fp,"%s %d %s %d %s %s\n",b.book_serial_number,b.isbn,b.bookname,b.edition,b.author,b.is_reserved);
    printf("Book has been successfully added!\n\n");
    printf("Do u want to add another record?(y/n): ");
    //fflush(stdin);
    choice=getche();
    printf("\n\n");
    }
    fclose(fp);
}





searchBook()
{
    struct book b[100];
    int i=0;
    FILE *fp;
    fp=fopen("Lib.txt","r");
    while(fscanf(fp,"%s %d %s %d %s %s",b[i].book_serial_number,&b[i].isbn,b[i].bookname,&b[i].edition,b[i].author,b[i].is_reserved)!=EOF)
    {
        i++;
    }
    fclose(fp);

    int choice;
    int found=0;
    printf("Enter the corresponding action you want to search a book by: \n");
    printf("1. By ISBN Number\n");
    printf("2. By Book Name\n");
    printf("3. By Author Name\n");
    scanf("%d",&choice);
    int isbn;
    char bookname[40],author[40];
    if(choice==1)
        {
        printf("Enter The ISBN of the book: ");
        scanf("%d",&isbn);
        for(int x=0;x<i;x++)
            {
            if(isbn==b[x].isbn)
                {
                printf("Book Found!\n\n");
                printf("Book Serial Number: %s\n",b[x].book_serial_number);
                printf("Book ISBN: %d\n",b[x].isbn);
                printf("Book Title: %s\n",b[x].bookname);
                printf("Book Edition: %d\n",b[x].edition);
                printf("Author: %s\n",b[x].author);
                printf("Reserved by: %s\n",b[x].is_reserved);
                found=1;
                }
            }
            if(found==0)
                {
                printf("Book not found!!");
                }
        }


    else if(choice==2)
        {
        printf("Enter The Name of Book: ");
        scanf("%s",bookname);
        for(int x=0;x<i;x++)
            {
            if(strcmp(bookname,b[x].bookname)==0)
                {
                printf("Book Found!\n\n");
                printf("Book Title: %s\n",b[x].bookname);
                printf("Author: %s\n",b[x].author);
                printf("Book Serial Number: %s\n",b[x].book_serial_number);
                printf("Book ISBN: %d\n",b[x].isbn);
                printf("Book Edition: %d\n",b[x].edition);
                printf("Reserved by: %s\n",b[x].is_reserved);
                found=1;
                }
            }
            if(found==0)
                {
                printf("Book not found!!");
                }

        }
    else if(choice==3)
        {
        printf("Enter the Author Name: ");
        scanf("%s",author);
        for(int x=0;x<i;x++)
            {
            if(strcmp(author,b[x].author)==0)
                {
                printf("Book Found!\n\n");
                printf("Book Title: %s\n",b[x].bookname);
                printf("Author: %s\n",b[x].author);
                printf("Book Serial Number: %s\n",b[x].book_serial_number);
                printf("Book ISBN: %d\n",b[x].isbn);
                printf("Book Edition: %d\n",b[x].edition);
                printf("Reserved by: %s\n",b[x].is_reserved);
                found=1;
                }
            }
            if(found==0)
                {
                printf("Book not found!!");
                }

        }
    else
        {
        printf("Book does not exist");

        }

}




deleteBook()
{
    struct book b[100];
    int i=0;
    FILE *fp;
    fp=fopen("Lib.txt","r");
    while(fscanf(fp,"%s %d %s %d %s %s",b[i].book_serial_number,&b[i].isbn,b[i].bookname,&b[i].edition,b[i].author,b[i].is_reserved)!=EOF)
    {
        i++;
    }
    fclose(fp);

    fp=fopen("Lib.txt","w");

    int isbn,found=0;
    printf("Enter ISBN Number of the book u want to delete: ");
    scanf("%d",&isbn);
    for(int x=0;x<i;x++)
        {
          if(isbn==b[x].isbn)
            {
            found=1;
            printf("Book with ISBN %d is deleted successfully!",isbn);
            continue;
            }
            fprintf(fp,"%s %d %s %d %s %s\n",b[x].book_serial_number,b[x].isbn,b[x].bookname,b[x].edition,b[x].author,b[x].is_reserved);
        }
        if(found==0)
            {
            printf("Book not found!");
            }
    fclose(fp);


}



displayBooks()
{
struct book b[100];
    int i=0,a=1;
    FILE *fp;
    fp=fopen("Lib.txt","r");
    while(fscanf(fp,"%s %d %s %d %s %s",b[i].book_serial_number,&b[i].isbn,b[i].bookname,&b[i].edition,b[i].author,b[i].is_reserved)!=EOF)
    {
        i++;
    }
   fclose(fp);

   if(i==0)
    {
    printf("No Books to be Displayed!\n");
    }
   for(int x=0;x<i;x++)
   {
        printf("Book%d:\n",a);
        a++;
        printf("Book Title: %s\n",b[x].bookname);
        printf("Author: %s\n",b[x].author);
        printf("Book Serial Number: %s\n",b[x].book_serial_number);
        printf("Book ISBN: %d\n",b[x].isbn);
        printf("Book Edition: %d\n",b[x].edition);
        printf("Reserved by: %s\n",b[x].is_reserved);

   }
}



updateBook()
{
 struct book b[100];
    int i=0,a=1;
    FILE *fp;
    fp=fopen("Lib.txt","r");
    while(fscanf(fp,"%s %d %s %d %s %s",b[i].book_serial_number,&b[i].isbn,b[i].bookname,&b[i].edition,b[i].author,b[i].is_reserved)!=EOF)
    {
        i++;
    }
   fclose(fp);

   fp=fopen("Lib.txt","w");

   int isbn,found=0;
   printf("Enter the ISBN of the Book u want to update: ");
   scanf("%d",&isbn);
   for(int x=0;x<i;x++)
   {
    if(isbn==b[x].isbn)
    {
    printf("Previous information of this entry: \n");
    printf("Book ISBN: %d\n",b[x].isbn);
    printf("Book Title: %s\n",b[x].bookname);
    printf("Book Serial Number: %s\n",b[x].book_serial_number);
    printf("Book Author Name: %s\n",b[x].author);
    printf("Book Edition: %d\n",b[x].edition);
    printf("Book Reservation: %s\n\n",b[x].is_reserved);

    printf("New information of this entry: \n");
    printf("Enter book serial number: ");
    scanf("%s",b[x].book_serial_number);
    printf("Enter ISBN number: ");
    scanf("%d",&b[x].isbn);
    printf("Enter name of book: ");
    scanf("%s",b[x].bookname);
    printf("Enter edition of book: ");
    scanf("%d",&b[x].edition);
    printf("Enter author name: ");
    scanf("%s",b[x].author);
    strcpy(b[x].is_reserved,"None");
    printf("Book has been successfully updated!\n");
    found=1;
    }
    fprintf(fp,"%s %d %s %d %s %s\n",b[x].book_serial_number,b[x].isbn,b[x].bookname,b[x].edition,b[x].author,b[x].is_reserved);
   }
   if(found==0)
    {
    printf("Book not found!");
    }
   fclose(fp);
}






issueBook()
{
 struct book b[100];
    int i=0,a=1;
    FILE *fp;
    fp=fopen("Lib.txt","r");
    while(fscanf(fp,"%s %d %s %d %s %s",b[i].book_serial_number,&b[i].isbn,b[i].bookname,&b[i].edition,b[i].author,b[i].is_reserved)!=EOF)
    {
        i++;
    }
   fclose(fp);

   fp=fopen("Lib.txt","w");

   int isbn,found=0;
   printf("Enter the ISBN of the book u want to issue: ");
   scanf("%d",&isbn);
   for(int x=0;x<i;x++)
    {
    if(isbn==b[x].isbn&&strcmp(b[x].is_reserved,"None")==0)
    {
        printf("Book Found!\n");
        printf("Enter the name of the person u want to issue this book to: ");
        scanf("%s",b[x].is_reserved);
        found=1;
        printf("Book issued successfully to %s\n",b[x].is_reserved);
    }
    if(isbn==b[x].isbn&&strcmp(b[x].is_reserved,"None")!=0)
        {
        printf("This book has already been issued to %s",b[x].is_reserved);
        found=1;
        }

    fprintf(fp,"%s %d %s %d %s %s\n",b[x].book_serial_number,b[x].isbn,b[x].bookname,b[x].edition,b[x].author,b[x].is_reserved);
    }
    if(found==0)
        {
        printf("Book not found!");
        }
    fclose(fp);
}
