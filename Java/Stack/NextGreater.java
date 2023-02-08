/*  Approach for solving
This code finds the next greater element for each element in the array.
It uses a stack data structure to keep track of the indices of the elements in the array.
The loop starts from the end of the array and for each element, the code checks
if there's any element in the stack with a value greater than the current element.
If there is, that element is the next greater element for the current element.
If not, the current element has no next greater element, so -1 is stored.
Finally, the index of the current element is pushed onto the stack.
The process repeats for all elements in the array.
The result is stored in the "nxtGre" array, and finally, it's printed out.
 */

//package Java_practice.Stack;
import java.util.*;
public class NextGreater {
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
        int size=sc.nextInt();
        int arr[]=new int[size];
        for(int i=0;i<size;i++){
            arr[i]=sc.nextInt();
        }
        Stack<Integer> s=new Stack<>();
        int nxtGre[]=new int[size];

        for(int i=size-1;i>=0;i--){
            while(!s.isEmpty() && arr[s.peek()]<=arr[i]){
                s.pop();
            }
            if(s.isEmpty()){
                nxtGre[i]=-1;
            }else{
                nxtGre[i]=arr[s.peek()];
            }
            s.push(i);
        }

        for(int j=0;j<nxtGre.length;j++){
            System.out.print(nxtGre[j]+" ");
        }
        System.out.println();
    }
}
