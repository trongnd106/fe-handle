// TÍNH TỔ HỢP

//#include<iostream>
//using namespace std;
//int C(int k, int n) {
//	if (k == 0 || k == n) return 1;
//	if (k == 1) return n;
//	return C(k - 1, n - 1) + C(k, n - 1);
//}
//int main(){
//	int n, k;
//	cin >> n >> k;
//	cout << "To hop bang: " << C(k, n);
//	system("pause");
//	return 0;
//}

// GIẢI PT BẬC HAI
/*
#include<bits/stdc++.h>

using namespace std;

int main(){
	double a,b,c;
	cin >> a >> b >> c;
	if (a == 0){
		if (b == 0 && c != 0) cout << "NO";
		else if (b == 0 && c == 0) cout << "WOW";
		else cout << setprecision(2) << fixed << -c/b;
	}
	else {
		double delta = b*b - 4*a*c;
		if (delta < 0) cout << "NO";
		else if (delta == 0) cout << setprecision(2) << fixed << -b/(2*a);
		else {
		    cout << setprecision(2) << fixed << (-b-sqrt(delta))/(2*a) << " ";
			cout << setprecision(2) << fixed << (-b+sqrt(delta))/(2*a);
	    }
	}
	return 0;	
}
*/
// CHUYỂN HOA -> THƯỜNG
/*
#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
	// if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
	cout << s;
	return 0;
}
*/

// CHUYỂN THẬP PHÂN -> NHỊ PHÂN
#include <iostream>
#include <cmath>

using namespace std;
 
void DectoBin(int n){
	long long ans = 0;
	int i = 0;
	while (n > 0){
		ans += (n % 2)*pow(10,i);
		++i;
		n /= 2;
	}
	cout << ans << endl;
}
int main(){
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n;i++) cin >> ar[i];
	for (int i = 0; i < n;i++) DectoBin(ar[i]);
	return 0;	
}