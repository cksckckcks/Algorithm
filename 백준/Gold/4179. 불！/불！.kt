import kotlin.math.min

val dx = listOf(0, 1, 0, -1)
val dy = listOf(1, 0, -1, 0)
lateinit var visited: Array<Boolean>

fun main() {
    val (r, c) = readln().split(" ").map { it.toInt() }
    val maze = Array(r) { CharArray(c) }

    val fireQueue = ArrayDeque<Triple<Int, Int, Int>>()
    val fireMap = Array(r) { Array(c) { 1000 } }
    val fireVisited = Array(r) { Array(c) { false } }

    val q = ArrayDeque<Triple<Int, Int, Int>>()
    val visited = Array(r) { Array(c) { false } }

    var answer = -1

    repeat(r) { rr ->
        val str = readln()

        repeat(c) { cc ->
            val chr = str[cc]

            maze[rr][cc] = chr
            if (chr == 'F') fireQueue.addLast(Triple(rr, cc, 0))
            if (chr == 'J') q.addLast(Triple(rr, cc, 0))
        }
    }

    while (fireQueue.isNotEmpty()) {
        val (x, y, cnt) = fireQueue.removeFirst()

        for (i in 0 until 4) {
            val xx = x + dx[i]
            val yy = y + dy[i]

            if (xx < 0 || xx >= r || yy < 0 || yy >= c || fireVisited[xx][yy] == true || maze[xx][yy] in listOf('#', 'F')) continue

            fireMap[xx][yy] = min(fireMap[xx][yy], cnt + 1)

            fireVisited[xx][yy] = true
            fireQueue.addLast(Triple(xx, yy, cnt + 1))
        }
    }

    while (q.isNotEmpty()) {
        val (x, y, cnt) = q.removeFirst()
        if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
            answer = cnt + 1

            break
        } 

        for (i in 0 until 4) {
            val xx = x + dx[i]
            val yy = y + dy[i]

            if (xx < 0 || xx >= r || yy < 0 || yy >= c || visited[xx][yy] == true || maze[xx][yy] in listOf('#', 'F', 'J')) continue

            if (fireMap[xx][yy] <= cnt + 1) continue

            visited[xx][yy] = true
            q.addLast(Triple(xx, yy, cnt + 1))
        }
    }

    println(if (answer == -1) "IMPOSSIBLE" else answer)
}
