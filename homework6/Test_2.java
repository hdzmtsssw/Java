package homework6;

import java.util.*;
public class Test_2 {
	public static void main(String[] args) {
		TreeMap map=new TreeMap(new MyComparator());
		map.put("1","Link");
		map.put("2","Xiaobendan");
		map.put("3","Tianxian");
		map.put("4","Cutex");
		map.put("5","List");
		for(Object key:map.keySet()) {
			System.out.println(key+":"+map.get(key));
		}
	}
}
