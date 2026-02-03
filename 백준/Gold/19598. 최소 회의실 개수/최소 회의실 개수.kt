import java.util.PriorityQueue

fun main() {
    val n = readln().toInt()

    val times = Array(n) { 
        val input = readln().split(" ").map { it.toInt() }

        input[0] to input[1] 
    }
    times.sortWith(compareBy { it.first })

    val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.second })
    pq.add(times[0])

    for (i in 1 until n) {
        val nextMeeting = times[i]
        val endTime = pq.peek().second

        if (nextMeeting.first >= endTime) {
            pq.poll()
        }

        pq.add(nextMeeting)
    }
    
    print(pq.size)
}