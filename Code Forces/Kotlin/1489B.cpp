import java.lang.StringBuilder
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max

val sc = Scanner(System.`in`)

fun solve() {
    var ln = readLine()!!.split(" ")
    var n = ln[0].toLong()
    var a = ln[1].toLong()
    var b = ln[2].toLong()
    if(b >= 2*a) println(a*n)
    else         println((n/2)*b+a*(n%2))
}

fun main(args: Array<String>) {
    var t = 1; t = readLine()!!.toInt()
    while (t-- > 0) solve()
}
