/* Bai1 Sap xep tang dan
#include <iostream>

using namespace std;

int main(){
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++){
        cin >> a[i];
    }
    for (i=0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for (i = 0; i< n; i++){
    cout << a[i] << " ";
    }
    return 0;
}
*/

/* Bai2   IP: 3 numbers -> OP: MAX
#include <iostream>
using namespace std;

int Nhap(int a, int b, int c){
	int maxValue = a;
	if(maxValue < b){
		maxValue = b;
	}
	if(maxValue < c){
		maxValue = c;
	}
	return maxValue;
}
int main(){
	Nhap(3,4,8); 
	Nhap(2,6,1);
	Nhap(10,21,13);
	return 0;
}
*/

/* Bai3  IP: 2 arr -> OP: Max of 2 arr
#include <iostream>
#include <iomanip>
using namespace std;
using std::setw;

void Nhap(int arr[1000], int n){
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
}

int maxOfArray(int arr[1000], int n){
	int MAX = arr[0];
	for (int i = 0; i < n; i++){
		if(arr[i] > MAX)
		  MAX = arr[i];
	
	}
	return MAX;
}
int main(){
	int n1, n2;
	int arr1[n1], arr2[n20];
	cin >> n1 >> n2;
	Nhap(arr1, n1);
	Nhap(arr2, n2);
	cout << maxOfArray(arr1, n1) << setw(5) << maxOfArray(arr2, n2);
	return 0;
	}
*/

/* Bai4   IP: 1 array kieu string -> OP: arr[i].size() >= 3  << use func>>
#include <iostream>
#include <string>
using namespace std;

void Nhap(string arr[1000], int n){
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
}
void Hienthi(string arr[1000], int n){
	for (int i = 0; i < n; i++){
            if (arr[i].size() >= 3)
		    cout << arr[i] << " ";
		}
}
int main(){
	int n;
	cin >> n;
	string arr[n];
	Nhap(arr, n);
	Hienthi(arr, n);
    return 0;
}
*/

//1. Tinh tong 2 so nguyen 
/*
#include <iostream>
using namespace std;
int main() {
  ios::base_sync_with_stdio(false);
  cout.tie(nullpr);
  int i = 20;
  int& iRef = i;
  std::cout << "i: " << i << std::endl;
  std::cout << "iRef: " << iRef << std::endl;
  
  std::cout << std::endl;

  iRef = 30; //Thay doi tham chi3u

  std::cout << "i: " << i << std::endl;
  std::cout << "iRef: " << iRef << std::endl;
  system ("pause");
}
*/

//số nguyên tố
/*
#include<bits/stdc++.h>
using namespace std;

bool isPrime (long long int n){
	if (n == 1)
	    return false;
	for (int i = 2; i*i < n; i++){
		if (n % i == 0)
		    return false;
	}
	return true;
}
int main(){
	long long int n;
	cin >> n;
	isPrime(n) ? cout << "True" : cout << "False";
	system("pause");
	return 0;
}
*/


// gộp dãy số theo thứ tự
/**
#include<bits/stdc++.h>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]){
	int i = 0, j = 0, k = 0;
	while (i < n1){
		arr3[k++] = arr1[i++];
	}
	while (j < n2){
		arr3[k++] = arr2[j++];
	}
	sort(arr3, arr3+n1+n2);   //sắp xếp
}

int main(){
	int m,n;
	cin >> m;
	int arr1[m];
	for (int i = 0; i < m; i++){
		cin >> arr1[i];
	}       // tại sao ???????? :D 
	cin >> n;
	int arr2[n];
	for (int i = 0; i < n; i++){
		cin >> arr2[i];
	}
	int arr3[m+n];
	mergeArrays(arr1, arr2, m, n, arr3);
	for (int i = 0; i < m+n; i++){
		cout << arr3[i] << " ";
	}
    return 0;
}
*/

