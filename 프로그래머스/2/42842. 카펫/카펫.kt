class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        var answer = intArrayOf(3, 3)
        
        val size = brown + yellow
        
        (3..size / 3).forEach {
            var width = size / it
            
            if ((width - 2) * (it - 2) == yellow)
                return intArrayOf(width, it)
        }
        
        return answer
    }
}