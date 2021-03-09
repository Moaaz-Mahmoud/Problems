class Pair<T1, T2>(first : T1, second : T2);

fun rintarr() : IntArray = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
fun rlongarr() : LongArray = readLine()!!.split(" ").map { it.toLong() }.toLongArray()
fun rint() : Int = readLine()!!.toInt()
fun rlong() : Long = readLine()!!.toLong()


fun solve() {
    var ln = readLine()!!.split(" ")
    var x = ln[0].toInt(); var y = ln[1].toInt()

    var digits = y.toString().toCharArray().map { it.toInt()-48 }.toIntArray()
    //var digits = y.toString().split("").map { it.toInt() }.toIntArray()
    var ans = 0
    var i = 0
    while (i < digits.size){
        ans += digits[i]/x
        digits[i] = digits[i]%x
        if(i < digits.size-1)
            digits[i+1] += (digits[i]%x)*10
        i++
    }
    ans += digits[digits.size-1]/x + digits[digits.size-1]%x
    println(ans)
}

fun main(args: Array<String>) {
    var t = 1; t = readLine()!!.toInt()
    while (t-- > 0) solve()
}
