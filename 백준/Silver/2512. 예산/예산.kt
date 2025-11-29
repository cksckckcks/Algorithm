import kotlin.system.exitProcess

fun check(citys: List<Int>, maxMoney: Int, limit: Int): Boolean {
    var sum = 0

    for (c in citys) {
        sum += if (c > limit) limit else c

        if (sum > maxMoney)
            return false
    }

    return true
}

fun main() {
    val n = readln().toInt()
    val citys = readln().split(" ").map { it.toInt() }
    val m = readln().toInt()

    var left = 0
    var right = citys.max()

    // if (citys.sum() < m) {
    //     println(citys.max())

    //     exitProcess(0)
    // }

    while (left <= right) {
        val mid = (left + right) / 2

        if (check(citys, m, mid)) {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    println(right)
}