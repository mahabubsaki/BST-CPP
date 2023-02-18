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
        node *allNode[9];
        // for (int i = 0; i < 6; i++)
        // {
        //     allNode[i] = CreateNewNode(i, i * 2);
        // }
        allNode[0] = CreateNewNode(0, 20);
        allNode[1] = CreateNewNode(1, 10);
        allNode[2] = CreateNewNode(2, 22);
        allNode[3] = CreateNewNode(3, 5);
        allNode[4] = CreateNewNode(4, 12);
        allNode[5] = CreateNewNode(5, 21);
        allNode[6] = CreateNewNode(6, 25);
        allNode[7] = CreateNewNode(7, 3);
        allNode[8] = CreateNewNode(8, 15);

        allNode[0]->Left = allNode[1];
        allNode[0]->Right = allNode[2];

        allNode[1]->Left = allNode[3];
        allNode[1]->Right = allNode[4];
        allNode[1]->Parent = allNode[0];
        allNode[3]->Parent = allNode[1];
        allNode[4]->Parent = allNode[1];

        allNode[2]->Left = allNode[5];
        allNode[2]->Right = allNode[6];
        allNode[2]->Parent = allNode[0];
        allNode[5]->Parent = allNode[2];
        allNode[6]->Parent = allNode[2];

        allNode[3]->Left = allNode[7];
        allNode[3]->Right = allNode[8];
        allNode[7]->Parent = allNode[3];
        allNode[8]->Parent = allNode[3];
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
                p = frontPart->Parent->value;
            if (frontPart->Left)
            {
                l = frontPart->Left->value;
                q.push(frontPart->Left);
            };
            if (frontPart->Right)
            {
                r = frontPart->Right->value;
                q.push(frontPart->Right);
            }
            cout << "Node id = " << frontPart->value << " Parent = " << p << " Left Child = " << l << " Right Child = " << r << endl;
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
    bt.build_binary_tree();
    bt.bfs_traversel();
    return 0;
}