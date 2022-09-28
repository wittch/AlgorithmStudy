#include"2263.h"
#include"global.h"



class Algorithm;

void Algorithm::makeTree(int data)
{
    Algorithm::root = (node*)malloc(sizeof(node));
    ino = new int[100001];
    pos = new int[100001];

    root->data = -1;
    root->lc = NULL;
    root->rc = NULL;


    for (int i = 0; i < data; i++)
    {
        int tmp;
        cin >> tmp;
        ino[i] = tmp;
    }

    for (int i = 0; i < data; i++)
    {
        int tmp;
        cin >> tmp;
        pos[i] = tmp;
    }

}

Algorithm::node* Algorithm::dfs(node* prev, int inofr, int inobk, int posfr, int posbk, bool flg)
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->lc = NULL;
    tmp->rc = NULL;
    tmp->data = NULL;

    if (inofr == inobk)
    {
        tmp->data = ino[inofr];
        if (flg)
            prev->lc = tmp;
        else
            prev->rc = tmp;

        return prev;
    }

    for (int i = 0; i <= inobk - inofr; i++)
    {
        if (pos[posbk] == ino[inofr + i])
        {
            tmp->data = pos[posbk];
            if (flg)
                prev->lc = tmp;
            else
                prev->rc = tmp;

            if (i >= 1)
                dfs(tmp, inofr, inofr + i - 1, posfr, posfr + i - 1, true);
            if (inofr + i + 1 <= inobk)
                dfs(tmp, inofr + i + 1, inobk, posfr + i, posbk - 1, false);


            break;
        }
    }

    return prev;
}
 
void Algorithm::pre(node* curr)
{
    if (curr == NULL)
        return;
    cout << curr->data << " ";
    pre(curr->lc);
    pre(curr->rc);
}