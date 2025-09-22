fun main() {
    val (n, m, k) = readln().split(" ").map { it.toInt() }
    val gap = Array<Pair<Int, Int>>(n) { 0 to 0 }

    val judgment = readln().split(" ").map { it.toInt() }

    var start = 1
    var end = judgment[k - 1] - judgment[0]
    var maxDist = 0

    while (start <= end) {
        var mid = (start + end) / 2
        var cnt = 1
        var prev = judgment[0]

        for (i in 1 until k) {
            if (judgment[i] - prev >= mid) {
                prev = judgment[i]
                cnt++
            }
        }

        // m개 배치 불가 시 갭 감소, m개 이상 배치 가능 시 거리 벌려보기
        if (cnt < m)
            end = mid - 1
        else {
            maxDist = mid
            start = mid + 1
        }
    }

    print(1)

    var cnt = 1
    var prev = judgment[0]

    for (i in 1 until k) {
        if (judgment[i] - prev >= maxDist && cnt < m) {
            print(1)

            prev = judgment[i]
            cnt++
        }
        else
            print(0)
    }
}