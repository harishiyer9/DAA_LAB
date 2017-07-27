#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <fstream>

using namespace std;

struct BSTnode
{
    int data;
    struct BSTnode *left,*right,*parent;
};

struct BSTnode *Insert(struct BSTnode *root,int data)
{
    struct BSTnode *newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
    {
        root = newnode;
        root->parent = NULL;
        return root;
    }
    struct BSTnode *y = NULL;
    struct BSTnode *x = root;
    while(x != NULL)
    {
        y = x;
        if(data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    newnode->parent = y;
    if(data < y->data)
    {
        y->left = newnode;
    }
    else
    {
        y->right = newnode;
    }
    return root;
}

int Count(struct BSTnode * root)
{
    int count = 0;
    struct BSTnode * temp = root;
    queue<BSTnode *> q;
    while(temp)
    {
        count++;
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        temp  = q.front();
        q.pop();
    }
    return count;
}


void Duplicate(struct BSTnode * root)
{
    int count = 0;
    struct BSTnode * temp = root;
    queue<BSTnode *> q;
    while(temp)
    {
        count++;
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        temp  = q.front();
        q.pop();
    }

    int a[count],i=0;
    temp = root;
    queue<BSTnode *> Q;
    while(temp)
    {
        a[i++] = temp->data;
        if(temp->left)
        {
            Q.push(temp->left);
        }
        if(temp->right)
        {
            Q.push(temp->right);
        }
        temp  = Q.front();
        Q.pop();
    }
   /* for(int i=0;i<count;i++)
    {
        printf("%d ",a[i]);
    }*/
    int dup;
    for(i=0;i<count/2;i++)
    {
        dup = 0;
        for(int j=i;j<count;j++)
        {
            if(a[i] == a[j])
            {
               dup++;
            }
        }
        if(dup>1)
        {
            printf("The value %d is repeated %d times\n",a[i],dup);
        }
    }
}
int main()
{

    ifstream in;
    in.open("input.txt");
    int length;
    in >> length;
    int *a = new int[length];
    for(int i=0;i<length;i++)
    {
        in >> a[i];
    }
    in.close();
    struct BSTnode *root = NULL;
    for(int i=0;i<length;i++)
    {
        root = Insert(root,a[i]);
    }
    /*root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,22);
    root = Insert(root,4);
    root = Insert(root,20);
    root = Insert(root,20);
    root = Insert(root,20);
    root = Insert(root,10);
    root = Insert(root,10);
    root = Insert(root,10);
    root = Insert(root,10);*/
    Duplicate(root);
    //InOrder(root,Count(root));





    return 0;
}
