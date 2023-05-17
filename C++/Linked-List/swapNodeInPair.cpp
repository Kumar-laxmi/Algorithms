#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next= NULL;
    Node(){
        data=0;
        next= NULL;
    }
    Node(int d){
        data= d;
        next= NULL;
    }
    ~Node(){
        cout<<"deleted Node data: "<<this->data<<"\n";
        delete this;
    }

};

void insertNode(Node* & head, int d){
    Node* temp= new Node(d);
    if(head==NULL){
        head= temp;
        return;
    }
    temp->next= head;
    head= temp;
}

int getLength(Node* head){
    int cnt=0;
    while(head!= NULL){
        cnt++;
        head= head->next;
    }
    return cnt;
}

Node*  swapNodeInPair(Node* head, int k){
     //naive approach---
            //t.c:- O(n) & auxilary-space:- O(1)
        int n= getLength(head);
        int i=0;
        Node* ptr1=head;
        Node* ptr2=head;
        Node* temp= head;
        while(i<n){
                if(i==k-1){
                    ptr1= temp;
                }
                if(i==n-k){
                    ptr2= temp;
                }
                temp= temp->next;
                i++;
        }
        swap(ptr1->data, ptr2->data);
        return head;
}

void print(Node* head){
    cout<<"given list: \n";
    while(head!= NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    return;
}

int main(){
 
 int n;
 cout<<"Enter the length of list : "<<"\n";
 cin>>n;
 Node* head=new Node();
for(int i=0; i<n; i++){
    int x;
    cin>>x;
    insertNode(head,x);
}
int k;
cin>>k;
print(head);
Node* ans= swapNodeInPair(head,k);
print(ans);
return 0;
}