#pragma once

class Algorithm {
    struct node {
        int data;
        node* lc;
        node* rc;
    };
public:
    /*int ino[100001];
    int pos[100001];*/
    int* ino;
    int* pos;
    node* root;
    node* dfs(node* prev, int inofr, int inobk, int posfr, int posbk, bool flg);
    void makeTree(int data);
    void pre(node* curr);
};
