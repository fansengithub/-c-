package day10.leidian;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Vector;

public class NpcBullet {
	int x;
	int y;
	int w;
	int h;
	int step=4;
	double sin;
	double cos;
	String  style;// 子弹样式
	boolean  isBoss;///判断是否是boss
	int xBoss;//boss子弹的x位置
	public NpcBullet(Npc  npc,int x2,int y2) {
		// TODO Auto-generated constructor stub
		style = "*";
		x = npc.x+npc.w/2;
		y = npc.y+npc.h;
		System.out.println("Npcx:"+npc.x+"npxy:"+npc.y);
		
		w = h = 5;
		int x1 = x2;
		int y1 = y2;
		int dx = x1-x;
		int dy = y1-y;
		
		double dline = Math.sqrt(dx*dx+dy*dy);
		cos = dx/dline;
		sin = dy/dline;
	}
	public NpcBullet(int x,int y,int x2,int y2,boolean b) {
		// TODO Auto-generated constructor stub
		isBoss = true;
		style = "●";
		step = 6;
		if(b)
			step = step-1;
		this.x = x;
		this.y = y;
		
		int x1 = x2;
		int y1 = y2;
		int dx = x1-x;
		int dy = y1-y;
		
		double dline = Math.sqrt(dx*dx+dy*dy);
		cos = dx/dline;
		sin = dy/dline;
	}
	public void paint(Graphics g){
		if(isBoss){
			g.setColor(Color.red);
			g.drawString(style, x, y);
			g.setColor(Color.white);
			g.drawString("⊙", x, y);
		}else{
			g.setColor(Color.WHITE);
			g.drawString(style, x, y);
		}
	}
	public void move(Plane  plane,Vector<NpcBullet>  npcBullets){
		
		x+=(int)(step*cos);
		y+=(int)(step*sin);
		
		//碰撞检测
		int x1 = plane.x;
		int y1 = plane.y;
		int w1 = plane.w;
		int h1 = plane.h;
		if(!plane.remove && !plane.protect){
			if(x >  x1-w && x< x1+w1){
				if(y > y1-h && y < y1+h1){
					npcBullets.remove(this);
					//通知飞机被击中
					plane.hit = true;
					plane.hitCount++;//写入飞机被击中的次数
				}
			}
		}
		//边界判断
		if(x<-100  && x>MyFrame.width+100){
			if(y < -100 && y< MyFrame.height+100){
				npcBullets.remove(this);
			}
		}
	}
}
