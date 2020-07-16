/*
Project name: Freelancing
Project contributors: Abid Ali SAP 21022 and Muhammad Waseem SAP 21331
Course name: ProgrammingFundamentals Section 2 semester 1 spring 2020 
Project goals set by teacher:-
Variables			  => 	Used on every page
Conditional operators =>    used on almost every page
logical operators	  =>	Used on almost every page
Switch Statement	  => 	Used more than 5 times throughout the project
Conditional Statements=> 	Used on almost every page
loops				  => 	used on almost every page
Arrays				  =>	declared in the beginning of the project, used in every page
	1D Array		  =>	first used in line#27
	2D Array		  =>	first used in line#32
Pointers			  =>	declared in line#896, used in line#939
Functions			  =>	first declared in line#60, used widely in the project
Structures			  =>	first declared in line#35, used within specific functions
String (Optional)	  =>	first declared in line#32, used widely in the project
FileHandling(Optional)=>	-Not needed, (data is stored during runtime and is erased as program closes)
*/
#include<iostream>	//for basic input output operations
#include<ctime>		//to collaborate with rand() to generate better random numbers
#include<cstdlib>	//to generate random numbers
#include<cmath>		//to perform some mathematic operations
using namespace std;
int total_credits[20]={};	//stores data for total_credits for 20 users
int credit_reward;
int user_id;
int user_pointer;
int registered_user=1;
string user[20][2];			//to store user names and passwords of 20 users, I know it was better to use struct, but I had to utilize 2d arrays too
string user_type[20];		//to find out whether user is a freelancer or a client
int current_user=0;			//to find out how many users have registered
struct about{				//to store data for about item which is used in freelancer and client main menu
	string name;
	int projects_completed;
	int projects_failed;
	int earned;
};
struct date_of_birth{		//to store date of birth of users
	int year;
	string month;
	int date;
};
about about_user[20];		//to store about data for 20 users
date_of_birth dob[20];		//to store dates of birth of 20 users
//to make sure compiler knows which functions i will be using
void register_client();
void register_freelancer();
int login();
void scam();
void client();
void freelance();
void find_maths();
void find_english();
void find_gk();
void maths_teacher();
void english_teacher();
void gk_teacher();
void help_center();
void register_client(){		//register as a client
	int flag;
	cout<<"\tRegister as a client\n\n";
	cout<<"Enter your name:"<<endl;
	cin>>user[current_user][0];
	cout<<"Enter your password:"<<endl;
	cin>>user[current_user][1];
	cout<<"Enter your date of birth\n";
	cout<<"Enter year:\n";
	cin>>dob[current_user].year;
	cout<<"Enter month name:\n";
	cin>>dob[current_user].month;
	cout<<"Enter date:\n";
	cin>>dob[current_user].date;
	for(int i=0;i<current_user;i++){
		if(user[current_user][0]==user[i][0]){
			cout<<"The user name is already taken, choose a different user name\n";
			flag=0;
		}		
	}
	if(flag!=0){
		user_type[current_user]="client";
		cout<<endl<<"you have successfully registered as a "<<user_type[current_user]<<endl;
		current_user++;
	}
}
void register_freelancer(){//register as a freelancer
	int flag;
	cout<<"\tRegister as a freelancer\n\n";
	cout<<"Enter your name:"<<endl;
	cin>>user[current_user][0];
	cout<<"Enter your password:"<<endl;
	cin>>user[current_user][1];
	cout<<"Enter your date of birth\n";
	cout<<"Enter year:\n";
	cin>>dob[current_user].year;
	cout<<"Enter month name:\n";
	cin>>dob[current_user].month;
	cout<<"Enter date:\n";
	cin>>dob[current_user].date;
	for(int i=0;i<current_user;i++){
		if(user[current_user][0]==user[i][0]){
			cout<<"The user name is already taken, choose a different user name\n";
			flag=0;
		}		
	}
	if(flag!=0){
		user_type[current_user]="freelancer";
		cout<<endl<<"you have successfully registered as a "<<user_type[current_user]<<endl;
		current_user++;
	}
}
int login(){					//login function used in the main menu
	registered_user=1;			//Is this user registered? 0=true, 1=false
	string temp_uname,temp_pass;//to store the name and pass entered by the user
	cout<<"\tLogin\n";
	cout<<"Enter your username:"<<endl;
	cin>>temp_uname;
	cout<<"Enter your password:"<<endl;
	cin>>temp_pass;
	for(int i=0;i<current_user;i++){	//iterate for all the registered users
		if(temp_uname==user[i][0]){		//is user name registred by any user?
			if(temp_pass==user[i][1]){	//if user is registered, does his password match
				user_id=i;				//to store the location of logged in user in the array
				registered_user=0;		//this user is now registered
				cout<<"User name and Password match found in the database!\n";
				cout<<"You are registered as a "<<user_type[user_id]<<endl;
				if(user_type[i]=="client"){
					user_pointer=0;		//redirect this user to client menu
				}
				else if(user_type[i]=="freelancer"){
					user_pointer=1;		//redirect this user to freelancer's menu
				}				
				system("pause");
				system("cls");
				if(user_type[user_id]=="client"){
				total_credits[user_id]+=100;	//to give some free credits to a client to get started
				cout<<"You have been awarded 100 free credits, congrats!\n";
				}
				about_user[user_id].name=user[user_id][0];	//to copy user name from array to struct
			}
			else{		//user found but password do not match
				cout<<"Your user name and password do not match, make sure you write them in correct case\n";
			}			
		}
		else if(temp_uname!=user[i][0]){//incorrect username
				cout<<"User not found!\n";
			}
	}
	if(current_user==0){			//no users have registered yet
		cout<<"No users yet!\n";
		cout<<"Why not register some in the menu below?\n";
	}
	return user_pointer;			//0=cliet, 1=freelancer
	return registered_user;			//decides whether user is registered or not in int main().
}
void scam(){		//not a scam
	srand(time(0));
	char choice;
	int amount;
	amount=rand()%20;
	cout<<"We are giving away free credits, would you like to have some too?\ny/n\n";
	cin>>choice;
	if(choice=='y'||choice=='Y'){
		total_credits[user_id]+=amount;
		cout<<"We gave you "<<amount<<" free credits\n";
	}
	else
		cout<<"good luck\n";
}
void client(){		//client main menu
	int cchoice;
	bool continue_work=true;
	while(continue_work){
		cout<<"***************************************"<<endl;
		cout<<"*          Find freelancer            *"<<endl;
		cout<<"* 1. Find Senior Maths teacher        *"<<endl;
		cout<<"* 2. Find Kids English teacher        *"<<endl;
		cout<<"* 3. Find GK teacher                  *"<<endl;
		cout<<"* 4. Show user data                   *"<<endl;
		cout<<"* 5. Get more credits                 *"<<endl;
		cout<<"* 6. Clear screen                     *"<<endl;
		cout<<"* 7. Back to previous menu            *"<<endl;
		cout<<"***************************************"<<endl;
		cout<<"\nEnter your choice:\n";	
		cin>>cchoice;
		switch(cchoice){
			case 1:
				find_maths();
				break;
			case 2:
				find_english();
				break;
			case 3:
				find_gk();
				break;
			case 4:
				system("cls");
				cout<<"user name: "<<about_user[user_id].name<<endl;
				cout<<"Total spent by the user: "<<about_user[user_id].earned<<" credits"<<endl;
				cout<<"Date of birth: "<<dob[user_id].month<<" "<<dob[user_id].date<<" "<<dob[user_id].year<<endl;
				cout<<"Projects user worked on: "<<about_user[user_id].projects_completed<<endl;
				cout<<"Total Available Credits: "<<total_credits[user_id]<<" credits"<<endl;
				break;
			case 5:
				scam();
				break;
			case 6:
				system("cls");
				break;
			case 7:
				continue_work=false;
				break;
			default:
				cout<<"invalid coice\n";
				break;
		}
	}
}
void freelance(){		//freelancer main menu
	int fchoice;
	bool continue_work=true;
	while(continue_work){
		cout<<"***************************************"<<endl;
		cout<<"*          Find Work                  *"<<endl;
		cout<<"* 1. Work as Senior Maths teacher     *"<<endl;
		cout<<"* 2. Work as Kids English teacher     *"<<endl;
		cout<<"* 3. Work as GK teacher               *"<<endl;
		cout<<"* 4. Show user data                   *"<<endl;
		cout<<"* 5. Clear screen                     *"<<endl;
		cout<<"* 6. Back to previous menu            *"<<endl;
		cout<<"***************************************"<<endl;
		cout<<"\nEnter your choice:\n";
		cin>>fchoice;
		switch(fchoice){
			case 1:
				maths_teacher();
				break;
			case 2:
				english_teacher();
				break;
			case 3:
				gk_teacher();
				break;
			case 4:
				system("cls");
				cout<<"user name: "<<about_user[user_id].name<<endl;
				cout<<"Date of birth: "<<dob[user_id].month<<" "<<dob[user_id].date<<" "<<dob[user_id].year<<endl;
				cout<<"Total earned by the user: "<<about_user[user_id].earned<<" credits"<<endl;
				cout<<"Projects user completed successfully: "<<about_user[user_id].projects_completed<<endl;
				cout<<"Projects user failed to complete: "<<about_user[user_id].projects_failed<<endl;
				break;
			case 5:
				system("cls");
				break;
			case 6:
				continue_work=false;
				break;
			default:
				cout<<"invalid coice\n";
				break;
		}
	}
}
void find_maths(){		//used in client's menu
	int credit_cost;
	double answer;
	bool success;
	int choice;
	bool done=false;
	int a,b,c,d;
	while(!done){
		success=false;
		cout<<"*********************************************"<<endl;
		cout<<"*          Find a mathematician             *"<<endl;
		cout<<"* 1. For discriminant calculation           *"<<endl;
		cout<<"* 2. For area of triangle                   *"<<endl;
		cout<<"* 3. For area of quadrilateral              *"<<endl;
		cout<<"* 4. For area of circle                     *"<<endl;
		cout<<"* 5. For number raised to a power n         *"<<endl;
		cout<<"* 6. For calculate sqrt of number           *"<<endl;
		cout<<"* 7. For finding distance between two points*"<<endl;
		cout<<"* 8. Back to previous menu                  *"<<endl;
		cout<<"*********************************************"<<endl;
		cout<<"\nEnter your choice: "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				credit_cost=20;
				if(total_credits[user_id]>=credit_cost){
				cout<<"enter the values for a then b and then c\n";
				cin>>a>>b>>c;
				answer=((b*b)-(4*a*c));
				cout<<"We hired a freelancer for you, he provided the following results\n";
				cout<<"discriminant = "<<answer<<endl;
				success=true;
				}
				else{
					cout<<"insufficient credits!\n";
				}
				break;
			case 2:
				credit_cost=15;
				if(total_credits[user_id]>=credit_cost){
				cout<<"Enter the base and then height of the triangle\n";
				cin>>a>>b;
				answer=(0.5*a*b);
				cout<<"We hired a freelancer for you, he provided the following results\n";
				cout<<"Area of right angled triangle = "<<answer<<endl;
				success=true;
				}
				else{
					cout<<"insufficient credits!\n";
				}
				break;
			case 3:
				credit_cost=25;
				if(total_credits[user_id]>=credit_cost){
				cout<<"Enter the length of each side of the quadrilateral one after the other\n";
				cin>>a>>b>>c>>d;
				answer=(0.5*((a*b)*(b*c)))+(0.5*((a*b)*(d*c)));
				cout<<"We hired a freelancer for you, he provided the following results\n";
				cout<<"Area of quadrilateral = "<<answer<<endl;
				success=true;
				}
				else{
					cout<<"insufficient credits!\n";
				}
				break;
			case 4:
				credit_cost=15;
				if(total_credits[user_id]>=credit_cost){
				cout<<"Enter the radius of circle\n";
				cin>>a;
				answer=(3.14*(a*a));
				cout<<"We hired a freelancer for you, he provided the following results\n";
				cout<<"Area of circle = "<<answer<<endl;
				success=true;
				}
				else{
					cout<<"insufficient credits!\n";
				}
				break;
			case 5:
				credit_cost=15;
				if(total_credits[user_id]>=credit_cost){
				cout<<"Enter the number and then its power\n";
				cin>>a>>b;
				answer=pow(a,b);
				cout<<"We hired a freelancer for you, he provided the following results\n";
				cout<<"Result of number "<<a<<" raised to power "<<b<<" is "<<answer<<endl;
				success=true;
				}
				else{
					cout<<"insufficient credits!\n";
				}
				break;
			case 6:
				credit_cost=10;
				if(total_credits[user_id]>=credit_cost){
				cout<<"enter the number to find square root\n";
				cin>>a;
				answer=sqrt(a);
				cout<<"We hired a freelancer for you, he provided the following results\n";
				cout<<"Square root of number "<<a<<" is "<<answer<<endl;
				success=true;
				}
				else{
					cout<<"insufficient credits!\n";
				}
				break;
			case 7:
				credit_cost=20;
				if(total_credits[user_id]>=credit_cost){
				cout<<"Enter the point x1 and then y1\n";
				cin>>a>>b;
				cout<<"enter the point x2 and then y2\n";
				cin>>c>>d;
				answer=sqrt(((c-a)*(c-a))+((d-b)*(d-b)));
				cout<<"We hired a freelancer for you, he provided the following results\n";
				cout<<"Distance between the points ("<<a<<","<<b<<") and "<<"("<<c<<","<<d<<") is"<<answer<<endl;
				success=true;
				}
				else{
					cout<<"insufficient credits!\n";
				}
				break;
			case 8:
				done=true;
				break;
			default:
				cout<<"please enter a valid choice!"<<endl;
				break;
		}
		if(success==true){
			cout<<"We verified your proposed output and the output provided by the freelancer\n";
			cout<<"Herewith:\n"<<credit_cost<<" has been deducted from your account\n";
			total_credits[user_id]-=credit_cost;
			about_user[user_id].projects_completed+=1;
			about_user[user_id].earned+=credit_cost;
		}
	}
}
void find_english(){		//used in client's menu
	char temp;
	char vowels[]={'a','e','i','o','u'};
	int choice;
	int credit_cost;
	char answer;
	bool success;
	bool done=false;
	while(!done){
		success=false;
		cout<<"******************************************"<<endl;
		cout<<"*      Find English teacher              *"<<endl;
		cout<<"* 1. For teaching capital aplhabets      *"<<endl;
		cout<<"* 2. For teaching small aplphabets       *"<<endl;
		cout<<"* 3. For teaching vowels                 *"<<endl;
		cout<<"* 4. To Answer the students              *"<<endl;
		cout<<"* 5. Back to previous menu               *"<<endl;
		cout<<"******************************************"<<endl;
		cout<<"\nEnter your choice: "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				credit_cost=10;
				cout<<"Teaching Capital Alphabets\n";
				for(int i=65;i<=90;i++){
					temp=i;
					cout<<temp<<" ";
				}
				success=true;
				break;
			case 2:
				credit_cost=10;
				cout<<"Teachin alphabets in lower case\n";
				for(int i=97;i<=122;i++){
					temp=i;
					cout<<temp<<" ";
				}
				success=true;
				break;
			case 3:
				credit_cost=10;
				cout<<"Teaching vowels\n";
				for(int i=0;i<5;i++){
					cout<<vowels[i]<<" ";
				}
				success=true;
				break;
			case 4:
				credit_cost=10;
				cout<<"Answer the students\n";
				cout<<"what alphabet comes after which letter? Enter the letter \n";
				cin>>temp;
				answer=temp+1;
				cout<<answer;
				success=true;
				break;
			case 5:
				done=true;
				break;
			default:
				cout<<"Invalid choice!\n";
		}
		if(success==true){
			cout<<endl;
			cout<<"We hired a freelancer for you, he provided the above results\n";
			cout<<"We verified your proposed output and the output provided by the freelancer\n";
			cout<<"Herewith:\n"<<credit_cost<<" credits have been deducted from your account\n";
			total_credits[user_id]-=credit_cost;
			about_user[user_id].projects_completed+=1;
			about_user[user_id].earned+=credit_cost;
		}
	}
}
void find_gk(){		//used in client's menu
	int credit_cost;
	bool success;
	bool done=false;
	string reply;
	int choice;
	while(!done){
		success=false;
		cout<<"*******************************************************************"<<endl;
		cout<<"*                What do you want to know?                        *"<<endl;
		cout<<"* 1. What is the total area of Pakistan in square kilometers      *"<<endl;
		cout<<"* 2. Who is current prime minister of Pakistan                    *"<<endl;
		cout<<"* 3. Roza became complulsory in which year                        *"<<endl;
		cout<<"* 4. How many days in the month of October                        *"<<endl;
		cout<<"* ________________________________________________________________*"<<endl;
		cout<<"* 5. Back to previous menu                                        *"<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<"Enter your choice\n";
		cin>>choice;
		switch(choice){
			case 1:
				credit_cost=15;
				cout<<"Total area of Pakistan is 796096 square kilometers\n";
				success=true;
				break;
			case 2:
				credit_cost=10;
				cout<<"Current prime minister is Muhammad Imran Khan Niazi\n";
				success=true;
				break;
			case 3:
				credit_cost=20;
				cout<<"Roza became compulsory in 623 AD\n";
				success=true;
				break;
			case 4:
				credit_cost=15;
				cout<<"There are 31 days in month of october\n";
				success=true;
				break;
			case 5:
				done=true;
				break;
			default:
				cout<<"Invalid choice!\n";
		}
		if(success==true){
			cout<<"We hired a freelancer to answer your question, we verified the results\n";
			cout<<"Hereby:\nWe have deducted "<<credit_cost<<" credits from your account\n";
			about_user[user_id].projects_completed+=1;
			about_user[user_id].earned+=credit_cost;
			total_credits[user_id]-=credit_cost;
		}
	}
}
void maths_teacher(){		//used in freelancer's menu
	srand(time(0));			//to make sure random numbers generated are never same
	bool done=false;
	int choice;
	while(!done){			//done=false, not_of_done=true, returns true
		bool success=false;
		int n1=rand()%10;	//random numbers are always less than 10
		int n2=rand()%10;
		int n3=rand()%10;
		int n4=rand()%10;
		float answer;
		float reply;
		cout<<"***********************************"<<endl;
		cout<<"*      Welcome teacher            *"<<endl;
		cout<<"* 1. Discriminant calculation     *"<<endl;
		cout<<"* 2. Area of triangle             *"<<endl;
		cout<<"* 3. Area of quadrilateral        *"<<endl;
		cout<<"* 4. Area of circle               *"<<endl;
		cout<<"* 5. Number raised to a power n   *"<<endl;
		cout<<"* 6. Calculate sqrt of number     *"<<endl;
		cout<<"* 7. Distance between two points  *"<<endl;
		cout<<"* 8. Back to previous menu        *"<<endl;
		cout<<"***********************************"<<endl;
		cout<<"\nEnter a valid choice: "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				credit_reward=20;
				int a,b,c;
				a=n1;
				b=n2;
				c=n3;
				cout<<"a = "<<n1<<"\nb= "<<n2<<"\nc = "<<n3;
				cout<<"\nFind discriminant and write the closest value as answer:\n";
				cin>>reply;
				answer=((b*b)-(4*a*c));
				if(reply>answer-1&&reply<answer+1){
					cout<<"You have fed the student with the correct answer!\n";
					success=true;
				}
				else{
					cout<<"You don't have good source of knowledge!\n";
				}
				cout<<"Your answer was supposed to be: "<<answer<<endl;
				break;
			case 2:
				credit_reward=15;
				cout<<"Calculate the area of right angled triangle\n";
				cout<<"base = "<<n1<<"\nheight = "<<n2<<endl;
				cin>>reply;
				answer=(0.5*n1*n2);
				if(reply>answer-1&&reply<answer+1){
					cout<<"You have fed the student with the correct answer!\n";
					success=true;
				}
				else{
					cout<<"You don't have good source of knowledge!\n";
				}
				cout<<"Your answer was supposed to be: "<<answer<<endl;
				break;
			case 3:
				credit_reward=25;
				cout<<"Calculate the area of quadrilateral\n";
				cout<<"A = "<<n1<<"\nB = "<<n2<<"\nC = "<<n3<<"\nD = "<<n4<<endl;
				cin>>reply;
				answer=(0.5*((n1*n2)*(n2*n3)))+(0.5*((n1*n4)*(n4*n3)));
				if(reply>answer-1&&reply<answer+1){
					cout<<"You have fed the student with the correct answer!\n";
					success=true;
				}
				else{
					cout<<"You don't have good source of knowledge!\n";
				}
				cout<<"Your answer was supposed to be: "<<answer<<endl;
				break;
			case 4:
				credit_reward=15;
				cout<<"Calculate the area of cicrcle\n";
				cout<<"Radius = "<<n1<<"\n Value of pi = 3.14"<<endl;
				cin>>reply;
				answer=(3.14*(n1*n1));
				if(reply>answer-1&&reply<answer+1){
					cout<<"You have fed the student with the correct answer!\n";
					success=true;
				}
				else{
					cout<<"You don't have good source of knowledge!\n";
				}
				cout<<"Your answer was supposed to be: "<<answer<<endl;
				break;
			case 5:
				credit_reward=15;
				cout<<"Calculate the result of a number "<<n1<<" raised to power "<<n2<<endl;
				cin>>reply;
				answer=pow(n1,n2);
				if(reply==answer){
					cout<<"You have fed the student with correct answer!\n";
					success=true;
				}
				else{
					cout<<"You don't have good source of knowledge!\n";
				}
				cout<<"Your answer was supposed to be: "<<answer<<endl;
				break;
			case 6:
				credit_reward=10;
				cout<<"Caculate the square root of the number "<<n1<<endl;
				cin>>reply;
				answer=sqrt(n1);
				if(reply>answer-1&&reply<answer+1){
					cout<<"You have fed the student with the correct answer!\n";
					success=true;
				}
				else{
					cout<<"You don't have good source of knowledge!\n";
				}
				cout<<"Your answer was supposed to be: "<<answer<<endl;
				break;
			case 7:
				credit_reward=20;
				cout<<"What will be the distance between two points defined as:\n(x1,y1) = ("<<n1<<","<<n2<<")\n";
				cout<<"(x2,y2) = ("<<n3<<","<<n4<<")\n";
				cin>>reply;
				answer=sqrt(((n3-n1)*(n3-n1))+((n4-n2)*(n4-n2)));
				if(reply>answer-1&&reply<answer+1){
					cout<<"You have fed the student with the correct answer!\n";				
					success=true;
				}
				else{
					cout<<"You don't have good source of knowledge!\n";
				}
				cout<<"Your answer was supposed to be: "<<answer<<endl;
				break;
			case 8:
				done=true;
				break;
			default:
				cout<<"please enter a valid choice!"<<endl;
				break;
		}
		if(success==true){
			about_user[user_id].projects_completed+=1;
			about_user[user_id].earned+=credit_reward;
			total_credits[user_id]+=credit_reward;
			cout<<credit_reward<<" credits have been added to your account. Good bye!\n";
		}
		else
			about_user[user_id].projects_failed+=1;
	}
}
void english_teacher(){		//used in freelancer's menu
	srand(time(0));
	int n1=rand()%27;
	char vowels[]={'a','e','i','o','u'};
	bool done=false;	
	int ch_count=0;
	int choice;
	while(!done){
		bool success=false;
		char temp;
		char answer,question;
		cout<<"***********************************"<<endl;
		cout<<"*      Welcome teacher            *"<<endl;
		cout<<"* 1. Teach capital aplhabets      *"<<endl;
		cout<<"* 2. Teach small aplphabets       *"<<endl;
		cout<<"* 3. Teach vowels                 *"<<endl;
		cout<<"* 4. Answer the students          *"<<endl;
		cout<<"* 5. Back to previous menu        *"<<endl;
		cout<<"***********************************"<<endl;
		cout<<"\nEnter a valid choice: "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				credit_reward=10;
				cout<<"Teach aplhabes in capital order one after the other\n";
				for(int i=65;i<=90;i++){
					cin>>temp;
					if(temp!=i){
						cout<<"You missed the chain!\n";
						break;
					}
					else{
						ch_count++;
					}
				}
				if(ch_count==26){
					cout<<"You teach well. You have been rewarded!\n";
					success=true;
				}
				break;
			case 2:
				credit_reward=10;
				cout<<"Teach aplhabes in lower order one after the other\n";
				for(int i=97;i<=122;i++){
					cin>>temp;
					if(temp!=i){
						cout<<"You missed the chain!\n";
						break;
					}
					else{
						ch_count++;
					}
				}
				if(ch_count==26){
					cout<<"You teach well. You have been rewarded!\n";
					success=true;
				}
				break;
			case 3:
				credit_reward=10;
				cout<<"Teach vowels!, write them one after the othe\n";
				for(int i=0;i<5;i++){
					cin>>temp;
					if(temp!=vowels[i]){
						cout<<"You are missing the chain, write them in order!\n";
						break;
					}
					else{
						ch_count++;
					}
				}
				if(ch_count==5){
					cout<<"You teach well. credits have been added to your account\n";
					success=true;
				}
				break;
			case 4:
				credit_reward=10;
				cout<<"Answer the students\n";
				question=n1+66;
				cout<<"what alphabet comes after "<<question<<" ? \n";
				cin>>temp;
				answer=question+1;
				if(temp==answer){
					cout<<"Exactly! you are right\n";
					success=true;	
				}
				else{
					cout<<"You need a refresher course!\n";
				}
				break;
			case 5:
				done=true;
				break;
			default:
				cout<<"Invalid choice!\n";
		}
		if(success==true){
			cout<<credit_reward<<" credits have been added to your account, good luck\n";
			total_credits[user_id]+=credit_reward;
			about_user[user_id].projects_completed+=1;
			about_user[user_id].earned+=credit_reward;
		}
		else
			about_user[user_id].projects_failed+=1;
	}
}
void gk_teacher(){		//used in freelancer's menu
	int success;
	string reply;
	int num=rand()%5;
	cout<<"Student is asking a question:\n";
	switch(num){
		case 0:
			credit_reward=15;
			cout<<"what is the total area of Pakistan in square kilometers?\n";
			cin>>reply;
			if(reply=="796096"){
				cout<<"Your have fed the student with correct answer! well done.\n";
				success=0;
			}
			else{
				cout<<"Sorry you do not have a good source of knowledge.\n";
				success=1;
			}
			break;
		case 1:
			credit_reward=15;
			cout<<"which year did china get independance\n";
			cin>>reply;
			if(reply=="1948"){
				cout<<"Your have fed the student with correct answer! well done.\n";
				success=0;
			}
			else{
				cout<<"Sorry you do not have a good source of knowledge.\n";
				success=1;
			}
			break;
		case 2:
			credit_reward=10;
			cout<<"Who is current prime minister of Pakistan?\n";
			cout<<"Specify only the first and last name without white space in lower case\n";
			cin>>reply;
			if(reply=="imrankhan"){
				cout<<"Your have fed the student with correct answer! well done.\n";
				success=0;
			}
			else{
				cout<<"Sorry you do not have a good source of knowledge.\n";
				success=1;
			}
			break;
		case 3:
			credit_reward=20;
			cout<<"Roza became complulsory in which year?\n";
			cout<<"specify A.D year in numerical form\n";
			cin>>reply;
			if(reply=="623"){
				cout<<"Your have fed the student with correct answer! well done.\n";
				success=0;
			}
			else{
				cout<<"Sorry you do not have a good source of knowledge.\n";
				success=1;
			}
			break;
		case 4:
			credit_reward=15;
			cout<<"How many days in the month of October?\n";
			cin>>reply;
			if(reply=="31"){
						cout<<"Your have fed the student with correct answer! well done.\n";
				success=0;
			}
			else{
				cout<<"Sorry you do not have a good source of knowledge.\n";
				success=1;
			}
			break;
		default:
			cout<<"Invalid choice!\n";
			break;
	}
	if(success==0){
		cout<<"Contract completed successfully!\n";
		total_credits[user_id]+=credit_reward;
		cout<<credit_reward<<" credits have been added to your account\n";
		about_user[user_id].projects_completed+=1;
		about_user[user_id].earned+=credit_reward;
	}
	else
			about_user[user_id].projects_failed+=1;
}
void help_center(){
   	system("cls");
  	cout<<"\n\n\n\t\tAbout this project\n";
	cout<<"* Welcome to 21022 and 21331 collaboration center\n";
	cout<<"* This program was written to provide a simulation of freelancing system\n";
    cout<<"* This program contains two main areas:\n\tClient interface\n\tFreelancer interface\n";
	cout<<"* We developed smart algorithms to handle user data and make registering and login";
	cout<<" process work accurately and error free\n";
	cout<<"* We have utilized all the statements that were taught during the course\n";
	system("pause");
	system("cls");
	cout<<"\n\n\t\tLogin and register\n";
	cout<<"* After you run this program the first thing you need to do is register for either client or freelancer\n";
	cout<<"* Once you are registered you need to login with your username and password\n";
	cout<<"* If your username and password match then you will be redirected to your registered account\n";
	system("pause");
	system("cls");
	cout<<"\n\n\t\tClient Interface\n";
	cout<<"* If you have registered as a client and you login to your account, you will be given 100 free credits\n";
	cout<<"* Each time a client hires a freelancer some credits are deducted from his account\n";
	cout<<"* When client's credits reaches zero client will not be able to hire anymore\n";
	cout<<"* We also added a function which replenishes client's credits in case they reach zero\n";
	system("pause");
	system("cls");
	cout<<"\n\n\t\tFreelancer Interface\n";
	cout<<"* You are redirected to client menu upon your login\n";
	cout<<"* Initially a freelancer has zero credits\n";
	cout<<"* Freelancer credits increase as he solves the puzzles\n";
	system("pause");
	system("cls");
}
int main(){		//t'all starts from here
	string *arr;
	arr=user_type;
	int count=0;
	bool done=false;
	while(!done){
		cout<<"****************************************"<<endl;
		cout<<"*           Main Menu                  *"<<endl;
		cout<<"* 1. Login                             *"<<endl;
		cout<<"* 2. Register as a client              *"<<endl;
		cout<<"* 3. Register as a freelancer          *"<<endl;
		cout<<"* 4. Show registered users             *"<<endl;
		cout<<"* 5. Clear Screen                      *"<<endl;
		cout<<"* 6. Project Manual                    *"<<endl;
		cout<<"* 7. Exit                              *"<<endl;
		cout<<"****************************************"<<endl;
		cout<<"\nEnter your choice:\n";
		int main_choice;
		cin>>main_choice;
		switch(main_choice){
			case 1:
				login();
				if(registered_user==0){
					switch(user_pointer){
						case 0:
							client();
							break;
						case 1:
							freelance();
							break;
					}
				}
				break;		
			case 2:
				register_client();
				break;
			case 3:
				register_freelancer();
				break;
			case 4:
				system("cls");
				cout<<"Total users: "<<current_user<<endl;
				for(int i=0;i<current_user;i++){
					cout<<"user name: "<<user[i][0]<<endl;
					cout<<"user type: "<<*(arr+i)<<endl<<endl;
				}
				break;
			case 5:
				system("cls");
				break;
			case 6:
				help_center();
				break;
			case 7:
				done=true;
				break;
			default:
				cout<<"invalid choice!\n";
				break;
		}
	}
}
