class Solution {
    fun solution(target: Int): IntArray {
        val dp = Array(target + 1) { Pair(Int.MAX_VALUE, Int.MAX_VALUE) }
        
        dp[0] = Pair(0, 0) 
        
        for(i in 1..target) {
            for(j in 1..20) {
                if(i < j) break
                
                val temp = dp[i-j].first + 1 to dp[i-j].second + 1
                dp[i] = max(temp, dp[i])
            }
            
            for (j in 22..40 step 2) {
                if(i < j) break
                
                val temp = dp[i-j].first + 1 to dp[i-j].second
                dp[i] = max(temp, dp[i])
            }
            
            for(j in 21..60 step 3) {
                if(i < j) break
                
                val temp = dp[i-j].first + 1 to dp[i-j].second
                dp[i] = max(temp, dp[i])
            }
            
            if(i >= 50) {
                val temp = dp[i-50].first + 1 to dp[i-50].second + 1
                dp[i] = max(temp, dp[i])
            }
            
        }
        
        return intArrayOf(dp[target].first, dp[target].second)
    }
    
    fun max(a: Pair<Int, Int>, b: Pair<Int, Int>) = when {
        a.first < b.first -> a
        a.first == b.first && a.second > b.second -> a
        else -> b
    }
}