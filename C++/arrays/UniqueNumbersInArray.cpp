class Solution{
  public:
    int findUnique(int a[], int n, int k) {
       sort(a,a+n);
       for(int i=0;i<n;i+=k){
           if(a[i]!=a[i+1]){
               return a[i];
           }
       }
    }
};
