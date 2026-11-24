
fun main() {
    val numbers = readln().split("-").map {
        it.split("+").map { n ->
            n.toInt()
        }.sum()
    }

    var ans = 0

    for (i in 0 until numbers.size) {
        if (i == 0) ans += numbers[i]
        else ans -= numbers[i]
    }

    println(ans)
}
