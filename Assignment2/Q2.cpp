#include <iostream>
using namespace std;
class Rectangle{
    int length;
    int breadth;
    int area;
    int peri;
    public:
        void input();
        int area();
        int perimeter();
        void display();
};
void Rectangle::input(){
    cout<<"Enter the length: "<<endl;
    cin>>length;
    cout<<"Enter the breadth: "<<endl;
    cin>>breadth;
}
int Rectangle::area(){
    return length*breadth;
}
int Rectangle::perimeter(){
    return 2*(length+breadth);
}
void Rectangle::display(){
    Rectangle r1;
    cout<<"Length: "<<length<<endl;
    cout<<"Breadth: "<<breadth<<endl;
    cout<<"Area: "<<r1.area()<<endl;
    cout<<"Perimeter: "<<r1.perimeter()<<endl;

}
int main() {
    Rectangle r1;

    return 0;
}