// -------- ON TAP CTDL&TT -----------

// 1. Đệ quy có nhớ
/*
#include<iostream>

using namespace std;
#define MAX 1000
int m[MAX][MAX];

int C(int k, int n){
	if (k == 0 || k == n)
		m[k][n] = 1;
	else {
		if (m[k][n] == 0){
			m[k][n] = C(k-1,n-1)+C(k,n-1);
		}
	}
	return m[k][n];
}

int main(){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			m[i][j] = 0;
		}
	}
	cout << C(5,12) << endl;
	return 0;
}
*/

//2. ĐỆ QUY QUAY LUI ------------------------------------------------------------------------------------------
// BT1: sinh xâu nhị phân
/*
#include<bits/stdc++.h>

using namespace std;
#define MAX 10000
int n, a[MAX];

void print(){
	for(int i = 1; i <= n; i++)
		cout << a[i];
	cout << endl;
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if (i == n){
			print();
		}
		else Try(i+1);
	}
}
int main(){
	cin >> n;
	Try(1);
	return 0;
}
*/

//BT2: liệt kê hoán vị
/*
#include<bits/stdc++.h>

using namespace std;
#define MAX 10000
int N, x[MAX], m[MAX];    
// expl: x[i]: mảng lưu phần tử thứ i của cấu hình
//       m[x[i]]: mảng đánh dấu phần tử x[i] đã được sử dụng?

void print(){
	for(int i = 1; i <= N; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

void Try(int i){
	for(int v = 1; v <= N; v++){
		if(!m[v]){
			x[i] = v;
			m[v] = 1;   //danh dau
			if (i == N)
				print();
			else Try(i+1);
			m[v] = 0;   //khoi phuc 
		}
	}
}

int main(){
	cin >> N;
	memset(m, sizeof(m), 0);
	Try(1);
	return 0;
}
*/

// BT3: bài toán xếp hậu
/*
 DESCRIBE: xếp n quân hậu lên bàn cờ nxn, sao cho không có 
 	  2 quân hậu nào ăn được nhau (khác hàng, cột, đường chéo)
 IDEA:
    x[i] là hàng của quân hậu xếp trên cột i
    check các dk sau:
    	x[i] # x[j] ,với 1 < i < j < n
    	x[i] + i # x[j] + j ,với 1 < i < j < n
    	x[i] - i # x[j] - j ,với 1 < i < j < n
*/
/*
#include<bits/stdc++.h>

using namespace std;
#define MAX 1000
int n, x[MAX];

void print(){
	for (int i = 1; i <= n; i++){
		cout << "Quan hau o cot " << i << " xep vao hang " << x[i] << endl;
	}
}
int check(int v, int k){
	// ktra xem gán được v cho x[k] ?
	for (int i = 1; i <= k-1; i++){
		if (x[i] == v) return 0;
		if (x[i] + i == v + k) return 0;
		if (x[i] - i == v - k) return 0;
	}
	return 1;
}

void Try(int k){
	for(int v = 1; v <= n; v++){
		if (check(v,k)){
			x[k] = v;
			if (k == n)
				print();
			else Try(k+1);
		}
	}
}

int main(){
	cin >> n;
	Try(1);
	return 0;
}
*/

// BT4: Trò chơi Sudocu
/*
#include<bits/stdc++.h>

using namespace std;
int x[9][9];

void print(){
	for(int i = 0; i <= 8; i++)
		for(int j = 0; j <= 8; j++)
			cout << x[i][j] << " ";
		cout << endl;
}

bool check(int v, int r, int c){
	for(int i = 0; i <= r-1; i++)
		if(x[i][c] == v) return false;
	for(int j = 0; j <= c-1; j++)
		if(x[r][j] == v) return false;
	int I = r/3;
	int J = c/3;
	int i = r - 3*I;
	int j = c - 3*J;
	for(int i1 = 0; i1 <= i-1; i1++)
		for(int j1 = 0; j1 <= 2; j1++)
			if(x[3*I+i1][3*J+j1] == v)
				return false;
	for(int j1 = 0; j1 <= j-1; j1++)
		if(x[3*I+i][3*J+j1] == v)
			return false;
	return true;
}

void Try(int r, int c){
	for(int v = 1; v <= 9; v++){
		if(check(v,r,c)){
			x[r][c] = v;
			if(r == 8 && c == 8){
				print();
			}else {
				if (c == 8) Try(r+1,0);
				else Try(r,c+1);
			}
		}
	}
}

int main(){
	Try(0,0);
	return 0;
}
*/

