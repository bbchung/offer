#include <queue>
#include "node.h"

void bfs(std::queue<TreeNode*>* helper)
{
    if (helper == NULL)
        return;

    while (!helper->empty())
    {
        TreeNode* front = helper->front();
        printf("%d ", front->value);

        if (front->left != NULL)
            helper->push(front->left);

        if (front->right != NULL)
            helper->push(front->right);

        helper->pop();
    }

    printf("\n");
}

void bfs(TreeNode* pRoot)
{
    if (pRoot == NULL)
        return;

    std::queue<TreeNode*> helper;
    helper.push(pRoot);
    bfs(&helper);
}


int main()
{
    TreeNode* pRoot = CreateSimpleTree();
    bfs(pRoot);
}
