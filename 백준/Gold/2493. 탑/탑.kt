import java.util.Stack
 
fun main()
{
    val st = Stack<Pair<Int, Int>>()

    val N = readln().toInt()
    val top = readln().split(" ").map { it.toInt() }
 
    val ans = IntArray(N) { 0 }
    
    
    for (i in N - 1 downTo 1)
    {
        if (top[i] > top[i - 1]) {
            st.add(Pair(i, top[i]))
        }
        else {
            ans[i] = i

            while (st.isNotEmpty())
            {
                val t = st.peek()

                if (t.second < top[i - 1]) {
                    st.pop()
                    ans[t.first] = i
                }
                else
                    break
            }
        }
    }

    println(ans.joinToString(" "))
}