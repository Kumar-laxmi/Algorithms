class hammingDistance {
    public static void main(String[] args) {
      int x = 9 , y = 14 , count =0;
      int res = x ^ y;
      while(res>0){
        count+= res &1;
        res >>=1;
      }
      System.out.println(count);
    }
  }
  