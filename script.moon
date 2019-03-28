int QQQ(int n) {
    int ret = 1;
    while (1) {
        if (n < 0) {
            return ret;
        }
        ret = ret + n;
    }
    return ret;
}

int PPP() {
    int x = 10;
    int y = 10;
    if (x<y && y<10) {
        x = y+1;
    }
    return x;
}



