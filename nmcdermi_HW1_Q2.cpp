#include <iostream>
#include <string>

using namespace std;

const int N = 10;

class Check{
    public:
    Check(){ //default constructor
        CheckMemo = "";
        CheckNum = 0;
        CheckAmount = 0;
    }
    string getMemo(){return CheckMemo;}
    int getNum(){return CheckNum;}
    float getAmount(){return CheckAmount;}
    void setMemo(string s){CheckMemo = s;}
    void setNum(int n){CheckNum = n;}
    void setAmount(float a){CheckAmount = a;}
private:
    string CheckMemo;
    int CheckNum;
    float CheckAmount;

};

class CheckBook{
    public:
    int balance;
    int numOfChecks;
    float lastDeposit;
    Check checks[N];
    int checkLimit = N;
    bool writeCheck(float amount) {
        if (amount <= balance) {
            string memo;
            cout<<"memo?: ";
            cin>>memo;
            checks[numOfChecks].setMemo(memo);
            checks[numOfChecks].setNum(numOfChecks);
            checks[numOfChecks++].setAmount(amount);
            balance -= amount;
            lastDeposit = amount;
            allChecks++;
            return true;
        }
            else{
                return false;
            }

    }

    void deposit(float amount){balance += amount;}

    void displayChecks(){
        for (int i = numOfChecks - 1; i>=0; i--){
            cout<<checks[i].getNum()
                <<" "<<checks[i].getAmount()
                <<" "<<checks[i].getMemo()<<'\n';

        }
    }

    CheckBook(){
        balance = 0;
        numOfChecks = 0;

    }
    CheckBook(int b){
        balance = b;
        numOfChecks = 0;
    }

    int getallChecks(){return allChecks;}

    private:
    static int allChecks;
};

int CheckBook::allChecks = 0;





int main(){
    CheckBook cb1(1000), cb2(500);
    for (int i = 0; i<10; i++)
    {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }

    cout<<"cb1 check details"<<endl;
    cb1.displayChecks();
    cout<<"cb2 check details"<<endl;
    cb2.displayChecks();

    cout<<cb1.getallChecks()<<endl;
    cout<<cb2.getallChecks()<<endl;
}

