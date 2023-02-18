#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int id;
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
    node *CreateNewNode(int id)
    {
        node *newNode = new node;
        newNode->id = id;
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
        allNode[0] = CreateNewNode(20);
        allNode[1] = CreateNewNode(10);
        allNode[2] = CreateNewNode(22);
        allNode[3] = CreateNewNode(5);
        allNode[4] = CreateNewNode(12);
        allNode[5] = CreateNewNode(21);
        allNode[6] = CreateNewNode(25);
        allNode[7] = CreateNewNode(3);
        allNode[8] = CreateNewNode(15);

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
    void preorder_traversel(node *a)
    {
        if (!a)
        {
            return;
        }
        cout << a->id << " ";
        preorder_traversel(a->Left);

        preorder_traversel(a->Right);
    }
    void inorder_traversel(node *a)
    {
        if (!a)
        {
            return;
        }

        inorder_traversel(a->Left);
        cout << a->id << " ";
        inorder_traversel(a->Right);
    }
    void postorder_traversel(node *a)
    {
        if (!a)
        {
            return;
        }

        postorder_traversel(a->Left);

        postorder_traversel(a->Right);
        cout << a->id << " ";
    }
};
int main()
{
    BinaryTree bt;
    bt.build_binary_tree();
    bt.postorder_traversel(bt.Root);
    return 0;
}

// inorder-traversel => node->left + node->root + node->right
// preorder-traversel => node->root +node->left + node->right
// postorder-traversel => node->left + node->right + root