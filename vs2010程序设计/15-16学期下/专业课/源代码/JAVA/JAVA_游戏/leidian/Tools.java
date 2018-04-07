package day10.leidian;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.Random;
import java.util.Vector;

public class Tools {
	int x;
	int y;
	int w;
	int h;
	String  str = "MFLS";
	Random  r = new Random();
	String   tools;
	int step =4;
	
	public Tools() {
		x  = r.nextInt(MyFrame.width-20);
		y = -20;
		w= h = 20;	
		tools = str.charAt(r.nextInt(str.length()))+"";
		
	}
	public void paint(Graphics  g){
		g.setColor(Color.red);
		g.fillRect(x, y, w, h);
		g.setColor(Color.WHITE);
		
		g.drawString(tools, x+4, y+13);
		g.drawString(tools, x+5, y+14);
		
	}
	public void move(Vector<Tools> tools){
		y+=step;
		if(y>MyFrame.height){
			tools.remove(this);
		}
	}
}
