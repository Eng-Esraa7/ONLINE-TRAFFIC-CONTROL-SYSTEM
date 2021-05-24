#include <iostream>
#include <string>

using namespace std;
const int ownedcar = 3;
int counter = 1;
bool check = false;
bool check2 = false;
bool check1 = false;
bool ok = false;
int pay;
string yourchoose;
string username, passward;

   // information about fines
struct fines_info {
	int value_fines=0;
	string street_name;
	string date_fines;
	string statue_fines;
};
    //information about owned car
struct list_of_ownedcars { 
	string car_plate_no;
	string model;
	fines_info fines;
	int production_year;
};

    //information about driver
struct drivers_info {
	int license_no;
	string driver_name;
	string driver_birthday;
	string driver_passward;
	list_of_ownedcars ownedcar_no[ownedcar];
} drivers[100];

   //information about traffic_man
struct traffic_man {
	string traffic_name;
	string traffic_birthday;
	string traffic_passward;
}trafficman[100];
 //function to calculates total fines
void total_fines(int no ,int driver_no){
	int sum=0;
	for (int i = 1; i <= no; i++) {
		 sum += drivers[driver_no].ownedcar_no[i].fines.value_fines;
	}
	cout << "total fines : " << sum << endl;
}
 
     // function to calculates fines value
void regestire_fines(float speed, float road_max_speed, int drivers_no, int owned_car_no) {
	if (speed > road_max_speed) {
		cout << "Enter street name" << endl;
		cin >> drivers[drivers_no].ownedcar_no[owned_car_no].fines.street_name;
		cout << "Enter date fines" << endl;
		cin >> drivers[drivers_no].ownedcar_no[owned_car_no].fines.date_fines;
		cout << "Enter statue fines(paid or not)" << endl;
		cin >> drivers[drivers_no].ownedcar_no[owned_car_no].fines.statue_fines;
		cout << "the value fines = ";
		drivers[drivers_no].ownedcar_no[owned_car_no].fines.value_fines = 2 * (speed - road_max_speed);
		cout << drivers[drivers_no].ownedcar_no[owned_car_no].fines.value_fines << endl;
	}
	else
		cout << "no fined";
}

   // function to pay fines
void pay_fines(int driver_no, int no) {
	cout << "you have to pay: " << drivers[driver_no].ownedcar_no[no].fines.value_fines << endl;
	cin >> pay;
	if (drivers[driver_no].ownedcar_no[no].fines.value_fines == pay) {
		drivers[driver_no].ownedcar_no[no].fines.statue_fines = "pay";
		drivers[driver_no].ownedcar_no[no].fines.value_fines = 0;
		cout << "successful" << endl;
	}

	else if (drivers[driver_no].ownedcar_no[no].fines.value_fines > pay) {
		cout << "it is not enough" << endl;
		drivers[driver_no].ownedcar_no[no].fines.statue_fines = "not_pay";
	}
 }
    //function to register new car
void regestire_new_car(int driver_no , int no) {
	no++;
	if (no > 3)
		cout << "it is not available" << endl;
	else {
		cout << "register new car (plate number)" << endl;
		cin >> drivers[driver_no].ownedcar_no[no].car_plate_no;
		cout << "register new car (model)" << endl;
		cin >> drivers[driver_no].ownedcar_no[no].model;
		cout << "register new car (production year)" << endl;
		cin >> drivers[driver_no].ownedcar_no[no].production_year;
	}
  }
   //to display total fines, paid fines or register new car
void drivers_info() {
	int driver_no;
	int no;
	char chick;
	int num;
	int number;
	cout << "Enter your username" << endl; cin.ignore();
	getline(cin, username);
	cout << "Enter your passward" << endl;
	cin >> passward;
	for (int i = 1; i <= 100; i++) {
		if (username == drivers[i].driver_name && passward == drivers[i].driver_passward) {
			check = true;
			driver_no = i;
		}
	}
	if (check == true) {
		cout << "if you want show total fines enter(t)" << endl;
		cout << " if you want pay fines enter(p)" << endl;
		cout << " if you want register new car enter(r)" << endl;
		cin >> chick;
		if (chick == 't') {
			cout << "how many cars you have" << endl;
			cin >> num;
			for (int i = 1; i <= num; i++) {
				cout << "the fine on the car " << i << endl;
				cout << drivers[driver_no].ownedcar_no[i].fines.value_fines << endl;
			}
			 total_fines(num, driver_no);
		}
		if (chick == 'p') {
			cout << "Enter owned car number you want pay to it" << endl;
			cin >> no;
			pay_fines(driver_no,no);
		}
		if (chick == 'r') {
			cout << "Enter how many cars you have"<<endl;
			cin >> number;
			regestire_new_car(driver_no,number);
		}
	}
	else
		cout << "invalid account" << endl;  //if username and passward invalid
	check = false;
}
  //to traffic_man register fines if the car speed exceeds the road maximum speed.
