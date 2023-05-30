#include <windows.h>
#include <iostream>
#include <lesson/lesson.h>
#include <stdexcept>
#include <string>



using namespace std;

void menu() {
	system("cls");
	cout << "��� �� ������ �������? ������� ����� �� 1 �� 6" << endl;
	cout << "1 - �������� ������� � ������ �� ���������� �������" << endl;
	cout << "2 - ������� ������� �� ������ �� ���������� �������" << endl;
	cout << "3 - ������� ������ �� �����" << endl;
	cout << "4 - ����������� �������� ������ ���������� � ������������ ����������� ������������ ����� �� ���� ��������" << endl;
	cout << "5 - ���������� ������� ���������� ������������ ����� �� ��������� ��������" << endl;
	cout << "6 - ��������� ���������" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int s=0;
	int idx, type;
	int n;
	int m;
	string p;
	shared_ptr<Lecture> lecture = make_shared<Lecture>();
	shared_ptr<Practice> practice = make_shared<Practice>();
	shared_ptr<Lab> lab = make_shared<Lab>();
	LessonList f = LessonList();
	while (s != 6) {
		menu();
		cin >> s;
		switch (s)
		{
		case 1:
			system("cls");
			cout << "�������� ������" << endl;
			cin >> idx;
			cout << "������� ���: (0-������, 1-����, 2-��������)" << endl;
			cin >> type;
			switch (type) {
			case 0:
				cin >> lecture;
				f.insert(idx, lecture);
				break;
			case 1:
				cin >> lab;
				f.insert(idx, lab);
				break;
			case 2:
				cin >> practice;
				f.insert(idx, practice);
				break;
			}	
			break;

		case 2:
			system("cls");
			cout << "������� ������ ���������� ��������" << endl;
			cin >> idx;
			f.remove(idx);
			break;
		case 3:
			system("cls");
			f.show_all();
			break;
		case 4:
			system("cls");
			cout << "������� ���������� �����" << endl;
			cin >> n;
			cout << "������� ���������� ��������" << endl;
			cin >> m;
			cout<<f.compute_max_paid(n,m) << endl;
			break;
		case 5:
			system("cls");
			cout << "������� �������� ��������:���, �������, ��������� ��� ������" << endl;
			cin >> p;
			cout << "������� ���������� �����" << endl;
			cin >> n;
			cout << "������� ���������� ��������" << endl;
			cin >> m;
			cout << f.compute_sum(n,m,p) << endl;
			break;
		}
		if (s != 6) {
			system("pause");
		}
	}
}
