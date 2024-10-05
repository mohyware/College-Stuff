#include "Browse.h"
Browse::Browse(): mn(new Manger()) , at(mn->get_reference_tree()) {}
Browse::~Browse() {
	delete at;
	delete mn;
}

Manger* Browse::get_reference_manger() { return mn; }

void Browse::LIKE(int code, std::string type, std::string desc, std::string hashtag) {
	Activity act;

	act.type = type;

	act.description = desc;

	if (at->search(code, at->ROOT())->Activities.isFull())
		at->search(code, at->ROOT())->Activities.dequeue();

	at->search(code, at->ROOT())->Activities.enqueue(act);
	at->search(code, at->ROOT())->act.Like++;

}

void Browse::COMMENT(int code, std::string type, std::string desc, std::string hashtag) {
	Activity act;
	act.type = type;
	act.description = desc;

	Hashtags[hashtag]++;

	AVLNode* temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.Comment++;
}

void Browse::SHARE(int code, std::string type, std::string desc, std::string hashtag) {
	Activity act;
	act.type = type;
	act.description = desc;

	Hashtags[hashtag]++;

	AVLNode* temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.Share++;
}

void Browse::FOLLOW(int code, std::string type, std::string desc, std::string hashtag) {
	Activity act;
	int Code;
	
	act.type = type;

	std::string username = desc;
	Code = at->hashCode(username);

	AVLNode* temp = at->search(Code, at->ROOT());
	AVLNode* cur_user = at->search(code, at->ROOT());

	// Invalid user
	if (!temp) {
		std::cout << "-> user name does not exist." << std::endl;
		return;
	}

	// Follow himself
	if (Code == code) {
		std::cout << "-> You cannot follow yourself." << std::endl;
		return;
 	}

	// Check if he followed the same user twice
	if (!cur_user->user->checkFollowes(Code)) {
		std::cout << "-> You are already following this user ." << std::endl;
		return;
	}

	std::cout << "-> Follow completed successfully (^_^)." << std::endl;
	cur_user->user->pushFollowed(Code);

	act.description = "Followed [ " + username + " ].";
	temp->user->increase_follower();

	temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.Follow++;
}

void Browse::CREATE_POST(int code, std::string type, std::string desc, std::string hashtag) {
	Activity act;
	act.type = type;
	act.description = desc;

	Hashtags[hashtag]++;

	//AVLNode* temp = ;
	std::cout << "\n" << at->search(code, at->ROOT())->Activities.isFull()<<"cnt="<< at->search(code, at->ROOT())->Activities.cnt << "size===" << at->search(code, at->ROOT())->Activities.getSize() << "\n";

	if (at->search(code, at->ROOT())->Activities.isFull())
		at->search(code, at->ROOT())->Activities.dequeue();

	at->search(code, at->ROOT())->Activities.enqueue(act);
	at->search(code, at->ROOT())->act.Create_Post++;
	}


void Browse::VIEW_PROFILE(int code) {
	Activity act;
	std::string userName;

	act.type = "View profile";

	std::cout << "Search user name : ";
	getline(std::cin, userName);

	AVLNode* temp = at->search(at->hashCode(userName), at->ROOT());

	if (!temp) {
		std::cout << "-> user name does not exist." << std::endl;
		return;
	}
	
	system("cls");

	auto color = [&](int cnt)-> void {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnt);
    };

	color(6);
	std::cout << " ==========================  " << std::endl;
	std::cout << "|                           |" << std::endl;
	std::cout << "|         PROFILE           |" << std::endl;
	std::cout << "|                           |" << std::endl;
	std::cout << " =========================== " << std::endl;
	color(14);

	std::cout << "* The username  : " << temp->user->getUserName() << std::endl;
	std::cout << "* The Email : " << temp->user->getEmail() << std::endl;
	std::cout << "* The Gender : " << temp->user->getGender() << std::endl;
	std::cout << "* The Birthday : " << temp->user->getBirth() << std::endl;
	std::cout << "* The phoneNumber : " << temp->user->getPhoneNumber() << std::endl;
	std::cout << "* The Followers : " << temp->user->getFollowers() << std::endl;
	std::cout << "* Registration Date : " << temp->user->get_dateRegistration()<< std::endl;


	act.description = "Veiw porfile [ " + userName + " ]";
	temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.View_Profile++;
}

