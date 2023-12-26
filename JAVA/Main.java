import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.*;
/**
 * 
 * @author TCchen 
 */
public class Main {
	public static void main(String[]args) throws IOException {
		new Main().run();
	}
	File input=new File("input.txt");
	File output=new File("output.txt");
	void run() throws IOException{
		boolean debug=false;
//		debug=true;
		if(debug)new Solve().setIO(input, output).run();
		else new Solve().setIO(System.in,System.out).run();
	}
	class Solve extends ioTask{
		int n,m,k,i,j,len,l,r,x,y;
		void solve()throws IOException{
			char[]s=in.ins().toCharArray();
			ss:for(i=1000;i<=10000;i++) {
				int x=i,y=0;
				while(y<18) {
					if(s[x]!=s[y]) continue ss;
					x++;
					y++;
				}
				out.println("No");
				return;
			}
			out.println("Yes");
		}
		int te;
		void run()throws IOException{
			int t=1;
//			t=in.in();
			for(te=1;te<=t;te++) {
				solve();
//				out.flush();
			}
			out.close();
		}
//		long timeMillis;
//		void st() {
//			timeMillis=System.currentTimeMillis();
//		}
//		void ed() {
//			System.out.println((System.currentTimeMillis()-timeMillis)+"ms");
//		}
	}
	class QIn{
		public QIn(InputStream is) {
			st = new StreamTokenizer(new BufferedReader(new InputStreamReader(is)));
		}
		StreamTokenizer st;
		int in() throws IOException {
			st.nextToken();
			return (int)st.nval;
		}
		long inl() throws IOException {
			st.nextToken();
			return (long)st.nval;
		}
		double ind()throws IOException  {
			st.nextToken();
			return st.nval;
		}
		String ins() throws IOException {
			st.nextToken();
			return st.sval;
		}
	}
	class In{
		private StringTokenizer in=new StringTokenizer("");
		private InputStream is;
		private BufferedReader br;
		public In(File file) throws IOException {
			is=new FileInputStream(file);
			init();
		}
		public In(InputStream is) throws IOException{
			this.is=is;
			init();
		}
		private void init() throws IOException {
			br=new BufferedReader(new InputStreamReader(is));
		}
		/**
		 * File and OJ only
		 */
		boolean hasNext() throws IOException {
			return in.hasMoreTokens()||br.ready();
		}
		String ins() throws IOException {
			while(!in.hasMoreTokens()) {
				in=new StringTokenizer(br.readLine());
			}
			return in.nextToken();
		}
		int in() throws IOException {
			return Integer.parseInt(ins());
		}
		long inl() throws IOException {
			return Long.parseLong(ins());
		}
		double ind() throws IOException {
			return Double.parseDouble(ins());
		}
		String line() throws IOException {
			return br.readLine();
		}
	}
	class Out{
		PrintWriter out;
		private OutputStream os;
		private void init() {
			out=new PrintWriter(new BufferedWriter(new OutputStreamWriter(os)));
		}
		public Out(File file) throws IOException {
			os=new FileOutputStream(file);
			init();
		}
		public Out(OutputStream os) throws IOException{
			this.os=os;
			init();
		}
	}
	abstract class ioTask{
		In in;
		PrintWriter out;
		public ioTask setIO(File in,File out) throws IOException{
			this.in=new In(in);
			this.out=new Out(out).out;
			return this;
		}
		public ioTask setIO(File in,OutputStream out) throws IOException{
			this.in=new In(in);
			this.out=new Out(out).out;
			return this;
		}
		public ioTask setIO(InputStream in,OutputStream out) throws IOException{
			this.in=new In(in);
			this.out=new Out(out).out;
			return this;
		}
		public ioTask setIO(InputStream in,File out) throws IOException{
			this.in=new In(in);
			this.out=new Out(out).out;
			return this;
		}
		void run()throws IOException{}
	}
}