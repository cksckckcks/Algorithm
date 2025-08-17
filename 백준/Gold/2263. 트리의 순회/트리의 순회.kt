val N = readln().toInt()
val inorder = readln().split(" ").map{ it.toInt() }
val postorder = readln().split(" ").map{ it.toInt() }
val position = IntArray(N + 1)

    
fun main() {
   for (i in 0 until N)
        position[inorder[i]] = i 

    getPreorder(0, N - 1, 0, N - 1)
}

fun getPreorder(inoderStart: Int, inoderEnd: Int, postorderStart: Int, postorderEnd: Int) {
    if (inoderStart > inoderEnd && postorderStart > postorderEnd)
        return

    val parent = postorder[postorderEnd]
    val left = position[parent] - inoderStart
    val right = inoderEnd - position[parent]

    print("$parent ")

    getPreorder(inoderStart, inoderStart + left - 1, postorderStart, postorderStart + left - 1)
    getPreorder(inoderEnd - right + 1, inoderEnd, postorderEnd - right, postorderEnd - 1)
}