#include <iostream>
#include <stdlib.h>





int number_of_books = 0;
int number_of_members = 0;

struct Books
{
	int code_book, price, copies;
	char name_book[30], author[30];
}book[1000];

struct Members
{
	int members_code, phone;
	char member_name[30], addres[30];

}member[1000];


void add_book();
void add_member();
void list_books();
void list_member();
void modify_book();
void delete_book();
void modify_member();
void delet_member();
void edit();




int main() {

	int pick;
	do {
		system("cls");
		std::cout << "BOOOK LIBRAY\n\n\n1. ADD NEW BOOK\n2. ADD NEW MEMBER\n3. LIST OF BOOKS\n4. LIST OF MEMBERS\n5. EDIT\n0. QUIT.\n";
		std::cout << "\n\nEnter your choice : ";
		std::cin >> pick;

		switch (pick)
		{
		case 1:
			add_book();
			break;

		case 2:
			add_member();
			break;
		case 3:
			list_books();
			break;

		case 4:
			list_member();
			break;

		case 5:
			edit();
			break;

		default:
			break;
		}


	} while (pick != 0);

}



void add_book() {
	char add_more;
	system("cls");
	bool duplicated = 0;
	std::cout << "ADDING A BOOK\n\nBook code : ";
	std::cin >> book[number_of_books].code_book;
	for (int i = 0; i < number_of_books; i++) {
		if (book[number_of_books].code_book == book[i].code_book) {
			duplicated = 1;
			break;
		}
	}
	if (!duplicated) {
		std::cout << "\nBook name : ";
		std::cin >> book[number_of_books].name_book;
		std::cout << "\nAuthor name : ";
		std::cin >> book[number_of_books].author;
		std::cout << "\nNumber of copies : ";
		std::cin >> book[number_of_books].copies;
		std::cout << "\nPrice : ";
		std::cin >> book[number_of_books].price;
		number_of_books++;
		std::cout << "\nTHE NEW BOOK HAS BEEN SAVED";

	}
	else { std::cout << "\nThe book code already exists."; }

	std::cout << "\n\nEnter (Y) to add another book  : ";
	std::cin >> add_more;
	if (add_more == 'y' || add_more == 'Y') {
		add_book();
	}
}


void add_member() {
	char add_more;
	system("cls");
	bool duplicated = 0;
	std::cout << "ADDING A MEMBER\n\nMember code : ";
	std::cin >> member[number_of_members].members_code;
	for (int i = 0; i < number_of_members; i++) {
		if (member[number_of_members].members_code == member[i].members_code) {
			duplicated = 1;
			break;
		}
	}
	if (!duplicated) {
		std::cout << "\nName : ";
		std::cin >> member[number_of_members].member_name;
		std::cout << "\nPhone number : ";
		std::cin >> member[number_of_members].phone;
		std::cout << "\nAddress : ";
		std::cin >> member[number_of_members].addres;
		number_of_members++;
		std::cout << "\nTHE NEW MEMBER HAS BEEN SAVED";

	}
	else { std::cout << "\nThe member code already exists."; }

	std::cout << "\n\Enter (y) to add another member : ";
	std::cin >> add_more;
	if (add_more == 'y' || add_more == 'Y') {
		add_member();
	}
}




void list_books() {
	char done;
	system("cls");
	std::cout << "CODE , BOOK NAME , AUTHOR , COPIES , PRICE \n";

	for (int i = 0;i < number_of_books;i++) {
		std::cout << book[i].code_book << " , " << book[i].name_book << " , " << book[i].author << " , " << book[i].copies << " , " << book[i].price << std::endl;

	}
	std::cout << "\n ENTER ANYRHING TO EXIT THE LIST ";
	std::cin >> done;
}


void list_member() {
	char done;
	system("cls");
	std::cout << "CODE , MEMbER NAME , PHONE , ADDRES\n";

	for (int i = 0;i < number_of_members;i++) {
		std::cout << member[i].members_code << " , " << member[i].member_name << " , " << member[i].phone << " , " << member[i].addres << std::endl;

	}
	std::cout << "\n ENTER ANYRHING TO EXIT THE LIST ";
	std::cin >> done;
}




void edit() {
	
	int pick;

	do {
		system("cls");
		std::cout << "1. modify book\n2. delete_book \n3. modify member\n4. delet_member\n0. QUIT EDIT";
		std::cout << "\n\nEnter your choice : ";
		std::cin >> pick;

		switch (pick)
		{
		case 1:
			modify_book();
			break;
		case 2:
			delete_book();
			break;
		case 3:
			modify_member();
			break;
		case 4:
			delet_member();
			break;

		default:
			break;
		}
	} while (pick != 0);

}




