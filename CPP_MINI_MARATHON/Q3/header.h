#ifndef HEADER_H
#define HEADER_H
#include <cstring>
class Player
{
    int playerid;
    char *pname;
    int score[3];

public:
    Player();
    Player(int, char *, int[]);
    Player(Player &);
    ~Player();
    int getPlayerid() const { return playerid; }
    void setPlayerid(int playerid_) { playerid = playerid_; }
    char *getPname() const { return pname; }
    void setPname(const char *pname_) { strcpy(pname, pname_); }
    float average(int[]);
    void accept();
    void display();

    
    bool operator==(Player &s1);
    bool operator<(Player &s1);
    int operator[](int index);

    friend std::ostream &operator<<(std::ostream &os, const Player &m);
};

#endif // HEADER_H
