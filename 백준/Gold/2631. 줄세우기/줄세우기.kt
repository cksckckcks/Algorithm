import kotlin.math.max

fun main() {
    val n = readln().toInt()

    val kids = Array(n) { readln().toInt() }

    val dp = Array(n + 1) { 0 }

    for (i in 0 until n) {
        dp[i] = 1

        for (j in 0 until i) {
            if (kids[i] > kids[j]) {
                dp[i] = max(dp[i], dp[j] + 1)
            }
        }
    }

    print(n - dp.maxOf{ it })
}