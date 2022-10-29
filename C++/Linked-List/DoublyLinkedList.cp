class node{
  public:
  int data;
  node* next;
  node* prev;
};

int main(){
  node* head = NULL;
  node* second = NULL;
  node* third = NULL;
  
  head = new node();
  second = new node();
  third = new node();
  
  head->data = 7;
  head->next = second;
  head->prev = NULL;
  
  second->data = 21;
  second->next = third;
  second->prev = head;
  
  third->data = 8;
  third->next = NULL;
  third->prev = second; 
}
