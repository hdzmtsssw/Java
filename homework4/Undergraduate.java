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
	   System.out.println("������"+this.name);
	   System.out.println("���䣺"+this.age);
	   System.out.println("רҵ��"+this.degree);
	}
}
