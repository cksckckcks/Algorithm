import java.util.PriorityQueue

fun main() {
    val pq = PriorityQueue<Int>()

    val n = readln().toInt()
    repeat(n) { 
        val card = readln().toInt()

        pq.add(card)    
    }

    var ans = 0
    while (pq.size > 1) {
        val sum = pq.poll() + pq.poll()
        
        pq.add(sum)

        ans += sum
    }

    print(ans)
}