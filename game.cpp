//Tejas Kakade
//game.cpp
//Monopoly Project

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//40 spaces on board in order
string spacename[] = {"Go","Mediterranean Avenue","Community Chest","Baltic Avenue","Income Tax","Reading Railroad","Oriental Avenue","Chance","Vermont Avenue","Connecticut Avenue","Jail / Just Visiting","St. Charles Place","Electric Company","States Avenue","Virginia Avenue","Pennsylvania Railroad","St. James Place","Community Chest","Tennessee Avenue","New York Avenue","Free Parking","Kentucky Avenue","Chance","Indiana Avenue","Illinois Avenue","B. & O. Railroad","Atlantic Avenue","Ventnor Avenue","Water Works","Marvin Gardens","Go To Jail","Pacific Avenue","North Carolina Avenue","Community Chest","Pennsylvania Avenue","Short Line","Chance","Park Place","Luxury Tax","Boardwalk"};
//if property value is 0, the space is special
#define spacenumber 0
#define price       1 //price to buy property
#define hprice      2 //price to buy house
//#define rent      3 //rent
//#define rent1     4 //rent with 1 house
//#define rent2     5 //rent with 2 houses
//#define rent3     6 //etc
//#define rent4     7 //etc
#define rent5       8 //rent with hotel
#define mortgage    9 //mortgage
int propertyvalues[40][10] = {{0,0,0,0,0,0,0,0,0},                              //go
                              {1,60,50,2,10,30,90,160,250,30},                  //mediterranean
                              {2,0,0,0,0,0,0,0,0},                              //community
                              {3,60,50,4,20,60,180,320,450,30},                 //baltic
                              {4,0,0,0,0,0,0,0,0},                              //income tax
                              {5,200,0,0,0,0,0,0,0},                            //railroad
                              {6,100,50,6,30,90,270,400,550,50},                //oriental
                              {7,0,0,0,0,0,0,0,0},                              //chance
                              {8,100, 50, 6, 30, 90, 270, 400, 550, 50},        //vernmont
                              {9,120, 50, 8, 40, 100, 300, 450, 600, 60},       //connecticut
                              {10,0,0,0,0,0,0,0},                               //jail
                              {11,140, 100, 10, 50, 150, 450, 625, 750, 70},    //st charles
                              {12,150,0,0,0,0,0,0,0},                           //electric company
                              {13,140, 100, 10, 50, 150, 450, 625, 750, 70},    //states ave
                              {14,160, 100, 12, 60, 180, 500, 700, 900, 80},    //virginia
                              {15,200,0,0,0,0,0,0,0},                           //railroad
                              {16,180, 100, 14, 70, 200, 550, 750, 950, 90},    //st james
                              {17,0,0,0,0,0,0,0,0},                             //community
                              {18,180, 100, 14, 70, 200, 550, 750, 950, 90},    //tennesee
                              {19,200, 100, 16, 80, 220, 600, 800, 1000, 100},  //ny ave
                              {20,0,0,0,0,0,0,0,0},                             //free parking
                              {21,220, 150, 18, 90, 250, 700, 875, 1050, 110},  //kentucky
                              {22,0,0,0,0,0,0,0,0},                    //chance
                              {23,220, 150, 18, 90, 250, 700, 875, 1050, 110},         //indiana
                              {24,240, 150, 20, 100, 300, 750, 925, 1100, 120},        //illinois
                              {25,200,0,0,0,0,0,0},                    //BO railroad
                              {26,260, 150, 22, 110, 330, 800, 975, 1150, 130},        //atlantic ave
                              {27,260, 150, 22, 110, 330, 800, 975, 1150, 130},        //ventnor
                              {28,150,0,0,0,0,0,0},                    //water works
                              {29,280, 150, 24, 120, 360, 850, 1025, 1200, 140},     //marvin gardens
                              {30,0,0,0,0,0,0,0},                    //go to jail
                              {31,300, 200, 26, 130, 390, 900, 1100, 1275, 150},        //pacific
                              {32,300, 200, 26, 130, 390, 900, 1100, 1275, 150},       //nc ave
                              {33,0,0,0,0,0,0,0,0},                                    //community chest
                              {34,320, 200, 28, 150, 450, 1000, 1200, 1400, 160},    //penn ave
                              {35,200,0,0,0,0,0,0},                    //railroad?
                              {36,0,0,0,0,0,0,0,0},                    //chance
                              {37,350, 200, 35, 175, 500, 1100, 1300, 1500, 175},      //park place
                              {38,0,0,0,0,0,0,0,0},                    //lux tax
                              {39,400, 200, 50, 200, 600, 1400, 1700, 2000, 200}};    //boardwalk




