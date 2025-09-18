import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))

var r = 0
var c = 0
var ans = 0
lateinit var map: Array<CharArray>
lateinit var visited: Array<BooleanArray>


val dx = arrayOf(-1, 0, 1)
val dy = arrayOf(1, 1, 1)



fun dfs(x: Int, y: Int): Boolean {
    if (y == c - 1)
        return true

    for (i in 0 until 3) {
        val xx = x + dx[i]
        val yy = y + dy[i]

        if (xx !in 0 .. r - 1 || map[xx][yy] != '.')
            continue
        
        map[x][y] = '0'

        if (dfs(xx, yy))
            return true
    }

    return false
}

fun main() {
    val input = br.readLine().split(" ").map { it.toInt() }

    r = input[0]
    c = input[1]

    map = Array(r) { br.readLine().toCharArray() }
    visited = Array(r) { BooleanArray(c) { false } }

    repeat(r) { idx ->
        if (dfs(idx, 0) == true)
            ans++
    }

    print(ans)
}