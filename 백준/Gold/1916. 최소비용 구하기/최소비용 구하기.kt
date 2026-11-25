import java.util.PriorityQueue

data class Bus(
    val start: Int,
    val dest: Int,
    val cost: Int,
)

fun main() {
    val n = readln().toInt()
    val m = readln().toInt()

    val buses = Array(n + 1) { mutableListOf<Bus>() }

    repeat(m) {
        val (s, d, c) = readln().split(" ").map { it.toInt() }

        buses[s].add(Bus(s, d, c))
    }

    val (s, e) = readln().split(" ").map { it.toInt() }

    val pq = PriorityQueue<Pair<Int, Int>>(
        compareBy<Pair<Int, Int>> { it.second }
    )

    pq.add(s to 0)
    val visited = Array(n + 1) { false }

    while (pq.isNotEmpty()) {
        val (now, cost) = pq.poll()
        visited[now] = true

        if (now == e) {
            println(cost)
            
            break
        }

        for (i in buses[now].indices) {
            val bus = buses[now][i]

            if (visited[bus.dest] == true) continue

            pq.add(bus.dest to cost + bus.cost)
        }
    }
}