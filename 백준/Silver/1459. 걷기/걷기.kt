import kotlin.math.*


fun main() {
    val (x, y, w, s) = readln().split(" ").map { it.toLong() }

    val moveStraight = (x + y) * w

    val moveDiagonal = if ((x + y) % 2L == 0L) max(x, y) * s else (max(x, y) - 1) * s + w

    val moveMiexed = (min(x, y) * s) + (abs(x - y) * w)
    
    print(minOf(moveDiagonal, moveMiexed, moveStraight))
}