import java.io.*;
import java.util.StringTokenizer;

public class F {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w = new PrintWriter(System.out);
		StringTokenizer s = new StringTokenizer(r.readLine());
		int n = Integer.parseInt(s.nextToken());
		int q = Integer.parseInt(s.nextToken());

		w.close();
	}
	
	public static class SegmentTree {
		private final Segment[] tree;
		private final int len;
		
		public SegmentTree(int len) {
			this.len = len;
			tree = new Segment[len * 2];
		}
		
		public void recalculate(int node) {
			tree[node] = 
		
		
		private static class Segment {
			
		}
	}
}
		
