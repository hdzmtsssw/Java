package homework4;

public class Undergraduate extends Student{
	protected String degree;
	public Undergraduate (String name, int age,String degree) {
		super(name, age);
		this.name = name;
	    this.age = age;
	    this.degree = degree;
	}
	void show()
	{
	   System.out.println("姓名："+this.name);
	   System.out.println("年龄："+this.age);
	   System.out.println("专业："+this.degree);
	}
}
