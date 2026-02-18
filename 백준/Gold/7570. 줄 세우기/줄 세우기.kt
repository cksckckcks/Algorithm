fun main() {
    val n = readln().toInt()

    val childrens = readln().split(" ").map { it.toInt() }

    val dp = Array(n + 1) { 0 }

    for (children in childrens) {
        dp[children] = dp[children - 1] + 1
    }

    println(n - dp.max())
}