/*
#include<stdio.h>
#include<conio.h>

int main(){
	int n;
	scanf("%d", &n);	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j < i) printf("  ");
			else printf(" A");
		}
		for (int j = 0; j < n; j++){
			if (j < n-i-1) printf ("  ");
			else printf(" D");
		}
		printf("\n");
	}
    for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j > n-i-1) printf("  ");
			else printf(" B");
		}
		for (int j = 0; j <= i; j++){
			printf(" C");
		}
		printf("\n");
    }
    system("cls");
    return 0;
}
// vẽ hình cánh quạt 
*/


/*
#include<stdio.h>
#include<conio.h>

int main(){
	int n;
	scanf("%d", &n);	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j < i) printf("  ");
			else printf(" A");
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n-i; j++){
			printf(" B");
		}
		printf("\n");
    }
	for (int i = 0; i < n; i++){	
		for (int j = 0; j <= i; j++){
			printf(" C");
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j < n-i-1) printf ("  ");
			else printf(" D");
		}
		printf("\n");
    }
    return 0;
}
*/

// VD tính: S = 1 + X + X^2/2! + X^3/3! + ... + X^n/n! với sai số epsi
#include <stdio.h>

int main(){
	int x; 
	scanf("%d", &x);
	int a = x, k = 2;
	float p = 1, epsi;
	int k = 2;
	scanf("%f", &epsi);
	while (a > epsi){
		p += a;
		a *= x/k++;
	}
	printf("%f", p);
	return 0;
}

//VD: Tính S = 
