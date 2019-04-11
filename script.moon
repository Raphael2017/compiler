struct BinaryNode {
    int data_;
    BinaryNode l_;
    BinaryNode r_;
};

int qwerty() {
    BinaryNode tree = BinaryNode{10, NIL, NIL};
    insert_binary_tree(tree, 8);
    insert_binary_tree(tree, 2);
    insert_binary_tree(tree, 66);
    insert_binary_tree(tree, 21);
    insert_binary_tree(tree, 123);
    print_binary_tree(tree);
}

int insert_binary_tree(BinaryNode node, int data) {
    BinaryNode p = node;
    int ret = 0;
    while (p <> NIL) {
        if (p.data_ == data) {
            ret = -1;
            break;
        }
        else {
            if (p.data_ < data) {
                if (p.r_ == NIL) {
                    p.r_ = BinaryNode{data, NIL, NIL};
                    ret = 0;
                    break;
                }
                else {
                    p = p.r_;
                }
            }
            else {
                if (p.l_ == NIL) {
                    p.l_ = BinaryNode{data, NIL, NIL};
                    ret = 0;
                    break;
                }
                p = p.l_;
            }
        }
    }
    return ret;
}

int print_binary_tree(BinaryNode node) {
    if (NIL == node) {
        return -1;
    }
    print_binary_tree(node.l_);
    PRINT_INT(node.data_);
    print_binary_tree(node.r_);
}


int alpha = 110;

