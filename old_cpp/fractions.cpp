#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class fraction{
private:
    int num, den, gcd;

public:
    void set_values(string& num, string& den){
        stringstream(num) >> this->num;
        stringstream(den) >> this->den;
    }

    int get_gcd(int x, int y){if(x == 0) return y; return get_gcd(y % x, x); }

    void simplify(){
        this-> gcd = get_gcd(this->num, this->den);
        int t_num = this->num / this->gcd;
        int t_den = this->den / this->gcd;
        
        if(t_num == t_den)
            cout << t_den << endl;
        else
            cout << t_num << "/" << t_den << endl;
    }

    void add(fraction& b){
        if(this->den == b.den){
            this->num += b.num;
        } else {
            this->num = (this->num * b.den) + (b.num * this->den);
            this->den *= b.den;
        }
    }

    void minus(fraction& b){
        if(this->den == b.den){
            this->num -= b.num;
        } else {
            this->num = (this->num * b.den) - (b.num * this->den);
            this->den *= b.den;
        }
    }

    void multiply(fraction& b){
        this->num *= b.num;
        this->den *= b.den;
    }

    void divide(fraction& b){
        this->num *= b.den;
        this->den *= b.num;
    }
};

void set(fraction &fract, string &tmp_fraction){
    string temp_num, temp_den;

    temp_num = tmp_fraction.substr(0, tmp_fraction.find("/"));
    if(tmp_fraction.find("/") == -1)
        temp_den = "1";
    else 
        temp_den = tmp_fraction.substr(tmp_fraction.find("/")+1, tmp_fraction.size()-1);

    fract.set_values(temp_num, temp_den);
}

void input(int op, fraction& a, fraction& b){
    string temp_frac_a, temp_frac_b;
    cin >> temp_frac_a >> temp_frac_b;

    set(a, temp_frac_a);
    set(b, temp_frac_b);

    switch(op){
        case 1:
            a.add(b);
            a.simplify();
        break;
        
        case 2:
            a.minus(b);
            a.simplify();  
        break;

        case 3:
            a.multiply(b);
            a.simplify();
        break;

        case 4:
            a.divide(b);
            a.simplify();
        break;

        default:
            cout << "invalid operator!" << endl;
        break;
    }
}

void single_input(fraction& a){
    string temp_frac_a;
    cin >> temp_frac_a;
    set(a, temp_frac_a);
    a.simplify();
}

int main(){
    fraction a, b;
    int op; cin >> op;
    (op == 5)? single_input(a) : input(op, a, b);
}