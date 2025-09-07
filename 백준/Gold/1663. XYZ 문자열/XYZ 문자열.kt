fun main() {
    val ansNum = readln().toInt()
    val n = readln().toInt()

    val arr = LongArray(maxOf(n, 3))
    arr[0] = 1
    arr[1] = 2
    arr[2] = 2
    
    for (i in 3 until n)
        arr[i] = arr[i - 3] + arr[i - 2]


    when (ansNum) {
        1 -> {
            print(arr[n - 1])
        }

        2 -> {
            var k = readln().toLong() - 1
            val s = arrayOf(
                charArrayOf('X'),
                charArrayOf('Y', 'Z'),
                charArrayOf('Z', 'X')
            )
            var idx = n - 1

            while (idx > 2) {
                val leftCnt = arr[idx - 3]

                if (k < leftCnt)
                    idx -= 3
                else {
                    k -= leftCnt
                    idx -= 2
                }
            }

            print(s[idx][k.toInt()])
        }

        else -> {
            val kk = readln()[0]
            val idx = when (kk) {
                'X' -> 0
                'Y' -> 1
                else -> 2
            }

            val dp = Array(maxOf(n, 3)) { LongArray(3) }
            dp[0] = longArrayOf(1, 0, 0) // X
            dp[1] = longArrayOf(0, 1, 1) // YZ
            dp[2] = longArrayOf(1, 0, 1) // ZX

            for (i in 3 until n) {
                val X = dp[i - 3][0] + dp[i - 2][0]
                val Y = dp[i - 3][1] + dp[i - 2][1]
                val Z = dp[i - 3][2] + dp[i - 2][2]

                dp[i] = longArrayOf(X, Y, Z)
            }

            print(dp[n - 1][idx])
        }
    }
}