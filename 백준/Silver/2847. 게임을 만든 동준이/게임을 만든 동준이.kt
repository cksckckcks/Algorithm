

fun main() {
    val n = readln().toInt()
    val points = mutableListOf<Int>()

    repeat(n) {
        points.add(readln().toInt())
    }

    var point = points[n - 1]
    var ans = 0
    for (i in n - 2 downTo 0) {
        val now = points[i]

        if (now >= point) {
            ans += now - point + 1

            points[i] = point - 1
        }

        point = points[i]
    }

    println(ans)
}
