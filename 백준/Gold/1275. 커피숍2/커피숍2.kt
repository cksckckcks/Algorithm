lateinit var arr: LongArray
lateinit var tree: LongArray

fun main() {
    val (n, q) = readln().split(" ").map { it.toInt() }
    arr = readln().split(" ").map { it.toLong() }.toLongArray()
    tree = LongArray(n * 4 + 1)

    init(0, n - 1, 0)

    repeat(q) {
        val (x, y, a, b) = readln().split(" ").map{ it.toInt() }

        if (x < y)
            println(sum(0, n - 1, 0, x - 1, y - 1))
        else
            println(sum(0, n - 1, 0, y - 1, x - 1))

        val diff = b.toLong() - arr[a - 1]
        arr[a - 1] = b.toLong()
        update(0, n - 1, 0, a - 1, diff)   
    }
}

fun init(start: Int, end: Int, node: Int): Long {
    if (start == end) { // 리프 노드 arr 그대로 가져가기
        tree[node] = arr[start]
        
        return tree[node]
    }

    val mid = (start + end) / 2
    
    tree[node] = init(start, mid, node * 2 + 1) + init(mid + 1, end, node * 2 + 2)

    return tree[node]
}

fun sum(start: Int, end: Int, node: Int, left: Int, right: Int): Long {
    if (left > end || right < start) // 겹치지 않음 -> 사용 x
        return 0L
    if (left <= start && end <= right) // 완전 겹침 -> 전체 사용
        return tree[node]
    
    val mid = (start + end) / 2 // 일부 겹침 -> 재귀로 탐색
    
    return sum(start, mid, node * 2 + 1, left, right) + sum(mid + 1, end, node * 2 + 2, left, right)
}

fun update(start: Int, end: Int, node: Int, index: Int, diff: Long) {
    if (index < start || index > end)
        return
    
    // 구간이 맞다면 diff 값 반영
    tree[node] += diff

    if (start == end)
        return
    
    val mid = (start + end) / 2

    update(start, mid, node * 2 + 1, index, diff)
    update(mid + 1, end, node * 2 + 2, index, diff)
}