import kotlin.math.max

fun main() {
    val (n, k) = readln().split(" ").map { it.toInt() }
    val volumes = Array(n) { readln().toInt() }

    val maxVolume = getMaxVolume(k, volumes)
    
    print(maxVolume)
}

fun getMaxVolume(k: Int, volumes: Array<Int>): Long {
    var left = 1L
    var right = volumes.max().toLong()
    var maxVolume = 0L

    while (left <= right) {
        val mid = (left + right) / 2
        val count = getCount(volumes, mid.toInt())

        if (count < k) {
            right = mid - 1
        } else if  (count >= k) {
            maxVolume = max(maxVolume, mid)
            left = mid + 1
        }
    }

    return maxVolume
}

fun getCount(volumes: Array<Int>, value: Int): Int {
    return volumes.sumOf { it / value }
}