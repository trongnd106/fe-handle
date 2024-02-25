/*
#include <iostream>
using namespace std;
int main() {
  int i = 20;
  int& iRef = i;      //tham chiếu iRef 
  std::cout << "i: " << i << std::endl;
  std::cout << "iRef: " << iRef << std::endl;
  
  std::cout << std::endl;

  iRef = 30; //Thay đổi tham chiếu

  std::cout << "i: " << i << std::endl;
  std::cout << "iRef: " << iRef << std::endl;
  system ("pause");
}
*/

// ví dụ về tham chiếu
// #include <bits/stdc++.h>
// using namespace std;

// void change(int& x, int& y){
// 	x += y;
// 	y -= 1;
// }

// int main(){
// 	int x = 10, y = 15;
// 	cout << x << endl;
// 	cout << y << endl;
// 	change (x, y);
// 	cout << x << endl;
// 	cout << y << endl;
// 	system("pause");
// 	return 0;
// }

// #include <iostream>

// using namespace std;
// //Định nghĩa hàm
// void passPointer(int *number) {
//   //Nhân giá trị số với 10
//   *number = *number * 10;
//   cout << "Value of number inside the function = " << *number << endl;
// }

// int main() {
//   //Khởi tạo biến
//   int num = 10;
//   cout << "Value of number before function call = " << num << endl;
//   //Gọi hàm
//   passPointer(&num);  //gọi hàm truyền vào con trỏ địa chỉ biến num thông qua toán tử &
//   cout << "Value of number after function call = " << num << endl;
//   system("pause");
//   return 0;
// }

// #include <iostream>

// using namespace std;

// // định nghĩa cấu trúc
// struct Student {
//   string name;        //khai báo từng biến thành viên
//   int roll_number;
//   int marks;
// };

// // định nghĩa hàm, nhận vào 1 giá trị kiểu string, 2 giá trị kiểu int
// Student fillStudent(string name, int roll_number, int marks) {     //hàm nhập vào
//   Student s;
//   s.name = name;
//   s.roll_number = roll_number;
//   s.marks = marks;
//   return s;       //trả về s
// }
// // định nghĩa hàm in ra thông tin từ cấu trúc
// void printStudent(struct Student s) {

//   cout << "Student information" << endl;
//   cout << "Name = " << s.name << endl;
//   cout << "Roll Number = " << s.roll_number << endl;
//   cout << "Marks = " << s.marks << endl;

// }

// int main() {
//   struct Student s[100];     //khai báo mảng cấu trúc + cấp phát bộ nhớ

//   s[0] = fillStudent("John", 1, 50);      //hàm nhập
//   printStudent(s[0]);                     //hàm in

//   s[1] = fillStudent("Alice", 2, 43);
//   printStudent(s[1]);
//   system("pause");
//   return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// class Collector {
//   int * list;
//   int size;
//   int capacity;

//   public:
//   Collector(){
//     list = nullptr;
//     size = 0;
//     capacity = 0;
//   }
  
//   Collector(int cap){
//     capacity = cap;
//     size = 0;
//     list = new int[capacity];
//   }

//   bool append(int v){
//     if (size < capacity) {
//       list [ size++ ] = v;
//       return true;
//     }
//     return false;
//   }

//   void dump(){ 
//     for(int i = 0 ; i < size ; i++) {
//       cout << list[i] << " ";
//     }
//     cout << endl;
//   }
  
//   ~Collector(){
//     cout << "Deleting the object " << endl;
//     if (capacity > 0)
//       delete[] list; 
//   }
// };

// int main(){  
//   Collector c(10); 
//   for (int i = 0 ; i < 15 ; i++){
//     cout << c.append(i) << endl;
//   }
//   system ("pause");
// }


// #include <iostream>
// #include <string>

// using namespace std;
// // định nghĩa class
// class Ball{
//   double radius;    //2 biển thành viên ở trong vùng private
//   string color;
  
//   public:
//   Ball(){           //hàm tạo mặc định 
//     radius = 0;     //giá trị mặc định
//     color = "";     //giá trị mặc định
//   }
  
//   Ball(double r, string c){        // hàm tạo chứa 2 tham số
//     radius = r;            //giá trị biến TV = nhập từ bf
//     color = c;
//   }
  
//   void printVolume();       //hàm thành viên 
//   void printRadius();
//   // gọi hàm bạn: setRadius kiểu trả về là void, hàm bạn của class Ball, truyền vào tham số thực r
//   friend void setRadius(Ball &b, double r); 
    
// };

