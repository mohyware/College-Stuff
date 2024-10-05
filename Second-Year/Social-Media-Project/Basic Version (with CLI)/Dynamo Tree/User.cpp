#include "User.h"
User::User() : dateRegistration(getCurrentTimeStamp()), FollowUp(new int[50]) {
	 userName = "";
	 password = "";
	 email = "";
	 gendre = "";
	 birthday = "";
	 phoneNumber = "";
	 Followers = 0;
	 idx = 0;
}

void User::setUserName(const string& userName) { this->userName = userName; }
void User::setPassword(const string& pass) { this->password = pass; }
void User::setEmail(const string& email) { this->email = email; }
void User::setGendre(const string& gendre) { this->gendre = gendre; }
void User::setBirth(const string& birthday) { this->birthday = birthday; }
void User::setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }
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
string User::getUserName() const { return this->userName; }
string User::getPassword() const { return this->password; }
string User::getEmail() const { return this->email; }
string User::getGendre() const { return this->gendre; }
string User::getBirth() const { return this->birthday; }
string User::getPhoneNumber() const { return this->phoneNumber; }
string User::get_dateRegistration() const { return dateRegistration; }
string User::getCurrentTimeStamp() {
	auto now = chrono::system_clock::now();
	time_t currentTime = chrono::system_clock::to_time_t(now);

	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

	return buffer;
}

istream& operator >> (istream& in, User& user) {
	//cout << "Enter the userName : ";
	//in >> user.userName;

	cout << "Enter the email : ";
	in >> user.email;

	char ch;
	cout << "Enter the password : ";
	while ((ch = _getch()) != '\r')
		cout << '*', user.password += ch;

	cout << endl;

	cout << "Enter the gendre : ";
	in >> user.gendre;

	cout << "Enter the birthday : ";
	in >> user.birthday;

	cout << "Ente the phoneNumber : ";
	in >> user.phoneNumber;

	return in;
}
ostream& operator << (ostream& out, const User& user) {
	out << "* The username  : " << user.userName << endl;
	out << "* The Email : " << user.email << endl;
	out << "* The Password : " << user.password << endl;
	out << "* The Gendre : " << user.gendre << endl;
	out << "* The Birthday : " << user.birthday << endl;
	out << "* The phoneNumber : " << user.phoneNumber << endl;
	out << "* The Followers : " << user.Followers << endl;
	out << "* Registration Date : " << user.dateRegistration << endl;
	return out;
}