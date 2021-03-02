import java.lang.StringBuilder
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max

val sc = Scanner(System.`in`)

fun solve() {
    var n = readLine()!!.toInt()
    var s = readLine()
    var cnt = 0; var ans = 0
    if (s != null) {
        for(c in s){
            if(c == 'x') cnt++
            else         cnt = 0
            if(cnt >= 3) ans++
        }
    }
    println(ans)
}

fun main(args: Array<String>) {
    var t = 1; //t = readLine()!!.toInt()
    while (t-- > 0) solve()
}
