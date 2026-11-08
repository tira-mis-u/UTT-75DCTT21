## Dạng 1: Mô hình hóa các trường hợp bằng hàm min/max (piecewise function simplification)
### Bài 1. Thời gian trùng lịch bảo trì

Một công ty có hai hệ thống máy chủ cần được bảo trì định kỳ. Máy chủ thứ nhất được bảo trì trong khoảng thời gian từ phút `L1` đến phút `R1`. Máy chủ thứ hai được bảo trì trong khoảng thời gian từ phút `L2` đến phút `R2`. Các mốc thời gian được tính từ cùng một thời điểm bắt đầu. Một khoảng thời gian được xem là gồm điểm bắt đầu nhưng không gồm điểm kết thúc. Ban quản trị muốn biết tổng thời gian mà cả hai máy chủ cùng được bảo trì.

#### Input

Một dòng chứa bốn số nguyên: `L1 R1 L2 R2`.

#### Output

Một số nguyên duy nhất là tổng số phút hai khoảng thời gian giao nhau.

#### Constraints

- `0 <= L1, R1, L2, R2 <= 10^9`.
- `L1 <= R1`.
- `L2 <= R2`.

#### Example

| Input | Output |
| :--- | :--- |
| `540 720 660 840` | `60` |

**Giải thích:**

Máy chủ thứ nhất được bảo trì từ phút `540` đến `720`, máy chủ thứ hai từ phút `660` đến `840`. Hai hệ thống cùng được bảo trì trong `60` phút.

---
### Bài 2. Tính phí gửi xe

Một bãi giữ xe áp dụng chính sách tính phí như sau:

- Khách hàng được miễn phí trong `F` phút đầu tiên.
- Sau thời gian miễn phí, cứ mỗi `K` phút hoặc một phần của khoảng thời gian đó, khách hàng phải trả `P` đồng.
- Tổng phí gửi xe không vượt quá `C` đồng cho một lượt gửi.

Một khách hàng gửi xe trong tổng cộng `T` phút. Hãy tính số tiền khách hàng phải trả.

#### Input

Một dòng chứa năm số nguyên: `T F K P C`.

Trong đó:

- `T`: Tổng thời gian gửi xe.
- `F`: Thời gian miễn phí.
- `K`: Số phút trong một đơn vị tính phí.
- `P`: Giá tiền mỗi đơn vị tính phí.
- `C`: Mức phí tối đa.

#### Output

Một số nguyên duy nhất là tổng số tiền khách hàng phải trả.

#### Constraints

- `0 <= T, F <= 10^9`.
- `1 <= K <= 10^9`.
- `0 <= P, C <= 10^9`.

#### Example

| Input | Output |
| :--- | :--- |
| `106 15 30 5000 18000` | `18000` |

**Giải thích:**
- Sau `15` phút miễn phí, khách hàng còn `91` phút tính phí.
- Vì cứ mỗi `30` phút hoặc một phần của khoảng thời gian đó được tính thành một đơn vị phí nên khách hàng phải trả tiền cho `4` đơn vị.
- Tổng phí ban đầu là `20000` đồng. Tuy nhiên, bãi xe quy định mức phí tối đa là `18000` đồng nên khách hàng chỉ phải trả `18000` đồng.

---

### Bài 3. Xếp hàng lên xe tải

Một công ty vận chuyển cần xếp các kiện hàng giống hệt nhau lên một chiếc xe tải. Mỗi kiện hàng có:

- Khối lượng `W` kg.
- Thể tích `V` lít.

Xe tải có hai giới hạn độc lập:

- Tổng khối lượng hàng không vượt quá `M` kg.
- Tổng thể tích hàng không vượt quá `S` lít.

Công ty có tổng cộng `N` kiện hàng.

Các kiện hàng không được cắt nhỏ. Hãy xác định số kiện hàng lớn nhất có thể xếp lên xe.

#### Input

Một dòng chứa năm số nguyên: `N M S W V`. Trong đó:
- `N`: Tổng số kiện hàng hiện có.
- `M`: Khối lượng hàng tối đa mà xe tải có thể chở.
- `S`: Thể tích hàng tối đa mà xe tải có thể chứa.
- `W`: Khối lượng của một kiện hàng.
- `V`: Thể tích của một kiện hàng.

