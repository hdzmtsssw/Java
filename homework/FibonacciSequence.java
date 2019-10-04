package homework;

import java.util.Scanner;//包含有 输入 的函数所在类

//斐波那契数列，使用递归方法获得第n个数的数值
public class FibonacciSequence{
	public static void main(String[] args){
		System.out.println("请输入一个0-92之间的整数：");
		long [] arr = new long [93];
		//长整型数值到92位斐波那契数列数值的时候是最后一个正常数字，后面的会溢出。
		Scanner input= new Scanner(System.in); 
		int Num = input.nextInt();
		arr[0] = 0;
		arr[1] = 1;
		for(int i=2;i<93;i++){
			arr[i] = arr[i-1] + arr[i-2];
//			System.out.println(arr[i]+" ");
		}
		System.out.println("那么斐波那契数列中第"+Num+"个数字的数值为"+arr[Num]);
	}
}
