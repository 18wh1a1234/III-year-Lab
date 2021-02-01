#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct frame {
    int sno;
    char msg[15];
    int flag;

};

int main() {
    int i, j, n, r, k;
    printf("Enter no of frames\n");
    scanf("%d",&n);
    struct frame fr[n];
    int s[n];
    for(i = 0; i < n; i++) {
        s[i] = -1;
        fr[i].sno = -1;
    }

    printf("Enter the message \n");
    for(i = 0; i < n; i++) {
        scanf("%s", fr[i].msg);
        fr[i].sno = i;
    }
    
	for(j = 0; j < n; j++) {
        r = rand() % n;
        if(s[r] == -1) {
            fr[j].flag = r;
            s[r] = 1;
        }
        else if(s[r] == 1) {
            for(k = 0; k < n; k++) {
                r = k;
                if(s[r] == -1) {
            		fr[j].flag = r;
            		s[r] = 1;
            		break;
        		}
            }
        }
    }

    printf("\nAFTER SHUFFLING :");
    printf("\nsno \t msg  \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            if(fr[j].flag == i) {
                printf("%d\t%s", fr[j].sno, fr[j].msg);
                printf("\n");
            }
    }	

    for(i = 0; i < n; i++) {
        for(j = 0; j < n - 1; j++) {
            if(fr[j].sno > fr[j + 1].sno) {
                struct frame temp;
                temp = fr[j];
                fr[j] = fr[j+1];
                fr[j+1] = temp;
            }
        }
    }

    printf("\nAFTER SORTING ARRIVED FRAMES ARE:");
    printf("\nsno \t msg \n");
	for(i = 0; i < n; i++) {
        printf("%d\t%s", fr[i].sno, fr[i].msg);
        printf("\n");
    }
    
	return 0;
}