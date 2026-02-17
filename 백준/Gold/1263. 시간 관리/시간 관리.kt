fun main() {
    val n = readln().toInt()

    val works = Array(n) {
        val (t, s) = readln().split(" ").map { it.toInt() }
        t to s
    }

    val sortedWorks = works.sortedWith(
        compareByDescending<Pair<Int, Int>> { it.second }
            .thenBy { it.first }
    )

    var time = sortedWorks.first().second
    for (work in sortedWorks) {
        time = minOf(time, work.second)
        time -= work.first
    }

    println(if (time >= 0) time else -1)
}
