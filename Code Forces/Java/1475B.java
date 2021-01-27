import java.util.*;
import java.lang.Math.*;
import java.lang.Character;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Contests {
	public static void nl(){
        System.out.println();
    }
    public static Scanner sc = new Scanner(System.in);
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
    
    public static void main(String []args)
    {
    	int t = sc.nextInt();
    	Set<Integer> S = new HashSet<>();
    	int i, j = 0;
    	for(i = 0; i+j <= 1000000; i += 2020) {
    		for(j = 0; i+j <= 1000000; j += 2021)
    			S.add(i+j);
    		j = 0;
    	}
    	for ( i = 2020; i <= 1000000; i += 2020)
    		S.add(i);
    	for(i = 0; i+j <= 1000000; i += 2021) {
    		for(j = 0; i+j <= 1000000; j += 2020)
    			S.add(i+j);
    		j = 0;
    	}
    	while(t-- != 0) {
    		int n = sc.nextInt();
    		if(S.contains(n))
    			System.out.println("YES");
    		else
    			System.out.println("NO");
    	}
    }
}
