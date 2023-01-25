// ====================== Problem Statement ==========================
/*
 Take 2 linked list as input from user and find the elements whose value are common i both linekd list. The input linked list may be in sorted order or not.
 Ex:
 Input : 
 1->3->4->7
 2->1->4
 Output:
 1->4
 
 Solution-
 Take 2 pointers on head of both linked lists and compare their values -
 Now compare each value of first linked list with every value of second list
 if vales are equal:- 
    print the value
    break the loop
    increment pointer pointing to first linked list to the next node
*/

// // ====================== Code with C++ ==========================
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

//function for inserting element to first linked list
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

//function for inserting element to second linked list
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

//function for finding the intersection of two linked list
void Intersection()
{
    node *ptr = head;
    cout<<endl<<"Intersection of Two Linked List : ";
    //outer loop for comparing each value of first linked list
    while(ptr != NULL)
    {
        node *ptr1 = head1;
        //inner loop comparing each value of first linked list element with second linked list elements
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

//function for displaying elements of first linked list
void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<"->"<<ptr->data;
        ptr=ptr->next;
    }
}

//function for displaying elements of second linked list
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
    //asking user for adding nodes to first linked list
    
    for(i=0;i<nodes;i++)
    {
        cout<<"Enter Node : ";
        cin>>num;
        insert(num);
    }
    //calling display function of linked list 1
    display();
    
    cout<< endl <<"Enter the total number of nodes : ";
    cin >> nodes1;
    
    //asking user for adding nodes to second linked list
    for(i=0;i<nodes1;i++)
    {
        cout<<"Enter Node : ";
        cin>>num;
        insert1(num);
    }
    //calling display function of linked list 2
    display1();
    
    //calling intersection function
    Intersection();
    
    return 0;
}
