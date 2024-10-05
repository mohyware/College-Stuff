// سبحان الله والحمد لله والله أكبر
#pragma once
#include "Manger.h"
#include <windows.h>
#include<unordered_map>
#include<vector>
#include<utility>
#include<algorithm>

enum ACITVITY { Like, Comment, Follow, Share, Create_post, View_Profile, log_out };

class Browse {
	Manger* mn;
	AVLTree* at;

public:
	std::unordered_map<std::string, int> Hashtags;
	Browse();

	~Browse();

	Manger* get_reference_manger();

	void Browse_user();

	void LIKE(int code, std::string type, std::string desc, std::string hashtag);

	void COMMENT(int code, std::string type, std::string desc, std::string hashtag);

	void FOLLOW(int code, std::string type, std::string desc, std::string hashtag);

	void SHARE(int code, std::string type, std::string desc, std::string hashtag);

	void CREATE_POST(int code, std::string type, std::string desc, std::string hashtag);

	void VIEW_PROFILE(int);

	void Statistics();

	std::vector<std::string> print_Treding();
};
