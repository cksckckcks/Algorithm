fun main() {
    var (E, S, M) = readLine()!!.split(" ").map { it.toInt() }

    var e = 1
    var s = 1
    var m = 1
    var ans = 1

    while (!(E == e && S == s && M == m)) {
        e = if (e == 15) 1 else e + 1
        s = if (s == 28) 1 else s + 1
        m = if (m == 19) 1 else m + 1
        ans++
    }

    print(ans)
}