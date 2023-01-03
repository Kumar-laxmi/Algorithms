#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};
node* head;
node* head1;

void insert(int x)
{
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    if(head==NULL)
    head = new_node;
    else
    {
        node *ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
}

void insert1(int x)
{
    node *new_node1 = new node();
    new_node1->data = x;
    new_node1->next = NULL;
    if(head1==NULL)
    head1 = new_node1;
    else
    {
        node *ptr1=head1;
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
        }
        ptr1->next=new_node1;
    }
}


void Intersection()
{
    node *ptr = head;
    cout<<endl<<"Intersection of Two Linked List : ";
    while(ptr != NULL)
    {
        node *ptr1 = head1;
        while(ptr1 != NULL)
        {
            if((ptr->data == ptr1->data) && (ptr1->data != -1))
            {
                cout<<ptr->data<<" ";
                ptr1->data=-1;
                break;
            }
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}

void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<"->"<<ptr->data;
        ptr=ptr->next;
    }
}

void display1()
{
    node *ptr1=head1;
    while(ptr1!=NULL)
    {
        cout<<"->"<<ptr1->data;
        ptr1=ptr1->next;
    }
}

int main()
{
    int i,nodes,num,nodes1;
    cout<< "Enter the total number of nodes : ";
    cin >> nodes;
    for(i=0;i<nodes;i++)
    {
        cout<<"Enter Node : ";
        cin>>num;
        insert(num);
    }
    display();
    cout<< endl <<"Enter the total number of nodes : ";
    cin >> nodes1;
    for(i=0;i<nodes1;i++)
    {
        cout<<"Enter Node : ";
        cin>>num;
        insert1(num);
    }
    display1();
    Intersection();
    
    return 0;
}