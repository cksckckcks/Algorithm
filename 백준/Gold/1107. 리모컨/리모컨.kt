import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
 
 
 
val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))
var ans = 0
var n = 0
var nLength = 0
val arr = IntArray(10)

fun dfs(num: Int) {
    if (num.toString().length > 6)
        return

    val tmp = Math.abs(num - n) + num.toString().length

    if (ans > tmp)
        if (!(num == 0 && arr[0] == 1))
            ans = tmp

    for (i in 0 .. 9) {
        if (arr[i] == 1 || (num == 0 && i == 0))
            continue
        
        dfs(num * 10 + i)
    }
}

fun main() {
    
    n = br.readLine().toInt()
    val m = br.readLine().toInt()
    val input = if (m != 0) br.readLine().split(" ").map { it.toInt() } else emptyList()


    for (i in input) 
        arr[i] = 1
    
    nLength = n.toString().length
    ans = Math.abs(n - 100)

    dfs(0)

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}