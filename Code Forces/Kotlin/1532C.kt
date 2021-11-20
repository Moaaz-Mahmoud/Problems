fun main(args: Array<String>) = repeat(readLine()!!.toInt()) {
    val(n, k) = readLine()!!.split(" ").map { it.toLong() }
    var i = 0
    while (i < n){
        var j = 0
        while (j < k && i < n){
            print('a'+j)
            j++
            i++
        }
    }
    println()
}
