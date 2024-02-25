import urllib.request
import heapq

# Đọc dữ liệu từ URL
url = "http://www-cs-faculty.stanford.edu/~knuth/sgb-words.txt"
response = urllib.request.urlopen(url)
data = response.read().decode('utf-8')

# Tạo danh sách từ vựng từ dữ liệu
word_list = data.split("\n")

# Hàm kiểm tra hai từ có khác nhau ở đúng một vị trí hay không
def is_one_letter_apart(word1, word2):
    # Kiểm tra xem có đúng một vị trí khác nhau không
    return sum(a != b for a, b in zip(word1, word2)) == 1

# Tạo đồ thị G
G = {word: set() for word in word_list}
for word1 in word_list:
    for word2 in word_list:
        if is_one_letter_apart(word1, word2):
            G[word1].add(word2)
            G[word2].add(word1)

# Hàm đếm số thành phần liên thông
def count_connected_components(graph):
    visited = set()
    count = 0
    for node in graph:
        if node not in visited:
            count += 1
            stack = [node]
            while stack:
                current = stack.pop()
                visited.add(current)
                stack.extend(graph[current] - visited)
    return count

# Đếm số thành phần liên thông của đồ thị G
num_components = count_connected_components(G)
print("Số thành phần liên thông của đồ thị G là:", num_components)

# Hàm tìm đường đi ngắn nhất từ u đến v trong đồ thị G
def shortest_path(graph, start, end):
    # Khởi tạo khoảng cách ban đầu và hàng đợi ưu tiên
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    queue = [(0, start)]  # (Khoảng cách từ start, đỉnh start)

    while queue:
        current_distance, current_vertex = heapq.heappop(queue)

        if current_vertex == end:
            path = []
            while current_vertex != start:
                path.append(current_vertex)
                current_vertex = previous[current_vertex]
            path.append(start)
            return path[::-1]

        if current_distance > distances[current_vertex]:
            continue

        for neighbor in graph[current_vertex]:
            distance = current_distance + 1  # Vì các từ khác nhau ở một vị trí
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
                previous[neighbor] = current_vertex

    return "Không có đường đi từ {} đến {}".format(start, end)

# Đây là phần code trước để tạo đồ thị G và danh sách từ vựng
# ...

# Khởi tạo biến previous để lưu đường đi trước đó
previous = {}

# Tìm đường đi ngắn nhất từ u đến v
u = "words"  # Đỉnh bắt đầu
v = "graph"  # Đỉnh kết thúc
shortest = shortest_path(G, u, v)
print("Đường đi ngắn nhất từ {} đến {} là: {}".format(u, v, shortest))
