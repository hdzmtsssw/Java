import java.util.Scanner;

public class second {
	public static void main (String[] args){
//		int grade = 102;
		Scanner scanner=new Scanner(System.in);
		int grade=scanner.nextInt();
//		float num=scanner.nextFloat();
//		String str=scanner.nextLine();
//		if(grade>90){
//			System.out.println("该成绩的等级为优");
//		}
//		else if(grade>80){
//			System.out.println("该成绩的等级为良");
//		}
//		else if(grade>70){
//			System.out.println("该成绩的等级为中");
//		}
//		else if(grade>60){
//			System.out.println("该成绩的等级为及格");
//		}else{
//			System.out.println("该成绩的等级为不及格");
//		}
		
		switch(grade/10){
		case 1 :System.out.println("该成绩的等级为不及格");break;
		case 2 :System.out.println("该成绩的等级为不及格");break;
		case 3 :System.out.println("该成绩的等级为不及格");break;
		case 4 :System.out.println("该成绩的等级为不及格");break;
		case 5 :System.out.println("该成绩的等级为不及格");break;
		case 6 :System.out.println("该成绩的等级为及格");break;
		case 7 :System.out.println("该成绩的等级为中");break;
		case 8 :System.out.println("该成绩的等级为良");break;
		case 9 :System.out.println("该成绩的等级为优");break;
		case 10 :System.out.println("你真棒！！");break;
		
		}
	}
}
