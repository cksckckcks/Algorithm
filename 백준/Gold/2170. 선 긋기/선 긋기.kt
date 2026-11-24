
fun main() {
    val list = mutableListOf<Pair<Int, Int>>()
    val n = readln().toInt()

    repeat(n) {
        val (a, b) = readln().split(" ").map { it.toInt() }

        list.add(a to b)
    }

    val sortedList = list.sortedWith(
        compareBy { it.first }
    )

    var ans = 0
    var (left, right) = sortedList[0]

    for (i in 1 until n) {
        val (a, b) = sortedList[i]


        if (right >= a) {
            if (right < b) right = b
        } else {
            ans += right - left

            left = a
            right = b
        }
    }

    ans += right - left

    println(ans)
}