//CLASS PLAYER
class Player{
protected:
    int balance = 0;
    string name;
    int location = 0;

public:
    Player (string n) { // default constructor
        balance = 1500;
        name = n;
        location = 0;
    }

    virtual int getSpace() = 0;                 // get player location
    virtual string getname() = 0;               // get player name
    virtual int getbal() = 0;                   // get player balance
    virtual bool getreal() = 0;                 // check if player is a computer or not
    virtual void roll() = 0;                    // roll the dice for the player
    virtual void debit(int value) = 0;          // debit player
    virtual void deposit(int value) = 0;        // deposit money into player account
    virtual void move_player(int new_loc) = 0;  // change the players location if changed by a card
    virtual bool getBankrupt() = 0;             // bankrupt?
    virtual void setBankrupt(bool val) = 0;     // set if bankrupt
    virtual bool getstatus() = 0;               // is game over?
    virtual void setstatus(bool a) = 0;         // set game status
};




//USER PLAYER
class Console_Player: public Player { // derived class
protected:
    bool real;
    bool bankrupt;
    bool status;
  
public:
    Console_Player(string n): Player(n) { // derived constructor for user player
        real = true;
        bankrupt = false;
        status = true;
    }

    virtual int getSpace(){ // get the location of the player
        return location;
    }

    virtual string getname() { // get the player's name
        return name;
    }

    virtual int getbal() { // check player's balance
        return balance;
    }

    virtual bool getreal() { // check if player is a computer or not.
        return real;
    }

    virtual bool getstatus(){ // get status
        return status;
    }

    virtual void setstatus(bool a){ // set what the status is
        status = a;
    }

    virtual void roll() { // roll the dice and move the player for that turn
        int dice1, dice2;

        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;

        location += dice1 + dice2;
        if(location >= 40){
            location-=40;
            balance += 200;
        }
    }

    // function to remove money from a player's balance, used in transfer and for chance/community chest cards.
    virtual void debit(int money) {
        balance -= money;
        return;
    }
    
    // function to deposit money into a players balance
    virtual void deposit(int money) {
        balance += money;
        return;
    }

    // move the player to a new location as determined by a chance or community chest card
    virtual void move_player(int new_location) {
        // if the player has already passed the location then they must pass GO to get to that location again.
        if(new_location == 10) {
            if(new_location < location) {
                balance += 200;
            }
        }
        location = new_location;
    }

    virtual bool getBankrupt() {
        return bankrupt;
    }

    virtual void setBankrupt(bool val) {
        bankrupt = val;
    }
};




//CPU PLAYER 
class CPU_Player: public Console_Player { // derrive auto class
public:
    CPU_Player(string n): Console_Player(n) {
        real = false;
        bankrupt = false;
    }
};

int dice_roll () { // rolls dice, non-class function
    int roll;
    int roll1;
    int roll2;
    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;
    roll = roll1 + roll2;
    return roll;
}




//BOARD SPACE
class space{
public:
    string sname;     // name of space, ex:boardwalk
    bool available;   // available to purchase property?
    int numhouses;
    int numhotels;
    Player * owner;
};




//GAME BOARD
class board{
private:
    space b[40];              //40 spaces that make up board
public:
    board(){
        for(int i = 0; i<40; i++){
            b[i].sname = spacename[i];
            if(propertyvalues[i][price] > 0)b[i].available = true;
            else b[i].available = false;
            b[i].owner = nullptr;
            b[i].numhouses = 0;
            b[i].numhotels = 0;
        }
    }
  
