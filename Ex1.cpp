#include<iostream>
using namespace std;
class Student{
    int reg_no;
    char name[100];
    float marks[5];
    public:
        void input();
        void display();

};
void Student::input(){
        cout<<"Enter the  registration number of students"<<endl;
        cin>>reg_no;
        cout<<"Enter the  name of student"<<endl;
        cin>>name;
        cout<<"Enter the  marks of students for 5 subjects"<<endl;
        for(int j = 0 ; j<5 ; j++){
             cin>>marks[j];
        }
} 
void Student::display(){
    cout<<"Information";
    cout<<endl;
    cout<<"Registration Number is: "<<reg_no<<endl;
    cout<<"Name: "<<name<<endl;
    for(int j = 0 ; j<5 ; j++){
        cout<<"Marks of subject: "<<j+1<<" "<<marks[j]<<endl;
        }
   

}
int main(){
    Student st[5];
    for (int i = 0 ; i<5 ; i++){
        st[i].input();
    }
    for (int i = 0 ; i<5 ; i++){
        st[i].display();
    }
}