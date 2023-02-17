#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node *l;
    node *r;
};
class BST
{
public:
    node *root;
    BST()
    {
        root = nullptr;
    }
    node *CreateNewNode(int value)
    {
        node *newNode = new node;
        newNode->l = nullptr;
        newNode->r = nullptr;
        newNode->value = value;
        return newNode;
    }
    void BFS()
    {
        if (!root)
        {
            return;
        }
        queue<node *> que;
        que.push(root);
        while (que.size())
        {
            node *front = que.front();
            que.pop();
            if (front->l)
                que.push(front->l);
            if (front->r)
                que.push(front->r);
            cout << front->value << " ";
        }
    }
    void Insert(int value)
    {
        node *newNode = CreateNewNode(value);
        if (!root)
        {
            root = newNode;
            return;
        }
        node *current = root;
        node *prev = nullptr;
        while (current)
        {
            if (newNode->value > current->value)
            {
                prev = current;
                current = current->r;
            }
            else
            {
                prev = current;
                current = current->l;
            }
        }
        if (newNode->value > prev->value)
        {
            prev->r = newNode;
        }
        else
        {
            prev->l = newNode;
        }
    }
    bool Search(int value)
    {
        node *current = root;
        while (current)
        {
            if (value > current->value)
            {
                current = current->r;
            }
            else if (value < current->value)
            {
                current = current->l;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    void Delete(int value)
    {
        node *current = root;
        node *previous = nullptr;
        while (current)
        {
            if (value > current->value)
            {
                previous = current;
                current = current->r;
            }
            else if (value < current->value)
            {
                previous = current;
                current = current->l;
            }
            else
            {
                break;
            }
        }
        if (!current)
        {
            cout << "Value not found" << endl;
            return;
        }
        // if found values left and right childs are null
        if (!current->l && !current->r)
        {
            if (previous->l && previous->l->value == current->value)
            {
                previous->l = nullptr;
            }
            else
            {
                previous->r = nullptr;
            }
            delete current;
            return;
        }
        // if found values left or right child have values;
        if (!current->l && current->r)
        {
            if (previous->l && previous->l->value == current->value)
            {
                previous->l = current->r;
            }
            else
            {
                previous->r = current->r;
            }
            delete current;
            return;
        }
        if (!current->r && current->l)
        {
            if (previous->l && previous->l->value == current->value)
            {
                previous->l = current->l;
            }
            else
            {
                previous->r = current->l;
            }
            delete current;
            return;
        }
        // if found values have right and left child available
        node *temp = current->r;
        while (temp->l)
        {
            temp = temp->l;
        }
        int saved = temp->value;
        Delete(saved);
        current->value = saved;
    }
};
int main()
{
    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);

    bst.Delete(6);
    bst.BFS();
    // cout << bst.Search(54);
    return 0;
}