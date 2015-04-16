#include <vector>
#include <queue>
#include <iostream>

#ifndef NULL
#define NULL (0)
#endif

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};


/**
 * Definition for binary tree
  */
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v;
        queue<struct TreeNode *> q1;
        queue<struct TreeNode *> q2;

        queue<struct TreeNode *> *pq1 = &q1;
        queue<struct TreeNode *> *pq2 = &q2;

        if (!root)
            return v;

        pq1->push(root);

        while (1)
        {
            v.push_back(pq1->back()->val);

            while (pq1->size() != 0)
            {
                root = pq1->front();
                pq1->pop();

                if (root->left)
                    pq2->push(root->left);

                if (root->right)
                    pq2->push(root->right);
            }

            if (pq2->size() == 0)
                break;

            queue<struct TreeNode *> *tmp = pq1;
            pq1 = pq2;
            pq2 = tmp;
        }

        return v;
    }
};

int main()
{
    struct TreeNode n1(1);
    struct TreeNode n2(2);
    struct TreeNode n3(3);
    struct TreeNode n4(4);
    struct TreeNode n5(5);

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n4.right = &n5;

    Solution sol;

    vector<int> v = sol.rightSideView(&n1);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}
