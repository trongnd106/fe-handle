// quan li thong tin hoc vien
#include<stdio.h>

int main(){
	char ht[100], gt[50];
	int ns;
	fgets(ht, sizeof(ht),stdin); 
	fgets(gt, sizeof(gt),stdin); 
	do {
		scanf("%d", &ns); 
		if (ns > 2010) printf("Vui long nhap lai: ");
	} while (ns > 2010);
	// hien thi thong tin
		puts(ht);
		puts(gt);
		printf("%d", ns);
		
	int n, dem = 0;
	scanf("%d", &n);
	double DiemThi[n];
	double sum = 0;
	
	for(int i = 0; i < n; i++){
		scanf("%lf", &DiemThi[i]);    // nhap mang
		sum += DiemThi[i];    
		if (DiemThi[i] < 5)
			dem++;     // dem so diem duoi 5
	}
	for(int i = 0; i < n; i++) 
		printf("%.2lf ", DiemThi[i]);   //in ra mang
	double dtb = sum/n;
	printf("\n%lf", dtb);	
	return 0;	
}