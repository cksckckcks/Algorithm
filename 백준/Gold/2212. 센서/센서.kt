fun main() {
    val n = readln().toInt()
    val k = readln().toInt()
    val points = readln().split(" ").map { it.toInt() }.sorted()
    
    val distance = Array(n) { 0 }
    for (i in 1 until n) {
        distance[i - 1] = points[i] - points[i - 1]
    }
    distance.sortDescending()

    var ans = 0
    for (i in k - 1 until distance.size) {
        ans += distance[i]
    }

    print(ans)
}
