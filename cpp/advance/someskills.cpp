// KỸ THUẬT 1:  SỬ DỤNG 2 CON TRỞ (TWO POINTERS) tập trung cho mảng và chuỗi

// P1: 1 ĐỐI TƯỢNG LẶP
// fake code:
/*
function fn(arr):
   left = 0
   right = arr.length - 1
   while left < right:
      do some logic here depending on the problem
	  do some more logic here to decide one of the following:
	      1. left++
		  2. right++
		  3. both left++ and right++
*/

//VD1: check chuỗi palindrome
/*
#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome (string s){
	int left = 0;
	int right = s.size() - 1;
	while (left < right){
		if (s[left] != s[right]){
			return false;
		}
		left++;
		right--;
	}
	return true;
}
int main(){
	string s;
	cin >> s;
	if (checkPalindrome(s) == true) cout << "TRUE";
	else cout << "FALSE";
	return 0;
}
*/

//VD2: Cho mảng đã sắp xếp, trả về true nếu tồn tại 1 cặp có tổng = 1 số targer cho trước
/*
#include<bits/stdc++.h>
using namespace std;

bool checkForTarget(vector<int>& nums, int target){
    int left = 0; 
    int right = nums.size() - 1;
    while (left < right) {
        int curr = nums[left] + nums[rights];
        if (curr == target){
            return true;
        }
        if (curr > target){
            right--;
        }
        else left++;
    }
    return false;
}
*/

//VD3: Đảo ngược chuỗi:
/*
#include<iostream>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int i = 0;
    int j = s.size() - 1;
    while (i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    cout << "Chuoi sau khi dao nguoc la:" << s << endl;
    return 0;
}
*/


//P2: 2 ĐỐI TƯỢNG LẶP 
/* Sử dụng 2 biến i và j với cách làm như sau:
   + tạo 2 con trỏ cho 2 vòng lặp, bắt đầu ở chỉ số đầu tiên
   + sử dụng vòng lặp while cho đến khi 1 trong 2 con trỏ đã di chuyển đến chỉ số cuối
   + tại mỗi lần lặp, di chuyển con trỏ về phía trước
   + di chuyển con trỏ còn lại đến chỉ số cuối đối tượng lặp của nó 
*/
// fake code:
/*
function fn(arr1, arr2):
    i = j = 0;
    while i < arr1.length AND j < arr2.length:
       do some logic here depending on the problem
	   do some more logic here to decide one of the following:
           1. i++
           2. j++
           3. both i++ and j++
    while i < arr1.length:
       do some logic here depending on the problem
       i++
    while j < arr2.length:
       do some logic here depending on the problem
       j++
*/

//VD4: Cho 2 mảng đã sắp xếp, trộn 2 mảng&trả về mảng mới cũng được sắp xếp
/*
#include<bits/stdc++.h>
using namespace std;

vector<int> combine(vector<int>& arr1, vector<int>& arr2){
    vector<int> ans;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()){
        if (arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()){
        ans.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()){
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
}
int main(){
    vector<int> a1 = {1,3,6,8,12};
    vector<int> a2 = {2,4,5,7};
    vector<int> a;
    a = combine(a1,a2);
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << "\t";
    }
    return 0;
}
*/

// VD5: Kiểm tra chuỗi con: s có là chuỗi con của t?
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        
        return i == s.size();
    }
};

int main(){
    Solution sl;
    string s,t;
    cin >> s;
    cin >> t;
    cout << sl.isSubsequence(s,t);
    return 0;
}
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s="A";
	int n;
	cin >> n;
	for (int i=0;;i++)
	{
		if (i%80000000==0)
		{
			for (int j=0; j<n;j++)
			{
				for (int l=0;l<j;l++)
				{
					cout << " ";
				}
				for (int k=n;k>j;k--)
				{
					cout << s;
				}
				cout << endl;
			}
		
		}
		if (i%80000000==19999999)
			system("cls");
		if (i%80000000==20000000)
		{
			for (int j=0; j<n;j++)
			{
				for (int l=0;l<2*n-j;l++)
				{
					cout << " ";
				}
				for (int k=0;k<j;k++)
				{
					cout << s;
				}
				cout << endl;
			}
		}
		if (i%80000000==39999999)
			system("cls");
		if (i%80000000==40000000)
		{
			for (int j=0;j<n;j++)
			{
				cout << endl;
			}
			for (int j=0; j<n;j++)
			{
				for (int l=0;l<n;l++)
				{
					cout << " ";
				}
				for (int l=0;l<j;l++)
				{
					cout << s;
				}
				for (int k=0;k<n-j;k++)
				{
					cout << " ";
				}
				cout << endl;
			}
		}
		if (i%80000000==59999999)
			system("cls");
		
		if (i%80000000==60000000)
		{
			for (int j=0;j<n;j++)
			{
				cout << endl;
			}
			for (int j=0; j<n;j++)
			{
				for (int l=0;l<n-j;l++)
				{
					cout << s;
				}
				for (int k=0;k<j;k++)
				{
					cout << " ";
				}
				cout << endl;
			}
		}
		
		if (i%80000000==79999999)
			system("cls");
	}
}


