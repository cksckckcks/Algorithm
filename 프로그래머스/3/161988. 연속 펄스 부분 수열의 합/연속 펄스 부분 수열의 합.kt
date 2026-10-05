import kotlin.math.max

class Solution {
    fun solution(sequence: IntArray): Long {
        var answer: Long = 0
        
        val s1 = Array(sequence.size) { 0L }
        val s2 = Array(sequence.size) { 0L }
        
        for (i in sequence.indices) {
            val num = if (i % 2 == 0) 1L else -1L
            s1[i] = sequence[i].toLong() * num
            s2[i] = sequence[i].toLong() * num * -1
        }
        
        val dp1 = Array(sequence.size) { 0L }
        val dp2 = Array(sequence.size) { 0L }
        dp1[0] = s1[0]
        dp2[0] = s2[0]
        
        for (i in 1 until sequence.size) {
            dp1[i] = max(dp1[i - 1] + s1[i], s1[i])
            dp2[i] = max(dp2[i - 1] + s2[i], s2[i])
        }
        
        answer = max(dp1.max(), dp2.max())
    
        return answer
    }
}