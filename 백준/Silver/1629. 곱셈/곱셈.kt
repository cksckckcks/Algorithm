import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
 
 
 
val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

fun pow(a: Long, b: Long, c: Long): Long{
    if (b == 1L)
        return a % c

    var powValue = pow(a, b / 2, c)

    if (b % 2 == 1L)
        return powValue * powValue % c * a % c
    else
        return powValue * powValue % c

}

fun main() {
    var (a, b, c) = br.readLine()!!.split(" ").map{it.toLong()}

    var ans = pow(a, b, c)

    bw.write("$ans")

    br.close()
    bw.flush()
    bw.close()
}