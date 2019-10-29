package homework6;

public class Person {
	String name;
	int age;
	public Person(String name,int age) {
		super();
		this.name=name;
		this.age=age;
	}
	public int hashCode() {
		return name.hashCode();
	}
	public boolean equals(Object obj) {
		if(this==obj)
			return true;
		if(obj==null)
			return false;
		Person p=(Person) obj;
		return p.name.contentEquals(this.name);
	}
}