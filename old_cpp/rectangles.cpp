#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

class point{
    public:
    double x, y;
};

class rectangle{
private:
    point top_left;
    point bot_right;

public:

    void init_rectangle(int t_x, int t_y, int b_x, int b_y){
        this->top_left.x = t_x; this->top_left.y = t_y;
        this->bot_right.x = b_x; this->bot_right.y = b_y;
    }

    void display(){

        for(int y=0; y != this->bot_right.y+1; y++)
        {
            for(int x=0; x != this->bot_right.x+1; x++)
            {
                if(x >= this->top_left.x && y >= this->top_left.y)
                {
                    if(x==this->top_left.x||y==this->top_left.y||x==this->bot_right.x||y==this->bot_right.y)
                        cout << "# ";
                    else 
                        cout << "  ";
                }
                else
                    cout << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }

    double area(){
        return ((this->bot_right.x - this->top_left.x) * (this->bot_right.y - this->top_left.y));
    }

    double perimeter(){
        return ((2 * (this->bot_right.x - this->top_left.x)) + (2 * (this->bot_right.y - this->top_left.y)));
    } 

    bool square(){
        if((this->bot_right.x - this->top_left.x) == (this->bot_right.y - this->top_left.y))
            return true;
        
        return false;
    }
    
    point center_point(){
        point mid_point;
        mid_point.x = (this->bot_right.x + this->top_left.x)/2.0;
        mid_point.y = (this->bot_right.y  +this->top_left.y)/2.0;
        return mid_point;
    }

    void out(){
        this->display();
        point mid_point = this->center_point();
        cout << "area: " << this->area() << endl;
        cout << "perimeter: " << this->perimeter() << endl;
        printf("center: (%.2f, %.2f)\n", mid_point.x, mid_point.y);
        cout << "square: " << ((this->square())? "yes" : "no") << endl;
    }

};

int main(){
    rectangle rect;
    int t_x, t_y, b_x, b_y;

    cin >> t_x >> t_y >> b_x >> b_y;
    rect.init_rectangle(t_x, t_y, b_x, b_y);
    rect.out();

    return 0;
}