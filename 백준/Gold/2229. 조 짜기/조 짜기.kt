import kotlin.math.*

fun main() {
    val n = readln().toInt()
    val students = readln().split(" ").map { it.toInt() }
    val diff = Array(n + 1) { Array(n + 1) { 0 } }
    val dp = Array(n + 1) { 0 }

    for (i in 1..n) {
        var minStudent = students[i - 1]
        var maxStudent = students[i - 1]

        for (j in i..n) {
            minStudent = min(students[j - 1], minStudent)
            maxStudent = max(students[j - 1], maxStudent)

            diff[i][j] = maxStudent - minStudent
        }
    }

    for (i in 1..n) {
        for (j in 0 until i) {
            dp[i] = max(dp[i], dp[j] + diff[j + 1][i])
        }
    }

    print(dp[n])
}