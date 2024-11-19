#include<iostream>
using namespace std;

class Person{
    const long long aadharNo;
    long long contectNo;
    const string panNo;
    string address;

    public:
    Person():aadharNo(000000000000), panNo(" "){
         address=" ";
         contectNo=0;
    }

    Person(long long a, long long b, string c, string d):aadharNo(a), panNo(c){
        address=d;
        contectNo=b;
    }

    long long get_aadhar() const{
        return aadharNo;
    }

    long long get_contectNo(){
        return contectNo;
    }

    string get_panNo() const{
        return panNo;
    }

    string get_address(){
        return address;
    }
    
};

int main(){
    Person p1(460676439845, 7877886585, "GIPPA1613A", "ABCD");
    cout<<p1.get_aadhar()<<endl;
    cout<<p1.get_panNo()<<endl;
    cout<<p1.get_address()<<endl;
    cout<<p1.get_contectNo()<<endl;
}
