package day10.leidian;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Vector;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class MyPanel extends JPanel implements Runnable {
	static int score;//�Ʒ�
	Map   map = new Map();//������ͼ
	Plane plane = new Plane();//�����ɻ�
	//����boss
	Boss   boss = new Boss();
	boolean showBoss = false;
	//�����ӵ�������
	Vector<Bullet>  bullets = new Vector<Bullet>();
	int bulletCount = 0;
	int bulletStep = 6;
	boolean isCreate = false;//�Ƿ񴴽��ӵ�
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
	
	
	//����gameover start
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
		//����Ѫ�� �ٷֱ� ������
		g.setColor(Color.red);
		g.drawRect(10, 10, 103, 15);
		int hp =100-plane.hitCount*10;
		if(hp<0 || plane.destroy)
			hp=0;
		g.fillRect(12, 12,hp , 12);
		g.drawString(hp+"%", 120, 25);
		g.drawString("Score:"+score*10, 220, 25);
		
		
		//���Ʒɻ�
		plane.paint(g);
		
		//����boss
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
		
		//���������������ӵ�
		for(int i = 0; i<bullets.size();i++){
			bullets.get(i).paint(g);
		}
		//����NPC
		///////////555555555555555
		for(int i = 0;i <npcs.size();i++){
			npcs.get(i).paint(g);
		}
		///////////555555555555555
		for(int i = 0; i <npcBullets.size();i++){
			npcBullets.get(i).paint(g);
		}
		//�������¿�ʼ
		if(plane.remove){
			g.drawImage(imgOver, 50,200, this);
		}
		////���Ƶ���
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
			map.move();//��ͼ�ƶ�
			plane.move(npcs,tools);
			//����ӵ� ��Ҫ��������
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
			//�ƶ������������ӵ�
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
			repaint();//�ػ�
		}
	}
	 public void addBullet(){
		 // �����ӵ� ��Ҫ���ݷɻ����е�level���Դ���
		 bulletCount++;
		 if(bulletCount % bulletStep ==0){
			 if(plane.level ==1){//����һ���ӵ�
				 Bullet  bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2;
				 bullet.y = plane.y;
				 bullets.add(bullet);
				 
			 }
			 if(plane.level ==2){//����2���ӵ�
				 Bullet  bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2-10;
				 bullet.y = plane.y ;
				 bullets.add(bullet);
				 
				 bullet = new Bullet();
				 bullet.x = plane.x+plane.w/2-bullet.w/2+10;
				 bullet.y = plane.y;
				 bullets.add(bullet);
				 
			 }
			 if(plane.level ==3){//����2���ӵ�
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
			 if(plane.level ==4){//����2���ӵ�
				 
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
