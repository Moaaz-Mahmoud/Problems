import java.util.Scanner
val sc = Scanner(System.`in`)

fun solve(){
    var s = sc.next()
    var t = sc.next()
    var i = 0; var j = 0
    var can = true
    while (i < s.length && j < t.length){
        if(s[i] == t[j]){
            i++
            j++
        }
        else if(s[i] == '+' && t[j] == '-'){
            can = false
            break
        }
        else{
            if(i+1 < s.length && s[i+1] == '-'){
                i += 2
                j++
            }
            else{
                can = false
                break
            }
        }
    }
    if(i == s.length && j == t.length && can)
        print("YES")
    else
        print("NO")
    print("\n")
}

fun main(args: Array<String>) {
    var t = sc.nextInt()
    while (t-- > 0) solve()
}
