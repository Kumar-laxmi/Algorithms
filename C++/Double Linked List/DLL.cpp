// C++ program for the all Doubly Linked List Operation
//It Includes
//insert at Begininng
//insert at End
//insert at Position
// Delte at Beginning
// Delte at End
// Delte at Position
// Printing the Linked List
// Reverse The linked list

#include <bits/stdc++.h>
using namespace std;

//Node of the Linked List
class node {
public:
	node* prev;
	int data;
	node* next;

	node(int value)
	{ // A constructor is called here
		prev = NULL; // By default previous pointer is
					// pointed to NULL
		data = value; // value is assigned to the data
		next = NULL; // By default next pointer is pointed
					// to NULL
	}
};

void insert_at_head(node*& head, int value)
{
	//created new Node
	node* n = new node(value);
	//Arranging the pointers
	n->next = head;
	//If not a empty Linked List
	if (head != NULL) {
		head->prev = n;
	}
	//Final Assignment
	head = n;
}

void insert_at_tail(node*& head, int value)
{
	//Same as insert_at_situation
	if (head == NULL) {
		insert_at_head(head, value);
		return;
	}

	//created new Node
	node* n = new node(value);
	//Temporary Point pointing towards the head
	node* temp = head;
	//Travelling to the last node
	while (temp->next != NULL) {
		temp = temp->next;
	}
	//Pointers Arrangement
	temp->next = n;
	n->prev = temp;
}
//consider 1-based indexing while deciding Position
void insert_at_pos(node *& head,int pos,int value){
	//If Linked List is Empty
	if(head==NULL){
        cout<<"Linked List is Empty"<<endl;
		return;
	}
	//insert_at_head situation when pos==1
	if(pos==1){
		insert_at_head(head,value);
		return;
	}
	else{
		pos=pos-2;
		node * temp=head;
		while(pos && temp!=NULL){
			temp=temp->next;
			pos--;
		}
		//it means we have travelled the whole linked list but not able to find a place a valid position
		if(pos>0){
			cout<<"Invalid Position"<<endl;
			return;
		}
		// it means the insert_at_tail situation
		else if(temp==NULL && pos==0){
			insert_at_tail(head,value);
			return;
		}
		else{
			//stroing the address of the next_node
			node * temp_next=temp->next;
			//edge case node_before null
			if(temp_next==NULL){
				//New Node Allocation
				node * n=new node(value);
				//Arranging Pointers
				temp->next=n;
				n->prev=temp;
				n->next=NULL;
				return;
			}
			//creating new node
			node * n=new node(value);
			//linking all the pointers
			temp->next=n;
			n->prev=temp;
			n->next=temp_next;
			temp_next->prev=n;
			}

	}

}
void delete_at_head(node*& head){
	//If Linked List is Empty
    if(head==NULL){
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    node * temp=head;
    temp=temp->next;
    temp->prev=NULL;
    head=temp;
    
}
void delete_at_end(node* & head){
	//If Linked List is Empty
	if(head==NULL){
        cout<<"Linked List is Empty"<<endl;
		return;
	}
    node * temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	//if only single node is present
	if(temp->prev==NULL){
		head=NULL;
		return;
	}
	else{
		temp=temp->prev;
		temp->next=NULL;
	}


}
void delete_at_pos(node *&head,int pos){
	//If Linked List is Empty
	if(head==NULL){
        cout<<"Linked List is Empty"<<endl;
		return;
	}
	// delete_at_head situation
	if(pos==1){
		delete_at_head(head);
		return;
	}
	//All other cases
	node * temp=head;
	pos--;
	while(pos && temp!=NULL){
		temp=temp->next;
		pos--;
	}
	//Invalid Position Case
	if(temp==NULL){
		cout<<"Invalid Position"<<endl;
		return;
	}
	//if we are at last node
	else if(temp->next==NULL){
		
		temp=temp->prev;
		temp->next=NULL;
		

		return;
	}
	//when a middle case
	else{
		node * temp_next=temp->next;
		node * temp_prev=temp->prev;
		temp_prev->next=temp_next;
		temp_next->prev=temp_next;
		return;

	}




}
void reverse(node *& head)
    {
		//If Linked List is Empty
		if(head==NULL){
			cout<<"Empty Linked List"<<endl;
		}
		// Using stack for reversing
		// It has a LIFO structure (Last In First Out)
        stack<int> st;
        node* temp = head;
        while (temp != NULL) {
            st.push(temp->data);
            temp = temp->next;
        }
 
        // added all the elements sequence wise in the
        // stack
        temp = head;
        while (temp != NULL) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
 
        // popped all the elements and the added in the
        // linked list,
        // which are in the reversed order finally
    }


//printing the Linked List
void display(node* head)
{
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

// Driver code
int main()
{
	node * head=NULL;
	
	cout<<"Welcome to the Doubly Linked List Program"<<endl;
	while (true)
	{
		cout<<"Press 1 To Display"<<endl;
		cout<<"Press 2 To Insert At Head"<<endl;
		cout<<"Press 3 To Insert At Tail"<<endl;
		cout<<"Press 4 To Insert At Position"<<endl;
		cout<<"Press 5 To Delete At Head"<<endl;
		cout<<"Press 6 To Delete At End"<<endl;
		cout<<"Press 7 To Delete At Position"<<endl;
		cout<<"Press 8 To Reverse The List"<<endl;
		cout<<"Press 9 To Exit"<<endl;
		int ch;
		cout<<"Enter Your Choice :";
		cin>>ch;
		if(ch==1){
			cout<<"Linked List :  ";
			display(head);
		}
		else if(ch==2){
			int value;
			cout<<"Enter the value :";
			cin>>value;
			insert_at_head(head,value);
		}
		else if(ch==3){
			int value;
			cout<<"Enter the value :";
			cin>>value;
			insert_at_tail(head,value);
		}
		else if(ch==4){
			int value;
			cout<<"Enter the value :";
			cin>>value;
			int position;
			cout<<"Enter the position :";
			cin>>position;
			insert_at_pos(head,position,value);
		}
		else if(ch==5){
			delete_at_head(head);
		}
		else if(ch==6){
			delete_at_end(head);
		}
		else if(ch==7){
			int position;
			cout<<"Enter the position :";
			cin>>position;
			delete_at_pos(head,position);
		}
		else if(ch==8){
			reverse(head);
		}
		else if(ch==9){
			cout<<"Thanks For Using..Hope You Enjoyed it"<<endl;
			break;
		}
		else{
			cout<<"Wrong Choice"<<endl;
		}

	}
	return 0;
}
