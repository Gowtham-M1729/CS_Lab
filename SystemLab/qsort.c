#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
   char title[50];
   int pages;
   float price;
}
book;
int compareBook(book b1, book b2){
   if(b1.price < b2.price){
      return 0;
   }
   return 1;
}
main() {
   int i;
   book book_arr[5];
   strcpy(book_arr[0].title, "C Programming");
   book_arr[0].pages = 260;
   book_arr[0].price = 450;
   strcpy(book_arr[1].title, "DBMS Guide");
   book_arr[1].pages = 850;
   book_arr[1].price = 775;
   strcpy(book_arr[2].title, "Learn C++");
   book_arr[2].pages = 350;
   book_arr[2].price = 520;
   strcpy(book_arr[3].title, "Data Structures");
   book_arr[3].pages = 380;
   book_arr[3].price = 430;
   strcpy(book_arr[4].title, "Learn Python");
   book_arr[4].pages = 500;
   book_arr[4].price = 300;
   qsort((void*)book_arr, 5, sizeof(book_arr[0]), compareBook);
   for(i = 0; i<5; i++) {
      printf("%s\t\t%d\t\t%f\n",book_arr[i].title, book_arr[i].pages, book_arr[i].price);
   }
}
