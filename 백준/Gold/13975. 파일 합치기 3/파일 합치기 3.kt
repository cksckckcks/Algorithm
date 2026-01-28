import java.util.PriorityQueue

fun main() {
    val t = readln().toInt()

    repeat(t) {
        val pq = PriorityQueue<Long>()

        val k = readln().toInt()
        readln().split(" ")
            .map { it.toLong() }
            .forEach { pq.add(it) }
        
        var ans = 0L
        while (pq.size > 1) {
            val sum = pq.poll() + pq.poll()
           
            ans += sum
            
            pq.add(sum)
        }

        println(ans)
    }
}