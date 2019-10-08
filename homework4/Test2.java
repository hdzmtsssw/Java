package homework4;

public class Test2 {
		public static void main(String []args) {
			Square square = new Square();
			Circle circle = new Circle();
			System.out.println("边长为3的正方形的面积为：" + square.area(3.0));
			System.out.println("半径为2的圆的面积为：" + circle.area(2.0));
		}
}
