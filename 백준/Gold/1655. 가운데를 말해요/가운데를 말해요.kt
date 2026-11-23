import java.util.PriorityQueue
import java.util.Collections

fun main() {
    val maxQueue = PriorityQueue<Int>()
    val minQueue = PriorityQueue<Int>(Collections.reverseOrder())
    val sb = StringBuilder()

    repeat(readln().toInt()) {
        val n = readln().toInt()

        if (minQueue.size >= maxQueue.size) {
            maxQueue.offer(n)
        } else {
            minQueue.offer(n)
        }

        if (minQueue.isNotEmpty() && maxQueue.isNotEmpty() && minQueue.peek() > maxQueue.peek()) {
            val minN = minQueue.poll()
            val maxN = maxQueue.poll()

            maxQueue.offer(minN)
            minQueue.offer(maxN)
        }

        sb.append(if ((it + 1) % 2 == 1) maxQueue.peek() else minQueue.peek()).append('\n')
    }

    print(sb)
}
