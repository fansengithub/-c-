package day10.leidian;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Map {
	int x;
	int y;
	BufferedImage  img;
	public Map() {
		// TODO Auto-generated constructor stub
//		img = ImageIO.read(new File(System.getProperty("user.dir")+"/bin/bg.gif"));
		try {
			img = ImageIO.read(getClass().getResource("/imgs/bg.gif"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		x = 0;
		y = 0;
	}
	//»æÖÆ
	public void paint(Graphics  g){
		g.drawImage(img, x, y-MyFrame.height, null);
		g.drawImage(img, x, y, null);
	}
	//ÒÆ¶¯
	public void move(){
		y+=2;
		if(y>MyFrame.height)
			y = 0;
	}
	

}
