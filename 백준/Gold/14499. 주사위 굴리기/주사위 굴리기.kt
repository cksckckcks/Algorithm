val dx = listOf(0, 0, -1, 1)
val dy = listOf(1, -1, 0, 0)

val dice = arrayOf(0, 0, 0, 0, 0, 0)

const val top = 0
const val left = 1
const val now = 2
const val right = 3
const val bot = 4
const val back = 5

fun swap(x: Int, y: Int) {
    val tmp = dice[x]
    dice[x] = dice[y]
    dice[y] = tmp
}

fun rotationDice(n: Int, tileNumber: Int): Int {
    when (n) {
        1 -> { // 오른쪽으로 돌림
            swap(left, right)
            swap(right, now)
            swap(back, left)
        }
        2 -> { // 왼쪽으로 돌림
            swap(left, right)
            swap(left, now)
            swap(back, right)
        }
        3 -> { // 위로 돌림
            swap(top, back)
            swap(now, top)
            swap(now, bot)
        }
        4 -> { // 아래로 돌림
            swap(top, back)
            swap(bot, back)
            swap(now, bot)
        }
    }

    if (tileNumber != 0) {
        dice[back] = tileNumber

        return 0
    } else {
        return dice[back]
    }
}


fun main() {
    val (n, m, x, y, k) = readln().split(" ").map { it.toInt() }

    val tiles = Array(n) {
        readln().split(" ").map { it.toInt() }.toIntArray()
    }

    val commands = readln().split(" ").map { it.toInt() }

    var nowX = x
    var nowY = y
    commands.forEach {
        val xx = nowX + dx[it - 1]
        val yy = nowY + dy[it - 1]

        if ((xx < 0 || xx >= n || yy < 0 || yy >= m) == false) {
            tiles[xx][yy] = rotationDice(it, tiles[xx][yy])

            nowX = xx
            nowY = yy

            println(dice[now])
        }
    }
}