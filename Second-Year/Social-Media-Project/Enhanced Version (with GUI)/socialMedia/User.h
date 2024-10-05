// سبحان الله وبحمده سبحان الله العظيم
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<conio.h>
#include <chrono>
#include <ctime>

class User {
	std::string userName;
	std::string password;
	std::string email;
	std::string gender;
	std::string birthday;
	std::string phoneNumber;
	std::string dateRegistration;
	int* FollowUp;
	int idx;

public:
	int Followers;
	User();

	void setUserName(const std::string&);
	void setPassword(const std::string&);
	void setEmail(const std::string&);
	void setGender(const std::string&);
	void setBirth(const std::string&);
	void setPhoneNumber(const std::string&);
	void setFollowers(const int&);
	void pushFollowed(const int&);

	bool checkFollowes(const int&);
	int increase_follower();
	int getFollowers() const;
	std::string getUserName() const;
	std::string getPassword() const;
	std::string getEmail() const;
	std::string getGender() const;
	std::string getBirth() const;
	std::string getPhoneNumber() const;
	std::string get_dateRegistration() const;
	static std::string getCurrentTimeStamp();

	friend std::istream& operator >> (std::istream& is,User& user);
	friend std::ostream& operator << (std::ostream& os, const User& user);
};