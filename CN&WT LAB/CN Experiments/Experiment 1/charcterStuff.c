//program for Character-stuffing

#include <stdio.h>
#include <string.h>

int main() {
	int n, i, count = 0, j = 0;
	char charStuff[50], Stuff[50];
	
	printf("Enter number of frames: ");
	scanf("%d", &n);
	
	printf("Enter charcater data: ");
	scanf("%s", charStuff);
	
	printf("AT SENDER\n");
	printf("Before Charcter-Stuffing: %s", charStuff);
	printf("\n");
	
	printf("AT RECEIVER\n");
	printf("After Character-Stuffing: DLESTX");
	for(i = 0; i < strlen(charStuff); i++) {
		if(charStuff[i] == 'D' && charStuff[i + 1] == 'L' && charStuff[i + 2] == 'E') {
			printf("DLE");
			j = j + 3;
		}
		printf("%c",charStuff[i]);
		Stuff[j] = charStuff[i];
		j++;
	}
	printf("DLEETX\n");
	
	printf("After De-Stuffing: ");
	for(i = 0; i < j; i++) {
		if(charStuff[i] == 'D' && charStuff[i + 1] == 'L' && charStuff[i + 2] == 'E') {
			i = i + 3;
		}
		
		printf("%c", Stuff[i]);
	}
	printf("\n");
	
	return 0;
}
