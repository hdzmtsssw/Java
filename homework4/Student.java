package homework4;

public class Student {
	protected String name;
	protected int age;
    public Student(String name,int age)
    {
    	this.name = name;
    	this.age = age;
    }
    void show()
    {
    	System.out.println("������"+this.name);
    	System.out.println("���䣺"+this.age);
    }
}
