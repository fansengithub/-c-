package day5;

public class test {
	public static void main(String[] args) {
		PointArray  pa = new PointArray(5);
		pa.setPointArray(0, 1, 5);
		pa.setPointArray(1, 2, 6);
		pa.setPointArray(2, 3, 7);
		pa.setPointArray(3, 4, 8);
		pa.setPointArray(4, 5, 9);
		pa.display();
		
		pa.getPontArray(3);
		
		
	}
}
