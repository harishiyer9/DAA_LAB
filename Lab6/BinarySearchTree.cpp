#include <iostream>
#include <stdio.h>
#include <stack>
#include <stdlib.h>

using namespace std;

struct BTnode
{
    int data;
    struct BTnode *left,*right;
};

struct BTnode *Insert(struct BTnode *root,int data)
{
    struct BTnode * newnode = (struct BTnode *)malloc(sizeof(struct BTnode));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    if(root == NULL)
    {
        root = newnode;
    }
    else
    {
        struct BTnode *prev = NULL;
        struct BTnode *current = root;
        while(current != NULL)
        {
            prev = current;
            if(current->data < data)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        if(prev->data < data)
        {
            prev->right = newnode;
        }
        else
        {
            prev->left = newnode;
        }
    }
    return root;
}

struct BTnode * Find_Min(struct BTnode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

void PreOrder(struct BTnode *root)
{
    stack<BTnode *> S;
    while(1)
    {
        while(root)
        {
            printf("%d ",root->data);
            S.push(root);
            root = root->left;
        }
        if(S.empty())
        {
            break;
        }
        root = S.top();
        S.pop();
        root = root->right;
    }
}

void InOrder(struct BTnode *root)
{
    stack<BTnode *> S;
    while(1)
    {
        while(root)
        {
            S.push(root);
            root = root->left;
        }
        if(S.empty())
        {
            break;
        }
        root = S.top();
        S.pop();
        printf("%d ",root->data);
        root = root->right;
    }
}

void PostOrder(struct BTnode *root)
{
    if (!root) return;
    stack<BTnode *> s;
    s.push(root);
    struct BTnode *prev = NULL;
    while (!s.empty())
    {
        struct BTnode *curr = s.top();

        if (!prev || prev->left == curr || prev->right == curr)
        {
            if (curr->left)
            {
                s.push(curr->left);
            }
            else if (curr->right)
            {
                s.push(curr->right);
            }
            else
            {
                cout << curr->data << " ";
                s.pop();
            }
        }

        else if (curr->left == prev)
        {
            if (curr->right)
            {
                s.push(curr->right);
            }
            else
            {
                cout << curr->data << " ";
                s.pop();
            }
        }

        else if (curr->right == prev)
        {
            cout << curr->data << " ";
            s.pop();
        }
        prev = curr;
    }
}

struct BTnode* Delete(struct BTnode* root, int data)
{
    if (root == NULL) return root;

    if (data < root->data)
        root->left = Delete(root->left, data);

    else if (data > root->data)
        root->right = Delete(root->right, data);

    else
    {

        if (root->left == NULL)
        {
            struct BTnode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BTnode *temp = root->left;
            free(root);
            return temp;
        }

        struct BTnode* temp = Find_Min(root->right);


        root->data = temp->data;


        root->right = Delete(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct BTnode * root = NULL;
    while(1)
    {
        printf("==================================\n");
        printf("Enter 1 to insert into BST\n");
        printf("Enter 2 to delete from BST\n");
        printf("Enter 3 to Preorder traversal\n");
        printf("Enter 4 to Inorder traversal\n");
        printf("Enter 5 to Postorder traversal\n");
        printf("Enter 0 to exit the menu\n");
        printf("==================================\n");
        int n;
        cin>>n;
        if(n==0)
        {
            break;
        }
        if(n==1)
        {
            int num;
            cout<<"Enter the element you want to insert\n";
            cin>>num;
            root = Insert(root,num);
        }
        if(n==2)
        {
            int num;
            cout<<"Enter the element you want to delete\n";
            cin>>num;
            root = Delete(root,num);
        }
        if(n==3)
        {
            if(root == NULL)
            {
                cout<<"No element in the tree\n";
            }
            else
            {
                PreOrder(root);
                printf("\n");
            }

        }
        if(n==4)
        {
            if(root == NULL)
            {
                cout<<"No element in the tree\n";
            }
            else
            {
                InOrder(root);
                printf("\n");
            }
        }
        if(n==5)
        {
            if(root == NULL)
            {
                cout<<"No element in the tree\n";
            }
            else
            {
                PostOrder(root);
                printf("\n");
            }
        }
    }

    return 0;
}
