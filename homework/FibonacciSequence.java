package homework;

import java.util.Scanner;//������ ���� �ĺ���������

//쳲��������У�ʹ�õݹ鷽����õ�n��������ֵ
public class FibonacciSequence{
	public static void main(String[] args){
		System.out.println("������һ��0-92֮���������");
		long [] arr = new long [93];
		//��������ֵ��92λ쳲�����������ֵ��ʱ�������һ���������֣�����Ļ������
		Scanner input= new Scanner(System.in); 
		int Num = input.nextInt();
		arr[0] = 0;
		arr[1] = 1;
		for(int i=2;i<93;i++){
			arr[i] = arr[i-1] + arr[i-2];
//			System.out.println(arr[i]+" ");
		}
		System.out.println("��ô쳲����������е�"+Num+"�����ֵ���ֵΪ"+arr[Num]);
	}
}
