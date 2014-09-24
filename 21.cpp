#include <stdio.h>
#include <limits.h>
struct Node
{
    int value;
    Node *next;
    Node *prev;
};

class Stack
{
public:
    Stack()
        : pListHead(nullptr)
    {
    }

    virtual ~Stack()
    {
    }

    void PrintAll()
    {
        Node *curr = pListHead;

        while (curr != nullptr)
        {
            printf("%d ", curr->value);
            curr = curr->prev;
        }

        printf("\n");
    }

    void Push(int val)
    {
        Node *node = new Node;
        node->value = val;
        node->next = nullptr;
        node->prev = nullptr;

        if (pListHead != nullptr)
        {
            node->prev = pListHead;
            pListHead->next = node;
        }

        pListHead = node;
    }

    bool Pop(int &retval)
    {
        if (pListHead == nullptr)
            return false;

        retval = pListHead->value;

        Node *last = pListHead;

        pListHead = pListHead->prev;

        if (pListHead != nullptr)
            pListHead->next = nullptr;

        delete last;

        return true;
    }

    bool Top(int &retval)
    {
        if (pListHead == nullptr)
            return false;

        retval = pListHead->value;

        return true;
    }

private:
    Node *pListHead;
};

class MinStack
{
public:
    MinStack()
    {
    }
    virtual ~MinStack()
    {
    }

    void Push(int val)
    {
        m_data.Push(val);

        int top;
        bool empty = !m_min.Top(top);

        if (empty || val < top)
            m_min.Push(val);
        else
            m_min.Push(top);
    }

    bool Pop(int &val)
    {
        bool succ = m_data.Pop(val);
        int top;
        m_min.Pop(top);

        return succ;
    }

    bool Min(int &value) // O(1) required
    {
        return m_min.Top(value);
    }

private:
    /* data */

    Stack m_min;
    Stack m_data;
};

int main()
{
    MinStack stack;
    stack.Push(3);
    stack.Push(2);
    stack.Push(4);
    stack.Push(5);
    stack.Push(1);

    int top;
    stack.Pop(top);
    stack.Pop(top);
    stack.Pop(top);
    stack.Pop(top);
    stack.Pop(top);
    stack.Pop(top);
    int min;
    stack.Min(min);

    printf("%d\n", min);
}
