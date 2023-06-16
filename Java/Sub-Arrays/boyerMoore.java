//This code in Java is an inplementation of Boyer Moore Algorithm to find the majority element in an array.
//The majority element is the element which occurs more than n/2 times in an array of size n.
//The time complexity of this algorithm is O(n) and space complexity is O(1).
//contributor :- Akhil Agrawal
//Gituhb :- swastik-akhil
public class boyerMoore{
    public static void main(String[] args) {
        int arr [] = {1,1,2,1,3,1,4,1,1,1,1,1,5,5,6,7,8};
        int count =1;
        int element = arr[0];
        for(int i=0;i<arr.length;i++){
            if(arr[i]==element){
                count++;
            }
            else{
                count--;
                if(count==0){
                    element = arr[i];
                    count =1;
                }
            }
        }
        if(count>1){
            System.out.println("Majority Element is :-" + element);
        }
        else{
            System.out.println("Majority Element is not present");
        }

    }
}