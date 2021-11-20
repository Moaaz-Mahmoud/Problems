fun main(args: Array<String>) = repeat(readLine()!!.toInt()) {
    val(a, b, k) = readLine()!!.split(" ").map { it.toLong() }
    println(a*((k+1)/2) - b*(k/2))
}
