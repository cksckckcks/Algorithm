import kotlin.math.max

var n = 0
var m = 0
lateinit var papers: Array<List<Int>>

fun ter1(x: Int, y: Int): Int {
    var ret = 0

    if (x + 3 < n) {
        val sum = (x..x + 3).sumOf { papers[it][y] }

        ret = max(sum, ret)
    }

    if (x - 3 >= 0) {
        val sum = (x - 3..x).sumOf { papers[it][y] }

        ret = max(sum, ret)
    }

    if (y + 3 < m) {
        val sum = (y..y + 3).sumOf { papers[x][it] }

        ret = max(sum, ret)
    }

    if (y - 3 >= 0) {
        val sum = (y - 3..y).sumOf { papers[x][it] }

        ret = max(sum, ret)
    }

    return ret
}

fun ter2(x: Int, y: Int): Int {
    var ret = 0
    
    if (x + 1 < n && y + 1 < m) {
        val sum = papers[x][y] + papers[x][y + 1] + papers[x + 1][y] + papers[x + 1][y + 1]

        ret = max(sum, ret)
    }

    if (x + 1 < n && y - 1 >= 0) {
        val sum = papers[x][y] + papers[x][y - 1] + papers[x + 1][y] + papers[x + 1][y - 1]

        ret = max(sum, ret)
    }

    if (x - 1 >= 0 && y + 1 < m) {
        val sum = papers[x][y] + papers[x][y + 1] + papers[x - 1][y] + papers[x - 1][y + 1]

        ret = max(sum, ret)
    }

    if (x - 1 >= 0 && y - 1 >= 0) {
        val sum = papers[x][y] + papers[x][y - 1] + papers[x - 1][y] + papers[x - 1][y - 1]

        ret = max(sum, ret)
    }

    return ret
}

fun ter3(x: Int, y: Int): Int {
    var ret = 0

    if (x + 2 < n && y + 1 < m) {
        val sum = papers[x][y] + papers[x + 1][y] + papers[x + 2][y] + papers[x + 2][y + 1]

        ret = max(sum, ret)
    }

    if (x - 1 >= 0 && y + 2 < m) {
        val sum = papers[x][y] + papers[x][y + 1] + papers[x][y + 2] + papers[x - 1][y + 2]

        ret = max(sum, ret)
    }

    if (x - 2 >= 0 && y - 1 >= 0) {
        val sum = papers[x][y] + papers[x - 1][y] + papers[x - 2][y] + papers[x - 2][y - 1]

        ret = max(sum, ret)
    }

    if (x + 1 < n && y - 2 >= 0) {
        val sum = papers[x][y] + papers[x][y - 1] + papers[x][y - 2] + papers[x + 1][y - 2]

        ret = max(sum, ret)
    }

    if (x + 2 < n && y - 1 >= 0) {
        val sum = papers[x][y] + papers[x + 1][y] + papers[x + 2][y] + papers[x + 2][y - 1]

        ret = max(sum, ret)
    }

    if (x + 1 < n && y + 2 < m) {
        val sum = papers[x][y] + papers[x][y + 1] + papers[x][y + 2] + papers[x + 1][y + 2]

        ret = max(sum, ret)
    }

    if (x - 2 >= 0 && y + 1 < m) {
        val sum = papers[x][y] + papers[x - 1][y] + papers[x - 2][y] + papers[x - 2][y + 1]

        ret = max(sum, ret)
    }

    if (x - 1 >= 0 && y - 2 >= 0) {
        val sum = papers[x][y] + papers[x][y - 1] + papers[x][y - 2] + papers[x - 1][y - 2]

        ret = max(sum, ret)
    }

    return ret
}

fun ter4(x: Int, y: Int): Int {
    var ret = 0

    if (x + 2 < n && y + 1 < m) {
        val sum = papers[x][y] + papers[x + 1][y] + papers[x + 1][y + 1] + papers[x + 2][y + 1]

        ret = max(sum, ret)
    }

    if (x - 1 >= 0 && y + 2 < m) {
        val sum = papers[x][y] + papers[x][y + 1] + papers[x - 1][y + 1] + papers[x - 1][y + 2]
        
        ret = max(sum, ret)
    }

    if (x - 2 >= 0 && y - 1 >= 0) {
        val sum = papers[x][y] + papers[x - 1][y] + papers[x - 1][y - 1] + papers[x - 2][y - 1]

        ret = max(sum, ret)
    }

    if (x + 1 < n && y - 2 >= 0) {
        val sum = papers[x][y] + papers[x][y - 1] + papers[x + 1][y - 1] + papers[x + 1][y - 2]
        
        ret = max(sum, ret)
    }

    if (x + 2 < n && y - 1 >= 0) {
        val sum = papers[x][y] + papers[x + 1][y] + papers[x + 1][y - 1] + papers[x + 2][y - 1]

        ret = max(sum, ret)
    }

    if (x + 1 < n && y + 2 < m) {
        val sum = papers[x][y] + papers[x][y + 1] + papers[x + 1][y + 1] + papers[x + 1][y + 2]
        
        ret = max(sum, ret)
    }

    if (x - 2 >= 0 && y + 1 < m) {
        val sum = papers[x][y] + papers[x - 1][y] + papers[x - 1][y + 1] + papers[x - 2][y + 1]

        ret = max(sum, ret)
    }

    if (x - 1 >= 0 && y - 2 >= 0) {
        val sum = papers[x][y] + papers[x][y - 1] + papers[x - 1][y - 1] + papers[x - 1][y - 2]
        
        ret = max(sum, ret)
    }

    
    return ret
}

fun ter5(x: Int, y: Int): Int {
    var ret = 0

    if (x + 1 < n && y - 1 >= 0 && y + 1 < m) {
        val sum = papers[x][y] + papers[x + 1][y - 1] + papers[x + 1][y] + papers[x + 1][y + 1]

        ret = max(ret, sum)
    }

    if (x - 1 >= 0 && x + 1 < n && y + 1 < m) {
        val sum = papers[x][y] + papers[x - 1][y + 1] + papers[x][y + 1] + papers[x + 1][y + 1]

        ret = max(ret, sum)
    }

    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < m) {
        val sum = papers[x][y] + papers[x - 1][y - 1] + papers[x - 1][y] + papers[x - 1][y + 1]

        ret = max(ret, sum)
    }

    if (x - 1 >= 0 && x + 1 < n && y - 1 >= 0) {
        val sum = papers[x][y] + papers[x - 1][y - 1] + papers[x][y - 1] + papers[x + 1][y - 1]

        ret = max(ret, sum)
    }

    return ret
}


fun main() {
    val input = readln().split(" ").map { it.toInt() }
    n = input[0]
    m = input[1]

    papers = Array(n) { readln().split(" ").map { it.toInt() } }
    
    var maxValue = 0
    for (i in 0 until n) {
        for (j in 0 until m) {
            maxValue = max(maxValue, ter1(i, j))
            maxValue = max(maxValue, ter2(i, j))
            maxValue = max(maxValue, ter3(i, j))
            maxValue = max(maxValue, ter4(i, j))
            maxValue = max(maxValue, ter5(i, j))
        }
    }

    print(maxValue)
}