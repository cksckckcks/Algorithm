import kotlin.math.sqrt

fun main() {
    var N = readln().toInt()
    var dp = IntArray(50001){ 0 }

    for (i in 1 until 224)
        dp[i * i] = 1

    for (i in 2 .. N) {
        var tmp = Int.MAX_VALUE
        var n = sqrt(i.toDouble()).toInt()

        for (k in 1 .. n)
            if (tmp > dp[k * k] + dp[i - k * k])
                tmp = dp[k * k] + dp[i - k * k]

        if(dp[i] != 1)
            dp[i] = tmp
    }

    print("${dp[N]}")
}