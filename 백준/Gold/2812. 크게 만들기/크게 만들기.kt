import java.util.Stack

fun main() {
    val (n, k) = readln().split(" ").map { it.toInt() }
    val num = readln()
    var cnt = 0
    // var ans = ""
    val st = Stack<Char>()

    for (i in 0 until n) {
        while (st.isNotEmpty()) {
            if (st.peek() >= num[i])
                break
            else if (cnt < k) {
                st.pop()
                cnt++
            }
            else
                break
        }

        // if (cnt == k)
        //     ans = st.joinToString("") + num.substring(i)

        st.push(num[i])
    }

    while (cnt < k) {
        st.pop()
        cnt++
    }

    print(st.joinToString(""))
}