#### Output

Một số nguyên duy nhất là số kiện hàng tối đa có thể vận chuyển.

#### Constraints

- `1 <= N, M, S, W, V <= 10^18`.

#### Example

| Input | Output |
| :--- | :--- |
| `100 1000 720 30 20` | `33` |

**Giải thích:**

- Giới hạn khối lượng cho phép tối đa `33` kiện hàng.
- Giới hạn thể tích cho phép tối đa `36` kiện hàng.
- Công ty chỉ có `100` kiện hàng.

Do đó, xe tải chỉ có thể vận chuyển tối đa `33` kiện hàng.

---
### Bài 4. Áp dụng mã giảm giá

Một cửa hàng trực tuyến cung cấp mã giảm giá cho khách hàng. Mỗi mã giảm giá có các thông tin:

- Hóa đơn ban đầu có giá trị `B` đồng.
- Mức giảm giá là `p%`.
- Số tiền giảm tối đa là `D` đồng.

Chính sách cửa hàng:

1. Số tiền giảm theo phần trăm được tính bằng cách lấy phần nguyên của kết quả.
2. Số tiền giảm thực tế không vượt quá mức giảm tối đa của mã.
3. Số tiền giảm không thể lớn hơn giá trị hóa đơn.

Hãy tính số tiền khách hàng phải thanh toán và số tiền thực tế được giảm.

#### Input

Một dòng chứa ba số nguyên: `B p D`. Trong đó:

- `B`: Giá trị hóa đơn ban đầu.
- `p`: Phần trăm giảm giá.
- `D`: Số tiền giảm tối đa.

#### Output

Một dòng chứa hai số nguyên: `PAY DISCOUNT`. Trong đó:

- `PAY`: Số tiền khách hàng phải thanh toán.
- `DISCOUNT`: Số tiền thực tế được giảm.

#### Constraints

- `1 <= B <= 10^12`.
- `0 <= p <= 100`.
- `0 <= D <= 10^12`.

#### Example

| Input | Output |
| :--- | :--- |
| `250000 20 30000` | `220000 30000` |

**Giải thích:**

Mức giảm theo phần trăm là `50000` đồng, nhưng mã giảm giá chỉ cho phép giảm tối đa `30000` đồng.
Vì vậy, khách hàng được giảm `30000` đồng và phải thanh toán `220000` đồng.

---
### Bài 5. Xác định vị trí đón khách trên tuyến xe buýt

Một tuyến xe buýt hoạt động trên đoạn đường thẳng có tọa độ từ `L` đến `R`.

Một hành khách đang đứng tại tọa độ `X`. Hệ thống cần xác định vị trí đón khách hợp lệ gần nhất trên tuyến xe buýt.

Giả sử xe buýt có thể đón khách tại bất kỳ tọa độ nguyên nào thuộc đoạn đường hoạt động.

Hãy xác định tọa độ đón khách sao cho khoảng cách từ hành khách đến vị trí đó là nhỏ nhất.

#### Input

Một dòng chứa ba số nguyên: `L R X`. Trong đó:

- `L`: Tọa độ bắt đầu của tuyến xe buýt.
- `R`: Tọa độ kết thúc của tuyến xe buýt.
- `X`: Tọa độ hiện tại của hành khách.

#### Output

Một số nguyên duy nhất là tọa độ đón khách được chọn.

#### Constraints

- `-10^9 <= L, R, X <= 10^9`.
- `L <= R`.

#### Example 1

| Input | Output |
| :--- | :--- |
| `1200 4800 5200` | `4800` |

**Giải thích:**

Hành khách đứng tại tọa độ `5200`, nằm ngoài phạm vi tuyến xe buýt. Vị trí đón khách gần nhất là điểm cuối tuyến tại tọa độ `4800`.

#### Example 2

| Input | Output |
| :--- | :--- |
| `1200 4800 3000` | `3000` |

**Giải thích:**

Hành khách đang đứng tại tọa độ `3000`, nằm trong phạm vi tuyến xe buýt nên có thể được đón ngay tại vị trí hiện tại.