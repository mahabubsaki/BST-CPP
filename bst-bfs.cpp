#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int id;
    int value;
    node *Left;
    node *Right;
    node *Parent;
};
class BinaryTree
{
public:
    node *Root;

    BinaryTree()
    {
        Root = nullptr;
    }
    node *CreateNewNode(int id, int value)
    {
        node *newNode = new node;
        newNode->id = id;
        newNode->value = value;
        newNode->Left = nullptr;
        newNode->Right = nullptr;
        newNode->Parent = nullptr;
        return newNode;
    }
    void build_binary_tree()
    {
        node *allNode[6];
        for (int i = 0; i < 6; i++)
        {
            allNode[i] = CreateNewNode(i, i * 2);
        }
        allNode[0]->Left = allNode[1];
        allNode[0]->Right = allNode[2];

        allNode[1]->Left = allNode[5];
        allNode[1]->Parent = allNode[0];

        allNode[2]->Left = allNode[3];
        allNode[2]->Right = allNode[4];
        allNode[2]->Parent = allNode[0];

        allNode[5]->Parent = allNode[1];

        allNode[3]->Parent = allNode[2];

        allNode[4]->Parent = allNode[2];
        Root = allNode[0];
    }
    void bfs_traversel()
    {
        if (!Root)
            return;
        queue<node *> q;
        q.push(Root);
        while (q.size())
        {
            node *frontPart = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if (frontPart->Parent)
                p = frontPart->Parent->id;
            if (frontPart->Left)
            {
                l = frontPart->Left->id;
                q.push(frontPart->Left);
            };
            if (frontPart->Right)
            {
                r = frontPart->Right->id;
                q.push(frontPart->Right);
            }
            cout << "Node id = " << frontPart->id << " Parent = " << p << " Left Child = " << l << " Right Child = " << r << endl;
        }
    }
    void Insert(int id, int value)
    {
        node *newNode = CreateNewNode(id, value);
        if (!Root)
        {
            Root = newNode;
            return;
        }
        queue<node *> q;
        q.push(Root);
        while (q.size())
        {
            node *frontPart = q.front();
            q.pop();
            if (frontPart->Left)
            {
                q.push(frontPart->Left);
            }
            else
            {
                frontPart->Left = newNode;
                newNode->Parent = frontPart;
                return;
            }
            if (frontPart->Right)
            {
                q.push(frontPart->Right);
            }
            else
            {
                frontPart->Right = newNode;
                newNode->Parent = frontPart;
                return;
            }
        }
    };
    void Search(node *a, int value)
    {
        if (!a)
        {
            return;
        }
        if (a->value == value)
        {
            cout << a->id << " ";
        }
        Search(a->Left, value);
        Search(a->Right, value);
    }
};
int main()
{
    BinaryTree bt;
    bt.Insert(0, 5);
    bt.Insert(1, 10);
    bt.Insert(2, 15);
    bt.Insert(3, 9);
    bt.Insert(4, 5);
    bt.Insert(5, 19);
    bt.Insert(6, 9);
    bt.Search(bt.Root, 5);
    cout << endl;
    bt.Search(bt.Root, 10);
    return 0;
}