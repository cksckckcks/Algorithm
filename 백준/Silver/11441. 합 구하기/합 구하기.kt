fun main() {
    val n = readln().toInt()
    val a = readln().split(" ").map { it.toInt() }

    val m = readln().toInt()

    val arr = Array(n + 1) { 0 }
    arr[1] = a[0]
    for (i in 2 .. n) {
        arr[i] = arr[i - 1] + a[i - 1]
    }

    repeat(m) {
        val (i, j) = readln().split(" ").map { it.toInt() }

        println(arr[j] - arr[i - 1])
    }
}