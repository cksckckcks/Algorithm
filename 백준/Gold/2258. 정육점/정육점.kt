fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val meats = Array(n) { readln().split(" ").map { it.toInt() } }
    val sortedMeats = meats.sortedWith(
        compareBy<List<Int>> { it[1] }
        .thenByDescending { it[0] }
    )

    var meatWeight = 0
    var lastPrice = -1
    var lastPriceCnt = 0
    var ans = Int.MAX_VALUE
    var isAnswer = false

    for ((weight, price) in sortedMeats) {
        meatWeight += weight

        if (lastPrice == price) {
            lastPriceCnt++
        } else {
            lastPrice = price
            lastPriceCnt = 0
        }

        if (meatWeight >= m) {
            isAnswer = true
            ans = minOf(ans, price * (lastPriceCnt + 1))
        }
    }

    print(if (isAnswer) ans else -1)
}
