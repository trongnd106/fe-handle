# PROJECT 1: XÂY DỰNG HỆ ĐỀ NGHỊ ĐƠN GIẢN
'''
Chúng ta sẽ sử dụng thư viện Beautiful Soup để đưa ra một bài báo trên trang dantri.com.vn
ngẫu nhiên và sau đó, nếu người dùng thích bài viết đó, họ sẽ mở nó trong trình duyệt web.
Nếu không, chương trình sẽ vẫn tiếp tục chạy và tạo ra các bài báo ngẫu nhiên.
'''
#DEMO
'''   hmm.... Trong command prompt
Cài đặt beautifulsoup: pip3 install beautifulsoup4
Cài đặt module requests: pip3 install requests
'''
#THỰC THI THÔI :))))
# module cần thiết
import requests
from bs4 import BeautifulSoup
import webbrowser
count = 0
# while luôn true sử dụng lặp lại liên tục để đưa ra suggests :)
while True:
    url = requests.get("https://dantri.com.vn/")        # lấy ra đường dẫn của web lày:v
    soup = BeautifulSoup(url.content, "html.parser")    # lấy nội dung trên web
    titles = soup.find_all(class_ = "article-title")    # tìm kiếm tất cả các tên tiêu đề và lưu vào biến tittles
    new_title = titles[count].text.strip()              # loại bỏ khoảng trắng ở phần đầu & cuối trong tiêu đề
    children = titles[count].findChildren("a" , recursive=False)     
    find_a = children[0]['href']
    
    print("\nBài báo:" + " \"" + new_title + "\"")
    print("Bạn có muốn xem không? (Y/N)")
    
    ans = input("").lower()
    if ans == "y":
        url = "https://dantri.com.vn/%s" % find_a
        webbrowser.open(url)
        break

    elif ans == "n":
        print("Try again!")
        count+=1
        continue

    else:
        print("Just \"y\" or \"n\"!")
        break

# https://dantri.com.vn/%s