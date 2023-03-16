#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
//        void set_index(int index) { // setter
//            index_ = index;
//        }
//        int index() { // getter
//            return index_;
//        }

    void set_name(const string &name) {
        name_ = name;
    }
    void set_surname(const string &surname) {
        surname_ = surname;
    }
    void set_album_number(const int &number) {
        if(number < 10000 || number > 999999){
            cout << "wrong album number" << endl;
            return;
        }
        album_number_ = number;
    }
    void set_grades(double grade) {
        if(grade < 2.0 || grade > 5.0){
            cout << "wrong grade" << endl;
            return;
        }
        grades_.emplace_back(grade);
    }

    //getters
    string name() {
        return name_;
    }

    string surname() {
        return surname_;
    }

    int album_number() {
        return album_number_;
    }

    const vector<double> &grades() const{
            return grades_;
    }

    double mean_grade() {
        double sum = 0;
        for (double grade : grades_) {
            sum += grade;
        }
        return sum/grades_.size();
    }

    bool passed_semester() {
        int count = 0;
        for (double grade : grades_) {
            if (grade == 2.0) {
                count++;
            }
        }
        return count == 1;
    }

    void summary() {
        cout << "student's full name: " << name_ << " " << surname_ << endl;
        cout << "album number: " << album_number_ << endl;
        cout << "grades: ";
        for (double grade : grades_) {
            cout << grade;
            cout << " ";
        }
        cout << "mean: " << mean_grade() << endl << endl;
        if (passed_semester() == 1) {
                cout << "Passed the semester" << endl;
            } else {
                cout << "Failed the semester" << endl;
            }
    }

private:
    string name_;
    string surname_;
    int album_number_;
    vector<double> grades_;
};


// new class


class Complex {
public:
    Complex(double real, double imaginary) {
        real_ = real;
        imaginary_ = imaginary;
    }
    Complex(double real) {
        real_ = real;
        imaginary_ = 0;
    }

    double real() {
        return real_;
    }

    double imaginary() {
        return imaginary_;
    }

    void set_real(double real) {
        real_ = real;
    }
    void set_imag(double imaginary) {
        imaginary_ = imaginary;
    }

    void print() {
        cout << real_;
            if (imaginary_ < 0) {
                cout << "-";
                imaginary_ = -imaginary_;
            } else {
                cout << "+";
            }
            cout << imaginary_ << "i" << endl;
    }

    Complex add(const Complex &other) {
        return Complex(real_ + other.real_, imaginary_ + other.imaginary_);
    }

    Complex add(double real) {
        return Complex(real_ + real, imaginary_);
    }

private:
    double real_;
    double imaginary_;
};


int main()
{

    Student a;

    a.set_name("marcin");
    a.set_surname("michalski");
    a.set_album_number(112233);
    a.set_grades(5);
    a.set_grades(2);
    a.set_grades(4);
    a.set_grades(2);
    a.summary();

    cout << "\n \n \n \n";

    Complex a1(1.0, -2.0);
    Complex b1(3.14);

    b1.set_imag(-5);

    Complex c1 = a1.add(b1);

    c1.print();

    Complex d1 = a1.add(2.5);

    d1.print();


    return 0;
}
