// diem thi hoc vien
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
		
	int n, dem = 0;
	scanf("%d", &n);
	double DiemThi[n];
	double sum = 0;
	
	for(int i = 0; i < n; i++){
		scanf("%lf", &DiemThi[i]);    // nhap mang
		sum += DiemThi[i];    
	}
	double dtb = sum/n; printf("\n%lf\n", dtb);   //diem trung binh

	for(int i = 0; i < n; i++) 
		printf("%.2lf ", DiemThi[i]);   //in ra mang
				
	double max = DiemThi[0];
	double min = DiemThi[0];
	for(int i = 0; i < n; i++){
		if (DiemThi[i] > max)
			max = DiemThi[i];
		if (DiemThi[i] < min)
			min = DiemThi[i];
	}
	printf("%.2lf  %.2lf", max, min);   //hien thi diem cao nhat, nho nhat
	
	// sap xep tang dan
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if (DiemThi[i] > DiemThi[j]){
				double tmp = DiemThi[i];
				DiemThi[i] = DiemThi[j];
				DiemThi[j] = tmp;
			}
		}
	}	
	return 0;	
}