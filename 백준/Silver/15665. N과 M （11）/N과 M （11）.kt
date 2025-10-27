var N = 0
var M = 0
lateinit var numbers: List<Int>
var list = mutableListOf<Int>()

fun main() {
    val input = readln().split(" ").map{ it.toInt() }
    
    N = input[0]
    M = input[1]

    numbers = readln().split(" ")
        .map{ it.toInt() }
        .sorted()
        .distinct()

    dfs()
}

fun dfs(n: Int = 0) {
    if (n == M) {
        println(list.joinToString(" "))
        
        return
    }

    for (i in 0 until numbers.size) {
        list.add(numbers[i])
        dfs(n + 1)
        list.removeAt(list.size - 1)
    }
}