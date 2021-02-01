#include <stdio.h>

int main() {
	int bucketSize, rate, p, iter, i, j, total = 0;
	printf("Enter the bucket size and output rate\n");
	scanf("%d %d", &bucketSize, &rate);
	
	printf("\nEnter the number of input lines\n");
	scanf("%d", &p);
	
	int pkt[p];
	printf("Enter the input packet rate of %d lines\n", p);
	for(i = 0; i < p; i++)
		scanf("%d", &pkt[i]);
		
	printf("\nEnter the number of iterations\n");
	scanf("%d", &iter);
	
	for(i = 0; i < iter; i++) {
		printf("\nIteration %d\n", i + 1);
		for(j = 0; j < p; j++) {
			total += pkt[j];
			if(total <= bucketSize) 
				printf("Input from line %d with rate %d is added to the bucket\nCurrent bucket size is %d\n", j + 1, pkt[j], total);
			else {
				total -= pkt[j];
				printf("Input from line %d with rate %d is thrown out bucket\nCurrent bucket size is %d\n", j + 1, pkt[j], total);
			}
		}
		
		if(total <= rate) {
			printf("\nPacket sent to output line at rate %d", rate);
			total = 0;
			printf("\nCurrent bucket size is %d", total);
		} else {
			total = total - rate;
			printf("\nPacket sent to output line at rate %d\nCurrent bucket size is %d\n", rate, total);
		}
	}
	
	return 0;
}
