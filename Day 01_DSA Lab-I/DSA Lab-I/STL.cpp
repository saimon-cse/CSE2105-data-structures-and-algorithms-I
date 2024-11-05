#include<bits/stdc++.h>
using namespace std;

class Student{
private:
    float cgpa;
public:
    string name;
    int age;

    void setCgpa(float x){
        cgpa = x;
    }
    void show(){
        cout << "Name: " << name << "\nAge: "<< age << "\nCGPA: "<< cgpa << endl;
    }

};

class Car{
private:
    string bName;
public:
    string brand;
    int price;

    Car(string b, int p){
        brand = b;
        price = p;
    }

    void setByerName(string n){
        bName = n;
    }

    void show(){
        cout << "Brand: " << brand << "\nPrice: " << price << "\nCustomer Name: " << bName << endl;
    }

};


int main(){
    map<float, string> student;

    student[3.52] = "Saimon";
    student[3.6] = "Ehasan";
    student[3.5] = "Aupo";
    student[3.88] = "Deb";

    // map<float, string>::iterator it;

    for(auto it = student.begin(); it != student.end(); it++){
        cout << it->first << " - " << it->second << endl;
    }
    
    Student student1;
    student1.name = "Saimon";
    student1.age = 22;
    student1.setCgpa(3.5);
    // student1.show();


    Car car1("BMW", 1000);
    car1.setByerName("Saimon Islam");
    // car1.show();

    vector<string> person;
    for(int i=0; i<2; i++){
        string temp ;
        cin >> temp;
        person.push_back(temp);
    }
    string p = person[0] + " + " + person[1];
    cout << p;
}