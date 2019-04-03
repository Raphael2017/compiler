int main() {
    int[] a = int[] {1,28,2,199,1,0};
    sort(a, 0, ARRAY_CNT(a)-1);
    int i = 0;
    while (i < ARRAY_CNT(a)) {
        PRINT_INT(a[i]);
        i = i + 1;
    }
}

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

