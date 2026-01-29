import java.util.PriorityQueue

fun main() {
    val pq = PriorityQueue<Pair<Int, Int>>(
        compareByDescending<Pair<Int, Int>> { it.second }
    )

    val n = readln().toInt()
    repeat(n) {
        val (time, score) = readln().split(" ").map { it.toInt() }

        pq.add(Pair(time, score))
    }

    var ans = 0
    val isClear = Array(1001) { false }

    while (pq.isNotEmpty()) {
        var (day, score) = pq.poll()

        while (day > 0) {
            if (!isClear[day]) {
                ans += score
                isClear[day] = true
                break
            }
            day--
        }
    }

    print(ans)
}