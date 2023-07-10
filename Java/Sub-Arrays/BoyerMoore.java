// The Boyer-Moore Majority Voting Algorithm is an efficient algorithm used to find the majority element in an array, if it exists. A majority element is an element that appears more than n/2 times in an array of length n.
// The algorithm works by maintaining a candidate variable and a count variable. It iterates through the array, updating the candidate and count based on certain conditions

public class BoyerMoore {
    public static void main(String[] args) {
        int arr [] = {2,1,2,2,2,1,1,3,2};
        int x=1, count =1, element = arr[0];
        while(x<arr.length){
            if(arr[x]==element){
                count++;
            }

            else if (arr[x]!=element){
                count--;
            }

            else if (arr[x]!=element && count==1){
                count--;
                element=arr[x];
            }
            x++;
        }
        System.out.println("The majority element is " + element);
        
    }
}
