//bài test

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int number, count = 0;
	cin >> number;
    if(number % 10 == 0)
        cout << "INVALID, please re-enter" << endl;    	
    int Bnumber = number;
	while(Bnumber != 0){
		Bnumber /= 10;
		++count;      
	}
	int p = count - 1;
	int reverse = 0;
	int Fnumber = number;
	while(Fnumber != 0){
	    reverse += (Fnumber % 10)*pow(10,p);
	    p--;
  	    Fnumber /= 10;
    }
	if(reverse == number){
		cout << ""<< number<<" is palindrome" << endl;
	}
	else cout << ""<< number<<" is not a palindrome" << endl;	
	system("pause");
	return 0;	
}

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