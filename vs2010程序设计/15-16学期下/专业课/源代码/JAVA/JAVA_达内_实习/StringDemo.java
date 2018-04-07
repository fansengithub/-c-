package day5;

import java.util.Scanner;

public class StringDemo {
	public static void main(String[] args) {
		//char [] strs = {'a','v','8','d'};
//		String类跟任意类型相加  结果为String
//		String snum = "10";
//		int num  = Integer.parseInt(snum);
//		num++;
//		snum = String.valueOf(num);
//		snum = num+"";
//		String  str3 = "hello";
		Scanner  s = new Scanner(System.in);
		System.out.println("请你数输入四则运算表达式");
		String str = s.nextLine();
		System.out.println(str);
		//boolean  b1 = s.nextBoolean();
//		byte  b2 = s.nextByte();
//		short  s1 = s.nextShort();
//		int  i1 = s.nextInt();
//		long  l1 = s.nextLong();
//		double  d = s.nextDouble();
//		float f = s.nextFloat()
//		int a = s.nextInt();
//		int b = s.nextInt();
//		System.out.println("a:"+a+",b:"+b);
//		String s1 =  s.next();
//		System.out.println(s1);
//		String s2 = s.nextLine();
//		System.out.println(s2);
//		char c = s.nextLine().charAt(0);
//		System.out.println(c);
		
		
//		String  str = new String("Hello,world!");
//		String str1 = "Hello,wor,ld!";
//		String str2 = "Hello,worlc!";
//		
//		System.out.println("value:"+str.equals(str1));
//		System.out.println("ref:"+(str == str1));
//		System.out.println("value:"+str2.equals(str1));
//		System.out.println("ref:"+(str2 == str1));
		// String 对象不可更改  不能被寻址
		//str1 = "world!";
//		String strs = "1.txt,2.bmp,3.jpg,4.png,5.exe";
////		str1.trim()//字符串两端去空格
//		String   s1 = "   ab cd    ";
//		System.out.println(s1);
//		System.out.println(s1.trim());
//		str1.toLowerCase();//转小写
//		str1.toUpperCase();//转大写
//		str1.substring(int  begin)//从指定位置开始  截取到最后 
//		str1.substring(int  begin，int  end)//从指定位置开始  截取到end 
//		String s = str1.substring(3, 7);//从起始位置开始 截取到终止位置
//		System.out.println(s);			///但不包含终止位置
		//方法
//		str1.startsWith("xxx");// 查找当前字符串是否是以xxx开头  返回boolean		
		
//		String [] stray = strs.split(",");//按照规则 提取字符串返回数组
//		for(String s : stray){
//			System.out.println(s);
//		}
		
//		String s = str1.replace(",", "-12345-");//查找替换
//		System.out.println(s);//Hello-1234-world
		
//		str1.matches(regex) 匹配正则表达式  返回boolean
		
//		str1.length();//返回字符串长度
		
//		System.out.println(str1.lastIndexOf("l",8));
		//查找最后一个出现的字符或字符串 的位置  不存在返回-1
		
//		System.out.println(str1.indexOf("w"));
		//System.out.println(str1.indexOf("m", 0));
		//查找一个字符或字符串 的位置  不存在返回-1
		
		
//		str1.endsWith(suffix)//当前字符串是否以 suffix结尾  返回boolean
//		String [] strs = {"1.txt","2.bmp","3.jpg","4.png","5.exe"};
//		for(String s : strs){
//			if(s.endsWith(".jpg")){
//				System.out.println(s);
//			}
//		}
		
//		str1.contains(String  s) 查询字符串s是否存在 返回boolean
//		System.out.println(str1.contains("wor"));
		
//		str1.concat(str2)// 相等于 + 链接两个字符串
//		String s =str1.concat("12345");
//		System.out.println(s);
		
		
//		int i = str1.compareTo(str2);//判断值是否相等 返回值0相等
//		System.out.println(i);
//		if(str1.compareTo(str)==0){
//			System.out.println("相等");
//		}else{
//			System.out.println("不等");
//		}
		
//		str1.charAt(index) 根据索引位置返回字符
		// 5 01234
//		char c = str1.charAt(0);
//		System.out.println(c);
		
	

	}

}
