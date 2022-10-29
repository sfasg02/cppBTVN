#include <vector>;
#include <algorithm>;
#include <iostream>;
#include <string>;
#include <cctype>;
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
using namespace std;


class VatTu {
public:
	string ma_vat_tu;
	string ten_vat_tu;
	string loai_phieu;
	string ngay_lap;
	float khoi_luong;
	float don_gia;
	float tinh_thanh_tien() { return (float) khoi_luong*don_gia; };
	float thanh_tien_stored;

	VatTu() {}; // Blank constructor for initiate object
	VatTu(string MaVT, string TenVT, string LoaiPhieu, string NgayLap, float KhoiLuong, float DonGia) {

		ma_vat_tu = MaVT;
		ten_vat_tu = TenVT;
		loai_phieu = LoaiPhieu;
		ngay_lap = NgayLap;
		khoi_luong = KhoiLuong;
		don_gia = DonGia;
	}

	float input_n_validate(string inputCaption) {
		float value;
		cout << inputCaption;
		while (1) {
			//Nếu input bắt đầu bằng số, input chỉ nhận cắt đến kí tự số cuối cùng nhận được.
			//Nếu input không bắt đầu bằng số sẽ bị coi là invalid (sai kiểu dữ liệu)
			if (cin >> value) {
				// valid number
				//cout << inputText << value;
				cin.clear();
				while (cin.get() != '\n');
				//Clear input trong trường hợp line kết thúc bằng kí tự. 
				return value;
				break;
			}
			else {
				// not a valid number
				cout << "Invalid Input! Please input a numerical value." << endl;
				cout << inputCaption;
				cin.clear();
				while (cin.get() != '\n');
				//Clear input trong trường hợp line kết thúc bằng kí tự. 
			}
		}
	};
	// Input string rồi convert sang float để handle được case 10a


	void input() {
		cout << "Nhập mã vật tư: "; cin >> ma_vat_tu;
		cout << "Tên vật tư: "; cin >> ten_vat_tu;
		cout << "Loại phiếu: "; cin >> loai_phieu;
		cout << "Ngày lập: "; cin >> ngay_lap;
		khoi_luong = input_n_validate("Khối lượng: ");
		don_gia = input_n_validate("Đơn giá: ");
		thanh_tien_stored = tinh_thanh_tien();
	};

	void show(string inputCaption) {
		cout << endl;
		cout << inputCaption;
		cout << "Mã vật tư: " << ma_vat_tu << endl;
		cout << "Tên vật tư: " << ten_vat_tu << endl;
		cout << "Loại phiếu: " << loai_phieu << endl;
		cout << "Ngày lập: " << ngay_lap << endl;
		cout << "Khối lượng: " << khoi_luong << endl;
		cout << "Đơn giá: " << don_gia << endl;
		cout << "Thành tiền: " << thanh_tien_stored << endl;
		cout << endl;
	};
};

//struct SV_less_diem_tb_prior {
//	bool operator ()(VatTu const& a, VatTu const& b) const {
//		if (a.diem_tb_stored < b.diem_tb_stored) return true;
//		if (a.diem_tb_stored > b.diem_tb_stored) return false;
//		// Cấu trúc này để trường hợp đtb của 2 SV bằng nhau sẽ lọt xuống 2 câu lệnh dưới.
//		if (a.ho_ten < b.ho_ten) return true;
//		if (a.ho_ten > b.ho_ten) return false;
//		return false;
//	}
//};

// Liệu có phương án nào hợp nhất SV_less_diem_tb_prior và SV_less_ho_ten_prior vào 1 struct để sử dụng dưới hàm sort mà không cần hard code không??

int bill_of_material_management() {
	SetConsoleOutputCP(65001); // Chuyển sang console log bằng Unicode (UTF-8 with signature) để tránh vỡ font chữ.
	cout << "NOW INPUTING BILL OF MATERIALS..." << endl;

	VatTu temp;
	vector<VatTu> a; // Sử dụng kiểu vector để tối ưu bộ nhớ.

	char TiepTuc;
	while (true) {
		cout << "Nhập thông tin hóa đơn quản lý vật tư tiếp theo? (Y/N)";
		cin >> TiepTuc;
		TiepTuc = toupper(TiepTuc);
		if (TiepTuc == 'N') { break; };
		temp.input();
		temp.show("");
		a.push_back(temp);
	};

	cout << "IN DANH SÁCH HÓA ĐƠN VẬT TƯ..." << endl;
	cout << endl;
	for (auto& element : a) {
		element.show("THÔNG TIN HÓA ĐƠN: ");
	};

	//sort(a.begin(), a.end(), SV_less_diem_tb_prior());
	//cout << "IN DANH SÁCH SINH VIÊN SẮP XẾP THEO ĐIỂM TRUNG BÌNH TỪ THẤP ĐẾN CAO..." << endl;
	//cout << endl;
	//for (auto& element : a) {
	//	element.show("THÔNG TIN SINH VIÊN: ");
	//};

	// Có nên đưa vào console loop để người dùng chọn action nào để thao tác sắp xếp không??
	// Có nên đưa options nhập dữ liệu từ file không??

	return 0;
}