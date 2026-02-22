import java.util.LinkedList
import kotlin.math.abs

fun main() {
    val t = readln().toInt()

    repeat(t) {
        val n = readln().toInt()

        val house = getPoint()
        val stores = Array(n) { getPoint() }
        val festival = getPoint()

        var result = false
        val visited = BooleanArray(n)
        val q = LinkedList<Pair<Int, Int>>()

        q.add(house)

        while (q.isNotEmpty()) {
            val (x, y) = q.poll()

            if (abs(x - festival.first) + abs(y - festival.second) <= 1000) {
                result = true
                break
            }

            for (i in 0 until n) {
                if (!visited[i]) {
                    val (nx, ny) = stores[i]

                    if (abs(x - nx) + abs(y - ny) <= 1000) {
                        visited[i] = true
                        q.add(stores[i])
                    }
                }
            }
        }

        println(if (result) "happy" else "sad")
    }
}

fun getPoint(): Pair<Int, Int> {
    val (x, y) = readln().split(" ").map { it.toInt() }
    return x to y
}
