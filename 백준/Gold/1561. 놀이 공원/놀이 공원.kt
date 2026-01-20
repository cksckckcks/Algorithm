fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val times = readln().split(" ").map { it.toInt() }

    if (n <= m) {
        print(n)
        return
    }
    
    var left = 1L
    var right = 2_000_000_000L * 30L
    var time = 0L

    while (left <= right) {
        val mid = (left + right) / 2L

        if (isAllRide(n, times, mid)) {
            time = mid
            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    var rideCount = m.toLong()
    times.forEach {
        rideCount += (time - 1) / it.toLong()
    }

    for (i in 0 until m) {
        if (time % times[i].toLong() == 0L) {
            rideCount++
        }

        if (rideCount == n.toLong()) {
            print(i + 1)
            break
        }
    }
}

fun isAllRide(n: Int, times: List<Int>, value: Long): Boolean {
    var rideCount = times.size.toLong()

    for (t in times) {
        rideCount += value / t.toLong()
        if (rideCount >= n) {
            return true
        }
    }

    return false
}
