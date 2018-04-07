package day10.leidian;



import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Vector;

import javax.imageio.ImageIO;

public class Bullet {
	int x;
	int y;
	int w;
	int h;
	int xStep=0;
	BufferedImage  img;
	public Bullet() {
		x = -10;
		y = -10;
		try {
			img = ImageIO.read(getClass().getResource("/imgs/bullet.png"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		w = 6;
		h = 17;
	}
	public void paint(Graphics g){
		
		g.drawImage(img, x, y, null);
	}
	// 
	public void move(Vector<Bullet>  bullets,Vector<Npc>  npcs){
		y-=10;
		x+=xStep;
		// 越界删除
		if(y<-100){
			bullets.remove(this);
		}
		// 敌机碰撞检测
		for(int i = 0;i<npcs.size();i++){
			int x1 = npcs.get(i).x;
			int y1 = npcs.get(i).y;
			int w1 = npcs.get(i).w;
			int h1 = npcs.get(i).h;
			if(x> x1-w && x <x1+w1){
				if(y>y1-h && y < y1+h1){
					//通知敌机被击中
					npcs.get(i).hit = true;
					// 是否直接移除子弹
					bullets.remove(this);
				}
			}
		}
	}
}
