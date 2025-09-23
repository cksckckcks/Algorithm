class Solution {
    fun solution(stones: IntArray, k: Int): Int {
        var answer = 0
        
        var left = 1
        var right = 200000000
        
        while (left <= right) {
            val mid = (left + right) / 2
                
            if (checkStones(stones, k, mid)) {
                answer = mid
                left = mid + 1
            }
            else
                right = mid - 1
        }
        
        return answer
    }
    
    fun checkStones(stones: IntArray, k: Int, n: Int): Boolean {
        var cnt = 0
        
        for (stone in stones) {
            if (stone < n) 
                cnt++
            else
                cnt = 0
            
            if (cnt >= k)
                return false
        }
        
        return true
    }
}