void Browse::Browse_user() {

	system("cls");
	std::cout << "\t\t\t===========================" << std::endl;
	std::cout << "\t\t\t                           " << std::endl;
	std::cout << "\t\t\t  Welcome browse platfrom  " << std::endl;
	std::cout << "\t\t\t                           " << std::endl;
	std::cout << "\t\t\t===========================" << std::endl;

	std::string userName;
	int Code;

	std::cout << "Logged in" << std::endl;
	std::cout << "*********" << std::endl;

	std::cout << "Enter user name : ";
	getline(std::cin, userName);

	Code = at->hashCode(userName);

	if (!at->search(Code, at->ROOT())) {
		std::cout << "-> Sorry , user not found ." << std::endl;
		system("pause");
		return;
	}

	char ch;
	std::string password = "";
	const int maxAttempts=3;
	int attempts = 1;
	do {
		std::cout << "Enter the password: ";
		password.clear();
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && !password.empty()) {
				password.pop_back();
				std::cout << "\b \b";
			}
			else if (ch != '\b') {
				std::cout << '*';
				password += ch;
			}
		}
		std::cout << std::endl;
		if (attempts <= maxAttempts+1 && at->search(Code, at->ROOT())->user->getPassword() == password)
			break;
		else if (attempts <= maxAttempts+1 && at->search(Code, at->ROOT())->user->getPassword() != password) {
			std::cout << "Wrong password. Try again " << (maxAttempts - attempts)+1 << " Attempts left " << std::endl;
			++attempts;
			continue;
		}
		else {
			std::cout << "Login Failed.Try again later"<<std::endl;
			system("pause");
			return;
		}
	} while (true);
		
	// User logged in
	auto user_Logged_in = [&]()-> void {
		Activity act;
		AVLNode* an = at->search(Code, at->ROOT());

		act.type = "Logged in";
		act.description = "Logged in successfully in ( " + act.timeStamp + " )";

		if (an->Activities.isFull())
			an->Activities.dequeue();

		an->Activities.enqueue(act);
		an->act.log_in++;
    };

	//User logged out
	auto user_Logged_out = [&]() {
		Activity act;
		AVLNode* an = at->search(Code, at->ROOT());

		act.type = "Logged out";
		act.description = "Logged out successfully in ( " + act.timeStamp + " )";

		if (an->Activities.isFull())
			an->Activities.dequeue();

		an->Activities.enqueue(act);
		an->act.log_out++;
    };
	user_Logged_in();

	auto color = [&](int cnt)-> void {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnt);
	};
	auto menu = [&](int pos)-> void {
		int mx_size = 7;
		std::vector<std::string> v = { "Like .", "Comment .", "Follow .", "Share ." , "Create_post ." , "View profile ." , "Log out ."};

		std::cout << "What do you want to do ?" << std::endl;
		std::cout << "************************" << std::endl;
		for (auto i = 0; i < mx_size; ++i) {
			if (pos == i) {
				color(10);
				std::cout << "-->\t";
				std::cout << v[i] << std::endl;
				color(7);
			}
			else {
				std::cout << "\t" << v[i] << std::endl;
			}
		}
		};
	auto Menu = [&]()-> int {
		system("cls");
		int i = 0;
		char ch;
		menu(0);

		while (true) {

			ch = _getch();

			switch (ch) {
			case 27:
				exit(0);
				break;
			case 72: // UP
				system("cls");
				i = (i - 1 + 7) % 7;
				menu(i);
				break;
			case 80: // DOWN
				system("cls");
				i = (i + 1) % 7;
				menu(i);
				break;
			case '\r': // Enter
				return i;
			default:
				break;
			}
		}
		};
	
	while (true) {
		system("cls");

		int i = Menu();

		switch(i) {
		case Like:
			break;
		case Comment:
			break;
		case Follow:
			system("pause");
			break;
		case Share:
			break;
		case Create_post:
			break;
		case View_Profile:
			VIEW_PROFILE(Code);
			system("pause");
			color(7);
			break;
		default:
			user_Logged_out();
			return;
		}
	}

	/*do {
		std::string ch;
		system("cls");
		Activity act;
		std::cout << "What do you want to do ?" << std::endl;
		std::cout << "************************" << std::endl;
		std::cout << "1) Like ." << std::endl;
		std::cout << "2) Comment ." << std::endl;
		std::cout << "3) Follow ." << std::endl;
		std::cout << "4) Share ." << std::endl;
		std::cout << "5) Create_post ." << std::endl;
		std::cout << "6) View profile ." << std::endl;
		std::cout << "7) Log out ." << std::endl;
		std::cout << "Enter your choice : ";
		std::cin >> ch;

		if (!mn->IsValidChoice(ch)) {
			system("pause");
			continue;
		}

		int cha = stoi(ch);
		switch (cha) {
		case Like:
			LIKE(Code);
			break;
		case Comment:
			COMMENT(Code);
			break;
		case Follow:
			FOLLOW(Code);
			system("pause");
			break;
		case Share:
			SHARE(Code);
			break;
		case Create_post:
			CREATE_POST(Code);
			break;
		case View_Profile:
			VIEW_PROFILE(Code);
			system("pause");
			color(7);
			break;
		case log_out:
			user_Logged_out();
			return;
		default:
			std::cout << "Invalid choice (-_-) ." << std::endl;
			system("pause");
			break;
		}
	} while (true);*/
}

