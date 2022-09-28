#include"global.h"
#include"2263.h"


int main()
{
    int n;
    cin >> n;
    Algorithm algo;
    algo.makeTree(n);
    algo.root = algo.dfs(algo.root, 0, n - 1, 0, n - 1, false);
    algo.pre(algo.root->rc);

    return 0;
}