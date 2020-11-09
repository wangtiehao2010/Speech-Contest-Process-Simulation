//
// Created by david on 09.11.20.
//
#include "SpeechManager.h"


//constructor
SpeechManager::SpeechManager()
{
    //initialization
    this->initSpeech();

    //creation of speakers
    this->createSpeaker();

    //get previous record
    this->loadRecord();
}

void SpeechManager::showManu()
{
    cout << "***************************************************" << endl;
    cout << "*********  Welcome to the speech contest  *********" << endl;
    cout << "*********  1. Start the contest  ******************" << endl;
    cout << "*********  2. View previous records  **************" << endl;
    cout << "*********  3. Clear all records  ******************" << endl;
    cout << "*********  0. exit the speech contest system  *****" << endl;
    cout << "***************************************************" << endl;
    cout << endl;
}

void SpeechManager::initSpeech()
{
    //make sure that all vectors and maps are empty
    this->v1.clear();
    this->v2.clear();
    this->v_Victory.clear();
    this->m_Speaker.clear();

    //initialization of the number of round
    this->m_Index = 1;

    //initialization of the record container
    this->m_Record.clear();
}

//create speakers
void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for(int i = 0; i < 12; i++)
    {
        string name = "Speaker ";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;
        for(int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }

        //contest numbers for 12 speakers
        this->v1.push_back(10000 + i);

        //use a map to save each speaker and their corresponding context number
        this->m_Speaker.insert(make_pair(10000+i, sp));
    }
}

//start the speech
void SpeechManager::startSpeech()
{
    /**First Round**/
    //1. draw lots(抽签)
    this->speechDraw();
    //2. competition
    this->speechContest();
    //3. show the result
    this->showScore();
    /**Second Round**/
    this->m_Index++;
    //1. draw lots(抽签)
    this->speechDraw();
    //2. competition
    this->speechContest();
    //3. show the result
    this->showScore();
    //4. save the result
    this->saveRecord();

    //reset contest after saving record
    //initialize attribute
    this->initSpeech();
    //recreate speakers
    this->createSpeaker();
    //load previous record again, update the data in the program
    this->loadRecord();

    cout << "the speech contest is finished" << endl;

}

//draw lots
void SpeechManager::speechDraw()
{
    cout << "Speakers of round " << this->m_Index << " is drawing lots" << endl;
    cout << "------------------------------------------" << endl;
    cout << "The result of drawing is shown below: " << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(v1.begin(),v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(),v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------------" << endl;

}

// start the contest
void SpeechManager::speechContest()
{
    cout << "--------------- Round " << this->m_Index << " start! ---------------" << endl;

    multimap<double, int, greater<double>> groupScore; // temporary container:  key is used to save the score(for sorting)

    int num = 0; //save the number of speakers, 6 persons for one group

    vector<int> v_Src; //speaker record container
    if(this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }

    //traverse all speakers
    for(vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;

        //scoring by judges
        deque<double> d;
        for(int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f; // 60~100
            //cout << score << " ";
            d.push_back(score);
        }

        sort(d.begin(),d.end(),greater<double>());      //sorting
        d.pop_front();                                        //remove the highest score
        d.pop_back();                                         //remove the lowest score

        double sum = accumulate(d.begin(),d.end(),0.0f);  //get the total score
        double avg = sum / (double)d.size();                  //get the average score

//test        cout << avg << endl;  //test

        //average score of each speaker
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
//test        cout << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;  //test


        //6 persons for a group, use the temporary container to save them
        groupScore.insert(make_pair(avg,*it));
        if (num % 6 == 0)
        {
            cout << "The rank of group " << num / 6 << endl;
            for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "contest number: " << it->second << "  name: " << this->m_Speaker[it->second].m_Name
                << "  Score: " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
            }

            int count = 0;
            // get the top three
            for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count <3; it++, count++)
            {
                if(this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    v_Victory.push_back((*it).second);
                }
            }

            groupScore.clear();

            cout << endl;
        }
    }

    cout << "--------------- Round " << this->m_Index << " end! ---------------" << endl;
}

//show score
void SpeechManager::showScore()
{
    cout << "---- Round " << this->m_Index << ": the list of speakers that have advanced ----" << endl;

    vector<int> v;
    if(this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = v_Victory;
    }

    for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
    {
        cout << "contest number: " << *it << "  name: " << this->m_Speaker[*it].m_Name
             << "  Score: " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);  //用输出的方式打开文件   --写文件

    //write the data of each person into the file
    for(vector<int>::iterator it = v_Victory.begin(); it != v_Victory.end(); it++)
    {
        ofs << *it << ","
        << m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;

    //close the file
    ofs.close();

    cout << "record has been saved!" << endl;

    //the record is not empty now
    this->fileIsEmpty = false;

}

//load the record
void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in); //read the file

    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "the file does not exist" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch; //read if it is an eof at first

    if (ifs.eof())
    {
        cout << "file is empty! " << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //file is not empty
    this->fileIsEmpty = false;

    ifs.putback(ch); //put the eof back into the file

    string data;
    int index = 0;
    while(ifs >> data)
    {
//        cout << data << endl;
        vector<string> v;

        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = data.find(",",start);
            if(pos == -1)
            {
                break;
            }
            string tmp = data.substr(start, pos - start); //find the comma, use substr to split the data
            v.push_back(tmp);
            start = pos + 1;
        }

        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();

//    for(map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
//    {
//        cout << it->first << ". champion number: " << it->second[0] << " score: " << it->second[1] << endl;
//    }
//    cout << this->m_Record[0][5];
//    cout << this->m_Record.size();
}

//show previous record
void SpeechManager::showRecord()
{
    if (fileIsEmpty)
    {
        cout << "the file is empty!" << endl;
    }
    else
    {
        for(int i = 0; i < this->m_Record.size(); i++)
        {
        string str = "";
        if(i+1 == 1)
        {
            str = "st ";
        }
        else if(i+1 == 2)
        {
            str = "nd ";
        }
        else if(i+1 == 3)
        {
            str = "rd";
        }
        else
        {
            str = "th ";
        }

        cout << i+1 << str << "Speech contest: " << endl;
        cout << "first place's contest number: " << this->m_Record[i][0] << " score: " << this-> m_Record[i][1] << endl;
        cout << "second place's contest number: " << this->m_Record[i][2] << " score: " << this-> m_Record[i][3] << endl;
        cout << "third place's contest number: " << this->m_Record[i][4] << " score: " << this-> m_Record[i][5] << endl;
        }

    }
}

void SpeechManager::clearRecord()
{
    cout << "Sure to clear all record?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "choose 1 or 2: " << endl;
    int select = 0;
    cin >> select;

    if(select == 1)
    {
        //turn on ios::trunc mode, if the file exist, delete it and recreate one
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        //reset contest after saving record

        //initialize attribute
        this->initSpeech();

        //recreate speakers
        this->createSpeaker();

        //load previous record again, update the data in the program
        this->loadRecord();

        cout << "clear all record successfully!" << endl;

    }
}

//exit the system
void SpeechManager::exitSystem()
{
    cout << " See you next time! " << endl;
    exit(0);
}

//destructor
SpeechManager::~SpeechManager()
{

}


