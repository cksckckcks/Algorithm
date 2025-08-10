import kotlin.math.max

var N = 0
var ans = 0
lateinit var egg: Array<Array<Int>>

fun main() {
    N = readln().toInt()

    egg = Array(N) {
        var (a, b) = readln().split(" ").map { it.toInt() }
        arrayOf(a, b)
    }

    dfs()

    print(ans)
}

fun dfs(n: Int = 0, cnt: Int = 0) {
    if (n == N || cnt == N) {
        ans = max(ans, cnt)
        return
    }

    if (egg[n][0] <= 0) {
        dfs(n + 1, cnt)
        return
    }

    var isHit = false

    for (i in 0 until N) {
        if (n == i || egg[i][0] <= 0)
            continue
        
        isHit = true

        egg[i][0] -= egg[n][1]
        egg[n][0] -= egg[i][1]

        var tmp = 0

        if (egg[i][0] <= 0)
            tmp++
        if (egg[n][0] <= 0)
            tmp++

        dfs(n + 1, cnt + tmp)

        egg[i][0] += egg[n][1]
        egg[n][0] += egg[i][1]
    }

    if (!isHit)
        dfs(n + 1, cnt)
}