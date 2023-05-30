#pragma once
#include <string>
#include <iostream>
#include <utility>
#include <cassert>
#include <vector>
#define ItemPtr shared_ptr<Lesson>
using namespace std;


	enum LessonType
	{
		LECTURE,
		LAB,
		PRACTICE
	};

	class Lesson;
	using LessonPtr = Lesson*;


	class Lesson {
	protected:
		string name;
		int hours;
		Lesson()=default;
		Lesson(const Lesson& lesson)=default;
		Lesson& operator=(const Lesson& other) = default;
		
	public: 
		string get_name() const;
		int get_hours() const;
		void set_name(string _name);
		void set_hours(int _hours);
		virtual int compute_paid_hours(int groups, int subgroups) const = 0;
		virtual unique_ptr<Lesson> clone() const = 0;
		virtual bool equals(shared_ptr<Lesson> other) const = 0;
		virtual void print(ostream& out) const = 0;
		virtual ~Lesson() = default;
		/*friend std::ostream& operator<<(std::ostream& out, Lesson& t);
		friend std::istream& operator>>(std::istream& in, Lesson& t);*/
		
	};
	
	class Lecture: public Lesson {
	public: 
		Lecture();
		~Lecture()=default;
		Lecture(string name, int hours);

		unique_ptr<Lesson> clone() const override;
		bool equals(shared_ptr<Lesson> other) const override;
		void print(ostream& out) const override;
		int compute_paid_hours(int groups, int subgroups) const override;
		friend std::istream& operator>>(std::istream& in, shared_ptr<Lecture>& t );
	};
	class Practice : public Lesson {
	public:
		Practice();
		~Practice()=default;
		Practice(string name, int hours);

		unique_ptr<Lesson> clone() const override;
		bool equals(shared_ptr<Lesson> other) const override;
		void print(ostream& out) const override;
		int compute_paid_hours(int groups, int subgroups) const override;
		friend std::istream& operator>>(std::istream& in, shared_ptr<Practice>& t);
	};
	class Lab : public Lesson {
	public:
		Lab();
		~Lab()=default;
		Lab(string name, int hours);

		unique_ptr<Lesson> clone() const override;
		bool equals(shared_ptr<Lesson> other) const override;
		void print(ostream& out) const override;
		int compute_paid_hours(int groups, int subgroups) const override;
		friend std::istream& operator>>(std::istream& in, shared_ptr<Lab>& t);
	};

	class LessonList {
		vector<ItemPtr> _lesson;
	public:
		LessonList();
		LessonList(vector<ItemPtr> lesson);
		LessonList(vector<ItemPtr> lesson, int );
		LessonList(const LessonList& other);

		ItemPtr get_lesson_by_index(int index);
		int size();

		void insert(int index, ItemPtr lesson);
		void remove(int index);

		ItemPtr operator[](int index) const;
		ItemPtr& operator[](int ind);
		LessonList& operator=(const LessonList& rhs);
		friend bool operator==(const LessonList& list, const LessonList& other);
		friend bool operator!=(const LessonList& list, const LessonList& other);
		LessonList& operator>>(LessonList& rhs);

		int compute_sum( int groups, int subgroups, string name) const;
		string compute_max_paid( int groups, int subgroups);
		
		void Swap(LessonList& other) noexcept;
		void print_current(int index);
		void show_all();
		void clear();
	};
	

