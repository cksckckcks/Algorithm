fun main() {
    val (h, w) = readln().split(" ").map { it.toInt() }
    val blockHeights = readln().split(" ").map { it.toInt() }
    val tiles = Array(h) { Array(w) { 0 } }

    for (i in 0 until w) {
        for (j in 0 until blockHeights[i]) {
            tiles[j][i] = 1
        }
    }

    var ans = 0
    for (i in 0 until h) {
        var cnt = 0
        var isBlock = false
        for (j in 0 until w) {
            if (isBlock && tiles[i][j] == 0) {
                cnt++
            } else if (isBlock && tiles[i][j] == 1) {
                ans += cnt
                cnt = 0
            } else if (tiles[i][j] == 1) {
                isBlock = true
            }
        }        
    }

    print(ans)
}