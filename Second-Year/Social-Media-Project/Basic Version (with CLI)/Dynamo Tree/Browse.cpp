#include "Browse.h"
Browse::Browse(): mn(new Manger()) , at(mn->get_reference_tree()) {}
Browse::~Browse() {
	delete at;
	delete mn;
}

Manger* Browse::get_reference_manger() { return mn; }

void Browse::LIKE(int code) {
	Activity act;
	string desc;

	act.type = "Like";

	cin.ignore();
	cout << "which post do you want to like ? ";
	getline(cin, desc);

	act.description = desc;

	AVLNode* temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.Like++;
}

void Browse::COMMENT(int code) {
	Activity act;
	string desc;

	act.type = "Comment";

	cin.ignore();
	cout << "which post to comment ? ";
	getline(cin, desc);

	string comm;
	cout << "Enter your comment : "; 
	getline(cin, comm);

	// Hashtag
	char ch;
	cout << "Do you want to add any hashtag ? (Y/N) .";
	cin >> ch;

	cin.ignore();
	if ((char)tolower(ch) == 'y') {
		string hashtag;
		cout << "Enter Hashtag : #";
		getline(cin, hashtag);
		Hashtags[hashtag]++;
	}

	act.description = desc + "\n The comment : " + comm;

	AVLNode* temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.Comment++;
}

void Browse::SHARE(int code) {
	Activity act;
	string desc;

	act.type = "Share";

	cin.ignore();
	cout << "which post to share ? ";
	getline(cin, desc);

	string comm_on_share = "";
	char ch;
	cout << "Do you want to add any comment on share ? (Y/N) .";
	cin >> ch;

	cin.ignore();
	if ((char) tolower(ch) == 'y') {
		cout << "Enter your comment : ";
		getline(cin, comm_on_share);

		// Hashtag
		char ch;
		cout << "Do you want to add any hashtag ? (Y/N) .";
		cin >> ch;

		cin.ignore();
		if ((char) tolower(ch) == 'y') {
			string hashtag;
			cout << "Enter Hashtag : #";
			getline(cin, hashtag);
			Hashtags[hashtag]++;
		}
	}

	act.description = desc + "\nThe comment on share : " +  comm_on_share;

	AVLNode* temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.Share++;
}

void Browse::FOLLOW(int code) {
	Activity act;
	string desc , userName;
	int Code;
	
	act.type = "Follow";

	cout << "Enter user name to follow : ";
	cin >> userName;

	Code = at->hashCode(userName);

	AVLNode* temp = at->search(Code, at->ROOT());
	AVLNode* cur_user = at->search(code, at->ROOT());

	// Invalid user
	if (!temp) {
		cout << "-> user name not exist." << endl;
		return;
	}

	// Follow himself
	if (Code == code) {
		cout << "-> Cannot recursive follow ." << endl;
		return;
 	}

	// Check if he followed the same user twice
	if (!cur_user->user->checkFollowes(Code)) {
		cout << "-> You are already following this user ." << endl;
		return;
	}

	cout << "-> Follow completed successfully (^_^)." << endl;
	cur_user->user->pushFollowed(Code);

	act.description = "Create follow to [ " + userName + " ].";
	temp->user->increase_follower();

	temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.Follow++;

}

void Browse::CREATE_POST(int code) {
	Activity act;
	act.type = "Create post";
	string desc;

	cin.ignore();
	cout << "What post to create ? ";
	getline(cin, desc);

	// Hashtag
	char ch;
	cout << "Do you want to add any hashtag ? (Y/N) .";
	cin >> ch;

	cin.ignore();
	if ((char)tolower(ch) == 'y') {
		string hashtag;
		cout << "Enter Hashtag : #";
		getline(cin, hashtag);
		Hashtags[hashtag]++;
	}

	act.description = desc;

	AVLNode* temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.Create_Post++;
}

