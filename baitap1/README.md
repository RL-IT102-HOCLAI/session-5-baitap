
# Bài tập 01: Dò vết và khắc phục lỗi vượt biên chỉ số mảng

## 1. Phân tích lỗi

Mảng `queue_numbers[4]` chứa 4 mã số thứ tự khám bệnh.
Trong ngôn ngữ C, chỉ số mảng bắt đầu từ 0, do đó các chỉ số hợp lệ là 0, 1, 2 và 3.

Biến `patient_position = 4` biểu thị bệnh nhân ở vị trí thứ 4 trong danh sách. Tuy nhiên, chương trình ban đầu sử dụng câu lệnh:

`queue_numbers[patient_position] = new_queue_number;`

Câu lệnh này tương đương với `queue_numbers[4] = 1099`, vượt phạm vi mảng.

Lỗi xảy ra do nhầm lẫn giữa vị trí thực tế của bệnh nhân (bắt đầu từ 1) và chỉ số mảng trong C (bắt đầu từ 0). Hành vi này có thể làm ghi sai vùng nhớ và khiến chương trình cho kết quả không chính xác.

## 2. Cách khắc phục

Sửa câu lệnh thành:

`queue_numbers[patient_position - 1] = new_queue_number;`

Phép trừ 1 giúp chuyển vị trí bệnh nhân thứ 4 thành chỉ số mảng 3. Nhờ đó, chương trình cập nhật đúng phần tử cần thay đổi.

## 3. Bảng Test Cases

| Trường hợp kiểm thử | Dữ liệu đầu vào | Kết quả sai thực tế | Kết quả đúng mong đợi |
|---|---|---|---|
| TC01: Cập nhật bệnh nhân thứ 4 | Mảng `{1001, 1002, 1003, 1004}`, vị trí `4`, mã mới `1099` | Chương trình có thể vẫn hiển thị `1004` cho bệnh nhân thứ 4; dữ liệu bị ghi vượt phạm vi mảng | Danh sách là `{1001, 1002, 1003, 1099}` |
| TC02: Kiểm tra các bệnh nhân không được cập nhật | Mảng `{1001, 1002, 1003, 1004}`, vị trí `4`, mã mới `1099` | Việc ghi ngoài phạm vi có thể gây ảnh hưởng không xác định đến bộ nhớ; chương trình không bảo đảm giữ nguyên dữ liệu | Ba bệnh nhân đầu vẫn có mã `1001`, `1002`, `1003`; bệnh nhân thứ 4 có mã `1099` |

## 4. Kết luận

Nguyên nhân lỗi là sử dụng sai chỉ số mảng do nhầm lẫn giữa vị trí bệnh nhân và chỉ số trong C.

Sau khi sửa bằng `patient_position - 1`, chương trình cập nhật đúng mã số thứ tự của bệnh nhân thứ 4 và giữ nguyên dữ liệu của ba bệnh nhân còn lại.
