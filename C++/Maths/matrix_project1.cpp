#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cout<<"  Press 1 For Matrix Addition "<<endl;
	cout<<"  Press 2 For Matrix Subtraction "<<endl;
	cout<<"  Press 3 For Matrix Multiplication "<<endl;
	cout<<"  Press 4 For Transpose Matrix "<<endl;
	cout<<"  Press 5 For Determinant Matrix "<<endl;
	cout<<"  Press 6 For Adjoint Matrix "<<endl;
	cout<<"  Press 7 For Inverse Matrix "<<endl<<endl;
	cout<<"  Enter A Valid Operation Digit: ";
	cin>>t;
	switch(t){
		
		       case 1:{
                        int a,b,c,d,e,f,g,i,j,arr1[100][100],arr2[100][100],arr3[100][100];
                        cout<<"Matrix Addition"<<endl;
                        cout << "Enter Rows And Column of Matrix A  ";
                        cin >> a>> b;
                       
                        cout<<"Enter elements of Matrix A "<<endl;
                        for(i=0;i<a;i++){
						
                        for(j=0;j<b;j++){
					
                         cout << "Enter Element A" << i + 1 << j + 1 << ": ";
                        cin>>arr1[i][j];
                    }
                }
                 cout << "Enter Rows And Column of Matrix B  ";
                        cin >> c >>d; 
                        cout << "Enter elements of Matrix B " << endl;
                        for( i=0;i<c;i++){
						
                        for(j=0;j<d;j++){
						
                         cout << "Enter Element B" << i + 1 << j + 1 << ": ";
                        cin>>arr2[i][j];
                    }
                }
                        for( i=0;i<a;i++)
                        for( j=0;j<b;j++)
                        arr3[i][j]=arr1[i][j]+arr2[i][j];
                        cout<<"Sum of Matrix A and B is "<<endl;
                        for(i=0;i<a;i++){
                        for(j=0;j<b;j++)
                        cout<<arr3[i][j]<<"\t";
                        cout<<endl;
                   }
            break;
		}
		        case 2:{
                         int a,b,c,d,e,f,g,i,j,arr1[100][100],arr2[100][100],arr3[100][100];
                         cout<<"Matrix Subtraction"<<endl;
                         cout << "Enter Rows And Column of Matrix A  ";
                         cin >> a>> b;
                          
                         cout<<"Enter Elements of Matrix A "<<endl;
                         for( i=0;i<a;i++){
						 
                         for( j=0;j<b;j++){
						 
                          cout << "Enter Element A" << i + 1 << j + 1 << ": ";
                         cin>>arr1[i][j];
                     }
                 }
                 cout << "Enter Rows And Column of Matrix B  ";
                         cin >> c >>d;
                         cout << "Enter Elements of Matrix B " << endl;
                         for(i=0;i<c;i++){
						 
                         for(j=0;j<d;j++){
						 
                          cout << "Enter Element B" << i + 1 << j + 1 << ": ";
                         cin>>arr2[i][j];
                     }
                 }
                         for(i=0;i<a;i++)
                         for(j=0;j<b;j++)
                         arr3[i][j]=arr1[i][j]-arr2[i][j];
                         cout<<"Subtraction of matrix A and B is "<<endl;
                         for(int i=0;i<a;i++){
                         for(int j=0;j<b;j++)
                         cout<<arr3[i][j]<<"\t";
                         cout<<endl;
                    }
                 break;
		       }
	           	case 3:{
                         int x,y,z,w,a[100][100],b[100][100],c[100][100];
                         cout<<"Matrix Multiplication"<<endl;
                         cout<<"Enter the Number of Rows of First Matrix: "<<endl;
                         cin>>x;
                         cout<<"Enter the Number of Coloumns of First Matrix: "<<endl;
                         cin>>y;
                         cout<<"Enter the Number of Rows of Second Matrix: "<<endl;
                         cin>>z;
                         cout<<"Enter the Number of Coloumns of Second Matrix: "<<endl;
                         cin>>w;
                         while(y!=z){
                         cout<<"Multiplication is Not Possible"<<endl;
                        }
                       while(y==z){
                         cout<<"Multiplication is Possible"<<endl;
                     break;
                   }                
                         cout<<"Enter the First Matrix Elements: "<<endl;
                         for(int i=0;i<x;i++){
                         for(int j=0;j<y;j++){
                         	cout << "Enter Element a" << i + 1 << j + 1 << ": ";
                         cin>>a[i][j];
                   }
               }
                      cout<<"Enter the Second Matrix Elements: "<<endl;
                      for(int i=0;i<x;i++){
                      for(int j=0;j<y;j++){
                      	cout << "Enter Element b" << i + 1 << j + 1 << ": ";
                     cin>>b[i][j];
               }
            }
                     cout<<"Multiplication of Matrix is: "<<endl;
                     for(int i=0;i<x;i++){
                     for(int j=0;j<y;j++){
                     c[i][j]=0;
                     for(int k=0;k<y;k++){
                     c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
                     for(int i=0;i<x;i++){
                     for(int j=0;j<y;j++){
                     cout<<c[i][j]<<"\t";
           }
        cout<<endl;
    }
			break;
		}
		case 4:{
			             int a[100][100], tp[100][100], r, c, i, j;
			             cout<<"Transpose Matrix"<<endl;
                         cout << "Enter Rows And Columns of Matrix: ";
                         cin >> r >> c;
                         cout << "\nEnter Elements of Matrix: " << endl;
                         for (int i = 0; i < r;i++) {
                         for (int j = 0; j < c;j++) {
                         cout << "Enter Element a" << i + 1 << j + 1 << ": ";
                         cin >> a[i][j];
                         }
                    }
                         cout << "\nEntered Matrix: " << endl;
                         for (int i = 0; i < r; ++i) {
                         for (int j = 0; j < c; ++j) {
                         cout << " " << a[i][j];
                         if (j == c- 1)
                         cout << endl;
                }
            }
                         for (int i = 0; i < r; ++i)
                         for (int j = 0; j < c; ++j) {
                         tp[j][i] = a[i][j];
        }
                         cout << "\nTranspose of Matrix: " << endl;
                         for (int i = 0; i < c; ++i)
                         for (int j = 0; j < r; ++j) {
                         cout << " " << tp[i][j];
                         if (j == r- 1)
                        cout<< endl;
            }
             break;
		}
		     case 5:{
		     	
                         int n;
                         cout<<"Determinant Matrix"<<endl;
                         cout<<"Enter the Order of Matrix: "<<endl;
                         cin>>n;
                         int a[n][n];
                         float determinant = 0;
                         cout<<"Enter the Element of Matrix: "<<endl;
                         for(int i=0;i<n;i++){
                         for(int j=0;j<n;j++){
                         cout << "Enter Element a" << i + 1 << j + 1 << ": ";
                         cin>>a[i][j];
                      }
                     }
                       cout<<"The Matrix is: "<<endl;
                       for(int i=0;i<n;i++){
                       for(int j=0;j<n;j++){
                      cout<<a[i][j]<<" ";
              }
                        cout<<endl;
            }
                        if(n==2){
                        determinant = a[0][0]*a[1][1] - a[1][0]*a[0][1];
                     cout<<fixed<<setprecision(2)<<"Determinant of The Matrix is: "<<determinant<<endl;
               }
                     else{
                     for(int i=0;i<n;i++){
                     determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
              }
                   cout<<fixed<<setprecision(2)<<"Determinant of The Matrix Is: "<<determinant<<endl;
            }

			break;
		}
		case 6:{
			        int n;
			        cout<<"Adjoint Of A Matrix"<<endl;
                    cout<<"Enter Order of Matrix: "<<endl;
                    cin>>n;
                    int a[n][n];
                    float determinant = 0;
                    cout<<"Enter the Element of Matrix: "<<endl;
                    for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                    cout << "Enter Element a" << i + 1 << j + 1 << ": ";
                    cin>>a[i][j];
                }
             }
                    cout<<"The Matrix is: "<<endl;
                    for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                    cout<<a[i][j]<<" ";
             }
                    cout<<endl;
         }
                    if(n==2){
                    determinant = a[0][0]*a[1][1] - a[1][0]*a[0][1];
                    
             }
                    else{
                    for(int i=0;i<n;i++){
                    determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
             }
                  
          }
               cout<<"Adjoint of The Matrix is: "<<endl;
               for(int i=0;i<n;i++){
                 for(int j=0;j<n;j++){
                 cout<<fixed<<setprecision(2)<<((a[(j+1)%3][(i+1)%3]*a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3]*a[(j+2)%3][(i+1)%3]))<<" ";
                    }
                    cout<<endl;
                }
			break;
		}
		case 7:{
                 int n;
                 cout<<"Inverse Matrix"<<endl;
                 cout<<"Enter the Order of Matrix: "<<endl;
                 cin>>n;
                 int a[n][n];
                 float determinant = 0;
                 cout<<"Enter the Element of Matrix: "<<endl;
                 for(int i=0;i<n;i++){
                 for(int j=0;j<n;j++){
        	     cout << "Enter Element a" << i + 1 << j + 1 << ": ";
                 cin>>a[i][j];
              }
            }
                 cout<<"The Matrix is: "<<endl;
                for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
           }
                cout<<endl;
        }
                if(n==2){
                determinant = a[0][0]*a[1][1] - a[1][0]*a[0][1];
                cout<<fixed<<setprecision(2)<<"Determinant of The Matrix is: "<<determinant<<endl;
       }
                 else{
                 for(int i=0;i<n;i++){
                 determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
        }
                 cout<<fixed<<setprecision(2)<<"Determinant Of The Matrix is: "<<determinant<<endl;
     }
                 cout<<"The Inverse of The Matrix is: "<<endl;
                 for(int i=0;i<n;i++){
                 for(int j=0;j<n;j++){
            cout<<fixed<<setprecision(2)<<((a[(j+1)%3][(i+1)%3]*a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3]*a[(j+2)%3][(i+1)%3]))/determinant<<" ";
         }
        cout<<endl;
    }
    	break;
		}
	    default:{
			exit;
		}
	}
}