// BÀI TẬP ĐỆ QUY QUAY LUI
// bai1 _ cach1
/*
#include<bits/stdc++.h>

using namespace std;
#define MAX 10000
int x[MAX], k, n, m1[MAX], m2[MAX];

void print(){
	for(int i = 1; i <= k; i++)
		cout << x[i] << " ";
	cout << endl;
}

void Try1(int i){
	memset(m1,0,sizeof(m1));
	for(int j = 1; j <= n; j+= 2){
		if(!m1[j]){
			x[i] = j;
			m1[j] = 1;
			if (i == k) 
				print();
			else Try1(i+1);
			m1[j] = 0;
		}
	}
}

void Try2(int i){
	memset(m2,0,sizeof(m2));
	for(int j = 2; j <= n; j+= 2){
		if(!m2[j]){
			x[i] = j;
			m2[j] = 1;
			if (i == k) 
				print();
			else Try2(i+1);
			m2[j] = 0;
		}
	}
}

int main(){
	cin >> n >> k;
	Try1(1);
	Try2(1);
	return 0;
}
*/
/*
// cach2
#include <iostream>
#include <vector>

using namespace std;

bool isValid(int i, int j) {
    // Hàm kiểm tra xem i và j có đứng cạnh nhau không
    return abs(i - j) > 1;
}

void genComb(int n, int k, vector<int>& curComb, int index){
    if (index == k) {
        // In ra một cách chọn
        for (int i = 0; i < k; i++) {
            cout << curComb[i] << " ";
        }
        cout << endl;
        return;
    }

    // Lặp qua tất cả các phần tử từ 1 đến n
    for (int i = 1; i <= n; i++) {
        // Kiểm tra xem phần tử i có thể thêm vào cách chọn hiện tại không
        bool canAdd = true;
        for (int j = 0; j < index; j++) {
            if (!isValid(curComb[j], i)) {
                canAdd = false;
                break;
            }
        }

        // Nếu phần tử i có thể thêm vào cách chọn, thêm vào và gọi đệ quy
        if (canAdd) {
            curComb[index] = i;
            genComb(n, k, curComb, index + 1);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> curComb(k);
    genComb(n, k, curComb, 0);
    return 0;
}
*/

// THUẬT TOÁN QUAY LUI - TỐI ƯU NHÁNH CẬN   ---------------------------------------------------------------------
/*
Bài toán: người đi du lịch
	Có n thành phố 1, 2, …, n. Chi phí đi từ thành phố i đến thành
	phố j là c(i, j). Hãy tìm một hành trình xuất phát từ thành phố thứ
	1, đi qua các thành phố khác, mỗi thành phố đúng 1 lần và quay
	về thành phố 1 với tổng chi phí nhỏ nhất
		input: 
			4
			0 85 26 81
			85 0 77 97
			26 77 0 26
			81 97 26 0
		output: 234
*/

/*
#include<bits/stdc++.h>

using namespace std;

int n, c[100][100], x[100];     
// xây dựng cấu hình x[i] = j (thành phố j được đi ở thứ tự i)
int d = 0, ans = INT_MAX;
int visited[100];

void inp(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];
		}
	}
	memset(visited, 0, sizeof(visited));
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(!visited[j]){
			x[i] = j;
			visited[j] = 1;
			d += c[x[i-1]][x[i]];
			if(i == n){
				// ghi nhận cấu hình
				ans = min(ans, d + c[x[n]][1]);
			} else {
				Try(i+1);
			}
			// backtrack
			visited[j] = 0;
			d -= c[x[i-1]][x[i]];
		}
	}
}

int main(){
	inp();
	x[1] = 1; visited[1] = 1;
	Try(2);
	cout << ans << endl;
	return 0;
}
*/

// cách 2: tối ưu = đánh giá cận
// đánh giá cận dưới: chi phí nhỏ nhất có thể đạt được trong lời gọi quay lui hiện tại 
/*
#include<bits/stdc++.h>

using namespace std;

int n, c[100][100], x[100];     
// xây dựng cấu hình x[i] = j (thành phố j được đi ở thứ tự i)
int d = 0, ans = INT_MAX, cmin = INT_MAX;
int visited[100];

void inp(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];
			if (c[i][j] != 0){
				cmin = min(cmin, c[i][j]);    // chi phí nhỏ nhất giữa 2 tp bất kì
			}
		}
	}
	memset(visited, 0, sizeof(visited));
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(!visited[j]){
			x[i] = j;
			visited[j] = 1;
			d += c[x[i-1]][x[i]];
			if(i == n){
				// ghi nhận cấu hình
				ans = min(ans, d + c[x[n]][1]);
			} // đánh giá cận dưới
			else if (d + (n - i + 1)*cmin < ans) {     // chi phí nhỏ nhất, nếu nhỏ hơn kỉ lục là ans thì mới 
				Try(i+1);                              // tiếp tục quay lui theo nhánh đó, không thì thôi 
			}
			// backtrack
			visited[j] = 0;
			d -= c[x[i-1]][x[i]];
		}
	}
}

int main(){
	inp();
	x[1] = 1; visited[1] = 1;
	Try(2);
	cout << ans << endl;
	return 0;
}
*/


