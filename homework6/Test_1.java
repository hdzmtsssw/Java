package homework6;

import java.util.*;

public class Test_1 {
	public static void main(String[] args) {
		HashSet hashSet=new HashSet();
		Person p1=new Person("CuteX",21);
		Person p2=new Person("Xiaobendan",21);
		Person p3=new Person("Link",22);
		hashSet.add(p1);
		hashSet.add(p2);
		hashSet.add(p3);
		for(Object obj:hashSet) {
			Person p=(Person)obj;
			System.out.println(p.name+":"+p.age);
		}
	}
}