// diem thi ban dan
#include<stdio.h>

int main(){
	char ht[100], gt[50];
	int ns;
	fgets(ht, sizeof(ht),stdin); 
	fgets(gt, sizeof(gt),stdin); 
	do {
		scanf("%d", &ns); 
		if (ns <= 1900) printf("Vui long nhap lai: ");
	} while (ns <= 1900);
	// hien thi thong tin
		puts(ht);
		puts(gt);
		printf("%d", ns);
		
	int n,x, dem = 0, sum = 0;
	scanf("%d", &n);
	scanf("%d", &x);
	int KetQua[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d", &KetQua[i]);    // nhap mang
		sum += KetQua[i];    // tinh tong diem
		if (KetQua[i] == 10)
			dem++;     // dem so diem 10
		if (KetQua[i] == x)
			printf("Can bo ban duoc diem %d", x);
	}
	for(int i = 0; i < n; i++) 
		printf("%d ", KetQua[i]);   //in ra mang
	
	// sap xep tang dan
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if (KetQua[i] > KetQua[j]){
				int tmp = KetQua[i];
				KetQua[i] = KetQua[j];
				KetQua[j] = tmp;
			}
		}
	}	
	return 0;	
}