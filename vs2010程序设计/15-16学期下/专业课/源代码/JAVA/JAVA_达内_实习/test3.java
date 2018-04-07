package day5;

import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JFrame;

public class test3 {
//	int a = 10;
//	JFrame  j = new JFrame();
//	public test3() {
//		j.addMouseListener(new MouseAdapter() {
//			@Override
//			public void mouseClicked(MouseEvent e) {
//				// TODO Auto-generated method stub
//				j.setTitle("asd");
//				System.out.println(a);
//			}
//		});
//	}
	public static void Kill(Animal  a ){
		a.Say();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//pig   dog
		
		
		Kill(new  Animal(){
			@Override
			public void Say() {
				// TODO Auto-generated method stub
				
			}
		});
		
		
	}

}

interface Animal{
	public int a = 10;
	// 接口中定义的变量都是static
	//接口中的数据成员都是final类型的常量
	
	public  void Say();
}
class Dog implements Animal{
	@Override
	public void Say() {
		// TODO Auto-generated method stub
		
	}
}