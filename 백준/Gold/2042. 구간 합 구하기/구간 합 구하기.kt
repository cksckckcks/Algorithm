import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))
lateinit var arr: LongArray
lateinit var tree: LongArray

fun main() {
    val(n, m, k) = br.readLine().split(" ").map { it.toInt() }

    arr = LongArray(n)
    repeat(n) { i ->
        val input = br.readLine().toLong()

        arr[i] = input
    }
    tree = LongArray(n * 4 + 1)

    init(0, n - 1, 0)

    repeat(m + k) {
        val (type, a, b) = br.readLine().split(" ").map{ it.toLong() }

        if (type == 1L) {
            val aa = a.toInt()

            val diff = b.toLong() - arr[aa - 1]

            arr[aa - 1] = b.toLong()
            update(0, n - 1, 0, aa - 1, diff)   
        }
        else {
            val aa = a.toInt()
            val bb = b.toInt()

            println(sum(0, n - 1, 0, aa - 1, bb - 1))
        }


        
    }
}

fun init(start: Int, end: Int, node: Int): Long {
    if (start == end) {
        tree[node] = arr[start]
        
        return tree[node]
    }

    val mid = (start + end) / 2
    
    tree[node] = init(start, mid, node * 2 + 1) + init(mid + 1, end, node * 2 + 2)

    return tree[node]
}

fun sum(start: Int, end: Int, node: Int, left: Int, right: Int): Long {
    if (left > end || right < start)
        return 0L
    if (left <= start && end <= right)
        return tree[node]
    
    val mid = (start + end) / 2
    
    return sum(start, mid, node * 2 + 1, left, right) + sum(mid + 1, end, node * 2 + 2, left, right)
}

fun update(start: Int, end: Int, node: Int, index: Int, diff: Long) {
    if (index < start || index > end)
        return
    
    tree[node] += diff

    if (start == end)
        return
    
    val mid = (start + end) / 2

    update(start, mid, node * 2 + 1, index, diff)
    update(mid + 1, end, node * 2 + 2, index, diff)
}