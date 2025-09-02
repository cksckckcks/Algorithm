var ans = 0

fun main() {
    val (N, M) = readln().split(" ").map{ it.toInt() }
    
    val books = readln().split(" ").map{ it.toInt() }

    val negBooks = books.filter { it < 0 }.map{ -it }.sortedDescending()
    val posBooks = books.filter { it > 0 }.sortedDescending()

    val isLast = negBooks.getOrNull(0) ?: -1 > posBooks.getOrNull(0) ?: -1

    addDist(negBooks, M, isLast)
    addDist(posBooks, M, !isLast)

    print(ans)
}

fun addDist(books: List<Int>, maxBooks: Int, isLast: Boolean) {
    for (i in 0 until books.size step(maxBooks)) {
        // println(books[i])
        ans += books[i] * 2
    }

    if (isLast)
        ans -= books[0]
} 
