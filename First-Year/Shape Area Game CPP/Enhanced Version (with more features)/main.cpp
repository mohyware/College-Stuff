#include <iostream>     // cout, cin
#include <stdlib.h>     // rand, srand, system
#include <unistd.h>     // sleep
#include <time.h>       // time.now time_t
#include <iomanip>
#include <conio.h>
using namespace std;
void start_screen();

int choose_level(int &level);

void header (int s_trial,int score,int level,int heart);

void level_inst(int l_score,int l_timeout,int l_trial,int level);

void draw_shape(int length,int width);

void game_over (int high_score);

void start_next();

int main()
{
    //0a. Define Variable
    int l_trial, s_trial;
    int score;
    int width, length;
    string user_areas ;
    int area,user_areai;
    int table_size;
    int heart;
    int level;
    int l_score,l_timeout,high_score;
    char play;
    time_t user_stime, user_timeout;

    //1a. Initiate Variables

    s_trial     = 0;
    score       = 0;
    high_score  = 0;
    heart       = 3;
    level       = 1;
    //0c. Change random based on time
    srand(time(0));
    //start screen function
    start_screen();



    do{
    //for new game
    s_trial     = 0;
    score       = 0;
    heart       = 3;

    choose_level(level);
    // each level variables
    table_size  = 4+(level-1)*2;   // 4     6     8
    l_score     = 2*(level);       // 2     4     6
    l_timeout   = 10-(level)*2;    // 8     6     4
    l_trial     = 2*(level+1);     // 4     6     8
    //level instruction
    level_inst(l_score,l_timeout,l_trial,level);

    do{
        //------Initiate Variables repeated part
        width       = 2+rand()%table_size;
        length      = 2+rand()%table_size;
        area        = width * length;
        s_trial++;
        //header then draw
        header (s_trial,score,level,heart);
        draw_shape(length,width);

        //3c. Set Start time
        user_stime = time(0);
        //3a. Ask User
        cout<<"\t\t\t"<<setw(31)<<"Area =  ";
        cin>>user_areas;
        //3c. Set end time and calc diff
        user_timeout = time(0) - user_stime;
        if(user_areas!="q")
            cout<<"\n\t\t\t\t\tYou take " << user_timeout <<"s to answer!....\n";
        //check  if he exit or not
        if(user_areas=="q"){
            s_trial=l_trial;
           continue;
           }
        else {
            user_areai = stoi(user_areas);
        }
        //compare areas
        if(user_areai ==area && user_timeout <= l_timeout/2){   //double score condition
            cout<< "\t\t\t\t\tYou answered in half time !\n";
            cout<< "\t\t\t___________________>Double Score !!!<___________________\n";
            score+=(l_score*2);
        }
        else if(user_areai==area && user_timeout <= l_timeout){  //correct score condition
            score+=l_score;
            cout<< "\t\t\t_____________________> Correct (: <_____________________\n";
        }else if(user_areai!= area){                             //wrong score condition
            cout<< "\t\t\t______________________> Wrong ): <______________________\n";
            heart--;
        }else {                                                 //timeout score condition
            cout<< "\t\t\t________________> Timeout :|, try fast <________________\n";
            heart--;
        }
        sleep(3);
        //header then next screen
        header (s_trial,score,level,heart);
        //not showing next in menu end of level or losing all hearts
        if(heart <0 || s_trial == l_trial  )
            continue;

        start_next();

    }
    //Check the number of trial
    while(s_trial<l_trial && heart>=0 );
    //heart bonus -----------not added when exit level
    if(user_areas!="q")
        score+=(heart*4);
   if(high_score<score){
        high_score=score;
    }

    game_over(high_score);
    cout<<"\t\t\t\t\t     Play Again Y/N?  ";
    cin>>play;
    cin.get();
    system("cls");
    }
    while((play=='y' || play == 'Y'));
    return 0;
}

void start_screen(){
    cout << "\t\t\t*******************************************************\n";  //56ch
    cout << "\t\t\t\t    ***Welcome to my first Game :)***\n";
    cout << "\t\t\t    Vision the Shape and Calculate its Area in time\n";
}

int choose_level(int &level){
    cout << "\n\t\t\t\t      Choose level to start 1,2,3 ...";
    cin>>level;
    while(level > 3 || level < 1){
        cout<< "\n\t\t\t\t      Please Choose valid level ...";
        cin>>level;
    }
    return level;
}

void header (int s_trial,int score,int level,int heart){
    system("cls");
    int heart_padding = (heart==1)?36:(heart==2)?35:(heart==3)?34:36;        //heart padding bug
    cout << "\t\t\t************************LEVEL("<<level<<")************************\n";  //56 ch
    cout << "\t\t\t|Trial Number        "<<setw(34)<<s_trial<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";
    cout << "\t\t\t|Your score          "<<setw(34)<<score<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";
    cout << "\t\t\t|Hearts            "<<setw(heart_padding);
    if(heart<=0)cout<<"0"; for(int i=0;i<heart;i++){cout<<"\3";}                      //draw hearts
    cout<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";
    cout << "\t\t\t|\t\t   Enter q to exit Level       "<<setw(10)<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";
}

void level_inst(int l_score,int l_timeout,int l_trial,int level){
    system("cls");
    string diff = (level==1)?"Easy":(level==2)?"Medium":"Hard";
    cout<<  "\t\t\t|***************[Level ("<<level<<") Instructions]***************|\n";
    cout << "\t\t\t|Difficulty          "<<setw(34)<<diff<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";
    cout << "\t\t\t|Trial Numbers       "<<setw(34)<<l_trial<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";
    cout << "\t\t\t|Problem score       "<<setw(34)<<l_score<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";
    cout << "\t\t\t|Timeout             "<<setw(34)<<l_timeout<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";
    cout << "\t\t\t|Notice: 1- double score when u answer in half the time|\n \t\t\t|\t 2- 4 bonus for remain heart"
    <<setw(21)<<"|\n";
    cout << "\t\t\t********************************************************\n";
    cout << "\n\t\t\t\t      Press any key to start ...";
    getch();
}

void draw_shape(int length,int width){
        cout<< "\t\t\t|"<<setw(56)<<"|\n";
        for(int i=0;i<length;i++){
            //2b. Padding left
            cout << "\t\t\t|";
            cout<<setw(29-width);
            for(int j=0; j<width; j++){
                cout<<"# ";
            }
            cout<<setw(29-width)<<"|\n";
        }
        cout << "\t\t\t|______________________________________________________|\n";
}


void game_over (int high_score){
    cout << "\n\t\t\t ____________________   GAME OVER  ____________________\n";  //56 ch
    cout << "\t\t\t|High Score is       "<<setw(34)<<high_score<<"|\n";
    cout << "\t\t\t|______________________________________________________|\n";

}

void start_next(){
        cout<<"\t\t\t\t\t  Start Next in ";
        for(int i=3; i>0; i--){
            cout<< i << "s...";
            sleep(1);
            cout<< "\b\b\b\b\b";
        }
}
