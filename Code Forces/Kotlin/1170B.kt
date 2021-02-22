import java.util.Scanner
val sc = Scanner(System.`in`)


fun main(args: Array<String>) {
    var n = sc.nextInt()
    var A = Array(n) { 0 }
    for(i in 0..n-1)
        A[i] = sc.nextInt()
    var ans = 0
    if(n == 1){
        print(0)
    }
    else {
        var m1 = -1;
        var m2 = -1
        if (A[0] > A[1])
            { m1 = A[0]; m2 = A[1] }
        else
            { m1 = A[1]; m2 = A[0] }
        for (i in 2..n - 1) {
            if(m1 > A[i] && m2 > A[i])
                ans++
            if(A[i] >= m1)
                { m2 = m1; m1 = A[i] }
            else if(A[i] > m2)
                { m2 = A[i] }
        }
        print(ans)
    }
}
