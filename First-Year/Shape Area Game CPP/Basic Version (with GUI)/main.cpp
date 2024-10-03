#include <iostream>     // cout, cin
#include <stdlib.h>     // rand, srand, system
#include <unistd.h>     // sleep
#include <time.h>       // time.now time_t
#include <conio.h>      // getch
#include <iomanip>      // setw#include <iomanip>      // setw
#include <string.h>     // string var
#include <windows.h>    // SetConsoleTextAttribute
using namespace std;

HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE); //@V3


void change_color(bool isBorder){
    if(isBorder)
        SetConsoleTextAttribute(cout_handle, 2);
    else
        SetConsoleTextAttribute(cout_handle, 12);
}

void gotoXY(int x, int y)     //gotoxy function
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}


int get_user_level(int &level,int &back_b){
        system("cls");
        change_color(false);
	int menu_item=0, run, x=7;
	bool running = true ;
	char key_2;
    back_b=0 ;
	gotoXY(18,5); cout << "Choose Level";
	gotoXY(18,7); cout << "->";
        change_color(true);
	while(running)
	{
        gotoXY(20,7);  cout << "1) EASY";
		gotoXY(20,8);  cout << "2) MEDIUM";
		gotoXY(20,9);  cout << "3) HARD";
		gotoXY(20,10);  cout << "  Back";
        key_2=getch();

		if(key_2 == 80 && x != 10) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
                change_color(false);
				gotoXY(18,x); cout << "->";
                change_color(true);
                menu_item++;
				continue;

			}

		if(key_2 == 72 && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
                change_color(false);
				gotoXY(18,x); cout << "->";
                change_color(true);
                menu_item--;
				continue;
			}

		if(key_2 == 13){ // Enter key_2 pressed

			switch(menu_item){

				case 0: {

					gotoXY(2,12);
					cout << "\tYou choose level 1 (EASY)\n";
					level=1;
					running=false;
                    break;
				}


				case 1: {
					gotoXY(2,12);
					cout << "\tYou choose level 2 (MEDIUM)\n";
					level=2;
					running=false;
					break;
				}


				case 2: {
                    gotoXY(2,12);
					cout << "\tYou choose level 3 (HARD)\n";
					level=3;
					running=false;
					break;
				}

                case 3:
                    back_b=1;
					running=false;
					break;
				}
			}

		}

	}



int menu(int &game){
        system("cls");
        change_color(false);

	int menu_item=0, run, x=7;
	bool running = true;
	char key=0;
	gotoXY(18,5); cout << "Main Menu";

	gotoXY(18,7); cout << "->";
            change_color(true);

	while(running)
	{
        gotoXY(20,7);  cout << "1) Play Game";
		gotoXY(20,8);  cout << "2) Help";
		gotoXY(20,9);  cout << "3) Quit Game";
        key =getch();
		if(key == 80 && x != 9) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
                change_color(false);
				gotoXY(18,x); cout << "->";
                change_color(true);
				menu_item++;
				continue;

			}

		if(key ==72 && x!=7 ) //up button pressed && x != 7
			{
				gotoXY(18,x); cout << "  ";
				x--;
                change_color(false);
				gotoXY(18,x); cout << "->";
                change_color(true);
				menu_item--;
				continue;
			}

		if(key == 13){ // Enter key pressed

			switch(menu_item){

				case 0: {

                    running = false;
					break;
				}


				case 1: {
					gotoXY(2,13);
					cout << "Vision Shape and Cal its Area in a specific time\n"
                         << "\t  -time depending on level you choose.\n"
                         << "\t  -trial number also depending on level.\n"
                         << "\t  -press q to quit level ";
					break;
				}


				case 2: {
					running = false;
					game = 0;
				    system("cls");
					gotoXY(20,2);
					cout << "The Game has now terminated!!";
				}

			}

		}
	}
}

// @V3 to move cursor over console
void moveCursor(int col, int row)
{
  cout << "\033[" << col << ";" << row << "H";
}
// @V3 to change color between game and border

// @V3
void print_centered(string str, int width){
    int len = str.length();
    int padding = (width-len)/2;
    //set border color
    change_color(true);
    cout<<'|';
    for(int i=1; i<padding; i++){
        cout<< ' ';
    }
    change_color(false);
    cout<<str;
    //return to border color
    change_color(true);
    for(int i=len+padding; i<width-1; i++){
        cout<< ' ';
    }
    cout<<"|\n";
    change_color(false);
}

// @V2 Print N of Chars in One Line
void print_nchars_line(int n, char c){
    for(int i=0;i<n;++i){
        cout<<c;
    }
    cout<<"\n";
}

