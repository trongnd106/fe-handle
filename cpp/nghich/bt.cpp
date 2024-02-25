//Bai 1: Tim so lon nhat trong 3 so
/* cach 1:
#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
    int MAX = a;
    if (b > MAX) cout << b;
    else if (c > MAX) cout << c;
    else cout << a;
    return 0;
	}
*/
/* cach 2: de quy
#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
    cout << max(a,max(b,c));
    return 0;
	}
*/

//2. GTTĐ
/*
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	cout << abs(a-b);
	return 0;
}
*/


//Bai 3: lam tron so
/*
#include <iostream>
#include <cmath>
using namespace std;
int main() {
double n;
cin >> n;
cout << round (n);
return 0;
}
*/

 
//Bai4: kiem tra so chinh phuong                (acp 2/5)
/*
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n;
	cin >> n;
	double x = sqrt(n);
	if (n = x*x ) cout << ""<< n <<" la so chinh phuong";
	return 0;
}
*/


//kiểm tra năm nhuận                  (acp 5/5)
/*
#include <iostream>
using namespace std;

int main(){
	int year;
	cin >> year;
		if(year > 0 && year <= 100000){   // giới hạn 0 -> 100000
            if((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0)){    //điều kiện năm
                cout << "YES";
            }else{
                cout << "NO";
            }
        }else{
            cout << "INVALID";
        }
        return 0;
}
*/


//tinh so ngay cua thang                    (acp 5/5)
/*
#include <iostream>
using namespace std;

int main(){
	int month;    //1-12
	long year;    //0-100000
	cin >> month >> year;
	if (month >= 1 && month <= 12){
		switch (month){
		case 1:
		case 3: 
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		    cout << "31" << endl;
		    break;
		case 4:
		case 6:
		case 9:
		case 11:
		    cout << "30" << endl;
		    break;
	    default:
	    	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
	    		cout << "29" << endl;
			} else cout << "28";
	}
    } else cout << "INVALID";
}
*/


//tinh tong pb1: S = 1+2+3+...+n                 (acp: 4/4)
/*
#include <iostream>
using namespace std;

int main(){
	unsigned long n;     // n < 10^6 , n nguyên dương
	long long S = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		S += i;
	}
	cout << S;
	return 0;
}
*/


//tinh S = (2 + 3 + 4... + n) + 2n                  (acp 4/4)
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n;   // n< 10^4 và n >= 2 
    long long S = 0;
    cin >> n;
    if (n >= 2){
    	for (int i = 2; i <= n; i++){
    		S += i;
		}	
	}
	cout << S + 2*n;
	return 0;
}
*/


//tinh S = 1/2 + 1/3 + ... + 1/n               (acp 4/4)
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	double S = 0;
	cin >> n;
	if (n<2) cout << "EROR";
	else {
		for (double i = 2; i <= n; i++){   //i phải đồng nhất kiểu dl với S;
			S += 1/i;
		}
		cout << setprecision(4) << fixed << S;
	}
	return 0;
}
*/


// Tinh S = 1 - 2 + 3 - ... + (3n + 1), nếu n chẵn            (acp 4/4)
//        = 1 - 2 + 3 - ... - (3n + 1), nếu n lẻ
//cach1:
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int S1 = 0, S2 = 0;
	cin >> n;
	int a = 3*n + 1;
	if (n % 2 == 0) {
		for (int i = 1; i <= a; i = i+ 2){
			S1 += i;
		}
		for (int i = 2; i < a; i = i+2){
			S2 += i;
		}
		cout << S1 - S2;
	}else{
		 for (int i = 1; i < a; i = i+ 2){
			S1 += i;
		}
		for (int i = 2; i <= a; i = i+2){
			S2 += i;
		}
		cout << S1 - S2;
	}
	return 0;
}
*/
//cach2: thiet lap cthuc Tong sicma:  E(i=1, n)[(-1)^i+1]*i
/*
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, S = 0;
	cin >> n;
	for (int i = 1; i <= (3*n)+ 1; i++){
		S += pow(-1, i+1)*i;    //so chan thi cong, so le thi tru
	}
	cout << S;
	return 0;
}
*/


//Tinh n!=1.2.3....n                 (acp 4/4)
//cach 1: for
/*
#include <iostream>
using namespace std;

int main(){
	unsigned int n;
	int T = 1;
	cin >> n;
	if (n <= 12){
		for (int i = 1; i <= n; i++){
			T *= i;
		}
	}
	cout << T;
	return 0;
}
*/
//cach 2: sd de quy
/*
#include <iostream>
using namespace std;

int giaithua(int n){
	if (n == 1 || n == 0) return 1;
	else return n*giaithua(n-1);
}

int main(){
	unsigned int n;
	cin >> n;
	cout << giaithua(n);
	return 0;
}
*/


