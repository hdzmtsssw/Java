public class BigToSmall  {
	public static void main(String[] args){
		int temp = 0; 
		int arr[] = {25,24,12,76,101,96,28};
		for (int i = 0 ; i < arr.length-1 ; i++) {
			for (int j = arr.length-1 ; j > i; j--) {
				if (arr[j - 1] < arr[j]) {
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
		for(int k=0;k<arr.length;k++){
	        System.out.println(arr[k]);
		}
	}
}