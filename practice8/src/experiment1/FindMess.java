package experiment1;

public class FindMess {
	public static void main(String args[]) {
		String mess = "����:С���� ����ʱ��:1998.07.29�� ������վ��http://www.xiaokeai.com��"+"���:173cm,����:57kg";
		int index = mess.indexOf(":");
		String name = mess.substring(index+1);
		if(name.startsWith("С")) {
			System.out.println("�����е�������\"С\"");
		}
		index = mess.indexOf(":",index+1);
		String date = mess.substring(index+1,index+11);
		System.out.println(date);
		index = mess.indexOf(":",index+1);
		int heightPosition = mess.indexOf("���");
		String personNet = mess.substring(index+1,heightPosition-1);
		System.out.println(personNet);
		index = mess.indexOf(":",heightPosition);
		int cmPosition = mess.indexOf("cm");
		String height = mess.substring(index+1,cmPosition);
		height = height.trim();
		int h = Integer.parseInt(height);
		if(h>=180) {
			System.out.println("�����е����"+height+"���ڻ����180 cm");
		}
		else{
			System.out.println("�����е����"+height+"С��180 cm");
		}
		index = mess.lastIndexOf(":");
		int kgPosition = mess.indexOf("kg");
		String weight = mess.substring(index+1,kgPosition);
		height = weight.trim();
		int w = Integer.parseInt(weight);
		if(h>=75) {
			System.out.println("�����е����"+weight+"���ڻ����75 kg");
		}
		else{
			System.out.println("�����е����"+weight+"С��75 kg");
		}
	}
}