void Browse::VIEW_PROFILE(int code) {
	Activity act;
	string userName;

	act.type = "View profile";

	cout << "Search user name : ";
	cin >> userName;

	AVLNode* temp = at->search(at->hashCode(userName), at->ROOT());

	if (!temp) {
		cout << "-> user name not exist." << endl;
		return;
	}
	
	system("cls");

	auto color = [&](int cnt)-> void {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnt);
    };

	color(6);
	cout << " ==========================  " << endl;
	cout << "|                           |" << endl;
	cout << "|         PROFILE           |" << endl;
	cout << "|                           |" << endl;
	cout << " =========================== " << endl;
	color(14);

	cout << "* The username  : " << temp->user->getUserName() << endl;
	cout << "* The Email : " << temp->user->getEmail() << endl;
	cout << "* The Gendre : " << temp->user->getGendre() << endl;
	cout << "* The Birthday : " << temp->user->getBirth() << endl;
	cout << "* The phoneNumber : " << temp->user->getPhoneNumber() << endl;
	cout << "* The Followers : " << temp->user->getFollowers() << endl;
	cout << "* Registration Date : " << temp->user->get_dateRegistration()<< endl;


	act.description = "Veiw porfile [ " + userName + " ]";
	temp = at->search(code, at->ROOT());
	if (temp->Activities.isFull())
		temp->Activities.dequeue();

	temp->Activities.enqueue(act);
	temp->act.View_Profile++;
}

void Browse::Browse_user() {

	system("cls");
	cout << "\t\t\t===========================" << endl;
	cout << "\t\t\t                           " << endl;
	cout << "\t\t\t  Welcome browse platfrom  " << endl;
	cout << "\t\t\t                           " << endl;
	cout << "\t\t\t===========================" << endl;

	string userName;
	int Code;

	cout << "Logged in" << endl;
	cout << "*********" << endl;

	cout << "Enter user name : ";
	cin >> userName;

	Code = at->hashCode(userName);

	if (!at->search(Code, at->ROOT())) {
		cout << "Sorry , user not found ." << endl;
		system("pause");
		return;
	}

	char ch;
	string password = "";
	cout << "Enter the password : ";
	while ((ch = _getch()) != '\r')
		cout << '*', password += ch;

	cout << endl;

	if (at->search(Code , at->ROOT())->user->getPassword() != password) {
		cout << "Wrong password ." << endl;
		system("pause");
		return;
	}

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
	
	
	do {
		string ch;
		system("cls");
		Activity act;
		cout << "What do you want to do ?" << endl;
		cout << "************************" << endl;
		cout << "1) Like ." << endl;
		cout << "2) Comment ." << endl;
		cout << "3) Follow ." << endl;
		cout << "4) Share ." << endl;
		cout << "5) Create_post ." << endl;
		cout << "6) View profile ." << endl;
		cout << "7) Log out ." << endl;
		cout << "Enter your choice : ";
		cin >> ch;

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
			cout << "Invalid choice (-_-) ." << endl;
			system("pause");
			break;
		}
	} while (true);
}

void Browse::print_Treding() {
	auto comp = [&](const pair<string, int>& p1, const pair<string, int>& p2)->bool {
		return p1.second > p2.second;
	};

	vector<pair<string, int>> vec(Hashtags.begin(), Hashtags.end());
	sort(vec.begin(), vec.end(), comp);


	system("cls");
	cout << " ===================== " << endl;
	cout << "|                     |" << endl;
	cout << "|      TREDNIG        |" << endl;
	cout << "|                     |" << endl;
	cout << " ===================== " << endl;

	int cnt = 0;
	for (auto& it : vec)
		cout << "*Trend " << ++cnt << "# " << it.first << endl;
}

void Browse::Statistics() {
	auto checkFoundUsers = [&]()-> bool {
		return !at->isEmpty();
	};

	do {
		string ch;
		system("cls");
		cout << "Statistics" << endl;
		cout << "**********" << endl;
		cout << "1) Statistics of all users ." << endl;
		cout << "2) Trending ." << endl;
		cout << "0) Exit ." << endl;
		cout << "Enter your choice : ";
		cin >> ch;
		if (!mn->IsValidChoice(ch)) {
			system("pause");
			continue;
		}

		int cha = stoi(ch);
		switch (cha) {
		case 1:
			if (!checkFoundUsers()) {
				cout << "---> No users Found ." << endl;
				system("pause");
				break;
			}
			system("cls");
			cout << " ===================== " << endl;
			cout << "|                     |" << endl;
			cout << "|    STATISTICS       |" << endl;
			cout << "|                     |" << endl;
			cout << " ===================== " << endl;
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
			cout << "-----> Invalid choice . <-----" << endl;
			system("pause");
		}
	} while (true);
	
}