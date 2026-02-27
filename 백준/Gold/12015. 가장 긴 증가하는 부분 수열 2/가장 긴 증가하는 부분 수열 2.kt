fun main() {
    val n = readln().toInt()
    val sequence = readln().split(" ").map { it.toInt() }
    val ans = mutableListOf<Int>()

    for (num in sequence) {
        if (ans.lastOrNull() ?: -1 < num) {
            ans.add(num)
        } else {
            var left = 0
            var right = ans.size
           
            while (left < right) {
                val mid = (left + right) / 2

                if (ans[mid] < num) {
                    left = mid + 1
                } else {
                    right = mid
                }
            }
            
            ans[right] = num
        }
    }


    println(ans.size)
}
