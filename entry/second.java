import java.util.Scanner;

public class second {
	public static void main (String[] args){
//		int grade = 102;
		Scanner scanner=new Scanner(System.in);
		int grade=scanner.nextInt();
//		float num=scanner.nextFloat();
//		String str=scanner.nextLine();
//		if(grade>90){
//			System.out.println("�óɼ��ĵȼ�Ϊ��");
//		}
//		else if(grade>80){
//			System.out.println("�óɼ��ĵȼ�Ϊ��");
//		}
//		else if(grade>70){
//			System.out.println("�óɼ��ĵȼ�Ϊ��");
//		}
//		else if(grade>60){
//			System.out.println("�óɼ��ĵȼ�Ϊ����");
//		}else{
//			System.out.println("�óɼ��ĵȼ�Ϊ������");
//		}
		
		switch(grade/10){
		case 1 :System.out.println("�óɼ��ĵȼ�Ϊ������");break;
		case 2 :System.out.println("�óɼ��ĵȼ�Ϊ������");break;
		case 3 :System.out.println("�óɼ��ĵȼ�Ϊ������");break;
		case 4 :System.out.println("�óɼ��ĵȼ�Ϊ������");break;
		case 5 :System.out.println("�óɼ��ĵȼ�Ϊ������");break;
		case 6 :System.out.println("�óɼ��ĵȼ�Ϊ����");break;
		case 7 :System.out.println("�óɼ��ĵȼ�Ϊ��");break;
		case 8 :System.out.println("�óɼ��ĵȼ�Ϊ��");break;
		case 9 :System.out.println("�óɼ��ĵȼ�Ϊ��");break;
		case 10 :System.out.println("���������");break;
		
		}
	}
}
