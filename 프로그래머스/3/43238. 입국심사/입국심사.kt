class Solution {
    fun solution(n: Int, times: IntArray): Long {
        var answer: Long = 0
        
        var left: Long = 0
        var right: Long = times.max().toLong() * n.toLong()
        
        while(left <= right) {
            var mid: Long = (left + right) / 2
            
            if (check(n, times, mid)) {
                answer = mid
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        
        return answer
    }
    
    fun check(n: Int, times: IntArray, time: Long): Boolean {
        val count = times.sumOf { time / it }
        
        return n <= count
    }
}