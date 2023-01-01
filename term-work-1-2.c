#include<stdio.h>

struct BOOK{
    char title[30];
    int edn, price;
};

void read(struct BOOK *b, int n);

void display(struct BOOK *b, int n);

void compute(struct BOOK *b, int n);

int main()
{   
        int n;
    printf("Enter number of books: ");
    scanf("%d",&n);         //number of books

    struct BOOK b[n];       //array to store structure values of all books

    read(b,n);    //reads details of n books
    display(b,n); //to print deatails of n books
    compute(b,n); //details of highest priced book

return 0;
}

void read(struct BOOK *b, int n){
        int i;
    printf("Enter details of %d books--\n",n);
    for (i = 0; i < n; i++)
    {
        printf("Book %d details-\n",i+1);
        printf("Title: ");      scanf("%s",b[i].title);
        printf("Edition: ");    scanf("%d",&b[i].edn);
        printf("Price: ");      scanf("%d",&b[i].price);
    }
}

void display(struct BOOK *b, int n){
        int i;
    printf("\n\nDetails of %d books are as follows--\n",n);
    for (i = 0; i < n; i++)
    {
        printf("Book %d details-\n",i+1);
        printf("Title: ");      printf("%s\n",b[i].title);
        printf("Edition: ");    printf("%d\n",b[i].edn);
        printf("Price: ");      printf("%d\n",b[i].price);
    }
}

void compute(struct BOOK *b, int n){
        int i=0, lar;
    lar = i;
    for (i = 0; i < n; i++){
            if (b[lar].price < b[i].price)
            {
                lar = i;
            }            
    }
    printf("\n\nDetails of Book worth highest price is:\n");
    printf("Book %d details-\n",lar+1);
        printf("Title: ");      printf("%s\n",b[lar].title);
        printf("Edition: ");    printf("%d\n",b[lar].edn);
        printf("Price: ");      printf("%d\n",b[lar].price);
}