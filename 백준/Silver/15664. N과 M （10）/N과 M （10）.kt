var N = 0
var M = 0

val ans: MutableSet<List<Int>> = mutableSetOf()

lateinit var arr: List<Int>
lateinit var pickArray: IntArray
val visited = BooleanArray(8)


fun main() {
    val input = readln().split(" ").map{ it.toInt() }
    
    N = input[0]
    M = input[1]

    arr = readln().split(" ").map{ it.toInt() }.sorted()

    pickArray = IntArray(M)

    dfs(0)

    for (list in ans)
        println(list.joinToString(" "))
}

fun dfs(cnt: Int) {
    if (cnt == M) {
        ans.add(pickArray.toList().sorted())
        
        return
    }

    for (i in 0 until N) {
        if (visited[i])
            continue

        pickArray[cnt] = arr[i]
        visited[i] = true

        dfs(cnt + 1)

        visited[i] = false
    }
}