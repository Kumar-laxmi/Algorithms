// ====================== Problem Statement ==========================
/*
Menu-Driven application to convert->
1.Infix to Postfix
2.Infix to Prefix
3.Prefix to Postfix
4.Prefix to Infix
5.Postfix to Prefix
6.Postfix to Infix

Algorithm -

--- Infix to Postfix---
1)Scan the infix expression from left to right. 
2)If the scanned character is an operand, append it to postfix variable. 
  Else, 
3)If the precedence of the scanned operator are greater than the precedence of the operator on top of the stack(or the stack is empty or the stack contains a ‘(‘ ), then push it.
4)Else,
  Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
5)If the scanned character is an ‘(‘, push it to the stack. 
6)If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
7)Repeat until the infix expression is scanned. 
8)Pop and append from the stack until it is not empty.
9)Return the postfix var 


--- Infix to Prefix---
1) Reverse the infix expression,while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
2) Apply postfix converison of the modified expression.
3) Reverse the postfix expression.


---Prefix to Postfix/Infix---
1)Read the Prefix expression from right to left
2)If the element is an operand, then push it onto the Stack
  If the element is an operator, then pop two operands from the Stack 
3)Create a string as shown below- 
string = operand1 + operand2 + operator (Prefix to Postfix) 
string = operand1 + operator + operand2(Prefix to Infix) 

push the resultant string to Stack
4)The remaining string at top of stack is the required expression.


---Postix to Prefix/Infix---
1)Read the Postfix expression.
2)If the element is an operand, then push it onto the Stack
  If the element is an operator, then pop two operands from the Stack 
3)Create a string as shown below-
string = operator + operand1 + operand2 (Postfix to Prefix) 
string = operand1 + operator + operand2 (Postfix to Infix) 

push the resultant string back to Stack
4)The remaining string at top of stack is the required expression.
*/

// // ====================== Code with C++ ==========================

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int prec(char ch){
    if(ch=='^')
       return 3;
    else if(ch=='/' || ch=='*')
       return 2;
    else if(ch=='+' || ch=='-')
       return 1;
    else
       return -1;
}

bool checkOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    
    return false;
}

string InfixToPostfix(string exp){
    stack<char>st;
    string Postfix="";

    for(int i=0; i<exp.length(); i++){
        char c= exp[i];

        if((c>='a' && c<='z')  || (c>='A'  && c<='Z')){
            Postfix=Postfix+c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                Postfix= Postfix+st.top();
                st.pop();
                if(st.empty()){
                	return "Incorrect";
				}
            }
            st.pop();
        }
        
        else{
            while(!st.empty() && prec(c)<=prec(st.top())){
                    Postfix= Postfix + st.top();
                    st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        Postfix=Postfix+st.top();
        st.pop();
    }
    
    return Postfix;
}


string InfixToPrefix(string exp){
    reverse(exp.begin(), exp.end());

    for(int i=0; i<exp.length(); i++){
        if(exp[i]=='('){
            exp[i]=')';
        }
        else if(exp[i]==')'){
            exp[i]='(';
        }
    }
    string temp =InfixToPostfix(exp);

    reverse(temp.begin(), temp.end());
    
    return temp;
}


string PrefixToPostfix(string exp){
            stack<string> st;
 
    // reading from right to left
    for (int i = exp.size() - 1; i >= 0; i--){
        if (checkOperator(exp[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = op1 + op2 + exp[i];            
            st.push(temp);
        }
        else {  
           st.push(string(1, exp[i]));
        }
    }
    return st.top();
}

string PrefixToInfix(string exp){
       stack<string> st;
 
    // reading from right to left
    for (int i = exp.size() - 1; i >= 0; i--){
        if (checkOperator(exp[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
 
           
            string temp = "(" + op1  + exp[i] + op2 + ")"; 
            st.push(temp);
        }
        else {   
            string temp;
            temp+=exp[i];
            st.push(temp);
        }
    }
    string res = st.top();
    string infix = res.substr(1, res.length()-2);
    return infix;
}

string PostfixToPrefix(string exp)
{
    stack<string> st;
 
    // reading from right to left
    for (int i = 0; i <exp.size(); i++) {
        if (checkOperator(exp[i])) {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string temp = exp[i] + op1 + op2;
            st.push(temp);
        }
        else {
            string temp;
            temp+=exp[i];
            st.push(temp);
        }
    }
    return st.top();
}


string PostfixToInfix(string exp)
{
    stack<string> st;
 
    for (int i=0; i<exp.size(); i++){
        if (checkOperator(exp[i])){
          string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string temp = "(" + op1 + exp[i] + op2 + ")" ;
            st.push(temp);
        }
        else{
            string temp;
            temp+=exp[i];
            st.push(temp);
        }
    }
    string res = st.top();
    string infix = res.substr(1, res.length()-2);
    return infix;
}



int main()
{  
    string exp;
    int choice;
    
    do{
        cout<<"Enter expression: ";
        cin>>exp;
        cout<<"---------------------------------------\n";
        cout<<"Press 1 for InfixToPostfix conversion\n";
        cout<<"Press 2 for InfixToPrefix conversion\n";
        cout<<"Press 3 for PrefixToPostfix conversion\n";
        cout<<"Press 4 for PrefixToInfix conversion\n";
        cout<<"Press 5 for PostfixToPrefix conversion\n";
        cout<<"Press 6 for PostfixToInfix conversion\n";
        cout<<"Press 0 to exit\n";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<InfixToPostfix(exp)<<endl;
            break;

            case 2:
            cout<<InfixToPrefix(exp)<<endl;
            break;

            case 3:
            cout<<PrefixToPostfix(exp)<<endl;
            break;

            case 4:
            cout<<PrefixToInfix(exp)<<endl;
            break;

            case 5:
            cout<<PostfixToPrefix(exp)<<endl;
            break;

            case 6:
            cout<<PostfixToInfix(exp)<<endl;
            break;

            default:
            break;
        }
    }while(choice!=0);
     return 0;
}
 