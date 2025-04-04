// Accept x and y coordinates of two points and write a menu driven program to perform the following operations fill the user selects exits. 
// 1) Distance between two points. 
// 2) Slope of line between the points. 
// 3) Check whether they are lie in the same quadrant. 
// 4) Exit .


#include<stdio.h>
#include<stdbool.h>
#include<math.h>
int main(){
    float x1,x2,y1,y2;
    int ch;
    printf("Enter the co-ordinates of x : ");
    scanf("%f%f",&x1,&x2);
    printf("Enter the value of y : ");
    scanf("%f%f",&y1,&y2);

    bool flag = true;
    float ans;
    do{
        printf("\n0.Exit");
        printf("\n1.Find Distance Between Points");
        printf("\n2.Find Slope of Lines Between Points");
        printf("\n3.Check wheather they are Lives in Same Quadrant");
        printf("\nEnter you choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 0 : flag = false;
                    break;
            case 1 : 
            ans = ((x2 - x1) * (x2 - x1)) /( (y2 - y1) * (y2 - y1));
                    printf("Distance between Points : %f\n" ,(sqrt(ans)));
                    break;
            case 2 : 
                    if((x2 - x1) != 0){
                        float slope = (y2 - y1) / (x2 - x1);
                        printf("\n Slope of the Line : %f\n", slope);
                    }else{
                        printf("\nCan't calculate the slope\n");
                    }
                    break;
            case 3 : 
                    if( x1 > 0 && y1 > 0){
                        printf("\nBoth are in First Quadrant\n");
                    }else if(x1 < 0 && y1 > 0){
                        printf("\nBoth are in Second Quadrant\n");
                    }else if(x1 < 0 && y1 < 0){
                        printf("\nBoth are in Third Quadrant\n");
                    }else if(x1 > 0 && y1 < 0){
                        printf("\nBoth are in Fourth Quadrant\n");
                    }
                    else{
                        printf("\nBoth are at the center\n");
                    }
                    break;
            default : 
                    printf("Enter the valid choice !!!! ");
                    break;
        }
    }while(flag);
}