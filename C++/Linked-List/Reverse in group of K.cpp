#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    //constructor to initialise value
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node *Insert(Node *head,int val){
    Node *temp=new Node(val);
    if(head==NULL){
       temp->next=head;
       return temp; 
    }

    Node *curr=head;
    while(curr->next != NULL)
        curr=curr->next;

    curr->next=temp;
    temp->next=NULL;
    return head;
}

Node *reverseinK(Node *head,int k){
    Node *curr=head,*prevFirst=NULL;
    bool isFirstPass=true;

    while(curr!=NULL){
        Node *first=curr,*prev=NULL;
        int count=0;

        while(curr!=NULL && count<k){
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(isFirstPass){
            head=prev;
            isFirstPass=false;
        }
        else
            prevFirst->next=prev;
        prevFirst=first;
    }
    return head;
}

void print(Node *head){
    Node *curr=head;
    cout<<endl<<endl;
    while(curr != NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl<<endl;
}
 
int main(){
    Node *head=NULL;
    int n,val,k;
    cout<<"Enter n, k : ";
    cin>>n>>k;
    cout<<"Enter nodes : \n";
    for(int i=0; i<n; i++){
        cin >> val;
        head=Insert(head,val);
    }
    print(head);
    head=reverseinK(head,k);
    print(head);
    return 0;
}
