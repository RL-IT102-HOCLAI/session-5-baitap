1. Phân tích Input / Output
Loại	Nội dung
Input	Số lượng bệnh nhân ban đầu n, từ 0 đến 100
Input	Mã số thứ tự, tuổi và trạng thái BHYT của từng bệnh nhân
Input	Chỉ số K của bệnh nhân cần hủy
Xử lý	Kiểm tra dữ liệu đầu vào, tính phí khám và phân loại ưu tiên
Xử lý	Xóa bệnh nhân tại K, cập nhật số lượng bệnh nhân
Output	Danh sách hàng chờ trước và sau khi hủy
Output	Tổng doanh thu dự kiến và số bệnh nhân ưu tiên sau mỗi lần thống kê
Quy tắc tính phí:
- Có BHYT (1): 30.000 VNĐ.
- Không có BHYT (0): 150.000 VNĐ.
- Ưu tiên: tuổi >= 70.
- Tuổi hợp lệ: từ 1 đến 120.
- Chỉ số mảng hợp lệ: từ 0 đến n - 1.
2. So sánh các giải pháp hủy lượt khám
Tiêu chí	Dồn dịch mảng	Đánh dấu đã hủy	Đổi chỗ với phần tử cuối
Cách thực hiện	Dịch phần tử phía sau sang trái	Gán trạng thái hủy cho bản ghi	Đưa phần tử cuối vào vị trí K
Thời gian xóa	\(O(n)\) trong trường hợp xấu nhất	\(O(1)\)	\(O(1)\)
Thời gian thống kê	\(O(n)\)	\(O(n)\), cần bỏ qua bản ghi đã hủy	\(O(n)\)
Bộ nhớ phụ	\(O(1)\)	\(O(1)\), nếu dùng mảng trạng thái	\(O(1)\)
Bảo toàn FIFO	Có	Có thể giữ thứ tự nếu lọc bản ghi đã hủy	Không bảo toàn
Độ phức tạp cài đặt	Thấp	Trung bình	Thấp
Phù hợp với phòng khám	Rất phù hợp	Phù hợp nếu cần lưu lịch sử hủy	Không phù hợp
Các độ phức tạp trên xét riêng thao tác xóa, với n là số bệnh nhân trong hàng chờ. Khi thống kê lại toàn bộ danh sách, chương trình vẫn cần duyệt các bản ghi đang hoạt động.