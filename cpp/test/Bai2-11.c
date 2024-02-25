// quan li nhiet do hang ngay cua 1 tinh
#include<stdio.h>

int main(){
	char tinh[100], huyen[100];
	int nam;
	fgets(tinh, sizeof(tinh),stdin); 
	fgets(huyen, sizeof(huyen),stdin); 
	do {
		scanf("%d", &nam); 
		if (nam <= 2000) printf("Vui long nhap lai: ");
	} while (nam <= 2000);
	// hien thi thong tin
		puts(tinh);
		puts(huyen);
		printf("%d", nam);
		
	int n, dem = 0;
	scanf("%d", &n);
	double Nhietdo[n];
	
	for(int i = 0; i < n; i++){
		scanf("%lf", &Nhietdo[i]);    // nhap mang  
	}
	for(int i = 0; i < n; i++) 
		printf("%.2lf ", Nhietdo[i]);   //in ra mang
				
	double max = Nhietdo[0];
	double min = Nhietdo[0];
	for(int i = 0; i < n; i++){
		if (Nhietdo[i] > max)
			max = Nhietdo[i];
		if (Nhietdo[i] < min)
			min = Nhietdo[i];
	}
	printf("%.2lf  %.2lf", max, min);   //nhiet do cao nhat, nho nhat
	return 0;	
}