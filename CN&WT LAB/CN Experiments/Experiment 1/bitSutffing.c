//program for Bit-Stuffing

#include <stdio.h>

int main() {
	int n;
	printf("Enter number of frames: ");
	scanf("%d", &n);
	
	int data[20], stuff[20], i, j= 0;
	printf("Enter data bits: ");
	for(i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	
	int count = 0;
	
	for(i = 0; i < n; i++) {
		if(data[i] == 1) {
			count++;
		} else {
			count = 0;
		}
		
		stuff[j] = data[i];
		j++;
		if(count == 5) {
			stuff[j] = 0;
			j++;
			count = 0;
		}
 	}
 	
 	printf("AT SENDER\n");
 	printf("After Bit stuffing : 01111110");
 	for(i = 0; i < j; i++) {
 		printf("%d", stuff[i]);
	 }
	 printf("01111110\n");
	 
	 printf("AT RECEVIER\n");
	 printf("Data received is: 01111110");
	 for(i = 0; i < j; i++) {
	 	printf("%d", stuff[i]);
	 }
	 printf("01111110\n");
	 
	 printf("Data after de-stuffing: 01111110");
	 
	 count = 0;
	 for(i = 0; i < j; i++) {
	 	if(stuff[i] == 1) {
	 		count++;
	 	} else {
	 		 count = 0;
		}
		printf("%d", stuff[i]);
		
		if(count == 5) {
			i++;
		}
	 }	 
	 printf("01111110\n");
	 
	
	return 0;
}
