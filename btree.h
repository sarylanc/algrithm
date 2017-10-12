namespace sarylanc_alg {
    struct btnode{
        int val;
        int count;
        btnode* left;
        btnode* right;
    };

    enum epos {
        POS_NOT_EXISTED = -1,
        POS_LEFT_CHILD,
        POS_RIGHT_CHILD
    };

    void add_recursion(btnode *node, int val);
    bool del_recursion(btnode *&node, int val);
    void pre_order_recursion(btnode *node);
    void mid_order_recursion(btnode* node);
    void pos_order_recursion(btnode* node);

    void add_loop(btnode *node, int val);
    void pre_order_loop(btnode* node);
    void mid_order_loop(btnode* node);
    void pos_order_loop(btnode* node);

    void level_order(btnode* node);
}

