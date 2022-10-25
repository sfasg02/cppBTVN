#include <vector>;
#include <algorithm>;
#include <iostream>;
#include <cmath>;
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
using namespace std;

struct MathPoint2D {
	float x_axis;
	float y_axis;
};

class MathVector2D {
private:
	MathPoint2D head;
	MathPoint2D tail;

	float magnitude; // Độ dài vector = sqrt( (x2-x1)^2 + (y2-y1)^2 )
	float direction; // Hướng của vector: theta: tan theta = (y2-y1)/(x2-x1)
	void calc_magnitude_n_direction() {
		magnitude = sqrt(pow((tail.x_axis - head.x_axis), 2) + pow((tail.y_axis - head.y_axis), 2));
		direction = atan((float)(tail.y_axis - head.y_axis) / (tail.x_axis - head.x_axis)); // Arctan tính theo rad
	};

public:
	MathVector2D() {}; // Khởi tạo vector rỗng
	MathVector2D(MathPoint2D Head, MathPoint2D Tail) {
		head = Head;
		tail = Tail;
		calc_magnitude_n_direction();
	};

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

	// 1 vector được xác định bằng gốc, độ dài và hướng của vector hoặc xác định bằng điểm gốc và điểm đích của vector
	void input_by_head_n_tail() {
		head.x_axis = input_n_validate("Nhập hoành độ điểm gốc vector (x_head): ");
		head.y_axis = input_n_validate("Nhập tung độ điểm gốc vector (y_head): ");
		tail.x_axis = input_n_validate("Nhập hoành độ điểm đích vector (x_tail): ");
		tail.y_axis = input_n_validate("Nhập tung độ điểm đích vector (y_tail): ");
		calc_magnitude_n_direction();
	};

	void show(string inputCaption) {
		cout << inputCaption << endl;
		cout << "Tọa độ gốc vector: (" << head.x_axis << ", " << head.y_axis << ")" << endl;
		cout << "Tọa độ đích vector: (" << tail.x_axis << ", " << tail.y_axis << ")" << endl;
		cout << endl;
	};

	MathVector2D Sum(MathVector2D otherMathVector2D) {
		MathPoint2D newHead{
			head.x_axis + otherMathVector2D.head.x_axis,
			head.y_axis + otherMathVector2D.head.y_axis
		};
		MathPoint2D newTail{
			tail.x_axis + otherMathVector2D.tail.x_axis,
			tail.y_axis + otherMathVector2D.tail.y_axis
		};
		return MathVector2D(newHead, newTail);

	};

	MathPoint2D delta_axis(){
		return MathPoint2D{
			tail.x_axis - head.x_axis,
			tail.y_axis - head.y_axis
		};
	};

	float Product(MathVector2D otherMathVector2D) {
		return (float) abs(delta_axis().x_axis * otherMathVector2D.delta_axis().x_axis + delta_axis().y_axis * otherMathVector2D.delta_axis().y_axis);
	};

};
int vector_calculate() {
	SetConsoleOutputCP(65001); // Chuyển sang console log bằng Unicode (UTF-8 with signature) để tránh vỡ font chữ.
	cout << "TÍNH TỔNG VÀ TÍCH 2 VECTOR TRONG HỆ MẶT PHẲNG TỌA ĐỘ..." << endl;

	cout << "Nhập giá trị vector 1..." << endl;
	MathVector2D Vector1;
	Vector1.input_by_head_n_tail();
	Vector1.show("THÔNG TIN VECTOR VỪA NHẬP...");

	cout << "Nhập giá trị vector 2..." << endl;
	MathVector2D Vector2;
	Vector2.input_by_head_n_tail();
	Vector2.show("THÔNG TIN VECTOR VỪA NHẬP...");

	Vector1.Sum(Vector2).show("TỔNG 2 VECTOR...");
	cout << "TÍCH VÔ HƯỚNG 2 VECTOR: " << Vector1.Product(Vector2) << endl;
	return 0;
};