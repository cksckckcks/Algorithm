import kotlin.math.abs

var ansValue = Long.MAX_VALUE
var ansList: List<Long> = emptyList()

fun main() {
    val N = readln().toInt()
    val solutionList = readln().split(" ").map { it.toLong() }.sorted()

    solutionList.forEachIndexed { idx, solution ->
        var left = idx + 1
        var right = solutionList.size - 1

        while (left < right) {
            val tmp: Long = solutionList[idx] + solutionList[left] + solutionList[right]

            if (abs(ansValue) > abs(tmp)) {
                ansValue = abs(tmp)
                ansList = listOf(solutionList[idx], solutionList[left], solutionList[right]).sorted()
            }

            if (tmp > 0)
                right--
            else
                left++
        }
    }

    ansList.map { print("$it ") }
}