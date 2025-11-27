import kotlin.system.exitProcess

val dx = listOf(0, 1, 0, -1)
val dy = listOf(1, 0, -1, 0)
var dir = 0
var nowX = 0
var nowY = 0
var idx = 0

fun main() {
    val n = readln().toInt()
    val k = readln().toInt()

    val board = Array(n) { Array(n) { 0 } }
    val visited = Array(n) { Array(n) { 0 } }

    repeat(k) {
        val(x, y) = readln().split(" ").map { it.toInt() }

        board[x - 1][y - 1] = 1
    }

    val l = readln().toInt()

    val snakeDir = Array(l) {
        val (x, c) = readln().split(" ")

        x.toInt() to c
    }

    val q = ArrayDeque<Pair<Int, Int>>()
    q.add(0 to 0)
    visited[0][0] = 1

    for (time in 1 .. 10000) {
        val xx = nowX + dx[dir]
        val yy = nowY + dy[dir]

        if (idx < snakeDir.size && snakeDir[idx].first == time) {
            dir = if (snakeDir[idx].second == "D") (dir + 1) % 4 else (4 + dir - 1) % 4

            idx++
        }
        
        if (xx < 0 || xx >= n || yy < 0 || yy >= n || visited[xx][yy] == 1) {
            print(time)

            exitProcess(0)
        }

        q.add(xx to yy)
        visited[xx][yy] = 1

        if (board[xx][yy] == 0) {
            val (qx, qy) = q.removeFirst() 
            visited[qx][qy] = 0
        } else {
            board[xx][yy] = 0
        }

        nowX = xx
        nowY = yy
    }
}