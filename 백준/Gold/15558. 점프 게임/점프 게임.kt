import java.util.*

lateinit var jumpMap: Array<String>
lateinit var visited: Array<Array<Boolean>>
var n = 0
var k = 0
var isClear = false

/*
fun dfs(x: Int, y: Int, time: Int) {
    if (y >= n) {
        isClear = true
        
        return
    }
    
    if (y <= time - 1)
        return
    
    var xx = x
    var yy = y + 1
    if (yy >= n) isClear = true

    if (jumpMap[xx][yy] == '1') {
        visited[x][yy] = true
        dfs(x, yy, time + 1)
        visited[x][yy] = false
    }

    xx = x
    yy = y - 1
    if (y > time && yy >= 0 && jumpMap[x][yy] == '1') {
        visited[xx][yy] = true
        dfs(xx, yy, time + 1)
        visited[xx][yy] = false
    }

    xx = if (x == 0) 1 else 0
    yy = y + k
    if (yy >= n) isClear = true

    if (yy < n && jumpMap[xx][yy] == '1') {
        visited[xx][yy] = true
        dfs(xx, yy, time + 1)
        visited[xx][yy] = false
    }
}
*/

fun bfs() {
    var q: Queue<Triple<Int, Int, Int>> = LinkedList()

    q.add(Triple(0, 0, 0))
    visited[0][0] = true

    while (q.isNotEmpty()) {
        val (x, y, time) = q.poll()

        var xx = x
        var yy = y + 1
        if (yy >= n) {
            print(1)

            return
        }

        if (yy > time && jumpMap[xx][yy] == '1' && !visited[xx][yy]) {
            visited[xx][yy] = true
            q.add(Triple(xx, yy, time + 1))
        }

        xx = x
        yy = y - 1
        if (yy > time && yy >= 0 && jumpMap[x][yy] == '1' && !visited[xx][yy]) {
            visited[xx][yy] = true
            q.add(Triple(xx, yy, time + 1))
        }

        xx = if (x == 0) 1 else 0
        yy = y + k
        if (yy >= n) {
            print(1)

            return
        }

        if (yy > time && yy < n && jumpMap[xx][yy] == '1' && !visited[xx][yy]) {
            visited[xx][yy] = true
            q.add(Triple(xx, yy, time + 1))
        }
    }

    print(0)
}

fun main() {
    val input = readln().split(" ").map { it.toInt() }

    n = input[0]
    k = input[1]

    jumpMap = Array(2) { readln() }
    visited = Array(2) { Array(n) { false } }

    bfs()
}