
public class Today {

		int year=2019;           // global variable

		public String day;       // public string
		private String week;		// private string

		public void Print_hello(String name){
			/* Formal parameter example */

	       System.out.println("Hello " +name +".Have a nice day!");

		}

		public void displayLocalVariable(){

			int year = 2000; // local variable

			System.out.println("Local value of year: " +year);

		}

		public void displayGlobalVariable(){

			System.out.println("Global value of year: " +year);
		}


}
