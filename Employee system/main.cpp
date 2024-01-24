#include <iostream>
using namespace std;

const int MAX = 10000;
string names[MAX];
int ages[MAX];
double salaries[MAX];
char genders[MAX];
int added = 0 ; // number of employees

void read_employee(){
	cout << "Enter name : ";
	cin >> names[added];
 
	cout << "Enter Age : ";
	cin >> ages[added];
 
	cout << "Enter salary : ";
	cin >> salaries[added];
 
	cout << "Enter gender (M/F) :";
	cin >> genders[added];
 
	++added;
}

void print_employee(){
	cout << "********************\n";
	for( int i = 0 ; i < added ; ++i ){
		if(ages[i]!=-1)
		cout << names[i] << " " << ages[i] << " " 
			<< salaries[i] << " " << genders[i] <<"\n";
	}
}
void delete_by_age(){
	int start , end;
	cout << "Enter start and end age \n";
	cin >> start >> end ;
	for( int i = 0 ; i < added ; ++i ){
		if(ages[i]>=start && ages[i]<=end){
			ages[i]=-1;
		}
	}
}

void Update_salary_by_name(){
	string nm ;
	double sl;
	cout << "Enter the name and salary : \n";
	cin >> nm >> sl ;
 
	bool is_found = true ;
	for( int i = 0 ; i < added ; ++i ){
		if(names[i]==nm && ages[i] != -1){
			is_found = true;
			salaries[i]=sl;
			break;
			}
		}
		if(!is_found)
			cout << "NO employee with this name!\n";
}
int menu(){
	int choice = -1;
	while(choice == -1){
		cout << "\nEnter your choice: \n";
		cout << "1) Add new employee \n";
		cout << "2) Print all emloyees \n";
		cout << "3) Delete by age \n";
		cout << "4) Update salary by name \n";
 		
 		cin >> choice ;
 		
		if( choice < 1 || choice > 4 ){
			cout << "Invalid Input . Try again\n";
			choice = -1;
		}
	}
	return choice;
}
void employee_system(){
	while(true){
		int choice = menu();
		
		if(choice == 1){
			read_employee();
		}
		else if(choice == 2){
			print_employee();
		}else if(choice == 3){
			delete_by_age();
		}else if(choice == 4){
			Update_salary_by_name();
		}else{
			break;
		}
	}
}
int main() {
	employee_system();			
	return 0;
}
