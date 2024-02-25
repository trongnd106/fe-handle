/*
#include<bits/stdc++.h>
using namespace std;

class Teacher;     //tiền khai báo class
class Student;    

class Student {
    private: 
        string ID;
        string name;
        string year;
        double GPA;
        static int count;     //biến static 
    public:
    // hàm tạo mặc định
        Student(){
            ID = " ";
            name = " ";
            year = " ";
            GPA = 0.0;
        }
    // hàm tạo 4 tham số
        Student(string i, string n, string y, double g){
            ID = i;
            name = n;
            year = y;
            GPA = g;
        }
    // 4 hàm thành viên
        void GetInfo();     //nhập thông tin
        void printInfo();   //in thông tin
        void increaseCount();   //tăng đếm
        int getCount();    //nhận đếm
     //   friend void coutInfo(Student);
        friend void normalize(Student&);    //chuẩn hoá tên
        friend class Teacher;      //khai báo lớp friend
};
// khởi tạo giá trị của biến static ở ngoài
int Student::count = 0;
void Student::increaseCount(){
    count++;       //tăng đếm
}
int Student::getCount(){
    return count;        //trả về giá trị của đếm
}
// void coutInfo(Student a){
//     cout << a.ID << " " << a.name;
// }
void normalize(Student &a){         //NguYeN   vAn  aN  -> Nguyen Van An
    string res = " ";
    stringstream ss(a.name);     //truy cập trực tiếp vào biến name
    string token;   
    while (ss >> token){
        res += toupper(token[0]);
        for(int i = 1; i < token.length(); i++){
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1); 
    a.name = res; 
}
void Student::GetInfo(){
    ++count;    //count  = 1
    this->ID = "SV" + string(3-to_string(count).length(), '0') + to_string(count);   //SV001  
    //count = 1 -> "1", có độ dài = 1, và sẽ tạo ra "00" bằng cách 3 - 1 còn 2 chữ số và cho toàn bộ 2 cs đó = '0'
    getline(cin, this->name);
    cin >> this->year;
    cin >> this->GPA;
    cin.ignore();
}
void Student::printInfo(){
    cout << fixed << setprecision(3) << this->ID << endl;
    cout << "Name: " << this->name << endl;
    cout << "Birthday: " << this->year << endl;
    cout << "Result: " << this->GPA << endl;
}

class Teacher {
    private:
       string exper;
    public:
       void update(Student&);
};
void Teacher::update(Student &x){
    x.GPA = 3.20;
}

int main(){
    // Student sd1;
    // cout << "Monitor's Infomation" << endl;
    // sd1.GetInfo();
    // sd1.printInfo();
    // Student sd2;
    // cout << "\nGroup 1's leader" << endl;
    // sd2.GetInfo();
    // sd2.printInfo();
    Student x;
    x.GetInfo();
    normalize(x);
    Teacher y;
    y.update(x);
    x.printInfo();
    // coutInfo(a);
    system("pause");
    return 0;
}
*/



