import kotlin.math.abs
import kotlin.math.max

var N = 0
var M = 0
var D = 0
lateinit var map: Array<IntArray>
lateinit var copyMap: Array<IntArray>
var ans = 0

fun main() {
    val input = readln().split(" ").map { it.toInt() }

    N = input[0]
    M = input[1]
    D = input[2]

    map = Array(N) { readln().split(" ").map { it.toInt() }.toIntArray() }
    copyMap = Array(N) { map[it].copyOf() }

    for (i in 0 until M) {
        for (j in i + 1 until M) {
            for (k in j + 1 until M) {
                ans = max(ans, shoot(listOf(i, j, k)))
                copyMap = Array(N) { map[it].copyOf() }
            }
        }
    }

    print(ans)
}

fun Pair<Int, Int>.getDist(other: Pair<Int, Int>): Int {
    return abs(this.first - other.first) + abs(this.second - other.second)
}

fun shoot(archerList: List<Int>): Int {
    var cnt = 0
    var now = N

    while (now > 0) { // 0번까지만 보면 됨
        val target = mutableListOf<Pair<Int, Int>>()

        for (archer in archerList) {
            var shootList = mutableListOf<Triple<Int, Int, Int>>()

            for (i in 0 until now) {
                for (j in 0 until M) {
                    if (copyMap[i][j] == 0)
                        continue
                    val dist = Pair(now, archer).getDist(Pair(i, j))

                    if (dist <= D)
                        shootList.add(Triple(i, j, dist))
                }
            }

            if (shootList.isEmpty())
                continue

            shootList.sortWith(
                compareBy<Triple<Int, Int, Int>> { it.third }
                    .thenBy { it.second }
            )

            val nowTarget = shootList.first()
            target.add(Pair(nowTarget.first, nowTarget.second))
        }

        for ((x, y) in target) {
            if (copyMap[x][y] == 1) {
                cnt++
                copyMap[x][y] = 0
            }
        }

        now--
    }
    return cnt
}