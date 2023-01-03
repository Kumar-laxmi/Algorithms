#include<iostream>
using namespace std;

template<class T>
void swap(T *a, T *b){
    T c;
    c=*a;
    *a=*b;
    *b=c;
}

int main(){
    int m,n,i,j;
    cout<<"Enter the knapsack capacity : ";
    cin>>m;
    cout<<"Enter the no of objects : ";
    cin>>n;
    int w[n],p[n],o[n];
    float p_w[n];
    cout<<"Enter the profits of objects : ";
    for(i=0;i<n;i++){
        cin>>p[i];
        o[i]=i+1;
    }
    cout<<"Enter the weights of objects : ";
    for(i=0;i<n;i++){
        cin>>w[i];
    }
    for(i=0;i<n;i++){
        p_w[i]=(float)p[i]/w[i];
    }

    for(i=0;i<n;i++){
        int temp=i;
        for(j=i+1;j<n;j++){
            if(p_w[temp]<p_w[j]){
                temp=j;
            }
        }
        swap(&p_w[i],&p_w[temp]);
        swap(&p[i],&p[temp]);
        swap(&w[i],&w[temp]);
        swap(&o[i],&o[temp]);
    }

    float profit=0;
    cout<<"Objects included are : ";
    for(i=0;i<n;i++){
        if(w[i]<=m){
            m=m-w[i];
            profit+=p[i];
            cout<<o[i]<<" ";
        }
        else{
            if(m!=0)
            cout<<o[i]<<"/"<<((float)m/w[i])<<" ";
            profit+=p[i]*((float)m/w[i]);
            m=0;
        }
    }
    cout<<endl<<"Maximum profit : "<<profit;
    return 0;
}