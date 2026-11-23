import java.util.PriorityQueue

fun main() {
    val (_, m) = readln().split(" ").map { it.toInt() }
    val pq = PriorityQueue<Long>()
    val card = readln().split(" ").map { pq.add(it.toLong()) }

    repeat(m) {
        val n = pq.poll() + pq.poll()

        pq.add(n)
        pq.add(n)
    }

    println(pq.sum())
}
