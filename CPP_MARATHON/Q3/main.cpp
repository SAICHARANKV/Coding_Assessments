#include <iostream>
#include "header.h"

int main()
{
    int n;
    int NUM;

    // Interlinking Exam with offline and online exams.

    Exam *cptr = new onlineexam[5];
    Exam *bptr = new offlineexam[5];

    // dynamic_cast with offline exams.

    onlineexam *c = dynamic_cast<onlineexam *>(cptr);
    offlineexam *b = dynamic_cast<offlineexam *>(bptr);

    std::cout << "Enter No of online exam objects\n";
    std::cin >> n;

    onlineexam *p = new onlineexam[n];
    std::cout << "Collecting Onlineexam Details\n";
    for (int i = 0; i < n; i++)
    {
        p[i].onlineexam::accept();
    }

    for (int i = 0; i < n; i++)
    {
        p[i].onlineexam::display();
    }

    std::cout << "Enter No of offline exam objects\n";
    std::cin >> NUM;

    offlineexam *q = new offlineexam[NUM];

    std::cout << "Collecting Offlineexam Details\n";

    for (int i = 0; i < NUM; i++)
    {
        q[i].offlineexam::accept();
    }

    for (int i = 0; i < NUM; i++)
    {
        q[i].offlineexam::display();
    }

    q[0].offlineexam::changelocation();
    q[0].offlineexam::display();

    // delete[] cptr;
    // delete[] bptr;
    return 0;
}