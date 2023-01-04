public class Sieve_erastonetihis {
    public static void main(String[] args) {
        // If you have to find prime numbers till n 
        int n = 1;
        //creating boolean array to mark multiples of primes as true
        //So all true element will be prime numbers
        if(n<=1){
            System.out.println("There is no prime numbers");
        }
        boolean [] primes = new boolean[n+1];
        sieve(n, primes);
    }
    public static void sieve(int n, boolean [] primes){
        for(int i=2;i*i<=n;i++){
            if(!primes[i]){
                for(int j=2*i;j<=n;j+=i){
                    primes[j]= true;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(!primes[i]){
                System.out.print(i + " ");
            }
        }

    }
}
