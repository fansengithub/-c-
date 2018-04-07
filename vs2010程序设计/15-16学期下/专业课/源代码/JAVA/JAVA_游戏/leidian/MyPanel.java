package day10.leidian;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Vector;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class MyPanel extends JPanel implements Runnable {
	static int score;//计分
	Map   map = new Map();//创建地图
	Plane plane = new Plane();//创建飞机
	//创建boss
	Boss   boss = new Boss();
	boolean showBoss = false;
	//定义子弹的容器
	Vector<Bullet>  bullets = new Vector<Bullet>();
	int bulletCount = 0;
	int bulletStep = 6;
	boolean isCreate = false;//是否创建子弹
	///////////////////////1111111111111111
	Vector<Npc>  npcs = new Vector<Npc>();
	int NpcCount = 0;
	int NpcStep = 20;
	////////////////////////11111111111111
	Vector<NpcBullet>  npcBullets = new Vector<NpcBullet>();
	///////////////////////
	Vector<Tools>  tools = new Vector<Tools>();
	int toolsCount = 0;
	int toolsStep = 50;
	/////////////////////////
	//Vector<NpcBullet>  bossBullets = new Vector<NpcBullet>();
	
	
	//加载gameover start
	BufferedImage  imgOver;
	
	public MyPanel() {
		// TODO Auto-generated constructor stub
		try {
			imgOver = ImageIO.read(
				getClass().getResource("/imgs/gameover.png"));
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
				
	}
	@Override
	public void paint(Graphics g) {
		// TODO Auto-generated method stub
		map.paint(g);
		//绘制血槽 百分比 及分数
		g.setColor(Color.red);
		g.drawRect(10, 10, 103, 15);
		int hp =100-plane.hitCount*10;
		if(hp<0 || plane.destroy)
			hp=0;
		g.fillRect(12, 12,hp , 12);
		g.drawString(hp+"%", 120, 25);
		g.drawString("Score:"+score*10, 220, 25);
		
		
		//绘制飞机
		plane.paint(g);
		
		//绘制boss
		if(showBoss){
			boss.paint(g);
			g.setColor(Color.YELLOW);
			g.drawRect(10,28, 103, 11);
			int hp2 = 100-boss.hitCount;
			if(hp2<0)
				hp2=0;
			g.fillRect(12,30,hp2 ,8);
			
			g.drawString(hp2*10+"", 120, 39);
			System.out.println(boss.y);
		}
		
		//绘制容器中所有子弹
		for(int i = 0; i<bullets.size();i++){
			bullets.get(i).paint(g);
		}
		//绘制NPC
		///////////555555555555555
		for(int i = 0;i <npcs.size();i++){
			npcs.get(i).paint(g);
		}
		///////////555555555555555
		for(int i = 0; i <npcBullets.size();i++){
			npcBullets.get(i).paint(g);
		}
		//绘制重新开始
		if(plane.remove){
			g.drawImage(imgOver, 50,200, this);
		}
		////绘制道具
		for(int i =0;i<tools.size();i++){
			tools.get(i).paint(g);
		}
		
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true){
			try {
				Thread.sleep(20);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			map.move();//地图移动
			plane.move(npcs,tools);
			//添加子弹 需要按键控制
			if(isCreate  && !plane.remove){
				addBullet();
			}
			////////////3
			
			if(score !=0  && score  %10 ==0){
				if(!showBoss){
					boss.init();
					showBoss = true;
				}
			}
			if(boss.remove){
				
				showBoss = false;
//				boss = null;
			}
			//System.out.println("socre:"+score+","+showBoss);
			if(showBoss){
				boss.move(npcBullets,bullets);
			}else{
				addNpc();
			}
			///////////3
			//addNpcBullet();
//			System.out.println(npcs.size());
			//移动容器中所有子弹
			for(int i = 0; i <bullets.size();i++){
				bullets.get(i).move(bullets,npcs);
			}
			///////////444444444
			for(int i = 0;i <npcs.size();i++){
				npcs.get(i).move(npcs,npcBullets,plane);
			}
			
			///////////44444444444
			for(int i = 0; i <npcBullets.size();i++){
				npcBullets.get(i).move(plane,npcBullets);
			}
			///////move////////////////
			addTools();
//			System.out.println(tools.size());
			for(int i =0;i<tools.size();i++){
				tools.get(i).move(tools);
			}
			///////////////////
			repaint();//重绘
		}
	}
	 public void addBullet(){
		 // 创建子弹 需要根据飞机类中的level属性创建
		 bulletCount++;
		 if(bulletCount % bulletStep ==0){
			 if(plane.level ==1){//创建一颗子弹
				 Bullet  bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2;
				 bullet.y = plane.y;
				 bullets.add(bullet);
				 
			 }
			 if(plane.level ==2){//创建2颗子弹
				 Bullet  bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2-10;
				 bullet.y = plane.y ;
				 bullets.add(bullet);
				 
				 bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2+10;
				 bullet.y = plane.y;
				 bullets.add(bullet);
				 
			 }
			 if(plane.level ==3){//创建2颗子弹
				 Bullet  bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2;
				 bullet.y = plane.y;
				 bullets.add(bullet);
				 
				 bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2-10;
				 bullet.xStep=-2;
				 bullet.y = plane.y ;
				 bullets.add(bullet);
				 
				 bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2+10;
				 bullet.xStep=2;
				 bullet.y = plane.y;
				 bullets.add(bullet);
				 
			 }
			 if(plane.level ==4){//创建2颗子弹
				 
				 Bullet  bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2-10;
				 bullet.y = plane.y ;
				 bullets.add(bullet);
				 
				 bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2+10;
				 bullet.y = plane.y;
				 bullets.add(bullet);
				 
				 bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2-15;
				 bullet.xStep=-2;
				 bullet.y = plane.y+5 ;
				 bullets.add(bullet);
				 
				 bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2+15;
				 bullet.xStep=2;
				 bullet.y = plane.y+5;
				 bullets.add(bullet);
			 }
			 bulletCount = 0;
		 }
		 
	 }
	 ////////////22222222222222222222
	 public void addNpc(){
		 NpcCount++;
		 if(NpcCount % NpcStep ==0){
			Npc  npc = new Npc();
			npcs.add(npc);
			NpcCount=0; 
		 }
	 }
	 //////////////22222222222222222
//	 public void addNpcBullet(){
//		 npcbulletCount++;
//		 if(npcbulletCouht % npcbulletStep==0){
//			 for(int i=0; i <npcs.size();i++){
//				 NpcBullet  nb = new NpcBullet(npcs.get(i), plane);
//				 npcBullets.add(nb);
//			 }
//		 }
//	 }
	public void init(){
		plane.init();
		score = 0;
	}
	public void clear(){
		
		for(int i = 0; i <npcs.size();i++){
			npcs.get(i).hit  = true;
		}
		npcBullets.clear();
	}
	
	public  void addTools(){
		toolsCount++;
		if(toolsCount % toolsStep ==0){
			Tools  t = new Tools();
			tools.add(t);
			toolsCount=0;
		}
	}
	
	
}
