fun main() {
    val n = readln().toInt()
    val balloons = readln().split(" ").map { it.toInt() }
    val maxHeight = balloons.max()
    val arrows = IntArray(maxHeight + 1) { 0 }
    
    var ans = 0
    for (height in balloons) {
        if (arrows[height] > 0) {
            arrows[height]--
        } else {
            ans++
        }

        arrows[height - 1]++
    }

    print(ans)
}