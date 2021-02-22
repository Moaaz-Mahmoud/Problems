import java.util.Scanner
val sc = Scanner(System.`in`)


fun main(args: Array<String>) {
    var t = sc.nextInt()
    while (t-- > 0){
        var small = sc.nextInt()
        var big = sc.nextInt()
        if(small > big) {
            var temp = small
            small = big
            big = temp
        }
        println("1 " + (small-1).toString() + " " + (big-small+1).toString())
    }
}
