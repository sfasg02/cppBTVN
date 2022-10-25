#include <vector>;
#include <algorithm>;
#include <iostream>;
#include <string>;
#include <cctype>;
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
using namespace std;


class SV {
public:
	string ho_ten;
	string ngay_sinh;
	string gioi_tinh;
	float diem_toan;
	float diem_ly;
	float diem_hoa;
	float diem_tb() { return (float)(diem_toan + diem_ly + diem_hoa) / 3; };
	float diem_tb_stored;

	SV() {}; // Blank constructor for initiate object
	SV(string hoTen, string ngaySinh, string gioiTinh, float diemToan, float diemLy, float diemHoa) {

		ho_ten = hoTen;
		ngay_sinh = ngaySinh;
		gioi_tinh = gioiTinh;
		diem_toan = diemToan;
		diem_ly = diemLy;
		diem_hoa = diemHoa;
	}

	float input_n_validate(string inputCaption) {
		float value;
		cout << inputCaption;
		while (1) {
			//Nếu input bắt đầu bằng số, input chỉ nhận cắt đến kí tự số cuối cùng nhận được.
			//Nếu input không bắt đầu bằng số sẽ bị coi là invalid (sai kiểu dữ liệu)
			if ((cin >> value) && (value <= 10) && (value >= 0))  {
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
				cout << "Invalid Input! Please input a numerical value in range (0 -> 10)." << endl;
				cout << inputCaption;
				cin.clear();
				while (cin.get() != '\n');
				//Clear input trong trường hợp line kết thúc bằng kí tự. 
			}
		}
	};
	// Input string rồi convert sang float để handle được case 10a


	void input() {
		cout << "Nhập họ tên sinh viên: "; cin >> ho_ten;
		cout << "Ngày sinh: "; cin >> ngay_sinh;
		cout << "Giới tính: "; cin >> gioi_tinh;
		diem_toan = input_n_validate("Điểm toán: ");
		diem_ly = input_n_validate("Điểm lý: ");
		diem_hoa = input_n_validate("Điểm hóa: ");
		diem_tb_stored = diem_tb();
	};

	void show(string inputCaption) {
		cout << endl;
		cout << inputCaption;
		cout << "Họ và tên sinh viên: " << ho_ten << endl;
		cout << "Ngày sinh: " << ngay_sinh << endl;
		cout << "Giới tính: " << gioi_tinh << endl;
		cout << "Điểm toán: " << diem_toan << endl;
		cout << "Điểm lý: " << diem_ly << endl;
		cout << "Điểm hóa: " << diem_hoa << endl;
		cout << "Điểm trung bình: " << diem_tb_stored << endl;
		cout << endl;
	};
};

struct SV_less_diem_tb_prior {
	bool operator ()(SV const& a, SV const& b) const {
		if (a.diem_tb_stored < b.diem_tb_stored) return true;
		if (a.diem_tb_stored > b.diem_tb_stored) return false;
		// Cấu trúc này để trường hợp đtb của 2 SV bằng nhau sẽ lọt xuống 2 câu lệnh dưới.
		if (a.ho_ten < b.ho_ten) return true;
		if (a.ho_ten > b.ho_ten) return false;
		return false;
	}
};

struct SV_less_ho_ten_prior {
	bool operator ()(SV const& a, SV const& b) const {
		if (a.ho_ten < b.ho_ten) return true;
		if (a.ho_ten > b.ho_ten) return false;
		// Cấu trúc này để trường hợp Họ tên của 2 SV bằng nhau sẽ lọt xuống 2 câu lệnh dưới.
		if (a.diem_tb_stored < b.diem_tb_stored) return true;
		if (a.diem_tb_stored > b.diem_tb_stored) return false;
		return false;
	}
};
// Liệu có phương án nào hợp nhất SV_less_diem_tb_prior và SV_less_ho_ten_prior vào 1 struct để sử dụng dưới hàm sort mà không cần hard code không??

int Student_management() {
	SetConsoleOutputCP(65001); // Chuyển sang console log bằng Unicode (UTF-8 with signature) để tránh vỡ font chữ.
	cout << "NOW INPUTING STUDENT INFOMATION..." << endl;

	SV temp;
	vector<SV> a; // Sử dụng kiểu vector để tối ưu bộ nhớ.
	
	char TiepTuc;
	while (true) {
		cout << "Nhập thông tin sinh viên tiếp theo? (Y/N)";
		cin >> TiepTuc;
		TiepTuc = toupper(TiepTuc);
		if (TiepTuc == 'N') { break; };
		temp.input(); 
		temp.show("");
		a.push_back(temp);
	};

	cout << "IN DANH SÁCH SINH VIÊN..." << endl;
	cout << endl;
	for (auto& element : a) {
		element.show("THÔNG TIN SINH VIÊN: ");
	};

	sort(a.begin(), a.end(), SV_less_diem_tb_prior());
	cout << "IN DANH SÁCH SINH VIÊN SẮP XẾP THEO ĐIỂM TRUNG BÌNH TỪ THẤP ĐẾN CAO..." << endl;
	cout << endl;
	for (auto& element : a) {
		element.show("THÔNG TIN SINH VIÊN: ");
	};

	sort(a.begin(), a.end(), SV_less_ho_ten_prior());
	cout << "IN DANH SÁCH SINH VIÊN SẮP XẾP THEO HỌ VÀ TÊN THEO VẦN ABC..." << endl;
	cout << endl;
	for (auto& element : a) {
		element.show("THÔNG TIN SINH VIÊN: ");
	};

	// Có nên đưa vào console loop để người dùng chọn action nào để thao tác sắp xếp không??
	// Có nên đưa options nhập dữ liệu từ file không??

	return 0;
}