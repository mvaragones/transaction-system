#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

#define clear system("CLS")


void gotoxy (int x, int y)
{HANDLE hConsoleOutput;
COORD dwCursorPosition;
dwCursorPosition.X=x;
dwCursorPosition.Y=y;
hConsoleOutput=GetStdHandle (STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}



void main_menu();
void mod(string &item, int &price);
void atomizer(string &item, int &price);
void battery(string &item, int &price);
void charger(string &item, int &price);
void juice(string &item, int &price);
void cart(string item, int price, char &ans);
void payment_method(int price, int &balance, int &initial_amount);
void askAgain(char &option);
int bank(int initial_amount, int &total_balance);
int input();
int category_input();


int main()
{
	system("title Transaction Based System");
	system("mode con: cols=88 lines=30");
	int choice,price,balance=10000,total_balance=0, initial_amount=0;
	string item;
	char ans,option;
	

doon:
		clear;
		main_menu();
		choice = category_input();
		switch(choice){
			case 1:
				clear;
				mod(item, price);
				cart(item, price, ans);
				if(ans=='Y'){
					payment_method(price,balance,initial_amount);
					total_balance=bank(initial_amount,total_balance);
					askAgain(option);	
					if (option=='Y'){
						goto doon;
					}
					else if(option=='N'){
						exit(0);
					}
					else{
						cout<<"Invalid Input";
					}
				}
				else if(ans=='N'){
					goto doon;
				}
				else{
					cout<<"Invalid Input";
				}
				
				break;
			case 2:
				clear;
				atomizer(item, price);
				cart(item,price,ans);
				if(ans=='Y'){
					payment_method(price,balance,initial_amount);
					total_balance=bank(initial_amount,total_balance);
					askAgain(option);	
					if (option=='Y'){
						goto doon;
					}
					else if(option=='N'){
						exit(0);
					}
					else{
						cout<<"Invalid Input";
					}
				}
				else if(ans=='N'){
					goto doon;
				}
				else{
					cout<<"Invalid Input";
				}
				break;
			case 3:
				clear;
				battery(item, price);
				cart(item,price,ans);
				if(ans=='Y'){
					payment_method(price,balance,initial_amount);
					total_balance=bank(initial_amount,total_balance);
					askAgain(option);	
					if (option=='Y'){
						goto doon;
					}
					else if(option=='N'){
						exit(0);
					}
					else{
						cout<<"Invalid Input";
					}
				}
				else if(ans=='N'){
					goto doon;
				}
				else{
					cout<<"Invalid Input";
				}
				break;
			case 4:
				clear;
				charger(item, price);
				cart(item,price,ans);
				if(ans=='Y'){
					payment_method(price,balance,initial_amount);
					total_balance=bank(initial_amount,total_balance);
					askAgain(option);	
					if (option=='Y'){
						goto doon;
					}
					else if(option=='N'){
						exit(0);
					}
					else{
						cout<<"Invalid Input";
					}
				}
				else if(ans=='N'){
					goto doon;
				}
				else{
					cout<<"Invalid Input";
				}
				break;
			case 5:
				clear;
				juice(item, price);
				cart(item,price,ans);
				if(ans=='Y'){
					payment_method(price,balance,initial_amount);
					total_balance=bank(initial_amount,total_balance);
					askAgain(option);	
					if (option=='Y'){
						goto doon;
					}
					else if(option=='N'){
						exit(0);
					}
					else{
						cout<<"Invalid Input";
					}
				}
				else if(ans=='N'){
					goto doon;
				}
				else{
					cout<<"Invalid Input";
				}
				break;
			case 0:
				goto doon;
				break;
			case 6:
				int counter=0;
				overhere:
				clear;
				string username,pass;
				
				gotoxy(30,4);
				cout<<"ADMIN SECTION";
				gotoxy(30,6);
				cout<<"Enter username: ";
				cin>>username;
				gotoxy(30,7);
				cout<<"Enter password: ";
				cin>>pass;
				if(username != "markadmin" || pass != "1234"){
					gotoxy(30,8);
					cout<<"Invalid Credentials";
					counter++;
					if(counter==3){
					clear;
					gotoxy(30,15);
					cout<<"You have been kicked from the admin section";
					sleep(3);
					goto doon;
				}
					sleep(3);
					goto overhere;
				}
				
				else{
					action:
					int num,withdraw;
					gotoxy(30,10);
					cout<<">> 1. Check Balance";
					gotoxy(30,11);
					cout<<">> 2. Withdraw";
					gotoxy(30,12);
					cout<<"Action: ";
					do{
						gotoxy(37,12);cout<<"                                           ";
						gotoxy(37,12);
						cin>>num;
					}while(num<1 || num>2);
					
					switch(num){
						case 1:
							gotoxy(30,14);
							cout<<"Your balance is: "<<total_balance;
							break;
						case 2:
							gotoxy(30,14);
							cout<<"Your balance is: "<<total_balance;
							gotoxy(30,15);
							cout<<"Enter amount to be withdrawn: ";
							cin>>withdraw;
							if (total_balance > withdraw || total_balance==withdraw){
								total_balance = total_balance - withdraw;
								gotoxy(30,16);
								cout<<"Your new balance is: "<<total_balance;
							}
							else if(total_balance < withdraw){
								gotoxy(30,16);
								cout<<"Insufficient amount";
							}
							
							break;
					}
					overthere:
					gotoxy(30,18);
					cout<<">> 0. Back to home";
					gotoxy(30,19);
					cout<<">> 1. Select another action";
					gotoxy(30,20);
					cout<<"Choice: ";
					cin>>num;
					if(num==0){
						goto doon;
					}
					else if (num == 1){
						for(int i=10; i<=20; i++){
							gotoxy(30,i);cout<<"                                                         ";
						}
						goto action;
						
					}
					else{
						goto overthere;
					}	
				}
				break;
		}

	
	getch();
}



void main_menu(){
	clear;
	char welcome1[50]="EM BI VAPE SHOP";
	gotoxy(24,2);
	for(int i=0; i<strlen(welcome1); i++){
		cout<<" "<<welcome1[i];
		Sleep(100);
	}
	gotoxy(30,4);
	cout<<"Choose category";
	gotoxy(30,6);
	cout<<">> 1. Mod";
	Sleep(200);
	gotoxy(30,8);
	cout<<">> 2. Atomizer";
	Sleep(200);
	gotoxy(30,10);
	cout<<">> 3. Battery";
	Sleep(200);
	gotoxy(30,12);
	cout<<">> 4. Charger";
	Sleep(200);
	gotoxy(30,14);
	cout<<">> 5. Juice";
	Sleep(200);
	gotoxy(30,16);
	cout<<">> 6. Admin Section";
	Sleep(200);
	gotoxy(30,18);
	
	
	cout<<"Choice: ";
}

void mod(string &item, int &price){
	int choice;
	string menu[9][2]={	">> 1. Drag x plus pro", "1300",
						">> 2. Asmodus lustro", "850",
						">> 3. Asmodus minikin", "850" ,
						">> 4. Aegis Legend V2", "1600",
						">> 5. Aegis Solo", "1500",
						">> 6. Jellybox mod", "1000",
						">> 7. M100", "1500",
						">> 8. S100", "1300",
						">> 9. Aegis x", "1800"};
	int row=2;
	gotoxy(20,0);cout<<"Product Name:";
	gotoxy(55,0);cout<<"Price:";
	for(int i=0; i<9; i++){
		gotoxy(20, row);
		for(int c=0; c<2; c++){
			if(i>5 && i!=8){
				cout<<menu[i][c]<<"\t\t\t\t";
				Sleep(50);	
			}
			else if (i>3){
				cout<<menu[i][c]<<"\t\t\t";	
				Sleep(50);	
			}
			
			else{
				cout<<menu[i][c]<<"\t\t";
				Sleep(50);	
			}
			
			
		}
		
		gotoxy(5, row);
		
		row += 2;
	}
	gotoxy(5,25);
	cout<<"Select an item: ";
	do{
		gotoxy(20,25);cout<<"                      ";
		gotoxy(20,25);
		cin>>choice;	
	}while(choice<1||choice>9);
	
	switch(choice){
		case 1:
			item = "Drag x plus pro";
			price = 1300;
			break;
		case 2:
			item = "Asmodus lustro";
			price = 850;
			break;
		case 3:
			item = "Asmodus minikin";
			price = 850;
			break;
		case 4:
			item = "Aegis Legend V2";
			price = 1600;
			break;
		case 5:
			item = "Aegis Solo";
			price = 1500;
			break;
		case 6:
			item = "Jellybox mod";
			price = 1000;
			break;
		case 7:
			item = "M100";
			price = 1500;
			break;
		case 8:
			item = "S100";
			price = 1300;
			break;
		case 9:
			item = "Aegis x";
			price = 1800;
			break;
		default:
			item = "Invalid Item";
			break;
	}
}

void atomizer(string &item, int &price){
	int choice;
	string menu[5][2]={	">> 1. Avocado 22 Special Edition", "1500",
						">> 2. NCR Nicotine Reinforcer RDA", "900",
						">> 3. Dead Rabbit", "350" ,
						">> 4. Loop RDA", "1400",
						">> 5. Head V2 RDA", "250"};
	int row=3;
	gotoxy(15,1);cout<<"Product Name:";
	gotoxy(55,1);cout<<"Price:";
	for(int i=0; i<5; i++){
		gotoxy(15, row);
		for(int c=0; c<2; c++){
			if(i>2 && i!=4){
				cout<<menu[i][c]<<"\t\t\t\t";
				Sleep(50);	
			}
			else if (i>1){
				cout<<menu[i][c]<<"\t\t\t";	
				Sleep(50);	
			}
			
			else if (i==1){
				cout<<menu[i][c]<<"\t";
				Sleep(50);	
			}
			else{
				cout<<menu[i][c]<<"\t\t";
				Sleep(50);
			}
			
			
		}
		
		gotoxy(5, row);
		
		row += 2;
	}
	gotoxy(5,25);
	cout<<"Select an item: ";
	do{
		gotoxy(20,25);cout<<"                      ";
		gotoxy(20,25);
		cin>>choice;	
	}while(choice<1||choice>5);
	switch(choice){
		case 1:
			item = "Avocado 22 Special Edition";
			price = 1500;
			break;
		case 2:
			item = "NCR Nicotine Reinforcer RDA";
			price = 900;
			break;
		case 3:
			item = "Dead Rabbit";
			price = 350;
			break;
		case 4:
			item = "Loop RDA";
			price = 1400;
			break;
		case 5:
			item = "Head V2 RDA";
			price = 250;
			break;
		
		default:
			item = "Invalid Item";
			break;
	}
}

void battery(string &item, int &price){
	int choice;
	string menu[5][2]={	">> 1. Cylaid blue", "300",
						">> 2. Cylaid purple", "300",
						">> 3. Lg Choco", "300" ,
						">> 4. Enook", "450",
						">> 5. Toha", "450"};
	int row=3;
	gotoxy(15,1);cout<<"Product Name:";
	gotoxy(55,1);cout<<"Price:";
	for(int i=0; i<5; i++){
		gotoxy(15, row);
		for(int c=0; c<2; c++){
			if(i<=1){
				cout<<menu[i][c]<<"\t\t\t";
				Sleep(50);
			}
			else{
				cout<<menu[i][c]<<"\t\t\t\t";
				Sleep(50);
			}
			
		}
		
		gotoxy(5, row);
		
		row += 2;
	}
	gotoxy(5,25);
	cout<<"Select an item: ";
	do{
		gotoxy(20,25);cout<<"                      ";
		gotoxy(20,25);
		cin>>choice;	
	}while(choice<1||choice>5);
	switch(choice){
		case 1:
			item = "Cylaid blue";
			price = 300;
			break;
		case 2:
			item = "Cylaid purple";
			price = 300;
			break;
		case 3:
			item = "Lg Choco";
			price = 300;
			break;
		case 4:
			item = "Enook";
			price = 450;
			break;
		case 5:
			item = "Toha";
			price = 450;
			break;
		
		default:
			item = "Invalid Item";
			break;
	}
}

void charger(string &item, int &price){
	int choice;
	string menu[1][2]={">> 1. Enook charger dual bay","250"};
	int row=3;
	gotoxy(15,1);cout<<"Product Name:";
	gotoxy(55,1);cout<<"Price:";
	for(int i=0; i<1; i++){
		gotoxy(15, row);
		for(int c=0; c<2; c++){
			if(i<=1){
				cout<<menu[i][c]<<"\t\t\t";
				Sleep(50);
			}
			else{
				cout<<menu[i][c]<<"\t\t\t\t";
				Sleep(50);
			}
			
		}
		
		gotoxy(5, row);
		
		row += 2;
	}
	gotoxy(5,25);
	cout<<"Select an item: ";
	do{
		gotoxy(20,25);cout<<"                      ";
		gotoxy(20,25);
		cin>>choice;	
	}while(choice<1||choice>1);
	switch(choice){
		case 1:
			item = "Enook charger dual bay";
			price = 250;
			break;
		default:
			item = "Invalid Item";
			break;
	}
}

void juice(string &item, int &price){
	int choice;
	string menu[4][2]={	">> 1. Dr cloud 100ml", "200",
						">> 2. Katas ni Dogie 60ml", "180",
						">> 3. Salt nic Collection 30ml", "100" ,
						">> 4. Cheese cake 100ml", "200",
						};
	int row=3;
	gotoxy(15,1);cout<<"Product Name:";
	gotoxy(55,1);cout<<"Price:";
	for(int i=0; i<4; i++){
		gotoxy(15, row);
		for(int c=0; c<2; c++){
			if(i==0||i==3){
				cout<<menu[i][c]<<"\t\t\t";
				Sleep(50);
			}
			else{
				cout<<menu[i][c]<<"\t\t";
				Sleep(50);
			}
			
		}
		
		gotoxy(5, row);
		
		row += 2;
	}
	gotoxy(5,25);
	cout<<"Select an item: ";
	do{
		gotoxy(20,25);cout<<"                      ";
		gotoxy(20,25);
		cin>>choice;	
	}while(choice<1||choice>5);
	switch(choice){
		case 1:
			item = "Dr cloud 100ml";
			price = 200;
			break;
		case 2:
			item = "Katas ni Dogie 60ml";
			price = 180;
			break;
		case 3:
			item = "Salt nic Collection 30ml";
			price = 100;
			break;
		case 4:
			item = "Cheese cake 100ml";
			price = 200;
			break;	
		default:
			item = "Invalid Item";
			break;
	}
}

void cart(string item, int price, char &ans){
	
	clear;
	gotoxy(20,4);
	cout<<"Item selected: "<<item<<endl;
	gotoxy(20,5);
	cout<<"Price: "<<price<<endl;
	gotoxy(20,7);
	cout<<"Confirm Purchase? [Y/N] ";
	ans = toupper(getch());
	
}

void payment_method(int price, int &balance, int &initial_amount){
	int payment, amount, change, deficit;
	int credit, PIN, count=0;
	bool isValid=true;
	string promo;
	char ans;
	repeat:
	gotoxy(20,7);cout<<"                                                       ";
	gotoxy(20,7);
	
	cout<<"Do you have a promo code? [Y/N]";
	ans = toupper(getch());
	if (ans=='Y'){
		gotoxy(20,8);
		cout<<"Enter promo code: ";
		cin>>promo;
		if (promo == "markadmin"){
			price = price-(price*0.50);
		}
		else if (promo=="20percent"){
			price = price-(price*0.20);
		}
		else if(promo == "10percent"){
			price = price-(price*0.10);
		}
		else{
			gotoxy(20,9);
			cout<<"Invalid Promo Code";
			isValid=false;
		}
		if(isValid==true){
			gotoxy(20,9);
			cout<<"Your new price is "<<price;	
		}
		else{
			sleep(3);
			goto skip;
		}
		
	}
	else if(ans=='N'){
		skip:
		gotoxy(20,8);
		cout<<"Your current price is "<<price;
	}
	else{
		goto repeat;
	}
	dito:
	gotoxy(27,13);cout<<"                                                           ";
	gotoxy(20,15);cout<<"                                                           ";
	gotoxy(20,16);cout<<"                                                           ";
	gotoxy(20,17);cout<<"                                                           ";
	gotoxy(20,18);cout<<"                                                           ";
	gotoxy(20,10);
	cout<<"Choose payment method:";
	gotoxy(20,11);
	cout<<">> 1. Cash";
	gotoxy(20,12);
	cout<<">> 2. Credit Card";
	
	gotoxy(20,13);
	cout<<"Choice: ";
	cin>>payment;
	gotoxy(20, 15);
	switch(payment){
		case 1:
			cout<<"Enter amount: ";
			cin>>amount;
			initial_amount=amount;
			if(amount>price){
				change = amount-price;
				gotoxy(20,17);
				cout<<"Thank you for your purchase here is your change: "<<change;
			}
			else if(amount<price){
				deficit = price-amount;
				gotoxy(20,17);
				cout<<"Oops! Insufficient amount you need "<<deficit<<" more";
				gotoxy(20,18);
				cin>>amount;
				initial_amount=initial_amount + amount;	
			here:
				
				if(amount>deficit){
					gotoxy(20,17);cout<<"                                                                               ";
					gotoxy(20,18);cout<<"                                                     ";
					gotoxy(20,17);
					cout<<"Thank you for you purchase here is your change: "<<amount-deficit;
					initial_amount = initial_amount + deficit;
				}
				else if(amount<deficit){
					deficit = deficit-amount;
					gotoxy(20,17);cout<<"                                                                               ";
					gotoxy(20,17);
					cout<<"Oops! Insufficient amount you need "<<deficit<<" more";
					gotoxy(20,18);cout<<"                                                     ";
					gotoxy(20,18);
					cin>>amount;
					initial_amount = initial_amount + amount;
					goto here;
				}
				else{
					gotoxy(20,17);cout<<"                                                                               ";
					gotoxy(20,18);cout<<"                                                     ";
					gotoxy(20,17);
					cout<<"Thank you for your purchase!";
					
				}
			}
			else{
				gotoxy(20,17);
				cout<<"Thank you for your purchase!";
				initial_amount = amount;
			}
			break;
		case 2:
			cout<<"Enter Credit Card number: ";
			cin>>credit;
			do{
			gotoxy(20,16);cout<<"                                                            ";
			gotoxy(20,16);
			cout<<"Enter PIN (We don't save your PIN):";
			cin>>PIN;
			count++;
			if(count==3){
				gotoxy(20,17);cout<<"                                                            ";
				gotoxy(20,17);
				cout<<"Invalid Credentials. Choose another Payment Method";
				sleep(2);
				goto dito;
			}
			}while(PIN != 1234);
			
			
			if (balance>price){
				balance = balance - price;
				initial_amount = price;
				gotoxy(20,17);cout<<"                                                                               ";
				gotoxy(20,17);
				cout<<"Thank you for your purchase!";
				gotoxy(20,18);cout<<"                                                                               ";
				gotoxy(20,18);
				cout<<"Your new balance is: "<<balance;
			}
			else if (balance<price){
				gotoxy(20,17);cout<<"                                                                               ";
				gotoxy(20,17);
				cout<<"Oops! Insufficient amount try another payment method";
				sleep(5);
				goto dito;
			}
		
	}	
}

int bank(int initial_amount, int &total_balance){
	total_balance += initial_amount;
	return total_balance;
}


void askAgain(char &option){
	
	gotoxy(20,19);
	cout<<"Go back to main menu? [Y/N]";
	option = toupper(getch());

}



int category_input(){
	int choice;
	do{
		gotoxy(38,18);cout<<"              ";
		gotoxy(38,18);
		cin>>choice;	
	}while(choice<0 || choice>6);
	
	return choice;
}