//nạp chồng toán tử
/*
#include <bits/stdc++.h>
using namespace std;

class Student {
    private: 
        string ID;
        string name;
        string year;
        double GPA;
        static int count;
    public:
        friend istream& operator >> (istream &in, Student& a);   //cú pháp
        friend ostream& operator << (ostream &out, Student a);   
        friend bool operator < (Student a, Student b);
};

bool operator < (Student a, Student b){
    return a.GPA < b.GPA;
}

istream& operator >> (istream &in, Student& a){
    cout << "Nhap ID: ";
    in >> a.ID;
    cout << "Nhap ten: "; in.ignore();
    getline(cin, a.name);
    cout << "Nhap ngay sinh: "; in >> a.year;
    cout << "Nhap diem: "; in >> a.GPA;
    return in;
}

ostream& operator << (ostream &out, Student a){
    out << a.ID << " " << a.name << " " << a.year << " " << fixed << setprecision(2) << a.GPA << endl;
    return out;
}

int main(){
    int n; 
    cin >> n;
    Student a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(Student x : a){
        cout << x;
    }
    system("pause");
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

class SoPhuc{
    private:
        int thuc, ao;
    public:
        friend istream& operator << (istream& in, SoPhuc &a);
        friend ostream& operator << (ostream& out, SoPhuc a);
        SoPhuc operator + (SoPhuc another);
        Sophuc operator - (Sophuc another);
};
istream& operator << (istream& in, SoPhuc &a){
    in >> a.thuc >> a.ao;
    return in;
}
ostream& operator << (ostream& out, SoPhuc a){
    out << a.thuc <<" "<< a.ao;
    return out;
}
SoPhuc SoPhuc::operator + (SoPhuc another){
    SoPhuc tong;
    tong.thuc = this->thuc + another.thuc;
    tong.ao = this->ao + another.ao;
    return tong;
}
SoPhuc SoPhuc::operator - (SoPhuc another){
    SoPhuc hieu;
    hieu.thuc = this->thuc - another.thuc;
    hieu.ao = this->ao - another.ao;
    return hieu;
}
int main(){
    SoPhuc a, b;
    cin >> a >> b;
    SoPhuc tong =  a + b;
    SoPhuc hieu = a - b;
    cout << tong << endl;
    cout << hieu << endl;
    system("pause");
    return 0;
}
*/


/*
//quan hệ hợp thành (composition) -> part-of
#include<bits/stdc++.h>
using namespace std;

class Engine{    //động cơ
    private:
        int capacity;
    public:
        Engine(){
            capacity = 0;
        }
        Engine(int cap){
            capacity = cap;
        }
        void Engine_details(){
            cout << "Engine details: " << capacity << endl;
        }
};
class Tyres {
    private: 
        int no_of_tyres;
    public:
        Tyres(){
            no_of_tyres = 0;
        }
        Tyres(int nt){
            no_of_tyres = nt;
        }
        void Tyres_details(){
            cout << "Number of tyres: " << no_of_tyres << endl;
        }
};
class Doors {
    private:
        int no_of_doors;
    public:
        Doors(){
            no_of_doors = 0;
        }
        Doors(int nd){
            no_of_doors = nd;
        }
        void Doors_details(){
            cout << "Number of doors: " << no_of_doors << endl;
        }
};
class Car {
    protected:
        Engine EObj;
        Tyres TObj;
        Doors DObj;
    private:
        string color;
    public:
        Car(Engine eng, Tyres tr, Doors dr, string col)
          : EObj(eng), TObj(tr), DObj(dr) {
            color = col;
          }     
        void Car_details(){
            EObj.Engine_details();
            TObj.Tyres_details();
            DObj.Doors_details();
            cout << "Car color: " << color << endl;
        }   
};

int main(){
    Engine EObj(1600);
    Tyres TObj(4);
    Doors DObj(4);
    Car CObj(EObj, TObj, DObj, "Black");
    CObj.Car_details();
    system("pause");
    return 0;
}
*/

//quan hệ tập hợp(aggregation)  -> Has-A
/*
#include<bits/stdc++.h>
using namespace std;

class Country{
    private:
        long population;
        string name;
    public:
        Country(long pl, string n){
            population = pl;
            name = n;
        }
        string getName(){
            return name;
        }
};
class Person{
    private:
        string name;
        Country* country;
    public:
        Person(string n, Country* c){
            name = n;
            country = c;
        }
        void print_details(){
            cout << "Name of person: " << name << endl;
            cout << "Nationality: " << country->getName() << endl;
        }
};
int main(void){
    Country* country = new Country(125083164,"Vietnam");
    {
        Person user("Nguyen Dat Trong", country);
        user.print_details();
    }
    //thời gian tồn tại của đối tượng user kết thúc
    cout << country->getName() << endl;      //đối tượng country vẫn tồn tại
    system("pause");
    return 0;
}
*/


//quan hệ liên kết (association)
#include <bits/stdc++.h>
using namespace std;

class Teacher;     //tiền khai báo
 
