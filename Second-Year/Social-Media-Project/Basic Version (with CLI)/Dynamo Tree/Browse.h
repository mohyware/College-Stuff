// سبحان الله والحمد لله والله أكبر
#pragma once
#include "Manger.h"
#include <windows.h>
#include<unordered_map>
#include<vector>
#include<utility>
#include<algorithm>

enum ACITVITY { Like = 1, Comment = 2, Follow = 3, Share = 4, Create_post = 5, View_Profile = 6, log_out = 7 };

class Browse {
	Manger* mn;
	AVLTree* at;
	unordered_map<string, int> Hashtags;

public:
	Browse();

	~Browse();

	Manger* get_reference_manger();

	void Browse_user();

	void LIKE(int);

	void COMMENT(int);

	void FOLLOW(int);

	void SHARE(int);

	void CREATE_POST(int);

	void VIEW_PROFILE(int);

	void Statistics();

	void print_Treding();
};
