fun main() {
    val n = readln().toInt()

    if (n == 0) {
        println(1)
        return
    }
    
    val dp = Array(n + 1) { 0 }
    dp[0] = 1
    dp[1] = 1

    for (i in 2..n) {
        dp[i] = (1 + dp[i - 2] + dp[i - 1]) % 1000000007
    }

    println(dp[n])
}