#include <list>

#include "node.h"

void PrintPath(std::list<int> *path)
{
    if (path == NULL)
        return;

    for (std::list<int>::iterator it = path->begin(); it != path->end(); ++it)
        printf("%d ", (*it));

    printf("\n");
}

void FindPath(TreeNode *pRoot, std::list<int> *path, int *sum, int number)
{
    if (pRoot == NULL || path == NULL || sum == NULL)
        return;

    path->push_back(pRoot->value);
    *sum += pRoot->value;
    if (*sum == number)
        PrintPath(path);

    if (pRoot->left != NULL)
        FindPath(pRoot->left, path, sum, number);

    if (pRoot->right != NULL)
        FindPath(pRoot->right, path, sum, number);

    path->pop_back();
    *sum -= pRoot->value;
}

int main()
{
    TreeNode *root = CreateTree2();
    std::list<int> list;
    int sum = 0;
    FindPath(root, &list, &sum, 22);

    DeleteTree(root);
}