    void checkspace(Player * p){  //check what to do on the space
        int currspace = p->getSpace();
        cout<< "You landed on " << spacename[currspace] << endl;
        if(propertyvalues[currspace][price] == 0){ //special spaces
            //community chest
            if((currspace == 2) || (currspace == 17) || (currspace == 33)){
                cout << "Community chest!" <<endl;
                communitychest(p);
            }
            //chance
            if((currspace == 7) || (currspace == 22) || (currspace == 36)){
                cout << "Chance!" <<endl;
                chance(p);
            }
            //special spaces
            //income tax 4
            if(currspace == 4){
                cout << "Income tax, pay $200" <<endl;
                p->debit(200);
            }
            //go to jail 30
            if(currspace == 30){
                cout << "Go to jail, pay $100 fine" <<endl;
                move(30);
                p->debit(100);
            }
            //luxury tax 38
            if(currspace == 38){
                cout << "Luxury tax, pay $75" <<endl;
                p->debit(75);
            }
        }
        else{
            if(b[currspace].available){   //space is available to purchase
                if(p->getreal()){
                    char answer;
                    cout<<"Would you like to buy "<< spacename[currspace] << " for $" << propertyvalues[currspace][price] << "? respond Y or N" << endl;
                    cin >> answer;
                    if(answer == 'Y')buyspace(currspace, p);
                    else return;
                }
                else{ //cpu decision
                    if(p->getbal() >= (propertyvalues[currspace][price] / 3)) buyspace(currspace, p);
                    else return;
                }
            }
            else{
                //railroad or utilities
                if((currspace == 12) || (currspace == 28) || (currspace == 5) || (currspace == 15) || (currspace == 25) || (currspace == 35))payUtilities(currspace,p);
                else{
                    payRent(currspace, p);
                }
            }
        }
    }

    void printboard(){ //output board
        ofstream op;
        op.open("board.txt");
        //header for board stats
        op<<"		Board Information		"<<endl;
        for(int i=0; i<40; i++){
            //space number, space name, space value, space owner
            op<<i+1<<" Owner: ";
            if(b[i].owner == nullptr) op << " None";
            else op << b[i].owner->getname();
            op<< " Space: " << b[i].sname;
            if(propertyvalues[i][1]>0) op << " Value:" << propertyvalues[i][1] <<endl;
            else op<<endl;
        }
        op.close();
    }

    //player chooses to buy space
    void buyspace(int s, Player * p){
        //arguments will need to be added to check if player has the funds and then debt them
        //b[s].owner = p;
        p->debit(propertyvalues[s][price]);
        b[s].available = false;
        b[s].owner = p;
    }

    //player's balance is negative and must sell all properties
    void liquidate(Player * p){
        for(int i = 0; i<40; i++){
            if(b[i].owner == p){
                p->deposit(propertyvalues[i][mortgage]);
                b[i].owner = nullptr;
                b[i].available = true;
            }
        }
    }

    //player lands on an owned space and must pay rent
    void payRent(int s, Player * p){
        int rentamt = 0;
        //if numhouses = 0, get propertyvalue[s][3], 1 house [s][4]
        rentamt = propertyvalues[s][b[s].numhouses+3];
        //override if there is a hotel
        if(b[s].numhotels == 1) rentamt = propertyvalues[s][rent5];
        p->debit(rentamt);
        cout << "You paid " << rentamt <<" in rent." <<endl;
        b[s].owner->deposit(rentamt);
    }

    void communitychest(Player * p){
        switch(rand()%5) {
            case 0: {
                cout<< "Bank error in your favor +$20" <<endl;
                p->deposit(20);
                return;
            }
            case 1: {
                cout<< "Doctor's fees, pay $50" <<endl;
                p->debit(50);
                return;
            }
            case 2: {cout<< "Income tax return +$20" <<endl;
                p->deposit(20);
                return;
            }
            case 3: {
                cout<< "School fees, pay $50" <<endl;
                p->debit(50);
                return;
            }
            case 4: {cout<< "Stock sold +$50" <<endl;
                p->deposit(50);
                return;
            }
            default: return;
        }
    }

