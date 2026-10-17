1. Sơ đồ tổ chức dữ liệu
Các mảng sử dụng chung một chỉ số i, nghĩa là thông tin ở vị trí i của tất cả mảng đều thuộc cùng một bệnh nhân.
Mảng	Kiểu dữ liệu	Ý nghĩa
ma_so[100]	int	Mã số thứ tự
ten[100][30]	char	Tên bệnh nhân
tuoi[100]	int	Tuổi bệnh nhân
uu_tien[100]	int	1: ưu tiên, 0: thường
bao_hiem[100]	int	1: có BHYT, 0: không có
phi_kham[100]	int	Chi phí khám sơ bộ
ten_bac_si[100][30]	char	Bác sĩ đăng ký
khung_gio[100][20]	char	Khung giờ khám
so_luong	int	Số bệnh nhân hiện có
ma_tiep_theo	int	Mã số tiếp theo được cấp
Bổ sung hai mảng bác sĩ và khung giờ giúp chương trình đếm chính xác số bệnh nhân đã đăng ký cho từng tổ hợp bác sĩ/khung giờ.