#include<iostream>
#include<string>

using namespace std;


void IncreaseDigit(string& number, int position) {

    const char nine = '9';
    const char zero = '0';

    if (number[position] == nine)
    {
        while (number[position] == nine && position >= 0) {
            number[position] = zero;
            if (position == 0) {
                number = "1" + number; 
                break; 
            }
            --position;
        }
    } else {
        ++number[position];
    }
}

void EqualizeNumber(string& number) {

    int dec, inc;
    inc = number.size() / 2; 
    dec = inc;

    if (number.size() % 2 == 0)
        --dec; 

    while (dec >= 0 && inc < (int) number.size())
    {
        number[inc] = number[dec];
        --dec;
        ++inc; 
    }
}

bool IsBiggerOrEqual(string& one, string& two) {
    if (one.size() != two.size()) { 
        return one.size() > two.size();
    }

    for (int i = 0; i < (int) one.size(); ++i) {
        if (one[i] != two[i])
            return one[i] > two[i];
    }

    return true; 
}

void GetNextPalindrome(string& number) {
    if (number.size() == 1) {
        number = "11";
        return; 
    }


    int center = number.size() / 2; 
    if (number.size() % 2 == 0) 
        --center;

    string original = number; 
    EqualizeNumber(number); 

    if (IsBiggerOrEqual(original, number)) { 
        IncreaseDigit(number, center);
        EqualizeNumber(number); 
    }
}


int main() {

    int cases;
    string number;

    cin >> cases;

    for (; cases > 0 ; --cases)
    {
        cin >> number; 
        GetNextPalindrome(number);
        cout << number << endl; 
    }
}
