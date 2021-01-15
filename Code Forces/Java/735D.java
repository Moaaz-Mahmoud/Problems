import java.util.*;
import java.lang.Math.*;
import java.lang.Character;
 
public class Contests {
    public static void nl(){
        System.out.println();
    }
    public static Scanner sc = new Scanner(System.in);
    public static int rdint(){
        return sc.nextInt();
    }
    public static double rddbl(){
        return sc.nextDouble();
    }
    public static long rdlong(){
        return sc.nextLong();
    }
    public static long max(long a, long b){
        return a > b ? a : b;
    }
    public static long max(long a, long b, long c){
        return max(max(a, b), c);
    }
    public static long min(long a, long b){
        return a < b ? a : b;
    }
    public static long min(long a, long b, long c){
        return min(min(a, b), c);
    }
    
    public static Boolean isPrime(long n) {
    	if (n <= 1) return false;
    	for (long i = 2; i * i <= n; i++) {
    		if (n % i == 0) return false;
    	}
    	return true;
    }
    
    public static void main(String[] args) {
    	int n;
    	n = rdint();
    	Boolean pr = isPrime(n);
    	if(pr)
    		System.out.print(1);
    	else if(n%2 == 0)
    		System.out.print(2);
    	else if(isPrime(n-2))
    		System.out.print(2);
    	else
    		System.out.print(3);
    }
}
