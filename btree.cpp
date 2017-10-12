#include <iostream>
#include "btree.h"
#include <stack>
#include<queue>
   
using std::stack;
using std::queue;

namespace sarylanc_alg{
    void add_recursion(btnode* start, int val){
        if(!start) return;
        if(start->val == val) {start->count++; return;}
        else if(start->val > val){
            if(!start->left){
                btnode* left = new btnode();
                left->val = val;
                left->count++;
                start->left = left;
            } else{
                add_recursion(start->left, val);
            }
        } else{
            if(!start->right){
                btnode* right = new btnode();
                right->val = val;
                right->count++;
                start->right = right;
            } else{
                add_recursion(start->right, val);
            }
        }
    }

    bool del_recursion(btnode *&node, int val){
        if(!node){ return false; }
        if(node->val == val && --node->count == 0){
            btnode* tar = nullptr;
            btnode* tarfa = nullptr;
            if(node->left){
                tar = node->left;
                while(tar->right){
                    tarfa = tar;
                    tar = tar->right;
                }
                if(tar != node->left){
                    tar->left = node->left;
                    tar->right = node->right;
                    tarfa->right = nullptr;
                    delete node;
                    node = tar;
                } else{
                    tar->right = node->right;
                    delete node;
                    node = tar;
                }

            } else if(node->right){
                tar = node->right;
                while(tar->left){
                    tarfa = tar;
                    tar = tar->left;
                }
                if(tar != node->right){
                    tar->left = node->left;
                    tar->right = node->right;
                    tarfa->left = nullptr;
                    delete node;
                    node = tar;
                } else{
                    tar->left = node->left;
                    delete node;
                    node = tar;
                }
            } else{
                delete node;
                node = nullptr;
            }
        }
        else if(node->val > val){
            del_recursion(node->left, val);
        }
        else{
            del_recursion(node->right, val);
        }
    }

    void pre_order_recursion(btnode *node){
        if(!node) return;
        printf("%d\t", node->val);
        pre_order_recursion(node->left);
        pre_order_recursion(node->right);
    }

    void mid_order_recursion(btnode* node){
        if(!node) return;
        mid_order_recursion(node->left);
        printf("%d\t", node->val);
        mid_order_recursion(node->right);
    }

    void pos_order_recursion(btnode* node){
        if(!node) return;
        pos_order_recursion(node->left);
        pos_order_recursion(node->right);
        printf("%d\t", node->val);
    }

    void add_loop(btnode *start, int val){
        if(!start) return;
        btnode* far = nullptr;
        btnode* cur = start;
        epos pos = POS_NOT_EXISTED;
        while(cur){
            if(cur->val > val){
                far = cur;
                cur = far->left;
                pos = POS_LEFT_CHILD;
            } else if(cur->val < val){
                far = cur;
                cur = far->right;
                pos = POS_RIGHT_CHILD;
            } else{
                cur->count++;
                return;
            }
        }
        cur = new btnode();
        cur->val = val;
        cur->count++;
        if(pos == POS_LEFT_CHILD) far->left = cur;
        else far->right = cur;
    }

    void pre_order_loop(btnode* node){
        if(!node) return;
        btnode* p = node;
        stack<btnode*> st;
        while(!st.empty() || p){
            while(p){
                printf("%d\t", p->val);
                st.push(p);
                p= p->left;
            }
            if(!st.empty()){
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
    }

    void mid_order_loop(btnode* node){
        if(!node) return;
        btnode* p = node;
        stack<btnode*> st;
        while(!st.empty() || p){
            while(p){
                st.push(p);
                p = p->left;
            }
            if(!st.empty()){
                p = st.top();
                printf("%d\t", p->val);
                st.pop();
                p = p->right;
            }
        }
    }

    void pos_order_loop(btnode* node){
        if(!node) return;
        btnode* p = node;
        stack<btnode*> st;
        btnode* cur, *last;
        cur = node;
        last = nullptr;
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        while(!st.empty()){
            cur = st.top();
            st.pop();
            if(!cur->right || cur->right == last){
                printf("%d\t", cur->val);
                last = cur;
            } else {
                st.push(cur);
                cur = cur -> right;
                while(cur){
                    st.push(cur);
                    cur = cur->left;
                }
            }
        }
    }

    void level_order(btnode* node){
        if(!node) return;
        queue<btnode*> st;
        while(!st.empty()){
            btnode *p = st.front();
            st.pop();
            printf("%d\t", p->val);
            if(p->left) st.push(p->left);
            if(p->right) st.push(p->right);
        }
    }
}
