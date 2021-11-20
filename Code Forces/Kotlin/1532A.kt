fun main(args: Array<String>) = repeat(readLine()!!.toInt()) {
    val(a, b) = readLine()!!.split(" ").map { it.toInt() }
    println(a+b)
}
