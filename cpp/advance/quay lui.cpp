// THUẬT TOÁN QUAY LUI

// VD1: Sinh xâu nhị phân N bit
/*
#include<bits/stdc++.h>
using namespace std;

int N, X[100];
void inkq(){
	for(int i = 0; i < N; i++){
		cout << X[i];
	}
	cout << endl;
}
void Try(int i){
	for (int j = 0; j <= 1; j++){
		X[i] = j;
		if (i == N){
			inkq();
		}
	    else
	        Try(i+1);
	}
}
int main(){
	cin >> N;
	Try(1);
	return 0;
}
*/

//VD2: Sinh tổ hợp chập K của N
/*
#include <bits/stdc++.h>
using namespace std;

int N, X[100], K;
void inkq(){
	for(int i=1; i <= K; i++){
		cout << X[i];
	}
	cout << endl;
}
void Try(int i){
	for(int j = X[i-1]+1; j <= N-K+j; j++){
		X[i] = j;
		if (i == N){
			inkq();
		}
		else{
			Try(i+1);
		}
	}
}
int main(){
	cin >> N >> K;
	Try(1);
	return 0;
}
*/


//VD3: Sinh hoán vị của N phần tử

//#include<bits/stdc++.h>
//using namespace std;
//
//int N, X[100], used[100];
//void inkq(){
//	for(int i = 1; i <= N; i++){
//		cout << X[i];
//	}
//	cout << endl;
//}
//void Try(int i){
//	for(int j = 1; j <= N; j++){
//		if(used[j] == 0){
//			X[i] = j;
//			// đánh dấu
//			used[j] = 1;
//			if(i == N){
//				inkq();
//			} else
//				Try(i+1);
//			//backtrack
//			used[j] = 0;
//		}
//	}
//}
//int main(){
//	cin >> N;
//	memset(used, 0, sizeof(used));
//	Try(1);
//	return 0;
//}
//

// VD4: Bài toán N QUEENS
/* PROBLEM: Sắp xếp N quân hậu vào bàn cờ vua N*N sao cho không có 2 quân hậu nào ăn nhau X = {X1,X2,...XN} 
là một nghiệm của bài toán, khi đó nếu x[i] = j thì xếp quân hậu ở hàng i vào cột j -> (i,j)
   NHẬN XÉT: (i,j) quản lí cột i, hàng j, đcx i-j+n, đcn i+j-1
*/
/*
#include<bits/stdc++.h>
using namespace std;

int N, X[100], col[100], dx[100], dn[100];
int a[100][100];

void inkq(){
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= N; i++){
		a[i][X[i]] = 1;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void Try(int i){
	for (int j = 1; j <= N; j++){
		if (col[j] == 1 && dx[i-j+N] == 1 && dn[i+j-1] == 1)
		{
			X[i] = j;
			col[j] = dx[j-j+N] = dn[i+j-1] = 0;
			
			if (i == N) 
				inkq();
			else 
				Try(i+1);
			//backtrack
			col[j] = dx[i-j+N] = dn[i+j-1] = 1;
		}
	}
}
int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		col[i] = dx[i] = dn[i] = 0;
	}
	Try(1);
    return 0;	
}
*/

