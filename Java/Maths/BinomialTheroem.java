import java.util.Scanner;
import java.lang.Math;

public class BinomialTheroem{
	public static int fact(int n){
	int factn =1;
	for(int i=1; i<n+1; i++){
		factn = factn*i;
	}
	return factn;
}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter in (1+x)^n the values of x and n respectively");
		int x = sc.nextInt();
		int n = sc.nextInt();
		int nf=fact(n);
		int [] arr = new int[n+1]; 
		
		for(int i=0;i<=n;i++){
			int ncr = nf/ (fact(i)*fact(n-i));
			arr[i] = ncr* (int)Math.pow(x,i) ;
			arr[n-i] = ncr* (int)Math.pow(x,n-i) ;
		}

		for(int i=0; i<arr.length; i++){
			System.out.print(arr[i] + " ");
		}

		sc.close();
	}
}
