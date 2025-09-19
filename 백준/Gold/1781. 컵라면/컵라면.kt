import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.PriorityQueue

val br = BufferedReader(InputStreamReader(System.`in`))

fun main() {
    val n = br.readLine().toInt()
    val pq = PriorityQueue<Int>{ a, b ->
        a - b
    }
    

    val inputs = Array(n) {
        val (d, num) = br.readLine().split(" ").map { it.toInt() }
        d to num
    }.sortedWith { a, b ->
        if (a.first != b.first)
            a.first - b.first
        else
            b.second - a.second
    }

    repeat(n) { idx ->
        if (pq.size < inputs[idx].first)
            pq.add(inputs[idx].second)
        else if (pq.peek() < inputs[idx].second) {
            pq.poll()
            pq.add(inputs[idx].second)
        }
    }


    // for (i in 0 until pq.size)
    //     print(pq.poll())
    print(pq.sum())
}