#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct queue_node
{
    struct node *data;
    struct queue_node *next;
};

void enqueue8(struct queue_node **queue,struct node *data)
{
    struct queue_node *new_node=NULL;
    new_node=(struct queue_node *)calloc(1,sizeof(struct queue_node));
    new_node->data=data;
    new_node->next=NULL;

    if(!(*queue))
    {
        *queue=new_node;
    }
    else
    {
        struct queue_node *temp=NULL;
        temp=*queue;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;
    }
    return;
}


struct node * dequeue8(struct queue_node **queue)
{
    struct queue_node *result=NULL;
    if(*queue)
    {
        result=*queue;
        *queue=(*queue)->next;
        result->next=NULL;
        return result->data;
    }
    return NULL;
}

struct node * create_node8(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree8(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node8(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        enqueue8(&my_queue,*root);
        while(my_queue)
        {
            struct node *temp=dequeue8(&my_queue);
            if(temp->left)
            {
                enqueue8(&my_queue,temp->left);
            }
            else
            {
                temp->left=create_node8(data);
                break;
            }
            if(temp->right)
            {
                enqueue8(&my_queue,temp->left);
            }
            else
            {
                temp->right=create_node8(data);
                break;
            }
        }
    }
    return;
}

int half_nodes(struct node *root)
{
    int result=0;
    if(root)
    {
        struct queue_node *my_queue=NULL;
        enqueue8(&my_queue,root);
        while(my_queue)
        {
            struct node *temp=dequeue8(&my_queue);
            if((temp->left && !temp->right) || (!temp->left && temp->right))
            {
                result++;
            }
            if(temp->left)
            {
                enqueue8(&my_queue,temp->left);
            }
            if(temp->right)
            {
                enqueue8(&my_queue,temp->right);
            }
        }
    }
    return result;
}

int test_main8()
{
    struct node *tree_head=NULL;
    int n=5;
    for(int i=0;i<n;i++)
    {
        insert_to_tree8(&tree_head,i);
    }
    printf("No of Leafs\t%d\n",half_nodes(tree_head));
    return 0;
}

