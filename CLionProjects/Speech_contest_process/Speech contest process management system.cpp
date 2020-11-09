#include <iostream>
#include "SpeechManager.h"
using namespace std;


int main()
{
    // create a object of class speechManager
    SpeechManager sm;

//    //testing code
//    for(map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
//    {
//        cout << "contest number: " << it->first << "  "
//             << "name: " << it->second.m_Name << "  "
//             << "score: "<< it->second.m_Score[0] << endl;
//    }

    while (true)
    {
        srand((unsigned int)time(NULL));
        sm.showManu();

        cout << "Please enter you choice: " << endl;
        int choice = 0;
        cin >> choice;

        switch (choice)
        {
            case 1:   //Start the contest
                sm.startSpeech();
                break;
            case 2:
                sm.showRecord();//View previous records
                break;
            case 3:   //Clear all records
                sm.clearRecord();
                break;
            case 0:   //exit the speech contest system
                sm.exitSystem();
                break;
            default:
                break;
        }

        cout << endl;
    }




    return 0;
}
