import java.util.LinkedList

fun main() {
    val (n, k, m) = readln().split(" ").map { it.toInt() }
    val hyperTubes = Array(m) {
        readln().split(" ").map { it.toInt() }
    }
    val stations = Array(n + 1) { mutableListOf<Int>() }

    for (i in 0 until m) {
        for (stationNumber in hyperTubes[i]) {
            stations[stationNumber].add(i)
        }
    }

    val visited = Array(n + 1) { false }
    val visitedTubes = Array(m + 1) { false }
    var ans = -1
    val q = LinkedList<Pair<Int, Int>>()
    q.add(Pair(1, 1))
    visited[1] = true

    while (q.isNotEmpty()) {
        val (now, cnt) = q.poll()

        if (now == n) {
            ans = cnt
            break
        }

        for (hyperTubeNumber in stations[now]) {
            if (visitedTubes[hyperTubeNumber]) {
                continue
            }
            visitedTubes[hyperTubeNumber] = true
            for (stationNumber in hyperTubes[hyperTubeNumber]) {
                if (!visited[stationNumber]) {
                    visited[stationNumber] = true

                    q.add(Pair(stationNumber, cnt + 1))
                }
            }
        }
    }

    println(ans)
}