#include <iostream>
#include<vector>
#include <queue>
#include <map>
using namespace std;

struct Node
{
	int key;
	Node *left, *right;

	// Constructor
	Node(int k){
		key = k;
		left = right = NULL;
	}
};

Node *Insert(Node *root){
	cout<<"Enter value to be entered : ";
	int val;
	cin>>val;
	root=new Node(val);

	if(val==-1)
		return NULL;

	cout<<"Enter value to left of "<<val<<" : ";
	root->left=Insert(root->left);
	cout<<"Enter value to right of "<<val<<" : ";
	root->right=Insert(root->right);

	return root;
}

void Display(vector<int>&V){
    for(auto i : V){
        cout<<i<<" ";
    }
}

void LeftView(Node* root, int level, vector<int>&res){
    if(!root)
        return;
    if(res.size()==level)
        res.push_back(root->key);

    LeftView(root->left,level+1,res);  
    LeftView(root->right,level+1,res);
}

void RightView(Node* root, int level, vector<int>&res){
    if(!root)
        return;
    if(res.size()==level)
        res.push_back(root->key);

    RightView(root->right,level+1,res);
    RightView(root->left,level+1,res);
}

vector<int> TopView(Node* root){
    vector<int>res;
    if(!root)
        return res;

    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        Node* node=f.first;
        int line=f.second;

        if(mp.find(line) == mp.end())
            mp[line]=node->key;
        
        if(node->left)
            q.push({node->left,line-1});
        if(node->right)
            q.push({node->right,line+1});
    }
    for(auto i : mp)
        res.push_back(i.second);
    
    return res;
}

vector<int> BottomView(Node* root){
    vector<int>res;
    if(!root)
        return res;

    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        Node* node=f.first;
        int line=f.second;

        mp[line]=node->key;
        
        if(node->left)
            q.push({node->left,line-1});
        if(node->right)
            q.push({node->right,line+1});
    }
    for(auto i : mp)
        res.push_back(i.second);
    
    return res;
}

int main(){
    Node *root = NULL;
    cout<<"Enter binary tree nodes and for no node enter -1\n\n";
    root=Insert(root);
    vector<int>L,R,T,B;
	int usrchoice = 0;

	while (1){
		cout << "\n\n1.Left View\n2.Right View\n3.Top View\n4.Bottom View\n5.Exit" << endl;
		cout << "Enter the choice of operation to be implemented : ";
		cin >> usrchoice;

		switch (usrchoice){
		case 1:
            LeftView(root,0,L);
            Display(L);
			break;

		case 2:
            RightView(root,0,R);
            Display(R);
			break;

		case 3:
			T=TopView(root);
            Display(T);
			break;

		case 4:
			B=BottomView(root);
            Display(B);
			break;

		case 5:
			exit(1);

		default:
			cout << "Enter a valid choice : ";
			break;
		}
	}
	return 0;
}