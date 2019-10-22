package homework5;

public class test01 {
	public static void main(String[] args){
		String str = "HelloWorld";
		char[] ch = str.toCharArray();
		StringBuffer buffer = new StringBuffer();
		for(int i = str.length()-1;i>=0;i--){
			if(ch[i]>='A' && ch[i]<='Z'){
				buffer.append(String.valueOf(ch[i]).toLowerCase());
			}else if(ch[i]>='a' && ch[i]<='z'){
				buffer.append(String.valueOf(ch[i]).toUpperCase());
			}
		}
		System.out.println(buffer.toString());
	}
}
