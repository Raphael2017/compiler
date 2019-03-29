struct LinkedList {
    int data_;
    LinkedList next_;
};

LinkedList insert_front(LinkedList head, int data) {
    return LinkedList{ data, head };
}

int sum(LinkedList head) {
    LinkedList it = head;
    int ret = 0;
    while (it <> nil) {
        ret = ret + it.data_;
    }
    return ret;
}

int main() {
    -- Primes less than 100
    int i = 0;
    LinkedList primes = nil;
    while (i < 100) {
        if (is_prime(i)) {
            primes = insert_front(primes, i);
        }
        i = i + 1;
    }
}

int is_prime(int i) {
    int t = 1;
    int ret = 1;
    while (t < i / 2) {
        if ((t - (t/i)*i) == 0) {   -- Calculate remainder
            ret = 0;
            break;
        }
        t = t + 1;
    }
    return ret;
}