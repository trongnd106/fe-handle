# HÀM NẶC DANH, HÀM LAMBDA
# 1. HÀM LAMBDA -> hàm ẩn danh 
# Các trường hợp sử dụng hàm lamda
# 1.a. Khi hàm lambda là đối số của hàm khác
'''
def get_full_name(first_name, last_name, format):
    return format(first_name, last_name)

full_name1 = get_full_name('Trọng', 'Đạt', lambda first_name, last_name: f"{first_name} {last_name}")
full_name2 = get_full_name('An', 'Hoà', lambda first_name, last_name : f"{last_name},{first_name}")
print(full_name1)
print(full_name2)
'''

# 1.b. Sử dụng với hàm filter()
'''
my_list = [2,3,4,5,6,7,8,9,10,12,15,16,19]
new_list = list(filter(lambda x: (x % 2 != 0), my_list))
print(new_list)
'''

# 1.c. Sử dụng với hàm map()
'''
lst1 = [18,12,13,5,9,11,8]
new_lst1 = list(map(lambda x: x*x, lst1))
print(max(new_lst1))
'''

# sd hàm lambda nối chuỗi
'''
list = ['Nguyen', 'Dat', 'Trong']
string_join = (lambda s: (" ").join(s))
print(string_join(list))
'''


