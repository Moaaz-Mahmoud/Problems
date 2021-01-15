import java.util.Scanner;
import java.lang.Math.*;
 
public class Main {
    public static void nl(){
        System.out.println();
    }
    private static Scanner sc = new Scanner(System.in);
    private static int rdint(){
        return sc.nextInt();
    }
    private static double rddbl(){
        return sc.nextDouble();
    }
    public static int n;
    public static int[] A;
    public static int[][] dp = new int[109][5];
    public static int solve(int idx, int last){
        if(idx == n) return 0;
        if(dp[idx][last] != -1) return dp[idx][last];
        
        if(A[idx] == 0){
            return dp[idx][last] = 1 + solve(idx+1, 0);
        }
        else if(A[idx] == 1){
            int p1 = 1 + solve(idx+1, 0), p2;
            if(last == 1) p2 = 100000;
            else          p2 = solve(idx+1, 1);
            return dp[idx][last] = Math.min(p1, p2);
        }
        else if(A[idx] == 2){
            int p1 = 1 + solve(idx+1, 0), p2;
            if(last == 2) p2 = 100000;
            else          p2 = solve(idx+1, 2);
            return dp[idx][last] = Math.min(p1, p2);
        }
        else{
            int p1 = 1 + solve(idx+1, 0), p2, p3;
            if(last == 1) p2 = 100000;
            else          p2 = solve(idx+1, 1);
            if(last == 2) p3 = 100000;
            else          p3 = solve(idx+1, 2);
            return dp[idx][last] = Math.min(Math.min(p1, p2), p3);
        }
    }
    
    public static void main(String[] args) {
        for(int i = 0; i < dp.length; i++)
            for(int j = 0; j < dp[i].length; j++)
                dp[i][j] = -1;
        
        n = rdint();
        A = new int[n];
        for(int i = 0; i < n; i++)
            A[i] = rdint();
        System.out.print(solve(0, 0) + "\n");
    }
    
}
