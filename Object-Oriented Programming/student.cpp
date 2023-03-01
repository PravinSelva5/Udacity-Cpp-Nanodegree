#include <cassert>
#include <stdexcept>
#include <string>

using std::string;


// TODO: Define "Student" class
class Student {
 public:
  // constructor
    Student(string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa){};
  // accessors
    string getName() const { return name_; }
    int getGrade() const { return grade_; }
    float getGPA() const { return gpa_; }
  // mutators
    void setName(string name){
        name_ = name;
    }
    void setGrade(int grade){
        if( grade >= 0 && grade <= 12){
            grade_ = grade;
        }
    }
    void setGPA(float gpa){
        if( gpa >= 0.0 && gpa <= 4.0){
            gpa_ = gpa;
        }
    }

 private:
  // name
    string name_;
  // grade
    int grade_;
  // GPA
    float gpa_;
};

// TODO: Test
int main() {
    Student student("Pravin", 10, 3.4);
    assert(student.getName() == "Pravin");
    assert(student.getGrade() == 10);
    assert(student.getGPA() == 3.4);
		bool caught{false};
		try {
			student.setGrade(114);
		}
		catch(...){
			caught = true;
		}
		assert(caught);
}