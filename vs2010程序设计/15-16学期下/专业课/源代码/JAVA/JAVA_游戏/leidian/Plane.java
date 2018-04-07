package day10.leidian;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Vector;

import javax.imageio.ImageIO;

public class Plane {
	int x;
	int y;
	int w;
	int h;
	int level =1;//子弹等级
	BufferedImage [] imgs = new BufferedImage[7];
	int count;//累计被击中次数
	boolean protect;//是否处于保护
	boolean  hit;//是否被击中
	int hitCount = 0;//被击中的次数
	int num = 0;//控制闪的次数
	boolean destroy;//是否通知销毁
	boolean left,up,right,down;
	int index;//控制图片索引
	int protectTime;//保护时间记数
	boolean remove ;
	int shanCount = 0;
	int shanStep = 2;
	int bombCount = 0;
	int bombStep = 2;
	boolean  reset = false;
	public Plane(){
		w = 40;
		h = 49;
		x = MyFrame.width/2 - w/2;
		y = MyFrame.height/2- h/2;
		count = 0;
		index =0;
		protectTime =0;
		protect = true;
		try {
			for(int i = 0; i <3;i++){
				imgs[i] = ImageIO.read(
						getClass().getResource(
								"/imgs/plane"+i+".png"));
			}
			for(int i = 0; i <4;i++){
				imgs[i+3] = ImageIO.read(
						getClass().getResource(
								"/imgs/bomb_"+i+".png"));
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void paint(Graphics  g){
		if(remove)
			return;
		g.drawImage(imgs[index], x, y, null);
		if(!destroy){
			if(hitCount >=10){
				hit = false;
				destroy = true;
			}
		
			if(hit && !protect){
				shanCount++;
				if(shanCount % shanStep ==0){
					index = (index==0)?1:0;
					num++;
					shanCount = 0;
				}
				if(num >10){
					index = 0;
					hit = false;
					num =0;
				}
			}
		
			if(protect){
				if(protectTime <100){
					protectTime++;
					index = (index==0)?2:0;
				}else{
					index =0;
					protect = false;
				}
			}
		}
		if(destroy){
			bombCount++;
			if(bombCount % bombStep ==0){
				index++;
			}
			if(index<3){
				index=3;
			}
		}
		if(index>=7){
			remove = true;
		}
	}
	public void move(Vector<Npc>  npcs,Vector<Tools>  tools){
		if(destroy)
			return;
		//碰撞检测tools
		for(int i = 0; i <tools.size();i++){
			int x1 = tools.get(i).x;
			int y1 = tools.get(i).y;
			int w1 = tools.get(i).w;
			int h1 = tools.get(i).h;
			if(x> x1-w && x <x1+w1){
				if(y>y1-h && y < y1+h1){
					//碰撞
					tools.get(i).y = MyFrame.height;
					String  s = tools.get(i).tools;
					if(s.equals("M"))
						level = 1;
					if(s.equals("L"))
						level = 2;
					if(s.equals("F"))
						level = 3;
					if(s.equals("S"))
						level = 4;
				}
			}
		}
		
		
		////碰撞检测Npc
		for(int i = 0; i <npcs.size();i++){
			int x1 = npcs.get(i).x;
			int y1 = npcs.get(i).y;
			int w1 = npcs.get(i).w;
			int h1 = npcs.get(i).h;
			if(x> x1-w && x <x1+w1){
				if(y>y1-h && y < y1+h1){
					//通知敌机被撞击
					npcs.get(i).hit = true;
					//通知自己被撞击  销毁
					if(!protect){
						destroy = true;
					}
				}
			}
			
		}
		
		
		if(left){x-=15;}
		if(up){y-=15;}
		if(right){x+=15;}
		if(down){y+=15;}
		//边界
		if(x<0){x=0;}
		if(x>MyFrame.width-w-5){x =MyFrame.width-w-5;}
		if(y<0){y=0;}
		if(y>MyFrame.height-h-20){y=MyFrame.height-h-30;}
		
	}
	
	public void init(){
		x = MyFrame.width/2 - w/2;
		y = MyFrame.height/2- h/2;
		count = 0;
		index =0;
		protectTime =0;
		protect = true;
		hit=false;
		hitCount = 0;//被击中的次数
		num = 0;
		destroy=false;//是否通知销毁
		index=0;//控制图片索引
		remove=false ;
		level =1;
		reset = false;
	}
	
}
