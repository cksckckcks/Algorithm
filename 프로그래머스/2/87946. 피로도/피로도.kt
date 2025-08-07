class Solution {
    lateinit var visited: BooleanArray
    var answer: Int = -1
    
    fun dfs (k: Int, dungeons: Array<IntArray>, cnt: Int = 0) {
        answer = if (answer < cnt) cnt else answer
        
        for (i in 0 until dungeons.size) {
            if (visited[i] || k < dungeons[i][0])
                continue
            
            visited[i] = true
            
            dfs(k - dungeons[i][1], dungeons, cnt + 1)
            
            visited[i] = false
        }
        
        return
    }
    
    fun solution(k: Int, dungeons: Array<IntArray>): Int {
        
        visited = BooleanArray(dungeons.size) { false }
        
        dfs(k, dungeons)
        
        
        return answer
    }
}