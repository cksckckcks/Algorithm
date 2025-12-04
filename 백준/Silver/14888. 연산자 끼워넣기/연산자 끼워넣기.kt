import kotlin.math.*

lateinit var operCnt: Array<Int>
lateinit var list: Array<Int>
var n = 0
var minValue = Int.MAX_VALUE
var maxValue = Int.MIN_VALUE

fun dfs(num: Int, idx: Int) {
    if (idx == n) {
        minValue = min(minValue, num)
        maxValue = max(maxValue, num)

        return
    }

    if (operCnt[0] > 0) {
        operCnt[0]--
        dfs(num + list[idx], idx + 1)
        operCnt[0]++
    }
    if (operCnt[1] > 0) {
        operCnt[1]--
        dfs(num - list[idx], idx + 1)
        operCnt[1]++ 
    }
    if (operCnt[2] > 0) {
        operCnt[2]--
        dfs(num * list[idx], idx + 1)
        operCnt[2]++
    }
    if (operCnt[3] > 0) {
        val tmp = if (num > 0) num / list[idx] else (num * -1 / list[idx]) * -1

        operCnt[3]--
        dfs(tmp, idx + 1)
        operCnt[3]++
    }
}

fun main() {
    n = readln().toInt()

    list = readln().split(" ").map { it.toInt() }.toTypedArray()
    
    operCnt = readln().split(" ").map { it.toInt() }.toTypedArray()

    dfs(list[0], 1)

    print("$maxValue\n$minValue")
}