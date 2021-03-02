import java.lang.StringBuilder
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max

val sc = Scanner(System.`in`)

fun solve() {
    var n = readLine()!!.toInt()
    val A = readLine()!!.split(" ").map { it.toInt() }
    var S = mutableSetOf<Int>()
    var Ans = arrayListOf<Int>()
    var i = n-1
    while(i >= 0) {
        if(!S.contains(A[i])){
            S.add(A[i])
            Ans.add(0, A[i])
        }
        i--
    }
    println(Ans.size)
    for(ans in Ans)
        print(ans.toString() + " ")
    println()
}

fun main(args: Array<String>) {
    var t = 1; //t = sc.nextInt()
    while (t-- > 0) solve()
}
