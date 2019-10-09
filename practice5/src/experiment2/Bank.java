package experiment2;

public class Bank {
	int saveMoney;
	int year;
	double interest;
	double interestRate = 0.29;
	public double computerInterest() {
		interest = year*interestRate*saveMoney;
		return interest;
	}
	public void setInterestRate(double rate) {
		interestRate = rate;
	}
}
