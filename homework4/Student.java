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
    	System.out.println("ĞÕÃû£º"+this.name);
    	System.out.println("ÄêÁä£º"+this.age);
    }
}
