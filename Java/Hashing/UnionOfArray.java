
import java.util.HashSet;
    public class UnionOfArray {
        static void unionOfTwoArrays(int arr1[],int arr2[])
        {
            HashSet<Integer> hs = new HashSet<>();
            for(int i=0;i<arr1.length;i++)
            {
                hs.add(arr1[i]);
            }
            for(int i=0;i<arr2.length;i++)
            {
                hs.add(arr2[i]);
            }
            System.out.println(""+hs);
        }
        public static void main(String[] args)
        {
            int arr1[]={1,2,3,4,5};
            int arr2[]={6,7,8,9};
            unionOfTwoArrays(arr1,arr2);
        }
    }

