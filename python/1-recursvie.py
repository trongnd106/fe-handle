# tính giai thừa bằng đệ quy
'''
def isRecursion (n):
    if n == 0 or n == 1:
        return 1
    elif n <= 20:
        return n*isRecursion(n-1)

n = int(input())
print(isRecursion(n))
'''

#tính luỹ thừa bậc P của N (N^P)
'''
def power(N,P):
    if P == 0:
        return 1 
    return (N*power(N, P-1))

# if __name__ = '__main__':      #python2
N = int(input())
P = int(input())
print(power(N,P))
'''

#đệ quy gián tiếp
# ví dụ: in ra các số từ n đến 20
'''
def func1(n):
    if n <= 20:
        print(n, end = " ")
        n += 1
        func2(n)
    else:
        return 

def func2(n):
    if n <= 20:
        print(n, end = " ")
        n += 1
        func1(n)
    else:
        return 

n = int(input())
func1(n)
'''

#đệ quy trực tiếp
# tính bình phương của x
'''
def square(x):
    if x == 0: 
        return x
    else:
        return square(x-1) + (2*x) - 1

n = int(input())
print(square(n))
'''

#bài toán tìm số fibonacci
'''
def fibo(x):
    if x <= 1:
        return x
    else:
        return fibo(x-1) + fibo(x-2)

n = int(input())
print(fibo(n))
'''

#bài toán đảo ngược kí tự bằng đệ quy
#python
''' 
def isReverse(x):
    if len(x) < 2:
        return x
    else:
        return isReverse(x[1:]) + x[0]
    
x = str(input())
print(isReverse(x))
''' 
#c++
'''
function reverse(string)
{
    if (string.length < 2)
    {
       return string;
    }
    else return reverse(string.slice(1, string.length)) + string[0];
}
int main()
{
    string s;
    cin >> s;
    cout << reverse(s);
    return 0;    
}
'''

#bài toán tháp Hà Nội
'''
def towerofHaNoi (n, from_r, mid_r, to_r):
    if n == 0:     #nếu n = 0 thì trả về
        return
    else:
    # chuyển n-1 đĩa từ cọc A qua cọc B, lấy C trung gian
        towerofHaNoi(n-1, from_r, to_r, mid_r)
    # chuyển đĩa thứ n từ cọc A sang cọc C, kết thúc bài toán cơ bản 1
        print("Disk", n, "moved from", from_r, "to", to_r)
    # chuyển n-1 đĩa còn lại từ cọc B qua cọc C, lấy A trung gian, tiếp tục đệ quy
        towerofHaNoi(n-1, mid_r, from_r, to_r)

N = 3
towerofHaNoi(N, 'A', 'B', 'C')
'''

#bài toán kiểm tra email
'''
def email_verify (email):
    if not email[0].isalpha():
        return False
    at = email.find("@")
    dot = email.rfind(".")
    if at == -1 or dot == -1 or dot < at:
        return False
    if dot == len(email) - 1:
        return False
    return True

email = input()
if email_verify(email):
    print("VALID")
else:
    print("INVALID")
'''

#kỹ thuật unpacking 
# công thức khoảng cách Manhatttan, in khoảng cách lớn nhất
# distance = |x| + |y| 
'''
points = [(1.2,1.5), (-3.1,5.6), (4.5,2.6), (1.4,6.8), (2.1,-8.4)]
dist_max = (0,0)
for x,y in points:
    dist = abs(x) + abs(y)
    if dist > abs(dist_max[0]) + abs(dist_max[1]):
        dist_max = (x,y)
print("Point", dist_max ,"has max distance to O(0,0):", abs(dist_max[0])+abs(dist_max[1]))
'''

'''
authors = [('Nguyen','Dat'),('Phung','Huy'),('Duc','Uy')]
for first_name, last_name in authors:
    print("First name:", first_name ,", Last name:", last_name)
'''
#Fibonacci using Unpacking 
'''
def Fib(n):
    a,b = 1,1
    for i in range(n):
        a,b = b,a+b
    print(a)
Fib(8)
'''