//tinh to hop
//cach1: sd de quy giai thua              (acp 2/5)
/*
#include<iostream>
using namespace std;
int giaiThua(int n){
	if (n == 0 || n == 1) return 1;
	return n*giaiThua(n-1);
}
int main(){
	int n, k, C;
	cin >> n >> k;
	if (k > n) cout <<"EROR";
	else {
		C = giaiThua(n)/(giaiThua(k)*giaiThua(n-k));
	}
    cout << C;
    return 0;
}
*/
//cach 2: de quy truc tiep                (acp: 5/5)
/*
#include <iostream>
using namespace std;

int C(int k, int n){
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;
	return C(k-1, n-1) + C(k, n-1);      //dang thuc to hop
}
int main(){
	int n, k;
	cin >> n >> k;
	cout << C(k,n);
	return 0;
}
*/


// Tinh: S = x + x^2/2! + ... + x^n/n!              (acp: 2/2)
/*
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int gt(int n){
    if(n == 0 || n == 1) return 1;
    return n*gt(n-1);
}
int main(){
    int n;
    double x, S = 0.0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        S += pow(x, i)/gt(i);
    }
   cout << setprecision(2) << fixed << S;
   return 0; 
}
*/


//dem so luong chu so cua so nguyen n                (acp 5/5)
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
    string n;
    cin >> n;
    if (n[0] == '-') cout << n.length() - 1;     //nếu là số âm lưu ý dấu trừ
    else cout << n.length();
    return 0;
}
*/


//ktra so nguyen to                    (acp: 5/6)
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	int count = 0;
	long long n;        // n < 10^12
	cin >> n;
	if (n < 2) cout << "NO";
	else{
	for (int i = 1; i <= n; i=i+2){
		if (n % i == 0) count++;
	}
	if (count == 2) cout << "YES";
	else cout << "NO";
	return 0;	
    }
}
*/

// bai toan so hoan hao
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long S = 0;
	long n;
	cin >> n;
	if (n < 2) cout << "NO";
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0) 
		{
		S += i;
	    }
	}
	if (S == n) cout << "YES";
	else cout << "NO";
	return 0;
}
*/


//tim uoc chung lon nhat cua 2 so
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	cout << abs(__gcd(a,b));   //ham tim ucln
	return 0;
}
*/


//rut gon phan so                    (acp: 4/5)
/*
#include<iostream>
#include<algorithm>      // __gcd(a,b) 
#include<cmath>          // abs(a)
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if (abs(a) <= 1000 && abs(b) <= 1000){
  	if (b == 0) cout << "INVALID";
  	int x = __gcd(a,b);
  	if (a % b == 0) cout << a/b;
  	else {
  	    a = a/x;
  	    b = b/x;
  	    cout << a << " " << b << " ";
	  }
  }      
  return 0;
}
*/


//tim boi chung nho nhat           (acp: 10/10)   chú ý ko tồn tại bcnn của số âm
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	cout << abs(a*b/__gcd(a,b));
	return 0;
}
*/

//tìm số đảo ngược
//cach 1
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	char a[1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	reverse (a, a+n);
	if (a[0] == 0) 
	{
		for (int i = 1; i < n; i++)
		{
		cout << a[i];
	    }
	}
	else if (a[n-1] == '-')
	{
		for (int i = 0; i < n-1; i++)
		{
		cout << a[i];
	    }
	}
    else for (int i = 0; i < n; i++)
         {
		 cout << a[i];
	     }
	return 0;
}
*/

// in ra chu cai                 (acp: 2/2)
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
	char a, b;
	cin >> a >> b;
	char x = a - 32;
	char y = b - 32;
	if ( x <= y){
	for (char i = x; i <= y; i++){
		cout << i << " ";
	}
    }
	return 0;
}
*/


//Tìm x nguyên dương lớn nhất, biết 1+2+3+...+x ≤ N           (acp 4/4)
//cach1: huong giai quyet so1
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
   long long N;
   cin >> N;
   if (N < 1) cout << "khong ton tai x";
   else if (N >= 5 && N <= pow(10,9))
   {
    double x = (-1+sqrt(1+8*N))/2;	     // đưa về bt: (1+x)x/2 ≤ N
    if (x < round(x)) cout << round(x) - 1;         //max của x chính là phần nguyên của nghiệm lớn     
    else 
	   cout << round(x);
   }
   else 
       cout <<"INVALID";
   return 0;	
}
*/

//cach2:
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long id, N, S = 0;
    cin >> N;
    for (long i = 1; i < N; i++)
    {
        S += i;
        if (S > N) //Ung voi gia tri x lam cho tong tu 1-->x > N ta lay gia tri x ngay truoc do chinh la gia tri x lon nhat ma tong tu 1 den x cua no <= N
        {
            id = i - 1;
            break; // Lay duoc gia tri x thoa man roi thi dung vong lap
        }
    }
    cout << id;
    return 0;
}
*/

