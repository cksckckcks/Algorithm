fun main() {
    val n = readln().toInt()
    val arr = readln().split(" ").map { it.toInt() }

    val ans = Array(n) { 0 }

    for (i in 0 until n) {
        var cnt = 0

        for (j in 0 until n) {
            if (cnt == arr[i] && ans[j] == 0) {
                ans[j] = i + 1
                break
            } else if (ans[j] == 0) {
                cnt++
            }
        }
    }

    print(ans.joinToString(" "))
}