val checkArr = List(101) { mutableListOf<Int>() }
val multiTap = mutableListOf<Int>()
var ans = 0



fun main() {
    val (N, M) = readln().split(" ").map { it.toInt() }
    val arr = readln().split(" ").map { it.toInt() }
    

    arr.forEachIndexed { idx, n ->
        checkArr[n].add(idx)
    }

    arr.forEach {
        checkArr[it].removeAt(0)

        if (multiTap.contains(it))
            return@forEach

        
        if (multiTap.size >= N)
            checkMultiTap(it)
        else 
            multiTap.add(it)

        // println(multiTap)
    }

    print(ans)
}

fun checkMultiTap(newItem: Int) {
    var tmpN = -1
    var tmpIdx = -1


    for (i in 0 until multiTap.size) {
        val n = multiTap[i] // 지금 꼽혀있는 멀티탭 번호 중 하나
        
        if (checkArr[n].isEmpty()) {
            // println(n.toString() + "empty!!!")
            tmpN = n
            tmpIdx = i

            break
        }

        if (checkArr[n].get(0) > if (tmpN ==- 1) -1 else checkArr[tmpN].get(0)) {
            tmpN = n
            tmpIdx = i
        }
    }

    // checkArr[n].removeAt(0)
    // println("remove " + tmpN.toString())
    multiTap.remove(tmpN)
    multiTap.add(newItem)

    ans++
}


// 1 4 3 2 // 5 4 3 // 2 5 3 // 4 2 3 4
// 1 4 3 -> 4 3 2 -> 5 4 3 -> 2 5 3 -> 4 2 3