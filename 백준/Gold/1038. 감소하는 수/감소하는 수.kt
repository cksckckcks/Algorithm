val ans = mutableListOf<Long>()

fun main() {
    val n = readln().toInt()

    for (i in 0L..9L) {
        dfs(i)
    }

    ans.sort()

    println(if (ans.size <= n) -1 else ans[n])
}

fun dfs(n: Long) {
    ans.add(n)
    
    for (i in 0..9) {
        if (n % 10 > i) {
            val num = n * 10 + i

            dfs(num)
        }
    }
}


// 0 1 2 3 4 5 6 7 8 9
// 10 20 21 30 31 32 40 41 42 43
// 50 51 52 53 54 60 