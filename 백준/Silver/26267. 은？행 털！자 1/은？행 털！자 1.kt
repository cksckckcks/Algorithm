import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))

fun main() {
    val n = br.readLine().toInt()
    val dic = mutableMapOf<Int, Long>()

    repeat(n) {
        val (x, t, c) = br.readLine().split(" ").map { it.toInt() }

        val key = t - x

        dic[key] = dic.getOrDefault(key, 0L) + c
    }

    print(dic.values.max())
}