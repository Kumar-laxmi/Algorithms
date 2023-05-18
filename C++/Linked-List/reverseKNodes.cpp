/*
    -----------------------------problem Statement------------------------------------
    You have given the head of Linked-List and a value k. Reverse only k nodes of given
    Linked-List. You have to change in the given linked-List only without using any 
    extra space.
    input:
    n=10
    list= 10->9->8->7->6->5->4->3->2->1
    k= 6

    Output:-
    5->6->7->8->9->10->4->3->2->1

    constraints:-
    1<=n<=10e9
    1<=k<=n
    -10e9<= node->data<= 10e9
*/
/*
    --------------------------Solution / Approach-------------------------------
     🌟Approach:-
     To reverse given no of nodes from beginning. You can use prev and cur pointers.
     And in each iteration make cur->next join to the prev Node. Run this loop K times to
     reverse only K nodes from beginning. Since, we have to use traverse so we use another
    Pointer to store value cur->next. 

    🌟 Expected Time- Complexity: - O(n)
    
         As we are traversing through list in one go only.
    
    🌟 Expexted Auxilary-space:- O(1)

                Since we are using only constant space for declaring pointers.


 (❁´◡`❁)Enjoy reading more Algorithms :)


*/
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node(int d)
    {
        data = d;
        next = NULL;
    }

    ~Node()
    {
        cout << "value of deleted Node: " << this->data;
        delete this;
    }
};

void insertNodeAtHead(Node* & head, int d)
{
    Node *nodeToInsert = new Node(d);
    if (head == NULL)
    {
        head = nodeToInsert;
    }else{
            nodeToInsert->next = head;
          head = nodeToInsert;
    }
    
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int getLength(Node* head){
    int cnt=0;
    while(head!= NULL){
        cnt++;
        head= head->next;
    }
    return cnt;
}

void reverseKNode(Node* & head, int k)
{   
    if(k>getLength(head)){
        cout<<"Invalid operation\n\n";
        cout<<endl;
        return;
    }    

    if(head==NULL || head->next==NULL)
    {
        return; //If there is No Node or Single Node then return without doing anything---
    }else
    {
          int cnt = 0;
    Node* prev = NULL;
    Node* cur = head;
     Node* nextNode = NULL;
    while (cnt < k)
    {
       nextNode= cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
        cnt++;
    }
    head->next= cur;
    head= prev;
    }

    
}

int main()
{
    int n;
    cout << "Enter the no of Nodes : ";
    cin >> n;
    Node* head = NULL;
    cout << "Enter the values of Nodes in order : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertNodeAtHead(head, x);
    }
    cout << "\nEntered Linked List : ";
    print(head);
    int k;
    cout << "Enter the no of Nodes from beginning which needs to be reversed : ";
    cin >> k;
    reverseKNode(head, k);
    cout<<"\nLinked-List after reversing its "<<k<<" Nodes : \n\n";
    print(head);
    cout<<endl;
    return 0;
}