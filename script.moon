int main() {
    int[] a = int[]{1,3,2,7,5};
    int[] b = a;
    sort(b, 0, 4);
    int i = 0;
    while (i < 5) {
        PRINT_INT(a[i]);
        i = i + 1;
    }
    PRINT_STR('CNT:');
    PRINT_INT(ARRAY_CNT(a));
}

struct Lesson {
    int price_;
    int time_;
};

struct Student{
    string id_;
    Lesson[] lessons_;
};

int sort(int[] a, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int i = left;
    int j = right;
    int key = a[left];
    while (i < j) {
        while (i < j && key <= a[j]) {
            j = j-1;
        }
        a[i] = a[j];
        while (i < j && key >=a[i]) {
            i = i+1;
        }
        a[j] = a[i];
    }
    a[i] = key;
    sort(a, left, i-1);
    sort(a, i+1, right);
    return 0;
}

