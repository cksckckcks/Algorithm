class Solution {
    fun solution(want: Array<String>, number: IntArray, discount: Array<String>): Int {
        val wantMap = want.zip(number.toTypedArray()).toMap() // zip -> Array<T>를 묶는다. 따라서 toTypedArray()를 해줘야 Map으로 묶을 수 있다.
        var answer = 0

        for (i in 0 .. discount.size - 10){
            val sliceItem = discount.slice(i until i + 10).groupingBy { it }.eachCount()
            
            if (wantMap.all { (key, value) -> (sliceItem[key] ?: 0) >= value })
                answer++
        }
        return answer
    }
}