    void chance(Player * p){
        switch(rand()%5){
            case 0: {
                cout<< "Advance to Go, collect $200" <<endl;
                move(0);
                return;
            }
            case 1: {
                cout<< "Advance to St. Charles Place" <<endl;
                move(11);
                return;
            }
            case 2: {cout<< "Advance to Boardwalk" <<endl;
                move(39);
                return;
            }
            case 3: {cout<< "Advance to Illinois Ave" <<endl;
                move(24);
                return;
            }
            case 4: {cout<< "Go directly to jail" <<endl;
                move(10);
                return;
            }
            case 5: {cout<< "Advance to Reading Railroad" <<endl;
                move(5);
                return;
            }
            case 6: {cout<< "Your building and loan matures, collect $150" <<endl;
                p->deposit(150);
                return;
            }
            case 7: {cout<< "Bank pays you dividend of $50" <<endl;
                p->deposit(50);
                return;
            }
            case 8: return;
            case 9: {cout<< "Pay poor tax of $15" <<endl;
                p->debit(15);
                return;
            }
            case 10: {cout<< "Go back 3 spaces" <<endl;
                int currspace = p->getSpace();
                move(currspace-3);
                return;
            }
            default: return;
        }
    }

    //player chooses to buy property
    void buyhouses(Player * p){
        char answer;
        if(p->getreal()){
            cout<<"Would you like to buy a house for any space? Enter Y or N" <<endl;
            cin >> answer;
            if(answer == 'Y'){
                for(int i = 0; i<40; i++){
                    if(b[i].owner == p){
                        int h = 0;                          //num houses to buy
                        int hp = propertyvalues[i][hprice]; //house price per
                        if(hp != 0){
                            cout<<"How many houses would you like to buy for " << b[i].sname << "for $" << hp << endl;
                            cout<<"Enter a number 0-5, with 5 as a hotel." <<endl;
                            cin >> h;
                            p->debit(hp*h);
                            b[i].numhouses += h;
                            if(b[i].numhouses > 4){
                                b[i].numhouses = 0;
                                b[i].numhotels = 1;
                            }
                        }
                    }
                }
            }
        }
        else{
            //cpufunction
            for(int i = 0; i<40; i++){
                if(b[i].owner == p){
                    int h = 0;                          //num houses to buy
                    int hp = propertyvalues[i][hprice]; //house price per
                    if(hp != 0){
                        if(p->getbal() >= 5*hp){h = 1;
                            p->debit(hp*h);
                            cout<<p->getname()<<" bought a house"<<endl;
                            b[i].numhouses += h;
                            if(b[i].numhouses > 4){
                                b[i].numhouses = 0;
                                b[i].numhotels = 1;}
                        }
                    }
                }
            }
        }
        return;
    }

    void payUtilities(int s, Player * p){
        int currspace = p->getSpace();
        int ownedRR = 0;  //utilities at 12 and 28  //rand(12) x 4 for one  x 10 for both
        int amt = 0;
        if((currspace == 12) || (currspace == 28)){
            if(((currspace == 12) && (b[12].owner == b[28].owner)) || ((currspace == 28) && (b[12].owner == b[28].owner))){//owns both
                amt = dice_roll() * 10;
            }
            else amt = dice_roll() * 4;
        }
        if((currspace == 5) || (currspace == 15) || (currspace == 25) || (currspace == 35)){
            if(b[currspace].owner == b[5].owner){ownedRR+=1;}
            if(b[currspace].owner == b[15].owner){ownedRR+=1;}
            if(b[currspace].owner == b[25].owner){ownedRR+=1;}
            if(b[currspace].owner == b[35].owner){ownedRR+=1;}
            amt = ownedRR * 25;
        }
        p->debit(amt);
        b[currspace].owner->deposit(amt);
        cout << p->getname() << " paid " << b[currspace].owner->getname() << " $" << amt << endl;
    }

};



