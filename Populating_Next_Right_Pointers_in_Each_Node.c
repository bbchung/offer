#include <stdio.h>

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left, *right, *next;
};

void do_connect(struct TreeLinkNode *root, struct TreeLinkNode *sib)
{
    if (root == NULL)
        return;

    root->next = sib;

    do_connect(root->left, root->right);

    if (sib)
        do_connect(root->right, sib->left);
    else
        do_connect(root->right, NULL);

}

void connect(struct TreeLinkNode *root)
{
    do_connect(root, NULL);
}

int main()
{
}

