import java.lang.Math.min
import java.util.*

val sc = Scanner(System.`in`)

fun solve() {
    var n = readLine()!!.toInt()
    var y = 0; var x = 1
    var A = mutableMapOf<Int, Int>()

    for(i in 1..n){
        var tokens = readLine()!!.split(" ")
        var cmd = tokens[0][0]
        var id  = tokens[1].toInt()
        if(cmd == 'L'){
            A[id] = --x
        }
        else if(cmd == 'R'){
            A[id] = ++y
        }
        else{
            println(      min( y - A[id]!! , A[id]!! - x )      )
        }
    }
}

fun main(args: Array<String>) {
    var t = 1; //t = readLine()!!.toInt()
    while (t-- > 0) solve()
}
