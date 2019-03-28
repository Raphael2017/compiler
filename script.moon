struct Lesson {
    int price_;
    int start_time_;
};

struct Student {
    int id_;
    Lesson[] lessons_;
};

typedef Lesson[] Lessons;

int main() {
    Student stu = Student{10, Lessons{Lesson{10,20101024},Lesson{11,20101125}}};
}