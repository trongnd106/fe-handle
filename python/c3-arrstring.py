# CHƯƠNG 3: MẢNG VÀ CHUỖI KÍ TỰ
# -------------------------- CHUỖI NGÀY HỌC GIẢI THUẬT -----------------------------
# Phần tử cực trị
'''
def findPeak (arr, n):
    if (n == 1):
        print(0, end = " ")
    if (arr[0] >= arr[1]):
        print(0, end = " ")
    if (arr[n-1] >= arr[n-2]):
        print(n-1, end = " ")
    for i in range (1, n-1):
        if (arr[i] >= arr[i-1]) and (arr[i] >= arr[i+1]):
            print(i, end = " ")
arr = [5,3,20,4,1,6]
n = len(arr)
findPeak(arr, n)
'''

# Bài toán số Narcissictic
'''
def countDigit(n):
    if n == 0:
        return 0
    return (1 + countDigit(n // 10))

def checkNarci(n):
    l = countDigit(n)
    dup = n
    sum = 0
    while (dup > 0):
        sum += pow(dup % 10, l)
        dup = dup // 10
    return (n == sum)

n = int(input())
a = [int(x) for x in input().split()]
count_check = 0
for i in range(0,n):
    if checkNarci(a[i]):
        print(a[i], end = " ")
        count_check = 1
if count_check == 0:
    print("NO")
'''

#  Xoá phần tử trong mảng
'''
n = int(input())
a = [int(x) for x in input().split()]
k = int(input())
for i in range(k, n):
    a[i] = a[i+1]
for i in range(0, n-1):
    print(a[i], end = " ")
'''

# Tách từ (chuẩn hoá xâu)
'''
s = str(input())
result = "Ket qua tach tu:"
for word in s:
    if ord(word) >= 65 and ord(word) <= 90 :
        result += " " + chr(ord(word) + 32)
    else:
        result += word
print(result)
'''

#Xác định mật khẩu mạnh
'''
def checkPass (password):
    if len(password) < 5:
        return False
    if any(c in special_characters for c in password):
        pass
    else: return False
    special_characters = "!@#$%^&*()_+"
    count_upper = count_lower = count_number = 0
    for character in password:
        if character.isupper():
            count_upper += 1
        elif character.islower():
            count_lower += 1
        elif character.isdigit():
            count_number += 1
    if count_upper == 0 or count_lower == 0 or count_number == 0:
        return False
    return True

s = input()
if checkPass(s):
    print("TRUE")
else: print("FALSE")
'''

'''
n = list(input())

j = len(n)
while True:
    dem = 0
    x = n[0]
    print(x,end="")
    for k in reversed(range(0,j)):
        if n[k]==x:
            dem+=1;
            n.pop(k)
    print(dem,end=" ")
    j = len(n)
    if j ==0: break
'''

# ĐẾM VÀ IN RA CÁC SỐ NGUYÊN TỐ TỪ 1 ĐẾN N
'''
from math import sqrt, floor
def check_prime(n):
    count = 0
    for i in range (2, floor(sqrt(n)+1)):
        if n % i == 0:
            count += 1
            break
    if count == 0:
        return True
    else: return False

n = int(input())
count_all = 0
for i in range (2, n+1):
    if check_prime(i):
        count_all += 1
        print(i, end = " ")
print("\nSo cac so nguyen to tu 1 den", n, "la:", count_all)
'''

# KIỂM TRA ĐỀ SUDOKU
# case1:
'''
. . . 1 4 . . 2 .
. . 6 . . . . . .
. . . . . . . . .
. . 1 . . . . . .
. 6 7 . . . . . 9
. . . . . . 8 1 .
. 3 . . . . . . 6
. . . . . 7 . . .
. . . 5 . . . 7 .

'''

''' #CODE NHÉ
a = []
for i in range(0,9):
    a.append([x for x in input().split()])
#check hàng 
def checkRow (row):
    temp = []
    for i in range(0,9):
        if a[row][i] != '.':
            temp.append(int(a[row][i]))
    if len(temp) != len(set(temp)):
        return 0
    return 1
#check cột
def checkCol (col):
    temp = []
    for i in range(0,9):
        if a[i][col] != '.':
            temp.append(int(a[i][col]))
    if len(temp) != len(set(temp)):
        return 0
    return 1
#check o vuong be nho 3x3
def checkSub():
    for row in range(0,9,3):
        for col in range(0,9,3):
            temp = []
            for r in range(row,row+3):
                for c in range(col,col+3):
                    if a[r][c] != '.':
                        a.append(int(a[r][c]))
    if len(temp) != len(set(temp)):
        return 0
    return 1

key = "TRUE"
if checkSub() == 0:
    print ("FALSE")
else:
    for i in range(0,9):
        if checkRow(i)*checkCol(i) == 0:
            key = "FALSE"
print(key)
'''

# MA TRẬN CHUYỂN VỊ
# cách1:
'''
import numpy as np
A = np.array([[1,2],[3,4],[5,6]])
print(A.T)
'''

# cách2:
'''
a = []
b = []
m, n = [int(x) for x in input().split()]

b = [[0 for x in range(n)] for y in range(m)]    # khởi tạo ma trận không 

for i in range(0, n):
    a.append([int(x) for x in input().split()])     # nhập ma trận a

for i in range(0,m):
    for j in range(0,n):
        b[i][j]=a[j][i]     # đổi vị trí & gán

for i in range (0,m):
    for j in range(0,n):
        print(b[i][j], end=" ")
    print()
'''


# ma trận xoắn ốc
'''
n = int(input())
a = [[0 for x in range(n)] for y in range(n)]

hang=0
cot=n-1
count = 1
for i in range(0,n//2+1):
    for j in range(hang,cot+1):
        a[hang][j] = count
        count+=1

    for j in range (hang+1, cot+1):
        a[j][cot] = count
        count+=1

    for j in reversed(range(hang,cot)):
        a[cot][j] = count
        count+=1

    for j in reversed(range(hang+1,cot)):
        a[j][hang]=count
        count+=1
    hang+=1
    cot -=1
for i in range(0, n):
    print("{}".format(a[i]).replace(",", "").replace("[", "").replace("]", ""))
'''

