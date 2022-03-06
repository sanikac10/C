#include<iostream>
using namespace std;
class calculate{
    public:
    void area(int a, int b){
        cout<<"The area of rectangle is "<<(a*b);
    }
    void area(double r){
        cout<<endl<<"The area of circle is ?<<(3.14*r*r)";
    }
    void area(int l){
        cout<<endl<<"The area of square is ?<<(l*l)";
    }
   
};
int main(){
    calculate a;
    a.area(2,5);
    a.area(2);
    a.area(4.0);
}
