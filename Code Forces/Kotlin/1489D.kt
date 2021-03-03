import java.util.*

val sc = Scanner(System.`in`)

data class Pair(var first : Int, var second : Int){}

fun solve() {
    var n = readLine()!!.toInt()
    var A = arrayOfNulls<String>(n)
    for(i in 0..n-1) A[i] = readLine()!!

    var M = mutableMapOf<Pair?, Boolean>()
    for(i in 0..n-1){
        for(j in 0..n-1) {
            if(i == j) continue
            if(A[i]!! in A[j]!!)
                M[Pair(i, j)] = true
            else
                M[Pair(i, j)] = false
        }
    }

    var vis = mutableMapOf<Int, Boolean> ()
    var ans = IntArray(n); var idx = n-1; var eligCnt = 0
    for(i in 0..n-1){
        for(j in 0..n-1) if(!vis.containsKey(j) || !vis[j]!!){
            var elig = true
            for(k in 0..n-1) if(!vis.containsKey(k) || !vis[k]!!){
                if(j == k) continue
                if(M[Pair(j, k)] == false)
                    elig = false
            }
            if(elig){
                ans[idx--] = j
                vis[j] = true
                eligCnt++
            }
        }
    }
    if(eligCnt == n) {
        println("YES")
        for(i in ans.size-1 downTo 0 step 1)
            println(A[ans[i]])
    }
    else{
        println("NO")
    }
}

fun main(args: Array<String>) {
    var t = 1; //t = readLine()!!.toInt()
    while (t-- > 0) solve()
}