// @V2 Clear and Print Game Header contains Trial Number and Level
void game_header(int ntrial,int mtrail, int level,int score){

    system("cls");

    change_color(true);
    //print header 50 * in line
    print_nchars_line(50,'-');


    cout << "| Trial: " << ntrial << "/" << mtrail;
    //align level into right
    cout << setw(35) << "Level: " << level << " |" <<endl;
    cout << "| SCORE: "  << score << setw(40) << "Enter q to quit trial |" <<endl;

    //print header 50 * in line
    print_nchars_line(50,'-');

    change_color(false);
}

// @V3 print game footer
void game_footer(){
    change_color(true);
    //print header 50 * in line
    print_nchars_line(50,'-');
    change_color(false);
}

// @V2 Print a waiting message with count down N Seconds
void start_after(int sec){
    cout<< "\n\t\tStart in ";
    for(int i=sec; i>0; i--){
        cout << i << "s...";
        sleep(1);
        cout <<"\b\b\b\b\b";
    }
}



int main()
{
    //0a. Define Variable
    int m_trial, n_trial;
    int score, g_timeout;
    int width, length;
    int area ,user_areai;
    string user_areas;
    int table_size;
    time_t user_stime, user_timeout;
    int level;
    int game_width;
    int n_lines; //total number of linesdepend
    int game;
    int back_b;
    int play;

    //1a. Initiate Variables
    game_width  = 50;
    table_size  = 5;
    m_trial     = 5;
    n_trial     = 0;
    score       = 0;
    n_lines     = 0;
    game        = 1;
    back_b      = 0;
    //0c. Change random based on time
    srand(time(0));

    //0b. Print Game instructions
    print_nchars_line(game_width,'-');
    cout << "|\t Welcome to my first Game :)\t\t |\n";
   // cout << "|Vision Shape and Cal. its Area in a few seconds.|\n";
    print_nchars_line(game_width,'-');
    system("pause");

do{
    //for new game
    n_trial     = 0;
    score       = 0;


    do{
    menu(game);

    if(game==0)
        return 0; //quit game
    //@V2 Get user level and store in local variable.
    get_user_level(level,back_b);
    }
    while(back_b==1 && game!=0);

    do{
        //@V2 Start game after 3 second
        start_after(1);
        //------Initiate Variables repeated part
        //@V2 Set tablesize and timeout based on level
        width       = (2*level)+rand()%(table_size+(level-1)*2);
        length      = (2*level)+rand()%(table_size+(level-1)*2);
        g_timeout   = 6-level;
        area        = width * length;
        n_trial++;

        //@V2 Show the game header
        game_header(n_trial, m_trial, level ,score);
        //header take 3 lines
        n_lines = 3;

        //2b. padding top
        for(int i=0; i<3; i++)
            print_centered(" ",game_width);
        n_lines+=3; //3 line padding

        //2a. Draw the Rectangle
        string rect_line= "";
        //@V3 get one line
        for(int j=0; j<width; j++){
            rect_line += "# ";
        }
        //@V3 print line multiple times
        for(int i=0;i<length;i++){
            print_centered(rect_line, game_width);
            ++n_lines;
        }

        //3c. Set Start time
        user_stime = time(0);

        for(int i=0; i<3; i++)
            print_centered(" ",game_width);
        n_lines+=3; //3 line padding

        //3a. Ask User
        print_centered("Area = ", game_width);
        int answer_inLine = ++n_lines; // get the line of answer
        game_footer();

        moveCursor(answer_inLine+1,29); //move cursor back to answer line

        cin >>user_areas;

        //3c. Set end time and calc diff
        user_timeout = time(0) - user_stime;

        if(user_areas!="q"){
         print_centered("You take " + to_string(user_timeout)+ "s to answer!....", game_width);
         user_areai = stoi(user_areas);
        }
        //check  if he exit or not
        if(user_areas=="q"){
            n_trial=m_trial;
           continue;
           }

        //4a. Compare Answer and Give them point
        if(user_areai==area && user_timeout <= g_timeout){
            score++;
            print_centered("Correct :)",game_width);
        }else if(user_areai!= area){
            print_centered("Wrong :( ",game_width);
        }else {
            print_centered("Timeout :|, try fast",game_width);
        }
        game_footer();
    }
    //5a. Check the number of trial
    while(n_trial<m_trial);

    game_header(n_trial, m_trial, level,score);
    //6a. Game over and print socre
    cout<<"\n\t\tGAME OVER\n";
    cout<<"\n\t\tYour Score is :" <<(score*1.0/m_trial)*100.0 <<"%\n";
    game_footer();
        cout<<"\t    Play Again Y/N?  ";
    play=getch();
    system("cls");
    }
    while((play=='y' || play == 'Y'));
    return 0;
}

