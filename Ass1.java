
import java.util.*;

public class Ass1 {

	public static void main(String[] args) {

		Scanner In = new Scanner(System.in);

		String name;
		System.out.print("What is your name ?  ");
		name = In.next();

		Today cobj = new Today();

     // name passed as formal parameter
		cobj.Print_hello(name);

     // prints local value

		cobj.displayLocalVariable();

	// prints global value
		cobj.displayGlobalVariable();

		System.out.print("What is Today's Day : ");
		cobj.day = In.next();

		System.out.println("Today is " +cobj.day);

// string day can be accessed bcz it is  declared public

// string week cannot be accessed bcz it is declared private
	}
}