// // truy cập vào hàm printVolume = toán tử truy cập phân giải phạm vi
// void Ball::printVolume(){
//   cout << (4/3) * 3.142 * radius * radius * radius << endl;    //công thức thể tích
// }

// //truy cập vào hàm printRadius
// void Ball::printRadius(){                       
//   cout << radius << endl;             // xuất ra bán kính
// }

// // sử dụng hàm bạn để truy cập vào biến radius ở vùng private
// void setRadius(Ball &b, double r){          
//   b.radius = r;
// }

//  int main(){
//   // tạo đối tượng b từ hàm tạo 2 biến, khởi tạo luôn
//    Ball b(30, "green");
//    cout << "Radius: ";
//   // gọi hàm print -> xuất ra bán kính
//    b.printRadius();
//   // gọi hàm setRadius -> tác động vào biến TV radius ở vùng private
//    setRadius(b, 60);     // thay đổi giá trị radius = 60
//    cout << "New radius: ";
//    // gọi hàm print -> xuất ra bán kính lúc sau
//    b.printRadius();   
//    cout << "Volume: ";
//    // gọi hàm in ra thể tích lúc sau
//    b.printVolume();
//    system ("pause");
//    return 0;
//  }

// #include <iostream>
// using namespace std;

// class Movie{
//   private:
//     string title;
//     int year;
//     string genre;
//   public:
//     Movie(){
//       title = " ";
//       year = -1;
//       genre = " ";
//     }
//     Movie(string t, int y, string g){
//       title = t;
//       year = y;
//       genre = g;
//     }
//     string getTitle(){
//       return title;
//     }
//     void setTitle(string t){
//       title = t;
//     }
//     int getYear(){
//       return year;
//     }
//     void setYear(int y){
//       year = y;
//     }
//     string getGenre(){
//       return genre;
//     }
//     void setGenre(string g){
//       genre = g;
//     }
//     void printDetails(){
//       cout << "Title: " << title << endl;
//       cout << "Year: " << year << endl;
//       cout << "Genre: " << genre << endl;
//     }
// };
// int main(){
//   cout << "BEST MOVIE FOR 20 YEARS" << endl;
//   cout << "1. The first " << endl;
//   Movie m("The Lion King", 2004, "Adventure");
//   m.printDetails();
//   cout << "2. The second" << endl;
//   m.setTitle("Anabelle");
//   m.setYear(2006);
//   m.setGenre("Horror");
//   cout << "Title: " << m.getTitle() << endl;
//   cout << "Year: " << m.getYear() << endl;
//   cout << "Genre: " << m.getGenre() << endl;
//   system ("pause");
//   return 0;
// }


// tính kế thừa
// #include <iostream>
// #include <cstring>
// using namespace std;

// //tạo 1 lớp vehicles với các thuộc tính và phương thức cơ bản
// class Vehicles {
//   protected:
//     string make;
//     string color;
//     int year;
//     string model;
//   public:
//     Vehicles(){
//       make = " ";
//       color = " ";
//       year = 0;
//       model = " ";
//     }
//     Vehicles(string mk, string col, int yr, string mdl){
//       make = mk;
//       color = col;
//       year = yr;
//       model = mdl;
//     }
//     void print_details(){
//       cout << "Manufacturer: " << make << endl;
//       cout << "Color: " << color << endl;
//       cout << "Year: " << year << endl;
//       cout << "Model: " << model << endl;
//     }
// };
// //định nghĩa lớp dẫn xuất cars được kế thừa từ lớp cơ sở vehicles
// class Cars : public Vehicles {
//     string trunk_size;    //bổ sung biến thành viên
//   public:
//     Cars(){
//       trunk_size = " ";    //bổ sung
//     }
//     Cars(string mk, string col, int yr, string mdl, string ts)
//     : Vehicles(mk, col, yr, mdl){    //chế độ kế thừa 
//         trunk_size = ts;
//       }
//     void printCar_details(){
//       print_details();
//       cout << "Trunk size: " << trunk_size << endl;
//     }
// };
// // định nghĩa lớp dẫn xuất Ships được kế thừa từ lớp cơ sở Vehicles
// class Ships : public Vehicles {
//     int number_of_anchors;    //bổ sung
//   public:
//     Ships(){
//       number_of_anchors = 0;    // bổ sung
//     }
//     Ships(string mk, string col, int yr, string mdl, int na)
//     : Vehicles(mk, col, yr, mdl){     //chế độ kế thừa
//         number_of_anchors = na;
//       }
//     void printShip_details(){
//       print_details();
//       cout << "Number of anchors: " << number_of_anchors << endl;
//     }
// };
// int main(){
//   cout << "This car's information: " << endl;
//   // tạo object car, khởi tạo thông tin
//   Cars car("Chevloret", "Black", 2010, "Camaro", "9.1 cubic feet");
//   car.printCar_details();
//   cout << "\nThis ship's information: " << endl;
//   // tạo object ship, khởi tạo thông tin
//   Ships ship("Harland and Wolff, Belfast", "Black and white", 1912, "RMS Titanic", 3);
//   ship.printShip_details();
//   system("pause");
//   return 0;
// }

