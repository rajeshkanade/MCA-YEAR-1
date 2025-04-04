#include<stdio.h>
int main(){
	float doorwidth,doorheight,window_width , window_height , room_height , room_width ;

	printf("Enter Room Width and Height : ");
	scanf("%f%f",&room_width,&room_height);

	printf("Enter door width and height : ");
	scanf("%f%f",&doorwidth ,&doorheight);

	printf("Enter room height and width : ");
	scanf("%f%f",&room_width,&room_height);


	float area_to_paint = 4 * (room_height * room_width) - ((doorwidth * doorheight) + 2 * (window_height * window_width));
	printf("area to be painted : %f\n",area_to_paint);

	float area_to_whiteWashed = room_height * room_width;

	printf("Area to whiteWashed : %f\n", area_to_whiteWashed);
}
