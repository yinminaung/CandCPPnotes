# include <iostream>
# include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;

    public:
        Person () {
            name = "Anonymous";
            age = 0;
        }
        Person(string yourname, int yourage) {
            name = yourname;
            age = yourage;
        }

        string getName() {
            return name;
        }

        int getAge() {
            return age;
        }
};

class Programmer : public Person {
    private:
        string jobTitle;
    
    public:
        Programmer() {
            jobTitle = "programmer";
        }
        Programmer (string job) {
            jobTitle = job;
        }

        Programmer (string yourName, int age, string job) : Person(yourName,  age) {
            jobTitle = job;
        }

        string getJobTitle() {
            return jobTitle;
        }
};
int main(){
    Person me("Yin Min Aung", 20);
    cout << me.getName() << endl;
    cout << me.getAge() << endl;

    Person you;
    cout << you.getName() << endl;
    cout << you.getAge() << endl;

    Programmer p1;
    cout << p1.getName() << endl;
    cout << p1.getAge() << endl;
    cout << p1.getJobTitle() << endl;

    Programmer p2("web developer");
    cout << p2.getName() << endl;
    cout << p2.getAge() << endl;
    cout << p2.getJobTitle() << endl;   

    Programmer p3("Okka", 24, "data scientist");
    cout << p3.getName() << endl;
    cout << p3.getAge() << endl;
    cout << p3.getJobTitle() << endl;

    return 0;
}