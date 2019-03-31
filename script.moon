int main() {
    Student stu = Student{'zhangsan', Lesson[]{Lesson{12,100}, Lesson{13,200}}};
    string id = stu.id_;
    int price1 = stu.lessons_[0].price_;
    int price2 = stu.lessons_[1].price_;
    int test = price1 / price2;
    PRINT_STR(id);
    PRINT_INT(stu.lessons_[0].price_);
}

struct Lesson {
    int price_;
    int time_;
};

struct Student{
    string id_;
    Lesson[] lessons_;
};

