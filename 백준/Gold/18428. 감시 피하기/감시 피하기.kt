import kotlin.system.exitProcess

var N = 0
lateinit var map: Array<Array<String>>

fun main() {
    N = readln().toInt()

    map = Array(N) { readln().split(" ").toTypedArray() }

    dfs()

    print("NO")
}

fun check(): Boolean {
    for (i in 0 until N) {
        for (j in 0 until N) {
            if (map[i][j] == "S") {
                if (!checkStudent(i, j))
                    return false
            }
        }
    }

    return true
}

fun checkStudent(x: Int, y: Int): Boolean {
    for (i in x - 1 downTo 0) {
        if (map[i][y] == "O")
            break
        
        if (map[i][y] == "T")
            return false
    }

    for (i in x + 1 until N) {
        if (map[i][y] == "O")
            break
        
        if (map[i][y] == "T")
            return false
    }

    for (i in y - 1 downTo 0) {
        if (map[x][i] == "O")
            break
        
        if (map[x][i] == "T")
            return false
    }

    for (i in y + 1 until N) {
        if (map[x][i] == "O")
            break
        
        if (map[x][i] == "T")
            return false
    }

    return true
}

fun dfs(x: Int = 0, y: Int = 0, cnt: Int = 0) {
    if (cnt == 3) {
        if (check()) {
            print("YES")
            exitProcess(0)
        }

        return
    }

    for (i in x until N) {
        for (j in (if(i == x) y else 0) until N) {
            if (map[i][j] == "X") {
                map[i][j] = "O"

                dfs(i, j + 1, cnt + 1)

                map[i][j] = "X"
            }
        }
    }
}