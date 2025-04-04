#include<stdio.h>
#include<string.h>
void SearchCity(char cities[5][50], int totalCities){
    char city[50];
    printf("Enter the city to be search : ");
    scanf("%s",city);
    int found = 0;
    for(int i = 0 ; i < totalCities ; i++ ){
        
        if(strcmp(cities[i],city) == 0){
            found = 1;
            break;
        }
        if(found){
            printf("\n%s city is found ..!",city);
        }else{
            printf("\n%s city is not found ..!",city);

        }
    }
}
void DipslayLongestString(char cities[5][50], int totalCities){
    char firstCity[50] = cities[50];
   for(int i = 1 ; i < totalCities - 1 ; i++){
    if(strcmp(firstCity,cities[i+1]) > 1){
        
    }else{
        firstCity = cities[i+1]
    }
   }
}
int main(){
    printf("Enter the number of cities to enter : ");
    int n;
    scanf("%d",&n);
    char cities[n][50];
    printf("Enter Names of the cities : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%s",&cities[i]);
    }

    do{
        printf("\n0. Exit");
        printf("\n1. Search for a city.");
        printf("\n1. Dipslay the longest String");
        printf("\n1. Sort the names");
        printf("\nEnter Your choice : ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1: SearchCity(cities,n);
            break;
            case 2: DipslayLongestString(cities,n);
            break;
            case 3 : sortCitiesNames(cities);
            break;
        }
    }while(n != 0);
    return 0;
}