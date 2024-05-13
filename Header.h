#pragma once


class User {
private:
	string Name;
	string Login;
	string Password;

public: //students
	User(string rollno) {
		StudentManagement temp(rollno);
		Name = temp.getName();
		Login = temp.getLogin();
		Password = temp.getPassword();
	}

	User(int courseid) {
		TeacherManagement temp(courseid);
		Name = temp.getName();
		Login = temp.getLogin();
		Password = temp.getPassword();
	}

	//getters  
	string getName() {
		return Name;
	}

	string getLogin() {
		return Login;
	}

	string getPassword() {
		return Password;
	}

	//void changePass(string rollno){
	//	StudentManagement temp(rollno);
	//	temp.changePassowrd(rollno);
	//}
	//
	//void changePassDef(string rollno){
	//	StudentManagement temp(rollno);
	//	temp.changePassowrdDef(rollno);
	//}

	//  
};


class Student : public User {

	string Rollno;
	int subject[11];

public:
	Student(string rollno) : User(rollno) {
		Rollno = rollno;
	}

	void changePass(string rollno) {
		StudentManagement temp(rollno);
		temp.changePassowrd(rollno);
	}

	void changePassDef(string rollno) {
		StudentManagement temp(rollno);
		temp.changePassowrdDef(rollno);
	}

	bool* RegisteredCourses() {
		StudentManagement temp(Rollno);
		bool* subject = temp.getSubject();
		return subject;

	}

	//getter

	string getRoll() {
		return Rollno;
	}
};

class Teacher : public User {
	int CourseId;

public:
	Teacher(int courseid) : User(courseid) {
		CourseId = courseid;
	}

	void changePass(int courseid) {
		TeacherManagement temp(courseid);
		string course = to_string(courseid);
		temp.changePassowrd(course);
	}

	void changePassDef(int courseid) {
		TeacherManagement temp(courseid);
		string course = to_string(courseid);
		temp.changePassowrdDef(course);
	}

};