void modify_book() {
	system("cls");
	int modfiy_code;
	int found = 0;
	char again;

	std::cout << "MODIFY BOOK\n\nEnter book code to modify : ";
	std::cin >> modfiy_code;

	for (int i = 0;i < number_of_books; i++) {
		if (book[i].code_book == modfiy_code) {
			std::cout << "book code : " << book[i].code_book << "\nbook name : " << book[i].name_book << "\nauthor : " << book[i].author << "\nprice : " << book[i].price << "\ncopies : " << book[i].copies;
			std::cout << "\nBook name : ";
			std::cin >> book[i].name_book;
			std::cout << "\nAuthor name : ";
			std::cin >> book[i].author;
			std::cout << "\nNumber of copies : ";
			std::cin >> book[i].copies;
			std::cout << "\nPrice : ";
			std::cin >> book[i].price;
			std::cout << "\nTHE CHANGES HAVE BEEN SAVED\n";
			found = 1;

		}
	}
	if (found == 0) {
		std::cout << "the book code you enterd is wrong \n";
	}
	std::cout << "\n\Enter (y) to modify another book : ";
	std::cin >> again;
	if(again == 'y' || again == 'Y'){ modify_book();}
}



void modify_member() {
	system("cls");
	int modfiy_code;
	int found = 0;
	char again;
	std::cout << "MODIFY MEMBER\n\nEnter member's code to modify : ";
	std::cin >> modfiy_code;

	for (int i = 0;i < number_of_members; i++) {
		if (member[i].members_code == modfiy_code) {
			std::cout << "Member code : " << member[i].members_code << "\nMember name : " << member[i].member_name << "\nPhone number : " << member[i].phone << "\nAddress : " << member[i].addres;
			std::cout << "\nName : ";
			std::cin >> member[i].member_name;
			std::cout << "\nPhone number : ";
			std::cin >> member[i].phone;
			std::cout << "\nAddress : ";
			std::cin >> member[i].addres;
			std::cout << "\nTHE NEW MEMBER HAS BEEN SAVED";
			found = 1;

		}
	}
	if (found == 0) {
		std::cout << "the member code you enterd is wrong \n";
	}
	std::cout << "\n\Enter (y) to modify another member : ";
	std::cin >> again;
	if (again == 'y' || again == 'Y') { modify_member(); }
}


void delete_book() {
	system("cls");
	int modfiy_code;
	int found = 0;
	char again;
	std::cout << "DELETE BOOK\n\nEnter the book code to delete : ";
	std::cin >> modfiy_code;
	for (int i = 0;i < number_of_books; i++) {
		if (book[i].code_book == modfiy_code) {
			number_of_books--;
			for (int j = i; j < number_of_books;j++) {
				book[j].code_book = book[j + 1].code_book;
				strcpy_s(book[j].name_book,sizeof(book[j].name_book), book[j + 1].name_book);
				strcpy_s(book[j].author, sizeof(book[j].author), book[j + 1].author);
				book[j].copies = book[j + 1].copies;
				book[j].price = book[j + 1].price;
			}
			
			std::cout << "\nTHE BOOK HAS BEEN DELETED\n";
			found = 1;
			break;
		}
	}
	if (found == 0) {
		std::cout << "the book code you enterd is wrong \n";
	}
	std::cout << "\n\Enter (y) to delete another book : ";
	std::cin >> again;
	if (again == 'y' || again == 'Y') { delete_book(); }
}


void delet_member() {
	system("cls");
	int modfiy_code;
	int found = 0;
	char again;
	std::cout << "DELETE MEMBER\n\nEnter the member's code to delete : ";
	std::cin >> modfiy_code;
	for (int i = 0;i < number_of_members; i++) {
		if (member[i].members_code == modfiy_code) {
			number_of_members--;
			for (int j = i; j < number_of_members;j++) {
				member[j].members_code = member[j + 1].members_code;
				strcpy_s(member[j].member_name, sizeof(member[j].member_name), member[j + 1].member_name);
				strcpy_s(member[j].addres, sizeof(member[j].addres), member[j + 1].addres);
				member[j].phone = member[j + 1].phone;
				
			}

			std::cout << "\nTHE MEMBER HAS BEEN DELETED\n";
			found = 1;
			break;
		}
	}
	if (found == 0) {
		std::cout << "the member code you enterd is wrong\n";
	}
	std::cout << "\n\Enter (y) to delete another member : ";
	std::cin >> again;
	if (again == 'y' || again == 'Y') { delet_member(); }
}