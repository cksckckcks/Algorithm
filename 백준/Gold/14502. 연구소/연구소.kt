import java.util.*
import kotlin.math.max

var n = 0
var m = 0

lateinit var lab: Array<Array<Int>>
lateinit var visited: Array<Array<Boolean>>
lateinit var copyLab: Array<Array<Int>>
var virus = mutableListOf<Pair<Int, Int>>()

val dx = listOf(0, 1, 0, -1)
val dy = listOf(1, 0, -1, 0)

var ans = 0

fun setWell(x: Int, y: Int, cnt: Int) {
    if (cnt == 3) {
        copyLab = lab.map{ it.copyOf() }.toTypedArray()
        visited = Array(n) { Array(m) { false } }

        bfs()

        val cnt = copyLab.sumOf { it.count { it == 0 } }

        ans = max(ans, cnt)

        return
    }

    for (i in x until n) {
        val range = if (i == x) y else 0
        
        for (j in range until m) {
            if (lab[i][j] == 0) {
                lab[i][j] = 1

                setWell(i, j, cnt + 1)

                lab[i][j] = 0
            }
        }
    }
}

fun bfs() {
    val q: Queue<Pair<Int, Int>> = LinkedList()

    virus.forEach { q.add(it) }

    while (q.isNotEmpty()) {
        val (nowX, nowY) = q.poll()

        visited[nowX][nowY] = true

        for (i in 0..3) {
            val xx = nowX + dx[i]
            val yy = nowY + dy[i]

            if (xx < 0 || xx >= n || yy < 0 || yy >= m || visited[xx][yy] || copyLab[xx][yy] == 1) {
                continue
            }

            copyLab[xx][yy] = 2

            q.add(Pair(xx, yy))
        }
    }


}

fun setVirus() {
    for (i in 0 until n) {
        for (j in 0 until m) {

            if (lab[i][j] == 2) {
                virus.add(Pair(i, j))
            }
        }
    }
}

fun main() {
    val input = readln().split(" ").map { it.toInt() }

    n = input[0]
    m = input[1]

    lab = Array(n) { readln().split(" ").map { it.toInt() }.toTypedArray() }
    visited = Array(n) { Array(m) { false } }

    setVirus()

    setWell(0, 0, 0)

    print(ans)
}
