import kotlin.system.exitProcess

var sudoku = Array(0) { IntArray(0) }

fun check(x: Int, y: Int, n: Int): Boolean {
    // sudoku[x].forEach {
    //     if (it == n)
    //         return false
    // }

    if (sudoku[x].any { it == n }) return false

    for (i in 0 until 9)
        if (sudoku[i][y] == n)
            return false

    val xx = when(x) {
        in 0..2 -> 0
        in 3..5 -> 3
        else -> 6
    }

    val yy = when(y) {
        in 0..2 -> 0
        in 3..5 -> 3
        else -> 6
    }

    for (i in xx until xx + 3)
        for (j in yy until yy + 3)
            if (sudoku[i][j] == n)
                return false

    return true
}

fun dfs(x: Int, y: Int) {
    if (x == 9) {
        sudoku.forEach {
            it.forEach {
                print("$it ")
            }
            println()
        }
        exitProcess(0)
    }

    if (y == 9) {
        dfs(x + 1, 0)

        return
    }



    if (sudoku[x][y] == 0) {
        for (i in 1 until 10) {
            if (check(x, y, i)) {
                sudoku[x][y] = i

                dfs(x, y + 1)
                
                sudoku[x][y] = 0
            }
        }
    }
    else
        dfs(x, y + 1)
}

fun main() {
    sudoku = Array(9) { readLine()!!.split(" ").map { it.toInt() }.toIntArray() }

    dfs(0, 0)
}