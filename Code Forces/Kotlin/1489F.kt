import java.lang.Integer.max
import java.util.*
import java.math.*

val sc = Scanner(System.`in`)

data class Pair(var first : Int, var second : Int){}

var n = 0; var m = 0L; var k = 0L

fun can(r : Int, A : LongArray) : Boolean{
    var remainingBoxes = m; var remainingSize = k
    var i = r
    while(i < n){
        if(A[i] <= remainingSize){
            remainingSize -= A[i]
            i++
        }
        else{
            remainingBoxes--
            remainingSize = k
            if(remainingBoxes == 0L) return false
        }
    }
    return true
}
fun solve() {
    var ln = readLine()!!.split(" ")
    n = ln[0].toInt(); m = ln[1].toLong();k = ln[2].toLong()
    var A : LongArray = readLine()!!.split(" ").map { it.toLong() }.toLongArray()

    var l = 0; var r = n; var x = (l+r)/2
    var ans = 0
    while (l <= r){
        x = (l+r)/2
        if(can(x, A)){
            r = x-1
            ans = max(ans, n-x)
        }
        else {
            l = x+1
        }
    }
    print(ans)
}

fun main(args: Array<String>) {
    var t = 1; //t = readLine()!!.toInt()
    while (t-- > 0) solve()
}
