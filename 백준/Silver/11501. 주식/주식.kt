fun main() {
    val T = readln().toInt()

    repeat(T) {
        val N = readln().toInt()
        val stock = readln().split(" ").map { it.toInt() }

        var sum = 0L
        var max = stock[N - 1]

        for (i in N - 2 downTo 0) {
            if (stock[i] < max) {
                sum += max - stock[i]
            } else {
                max = stock[i]
            }
        }

        println(sum)
    }
}