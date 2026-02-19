import java.util.PriorityQueue

fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val devices = readln().split(" ").map { it.toInt() }.sortedDescending()

    val pq = PriorityQueue<Int>()

    var now = 0
    for (i in 0 until n) {
        if (pq.size >= m) {
            now = pq.poll()
        }

        pq.add(now + devices[i])
    }

    while (pq.isNotEmpty()) {
        now = pq.poll()
    }

    println(now)
}