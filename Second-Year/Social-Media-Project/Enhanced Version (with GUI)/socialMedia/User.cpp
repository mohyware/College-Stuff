#include "User.h"
User::User() : dateRegistration(getCurrentTimeStamp()), FollowUp(new int[50]) {
	 userName = "";
	 password = "";
	 email = "";
	gender = "";
	 birthday = "";
	 phoneNumber = "";
	 Followers = 0;
	 idx = 0;
}

void User::setUserName(const std::string& userName) { this->userName = userName; }
void User::setPassword(const std::string& pass) { this->password = pass; }
void User::setEmail(const std::string& email) { this->email = email; }
void User::setGender(const std::string& gender) { this->gender = gender; }
void User::setBirth(const std::string& birthday) { this->birthday = birthday; }
void User::setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
void User::setFollowers(const int& number) { this->Followers = number; }
void User::pushFollowed(const int& hashCode) {
	FollowUp[idx++] = hashCode;
}

bool User::checkFollowes(const int& hashCode) {
	for (auto i = 0; i < idx; ++i)
		if (FollowUp[i] == hashCode) return false;

	return true;
}
int User::increase_follower() { ++Followers; return Followers; }
int User::getFollowers() const { return this->Followers; }
std::string User::getUserName() const { return this->userName; }
std::string User::getPassword() const { return this->password; }
std::string User::getEmail() const { return this->email; }
std::string User::getGender() const { return this->gender; }
std::string User::getBirth() const { return this->birthday; }
std::string User::getPhoneNumber() const { return this->phoneNumber; }
std::string User::get_dateRegistration() const { return dateRegistration; }
std::string User::getCurrentTimeStamp() {
	auto now = std::chrono::system_clock::now();
	time_t currentTime = std::chrono::system_clock::to_time_t(now);

	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

	return buffer;
}

std::istream& operator >> (std::istream& in, User& user) {
	//std::cout << "Enter the userName : ";
	//in >> user.userName;

	std::cout << "Enter the email : ";
	in >> user.email;

	char ch;
	do {
		std::cout << "Enter the password: ";
Handle_empty_password:
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && !user.password.empty()) {
				user.password.pop_back();
				std::cout << "\b \b";
			}
			else if (ch != '\b') {
				std::cout << '*';
				user.password += ch;
			}
		}
		std::cout << std::endl;
		if (user.password.empty())
			goto Handle_empty_password;

		//password verfication!!
		std::string check_password = "";
		std::cout << "Password confirmation: ";

Handle_empty_password_verfication:
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && !check_password.empty()) {
				check_password.pop_back();
				std::cout << "\b \b";
			}
			else if (ch != '\b') {
				std::cout << '*';
				check_password += ch;
			}
		}
		std::cout << std::endl;

		if (check_password.empty())
			goto Handle_empty_password_verfication;

		if (user.password == check_password) {
			check_password.clear();
			break;
		}
		if (user.password != check_password) {
			std::cout << "-> Passwords don't match...Try again." << std::endl;
			user.password.clear();
			check_password.clear();
		}
	} while (true);
	char gen;
	do {
		std::cout << "Choose your gender (1-Male/2-Female) : ";
		std::cin >> gen;
		switch (gen)
		{
		case '1':
			user.gender = "Male";
			break;
		case '2':
			user.gender = "Female";
			break;
		case '3':
			user.gender = "Civil Engineer";
			break;
		default:
			std::cout << "-> Invalid Choice...Please choose 1 or 2 only." << std::endl;
			system("pause");
			break;
		}
	} while (gen != '1' && gen != '2' && gen != '3');

	std::cout << "Enter the birthday : ";
	in >> user.birthday;

	
Handle_PhoneNumber:
	bool check = false;
	std::cout << "Ente the phoneNumber : ";
	in >> user.phoneNumber;

	for (int i = 0; i < user.phoneNumber.size(); i++)
		if (!isdigit(user.phoneNumber[i]))
		{
			check = true;
			break;
		}
	if (check) {
		std::cout << "No letters allowed in the phone number...type numbers only."<<std::endl;
		user.phoneNumber.clear();
		goto Handle_PhoneNumber;
	}
	
	return in;
}
std::ostream& operator << (std::ostream& out, const User& user) {
	out << "* The username : " << user.userName << std::endl;
	out << "* The Email : " << user.email << std::endl;
	out << "* The Password : " << user.password << std::endl;
	out << "* The Gender : " << user.gender << std::endl;
	out << "* The Birthday : " << user.birthday << std::endl;
	out << "* The phoneNumber : " << user.phoneNumber << std::endl;
	out << "* The Followers : " << user.Followers << std::endl;
	out << "* Registration Date : " << user.dateRegistration << std::endl;
	return out;
}