import java.util.PriorityQueue

data class Road(
    val start: Int,
    val dest: Int,
    val length: Int,
    val toll: Int,
)

fun main() {
    val k = readln().toInt() // 준비해 둔 교통비
    val n = readln().toInt()
    val r = readln().toInt()

    val roads = Array(n + 1) { mutableListOf<Road>() }
    repeat(r) {
        val (s, d, l, t) = readln().split(" ").map { it.toInt() }

        roads[s].add(Road(s, d, l, t))
    }

    // now, cost, dist
    val pq = PriorityQueue<Triple<Int, Int, Int>>(
        compareBy<Triple<Int, Int, Int>> { it.third }
            .thenBy { it.second }
            .thenBy { it.first }
    )

    pq.add(Triple(1, 0, 0))
    
    // val visited = Array(n + 1) { false }

    var ans = -1
    while (pq.isNotEmpty()) {
        val (now, cost, dist) = pq.poll()

        // visited[now] = true

        if (now == n) {
            ans = dist
            
            break
        }

        for (i in roads[now].indices) {
            val road = roads[now][i]

            if (road.toll + cost > k) continue

            // visited[road.dest] = true
            // 여기서 pq에 들어가기전에 true로 바뀌어도 우선순위가 밀려 사용되지 않는 경우 발생
            // 따라서, pq에서 빼게 되면 (우선순위가 1번일 때) visited를 초기화함

            // println("$now -> ${road.dest} $cost $dist")

            pq.add(Triple(road.dest, cost + road.toll, dist + road.length))
        }
    }

    println(ans)
}
