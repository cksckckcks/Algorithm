import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))

var n = 0

lateinit var child: Array<MutableList<Int>>
lateinit var animalType: CharArray
lateinit var animalCount: LongArray
lateinit var tree: LongArray

fun dfs(node: Int): Long {
    if (node != 1 && tree[node] != -1L)
        return tree[node]
    
    var total = 0L
    
    for (it in child[node])
        total += dfs(it)
    
    tree[node] = when (animalType[node]) {
        'S' -> total + animalCount[node]
        'W' -> maxOf(0L, total - animalCount[node])
        'R' -> total // 1번 노드 전용
        else -> 0L
    }
    
    return tree[node]
}

fun main() {
    n = br.readLine().toInt()
    
    child = Array(n + 1) { mutableListOf<Int>() }
    animalType = CharArray(n + 1)
    animalCount = LongArray(n + 1)
    tree = LongArray(n + 1) { -1L }
    
    tree[1] = 0L
    animalType[1] = 'R'
    
    for (i in 2..n) {
        val input = br.readLine().split(" ")
        
        animalType[i] = input[0][0]
        animalCount[i] = input[1].toLong()
        child[input[2].toInt()].add(i)
    }
    
    print(dfs(1))
}