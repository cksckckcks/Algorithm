fun main() {
    while (true) {
        val input = readln().split(" ")
        val n = input[0].toInt()
        val m = input[1].toDouble()

        if (n == 0 && m == 0.00) { break }

        val mm = (m * 100.0 + 0.5).toInt()
        val dp = Array(mm + 1) { 0 }
        for (i in 0 until n) {
            val candyInput = readln().split(" ")
            val calorie = candyInput[0].toInt()
            val money = (candyInput[1].toDouble() * 100.0 + 0.5).toInt()

            for (j in 0..mm) {
                if (j - money >= 0) {
                    dp[j] = maxOf(dp[j], dp[j - money] + calorie)
                }
            }
        }

        println(dp[mm])
    }
}

// (n / 2의 거듭 제곱) 꼴로 나타낼 수 없는 모든 실수는 정확하게 표현되지 않는다. (rounding error)
// -> 따라서 이를 방지하기 위해 적당한 작은 수를 더해 소숫점 아래를 버림해도 문제 없도록 한다.