//MAIN
int main() {
    srand(time(0)); // init time for RNG
    board b;
    int pSize=10;
    int cpuSize=10;
    int totalSize = 0;
    string n[8];
    string cpuNames[8] = {"CPU 1", "CPU 2", "CPU 3", "CPU 4", "CPU 5", "CPU 6", "CPU 7", "CPU 8"};

    cout << "Welcome to Monopoly!" << endl;
    cout << "Enter the number of human players: ";
    cin >> pSize;
    cout << endl << "Enter the number of CPU players: ";
    cin >> cpuSize;
    cout << endl;

    if((pSize == 10) && (cpuSize == 10)){
        pSize = 0;
        cpuSize = 2;
    }

    totalSize = pSize+cpuSize;

    for(int i = 0; i<pSize; i++){
        cout << endl << "Enter name for Player "<< i+1 << endl;
        cin >> n[i];
    }

    vector<Player *> allplayers;

    if(pSize>0){Console_Player * a = new Console_Player (n[0]); allplayers.push_back(a);}
    if(pSize>1){Console_Player * b = new Console_Player (n[1]); allplayers.push_back(b);}
    if(pSize>2){Console_Player * c = new Console_Player (n[2]); allplayers.push_back(c);}
    if(pSize>3){Console_Player * d = new Console_Player (n[3]); allplayers.push_back(d);}
    if(pSize>4){Console_Player * e = new Console_Player (n[4]); allplayers.push_back(e);}

    if(cpuSize>0){CPU_Player * f = new CPU_Player (cpuNames[0]); allplayers.push_back(f);}
    if(cpuSize>1){CPU_Player * g = new CPU_Player (cpuNames[1]); allplayers.push_back(g);}
    if(cpuSize>2){CPU_Player * h = new CPU_Player (cpuNames[2]); allplayers.push_back(h);}
    if(cpuSize>3){CPU_Player * i = new CPU_Player (cpuNames[3]); allplayers.push_back(i);}
    if(cpuSize>4){CPU_Player * k = new CPU_Player (cpuNames[4]); allplayers.push_back(k);}
    if(cpuSize>5){CPU_Player * l = new CPU_Player (cpuNames[5]); allplayers.push_back(l);}
    if(cpuSize>6){CPU_Player * m = new CPU_Player (cpuNames[6]); allplayers.push_back(m);}
    if(cpuSize>7){CPU_Player * n = new CPU_Player (cpuNames[7]); allplayers.push_back(n);}

    bool status = false;

    int playersout = 0;
    int c=0;

    cout << endl << endl << endl << "--- START GAME ---" << endl;
    while ((!status)) {
        Player * currplayer = allplayers[c];
        if(currplayer->getstatus()){
            cout << "Current turn is:" << currplayer->getname() << endl;
            currplayer->roll();
            cout << "Player's new space is " << currplayer->getSpace() << endl;
            cout<<currplayer->getname()<<" balance is $"<<currplayer->getbal()<<endl;
            b.checkspace(currplayer);
            if(currplayer->getbal() <= 0)
                cout<<currplayer->getname()<<" balance is $"<<currplayer->getbal()<<endl;
            b.buyhouses(currplayer);

            if(currplayer->getbal()<0){
                cout<<currplayer->getname()<<" must sell property"<<endl;
                b.liquidate(currplayer);
                cout<<currplayer->getname()<<" balance is $"<<currplayer->getbal()<<endl;
            }

            if(currplayer->getbal()<0){
                cout<<currplayer->getname()<<" must sell property"<<endl;
                b.liquidate(currplayer);
                cout<<currplayer->getname()<<" balance is $"<<currplayer->getbal()<<endl;
                cout<<"There are " << totalSize - playersout - 1 << " players remaining" <<endl;
            }

            if(currplayer->getbal()<0){
                cout << currplayer->getname() << " is out of the game" << endl;
                currplayer->setstatus(false);
                playersout += 1;
            }

            if(totalSize-1 == playersout) status = true;

        }
        c++;
        if(c>=totalSize){
            b.printboard();
            c = 0;}   //turn cycle over

    }
    cout << "Game has ended!"<<endl;
    for(int i = 0; i < pSize+cpuSize; i++){
        Player * currplayer = allplayers[i];
        if(currplayer->getstatus()){
            cout<<endl;
            cout << currplayer->getname() << " has won!"<<endl;
            cout<<endl;
        }
    }
    return 0;
}
