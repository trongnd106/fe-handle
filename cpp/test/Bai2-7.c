#include<stdio.h>

int main(){
	char stk[100], ht[100], gt[50];
	int ns;
	fgets(stk, sizeof(stk),stdin); 
	fgets(ht, sizeof(ht),stdin); 
	fgets(gt, sizeof(gt),stdin); 
	do {
		scanf("%d", &ns); 
		if (ns <= 1900) printf("Vui long nhap lai: ");
	} while (ns <= 1900);
	// hien thi thong tin
		puts(stk);
		puts(ht);
		puts(gt);
		printf("%d", ns);
		
	int n, dem = 0;
	scanf("%d", &n);
	double giaodich[n];
	double sum = 0;
	
	for(int i = 0; i < n; i++){
		scanf("%lf", &giaodich[i]);    // nhap mang
		sum += giaodich[i];    // tinh tong so tien rut
		if (giaodich[i] > 2.2)
			dem++;     // dem so giao dich > 2.2 trieu
	}
	for(int i = 0; i < n; i++) 
		printf("%.2lf ", giaodich[i]);   //in ra mang
	int sum3 = giaodich[0] + giaodich[1] + giaodich[2];   //tong 3 giao dich dau tien
	
	// sap xep giam dan
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if (giaodich[i] < giaodich[j]){
				double tmp = giaodich[i];
				giaodich[i] = giaodich[j];
				giaodich[j] = tmp;
			}
		}
	}	
	return 0;	
}