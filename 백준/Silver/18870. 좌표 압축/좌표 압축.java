import java.io.*;
import java.util.HashMap;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        TreeSet<Integer> ts = new TreeSet<Integer>();
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();

        int N = Integer.parseInt(bf.readLine());
        int[] arr = new int[N];

        String input = bf.readLine();
        StringTokenizer st = new StringTokenizer(input, " ");

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            ts.add(arr[i]);
        }

        Iterator it = ts.iterator();
        for (int i = 0; it.hasNext(); i++)
            hm.put((Integer)it.next(), i);

        for (int i = 0; i < N; i++)
            bw.write(hm.get(arr[i]) + " ");

        bf.close();
        bw.flush();
        bw.close();
    }
}