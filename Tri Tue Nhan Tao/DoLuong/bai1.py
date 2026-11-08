'''

Ko gian trạng thái (State Space): T = {(x, y) | 0 <= x <= 4; 0 <= y <= 3}
Trạng thái ban đầu (Start State): S = {(0, 0)}

Trạng thái đích (Goal State): G = {(2, y) | 0 <= y <= 3}

Các phép toán chuyển trạng thái (Operators): F = {A -> B, B -> A, Đổ B đi, đổ A đi, đổ đầy A, đổ đầy B}

- A -> B: x > 0, y < 3 (Đổ từ A sang B, cần A có nước và B chưa đầy)
- B -> A: x < 4, y > 0 (Đổ từ B sang A, cần B có nước và A chưa đầy)
- empty B: y > 0 (Đổ hết B đi, cần B có nước),
- empty A: x > 0 (Đổ hết A đi, cần A có nước),
- fill A: x < 4 (Đổ đầy A, cần A chưa đầy),
- fill B: y < 3 (Đổ đầy B, cần B chưa đầy)

Xử lý các TH có thể xảy ra:

- Khi A -> B tức là x + y >= 3: (x + y - 3, 3) Do đổ đầy B nên A là số lít còn lại của tổng sau khi bỏ đi số lít từ B
- Khi B -> A tức là x + y >= 4: (4, x + y - 4) Do đổ đầy A nên B sẽ là tổng số lít nước còn lại
- Khi đổ đầy bình B mà bình A rỗng tức là x + y <= 3: (0, x + y)
- Khi đổ đầy bình A mà bình B rỗng tức là x + y <= 4: (x + y, 0)


'''










