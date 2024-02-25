// ghi du lieu vao file 
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
	// 1. tao file
	// 2. mo file
	FILE *fptr;
	fptr = fopen("Bai1.txt", "w");
	if (fptr == NULL) {
		printf ("\nLoi tao hoac mo file");
		exit(1);
	} 
	// 3. doc hoac ghi
	int n;
	printf ("\nNhap vao so n: "); scanf("%d", &n);
	fprintf(fptr, "%d", n);
	// 4. dong file
	fclose(fptr);
	
	return 0;
}
*/

// ghi vao file
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f;
	f = fopen("Bai1.txt", "r");
	if (f == NULL) {
		printf("\n Loi tao hoac mo file");
		exit(1);
	}
	int n;
	fscanf(f, "%d", &n);
	printf ("\nGia tri cua n: %d", n);
	fclose(f);
	return 0;
}
*/


// lam viec voi file nhi phan
/*
để ghi dữ liệu dạng nhị phân có hàm:
   fwrite (addressData, sizeData, numbesrData, poitertoFile);
   vd: fwrite(&num, sizeof(struct of threeNum), 1, ptr);
*/

/*
#include <stdio.h>
#include <stdlib.h>

struct Date {
	int ngay;
	int thang;
	int nam;
} d1;

int main(){
	FILE *f;
	// tao, mo file
	f = fopen("Bai2.bin", "wb");
	if (f == NULL) {
		printf ("\n Loi tao hoac mo file!");
		exit(1);
	}
	// ghi du lieu

	d1.ngay = 10;
	d1.thang = 6;
	d1.nam = 2004;
	
	fwrite(&d1, sizeof (struct Date), 1, f);
	
	fclose(f);
	return 0;
}
*/












