// chèn phần tử vào mảng
/*
#include <stdio.h>

int main(){
	int arr[100], position, c, n, value;
	printf("Nhap so phan tu cua mang:\n");
	scanf("%d", &n);
	printf("\nNhap phan tu: \n");
	for (c = 0; c < n; c++){
		scanf("%d", &arr[c]);
	}
	printf("\nMang da nhap: \n");
	for (c = 0; c < n; c++){
		printf("%5d", arr[c]);
    }
    printf("\nNhap vi tri chen phan tu: \n");
    scanf("%d", &position);
    printf("\nNhap gia tri can chen: \n");
    scanf("%d", &value);
    for (c = n - 1; c >= position - 1; c--){
    	arr[c+1] = arr[c];
	}
	arr[position-1] = value;
	printf("\nMang luc sau: \n");
	for (c = 0; c < n+1; c++){
		printf("%5d", arr[c]);
	}
	return 0;   
}
*/


//thao tác tìm kiếm phần tử
/*
#include<stdio.h>

int main(){
	int arr[100], n, find, pos;
	printf("Nhap so phan tu cua mang: \n");
	scanf("%d", &n);
	printf("\nNhap mang: \n");
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("\nMang vua nhap la: \n");
	for (int j = 0; j < n; j++)
	{
		printf("%5d", arr[j]);
	}
	printf("\nNhap gia tri can tim kiem: \n");
	scanf("%d", &find);
	for (int i = 0; i < n; i++)
	{ 
	   if (arr[i] == find)
	   {
	   	   pos = i;
	   	   break;
	   }
	}
	printf("Gia tri can tim nam o vi tri thu %d", pos+1);
	return 0;
}
*/

// cập nhật giá trị của phần tử:
/*
#include<stdio.h>

int main(){
	int arr[100], n, update, pos;
	printf("Nhap so phan tu cua mang: \n");
	scanf("%d", &n);
	printf("\nNhap mang: \n");
	for (int i = 0; i < n; i++){
		scanf("%3d", &arr[i]);
	}
	printf("\nMang vua nhap la: \n");
	for (int j = 0; j < n; j++)
	{
		printf("%5d", arr[j]);
	}
	printf("\nVi tri can cap nhat la: \n");
	scanf("%d", &pos);
	printf("\nGia tri can cap nhat la: \n");
	scanf("%d", &update);
	arr[pos-1] = update;
    printf("\nMang luc sau: \n");
	for (int c = 0; c < n; c++){
		printf("%3d", arr[c]);
	}
	return 0; 
}
*/

//kiểm tra cấp số cộng - C++
/*
#include<iostream>
using namespace std;

int main(){
	int n, arr[n];
	int k, flag = 1;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	k = arr[1] - arr[0];
	for (int i = 1; i < n; i++){
		if (arr[i] != (arr[i-1]+1)){
			flag = 0;
			break;
		}
	}
	if (flag == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
*/
// viết dấu như này hả
/*
#include<stdio.h>

int X(int n);
int Y(int n);
int X(int n){
	if (n==1) return 1;
    else return X(n-1)+Y(n-1);
}
int Y(int n){
	if (n==1) return 1;
	else return X(n-1)*Y(n-1);
}
void inkq(int n, int x[100]){
	for (int i = 0; i < n-1; i++){
		printf("%d,", x[i]);
	}
	printf("%d", x[n-1]);
	printf("\n");
}
int main(){
	int n, x[100], y[100];
	printf("Nhap n: ");
    scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		x[i-1] = X(i);
		y[i-1] = Y(i);
	}
	inkq(n,x);
	inkq(n,y);
	return 0;
}
*/
/*
#include<stdio.h>

int main(){
	double f,t,k,x,ss,a, dau;
	printf("nhap x = ");    // nhập x
	scanf("%lf", &x);
	printf("nhap ss = ");   // nhập sai số
	scanf("%lf", &ss);
	f=1-3*x;          // f = 1 -3x
	k=1; 
	t=5;
	x=1;              // nhập x ở trên rồi gán x = 1 ?? :(
	a=1;
	dau=1;
	while(ss<t*a*x*x*x/((k+1)*(k+2)*(k+3))) {    
		a=t*a*x*x*x/((k+1)*(k+2)*(k+3));     // sao ở trên lại khởi tạo a = 1 z e;(
		k=k+3;
		t=t+2;
		f=f+a*dau;      //biểu thức f 
		dau=-dau;
	}
	printf("f = %f", f);
	return 0;
}
*/






