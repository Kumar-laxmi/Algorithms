#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printLinkedList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *FlattenLinkedList(Node *root)
{
    // Initialize the head pointers
    Node* head1 = root;
    Node* head2 = root->next;
    root = root->next;

    while(root != NULL){
        // Initialize head and tail for the new flattened list
        Node* head = NULL;
        Node* tail = NULL;
        
        // Merge the two sorted linked lists
        while(head1 != NULL && head2 != NULL){
            if(head1->data < head2->data){
                // Create a new node for the merged list
                Node* newNode = new Node(head1->data);
                if(head == NULL && tail == NULL){
                    head = newNode;
                    tail = newNode;
                }else{
                    tail->bottom = newNode;
                    tail = tail->bottom;
                }
                head1 = head1->bottom;
            }else{
                // Create a new node for the merged list
                Node* newNode = new Node(head2->data);
                if(head == NULL && tail == NULL){
                    head = newNode;
                    tail = newNode;
                }else{
                    tail->bottom = newNode;
                    tail = tail->bottom;
                }
                head2 = head2->bottom;
            }
        }
        
        // Append the remaining nodes of the linked lists
        while(head1 != NULL){
            Node* newNode = new Node(head1->data);
            if(head == NULL && tail == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->bottom = newNode;
                tail = tail->bottom;
            }
            head1 = head1->bottom;
        }
        while(head2 != NULL){
            Node* newNode = new Node(head2->data);
            if(head == NULL && tail == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->bottom = newNode;
                tail = tail->bottom;
            }
            head2 = head2->bottom;
        }
        
        // Move to the next level
        root = root->next;
        head1 = head;
        head2 = root;
    }
    return head1;
}

int main(void) {
    int t;
    cout << "Enter No of attempts : " <<endl;
    cin >> t;

    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node* temp = NULL;
        struct Node* head = NULL;
        struct Node* pre = NULL;
        struct Node* tempB = NULL;
        struct Node* preB = NULL;

        cout << "Enter size of horizontal Linkedlist : " <<endl;
        cin >> n;
        int work[n];
        cout<<"Elements in Horizontal Linkedlist : "<<endl;
        for (int i = 0; i < n; i++){
            cin >> work[i];
        }
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            cout << "Enter Head For Bottom LinkedList  : " <<endl;
            cin >> data;
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            cout<<"Enter Bottom Linkedlist Elements "<<endl;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }

        // Flattening and printing the linked list
        Node* root = FlattenLinkedList(head);
        printLinkedList(root);
        cout <<endl;
    }

    return 0;
}
