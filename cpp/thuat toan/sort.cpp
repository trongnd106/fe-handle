// 1. SELECTION SORT
/*
#include <bits/stdc++.h>

using namespace std;

void selectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int min_pos = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[min_pos]){
                min_pos = j;
            }
        }
        swap(a[i], a[min_pos]);
    }
}

int main(){
    int a[1000], n;
    cin >> n;
    for (int i=0; i < n;i++){
        cin >> a[i];
    }
    selectionSort(a,n);
    for (int i=0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
*/

// QUICK SORT 

#include<bits/stdc++.h>

using namespace std;

int partition(int A[], int L, int R, int pivotIndex){
    int pivot = A[pivotIndex];
    swap(A[pivotIndex], A[R]);
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        if(A[i] < pivot){
            swap(A[storeIndex], A[i]);
            storeIndex++;
        }
    }
    swap(A[storeIndex], A[R]);
    return storeIndex;
}

void quickSort(int A[], int L, int R){
    if(L < R){
        int index = (L+R)/2;
        index = partition(A,L,R,index);
        if(L < index)
            quickSort(A, L, index-1);
        if(index < R)
            quickSort(A, index+1, R);
    }
}
