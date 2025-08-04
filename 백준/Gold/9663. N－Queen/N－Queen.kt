import kotlin.math.abs

var n = 0
var ans = 0
var chess = Array(15) { 0 }

fun main() {
    n = readln().toInt()

    nQueens(0)

    print(ans)
}

fun nQueens(cnt: Int) {
    if (cnt == n) {
        ans++
        return
    }

    for (i in 0 until n) {
        chess[cnt] = i
        if (check(cnt))
            nQueens(cnt + 1)
    }
}

fun check(row: Int): Boolean {
    for (i in 0 until row)
        if (chess[i] == chess[row] || abs(chess[row] - chess[i]) == row - i)
            return false
            
        return true
}