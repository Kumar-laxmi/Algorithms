

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

    public class IntersectionOfArray {
        static void intersectionOfTwoArrays(int nums1[],int nums2[])
        {
            Map<Integer, Integer> h = new HashMap<>();
            for(int i=0;i<nums1.length;i++)
            {
                h.put(nums1[i],h.getOrDefault(nums1[i],0)+1);
            }

            List<Integer> list = new ArrayList<>();
            for(int i=0; i<nums2.length; i++){
                if(h.containsKey(nums2[i]) && h.get(nums2[i])>0){
                    list.add(nums2[i]);
                    h.put(nums2[i], h.get(nums2[i])-1);
                }
            }

            int[] ans = new int[list.size()];
            for(int i=0; i<list.size(); i++)
                ans[i] = list.get(i);
            for(int i=0;i<ans.length;i++)
            {
                System.out.println(" " + ans[i]);
            }

        }
        public static void main(String[] args)
        {
            int arr1[]={4,9,7};
            int arr2[] ={1,2,4,9,4,9};
            intersectionOfTwoArrays(arr1,arr2);
        }


    }
