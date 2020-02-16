import java.util.Scanner;
import java.io.*;
import java.util.*;
import MyPackage.*;

public class EmpSalary {
	public static void main(String args[])
	{
		double baseSalary, salary;
		cal_Implement a;
		a = new cal_Implement();
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the base salary of the employee : ");
		baseSalary = in.nextInt();
		salary = a.calculate_salary(baseSalary);
		System.out.println("The total salary of the employee is : " + salary);
	}
}
