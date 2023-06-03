/*Name :  Hardik Goyal
Github username : HardikGoyal2003
Repositary name : Algorithms
*/
/* Problem Statement : Given a Integer between 0-4000, the task is to convert it into its Roman Numeral Equivalent.
EXAMPLES : 
1)
Input:  55
Output: "LV"
2)
Input:  2876
Output: "MMDCCCLXXVI"
3)
Input: 4030
Output: "Enter Number Between 0-4000" */

#include<bits/stdc++.h>
using namespace std;

int main(){

  int n; //Input Number
  cin>>n;
  string roman; //Final Output String 

  //loop running until number becomes zero or less  
  while(n>0){	

    //Check for Number lie in valid range or not
  	if (n<4000 and n>0)
  	{

	    if(n>=1000){
        
        //Number will be reduced
	      n-=1000;

        //Roman charcter is appending in string   
	      roman.push_back('M');
	    
	    }

		else if(n>=900){

	      n-=900;
	      roman.push_back('C');
	      roman.push_back('M');
	   
	    }
	    
	    else if(n>=500){

	      n-=500;
	   	  roman.push_back('D');
	     
	     }
		
		else if(n>=400){

	      n-=400;
	      roman.push_back('C');
	      roman.push_back('D');
	   
	    }

	    else if(n>=100){

	      n-=100;
	      roman.push_back('C');

	    }

		else if(n>=90){

	      n-=90;
	      roman.push_back('X');
	      roman.push_back('C');
	   
	    }

	    else if(n>=50){

	      n-=50;
	      roman.push_back('L');

	    }

		else if(n>=40){

	      n-=40;
	      roman.push_back('X');
	      roman.push_back('L');
	   
	    }      
	    
	    else if(n>=10){

	      n=n-10;
	      roman.push_back('X');
	      
	    }   
		
		else if(n>=9){

	      n-=9;
	      roman.push_back('I');
	      roman.push_back('X');
	   
	    }    
	    else if(n>=5){

	      n-=5;
	      roman.push_back('V');

	    }   
		
		else if(n>=4){

	      n-=4;
	      roman.push_back('I');
	      roman.push_back('V');
	    }    
	    else if(n>=1){

	      n-=1;
	      roman.push_back('I');      
	    } 

	}    

    else{

      cout<<"Enter Number Between 0-4000";
      break;

    }  
  }

   cout<<roman; //Final Output

}