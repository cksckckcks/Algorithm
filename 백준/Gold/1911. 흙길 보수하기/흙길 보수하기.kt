 fun main() {
    val (n, l) = readln().split(" ").map { it.toInt() }
    val water = Array(n) { val (start, end) = readln().split(" ").map {it.toInt()}
        start to end
    }.sortedWith(
        compareBy<Pair<Int, Int>> { it.first }
            .thenBy { it.second }
    )

    var now = 0
    var ans = 0

    repeat(n) { idx ->
        if (now < water[idx].first) {
            now = water[idx].first
        }

        while (now < water[idx].second) {
            ans++
            now += l
        }
    }

    print(ans)

}