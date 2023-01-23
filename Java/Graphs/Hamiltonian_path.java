import java.util.*;
class Hamiltonian_path
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while(t-- > 0)
        {
            String input_line[] = read.readLine().trim().split("\\s+");
            int N = Integer.parseInt(input_line[0]);
            int M = Integer.parseInt(input_line[1]);

            input_line = read.readLine().trim().split("\\s+");
            ArrayList<ArrayList<Integer>> Edges = new ArrayList<ArrayList<Integer>>();
            for(int i = 0;i < M;i++)
            {
                ArrayList<Integer> e = new ArrayList<Integer>();
                e.add(Integer.parseInt(input_line[2*i]));
                e.add(Integer.parseInt(input_line[2*i+1]));
                Edges.add(e);
            }
            Solution ob = new Solution();
            if(ob.check(N, M, Edges))
                System.out.println(1);
            else
                System.out.println(0);
        }
    }
}

class Solution 
{ 
    boolean check(int N, int M, ArrayList<ArrayList<Integer>> Edges) 
    { 
      ArrayList<Integer> al[]=new ArrayList[N+1];
      
      for(int i=0;i<N+1;i++)
          al[i]=new ArrayList<>();
      
      for(ArrayList<Integer> ed:Edges)
      {
          int src=ed.get(0);
          int des=ed.get(1);
          al[src].add(des);
          al[des].add(src);
      }
      Set<Integer> st=new HashSet<>();
    
     for(int i=1;i<=N;i++)
     {
     if(find(al,i,st))
     return true;
     }
      return false;
   }
   public static boolean find(ArrayList<Integer> al[],int src,Set<Integer> st)
   {
               st.add(src);
       if(st.size()==al.length-1)
       return true;

       for(Integer ele:al[src])
       {
           if(!st.contains(ele))
           {
               if(find(al,ele,st))
               return true;
           }
       }
       st.remove(src);
       return false;
   }
}