class Student {
private:
	string Std_name;
	vector<Teacher *> tr;     //kt sử dụng vector
	void addTeacher(Teacher * teach);   
 
public:
	Student(string name) {        //hàm tạo 1 tham số
		 Std_name = name;
	}
 
	string getName() const {       //hàm thành viên get
         return Std_name; 
    }
  // nạp chồng toán tử cout << 
  	friend ostream& operator<<(ostream &out, const Student &std);
  // định nghĩa lớp bạn
	friend class Teacher;
};
 
class Teacher {
private:
	string tr_name;
	vector<Student *> stdnt;
 
public:   
 	Teacher (string name) {     //hàm tạo 1 tham số
		tr_name = name;
	}
 
	void addStudent(Student *st) {
		//Thêm học sinh vào khóa học
		stdnt.push_back(st);
		
		//Kết nối với giáo viên
		st->addTeacher(this);
	}
	// nạp chồng toán tử (overload operator)
	friend ostream& operator<<(ostream &out, const Teacher &tchr) {
		int length = tchr.stdnt.size();
		if (length == 0) {
			out << tchr.tr_name << " is not teaching any class";
			return out;
		}
 
		out << tchr.tr_name << " is teaching: ";
		for (int count = 0; count < length; ++count)
			 out << tchr.stdnt[count]->getName() << ' ';
 
		return out;
	}
 
	string getName() const {
    return tr_name; 
  }
};
// toán tử truy cập phân giải phạm vi
void Student::addTeacher(Teacher *teach) {
	tr.push_back(teach);
}
 
ostream& operator<<(ostream &out, const Student &std) {
	int length = std.tr.size();
	if (length == 0) {
		out << std.getName() << " is not registered in any course";
		return out;
	}
 
	out << std.Std_name << " is taught by: ";
	for (int count = 0; count < length; ++count)
		out << std.tr[count]->getName() << ' ';
 
	return out;
}

int main() {
	//Tạo Student ngoài phạm vi của Teacher
	Student *s1 = new Student("John");
	Student *s2 = new Student("Stacy");
	Student *s3 = new Student("Sarah");
 
	Teacher *t1 = new Teacher("Henry");
	Teacher *t2 = new Teacher("Neil");
  	Teacher *t3 = new Teacher("Steve");

	t1->addStudent(s1);
	t2->addStudent(s1);
	t1->addStudent(s3);
 
	cout << *t1 << endl;
	cout << *t2 << endl;
  	cout << *t3 << endl;
	cout << *s1 << endl;
	cout << *s2 << endl;
	cout << *s3 << endl;
}

// bài tập nhỏ
/*
#include<bits/stdc++.h>
using namespace std;

class Student {
    private: 
        string ID;
        string name;
        string year;
        double GPA;
        static int count;
    public:
        Student(){
            ID = " ";
            name = " ";
            year = " ";
            GPA = 0.0;
        }
        Student(string i, string n, string y, double g){
            ID = i;
            name = n;
            year = y;
            GPA = g;
        }
        void GetInfo();
        void printInfo();
        void increaseCount();
        int getCount();
};

int Student::count = 0;

void Student::increaseCount(){
    count++;
}
int Student::getCount(){
    return count;
}
void Student::GetInfo(){
    ++count;    //count  = 1
    this->ID = "SV" + string(3-to_string(count).length(), "0") + to_string(count);   //SV001  
    //count = 1 -> "1"
    cout << "Name: " << endl;
    getline(cin, this->name);
    cout << "Birthday: " << endl;; cin >> this->year;
    cout << "Your result: " << endl; cin >> this->GPA;
    cin.ignore();
}
void Student::printInfo(){
    cout << fixed << setprecision(3) << this->ID << endl;
    cout << this->name << endl;
    cout << this->year << endl;
    cout << this->GPA << endl;
}

int main(){
    Student sd1;
    cout << "Monitor's Infomation" << endl;
    sd1.GetInfo();
    sd1.printInfo();
    Student sd2;
    cout << "Group 1's leader" << endl;
    sd2.GetInfo();
    sd2.printInfo();
    system("pause");
    return 0;
}
*/