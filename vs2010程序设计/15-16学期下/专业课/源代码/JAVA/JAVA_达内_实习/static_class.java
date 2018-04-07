package day5;

public class static_class {
	public static void main(String[] args) {
		CA.CB   cab = new CA.CB();
		cab.Hello();
	}
}



class  CA{
	public int a;
	public static int b;
	public void hello(){
		System.out.println("ÆÕÍ¨µÄHello");
	}
	public static void hello2(){
		System.out.println("¾²Ì¬µÄHello");
	}
	public static class CB{
		public void Hello(){
//			a = 100;
			b = 100;
			hello2();
			System.out.println("CB  hello");
		}
	}
}