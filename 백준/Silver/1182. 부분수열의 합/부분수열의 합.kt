import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.ArrayDeque
 
 
val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var N = 0
var S = 0
var ans = 0
lateinit var arr: IntArray

fun dfs(sum: Int = 0, idx: Int = 0) {
    if (idx == N) {
        if (sum == S)
            ans++
        return
    }

    dfs(sum + arr[idx], idx + 1)
    dfs(sum, idx + 1)

}

fun main() {
    val input = br.readLine()!!.split(" ").map{it.toInt()}

    N = input[0]
    S = input[1]

    arr = br.readLine()!!.split(" ").map { it.toInt() }.toIntArray()

    dfs()

    if (S == 0)
        ans--
        
    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}