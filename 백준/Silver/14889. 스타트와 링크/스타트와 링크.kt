import kotlin.math.abs

var n = 0
lateinit var ability: Array<List<Int>>
lateinit var visited: BooleanArray
var ans = Int.MAX_VALUE

fun main() {
    n = readln().toInt()

    ability = Array(n) { readln().split(" ").map { it.toInt() } }
    visited = BooleanArray(n) { false }

    dfs(0, 0)

    println(ans)
}

fun dfs(cnt: Int, last: Int) {
    if (cnt == n / 2) {
        // println(visited.joinToString())
        // println(getGap())
        ans = minOf(ans, getGap())

        return
    }

    for (i in last until n) {
        if (visited[i]) { continue }
        visited[i] = true
        dfs(cnt + 1, i + 1)
        visited[i] = false
    }
}

fun getGap(): Int {
    var gap = 0

    for (i in 0 until n) {
        for (j in i + 1 until n) {
            if (visited[i] == visited[j]) {
                val score = ability[i][j] + ability[j][i]
                gap += if (visited[i]) score else -score
            }
        }
    }

    return abs(gap)
}
