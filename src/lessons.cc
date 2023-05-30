#include <windows.h>
#include <iostream>
#include <lesson/lesson.h>
#include <stdexcept>
#include <string>



using namespace std;

void menu() {
	system("cls");
	cout << "Что вы хотите сделать? Введите цифру от 1 до 6" << endl;
	cout << "1 - вставить элемент в список по указанному индексу" << endl;
	cout << "2 - удалить элемент из списка по указанному индексу" << endl;
	cout << "3 - вывести список на экран" << endl;
	cout << "4 - определение названия первой дисциплины с максимальным количеством оплачиваемых часов по всем занятиям" << endl;
	cout << "5 - вычисление полного количества оплачиваемых часов по заданному названию" << endl;
	cout << "6 - завершить программу" << endl;
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
			cout << "Ввведите индекс" << endl;
			cin >> idx;
			cout << "Введите тип: (0-Лекция, 1-Лаба, 2-Практика)" << endl;
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
			cout << "Введите индекс удаляемого элемента" << endl;
			cin >> idx;
			f.remove(idx);
			break;
		case 3:
			system("cls");
			f.show_all();
			break;
		case 4:
			system("cls");
			cout << "Введите количество групп" << endl;
			cin >> n;
			cout << "Введите количество подгрупп" << endl;
			cin >> m;
			cout<<f.compute_max_paid(n,m) << endl;
			break;
		case 5:
			system("cls");
			cout << "Введите название предмета:ООП, Алгебра, Геометрия или другое" << endl;
			cin >> p;
			cout << "Введите количество групп" << endl;
			cin >> n;
			cout << "Введите количество подгрупп" << endl;
			cin >> m;
			cout << f.compute_sum(n,m,p) << endl;
			break;
		}
		if (s != 6) {
			system("pause");
		}
	}
}
