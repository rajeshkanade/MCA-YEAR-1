// Write a program to manage infomation about book in a library. 



#include<stdio.h>
#include<stdbool.h>
typedef struct Book {
    char title[20] , author[20];
    float price;
    bool avail;
}Book;


void getBooks(Book b1[]){
    for(int i = 0 ; i < 5 ; i++){
        printf("\nEnter the details for book %d",i+1);
        printf("\nEnter the title : ");
        scanf("%s",b1[i].title);
        printf("\nEnter the author : ");
        scanf("%s",b1[i].author);
        printf("\nEnter the price : ");
        scanf("%f",&b1[i].price);
        printf("\nEnter Available (1 -> Available , 0 -> Not) : ");
        scanf("%d",&b1[i].avail);
    }
}

void dispBook(Book b1[]){
    for(int i = 0 ; i < 5 ; i++){
        printf("\n%s\t%s\t%2.f\t",b1[i].title,b1[i].author, b1[i].price);
        if(b1[i].avail == true){
            printf("YES");
        }else{
            printf("NO");
        }
        printf("\n");
    }
}
int main(){
    Book b1[5];
    getBooks(b1);
    printf("\nTitle\tAuthor\tPrice,\tAvailable");
    printf("\n-----------------------------------------------------");
    dispBook(b1);
    return 0;
}