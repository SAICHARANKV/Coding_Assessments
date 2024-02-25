#ifndef HEADER_H
#define HEADER_H
#include <cstring>
#include <iostream>
enum Exam_category
{
    UNIT_TEST = 1,
    MID_TERM,
    END_SEM
};
enum Exam_platform
{
    MEET = 1,
    TEAMS,
    ZOOM
};

enum Exam_Topic
{
    CPP = 1,
    DS,
    JAVA
};

class Exam
{
    Exam_category e;
    std::string examcode;
    int timeduration;

public:
    Exam();
    Exam(enum Exam_category e, std::string excode, int time);
    virtual void display() = 0; // Pure virtual function
    Exam_category getE() const { return e; }
    void setE(const Exam_category &e_) { e = e_; }

    std::string getExamcode() const { return examcode; }
    void setExamcode(const std::string &examcode_) { examcode = examcode_; }

    int getTimeduration() const { return timeduration; }
    void setTimeduration(int timeduration_) { timeduration = timeduration_; }
};

class onlineexam : public Exam
{
    Exam_platform p;
    int marks[5];

public:
    void accept();
    void display();
    void averagemarks(int *);
    onlineexam();
    onlineexam(enum Exam_platform m);
    onlineexam(onlineexam &s1);
    ~onlineexam();
    Exam_platform getP() const { return p; }
    void setP(const Exam_platform &p_) { p = p_; }

  
};

class offlineexam : public Exam
{
    Exam_Topic t;
    std::string examloc;

public:
    offlineexam();
    offlineexam(enum Exam_Topic m, std::string el);
    void accept();
    std::string getExamloc() const { return examloc; }
    void setExamloc(const std::string &examloc_) { examloc = examloc_; }

    void display();
    void changelocation();
};

#endif // HEADER_H
