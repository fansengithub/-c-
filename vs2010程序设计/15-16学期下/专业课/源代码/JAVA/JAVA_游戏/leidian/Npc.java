package day10.leidian;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;
import java.util.Vector;

import javax.imageio.ImageIO;

public class Npc {
	int x;
	int y;
	int x1;
	int y1;
	int w;
	int h;
	
	int imgcount = 0;
	int imgstep = 3;//���Ʊ�ըʱ��
	int bulletCount = 0;
	int bulletStep = 25;
	
	boolean  hit = false;//�Ƿ񱻻���
	boolean  remove =false;//�ǹ��Ƴ�
	
	BufferedImage  [] imgs = new BufferedImage[5];
	int index = 0;
	Random  r = new Random();
	int direction = 0;//����
	double sin=0;
	double cos=0;
	int step=3;
	public Npc() {
		int i = r.nextInt(8);
		step = r.nextInt(5)+2;
		//////66666666666
		direction = r.nextInt(5);
		///////66666666666
		try {
			imgs[0] = ImageIO.read(getClass().getResource("/imgs/"+i+".png"));
			for(int j = 0; j<4;j++){
				imgs[j+1] = ImageIO.read(getClass().getResource("/imgs/bomb_"+j+".png"));
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		w = imgs[0].getWidth();
		h = imgs[0].getHeight();
		if(direction==0){//��������  �ۻ�
			x= 0-imgs[0].getWidth();
			y= 0-imgs[0].getHeight();	
			x1 = MyFrame.width -imgs[0].getWidth();
			y1 = r.nextInt(MyFrame.height-imgs[0].getHeight()*2)+imgs[0].getHeight();
			
			
		}
		if(direction==1){//���ҵ�����  �ۻ�
			x= MyFrame.width;
			y= 0-imgs[0].getHeight();	
			x1 = 0;
			y1 = r.nextInt(MyFrame.height-imgs[0].getHeight()*2)+imgs[0].getHeight();
			
		}
		if(direction==2){//���ϵ���  �����xλ��
			x= r.nextInt(MyFrame.width-imgs[0].getWidth());
			y= 0-imgs[0].getHeight();	
			x1 = x;
			y1 = MyFrame.height/2 + r.nextInt(MyFrame.height/2-imgs[0].getHeight());
		}
		if(direction==3){//������ ƽ�� �����y 
			x= 0-imgs[0].getWidth();
			y = r.nextInt(MyFrame.height/2);
			x1 = MyFrame.width - imgs[0].getWidth();
			y1 = y;	
		}
		if(direction==4){//���ҵ��� ƽ�� �����y
			x= MyFrame.width;
			y = r.nextInt(MyFrame.height/2);
			x1 =0;
			y1 = y;
			
		}		
		int dx = x1-x;
		int dy = y1-y;
		double dline =Math.sqrt(dx*dx+dy*dy);
		cos  = dx/dline;
		sin =  dy/dline;
	}
	//����
	public void paint(Graphics g){
		if(remove)
			return;
		g.drawImage(imgs[index], x, y, null);
		if(hit){
			imgcount++;
			if(imgcount % imgstep ==0){
				index++;
				imgcount = 0;
			}
		}
		if(index>=4){
			remove = true;
		}
	}
	//NPC�ƶ�
	public void move(Vector<Npc>  npcs,Vector<NpcBullet> npcbullets,Plane plane){
		//0 ��������  �ۻ�
		//1 ���ҵ�����  �ۻ�
		//2 ���ϵ���  �����xλ��
		//3 ������ ƽ�� �����y 
		//4 ���ҵ��� ƽ�� �����y
		if(!remove && !plane.remove ){
			bulletCount++;
			if(bulletCount % bulletStep ==0){
				NpcBullet  nb = new NpcBullet(this,plane.x,plane.y);
				npcbullets.add(nb);
			}
		}
		
		if(remove){
			npcs.remove(this);
			MyPanel.score++;
		}
		x = x+(int)(step*cos);
		y = y+(int)(step*sin);
		if(direction==0){//��������  �ۻ�
			
			//�ж�x�����  ����ĳ��ֵ�� ���෴�����ƶ�
			if(x>MyFrame.width-imgs[0].getWidth()){
				//������������ ����
				int  x2 = 0-imgs[0].getWidth();
				int  y2 = r.nextInt(
						MyFrame.height-imgs[0].getHeight()*2)
						+imgs[0].getHeight();
				fun(x2,y2);
			}
		}
		if(direction==1){//���ҵ�����  �ۻ�
			
				if(x<0){
					int  x2 = MyFrame.width;
					int  y2 = r.nextInt(
							MyFrame.height-imgs[0].getHeight()*2)
							+imgs[0].getHeight();
					fun(x2,y2);
				}
		}
//		if(direction==2){//���ϵ���  �����xλ��
//			
////			
//		}
		if(direction==3){//������ ƽ�� �����y 
			
			if(x >MyFrame.width-imgs[0].getWidth()){
				int x2= 0-imgs[0].getWidth();
				int y2 = y1;
				fun(x2,y2);
			}
		}
		if(direction==4){//���ҵ��� ƽ�� �����y
			
			if(x<0){
				int x2 =MyFrame.width;
				int y2 = y;
				fun(x2,y2);
			}
		}
		if(x < 0-imgs[0].getWidth() ||
				x> MyFrame.width+imgs[0].getWidth() ||
				y>MyFrame.height){
			npcs.remove(this);
		}
	}
	private void fun(int x2,int y2){
		int dx = x2-x1;
		int dy = y2-y1;
		double dline =Math.sqrt(dx*dx+dy*dy);
		cos  = dx/dline;
		sin =  dy/dline;
	}
}