// Tách từ
/*
#include<bits/stdc++.h>
using namespace std;

string standard_tring(string s){
	string result;
	if (s[0] >= 'A' && s[0] <= 'Z'){
		s[0] += 32;
	}
	for (int i = 0; i < s.length(); i++){
		if (s[i] >= 'A' && s[i] <= 'Z'){
			result = result + " " + char(s[i] + 32);
		}
		else{
			result = result + s[i];
		}
	}
	return result;
}
int main(){
	string s;
	cin >> s;
	string result = standard_tring(s);
	cout << "Ket qua tach tu:" << result << endl;
	return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int X(int n);
int Y(int n);

void inkq(int n, int arr[100]){
	for(int i = 0; i < n-1; i++){
		cout << arr[i] << ",";
	}
	cout << arr[n-1] << endl;
}
int tongday(int n, int arr[100]){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}
	return sum;
}
int X(int n){
	if (n < 5) 
	    return n;
	else
	    return Y(n-1) + X(n-2) + Y(n-3) + X(n-4);
}
int Y(int n){
	if (n < 5) 
	    return 2*n;
	else
	    return X(n-1) + Y(n-2) + X(n-3) + Y(n-4);
}
int main(){
	int n, x[100], y[100];
	int sumX, sumY;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++){
		x[i-1] = X(i);
		y[i-1] = Y(i);
	}
	cout << "Voi "<< n <<" phan tu, ta co:" << endl;
	cout << "day X la: ";
	inkq(n,x);
	sumX = tongday(n,x);
	cout << "day Y la: ";
	inkq(n,y);
	sumY = tongday(n,y);
	cout << "Tong day X la: " << sumX << endl;
	cout << "Tong day Y la: " << sumY << endl;
	return 0;
}
*/


/*
#include<stdio.h>
#include<math.h>

int main() {
	int a,b,c;
	double d,e;
	printf("nhap a,b,c: ");
	scanf("%d%d%d", &a,&b,&c);
	int dta = b*b - 4*a*c;
	if(dta < 0) {
		printf("phuong trinh %dx^2+%dx+%d=0 vo nghiem", a,b,c);
	}
	if(dta == 0) {
		d =(double) -b/(2*a);
		printf("phuong trinh %dx^2+%dx+%d=0 co nghiem kep x = %f", a,b,c,d);
	}
	if(dta > 0) {
		d = (1.0)*(-b+sqrt(b*b-4*a*c))/(2*a);
		e = (1.0)*(-b-sqrt(b*b-4*a*c))/(2*a);
		printf("phuong trinh %dx^2+%dx+%d=0 co 2 nghiem x1 = %f; x2 = %f", a,b,c,d,e);
	}
	return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
	int fact = 1;
	for (int i = 1; i <= n; i++) {
		fact = fact*i;
	}
	return fact;
}

int main() {
	double epsi;
	int x;
	cin >> epsi;
	cin >> x;
	int sign = -1, n = 0;
	double sum = 1;
	// cho n chạy từ 0 thì số hạng h[0] = (-1).3x = -3x
	double general_term = (2*n+3)*pow(x,2*n+1)/factorial(3*n+1);    
	while (general_term > epsi){
		sum += sign*general_term;
        sign = -sign;
		n++;
	}
    cout << "Tong day voi sai so la: " << sum << endl;
    return 0;
}
*/


// ma trận chuyển vị
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[100][100], b[100][100];
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	memset(b, 0, sizeof(b));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			b[j][i] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
*/
/*
#include <stdio.h>

int fn(int i){
	if (i > 3){
		return 0;
	}
	printf("\n%d", i);
	fn(i+1);
	printf("\nEnd of call where i = %d", i);
	return 0;
}
int main(){
	fn(1);
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next;
};

node *createNode(int x){
	node *temp = new node;
	temp->next = NULL;
	temp->data = x;
	return temp;
}

void printList(node *l){
	node *p = l;
	while(p != NULL){
		cout << p->data;
		p = p->next;
	}
}

node *addElement(node *p, int x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}

node *getNode(node *l, int k){
	node *p = l;
	for (int i = 0; i < k; i++){
		p = p->next;
	}
	return p;
}

int main(){
	int n,x,k;
	cin >> n >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p,x);
	}
	cin >> k;
	p = getNode(l,k);
	cout << p->data;
	return 0;
}
*/
/*
#include<iostream>

using namespace std;

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			cout << " A";
		}
		cout << endl;
	}
	return 0;
}
*/

// bài 2 chuỗi S,T  5.5
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char S[100], T[100];
	char mid[100];
	fflush(stdin);
	gets(S);
	fflush(stdin);
	gets(T);
	strcpy(mid, S);
	strcat(mid, T);
	int cnt[256] = {0};	
	for(int i = 0; i < strlen(mid); i++){
		cnt[mid[i]]++;	
	}
	for(int i = 0; i < 256; i++){
		if (cnt[i] > 0) printf("%c", i);
	}
	for(int i = 0; i < 256; i++){
		if (cnt[i] > 0) printf("\n%d", cnt[i]);
	}
	return 0;
}
*/
/*
#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int arr[n], sum = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("\nMang sau khi dao nguoc la: \n");
	for (int i = n-1; i >= 0; i--){
		printf("%d ", arr[i]);
	}
	printf("\n%d", sum);
	return 0;
}
*/


