// ----------------- V E C T O R ----------------
// 1. MODIFIERS
/*
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 
   
int main() 
{ 
    // Assign vector 
    vector<int> vec; 
   
    // fill the array with 12 seven times 
    vec.assign(7, 12);            // vec = {12,12,12,12,12,12,12}
   
    cout << "The vector elements are: "; 
    for (int i = 0; i < 7; i++) 
        cout << vec[i] << " "; 
   
    // inserts 24 to the last position 
    vec.push_back(24);     // 12 12 12 12 12 12 12 24
    int s = vec.size();     // 8
    cout << "nThe last element is: " << vec[s - 1];    // 24
 
     // prints the vector 
    cout << "nThe vector elements after push back are: ";   
    for (int i = 0; i < vec.size(); i++) 
        cout << vec[i] << " "; 
   
    // removes last element   
    vec.pop_back();      // delete 24
   
    // prints the vector 
    cout << "nThe vector elements after pop_back are: "; 
    for (int i = 0; i < vec.size(); i++) 
        cout << vec[i] << " "; 
   
    // inserts 10 at the beginning 
    vec.insert(vec.begin(), 10);      // 10 12 12 12 12 12 12 12 
   
    cout << "nThe first element after insert command is: " << vec[0];   // 10
   
    // removes the first element 
    vec.erase(vec.begin());    //delte 10
   
    cout << "nThe first element after erase command is: " << vec[0];    // 12
   
    // inserts at the beginning 
    vec.emplace(vec.begin(), 5);      // 5 12 12 12 12 12 12 12 
    cout << "nThe first element emplace is: " << vec[0];    // 5 
   
    // Inserts 20 at the end 
    vec.emplace_back(20);      // 5 12 12 12 12 12 12 12 20
    s = vec.size();        //9
    cout << "nThe last element after emplace_back is: " << vec[s - 1];    // 20
   
    // erases the vector 
    vec.clear();     
    cout << "nVector size after clear(): " << vec.size();     // 0
   
    // two vector to perform swap 
    vector<int> obj1, obj2; 
    obj1.push_back(2);   
    obj1.push_back(4);     // 2 4 
    obj2.push_back(6); 
    obj2.push_back(8);      // 6 8 
   
    cout << "nnVector 1: "; 
    for (int i = 0; i < obj1.size(); i++) 
        cout << obj1[i] << " ";     // 2 4 
   
    cout << "nVector 2: "; 
    for (int i = 0; i < obj2.size(); i++) 
        cout << obj2[i] << " ";      // 6 8
   
    // Swaps obj1 and obj2 
    obj1.swap(obj2); 
   
    cout << "nAfter Swap nVector 1: "; 
    for (int i = 0; i < obj1.size(); i++) 
        cout << obj1[i] << " ";       // 6 8 
   
    cout << "nVector 2: "; 
    for (int i = 0; i < obj2.size(); i++) 
        cout << obj2[i] << " ";       // 2 4 
}
*/
/*
#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vec1;
    for (int i=0; i<10; i++){
        vec1.push_back(i);
    }
    cout << "Understanding: " << endl;
    for(auto i = vec1.begin(); i != vec1.end(); i++){
        cout << *i << " ";
    }
    return 0;
}
*/



// 2. ITERATOR
/*
// C++ program to illustrate the 
// iterators in vector 
#include <iostream> 
#include <vector> 

using namespace std; 

int main() 
{ 
    vector<int> g1; 

    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 

    cout << "Output of begin and end: "; 
    for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " "; 

    cout << "nOutput of cbegin and cend: "; 
    for (auto i = g1.cbegin(); i != g1.cend(); ++i) 
        cout << *i << " "; 

    cout << "nOutput of rbegin and rend: "; 
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
        cout << *ir << " "; 

    cout << "nOutput of crbegin and crend : "; 
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir) 
        cout << *ir << " "; 

    return 0; 
}
*/


/*
// CPP program to illustrate working of crbegin()  
// crend() 
#include <iostream> 
#include <vector> 
using namespace std; 

int main () 
{ 
  // initializing vector with values 
  vector<int> vect = {10, 20, 30, 40, 50}; 

  // for loop with crbegin and crend 
  for (auto i = vect.crbegin(); i != vect.crend(); i++) 
    cout << ' ' << *i;  //printing results 

  cout << 'n'; 
  return 0; 
}
*/


 
// 3. CAPACITY
/*
#include <iostream> 
#include <vector> 
   
using namespace std; 
   
int main() 
{ 
    vector<int> vec1; 
   
    for (int i = 1; i <= 10; i++) 
        vec1.push_back(i); 
   
    cout << "Size of our vector: " << vec1.size(); 
    cout << "nCapacity of our vector: " << vec1.capacity(); 
    cout << "nMax_Size of our vector: " << vec1.max_size(); 
   
    // resizes the vector size to 4 
    vec1.resize(4); 
   
    // prints the vector size after resize() 
    cout << "nSize of our vector after resize: " << vec1.size(); 
   
    // checks if the vector is empty or not 
    if (vec1.empty() == false) 
        cout << "nVector is not empty"; 
    else
        cout << "nVector is empty"; 
   
    return 0; 
}
*/
   




// 4. ELEMENT ACCESS
/*
// C++ program to illustrate the 
// element accesser in vector 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    vector<int> g1; 
  
    for (int i = 1; i <= 10; i++) 
        g1.push_back(i * 10); 
  
    cout << "nReference operator [g] : g1[2] = " << g1[2]; 
  
    cout << "nat : g1.at(4) = " << g1.at(4); 
  
    cout << "nfront() : g1.front() = " << g1.front(); 
  
    cout << "nback() : g1.back() = " << g1.back(); 
  
    // pointer to the first element 
    int* pos = g1.data(); 
  
    cout << "nThe first element is " << *pos; 
    return 0; 
}
*/


#include<iostream>
#include<vector>

int main(){
    std::vector<bool> array = {true, false, false, true, true};
    std::cout << "The length is: " << array.size() << '\n';
    for (int i : array)
       std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}