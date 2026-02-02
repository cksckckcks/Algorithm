val dx = listOf(0, 1, 0, -1, 1, -1, 1, -1)
val dy = listOf(1, 0, -1, 0, -1, 1, 1, -1)
lateinit var visited: Array<Array<Boolean>>
lateinit var banners: Array<List<Int>>
var m = 0
var n = 0

fun bfs(x: Int, y: Int) {
    val q = ArrayDeque<Pair<Int, Int>>()

    visited[x][y] = true
    q.add(Pair(x, y))

    while (q.isNotEmpty()) {
        val (qx, qy) = q.removeFirst()

        for (i in 0 until 8) {
            val xx = qx + dx[i]
            val yy = qy + dy[i]

            if (xx < 0 || xx >= m || yy < 0 || yy >= n || banners[xx][yy] == 0 || visited[xx][yy]) { continue }

            visited[xx][yy] = true
            q.add(Pair(xx, yy))
        }
    }
}


fun main() {
    val input = readln().split(" ").map { it.toInt() }
    m = input[0]
    n = input[1]

    banners = Array(m) {
        readln().split(" ").map { it.toInt() }
    }
    visited = Array(m) { Array(n) { false } }
    
    var ans = 0
    for (i in 0 until m) {
        for (j in 0 until n) {
            if (banners[i][j] == 1 && !visited[i][j]) {
                bfs(i, j)
                ans++
            }
        }
    }

    print(ans)
}