//doi he thap phan sang nhi phan
/*
#include <iostream>
#include <cmath>
using namespace std;

int Dec2Bina(long long decimalNumber){
	int tmp = 0;
	long long BinaryNumber = 0;
	while (decimalNumber > 0){
		BinaryNumber += (decimalNumber % 2)*pow(10,tmp);
		tmp++;
		decimalNumber /= 2;
	}
	return BinaryNumber;
}

int main(){
	int T;
	cin >> T;
	long long n[T];
	for (int i = 0; i < T; i++){
		cin >> n[i];
	}
	for (int i = 0; i < T; i++){
     	if (T >= 1 && n[i] >= 1){
     	    cout << Dec2Bina(n[i])<< endl;	
	}
    }
    	return 0;
}
*/ 

//tim so lon nhat trong mang          (acp: 2/4)
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long n;
	long A[1000];
	cin >> n;
	long max = A[0];
	for (long i = 0; i < n; i++){
		cin >> A[i];
		if (A[i] > max) max = A[i]; 
	}
	cout << max;
	return 0;
}
*/

//tim so lơn thu 2 trong mang     (acp: 11/11)
/*
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];      //nhập mảng
    }
    if (n <= 1){
        cout << "NOT FOUND";      //điều kiện đề 
        return 0;
    }
    for(int i = 0; i < n; i++){              // sắp xếp giảm dần
        for(int j = i + 1 ;j < n;j++){
            if(arr[i] < arr[j]){
            	int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
       		}
        }
    }
    int count = 0;               //đếm các phần tử trùng nhau
    for(int i = 1; i < n; i++){
        if(arr[0] == arr[i]){
            count++;
        } else {
            break;
        }
    }
    if (count == n - 1){          //chỉ ra second
        cout << "NOT FOUND";
    } else {
        cout << arr[count + 1];
    }
    return 0;
}
*/


//ktra xem số có tính chất palindrome không?

#include <bits/stdc++.h>
using namespace std;
int main(){
	int number;
	int count = 0;
	cin >> number;
    if (number % 10 == 0)
	{
        cout << "INVALID, please re-enter" << endl;    	
	}
    int Bnumber = number;
	while (Bnumber != 0)
	{
		Bnumber /= 10;
		++count;      
	}
	int p = count - 1;
	int reverse = 0;
	int Fnumber = number;
	while (Fnumber != 0)
	{
	    reverse += (Fnumber % 10)*pow(10,p);
	        p--;
  	        Fnumber /= 10;
    }
//    cout << afNumber;
	if (reverse == number)
	{
		cout << ""<< number<<" is palindrome\n";
	}
	else cout << ""<< number<<" is not a palindrome\n";	
	system ("pause");
	return 0;	
}



// chỉ số của phần tử trong mảng có giá trị lớn nhất    (acp 4/4)
/*
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int cs=0,max=A[0];
	for(int i=1;i<n;i++){
		if(max<=A[i]){
			max=A[i];
			cs=i;
		}
	}
	cout<<cs;
	return 0;
}
*/


//Cho mảng số nguyên A có n phần tử, hãy tìm kiếm xem trong mảng có xuất hiện phần tử x hay không?
/*
#include <iostream>
using namespace std;

int main(){
	int n,x,A[n];
	cin >> n >> x;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	for (int i = 0; i < n; i++){
		if (A[i] == x) cout << "YES";
		else cout << "NO";
		break;
	}
	return 0;
}*/

/*
#include <iostream>
using namespace std;

//Định nghĩa hàm
int make_juice ( int water = 1 , int fruit = 3){
//Khai báo biến juice
  int juice ;
//Cộng giá trị của biến water và fruit
  juice = water + fruit;
//In ra kết quả
  cout << "Your juice is ready" << endl ;
//Trả về giá trị của biến juice cho hàm
  return juice;

}
int main() {
  //Khai báo biến juice_glass
  int juice_glass; 

  //Gọi hàm make_juice không truyền vào bất kỳ giá trị nào
  juice_glass = make_juice();
  cout << "Number of juice glass = " << juice_glass << endl;
  //Gọi hàm make_juice với một tham số duy nhất truyền vào
  juice_glass = make_juice (5);
  cout << "Number of juice glass = " << juice_glass << endl;
  //Gọi hàm make_juice và truyền vào 2 giá trị
  juice_glass = make_juice(2, 5);
  cout << "Number of juice glass = " << juice_glass << endl;
  
  return 0;
}
*/

/*
#include <iostream>

using namespace std;

int main() {
  //Khai báo biến John
  int John = 10;
  //In ra địa chỉ bộ nhớ mà giá trị của John được lưu
  cout << "John Address = " << &John << endl;
  //In ra giá trị của John
  cout << "John Value = " << John << endl;
  return 0;
}
*/






















