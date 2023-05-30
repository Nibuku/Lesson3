#include <gtest/gtest.h>
#include <lesson/lesson.h>
using namespace std;

TEST(LessonTests, LabTest1) {
    Lab lesson("OOP", 5);
    int r = lesson.compute_paid_hours(4, 8);
    EXPECT_EQ(r, 40);
}


TEST(LessonTests, LectureTest1) {
    Lecture lesson("Алгебра", 5);
    int r = lesson.compute_paid_hours(4, 8);
    EXPECT_EQ(r, 5);
}

TEST(LessonTests, PracticeTest1) {
    Lecture lesson("Геометрия", 5);
    int r = lesson.compute_paid_hours(4, 8);
    EXPECT_EQ(r, 5);
}

TEST(LessonTests, ForGetName) {
    Lecture lesson("Геометрия", 5);
    string r = lesson.get_name();
    EXPECT_EQ(r, "Геометрия");
}

TEST(LessonTests, ForGetHours) {
    Practice lesson("Алгебра", 5);
    int r = lesson.get_hours();
    EXPECT_EQ(r, 5);
}

TEST(LessonTests, SetName) {
    Lecture lesson;
    lesson.set_name("OOP");
    EXPECT_EQ(lesson.get_name(), "OOP");
}
TEST(LessonTests, Sethours) {
    Lab lesson;
    lesson.set_hours(12);
    EXPECT_EQ(lesson.get_hours(), 12);
}

TEST(LessonTests, Compute1Sum) {
    LessonList lesson= LessonList();
    EXPECT_EQ(lesson.compute_sum( 4, 8, "OOP"), 0);
}

TEST(LessonListTests, LessonListDefaultConstructorTest) {
    LessonList ll = LessonList();
    EXPECT_EQ(ll.size(), 6);
}

TEST(LessonListTests, LessonListInsertTest) {
    LessonList ll = LessonList();
    ItemPtr lesson = make_shared<Lab>("OOP", 8);
    ll.insert(1, lesson);
    EXPECT_EQ(ll.size(), 7);
    EXPECT_EQ(ll[1]->get_name(), "OOP");
    EXPECT_EQ(ll[1]->get_hours(), 8);
}

TEST(LessonListTests, LessonListRemoveTest) {
    LessonList ll = LessonList();
    ll.remove(0);
    EXPECT_EQ(ll.size(), 5);
}

TEST(LessonListTests, LessonListClearTest) {
    LessonList ll = LessonList();
    ll.clear();
    EXPECT_EQ(ll.size(), 0);
}

TEST(LessonListTests, LessonListMaxComputeTest) {
    LessonList ll = LessonList();
    ItemPtr one = make_shared<Lab>("OOP", 48);
    ItemPtr two = make_shared<Lab>("Алгебра", 8);
    ItemPtr tree = make_shared<Practice>("Алгебра", 8);
    ItemPtr four = make_shared<Lecture>("Алгебра", 8);
    ll.insert(1, one);
    ll.insert(2, two);
    ll.insert(3,tree);
    ll.insert(4, four);
    string r = ll.compute_max_paid(2, 4);
    EXPECT_EQ(r, "OOP");
}


TEST(lessonTests, LessonIndexOutTest) {
    LessonList ll = LessonList();
    EXPECT_THROW(ll.remove(-1), std::runtime_error);
    EXPECT_THROW(ll.remove(10), std::runtime_error);
}

TEST(LessonListTests, LessonListCtorAndOPCpyTest) {
  
    LessonList EL = LessonList();
    LessonList EL2(EL);
    LessonList EL3 = EL;
    EXPECT_EQ(EL, EL2);
    EXPECT_EQ(EL, EL3);
}