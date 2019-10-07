package experiment4;

public class Land {
	public static void main(String args[]){
		Village.setWaterAmount(200);  //用类名调用setWaterAmount(int m)，并向参数传值200
		int leftWater = Village.waterAmount;
		System.out.println("水井中有"+leftWater+"升水");
		Village zhaoZhuang,maJiaHeZi;
		zhaoZhuang = new Village("赵庄");
		maJiaHeZi = new Village("马家河子");
		zhaoZhuang.setPeopleNumber(80);
		maJiaHeZi.setPeopleNumber(120);
		zhaoZhuang.drinkWater(50);  //赵庄喝了50升水
		leftWater = maJiaHeZi.lookWaterAount();
		String name = maJiaHeZi.name;
		System.out.println(name+"发现水井中有"+leftWater+"升水");
		maJiaHeZi.drinkWater(100);
		leftWater = zhaoZhuang.lookWaterAount();
		name = zhaoZhuang.name;
		System.out.println(name+"发现水井中有"+leftWater+"升水");
		int peopleNumber = zhaoZhuang.getPeopleNumber();
		System.out.println("赵庄的人口："+peopleNumber);
		peopleNumber = maJiaHeZi.getPeopleNumber();
		System.out.println("马家河子的人口："+peopleNumber);
	}
}
