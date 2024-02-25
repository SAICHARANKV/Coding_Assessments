#include <iostream>
#include "header.h"
#include <cstring>
Player::Player()
{
    playerid = 0;
    pname = new char[30];
    strcpy(pname, "sunny");
    score[0] = 33;
    score[1] = 33;
    score[2] = 33;
}
Player::Player(int pid, char *pe, int s[]) : playerid(pid)
{
    int m[3];
    playerid = 0;
    pname = new char[30];
    strcpy(pname, pe);
    m[0] = 66;
    m[1] = 66;
    m[2] = 66;
    for (int i = 0; i < 3; i++)
    {
        score[i] = m[i];
    }
}

Player::Player(Player &p1)
{
    pname = new char[30];
}

Player::~Player()
{
    delete[] pname;
}

void Player::accept()
{
    std::cout << "\nEnter Details\n";
    std::cout << "Player ID:\t";
    std::cin >> playerid;
    std::cout << "Player name:\t";
    pname = new char[30];
    std::cin >> pname;
    std::cout << "Enter 3 Scores\n";
    for (int i = 0; i < 3; i++)
    {
        std::cin >> score[i];
    }
}

void Player::display()
{
    std::cout << "\nDetails\n";
    std::cout << playerid << "\t";
    std::cout << pname << "\t";
    for (int i = 0; i < 3; i++)
    {
        std::cout << score[i] << "\t";
    }
    std::cout << std::endl;
    float avg_score = average(score);
    std::cout << avg_score << std::endl;
}
float Player::average(int a[])
{
    float avg = 0;
    int sum = 0;
    sum = a[0] + a[2] + a[3];
    avg = float(sum) / 3.0f;
    return avg;
}

// Overloading Functions
//  ==
bool Player::operator==(Player &s1)
{
    return this->playerid == s1.playerid;
}

// <
bool Player::operator<(Player &s1)
{
    return this->score[0] < s1.score[0];
}

// []
int Player::operator[](int index)
{
    if (index < 0 || index > (strlen(pname) + 1))
    {
        std::cout << "Index out of bounds";
    }
    else
        return pname[index];
}

std::ostream &operator<<(std::ostream &os, const Player &m)
{
    os << "\n"
       << m.getPname() << std::endl;
    return os;
}