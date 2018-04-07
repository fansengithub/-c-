package day10.leidian;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;
import java.util.Vector;

import javax.imageio.ImageIO;

public class Boss{
	int x;
	int y;
	int w;
	int h;
	BufferedImage [] imgs = new BufferedImage[15];
	int index = 0;//控制图片索引
	boolean  hit;//是否被击中
	static int  hitCount=0;//击中次数
	boolean  destroy;//是否销毁
	boolean  remove;//是否移除
	Random  r = new Random();
	int x1;
	int y1;
	double sin;
	double cos;
	int step  = 3;//移动速度
	int bossCount = 0;
	int bossStep = 30;
	int shancount = 0;
	int shanstep = 3;
	public void init(){
		index = 0;
		hit=false;//是否被击中
		hitCount=0;//击中次数
		destroy = false;//是否销毁
		remove= false;//是否移除
		x = r.nextInt(MyFrame.width-w);
		y = 0-h;
		x1 = r.nextInt(MyFrame.width-w);
		y1 =  r.nextInt(MyFrame.height/2-h)+10;
		int  dx = x1 -x;
		int  dy = y1 -y;
		double dline = Math.sqrt(dx*dx+dy*dy);
		cos = dx/dline;
		sin = dy/dline;
	}
	public Boss() {
		try {
			for(int i =0; i <imgs.length;i++)
			imgs[i] = ImageIO.read(
				getClass().getResource("/imgs/boss"+i+".png"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		w = 61;
		h = 54;
		x = r.nextInt(MyFrame.width-w);
		y = 0-h;
		x1 = r.nextInt(MyFrame.width-w);
		y1 =  r.nextInt(MyFrame.height/2-h)+10;
		int  dx = x1 -x;
		int  dy = y1 -y;
		double dline = Math.sqrt(dx*dx+dy*dy);
		cos = dx/dline;
		sin = dy/dline;
		
	}
	public void paint(Graphics  g){
		if(remove)
			return;
		if(!destroy){
			if(hit){
				index = 1;
				hit = false;
			}else{
				index = 0;
			}
		}else{
			shancount++;
			if(shancount % shanstep ==0){
				index++;
				shancount = 0;
			}
			if(index>=imgs.length){
				remove = true;
				return;
			}
		}
		g.drawImage(imgs[index], x, y, null);
		
	}
	public void move(Vector<NpcBullet>  npcBullets,Vector<Bullet> bullets){
		if(destroy)
			return;
		//碰撞检测
		for(int i = 0 ;i <bullets.size();i++){
			int x1 = bullets.get(i).x;
			int y1 = bullets.get(i).y;
			int w1 = bullets.get(i).w;
			int h1 = bullets.get(i).h;
			if(x1 > x-w1 && x1< x+w){
				if(y1 > y-h1 && y1 < y+h){
					bullets.remove(i);//移除子弹
					hitCount ++;
					//System.out.println(hitCount);
					if(hitCount==100)
						MyPanel.score+=5;
					if(hitCount >100){
						destroy = true;
					}
					hit = true;
				}
			}
			
		}
		
		
		x+= step*cos;
		y+= step*sin;
		
		if(x<0 || x> MyFrame.width-w || y <0 || y>MyFrame.height/2-h){
			x1 = r.nextInt(MyFrame.width-w);
			y1 = r.nextInt(MyFrame.height/2-h)+10;
			int  dx = x1 -x;
			int  dy = y1 -y;
			double dline = Math.sqrt(dx*dx+dy*dy);
			cos = dx/dline;
			sin = dy/dline;
		}
		if(!destroy){
			bossCount++;
			if(bossCount % bossStep ==0){
				position(npcBullets,new Point(x,y));
				bossCount =0;
			}
		}
	}
	
	void position(Vector<NpcBullet>  npcBullets,Point  pt){
		NpcBullet  nb;
		int x = pt.x;
		int y = pt.y;
		
		nb = new NpcBullet(x+w/2,y+h, x+w/2, MyFrame.height,true);
		npcBullets.add(nb);

		nb = new NpcBullet(x+w/2-10,y+h, x+w/2-100, MyFrame.height,false);
		npcBullets.add(nb);
//		
		nb = new NpcBullet(x+w/2+10,y+h, x+w/2+100, MyFrame.height,false);
		npcBullets.add(nb);

		nb= new NpcBullet(x+w/2-20,y+h-20, x+w/2-200, MyFrame.height,false);
		npcBullets.add(nb);
		
		nb= new NpcBullet(x+w/2+20,y+h-20, x+w/2+200, MyFrame.height,false);
		npcBullets.add(nb);
		
		nb= new NpcBullet(x+w/2-20,y+h-30, x+w/2-300, MyFrame.height,false);
		npcBullets.add(nb);
		
		nb= new NpcBullet(x+w/2+20,y+h-30, x+w/2+300, MyFrame.height,false);
		npcBullets.add(nb);
	}
}
