struct Lesson {
    int time_;
    int price_;
};

struct Student {
    int id_;
    Lesson[] lessons_;
};

int test1(int[] a, int b) {
    alpha = b;
    int c = 100;
    c = -c + b;
    return test(b,a) + c;
}

int test(int a, int[] b) {
    a = b[0] + b[1];
    return a;
}

int jiechen(int a) {
    if (a > 1) {
        return a*jiechen(a-1);
    }
    else {
        return 1;
    }
}

int PPP() {
    Student stu;
    Student stu1;
    stu = stu1;
    stu.id_ = 10;
    stu.lessons_[0].price_ = 100;
    return 0;
}

int alpha = 10;
int beta = 20;



