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