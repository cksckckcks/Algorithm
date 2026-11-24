import kotlin.math.max


fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val memory = readln().split(" ").map { it.toInt() }
    val cost = readln().split(" ").map { it.toInt() }
    val totalCost = cost.sum()

    val dp = Array(n + 1) { Array(totalCost + 1) { 0 } }

    for (i in 1..n) {
        for (j in 0..totalCost) {
            dp[i][j] = dp[i - 1][j]

            if (cost[i - 1] <= j) {
                dp[i][j] = maxOf(dp[i][j], dp[i - 1][j - cost[i - 1]] + memory[i - 1])
            }
        }
    }

    for (i in 0..totalCost) {
        if (dp[n][i] >= m) {
            println(i)

            break
        }
    }
}
