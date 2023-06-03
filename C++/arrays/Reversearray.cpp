// Using C++ STL(vector);
#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v){
    int s=0, e=v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}
void print(vector<int> v){
    for(int i=0; i<v.size();i++){
        cout<< v[i] << " ";
    }
    cout<<endl;
}
int main(){
    vector<int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);
    vector<int> ans = reverse(v);
    print(ans);
    return 0;
}

////////////////////using simple array;
#include <iostream>
using namespace std;
int main() {
   
 // TAKING INPUT 
   int n ;
   cin >> n ; 
   int arr[ n ] ;
   for ( int i = 0 ; i < n ; i++ ) 
   {
       cin >> arr[i] ;
   }
   
     // REVERSING THE ARRAY 
   int start = 0 ;
   int end = n-1 ; 
   
   while ( start <= end  ) {
       swap ( arr[start],arr[end] ) ;
       start++ ; 
       end-- ;
   }
   
   // PRINTING OUTPUT
   for ( int i = 0 ; i < n ; i++ ) {
       cout << arr[i] << " " ;
   }
    return 0 ; 
}
