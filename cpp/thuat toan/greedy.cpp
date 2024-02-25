// GIẢI THUẬT THAM LAM

//Bài toán 1: Danh sách hành tinh Asteroids và hành tinh Mass 
/*
#include <bits/stdc++.h>

using namespace std;

bool destroyAsteroids(int mass, vector<int>& asteroids){
    long currMass = mass;
    sort(asteroids.begin(), asteroids.end());
    for(int asteroid : asteroids){
        if (asteroid > currMass){
           return false;
        }
        currMass += asteroid;
    }
    return true;
}

int main(){
    vector<int> asteroids = {5, 2, 21, 3, 6};
    int mass = 12;
    cout << boolalpha << destroyAsteroids(mass, asteroids);
    return 0;
}
*/

// BT1: Bài toán đổi tiền
/*
#include<iostream>
using namespace std;

int main(){
	int a[] = {1000,500,200,100,50,20,10,5,2,1};
	int n = 10;
	int t; cin >> t;
	while(t--){
		long long k, res = 0;
		cin >> k;
		for(int i = 0; i < n; i++){
			res += k/a[i];
			k %= a[i];
		}
		cout << res << endl;
	}
	return 0;
}
*/


// BT2: Nhầm chữ số
/*
   Cho 2 số A và B. Bi không bao giờ tính sai, thi thoảng chép nhầm số '5' thành '6' hoặc ngược lại
   Tính tổng nhỏ nhất và lớn nhất có thể nhận được khi viết sai    (1 <= A,B <= 1000000)
   ex:
   	 input: 11 25 -> output: 36 37
	 input: 16796 58786 -> output: 74580 85582
*/
/*
#include<bits/stdc++.h>
using namespace std;
string a,b;

string sum(){
	if (a.size() < b.size()) a = "0"+a;
	if (b.size() < a.size()) b = "0"+b;
	int len = a.size();
	string res = "";
	int rem = 0;
	for(int i = len-1; i>= 0; i--){
		int num = int(a[i]-'0') + int(b[i]-'0') + rem;
		res = char(num%10 + '0') + res;
		rem = num/10;
	}
	if (rem > 0) return char(rem+'0') + res;
	return res;
}

int main(){
	int t; cin >> t;    // so bo test
	while(t--){
		cin >> a >> b;
		for(int i = 0; i < a.size(); i++)
			if(a[i] == '6') a[i] = '5';
		for(int i = 0; i < b.size(); i++)
			if(b[i] == '6') b[i] = '5';
		// tong nho nhat
		cout << sum() << " ";

		for(int i = 0; i < a.size(); i++)
			if(a[i] == '5') a[i] = '6';
		for(int i = 0; i < b.size(); i++)
			if(b[i] == '5') b[i] = '6';
		// tong lon nhat
		cout << sum() << endl;
	}
	return 0;
}
*/

// BT3: Tổng T = A[i]*i đạt max, in ra T mod (10^9 + 7)
/*
#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

int main(){
	int n;
	long long max = 0, a[n];
	int t; cin >> t;
	while (t--){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		for(int i = 0; i < n; i++){
			max += a[i]*i;
			max %= mod;
		}
	}
	cout << max << endl;
	return 0;
}
*/


// BT4: Tổng nhỏ nhất
/* Cho mảng A gồm các số từ 0-9, lập 2 số bất kì từ tất cả các phần tử 
     của mảng A sao cho tổng 2 số đó là nhỏ nhất 
    IDEA: ghép số ở vị trí chẵn với nhau, lẻ với nhau => tổng nhỏ nhất
    input: A[] = {1,2,3,4,5}
            => 24 và 135  
    output: 159
*/
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    long long m = 0, n = 0;
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int val; cin >> val;
            if (val != 0) a.push_back(val);
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size(); i++){
            if (i % 2) m = 10*m + a[i];
            else n = 10*n + a[i];
        }
    }
    cout << m+n << endl;
    return 0;
}
*/


// BT5: Chia mảng
/*
 Chia mảng A thành 2 mảng con kích thước K và N-K sao cho hiệu của 
 tổng các phần tử của 2 mảng là lớn nhất
    input: n = 5 -> {8,5,2,4,10}
           k = 3
    output: 17   (5,8,10)-(2,4)
           k = 2
    output: 17    (5,8,10)-(2,4)     //không quy định thứ tự mảng con 
*/
/*
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int n,k; int a[n];
    long long sum1 = 0, sum2 = 0, res = 0;
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        int j = 0;
        while (j < n){
            if (j < k) sum1 += a[j];
            else sum2 += a[j];
            j++;
        } 
        res = abs(sum1 - sum2);
        sum1 = sum2 = 0;
        j = 0;
        while (j < n){
            if (j < n-k) sum1 += a[j];
            else sum2 += a[j];
            j++;
        }
        res = max(res, abs(sum1 - sum2));
        cout << res << endl;
        return 0;
    }
}
*/

