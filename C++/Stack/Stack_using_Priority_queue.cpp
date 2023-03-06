// ====================== Problem Statement ==========================
/*
Here we will take the numbers input from user and with the help of priority queue we need to implement stack.
Priority queue is a special type of queue in which the numbers are dequeue based on their priority. Every no has some priority along with its data.
The data having the highest priority is popped first.
In priority queue, we assign priority to the elements that are being pushed. A stack requires elements to be processed in Last in First Out manner.
The idea is to associate a count that determines when it was pushed. This count works as a key for the priority queue. So the implementation of 
stack uses a priority queue of pairs, with the first element serving as the key.
For ex:
User enters input : 4 1 2
so in queue -> [(2,3) (1,2) (4,1)]
*/

// // ====================== Code with C++ ==========================

#include<iostream>
#include<climits>
#include<queue>
using namespace std;

typedef pair<int, int> pr;

class Queue{
    int count;//storing the count of no of elements in queue and act as a key for priority
    priority_queue<pair<int,int> > p;
	
    public:
    	Queue():count(0){}//initialising count to 0
    	
    	//function to insert element in queue
    	void push(int data){
    		count++;
			p.push(pr(count,data));
		}
		//function to delete element from queue
    	void pop(){
		    if(p.empty()){
			    cout<<"Stack is empty !!";
	        }  
	        else{
		        count--;
		        p.pop();
	        }
		}
		//function to find top element
    	int top(){
    		if(p.empty()){
			    return INT_MAX;
	        } 
    		else{
    			pr t =p.top();
				return t.second;
			} 
		}
};

int main(){
    int element,choice,temp;
    cout<<"Enter choice :"<<endl;
    cout<<"1-push 2-pop 3-peek"<<endl;
    cin>>choice;//choice is used to store the value of next function to pe performed
    Queue *q=new Queue();
    while(choice!=0)
    {
    	if(choice==1)//insert element
    	{
            cout<<"Enter Element :";
            cin>>element;
            q->push(element);
		}
        else if(choice==2)//delete element
        {
        	q->pop();
		}
		else if(choice == 3)//find topmost element
		{
			if(q->top()==INT_MAX)
				cout<<"Stack is empty!!"<<endl;
			else
			    cout<<q->top()<<endl;
		}
		else if(choice == 0)//terminate the loop
		{
			break;
		}
		else
		{
			cout<<"Invalid Choice"<<endl;
		}
		cout<<"Enter choice :"<<endl;
        cout<<"0-To Exit 1-push 2-pop 3-peek"<<endl;
        cin>>choice;
	}
    return 0;
}
