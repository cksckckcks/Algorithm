import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.PriorityQueue

val br = BufferedReader(InputStreamReader(System.`in`))



fun main() {
    val (n, k) = br.readLine().split(" ").map { it.toInt() }

    val jewelry = Array(n) {
        val (a, b) = br.readLine().split(" ").map { it.toInt() } 
        a to b    
    }.sortedWith(
        compareBy<Pair<Int, Int>> { it.first }
            .thenBy { it.second }
    )

    val bag = Array(k) { br.readLine().toInt() }.sorted()
    
    var ans = 0L
    val pq = PriorityQueue<Int>(reverseOrder())
    var rememberIdx = 0

    for (i in 0 until k) {
        while (rememberIdx < n && jewelry[rememberIdx].first <= bag[i]) {
            pq.add(jewelry[rememberIdx].second)
            rememberIdx++
        }

        if (pq.isNotEmpty())
            ans += pq.poll()
    }
    
    print(ans)
}