// THUẬT TOÁN THAM LAM
// Bài toán đoạn giao 
/* Tối ưu nhất theo tham lam 3:
   sắp xếp theo chiều không giảm của bi

   input: 6
		0 10
		3 7
		6 14
		9 11
		12 15
		17 19
	output: 4
*/
/*
#include<bits/stdc++.h>
using namespace std;
#define N 100001
struct Segment{
	int a,b;
};

Segment s[N];
int n, ans=0;

void inp(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i].a >> s[i].b;
	}
}

void solve(){
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(s[i].b > s[j].b){
				Segment tmp = s[i]; s[i] = s[j]; s[j] = tmp;
			}
		}
	}
	int last = INT_MIN;
	for(int i = 1; i <= n; i++){
		if(s[i].a > last){
			ans += 1;
			last = s[i].b;
			// cout << "Select segment " << i << ": (" << s[i].a << "," << s[i].b << ")" << endl;
		}
	}
	cout << ans << endl;
}

int main(){
	inp();
	solve();
	return 0;
}
*/


// THUẬT TOÁN CHIA ĐỂ TRỊ ------------------------------------------------------------------------------------------
// BT1: Tìm kiếm nhị phân 
/*     // O(logn)
#include<bits/stdc++.h>
using namespace std;
int n,y, x[10000];

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	cin >> y;
}
int bSearch(int x[10000], int start, int end, int y){
	if (start == end){
		if (x[start] == y)
			return start;
		return -1;
	} else {
		int m = (start+end)/2;
		if (x[m] == y) return m;
		else if (x[m] > y) 
			return bSearch(x,start,x[m-1],y);
		else return bSearch(x,x[m+1],end,y);		
	}
}

int main(){
	input();
	cout << bSearch(x,0,n-1,y);
	return 0;
}
*/


//BT2: dãy con cực đại
/* dãy con gồm các phần tử liên tiếp có tổng cực đại
   áp dụng thực tế cho mảng chứa cả số nguyên âm */

/*
#include<bits/stdc++.h>
using namespace std;
int n, a[10000];     // mảng a gồm các số nguyên 

void readData(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];   
	}
}

int maxLeft(int *a, int l, int r){
	int max = -999999999;
	int s = 0;
	for(int i = r; i >= l; i--){
		s += a[i];
		if(s > max) max = s;
	}
	return max;
}

int maxRight(int *a, int l, int r){
	int max = -999999999;
	int s = 0;
	for(int i = l; i <= r; i++){
		s += a[i];
		if(s > max) max = s;
	}
	return max;
}

int maxSeq(int *a, int l, int r){
	if(l == r) return a[l];
	int max;
	int mid = (l+r)/2;
	int mL = maxSeq(a, l, mid);
	int mR = maxSeq(a, mid+1, r);
	int mLR = maxLeft(a, l, mid) + maxRight(a, mid+1, r);
	max = mL;
	if (max < mR) max = mR;
	if (max < mLR) max = mLR;
	return max;
}

int main(){
	readData();
	cout << maxSeq(a, 0, n-1) << endl;
	return 0;
}
*/

// Định lý thợ


// THUẬT TOÁN QUY HOẠCH ĐỘNG --------------------------------------------------------------------------------------
// Dãy con cực đại
/*
	Dãy nguyên (dương,âm) => dãy con liên tiếp có tổng cực đại
	IDEA: phân chia:
		P(i) là bài toán tìm dãy con bao gồm các phần tử liên tiếp có tổng
			cực đại mà phần tử cuối cùng là a(i), với i = 1...n
		S(i) là tổng các phần tử của lời giải của P(i)
		S(1) = a(1)
		S(i) = S(i-1) + a(i), nếu S(i-1) > 0
			 = a(i)         , nếu S(i-1) < 0

	  => Result = Max{S1, S2, ..., Sn}
*/
/*
#include<bits/stdc++.h>

using namespace std;
int a[1000], S[1000], n;

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
}

int maxSeq(int *a){
	S[1] = a[1];
	int ans = S[1];
	for(int i = 2; i <= n; i++){
		if(S[i-1] > 0) 
			S[i] = S[i-1] + a[i];
		else S[i] = a[i];
		ans = max(ans,S[i]);
	}
	return ans;
}

int main(){
	input();
	cout << maxSeq(a) << endl;
	return 0;
}
*/

// BT2: Dãy con chung dài nhất
/*
	Một dãy con của X được tạo ra bằng cách loại bỏ 1 số phần tử của tập X
	Input: 2 dãy X và Ys
	Ouput: dãy con chung của X và Y có độ dài lớn nhất
*/

