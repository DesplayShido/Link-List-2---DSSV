#include <iostream>
#include <string>
#include "LinkListDSSV.h"

using namespace std;

void DanhSanh() {
	cout << "1: Tot" << endl;
	cout << "2: Kha" << endl;
	cout << "3: Trung binh" << endl;
	cout << "4: Yeu" << endl;
}

void DownLine() {
	cout << "=================================" << endl;
}

int main() 
{
	int n, x;
	Data data;
	Node* node;
	LinkList list;
	CreateList(list);
	cout << "Nhap n: ";
	cin >> n;

	//Cau18: Nhap danh sach sinh vien 
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
		cout << "MSSV: ";
		cin >> data.mssv;
		cin.ignore();
		cout << "Ho va ten: ";
		getline(cin, data.ten);
		cout << "Lop: ";
		cin >> data.lop;
		cout << "Diem tong ket: ";
		cin >> data.dtb;
		backcinhanhkiem:
		cout << "Hanh kiem: " << endl;
		DanhSanh();
		cin >> x;
		if (x < 1 || x > 4) {
			cout << "Nhap sai hanh kiem, moi nhap lai !" << endl;
			goto backcinhanhkiem;
		}
		data.hanhkiem = x;
		node = CreateNode(data);
		AddTail(list, node);
		DownLine();
	}

	//Cau18: Xuat danh sach sinh vien da nhap
	cout << "Danh sach sinh vien da nhap: " << endl;
	PrintList(list);
	DownLine();

	//Cau18: Xuat danh sach sinh vien theo lop
	cout << "Nhap ten lop: ";
	string Lop;
	cin >> Lop;
	cout << "Nhung sinh vien thuoc lop " << Lop << " la: " << endl;
	PrintListWithCondition(list, Lop);
	DownLine();

	//Cau18: Xuat danh sach sau khi sap xep theo MSSV
	ArrangeList(list);
	cout << "Danh sach sinh vien sau khi duoc sap xep theo MSSV la: " << endl;
	PrintList(list);
	DownLine();

	//Cau18: Xoa phan tu cuoi cung trong danh sach roi xuat ra
	if (RemoveTail(list) == 0) {
		cout << "Xoa phan tu cuoi cung khong thanh cong !" << endl;
	}
	else {
		cout << "Danh sach sau khi xoa phan tu cuoi cung la: " << endl;
		PrintList(list);
	}
	DownLine();
	return 0;
}