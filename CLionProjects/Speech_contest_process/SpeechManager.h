//
// Created by david on 09.11.20.
//
#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "Speaker.h"
#include <fstream>
#include <algorithm>
#include <deque>
#include <numeric>


//design a class of speech manager
class SpeechManager
{
public:

    //constructor
    SpeechManager();

    void showManu();

    //initialization
    void initSpeech();

    //exit the system
    void exitSystem();

    //create speakers
    void createSpeaker();

    //start the speech
    void startSpeech();

    //draw lots
    void speechDraw();

    //speech contest
    void speechContest();

    //show result
    void showScore();

    //save record
    void saveRecord();

    //load record
    void loadRecord();

    //show previous record
    void showRecord();

    //clear all record
    void clearRecord();

    //destructor
    ~SpeechManager();


    //vector for all speakers   (12 persons)
    vector<int> v1;

    //vector for speakers who have won in the first round   (6 person)
    vector<int> v2;

    //vector for Top three speakers   (3 persons)
    vector<int> v_Victory;

    //map for each speaker and their corresponding context number
    map<double, Speaker> m_Speaker;

    //record for the number of rounds
    int m_Index;

    //the flag that the file is empty
    bool fileIsEmpty;

    //previous record
    map<int, vector<string>> m_Record;



};