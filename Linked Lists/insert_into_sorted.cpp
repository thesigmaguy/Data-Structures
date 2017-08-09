#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert_ll4(int data,struct node **head)
{
    struct node *temp=*head,*temp2;
    temp2=(struct node*)calloc(1,sizeof(struct node*));
    temp2->data=data;
    if(*head)
    {

        while(temp->next)
        {
            temp=temp->next;
        }
        temp2->next=temp->next;
        temp->next=temp2;
    }
    else
    {
        temp2->next=*head;
        *head=temp2;
    }
}

void print4(struct node *head)
{
    struct node *temp;
    while(temp)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    cout<<endl;
}

int test_main4()
{
    struct node *head=NULL;

    for(int i=0;i<20;i++)
    {
        insert_ll4(i*10,&head);
    }
    print4(head);
    return 0;
}
