#include <iostream>
#include "header.h"

// Exam functions
Exam::Exam()
{
    enum Exam_category e = UNIT_TEST;
    examcode = "COM111";
    timeduration = 12;
}
// Constructors Paramters
Exam::Exam(enum Exam_category e, std::string excode, int time) : timeduration(time)
{
}

// Onlinen exam functions
onlineexam::onlineexam()
{
    enum Exam_platform e = TEAMS;
}

onlineexam::onlineexam(enum Exam_platform m)
{
    p = m;
}
// Copy Constructors
onlineexam::onlineexam(onlineexam &s1)
{
    this->setP(s1.p);
}

void onlineexam::display()
{
    std::cout << "selected options\n";
    std::cout << p << std::endl;
    averagemarks(marks);
}

void onlineexam::averagemarks(int *a)

{
    int sum = 0;
    float avg = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + a[i];
    }
    avg = float(sum) / 5;

    std::cout << "Average marks of exams " << avg << std::endl;
}

onlineexam::~onlineexam()
{
}
void onlineexam::accept()
{
    std::cout << "Exam platform" << std::endl;
    int choice;
    std::cout << "1.MEET 2.TEAMS 3.ZOOM" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        p = MEET;
        break;
    case 2:
        p = TEAMS;
        break;
    case 3:
        p = ZOOM;
    }
    std::cout << "Enter marks\n";
    for (int i = 0; i < 5; i++)
    {
        std::cin >> marks[i];
    }
}

// Offlineexam  functions

offlineexam::offlineexam()
{
    enum Exam_Topic e = CPP;
    examloc = "India";
}
offlineexam::offlineexam(enum Exam_Topic m, std::string el)
{
    examloc = el;
    t = m;
}

void offlineexam::display()
{
    std::cout << t << std::endl;
    std::cout << examloc << std::endl;
}

void offlineexam::accept()
{
    std::cout << "Exam Topic" << std::endl;
    int choice;
    std::cout << "1.CPP 2.DS 3.JAVA" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        t = CPP;
        break;
    case 2:
        t = DS;
        break;
    case 3:
        t = JAVA;
    }
    std::cout << "Enter Examlocation\t";
    std::cin >> examloc;
}

void offlineexam::changelocation()
{
    std::string newlocation;
    std::cout << "Enter New Location\n";
    std::cin >> newlocation;
    examloc = newlocation;
    std::cout << "Location Changed\n";
}