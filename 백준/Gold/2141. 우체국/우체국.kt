fun main() {
    val n = readln().toInt()
    
    var humanCount = 0L
    val villages = Array(n) {
        val (x, a) = readln().split(" ").map { it.toLong() }
        humanCount += a

        x to a
    }
    
    villages.sortBy { it.first }

    var count = 0L
    for ((x, a) in villages) {
        count += a
        if (count >= (humanCount + 1) / 2) {
            print(x)
            break
        }
    }
}