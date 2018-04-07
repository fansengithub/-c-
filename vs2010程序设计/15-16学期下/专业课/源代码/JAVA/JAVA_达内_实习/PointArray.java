package day5;
// 点数组类
public class PointArray {
	/////22 begin
	private POINT [] pts;
	private int size;
	public int getSize() {
		return size;
	}
	public PointArray() {
		//如果没传参
		this(5);//调用带参数的构造方法
	}
	public PointArray(int size) {
		this.size = size;
		pts = new POINT[size];
		for(int i = 0 ; i <size;i++){
			pts[i] = new POINT();
		}
	}
	
	// set(int index,int x,int y)  
	public void setPointArray(int index,int x,int y){
		if(index<0 || index>=size){
			System.out.println("index--"+index+"-----size"+size);
			System.err.printf("索引越界...！");
			return;
		}
		pts[index].setX(x);
		pts[index].setY(y);
	}
	public void getPontArray(int index){
		if(index<0 || index>=size){
			System.err.printf("索引越界！");
			return;
		}
		System.out.println("["+pts[index].getX()+","+pts[index].getY()+"]");
	}
	public  void display(){
		System.out.println("-------------");
		for(POINT  pt : pts){
			System.out.println("["+pt.getX()+","+pt.getY()+"]");
		}
		System.out.println("-------------");
	}
///////////////////2  end 
	
	///1  begin----------
	private class POINT{
		private int x;
		private int y;
		public POINT() {
			this(0,0);
		}
		public POINT(int x ,int y) {
			this.x = x;
			this.y = y;
		}
		public int getX() {
			return x;
		}
		public void setX(int x) {
			this.x = x;
		}
		public int getY() {
			return y;
		}
		public void setY(int y) {
			this.y = y;
		}
	}
///1  end 
}