// bai 5.4
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[100], result[100];
	int n;
	fflush(stdin);
	gets(s);
	scanf("%d", &n);
    if (n <= strlen(s)) {
		strncpy(result, s+0, n);
	}
	result[n] = '\0';
	printf("\n%s", result);
    return 0;
}
*/

/*
#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    int arr[n];
    int count = 0, sum1 = 0, sum2 = 0;
    double tbc;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &arr[i]);
        if (arr[i] < 0){
            count++;
            sum2 += arr[i];
        }
        else sum1 += arr[i];
    }
    if (count == 0){
       printf("Mang khong co so am ");
       printf("%.6lf", sum1*1.0);
    } 
    else if (count == n) {
    	tbc = sum2/count;
        printf("%.6lf", tbc);
        printf(" Mang khong co so duong");
    }
    else {
    	tbc = sum2/count;
        printf("%.6lf", tbc);
        printf(" %.6lf", sum1*1.0);
    }
    return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>

void normalize(char inp[])
{
    int n = strlen(inp);
    for(int i = 0; i < n; i++){
        if(inp[i]==' '){
            for(int j=i;j<n-1;j++){
                inp[j] = inp[j+1];
            }
            inp[n-1]=NULL;
            i--;
            n--;
        }
        else break;
    }
     
    for(int i = n-1; i >= 0; i--){
        if(inp[i]==' '){
            inp[i] = NULL;
            n--;
        }
        else break;
    }
     
    for(int i = 1; i < n-1; i++){
        if(inp[i]==inp[i+1] && inp[i]==' '){
            for(int j = i; j < n-1; j++){
                inp[j] = inp[j+1];
            }
            inp[n-1]=NULL;
            i--;
            n--;
        }
    }
}

int main()
{
    char a[100];
    gets(a);
    normalize(a);
    puts(a);
    return 0;
}
*/





// #include<bits/stdc++.h>

// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// using namespace std;

// void prufer(){
// 	int v,e,label,k;
// 	cin >> label;  // the max_label
// 	// so that: 
// 		v = label+1;   // number of vertices
// 		e = v-1;       // number of egdes
// 	int edge[e][2], deg[label];
// 	memset(deg,0,label);
// 	for(int i = 0; i < e; i++){
// 		cin >> edge[i][0] >> edge[i][1];
// 			deg[edge[i][0]] ++;
// 			deg[edge[i][1]] ++;
// 	}
// 	for(int i = 0; i < v-2; i++){
//         int MIN = 10000;
// 		for(int j = 0; j < e; j++){
// 			if(deg[edge[j][0]] == 1){
// 				if(MIN > edge[j][0]){
// 					MIN = edge[j][0];
// 					k = j;
// 				}
// 			}
// 			if(deg[edge[j][1]] == 1){
// 				if(MIN > edge[j][1]){
// 					MIN = edge[j][1];
// 					k = j;
// 				}
// 			}
// 		}
// 		// remove vertice by making it's deg = 0
// 		deg[edge[k][0]]--;
// 		// decrease other ver's deg (after remove)
// 		deg[edge[k][1]]--;

// 		if(deg[edge[k][0]] == 0) 
// 			cout << deg[edge[k][1]] << " ";
// 		else cout << deg[edge[k][0]] << " ";
// 	}
// }	

// int main(){
// 	fast_cin();
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
// 	prufer();
// 	return 0;
// } 


// #include<iostream>
// #include<stdlib.h>
// #include<vector>
// #include<set>
// #include<map>

// #define ll long long
// ll N,u,v,remove,pair;

// using namespace std;

// vector<ll> deg(N+1,0);                  // store: deg
// vector<set<ll>> edge(N+1,set<ll>());    // store: v_friends (connect  _ex: 0 with 2,3)
// map<ll,set<ll>> grp;                    // store: group of vertices with a determined deg

