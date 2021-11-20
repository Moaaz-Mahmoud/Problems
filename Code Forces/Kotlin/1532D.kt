fun readListI() = readLine()!!.split(" ").map { it.toInt() }
fun readListL() = readLine()!!.split(" ").map { it.toLong() }
 
fun main(args: Array<String>) {
    val(n) = readLine()!!.split(" ").map { it.toInt() }
    var A = readListI().sorted()
    var i = 0; var sum = 0L
    while (i < n){
        sum += A[i+1] - A[i]
        i+=2
    }
    print(sum)
}