# Object Oriented Programming (OOP) in Python3
# Manage Couses
'''
class Course:
    def __init__(self, name,year,id_number,lecturer):
        self.name = name
        self.year = year
        self.id_number = id_number
        self.lecturer = lecturer
        self.student_list = []

    def enroll(self,student):
        self.student_list.append(student)

    def print_student(self):
        print("----------Students in course " + self.name + "----------")
        for i in self.student_list:
            txt = "{:<16} {:<16} {:<6d} {:<16}"
            txt2 = "{:<16} {:<16} {:<6} {:<16}"
            print(txt2.format("First name", "Last name", "Age", "Email"))
            print(txt.format(i.first_name, i.last_name, i.age, i.email))
           
    def print_lecturer(self):
        print("\n\n\n----------Lecturer in course " + self.name + "----------")
        txt = "{:<16} {:<16d}"
        txt2 = "{:<16} {:<16}"
        print(txt2.format("Name", "Bank Account"))
        print(txt.format(self.lecturer.first_name, self.lecturer.bank_account))

class Person:
    def __init__(self, first_name,last_name,age,email):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.email = email
    def print_info(self):
        print(self.first_name +" " +self.last_name +" is " + str(self.age) +" years old.")
        print("Email:" + self.email)

class Lecturer(Person):
    def __init__(self,f_name,l_name,age,email,bank_account):
        super().__init__(f_name,l_name,age,email)
        self.bank_account = bank_account
    
    def print_info(self):
        super().print_info()
        print("Bank Accout:" + str(self.bank_account))
       
class Student(Person):
    def __init__(self,f_name,l_name,age,email,student_id, grade=-1):
        super().__init__(f_name,l_name,age,email)
        self.student_id = student_id
        self.grade=grade
    
    def print_info(self):
        super().print_info()
        print("Student ID: " + self.student_id)
        print("Grade: " + str(self.grade))

#Khởi tạo objects
lecturer_TEK4VN = Lecturer("Hưng","Đặng",35,"hungnguyen@tek4.vn",1234567)
python_course = Course("Lập trình Python cơ bản",2019,1234,lecturer_TEK4VN)
student_hai = Student("Hải","Nguyễn",18,"hainguyen@tek4.vn","108001024")
student_ba=Student("Ba", "Nguyễn", 21, "banguyen@tek4.vn", "108001025")
python_course.enroll(student_hai)
python_course.enroll(student_ba)

#Xuất danh sách sinh viên có trong khóa học
python_course.print_student()
python_course.print_lecturer()
student_hai.print_info()
lecturer_TEK4VN.print_info()
'''

#Nạp chồng toán tử (Operator Overloading)
'''
class Vector:
  def __init__(self, v):
    self.v = v
    
  def __add__(self, other):
    if len(self.v) != len(other.v):
      print("Size Error!")
      return None
    result1 = []
    for i in range(len(self.v)):
      result.append(self.v[i] + other.v[i])
    return result1
    
  def __sub__(self, other):
    if len(self.v) != len(other.v):
      print("Size Error!")
      return None
    result2 = []
    for i in range(len(self.v)):
      result.append(self.v[i] - other.v[i])
    return result2
    
  def __mul__(self, other):
    if len(self.v) != len(other.v):
      print("Size Error!")
      return None
    result3 = []
    for i in range(len(self.v)):
      result.append(self.v[i] * other.v[i])
    return sum(result3)
    
  def __eq__(self, other):
    if len(self.v) != len(other.v):
      print("Size Error!")
      return None
    flag = True
    for i in range(len(self.v)):
      if self.v[i] != other.v[i]:
        flag = False
    return flag
  
v1 = [1.2,2.3,4.5,3.5,4.6]
v2 = [2.1,2.2,2.3,2.5,3.6]
# Tạo đối tượng
vector1 = Vector(v1)
vector2 = Vector(v2)

print(vector1+vector2)
print(vector1-vector2)
print(vector1*vector2)
print(vector1==vector2)
'''

# EX nhỏ: Chương trình sinh mật khẩu mạnh
# Yêu cầu về mật khẩu mạnh:
#    + Có tối thiểu 8 kí tự, để giới hạn lấy max = 12 kí tự
#    + Kí tự số (digits)
#    + Chữ thường (lower-case characters), chữ hoa (upper-case characters)
#    + Ký tự đặc biệt (Symbols)
'''
import random 
DIGITS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

LCASE_CHARACTERS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                    'y', 'z']

UCASE_CHARACTERS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                    'Y', 'Z']

SYMBOLS = ['@', '#', '$', '%', ':', '?', '.', '/', '|', '~',
           '>', '<', '(', ')']

# Mỗi phần chọn ít nhất 1 cái cho ăn chắc :D
rand_digit = random.choice(DIGITS)
rand_lower = random.choice(LCASE_CHARACTERS)
rand_upper = random.choice(UCASE_CHARACTERS)
rand_symbol = random.choice(SYMBOLS)

#Tạm gom lại nào
temp_pass = [rand_digit, rand_lower, rand_upper, rand_symbol]
#Còn lại cũng gom tất vào
MIXTAPE_LIST = DIGITS + LCASE_CHARACTERS + UCASE_CHARACTERS + SYMBOLS
MAX_LEN_OF_PASS = 12     #Ở đây có thể thay đổi độ dài password 

for x in range(MAX_LEN_OF_PASS - 4):
    temp_pass.append(random.choice(MIXTAPE_LIST))
#xóc xóc lên 1 tí cho nó mixtape =)))
random.shuffle(temp_pass)

password = ""
for x in temp_pass:
    password = password + x
#ú oà in ra thôi
print("Password generated: " + password)
'''

#Xây dựng module rồi tự import :D
'''
from lib import filter       #import phương thức filter() từ module lib.py 

request="http://localhost:81/DVWA/vulnerabilities/xss_r/?name=<script>alert(document.cookie)</script>"
print(filter(request))
'''


