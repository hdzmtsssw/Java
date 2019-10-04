
public class Add {
	public static void main(String[] args) {
		int result = 0;
		int i;
		for(i=0 ; i<100 ; i++){
			if(i%2 != 0){
				result += i;
			}
		}
		System.out.println(result);
	}
}