void traffic_man_info(){
	int trafficman_no;
	int no;
	string platecar;
	int driver;
	float speed;
	float road_max_speed;
	cout << "Enter your username" << endl; cin.ignore();
	getline(cin, username);
	cout << "Enter your passward" << endl;
	cin >> passward;
	for (int i = 1; i <= 100; i++) {
		if (username == trafficman[i].traffic_name && passward == trafficman[i].traffic_passward) {
			check1 = true;
			trafficman_no = i;
		}
	}
	if (check1 == true) {
		cout << "Enter driver username" << endl; cin.ignore();
		getline(cin, username);
		cout << "Enter owned car number" << endl;
		cin >> no;
		cout << "Enter driver plate car number" << endl;
		cin >> platecar;
		for (int i = 1; i <= 100; i++) {
			if (username == drivers[i].driver_name && platecar == drivers[i].ownedcar_no[no].car_plate_no) {
				check2 = true;
				driver = i;
			}
		}
		if (check2 == true) {
			cout << "Enter the speed of car" << endl;
			cin >> speed;
			cout << "Enter road_max_speed" << endl;
			cin >> road_max_speed;

	regestire_fines(speed, road_max_speed, driver, no);
		}
		else
			cout << "invalid account" << endl;
	}
	else
		cout << "invalid account" << endl;
	check = false;
	check2 = false;
}
   //to search about car and fines by plate car or owner name
  void search() {
	  int driver_no;
	  int no;
	  int num;
	  char cho;
	  string plate;
	  string name;
	  cout << "if you want research by plate car enter (1)" << endl;
	  cout << "if you want research by car owner name enter (2)" << endl;
	  cin >> cho;
	  //to research by plate car
	  if (cho == '1') {
		  cout << "Enter plate car" << endl;
		  cin >> plate;
		  cout << "Enter number of cars owned" << endl;
		  cin >> no;
		  for (int i = 1; i <= 100; i++) {
			  if (plate == drivers[i].ownedcar_no[no].car_plate_no) {
				  ok = true;
				  driver_no = i;
			  }
		  }
	  }
	  //to research by owner name
	  if (cho == '2') {
		  cout << "Enter car owner name" << endl; cin.ignore();
		  getline(cin, name);
		  cout << "Enter number of cars owned" << endl;
		  cin >> no;
		  for (int i = 1; i <= 100; i++) {
			  if (name == drivers[i].driver_name) {
				  ok = true;
				  driver_no = i;
			  }
		  }
	  }
	  if (ok == true) {
		  cout << "car model : " << drivers[driver_no].ownedcar_no[no].model << endl;
		  cout << "car production year : " << drivers[driver_no].ownedcar_no[no].production_year << endl;
		  cout << "fines value : " << drivers[driver_no].ownedcar_no[no].fines.value_fines << endl;
		  cout << "fines statue : " << drivers[driver_no].ownedcar_no[no].fines.statue_fines << endl;
		  cout << "fines date : " << drivers[driver_no].ownedcar_no[no].fines.date_fines << endl;
		  cout << "fines street : " << drivers[driver_no].ownedcar_no[no].fines.street_name << endl;

	  }
	  else
		  cout << "invalid account" << endl;  //this account didn’t find
	  ok = false;
  }

// to make account
void sign_up(string type) {
	int owncarno;
	if (type == "driver") { //register information about drivers and their cars
		cout << "username" << endl; cin.ignore();
		getline(cin, drivers[counter].driver_name);
		cout << "passward" << endl;
		cin >> drivers[counter].driver_passward;
		cout << "what is your birthday" << endl;
		cin >> drivers[counter].driver_birthday;
		cout << "Enter your license number" << endl;
		cin >> drivers[counter].license_no;
		cout << "how many cars you have?" << endl;
		cin >> owncarno;
		for (int i = 1; i <= owncarno; i++) {
			cout << "Enter information about car" << i << endl;
			cout << "Enter your car plate number" << endl;
			cin >> drivers[counter].ownedcar_no[i].car_plate_no;
			cout << "Enter your car model" << endl;
			cin >> drivers[counter].ownedcar_no[i].model;
			cout << "Enter your car production year" << endl;
			cin >> drivers[counter].ownedcar_no[i].production_year;
		}
		counter++;
	}
	else if (type == "traffic_man") {  //register information about traffic_man
		cout << "username" << endl; cin.ignore();
		getline(cin, trafficman[counter].traffic_name);
		cout << "passward" << endl;
		cin >> trafficman[counter].traffic_passward;
		cout << "what is your birthday" << endl;
		cin >> trafficman[counter].traffic_birthday;
		counter++;
	}
}

//to sign in and do tasks
void sign_in(string type) {
	char chick;
	
	if (type == "driver") {
		drivers_info();
	}
		
	if (type == "traffic_man") {
		traffic_man_info();
	}
	else if (type == "researcher") {
		search();
	}
}
int main() {
	system("COLOR f0");
	string type;
	string ch;
	string cont;
	do {
		cout << "you have account" << endl;
		cin >> ch;
		if (ch == "yes") {
			cout << "are you driver , traffic_man or researcher??" << endl;
			cin >> type;
			sign_in(type);
		}
		else if(ch=="no") {
			cout << "are you driver or traffic_man??" << endl;
			cin >> type;
			sign_up(type);
		}
		cout << "are you want to continue??" << endl;
		cin >> cont;
	} while (cont == "yes");  //ask you if you want to continue  the program

	system("pause");
	return 0;
}