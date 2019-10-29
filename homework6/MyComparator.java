
package homework6;

import java.util.Comparator;

public class MyComparator implements Comparator{
	@Override
		public int compare(Object obj1, Object obj2) {
			// TODO Auto-generated method stub
			String str1=(String) obj1;
			String str2=(String) obj2;
			return str2.compareTo(str1);
		}
}
