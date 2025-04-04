#include<stdio.h>
int main(){
	char c ;
	printf("Enter character : ");
	scanf("%c",&c);
	char prev = c - 1;
	char next = c + 1;
	printf("Previous Character is : %c\n",prev);
	printf("Next character is : %c\n",next);
	return 0;
}
