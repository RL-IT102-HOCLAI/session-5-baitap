1. Phân tích bài toán I/O
Loại	Dữ liệu
Đầu vào	tuoi_benh_nhan[4]: tuổi của 4 bệnh nhân
Đầu vào	co_bao_hiem[4]: trạng thái BHYT (0 hoặc 1)
Xử lý	phi_kham[4]: phí khám thực tế của từng bệnh nhân
Xử lý	tong_doanh_thu: tổng phí khám của 4 bệnh nhân
Xử lý	so_ca_uu_tien: số bệnh nhân trên 70 tuổi có tuổi hợp lệ
Đầu ra	Tuổi, BHYT, phí khám và luồng khám của từng bệnh nhân
Đầu ra	Tổng doanh thu và tổng số ca ưu tiên
2. Đề xuất giải pháp
- Khai báo 3 mảng có 4 phần tử, sử dụng chỉ số từ 0 đến 3.
- Nhập tuổi và trạng thái BHYT của từng bệnh nhân.
- Nếu tuổi nhỏ hơn hoặc bằng 0, hoặc lớn hơn 120, gán phí khám bằng 0, phân luồng LỖI DỮ LIỆU và không tính ưu tiên.
- Nếu trạng thái BHYT không phải 0 hoặc 1, điều chỉnh về 0.
- Nếu tuổi hợp lệ và có BHYT, phí khám là 40.000 VNĐ; nếu không có BHYT, phí là 200.000 VNĐ.
- Nếu tuổi lớn hơn 70, phân luồng ƯU TIÊN; các trường hợp hợp lệ còn lại là THƯỜNG.
- Cộng phí khám vào tổng doanh thu và đếm số ca ưu tiên.

Ví dụ kiểm thử
Giả sử nhập dữ liệu sau:
Bệnh nhân	Tuổi	BHYT nhập vào	BHYT sau kiểm tra	Phí khám (VNĐ)	Luồng
1	75	1	1	40.000	ƯU TIÊN
2	30	0	0	200.000	THƯỜNG
3	65	2	0	200.000	THƯỜNG
4	0	1	1	0	LỖI DỮ LIỆU
Kết quả tổng hợp:
- Tổng doanh thu: 440000 VNĐ.
- Tổng số ca ưu tiên: 1.
Bệnh nhân thứ 4 có tuổi không hợp lệ nên không được tính phí và không được tính vào số ca ưu tiên.