// //đa kế thừa
// #include <iostream>
// #include <string>
// using namespace std;

// class Vehicle {
//   protected:
//     string make;
//     string color;
//     int year;
//     string model;
//   public:
//     Vehicle(){
//       make = " ";
//       color = " ";
//       year = 0;
//       model = " ";
//     }
//     Vehicle(string mk, string cl, int yr, string md){
//       make = mk;
//       color = cl;
//       year = yr;
//       model = md;
//     }
//     void printVehicle_details(){
//       cout << "Make: " << make << endl;
//       cout << "Color: " << color << endl;
//       cout << "Year: " << year << endl;
//       cout << "Model: " << model << endl;
//     }
// };
// class Car {
//     string trunk_size;
//   public:
//     Car(){
//       trunk_size = " ";
//     }
//     Car(string ts){
//       trunk_size = ts;
//     }
//     void printCar_details(){
//       cout << "Trunk size: " << trunk_size << endl;
//     }
// }; 
// class Tek : public Car, public Vehicle {
//     int top_speed;
//   public:
//     Tek(){
//       top_speed = 0;
//     }
//     Tek(string mk, string cl, int yr, string md, string ts, int tp)
//     :Vehicle (mk, cl, yr, md), Car(ts) {
//       top_speed = tp;
//     }
//     void printTek_details(){
//       printVehicle_details();
//       printCar_details();
//       cout <<"Top speed of the car: " << top_speed << endl;
//     }
// };
// int main(){
//   Tek SuperCar("Tek", "Black", 2006, "Accord", "14.7 cubic feet", 260);
//   cout << "This information";
//   SuperCar.printTek_details();
//   system("pause");
//   return 0;
// }

/*
// tính đa hình
#include<iostream>
using namespace std;

class Shape {
  public:
    float getArea(){}
};
class Rectangle : public Shape {
  private:
    float width;
    float height;
  public:
    Rectangle(float wid, float hei){
      width = wid;
      height = hei;
    }

    float getArea(){
      return width*height;
    }
};
class Circle : public Shape {
  private:
    float radius;
  
  public:
    Circle (float rd){
      radius = rd;
    }
    float getArea(){
      return 3.14159f*radius*radius;
    }
};
int main(void) {
  Rectangle r(2,6);
  //tham chiếu lớp Shape tới đối tượng rectangle
  Shape* shape = &r;      //khai báo con trỏ, trỏ tới địa chỉ của r

  cout << "Calling Rectangle getArea function: " << r.getArea() << endl;
  cout << "Calling Rectangle from shape pointer: " << shape -> getArea() << endl;
  Circle c(5);
  //tham chiếu lớp Shape tới đối tượng circle
  shape = &c;    

  cout << "Calling Circle getArea function: " << c.getArea() << endl;
  cout << "Calling Circle from pointer: " << shape -> getArea() << endl;
system("pause");
  return 0;
  }
*/


//nhân hai ma trận
/*
#include <iostream>

using namespace std;
// điều kiện để 2 ma trận nhân được với nhau là số cột của mt1 = số hàng của mt2;
void multiplication(int arr1[][2], int row1, int col1, int arr2[][2], int row2, int col2, int result[][2]) {
  if (col1 == row2) {
    for (int x = 0; x < row1; x++) {
      for (int y = 0; y < col2; y++) {
        for (int z = 0; z < col1; z++) {
          result[x][y] = result[x][y] + arr1[x][z] * arr2[z][y];
        }
      }
    }
  }
  else{
    for (int x = 0; x < row1; x++) {
      for (int y = 0; y < col2; y++) {
        result[x][y] = -1;
      }
    }
  } 
}

void print_array(int arr[3][2], int row, int column) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int arr1[3][2] = {{1,2},{3,4},{5,6}};
  int arr2[2][2] = {{10,20},{30,40}};
  int result[3][2] = {{0,0},{0,0},{0,0}};
  multiplication(arr1, 3, 2, arr2, 2, 2, result);
  print_array(result, 3, 2);
  system("pause");
  return 0;
}
*/


