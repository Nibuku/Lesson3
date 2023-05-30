#include <lesson/lesson.h>
#include <stdexcept>
#include <algorithm>
using namespace std;


void Lesson::set_name(string name) { this->name = name; }
void Lesson::set_hours(int hours) { this->hours = hours; }

string Lesson::get_name() const { return name; }
int Lesson::get_hours() const { return hours; }



Lecture::Lecture(string name, int hours)
{
	this->hours = hours;
	this->name = name;
}
Practice::Practice(string name, int hours)
{
	this->hours = hours;
	this->name = name;
}
Lab::Lab(string name, int hours)
{
	this->hours = hours;
	this->name = name;
}

Lecture::Lecture() {
	name = "OOP";
	hours = 0;
}
Practice::Practice() {
	name = "OOP";
	hours = 0;
}
Lab::Lab() {
	name = "OOP";
	hours = 0;
}

LessonList::LessonList() {
	for (int i = 0; i < 6; ++i) {
		_lesson.push_back(make_shared<Lecture>());
	}
}
LessonList::LessonList(vector<ItemPtr> lesson) {
	_lesson = vector<ItemPtr>(lesson.size());
		for (int i = 0; i < _lesson.size(); ++i) {
			this->_lesson[i] = make_shared<Lecture>();
		}
}
LessonList::LessonList(vector<ItemPtr> lesson, int) {
	_lesson = vector<ItemPtr>(lesson.size());
	for (int i = 0; i < _lesson.size(); ++i) {
		this->_lesson[i] = make_shared<Lecture>();
	}
}
LessonList::LessonList(const LessonList& other) {
	this->_lesson = other._lesson;
}


int Lecture::compute_paid_hours(int groups, int subgroups) const {
	return hours;
}
int Practice::compute_paid_hours(int groups, int subgroups) const {
	return hours*groups;
}
int Lab::compute_paid_hours(int groups, int subgroups) const {
	return hours*subgroups;
}



unique_ptr<Lesson> Lecture::clone() const{
	return make_unique<Lecture>(name, hours);
}
unique_ptr<Lesson> Practice::clone() const {
	return make_unique< Practice>(name, hours);
}
unique_ptr<Lesson> Lab::clone() const {
	return make_unique<Lab>(name, hours);
}
void Practice::print(ostream& out)const {
	out << "Practice(" << name << ',' << hours << ')';
}
void Lab::print(ostream& out)const {
	out << "Lab(" << name << ',' << hours << ')';
}
void Lecture::print(ostream& out)const {
	out << "Lecture(" << name << ',' << hours << ')';
}

int LessonList::compute_sum( int groups, int subgroups, string name) const{
	int s = 0;
	for (int i = 0; i < _lesson.size(); ++i) {
		const auto value = _lesson[i]->compute_paid_hours(groups, subgroups);
		const auto r = _lesson[i];
		if (name == r->get_name()) {
			s = s + value;

		}
	}
	return s;
}
void LessonList::Swap(LessonList& other) noexcept {
	swap(_lesson, other._lesson);
}

string LessonList::compute_max_paid(int groups, int subgroups) {
	int max = 0;
	int index = 0;
	for (int i = 0; i < _lesson.size(); ++i) {
		const auto value = _lesson[i]->compute_paid_hours(groups, subgroups);
		if (max < value) {
			max =value;
			index = i;
		}
	}
	const auto r = _lesson[index];
	return r->get_name();
}

int LessonList::size() {
	return static_cast<int>(_lesson.size());
}


LessonList& LessonList::operator=(const LessonList& rhs) {
	LessonList copy(rhs);
	copy.Swap(*this);
	return *this;
}

LessonList& LessonList::operator>> (LessonList& rhs) {
	LessonList copy(rhs);
	copy.Swap(*this);
	return *this;
}
  
void LessonList::insert(int index, ItemPtr f) {
	if (index >= _lesson.size() || index < 0) {
		throw runtime_error("error1");
	}
	_lesson.insert(_lesson.begin() + index, f);
}

void LessonList::remove(int index) {
	if (index >= _lesson.size() || index < 0) {
		throw runtime_error("error1");
	}
	_lesson.erase(_lesson.begin() + index);
}

void LessonList::clear() {
	_lesson.clear();
}

ItemPtr LessonList::operator[](const int index) const {
	if (index >= _lesson.size() || index < 0) {
		throw runtime_error("error1");
	}
	return _lesson[index];
}
ItemPtr& LessonList::operator[]( int index) {
	if (index >= _lesson.size() || index < 0) {
		throw runtime_error("error1");
	}
	return _lesson[index];
}

std::istream& operator>>(std::istream& in, LessonType& t)
{
	int type;
	in >> type;
	switch (type) {
	case 0:
		t = LECTURE;
		break;
	case 1:
		t = LAB;
		break;
	case 2:
		t = PRACTICE;
		break;
	default:
		throw runtime_error("error3");
	}

	return in;
}

istream& operator>>(istream& in, shared_ptr<Lab>& t)
{
	
		cout << "Введите название предмета:OOП, Алгебра, Геометрия\n ";
		in >> t->name;
		cout << "Введите количество часов:\n ";
		in >> t->hours;

		return in;
}
istream& operator>>(istream& in, shared_ptr<Lecture>& t)
{

	cout << "Введите название предмета:OOП, Алгебра, Геометрия\n ";
	in >> t->name;
	cout << "Введите количество часов:\n ";
	in >> t->hours;

	return in;
}
istream& operator>>(istream& in, shared_ptr<Practice>& t)
{

	cout << "Введите название предмета:OOП, Алгебра, Геометрия\n ";
	in >> t->name;
	cout << "Введите количество часов:\n ";
	in >> t->hours;

	return in;
}

void LessonList::print_current(int index) {
	_lesson[index]->print(cout);
}
void LessonList::show_all() {
	cout << "Текущий список:\n";
	for (int i = 0; i < _lesson.size(); ++i) {
		cout << i << ':';
		print_current(i);
		cout << endl;
	}
}

bool operator==(const LessonList& list, const LessonList& other) {
	return (list._lesson == other._lesson);
}
bool operator!=(const LessonList& list, const LessonList& other) {
	return !(list == other);
}

bool Lecture::equals(shared_ptr<Lesson> other) const {
	const auto d_other = dynamic_pointer_cast<Lecture>(other);
	if (d_other == nullptr) {
		return false;
	}
	return (name == d_other->name && hours==d_other->hours);
}
bool Practice::equals(shared_ptr<Lesson> other) const {
	const auto d_other = dynamic_pointer_cast<Practice>(other);
	if (d_other == nullptr) {
		return false;
	}
	return (name == d_other->name && hours == d_other->hours);
}
bool Lab::equals(shared_ptr<Lesson> other) const {
	const auto d_other = dynamic_pointer_cast<Lab>(other);
	if (d_other == nullptr) {
		return false;
	}
	return (name == d_other->name && hours == d_other->hours);
}

ItemPtr LessonList::get_lesson_by_index(int index) {
	return _lesson[index];
}