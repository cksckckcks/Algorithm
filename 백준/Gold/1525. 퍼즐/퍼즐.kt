import java.util.Queue
import java.util.LinkedList

fun main() {
    val input = Array(3) { readln().split(" ").joinToString("") }.joinToString("")

    val dx = arrayOf(0, 1, 0, -1)
    val dy = arrayOf(1, 0, -1, 0)

    val q: Queue<Pair<String, Int>> = LinkedList()
    val visitedSet = mutableSetOf<String>()
    var ans = -1

    q.add(Pair(input, 0))

    while (q.isNotEmpty()) {
        val top = q.poll()

        val str = top.first
        val cnt = top.second
        val zeroIdx = str.indexOf('0')
        
        // println(str)        

        if (str == "123456780") {
            ans = cnt
            break
        }

        visitedSet.add(str)

        val x = zeroIdx / 3
        val y = zeroIdx % 3

        for (i in 0 until 4) {
            val xx = x + dx[i]
            val yy = y + dy[i]

            if (xx !in 0..2 || yy !in 0..2)
                continue

            val tmpArray = str.toCharArray()
            
            val tmp = tmpArray[zeroIdx]
            tmpArray[zeroIdx] = tmpArray[xx * 3 + yy]
            tmpArray[xx * 3 + yy] = tmp 

            val newStr = String(tmpArray)  


            if (visitedSet.contains(newStr))
                continue

            q.add(Pair(newStr, cnt + 1))
        }
    }

    print(ans)
}