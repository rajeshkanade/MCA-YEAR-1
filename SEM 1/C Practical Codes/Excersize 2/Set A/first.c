#include<stdio.h>
int main(){
    int no,rem=0 ;
    printf("Enter the Number : ");
    scanf("%d",&no);

    // no = 6789
    int reverseNo = 0;
   while(no > 0){
        rem = no%10;
        // rem = 67 % 10 = 7
        no = no / 10;
        // no = 67 / 10 = 6
        reverseNo = reverseNo * 10 + rem;

        // reverseNo = 98 * 10 + 7 = 987      
   }


    while(reverseNo > 0){
    rem = reverseNo % 10;
    reverseNo = reverseNo / 10;
    if(reverseNo <=0){
switch(rem){
        case 1 : printf("ONE");
                    break;
        case 2 : printf("TWO");
                    break;
        case 3 : printf("THREE");
                    break;
        case 4 : printf("FOUR");
                    break;
        case 5 : printf("FIVE");
                    break;
        case 6 : printf("SIX");
                    break;
        case 7 : printf("SEVEN");
                    break;
        case 8 : printf("EIGHT");
                    break;
        case 9 : printf("NINE");
                    break;
        case 0 : printf("TEN");
                    break;
    }
    }
    else{
        switch(rem){
        case 1 : printf("ONE-");
                    break;
        case 2 : printf("TWO-");
                    break;
        case 3 : printf("THREE-");
                    break;
        case 4 : printf("FOUR-");
                    break;
        case 5 : printf("FIVE-");
                    break;
        case 6 : printf("SIX-");
                    break;
        case 7 : printf("SEVEN-");
                    break;
        case 8 : printf("EIGHT-");
                    break;
        case 9 : printf("NINE-");
                    break;
        case 0 : printf("TEN-");
                    break;
    }
    }
    }
    printf("\n");
}