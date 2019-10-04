
public class first {
	public static void main(String[] args){
		student stu = new student();
		stu.setAll("xueyan",'f', false, 78, 85);
		System.out.println(stu.name);
		System.out.println(stu.sex);
		System.out.println(stu.register);
		System.out.println(stu.javaNormalScore);
		System.out.println(stu.javaMidScore);
//		,stu.register,stu.javaNormalSccmdore,stu.javaMidScore
	}
}
class student{
	String name;
	char sex;
	boolean register;
	int javaNormalScore;
	float javaMidScore;
	public void setAll(String name,char sex,boolean register,int javaNormalScore,float javaMidScore){
//		//
		this.name = name;
		this.sex = sex;
		this.register = register;
		this.javaNormalScore = javaNormalScore;
		this.javaMidScore = javaMidScore;
	}
}