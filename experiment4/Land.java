package experiment4;

public class Land {
	public static void main(String args[]){
		Village.setWaterAmount(200);  //����������setWaterAmount(int m)�����������ֵ200
		int leftWater = Village.waterAmount;
		System.out.println("ˮ������"+leftWater+"��ˮ");
		Village zhaoZhuang,maJiaHeZi;
		zhaoZhuang = new Village("��ׯ");
		maJiaHeZi = new Village("��Һ���");
		zhaoZhuang.setPeopleNumber(80);
		maJiaHeZi.setPeopleNumber(120);
		zhaoZhuang.drinkWater(50);  //��ׯ����50��ˮ
		leftWater = maJiaHeZi.lookWaterAount();
		String name = maJiaHeZi.name;
		System.out.println(name+"����ˮ������"+leftWater+"��ˮ");
		maJiaHeZi.drinkWater(100);
		leftWater = zhaoZhuang.lookWaterAount();
		name = zhaoZhuang.name;
		System.out.println(name+"����ˮ������"+leftWater+"��ˮ");
		int peopleNumber = zhaoZhuang.getPeopleNumber();
		System.out.println("��ׯ���˿ڣ�"+peopleNumber);
		peopleNumber = maJiaHeZi.getPeopleNumber();
		System.out.println("��Һ��ӵ��˿ڣ�"+peopleNumber);
	}
}
