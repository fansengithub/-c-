package day10.leidian;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;

public class MyFrame extends JFrame {
	//³£Á¿
	static int width = 320;
	static int height= 480;
	MyPanel  mp = new MyPanel();
	public MyFrame() {
		// TODO Auto-generated constructor stub
		this.setSize(width, height);
		this.setTitle("À×µç");
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setResizable(false);
		this.add(mp);
		this.setVisible(true);
		Thread  t = new Thread(mp);
		t.start();
		this.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				if(mp.plane.remove){
					int x = e.getX();
					int y = e.getY();
					if(x>55 && x <250 && y>232 && y <268){
						mp.init();
					}
				}
			}
		});
		this.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				switch(e.getKeyCode()){
				case KeyEvent.VK_LEFT:
				case KeyEvent.VK_A:
					mp.plane.left = true;
				
					break;
				case KeyEvent.VK_W:
				case KeyEvent.VK_UP:
					mp.plane.up = true;
					break;
				case KeyEvent.VK_RIGHT:
				case KeyEvent.VK_D:
					mp.plane.right = true;
					break;
				case KeyEvent.VK_DOWN:
				case KeyEvent.VK_S:
					mp.plane.down = true;
					break;
				case KeyEvent.VK_CONTROL:
				case KeyEvent.VK_J:
					mp.isCreate = true;
					break;
				case KeyEvent.VK_ESCAPE:
					mp.clear();
					break;
				}
			}
			@Override
			public void keyReleased(KeyEvent e) {
				// TODO Auto-generated method stub
				switch(e.getKeyCode()){
				case KeyEvent.VK_LEFT:
				case KeyEvent.VK_A:
					mp.plane.left = false;
					break;
				case KeyEvent.VK_UP:
				case KeyEvent.VK_W:
					mp.plane.up = false;
					break;
				case KeyEvent.VK_RIGHT:
				case KeyEvent.VK_D:
					mp.plane.right = false;
					break;
				case KeyEvent.VK_DOWN:
				case KeyEvent.VK_S:
					mp.plane.down = false;
					break;
				case KeyEvent.VK_CONTROL:
				case KeyEvent.VK_J:
					mp.isCreate = false;
					break;
				}
			}
		});
	}
}
