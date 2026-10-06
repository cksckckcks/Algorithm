import kotlin.collections.ArrayDeque

class Solution {
    fun solution(n: Int, roads: Array<IntArray>, sources: IntArray, destination: Int): IntArray {
        var answer = mutableListOf<Int>()
        val roadList = Array(n + 1) { mutableListOf<Int>() }
        
        for (i in roads.indices) {
            val (a, b) = roads[i]
            
            roadList[a].add(b)
            roadList[b].add(a)
        }
        
        for (i in sources) {
            answer.add(bfs(roadList, i, destination, n))
        }
        
        return answer.toIntArray()
    }
    
    fun bfs(roadMap: Array<MutableList<Int>>, now: Int, dest: Int, n: Int): Int {
        val visited = Array(n + 1) { false }
        val q = ArrayDeque<Pair<Int, Int>>()
        q.add(Pair(now, 0))
        visited[now] = true
        
        while (q.isNotEmpty()) {
            val (num, cnt) = q.removeFirst()
            if (num == dest) { return cnt }
            
            
            for (i in roadMap[num]) {
                if (visited[i] == false) {
                    visited[i] = true  
                    q.add(Pair(i, cnt + 1))
                }
            }
        }
        
        return -1
    }
}