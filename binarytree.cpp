#include <iostream>
#include<queue>

using namespace std;


//Representation of Node as a class
class node {
public:
    int data;
    node* left;
    node* right;

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};


//Creation of tree
node* buildtree(node* root)
{
    int data;
    cout << "enter the data :- ";
    cin >> data;
    cout << "\n";
    //1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 13 -1 -1 7 14 -1 -1 -1
    //1 2 4 -1 8 -1 12 -1 -1 5 -1 9 -1 -1 3 6 -1 -1 7 10 -1 -1 11 -1 -1
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the left node of " << data << " :- \n";
    root->left = buildtree(root->left);

    cout << "enter the right node of " << data << " :- \n";
    root->right = buildtree(root->right);

    return root;
}

//Display a tree

void display(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data<<" ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


//Inorder traversal
void inorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//preorder traversal

void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


//postorder traversal
void postorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


//levelwise sum of leaf node
void sumatlevel(node* root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty";
        return;
    }
    queue<node*> q;
    q.push(root);
    int level{ 0 };

    while (!q.empty())
    {
        int size = q.size();
        int sum{ 0 };
        for (int i = 0; i < size; i++)
        {
            node* temp = q.front();
            q.pop();
            if (temp->left == NULL && temp->right == NULL)
            {
                sum = sum + temp->data;
            }
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
        cout << "Sum of level" << level++ << " is :- " << sum<<"\n";
    }

    return;
}

int main()
{
    node* root = NULL;
    root = buildtree(root);
    cout << "\n";
    display(root);
    cout << "\nInordered Traversal :- ";
    inorder(root);
    cout << "\n\nPrerdered Traversal :- ";
    preorder(root);
    cout << "\n\nPostordered Traversal :- ";
    postorder(root);
    cout << "\n\n";
    sumatlevel(root);
}
