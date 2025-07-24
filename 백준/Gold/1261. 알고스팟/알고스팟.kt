import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.ArrayDeque
 
 
val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var N = 0
var M = 0
lateinit var map: Array<IntArray>
var ans = 0
var visited = Array(100) { IntArray(100) { 0 } }
val dx = intArrayOf(0, 1, 0, -1)
val dy = intArrayOf(1, 0, -1, 0)

// 시간초과 dfs -> bfs
fun bfs() {
    val q = ArrayDeque<Triple<Int, Int, Int>>()

    q.add(Triple(0, 0, 0))

    while (q.isNotEmpty()) {
        val n = q.removeFirst()

        for (i in 0 until 4) {
            val xx = n.first + dx[i]
            val yy = n.second + dy[i]

            if (xx == M - 1 && yy == N - 1) {
                ans = n.third
                return
            }

            if (xx in 0 until M && yy in 0 until N && visited[xx][yy] == 0) {
                visited[xx][yy] = 1
                if (map[xx][yy] == 0)
                    q.addFirst(Triple(xx, yy, n.third))
                else
                    q.addLast(Triple(xx, yy, n.third + 1))
            }
        }

        
    }
    

    
}

fun main() {
    val input = br.readLine()!!.split(" ").map{it.toInt()}

    N = input[0]
    M = input[1]

    map = Array(M) { br.readLine()!!.map { it - '0' }.toIntArray() }

    visited[0][0] = 1
    bfs()

    bw.write("$ans")
    
    bw.flush()
    bw.close()
    br.close()
}