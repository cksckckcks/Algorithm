import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.PriorityQueue

val br = BufferedReader(InputStreamReader(System.`in`))


fun main() {
    val n = br.readLine().toInt()
    val oils = Array(n){br.readLine().split(" ").map { it.toInt() }}.sortedWith(compareBy({it[0]}, {it[1]}))
    val (l, p) = br.readLine().split(" ").map{ it.toInt() }
    val pq = PriorityQueue<Int> { a, b -> b - a }

    var now = 0
    var nowOil = p
    var ans = 0

    for (oil in oils) {
        val tmp = oil[0] - now

        while (pq.isNotEmpty() && nowOil < tmp) {
            ans++
            nowOil += pq.poll()
        }

        if (nowOil < tmp)
            break
        
        nowOil -= tmp
        pq.add(oil[1])
        now = oil[0]

        if (now >= l)
            break
    }

    if (now < l) {
        now += nowOil

        while (pq.isNotEmpty() && now < l) {
            ans++
            now += pq.poll()
        }
    }

    print(if (now >= l) ans else -1)
}