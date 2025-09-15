import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

val br = BufferedReader(InputStreamReader(System.`in`))
lateinit var arr: IntArray
lateinit var minTree: IntArray
lateinit var maxTree: IntArray

fun main() {
    val(n, m) = br.readLine().split(" ").map { it.toInt() }

    arr = IntArray(n)
    repeat(n) { i ->
        val input = br.readLine().toInt()

        arr[i] = input
    }

    minTree = IntArray(n * 4 + 1)
    maxTree = IntArray(n * 4 + 1)

    init(0, n - 1, 0)

    repeat(m) {
        val (a, b) = br.readLine().split(" ").map{ it.toInt() }

        val result = getMinMax(0, 0, n - 1, a - 1, b - 1)
        println("${result.first} ${result.second}")
    }
}

fun init(start: Int, end: Int, node: Int) {
    if (start == end) {
        minTree[node] = arr[start]
        maxTree[node] = arr[start]
        
        return
    }

    val mid = (start + end) / 2
    
    init(start, mid, node * 2 + 1)
    init(mid + 1, end, node * 2 + 2)

    minTree[node] = min(minTree[node * 2 + 1], minTree[node * 2 + 2])
    maxTree[node] = max(maxTree[node * 2 + 1], maxTree[node * 2 + 2])

    return
}


fun getMinMax(node: Int, start: Int, end: Int, left: Int, right: Int): Pair<Int, Int> {
    if (left > end || right < start)
        return Pair(Int.MAX_VALUE, Int.MIN_VALUE)
    else if (left <= start && end <= right)
        return Pair(minTree[node], maxTree[node])
    else {
        val mid = (start + end) / 2

        val leftValue = getMinMax(node * 2 + 1, start, mid, left, right)
        val rightValue = getMinMax(node * 2 + 2, mid + 1, end, left, right)

        return Pair(min(leftValue.first, rightValue.first), max(leftValue.second, rightValue.second))
    }
    

}