std::vector<std::string>  Browse::print_Treding() {
	auto comp = [&](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2)->bool {
		return p1.second > p2.second;
	};

	std::vector<std::pair<std::string, int>> vec(Hashtags.begin(), Hashtags.end());
	sort(vec.begin(), vec.end(), comp);

	std::vector<std::string> trendingHashtags;
	for (const auto& pair : vec) {
		trendingHashtags.push_back(pair.first);
	}
	return trendingHashtags;
//	int cnt = 0;
//	for (auto& it : vec)
//		std::cout << "*Trend " << ++cnt << "# " << it.first << std::endl;
}

void Browse::Statistics() {
	auto checkFoundUsers = [&]()-> bool {
		return !at->isEmpty();
	};

	auto color = [&](int cnt)-> void {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnt);
	};

	auto menu = [&](int pos)-> void {
		int mx_size = 3;
		std::vector<std::string> v = { "Statistics of all users .", "Trending .", "Exit ."};

		std::cout << "Statistics" << std::endl;
		std::cout << "**********" << std::endl;
		for (auto i = 0; i < mx_size; ++i) {
			if (pos == i) {
				color(11);
				std::cout << "-->\t";
				std::cout << v[i] << std::endl;
				color(7);
			}
			else {
				std::cout << "\t" << v[i] << std::endl;
			}
		}
		};

	auto Menu = [&]()-> int {
		system("cls");
		int i = 0;
		char ch;
		menu(0);

		while (true) {

			ch = _getch();

			switch (ch) {
			case 27:
				exit(0);
				break;
			case 72: // UP
				system("cls");
				i = (i - 1 + 3) % 3;
				menu(i);
				break;
			case 80: // DOWN
				system("cls");
				i = (i + 1) % 3;
				menu(i);
				break;
			case '\r': // Enter
				return i;
			default:
				break;
			}
		}
		};

	
	while (true) {
		system("cls");

		int i = Menu();

		switch (i) {
		case 0:
			if (!checkFoundUsers()) {
				std::cout << "---> No users Found ." << std::endl;
				system("pause");
				break;
			}
			system("cls");
			std::cout << " ===================== " << std::endl;
			std::cout << "|                     |" << std::endl;
			std::cout << "|    STATISTICS       |" << std::endl;
			std::cout << "|                     |" << std::endl;
			std::cout << " ===================== " << std::endl;
			at->print_Statistics();
			system("pause");
			break;
		case 1:
			print_Treding();
			system("pause");
			break;
		default:
			return;
		}
	}
	
	/*do {
		std::string ch;
		system("cls");
		std::cout << "Statistics" << std::endl;
		std::cout << "**********" << std::endl;
		std::cout << "1) Statistics of all users ." << std::endl;
		std::cout << "2) Trending ." << std::endl;
		std::cout << "0) Exit ." << std::endl;
		std::cout << "Enter your choice : ";
		std::cin >> ch;
		if (!mn->IsValidChoice(ch)) {
			system("pause");
			continue;
		}

		int cha = stoi(ch);
		switch (cha) {
		case 1:
			if (!checkFoundUsers()) {
				std::cout << "---> No users Found ." << std::endl;
				system("pause");
				break;
			}
			system("cls");
			std::cout << " ===================== " << std::endl;
			std::cout << "|                     |" << std::endl;
			std::cout << "|    STATISTICS       |" << std::endl;
			std::cout << "|                     |" << std::endl;
			std::cout << " ===================== " << std::endl;
			at->print_Statistics();
			system("pause");
			break;
		case 2:
			print_Treding();
			system("pause");
			break;
		case 0:
			return;
		default:
			std::cout << "-----> Invalid choice . <-----" << std::endl;
			system("pause");
		}
	} while (true);*/
}