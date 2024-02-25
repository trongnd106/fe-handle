// nhap mang nhau nhien gom n phan tu, tim phan tu lon nhat, nho nhat trong mang
#include <iostream>
#include <cstdlib>   //for srand() va rand()
#include <ctime>     //for time()
#include <iomanip>
using namespace std;
using std::setw;
int main(){
	int n; cin >> n;
	int a[n];
	srand(time(NULL));   //khoi tao so ngau nhien
	for (int i = 0; i < n; i++){
		a[i] = rand();  //chon so ngau nhien
		cout << setw(10) << "Phan tu thu "<< i <<" la: " << setw(7) << a[i] << endl;
	}
	int MAX = a[0];
	int MIN = a[n];
	for (int i = 0; i < n; i++){
		if (a[i] > MAX) 
		MAX = a[i]; }
	for (int j = 0; j < n; j++){
		 if (a[j] < MIN)
	    MIN = a[j];	}
	cout << setw(7) << "Phan tu lon nhat trong mang la: " << MAX << endl;
	cout << setw(7) << "Phan tu nho nhat trong mang la: " << MIN;
	int S = 0;
	for (int m = 0; m < n; m++){
		S = S + a[m]; }
	cout << "\nTong cac phan tu cua mang = " << S;
	return 0;
}