// void pruferConstructor(){
// 	ll count = 0;   // count for removes => max: N-2;
// 	for(ll i=0; i < N; i++){   // N egde
// 		cin >> u >> v;
// 		deg[u]++; deg[v]++;
// 		// connect u and v
// 		edge[u].insert(v);
// 		edge[v].insert(u);
// 	}
// 	for(ll i=0; i < N+1; i++)  // N+1 vertices
// 	    grp[deg[i]].insert(i);    // some 

// 	while(grp[1].size() != 0){
// 		remove = *(mp[1].begin());
// 		pair = *(edge[remove].begin()); 
// 		if (remove != 0){
// 			// print prufercode:
// 			cout << pair << " ";

// 			grp[deg[pair]].erase(pair);  // deg -1
// 				--deg[pair];
// 			if(pair != 0){
// 				grp[deg[pair]].insert(pair);   // re-add 
// 			}
// 			// certainly:
// 			grp[1].erase(remove);     // delete 'remove' from group(deg=1)
// 			edge[pair].erase(remove);    // delete 'remove' from pair_friends  
// 		}
// 	}

// }
// int main(){
// 	cin >> N;
// 	pruferConstructor();
// 	return 0;
// }

// /* Ex: 
// // Tap hop cac canh - lien ket
// edge[0] = {2,3}
// edge[1] = {6}
// edge[2] = {0,4,6,9}
// edge[3] = {0}
// edge[4] = {2}
// edge[5] = {6}
// edge[6] = {2,1,5}
// edge[7] = {9}
// edge[8] = {9}
// edge[9] = {8,7,2}

// // Tap hop cac dinh(value dang set) theo deg
// grp[2] : {0}
// grp[1] : {1, 3, 4, 5, 7, 8}
// grp[4] : {2}
// grp[3] : {6,9}
// */

/*
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map <int ,int > deg;
    vector<vector<int> > edge(n+1);	
    for (int k = 0; k < n; k++) {
        int i, j;
		cin >> i >> j;
		deg[i]++; deg[j]++;
        edge[i].push_back(j); edge[j].push_back(i);
    }
while (deg.size()>2)
        for (int p = 1; p <= n; p++) {
            if (deg[p] == 1) {
                cout << edge[p][0] << " ";
                deg.erase(p);
                deg[edge[p][0]]--;
                edge[edge[p][0]].erase(find(edge[edge[p][0]].begin(), edge[edge[p][0]].end(), p));
                break;
            }
            if (deg[p] == 0) deg.erase(p);
        }
    return 0;
}
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char palette[6][10];
void taomau(char palette[][10]){
    strcpy(palette[0], "red");
    strcpy(palette[1], "green");
    strcpy(palette[2], "blue");
    strcpy(palette[3], "yellow");
    strcpy(palette[4], "brown");
    strcpy(palette[5], "pink");
}

int main(){
    taomau(palette);
    FILE* f=fopen("dothi.txt","r");
    if(f==NULL){
        cout<<"Không mở được tệp";
        return 1;
    }
    int n,m;
    fscanf(f,"%d %d", &n, &m);
    vector<vector<int> > graph(n);
    pair<int,int> edge[m];
    for (int v = 0; v < m; v++) {
        fscanf(f, "%d %d", &edge[v].first, &edge[v].second);
        cout <<edge[v].first<< " " <<edge[v].second<< endl;
        graph[edge[v].first-1].push_back(edge[v].second-1);
        graph[edge[v].second-1].push_back(edge[v].first-1);
    }
    vector<int> colors(n, -1); \
    for (int v = 0; v < n; v++) {
        vector<bool> available(n, true);
        for (int neighbor : graph[v]) {
            if (colors[neighbor] != -1) {
                available[colors[neighbor]] = false;
            }
        }
        int color;
        for (color = 0; color < n; color++) {
            if (available[color]) {
                break;
            }
        }
        colors[v] = color;
    }
    for (int v = 0; v < n; v++) {
        cout << "Đỉnh " << v+1 << " được tô màu " << colors[v] << endl;
    }
    fclose(f);
    FILE* f1=fopen("dothitomau.dot","w");
    fputs("graph dothi\n{\n",f1);
    for(int v=0;v<n;v++){
        fprintf(f1, "  %d [fillcolor=\"%s\", style=filled];\n", v + 1, palette[colors[v]]);
    }
    for(int v=0;v<m;v++){
       fprintf(f1,"  %d--%d;\n",edge[v].first,edge[v].second);
    }
    fputs("}",f1);
    fclose(f1);
    return 0;
}










