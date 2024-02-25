#include <stdio.h>
#include <unistd.h>

int main(){
	int n;
	scanf("%d", &n);
	while (1){
		for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j < i) printf("  ");
			else printf(" A");
		}
		printf("\n");
	}
	}
	return 0;
	
}