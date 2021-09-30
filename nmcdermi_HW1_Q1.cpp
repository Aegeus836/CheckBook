#include <iostream>
#include <string>

using namespace std;

const int N = 5;

struct Check{
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
            cout<<"Input memo for check: ";
            cin>>checks[numOfChecks].CheckMemo;
            checks[numOfChecks++].CheckAmount = amount;
            checks[numOfChecks-1].CheckNum = numOfChecks;
            balance -= amount;
            lastDeposit = amount;
            return true;
        }
            else{
                return false;
            }

    }

    void deposit(float amount){balance += amount;}

    void displayChecks(){
        for (int i = numOfChecks - 1; i>=0; i--){
            cout<<"Check: "<<checks[i].CheckNum
                <<", amount: "<<checks[i].CheckAmount
                <<", memo: "<<checks[i].CheckMemo<<'\n';

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

    private:
};





int main(){
    CheckBook cbl(100);
    for (int i = 0; i<5; i++)
    {
        float amount;
        cout<<"What is the check amount: ";
        cin >> amount;
        cbl.writeCheck(amount);
    }
    cbl.displayChecks();
        return 0;

}

