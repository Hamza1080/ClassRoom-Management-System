#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <conio.h>
using namespace std;


void updateattendence(int quiznumber,string rollnumber,string coursename) {
	ofstream attendence("Attendence.txt", ios::app);
		if(attendence.is_open())
		{
			attendence << "Course Name  : " << coursename << endl;
			attendence << "Quiz Number  : " << quiznumber+1 << endl;
			attendence << "Roll Number  : " << rollnumber << endl;
			attendence.close();
			cout << "Attendence Marked " << endl;
		}

		else
		{
			cout << "Error opening file." << endl;
		}


}

string getPassword()
{
	string password = "";
	char ch;
	cout << "Enter password: ";
	ch = _getch();
	while (ch != 13) // 13 is the ASCII value of Enter key
	{
		password.push_back(ch);
		cout << "*";
		ch = _getch();
	}
	cout << endl;
	return password;
}

void getUserTime(tm& time){
	cout<<"Please Set the Year of Quiz"<<endl;
	cin>>time.tm_year;
	cout<<"Please Set Month Of Quiz"<<endl;
	cin>>time.tm_mon;
	cout<<"Please Set the Day of Quiz"<<endl;
	cin>>time.tm_mday;
	cout<<"Please Set the hour of Quiz"<<endl;
	cin>>time.tm_hour;
	cout<<"Please Set the Minute of Quiz"<<endl;
	cin>>time.tm_min;
	cout<<"Please Set the second of Quiz"<<endl;
	cin>>time.tm_sec;
	
	
}

int* convertToUnsorted(int arr[], int size) {
	int* unsortedArr = new int[size];
	bool* used = new bool[size];
	for (int i = 0; i < size; i++) {
		used[i] = false;
	}

	srand(time(NULL)); // Seed the random number generator with the current time

	for (int i = 0; i < size; i++) {
		int randIndex = rand() % size;
		while (used[randIndex]) { // If the random index has already been used, get a new one
			randIndex = rand() % size;
		}
		unsortedArr[i] = arr[randIndex];
		used[randIndex] = true;
	}

	delete[] used;
	return unsortedArr;
}

//-------------------------------------Report------------------------//
class Report {
	int Totalmarks;
	int avgmarks;
	int maximum;
	int minimum;
	int numberofquestion;
	int *attemptcorrect; //ISKA SIZE ABHI NAHI PATA 
	int totalattempt;

public:

	Report() {
		Totalmarks = 0;
		avgmarks = 0;
		maximum = 0;
		minimum= 1000;
}
  void	makereport(int obtainmarks,int totalmarks,int numberofquestions) {  //YAHAN NUMBER OF QUESTIONS DEKH KR ISKA SIZE PATA LAGEGA
	  Totalmarks = totalmarks;
	
	  if (obtainmarks > maximum) {
		  maximum = obtainmarks;
	  }
	  if (minimum > obtainmarks) {
		  minimum = obtainmarks;
	  }
	  avgmarks = (avgmarks + obtainmarks) / totalattempt;
	}

  void showreport() {
	  system("cls");
		  cout << "Total Marks Of Quiz Are " << Totalmarks << endl;
		  if (minimum == 1000) {
			 cout << "Minimum Marks Of Quiz Are " << "0" << endl;
		  }
		  else
		  {
			 cout << "Minimum Marks Of Quiz Are " << minimum << endl;

		  }
		 cout << "Maximum Marks Of Quiz Are " << maximum << endl;
		  cout << "Average Marks Of Quiz Are " << avgmarks << endl;
  }
  void settotalquestion(int totalq) {
	  numberofquestion=totalq;
	  attemptcorrect = new int[numberofquestion];
	  for (int i = 0; i < numberofquestion; i++) {
		  attemptcorrect[i] = 0;
	  }
  }

  void startanalytics() {
	  for (int i = 0; i < numberofquestion; i++) {
		  attemptcorrect[i] = 0;
	  }
  }
  void setanalytics(int *correctanswer){
	  for (int i = 0; i < numberofquestion; i++) {
		  attemptcorrect[i] = attemptcorrect[i] + correctanswer[i];
	  }
	  totalattempt = totalattempt + 1;
  }

  void showanalytics() {
	  for (int i = 0; i < numberofquestion; i++) {
		  cout << "Correct Attempt Of Question " << i + 1 << "Are : " << attemptcorrect[i]<<" / "<< totalattempt << endl;
	  }
	  int highestt=0;
	  for (int i = 0; i < numberofquestion; i++) {
		  if (highestt < attemptcorrect[i])
			  highestt = attemptcorrect[i];
		}
	  cout << "---------BAR GRAPH---------" << endl;
	  

	  for (int x = highestt; x >0 ; x--) {
		  for(int y=0;y<numberofquestion;y++)
		  if (attemptcorrect[y] >= x)
			  cout << "|=|"<<"               ";
		  cout << endl;
	  }
	  highestt = 0;
	  int asad = 0;
	  int counting = 0;
	  for (int i = 0; i < numberofquestion; i++) {
		  if (attemptcorrect[i] > 0) {
			  counting = counting + 1;
		  }
	  }
	  int* index = new int[numberofquestion];
	  for (int x = 0; x < numberofquestion; x++) {
		  for (int y = 0;y< numberofquestion; y++)
		  {
			  if (highestt <= attemptcorrect[y])
			  {
				  highestt = attemptcorrect[y];
				  index[x] = y+1;
				  asad = y;
			  }
		  }
		  highestt = 0;
		  attemptcorrect[asad] = 0;
	  }
	  for (int x = 0; x < counting; x++)
		  cout << "Qno : " << index[x] <<"          ";

	  cout << endl;
	  delete[] index;
  }
  
	//getter

	int getTotalmarks() {
		return Totalmarks;
	}

	int getavgmarks() {
		return avgmarks;
	}

	int getmaximum() {
		return maximum;
	}

	int getminimum() {
		return minimum;
	}

	//setter

	void setTotalmarks(int total) {
		Totalmarks = total;
	}

	void setavgmarks(int avg) {
		avgmarks = avg;
	}

	void setmaximum(int max) {
		maximum = max;
	}

	void setminimum(int min) {
		minimum = min;
	}

};


//-------------------------------------Report------------------------//




//-------------------------------------Question------------------------//

class Question {
	string question;
	string topic;
	string type;
	int mark;


public:
	Question() {

	}
	Question(string question, string topic, string type, int mark) {
		this->question = question;
		this->topic = topic;
		this->type = type;
		this->mark = mark;
	}


	//getter

	string getquestion() {
		return question;
	}
	string gettopic() {
		return topic;
	}
	string gettype() {
		return type;
	}
	int getmarks() {
		return mark;
	}

	//setter

	void setquestion(string q) {
		question = q;
	}
	void settopic(string t) {
		topic = t;
	}
	void settype(string t) {
		type = t;
	}
	void setmarks(int marks) {
		mark = marks;
	}

	//mcq getter

};


class Mcq : public Question {
	string opt[4];
	string answer;

public:

	Mcq() {
		opt[0] = "";
		opt[1] = "";
		opt[2] = "opt2";
		opt[3] = "opt3";
		answer = "answeri";
	}
	Mcq(string opt0, string opt1, string opt2, string opt3, string answeri, string question, string topic, string type, int mark) : Question(question, topic, type, mark) {
		opt[0] = opt0;
		opt[1] = opt1;
		opt[2] = opt2;
		opt[3] = opt3;
		answer = answeri;
	}
	
	//getter
	string* getopt() {
		return opt;
	}
	string getanswer() {
		return answer;
	}
	string getopt1() {
		return opt[0];
	}

	string getopt2() {
		return opt[1];
	}
	string getopt3() {
		return opt[2];
	}
	string getopt4() {
		return opt[3];
	}

	//setter 
	void setopt(string opt1[]) {
		for (int i = 0; i < 4; i++) {
			opt[i] = opt1[i];
		}
	}
	void setanswerind(string ans) {
		answer = ans;
	}
};

class TrueFalse : public Question {
	bool answer = 0;
public:
	TrueFalse() {

	}
	TrueFalse(bool ans, string question, string topic, string type, int mark) : Question(question, topic, type, mark) {
		answer = ans;
	}
	//getter
	bool getanswer() {
		return answer;
	}
	//setter
	void setter(bool ans) {
		answer = ans;
	}
};

class Subjective : public Question {
	string answer;

public:
	Subjective(){

	}
	Subjective(string answer, string question, string topic, string type, int mark) : Question(question, topic, type, mark) {
		this->answer = answer;
	}
	Subjective(string question, string topic, string type, int mark) : Question(question, topic, type, mark) {

	}

};



//-------------------------------------Question done------------------------//

//-------------------------------------QuestionBank------------------------//
class QuestionBank {
	string filename;
	int totalquestion;
	int totalmcq;
	int totaltruefalse;
	int totalsubjective;
	Mcq *mcqs[12];
	TrueFalse* truefalse[12]; 
	Subjective* subjective[6];


public:
	QuestionBank(string filename) {
		filename = filename;
		//

		//
		totalquestion = 0;
		totalmcq = 0;
		totaltruefalse = 0;
		totalsubjective = 0;

		//markers
		string topic = "a5380ee";
		string McQ = "2efcde9";
		string correct = "dabfac4";
		string Truefalse = "b94d27b";
		string descriptive = "88f7ace";


		ifstream questionfile;
		string line;
		questionfile.open(filename);

	
		
		questionfile.close();
		totalquestion = totalmcq + totaltruefalse + totalsubjective;



		questionfile.open(filename);
		string question;
		string top;
		string opt1, opt2, opt3, opt4;
		int corr;
		string answer;
		bool tf;
		int i = 0;
		int j = 0;
		int k = 0;
		while (questionfile.good()) {

			getline(questionfile, line);
			if (line == topic) {
				getline(questionfile, top);
			}

			if (line == McQ) {
				getline(questionfile, question);
				getline(questionfile, opt1, ':');
				if (opt1 == "option dabfac4") {
					corr = 1;
				}
				getline(questionfile, opt1, '\n');
				getline(questionfile, opt2, ':');
				if (opt2 == "option dabfac4") {
					corr = 2;
				}
				getline(questionfile, opt2, '\n');
				getline(questionfile, opt3, ':');
				if (opt3 == "option dabfac4") {
					corr = 3;
				}
				getline(questionfile, opt3, '\n');
				getline(questionfile, opt4, ':');
				if (opt4 == "option dabfac4") {
					corr = 4;
				}
				getline(questionfile, opt4, '\n');

				//		cout<<top<<endl;
				//		cout<<question<<endl;
				//		cout<<opt1<<endl;
				//		cout<<opt2<<endl;
				//		cout<<opt3<<endl;
				//		cout<<opt4<<endl;
				if (corr == 1) {
					answer = opt1;
				}
				else if (corr == 2) {
					answer = opt2;
				}
				else if (corr == 3) {
					answer = opt3;
				}
				else if (corr == 4) {
					answer = opt4;
				}
				if(i<12)
				{
					mcqs[i] = new Mcq(opt1, opt2, opt3, opt4, answer, question, top, McQ, 1);
					i++;
				}

			}

			else if (line == Truefalse) {
				getline(questionfile, question);
				getline(questionfile, opt1, ':');
				if (opt1 == "option dabfac4") { tf = 1; }
				else { tf = 0; }

				if(j<12)
				{
					truefalse[j] = new TrueFalse(tf, question, top, Truefalse, 1);
					j++;
				}
			}

			else if (line == descriptive) {
				question = "";
				while (1) {
					getline(questionfile, opt1, '\n');
					//	truefalse[k]=new TrueFalse(tf,question,top,Truefalse,1);
					if ((opt1 == topic) || (opt1 == McQ) || (opt1 == correct) || (opt1 == Truefalse) || (opt1 == descriptive) || (questionfile.eof())) {
						break;
					}
					else {
						string linebreak = "\n";
						question = question + linebreak + opt1;
					}
				}
				//			cout<<question<<endl;
				if(k<6)
				{
					subjective[k] = new Subjective(question, top, descriptive, 1);
					k++;
				}

			}

		}
		//cout<<subjective[0]->getquestion();
		//cout<<subjective[1]->getquestion();
		questionfile.close();

	}

	bool checktopicmcq(string top,int index) {
		if (mcqs[index]->gettopic() == top) {
			return 1;
		}
		else {
			return 0;
		}

	}

	bool checktopictruefalse(string top, int index) {
		if (truefalse[index]->gettopic() == top) {
			return 1;
		}
		else {
			return 0;
		}



	}

	bool checktopicsubjective(string top, int index) {
		if (subjective[index]->gettopic() == top) {
			return 1;
		}
		else {
			return 0;
		}

	}

	Mcq* getMcq(int index) {
		
		Mcq* m = new Mcq;
		m = mcqs[index];

		return m;
	}

	TrueFalse* gettruefalse(int index) {

		TrueFalse* t_f = new TrueFalse;
		t_f = truefalse[index];

		return t_f;
	}

	Subjective* getsubjective(int index) {

		Subjective* s = new Subjective;
		s = subjective[index];

		return s;
	}
	//void checksubjective() {
	//	for (int i = 0; i < 12; i++) {
	//		TrueFalse* s = new TrueFalse;
	//		s = truefalse [i] ;
	//		cout << "Check  " << i << "PROCESS" << endl;
	//		cout << s->getquestion() << endl;
	//		cout << "Index number  " << i << "  Works" <<endl;
	//	}
	//	//return s;
	//}

	//Question** getquestions(string* topics, int ntopic, int mcq, int subj, int t_f) {
	//	int total = mcq + subj + t_f;
	//	Question* q[10];
	//	/*	int array[4] = {-1,-1,-1 - 1};
	//		int m = 0;
	//		int k = 0;
	//		int topicexist;
	//		cout << mcqs[1]->gettopic();
	//		cout << "Line 342" << endl;
	//		while (m < mcq) {
	//			int a = rand() % totalmcq;
	//			for (int i = 0; i < ntopic; i++) {
	//				if ((mcqs[a]->gettopic()) == topics[i]) {
	//					topicexist = 1;
	//				}
	//				cout << "Line 349"<<endl;
	//			}
	//			if (topicexist == 1) {
	//				for (int i = 0; i < 4; i++) {
	//					if (a == array[i]) {

	//					}
	//					else {
	//						array[i] = a;
	//						q[k] = mcqs[a];
	//						k++;
	//						m++;
	//					}
	//				}
	//			}
	//		}

	//		return q;
	//	}
	//	*/
	//	int counter = 0;
	//	for (int i = 0; i < mcq; i++) {
	//		q[counter] = new Mcq();
	//		q[counter] = mcqs[i];
	//		counter++;
	//	}
	//	for (int i = 0; i < t_f; i++) {
	//		q[counter] = new TrueFalse();
	//		q[counter] = truefalse[i];
	//		counter++;
	//	}

	//	//for (int i = 0; i < t_f; i++) {
	//	//	q[counter] = new Subjective();
	//	//	q[counter] = subjective[i];
	//	//	counter++;
	//	//}
	//	for (int i = 0; i < total; i++) {
	//		cout << q[i]->getquestion() << endl;
	//		
	//	}

	//	for (int i = 0; i < mcq; i++) {
	//		q[i]->opt[1];
	//	}
	//	return q;
	//}

	~QuestionBank() {
		for (int i = 0; i < 12; i++) {
			delete[] mcqs[i];
		}
		delete[] mcqs;
		
		for (int i = 0; i < 12; i++) {
			delete[] truefalse[i];
		}
		delete[] truefalse;

		for (int i = 0; i < 12; i++) {
			delete[] subjective[i];
		}
		delete[] subjective;


	}
	//getter

	string getfilename() {
		return filename;
	}

	int gettotalquestion() {
		return totalquestion;
	}
	int gettotalmcq() {
		return totalmcq;
	}

	int gettotaltruefalse() {
		return totaltruefalse;
	}

	int gettotalsubjective() {
		return totalsubjective;
	}

	//settter 
	void setfilename(string f) {
		filename = f;
	}

	void settotalquestion(int totalq) {
		totalquestion = totalq;
	}
	void settotalmcq(int nomcq) {
		totalmcq = nomcq;
	}

	void settotaltruefalse(int notf) {
		totaltruefalse = notf;
	}

	int settotalsubjective(int nosubj) {
		totalsubjective = nosubj;
	}
};



//-------------------------------------QuestionBank------------------------//

//-------------------------------------STRUCT Q/A------------------------//
struct Q_A {
	string Questions;
	string Answers;
};

//-------------------------------------Quiz------------------------//
class Quiz {
	int topics[3];
	int totaltopics;
	int numberT;
	int totalNoQuestions;
	int mcq;
	int  subj;
	int t_f;
	int totaltime;
	int markmcq;
	int marktf;
	int marksubj;
	int totalmarks;
	string* answerkey;
	Mcq mcqs[4];
	TrueFalse truefalse[4];
	Subjective subjective[2];
	Q_A AnsKey[10];
	tm Quiztime;
	//start time
	//end time

public:
	Quiz(int mcqs, int subjective, int tf, int nTopic,int marksmcq,int  markstruefalse,int  markssubjective, int time, bool topic[],tm quiztime ) {
		mcq = mcqs;
		subj = subjective;
		t_f = tf;
		markmcq= marksmcq;
		marktf = markstruefalse;
		marksubj = markssubjective;
		totalNoQuestions = mcq + subj + t_f;
		totaltopics = nTopic;
		for (int i = 0; i < 3; i++) {
			topics[i] = topic[i];
			cout << topics[i];
		}
		Quiztime = quiztime;
		totaltime = time;
	}


	void CreateMcq(QuestionBank* qb) {
		//mcqs[11] = *(qb->getMcq(11));
		//cout << i + 1 << ") " << mcqs[11].getquestion() << endl;
		srand(time(NULL));
		cout << endl << endl << "ALL MCQ QUESTIONS OF QUIZ ARE" << endl;

		int i = 0;
		int index;
		while (i < mcq) {
			while (1) {
				index = rand() % 12;
				if (topics[0] == 1) {
					if ((index >= 0) && (index < 4)) {
						break;
					}
				}
				if (topics[1] == 1) {
					if ((index >= 4) && (index < 8)) {
						break;
					}
				}
				if (topics[2] == 1) {
					if ((index >= 8) && (index < 12)) {
						break;
					}
				}
			}
			mcqs[i] = *(qb->getMcq(index));
			cout << i + 1 << ") " << mcqs[i].getquestion() << endl;
			i++;
		}
	}
	void CreateTrueFalse(QuestionBank* qb) {
		
		cout << endl << endl << "ALL True/False QUESTIONS OF QUIZ ARE" << endl;
		int i = 0;
		int index;
		while (i < t_f) {
			while (1) {
				index = rand() % 12;
				if (topics[0] == 1) {
					if ((index >= 0) && (index < 4)) {
						break;
					}
				}
				if (topics[1] == 1) {
					if ((index >= 4) && (index < 8)) {
						break;
					}
				}
				if (topics[2] == 1) {
					if ((index >= 8) && (index < 12)) {
						break;
					}
				}
			}
			truefalse[i] = *(qb->gettruefalse(index));
			cout << i + 1 << ") " << truefalse[i].getquestion() << endl;
			i++;
		}
	}

	/*	int array[4] = { -1,-1,-1,-1 };
		int randcheck = 1;
		int topiccheck = 1;
		int i = 0;

		cout <<endl<<endl<< "ALL TRUE FALSE OF QUIZ ARE" << endl;
		while (i < t_f) {
			int index = rand() % 4;
			for (int i = 0; i < 4; i++) {
				if (array[i] == index) {
					randcheck = 0;
				}
			}
			for (int i = 0; i < totaltopics; i++) {
				if (topiccheck == qb->checktopictruefalse(topics[i], index)) {
					topiccheck = 1;
				}
				else {
					topiccheck = 0;
				}
			}
			if (topiccheck && randcheck) {
				truefalse[i] = *(qb->gettruefalse(i));
				cout << i + 1 << ") " << truefalse[i].getquestion() << endl;
				i++;
			}
		}
	}*/

	void CreateSubjective(QuestionBank* qb) {
		srand(time(NULL));

		cout << endl << endl << "ALL SUBJECTIVE OF QUIZ ARE" << endl;
		int array[3] = { -1,-1,-1};

		int i = 0;
		int k = 0;
		int index;
		while (i < subj) 
		{
			while (1) {
				index = rand() % 6 ;
					
				if (topics[0] == 1) {
					if ((index >= 0) && (index < 2)) {
						{
							index = rand() % 100;
							if (index > 50)
							{
								index = 1;
								break;
							}
							else
								index = 0;
								break;
						}
					}
				}
				if (topics[1] == 1) {
					if ((index >= 2) && (index < 4)) {
						index = rand() % 100;
						if (index > 50)
							index = 3;
						else
							index = 2;
						break;
					}
				}
				if (topics[2] == 1) {
					if ((index >= 4) && (index < 6)) {
						index = rand() % 100;
						if (index > 50)
							index = 4;
						else
							index = 5;
						break;
					}
				}
			}
			subjective[i] = *(qb->getsubjective(index));
			cout << i + 1 << ") " << subjective[i].getquestion() << endl;
			i++;
		}
	
}
		//int array[2] = { -1,-1};
		//int randcheck = 1;
		//int topiccheck = 1;
		//int i = 0;

		//while (i < subj) {
		//	int index = rand() % 2;
		//	for (int i = 0; i < 2; i++) {
		//		if (array[i] == index) {
		//			randcheck = 0;
		//		}
		//	}
		//	for (int i = 0; i < totaltopics; i++) {
		//		if (topiccheck == qb->checktopicsubjective(topics[i], index)) {
		//			topiccheck = 1;
		//		}
		//		else {
		//			topiccheck = 0;
		//		}
		//	}

		//	if (topiccheck && randcheck) {
		//		subjective[i] = *(qb->getsubjective(i));
		//		cout << i + 1<<") " << subjective[i].getquestion() << endl;
		//		i++;
		//	}
		//}
	//}

void Make_AnsKey(){
	int counter = 0;
	for (int i = 0; i < mcq; i++) {
		AnsKey[counter].Questions = mcqs[i].getquestion();
		AnsKey[counter].Answers = mcqs[i].getanswer();
		counter++;
	}
	for (int i = 0; i < t_f; i++) {
		AnsKey[counter].Questions = truefalse[i].getquestion();
		if (truefalse[i].getanswer() == 1) {
			AnsKey[counter].Answers = "1";
		}
		else {
			AnsKey[counter].Answers = "0";
		}
		counter++;
	}
	for (int i = 0; i < subj; i++) {
		AnsKey[counter].Questions = subjective[i].getquestion();
		AnsKey[counter].Answers = "";
		counter++;
	}
	
}

bool Check_QuestionMcq(string AttempQuesion, string AttemptAnswer) {
	int totalquestion = mcq + subj + t_f;
	for (int i = 0; i < totalquestion; i++) {
		if (AnsKey[i].Questions == AttempQuesion) {
			//cout << "AnsKey[i]  " << AnsKey[i].Answers << endl;
			//cout << "Attempt " << AttemptAnswer << endl;
			if (AnsKey[i].Answers == AttemptAnswer) {
				return true;
			}
		}
	}
	return false;
}
bool Check_QuestionT_F(string AttempQuesion, bool choice) {
	int totalquestion = mcq + subj + t_f;
	string a;
	if (choice) {
		a = "1";
	}
	else {
		a = "0";
	}
	for (int i = 0; i < totalquestion; i++) {
		if (AnsKey[i].Questions == AttempQuesion) {
			//cout << "AnsKey[i]  " << AnsKey[i].Answers << endl;
			if (a==AnsKey[i].Answers) {
				return true;
			}
		}
	}
	return false;
}

float Check_Questionsubj(string answer) {
	float size = answer.length();
	float marks = size * 0.1;
	return marks;
}

int AttemptQuiz(Report *report) {
	int choice;
	int mcqcorrect=0;
	int tfcorrect=0;
	int subjectivemarks = 0;
	int *correctanswer=new int[mcq + t_f];
	for (int i = 0; i < (mcq + t_f); i++) {
		correctanswer[i] = 0;
	}
	cout << "---- YOUR QUIZ IS READY ----" << endl << endl;
	cout << "Press 1 to continue" << endl;
	cin >> choice;
	system("cls");
	int counter=0;
	int questioncorrect=0;
	
	int* array = new int[mcq];
	for (int i = 0; i < mcq; i++) {
		array[i] = i;
	}

	int* options = new int[4];
	for (int i = 0; i < 4; i++) {
		options[i] = i;
	}
	int* unsortedArr = convertToUnsorted(array, mcq);
	int* unsortetOpt = convertToUnsorted(array, mcq);
	
	for (int i = 0; i < mcq; i++) {
		cout << "QUESTION NUMBER : " << counter+1 << endl;
		cout << mcqs[unsortedArr[i]].getquestion() << endl;
		string option[4] = { mcqs[unsortedArr[i]].getopt1(),mcqs[unsortedArr[i]].getopt2(),mcqs[unsortedArr[i]].getopt3(),mcqs[unsortedArr[i]].getopt4() };
		for (int j = 0; j < 4; j++) {
		cout << j+1 << ".  " << option[unsortetOpt[j]] << endl;
		}

		do {
			cin >> choice;
		} while (choice < 1 && choice >3);
		string a = option[unsortetOpt[choice - 1]];
		cout << "YOUR SELECTED ANSWER IS : " << a << endl << endl;
		correctanswer[counter] = Check_QuestionMcq(AnsKey[unsortedArr[i]].Questions, option[choice - 1]);
		mcqcorrect= mcqcorrect+Check_QuestionMcq(AnsKey[unsortedArr[i]].Questions, option[choice - 1]);
		counter++;
	}
	delete[] unsortedArr;
	delete[] array;

	//tf randomize
	for (int i = 0; i < t_f; i++) {
		cout << "QUESTION NUMBER : " << counter + 1 << endl;
		cout << AnsKey[counter].Questions<<endl;
		cout << "Press 1 For True & 0 For False" << endl ;
		do {
			cin >> choice;
		} while ((choice != 1 ) && (choice != 0));
		cout << endl  ;
		correctanswer[counter]= Check_QuestionT_F(AnsKey[counter].Questions, choice);
		tfcorrect = tfcorrect + Check_QuestionT_F(AnsKey[counter].Questions, choice);
		counter++;
	}
	for (int i = 0; i < subj; i++) {
		string answer;
		
		cout << "QUESTION NUMBER : " << counter + 1 << endl;
		cout << AnsKey[counter].Questions << endl;
		cin >> answer;

		
		cout << endl;
		subjectivemarks = subjectivemarks + Check_Questionsubj(answer);
		if (subjectivemarks >= (i+1)* marksubj){
			subjectivemarks = (i+1)* marksubj;
		}
		counter++;
	}
	system("cls");
	int obtainmarks = (mcqcorrect * markmcq) + (tfcorrect * marktf) + subjectivemarks;
	totalmarks = (mcq * markmcq) + (t_f * marktf) + (marksubj * subj);
	cout << "The total marks you score in Quiz are : " <<obtainmarks<<" / "<<totalmarks<< endl;
	report->setanalytics(correctanswer);

	delete [] correctanswer;
	return obtainmarks;
}

bool Checktime() {
	time_t now = time(nullptr);
	tm a = Quiztime;
	a.tm_year -= 1900;
	a.tm_mon--;
	time_t start_time = mktime(&a);
	time_t end_time = start_time + (totaltime * 60);
	//cout <<"Difference is"<< ((start_time - now )/ 60) << endl;
	if (now < start_time) {
		system("cls");
		cout << "Time remaining for Quiz is : "<< ((start_time - now) / 60) <<" minutes earlier" << endl;
		return 0;
	}
	else if (now > end_time) {
		system("cls");
		cout << "You cannot give quiz it ended  : "<<(now-end_time)/60 << " minutes earlier"<<endl;
		return 0;
	}
	else {
		cout << "You are eligbile for Quiz,Goodluck" << endl;
		return 1;
	}
}




	~Quiz() {
		delete topics;
		delete answerkey;
		

}
	//getter
	//int gettopic() {
	//	return topics[];
	//}
	int gettotalquestions() {
		return mcq + t_f;
	}
	int gettotalmarks() {
		return totalmarks;
	}
	int getnoQuestion() {
		return totalNoQuestions;
	}
	//-----remaining----//

	//setter
	//void settopic(string* topic) {
	//	topics = topic;
	//}
	int setnoQuestion(int n) {
		totalNoQuestions = n;
	}

};


//-------------------------------------QuizEnd------------------------//

//-------------------------------------Course------------------------//
class Course {
	string name;
	string topics[3];
	int quiz_taken;
	QuestionBank* Qs;
	Quiz* quiz[5];
	Report *report[5];

public:
	Course(string name, string top[], QuestionBank* q) {
		this->name = name;
		topics[0] = top[0];
		topics[1] = top[1];
		topics[2] = top[2];
		quiz_taken = 0;
		for (int i = 0; i < 5; i++) {
			report[i] = new Report();
		}

		Qs = q;
	}

	~Course() {
		delete Qs;
		for (int i = 0; i < 5; i++) {
			delete quiz[i];
			delete report[i];
		}
		delete quiz;
		delete report;
	}

	//functions
	void makequiz() {
		//chek
		int NoMcqs;
		int NoT_F;
		int Nosubjective;
		int time;
		int Notopic;
		tm Quiztime;
		int marksmcq;
		int markstruefalse;
		int markssubjective;


		bool topic[3] = { 0,0,0 };
		while (1) {
			cout << "Enter Number of mcqs - Less than 5" << endl;
			cin >> NoMcqs;
			if ((NoMcqs < 5) && (NoMcqs > -1)) {
				break;
			}
			else {
				cout << "Invalid number of Mcqs" << endl;
			}
		}
		while (1) {
			cout << "Enter Number of True False - Less than 5" << endl;
			cin >> NoT_F;
			if ((NoT_F < 5) && (NoT_F > -1)) {
				break;
			}
			else {
				cout << "Invalid number of True False" << endl;
			}
		}

		while (1) {
			cout << "Enter Number of subjective - Less than 3" << endl;
			cin >> Nosubjective;
			if ((Nosubjective < 3) && (Nosubjective > -1)) {
				break;
			}
			else {
				cout << "Invalid number of Subjective" << endl;
			}
		}
		
		cout << "Enter total time in minutes" << endl;
		cin >> time;

	/*	while (1) {
			cout << "Enter number of topics to add - less than 4" << endl;
			cin >> Notopic;
			if ((Notopic < 4) && (Notopic > 0)) {
				break;
			}
			else {
				cout << "Invalid number of topics" << endl;
			}
		}*/
		//topic = new string[Notopic];
		//Notopic = 0;
		string topics[3] = {"General","C++","Programming"};
		int add;
		int k = 0;
		int l=0;
		for (int i = 0; i < 3; i++) {
			cout << "PRESS 1 TO ADD TOPICS" << endl;
			cout << topics[i] << endl;
			cin >> add;
			if (add == 1) {
				topic[i] = 1;
				//Notopic++;
				add = 0;
			}
		}
		cout << "Enter Marks Per Mcq" << endl;
		cin >> marksmcq;
		cout << "Enter Marks Per TrueFalse" << endl;
		cin >> markstruefalse;
		cout << "Enter Marks Per Subjective" << endl;
		cin >> markssubjective;

		getUserTime(Quiztime);
		if (quiz_taken < 5) {
			cout << "Does it work" << endl;
			quiz[quiz_taken] = new Quiz(NoMcqs, Nosubjective, NoT_F,3, marksmcq, markstruefalse, markssubjective, time, topic,Quiztime);
			report[quiz_taken]->settotalquestion(NoMcqs + NoT_F);
			system("cls");
			quiz[quiz_taken]->CreateMcq(Qs);
			quiz[quiz_taken]->CreateTrueFalse(Qs);
			quiz[quiz_taken]->CreateSubjective(Qs);
			cout << endl << endl << "QUIZ HAS BEEN MADE SUCCESSFULLY" << endl;
			quiz_taken++;
		}
		else {
			cout << "Maximum Quizzes taken" << endl;
		}
		
	}
	void Takequiz(int quizno,int &quiznumber,string rollnumber,string coursename) {
		if (quizno > quiz_taken) {
			cout << "invalid number kindly re-enter" << endl;
		}
		bool time = 0;
		time=quiz[quizno]->Checktime();
		if(time)
		{
			quiz[quizno]->Make_AnsKey();
			int obtainmarks=quiz[quizno]->AttemptQuiz(report[quizno]);
			int totalmarks=quiz[quizno]->gettotalmarks();
			int totalquestions = quiz[quizno]->gettotalquestions();
			//int *correctattemprray =quiz[quizno]->getcorrectarray()
			report[quizno]->makereport(obtainmarks, totalmarks, totalquestions); //totalquestions doesn include subjective
			updateattendence(quiznumber, rollnumber,coursename);
			quizno++;
			quiznumber++;
		}
		else {
			cout << "It Is Not Time For Quiz" << endl;
		}
		//quiz[quizno].display();

	}

	void showReport() {
		int choice;
		if (quiz_taken == 0) {
			cout << "NO QUIZ TAKEN YET" << endl;
		}
		else {
			for (int i = 0; i < quiz_taken; i++) {
				cout << "Show Report For Quiz " << i +1<<endl;
			}
			do {
				cin >> choice;
			} while (choice <= 0 || choice > quiz_taken );
			report[choice - 1]->showreport();
		}
	}

	void showquizes(int &quizgiven,string rollnumber,string coursename) {
		int choice = 0;
		if (quiz_taken == 0) {
			cout << "NO QUIZ HAS BEEN MADE YET" << endl;
		}
		else
		{	
			for (int i = quizgiven; i < quiz_taken; i++) {
				cout << "Quiz Number  " << i + 1 << endl;
			}
			do {
				cin >> choice;
			} while ((choice >= quizgiven-1) && (choice < quiz_taken-1));

			Takequiz(choice - 1,quizgiven,rollnumber, coursename);
		}
	}

	void showanalytics() {
		int choice;
		if (quiz_taken == 0) {
			cout << "NO QUIZ TAKEN YET" << endl;
		}
		else {
			for (int i = 0; i < quiz_taken; i++) {
				cout << "Show Report For Quiz " << i + 1 << endl;
			}
			do {
				cin >> choice;
			} while (choice <= 0 || choice > quiz_taken);
			report[choice - 1]->showanalytics();
		}
	}


	//getter
	string getname() {
		return name;
	}
	string gettopics() {
		return topics[0];
	}
	//int getnoquiz(){
	//	return totalquizes;
	//}

	//---------- Remaing *quiz----//

	//setter

	void setname(string n) {
		name = n;
	}
	void settopics(string t[]) {
		for (int i = 0; i < 3; i++) {
			topics[i] = t[i];
		}
	}
	//int setnoquiz(int n){
	//	totalquizes=n;
	//}



};


//-------------------------------------CourseEnd------------------------//




//-------------------------------------Login------------------------//

//string getPassword(string rolln){
//			
//string roll;
//string password;
//	
//	ifstream pass;
//	pass.open("student.csv");
//	
//
//	while((getline(pass,roll,','))&&(getline(pass,password,'\n'))){
//					
//			if(roll==rolln){
//		 	return password;
//			}
//	}
//	
//}


//void changePassowrd(string rolln){
//		
//string roll;
//string password;
//string password1;
//int newpass;
//
//	
//	char rollnumber[30];
//	char name[30];
//	
//
//	ifstream pass;
//	pass.open("student.csv");
//	
//	ofstream e;
//	e.open("new.csv");
//	
//	while((getline(pass,roll,','))&&(getline(pass,password,'\n'))){
//		
////			getline(pass,roll,',');		
////			getline(pass,password,'\n');
//			
//			if(roll!=rolln){
//		 	e << roll << "," << password << endl;
//			}
//			else{
//				newpass=1;
//				cout<<"record deleted"<<endl;
//			}
//		}
//		e.close();
//		pass.close();
//		
//		if(remove("student.csv")!=0){
//			cout<<"File not removed"<<endl;
//		}
//		else{
//			cout<<"OKAY"<<endl;
//		}
//		if(rename("new.csv","student.csv")!=0){
//			cout<<"File not renamed"<<endl;			
//		}	
//		else{
//			cout<<"okay"<<endl;
//		}
//	if(newpass==1){
//	ofstream savedfile("student.csv", ios_base::app);
//
//	cout<<"enter new password1"<<endl;
//	cin>>password1;
//	savedfile<<rolln<<","<<password1<<"\n";
//	
//	savedfile.close();
//	newpass=0;
//	}
//}

bool PasswordCheck(const string& password)
{
	bool has_uppercase = false;
	bool has_lowercase = false;
	bool has_digit = false;
	bool has_special = false;

	// Check the length of the password
	if (password.length() < 6) {
		return false;
	}

	// Iterate over the characters of the password
	int i = 0;
	while (password[i] != '\0') {
		char c = password[i];
		if (c >= 'A' && c <= 'Z') {
			has_uppercase = true;
		}
		else if (c >= 'a' && c <= 'z') {
			has_lowercase = true;
		}
		else if (c >= '0' && c <= '9') {
			has_digit = true;
		}
		else if (((c >= 37) || (c <= 47)) && ((c >= 58) || (c <= 64)) || ((c >= 91) || (c <= 96)) || ((c >= 123) || (c <= 126))) {
			has_special = true;
		}

		// If all criteria are met, return true
		if (has_uppercase && has_lowercase && has_digit && has_special) {
			return true;
		}
		i++;
	}

	// If any criteria are not met, return false
	return false;
}


//Teacher managment system
bool CourseExist(int courseId) {
	ifstream myfile;
	string line;
	myfile.open("T.data.csv");

	string c = to_string(courseId);

	string CourseID;
	string name;
	string password;

	while (myfile.good()) {
		getline(myfile, CourseID, ',');
		getline(myfile, name, ',');
		getline(myfile, password, '\n');


		if (c == CourseID) {
			myfile.close();
			return true;
		}
	}
	myfile.close();
	return false;
}

class TeacherManagement {
private:
	int courseid;
	string coursestr;
	string name;
	string login;
	string password;

public:
	TeacherManagement(int CourseId) {

		ifstream myfile;
		string line;
		myfile.open("T.data.csv");

		while (myfile.good()) {
			getline(myfile, coursestr, ',');
			getline(myfile, name, ',');
			getline(myfile, password, '\n');

			courseid = stoi(coursestr);
			if (courseid == CourseId) {
				break;
			}
		}
		myfile.close();
		login = coursestr + "@nu.edu.pk";
		password = getPassword(coursestr);

	}

	//getters

	int getCourseId() {
		return courseid;
	}

	string getName() {
		return name;
	}

	string getLogin() {
		return login;
	}

	string getPassword() {
		return password;
	}

	//taking password from file	
	string getPassword(string coursestr) {

		string course;
		string name;
		string password;

		ifstream pass;
		pass.open("T.data.csv");


		while ((getline(pass, course, ',')) && (getline(pass, name, ',')) && (getline(pass, password, '\n'))) {

			if (coursestr == course) {
				return password;
			}
		}

		pass.close();

	}
	//changing password in file
	void changePassowrd(string coursestr) {

		string courseid;
		string name;
		string password;
		string password1;
		int newpass;


		//	char rollnumber[30];
		//	char name[30];


		ifstream pass;
		pass.open("T.data.csv");

		ofstream e;
		e.open("new.csv");

		while ((getline(pass, courseid, ',')) && (getline(pass, name, ',')) && (getline(pass, password, '\n'))) {

			if (courseid != coursestr) {
				e << courseid << "," << name << "," << password << endl;
			}
			else {
				newpass = 1;
				//	cout<<"record deleted"<<endl;
			}
		}
		e.close();
		pass.close();

		if (remove("T.data.csv") != 0) {
			cout << "File not removed" << endl;
		}
		else {
			//	cout<<"OKAY"<<endl;
		}
		if (rename("new.csv", "T.data.csv") != 0) {
			cout << "File not renamed" << endl;
		}
		else {
			//	cout<<"okay"<<endl;
		}
		cout << newpass << endl;
		if (newpass == 1) {
			ofstream savedfile("T.data.csv", ios_base::app);
			while (1) {
				cout << "enter new password" << endl;
				cin >> password1;
				if (PasswordCheck(password1)) {
					savedfile << coursestr << "," << name << "," << password1 << "\n";
					savedfile.close();
					newpass = 0;
					break;
				}
				else {
					system("cls");
					cout << "Invalid Password kindly re-enter" << endl;
				}
			}
		}
	}

	void changePassowrdDef(string coursestr) {

		string courseid;
		string name;
		string password;
		string password1;
		int newpass;


		//	char rollnumber[30];
		//	char name[30];


		ifstream pass;
		pass.open("T.data.csv");

		ofstream e;
		e.open("new.csv");

		while ((getline(pass, courseid, ',')) && (getline(pass, name, ',')) && (getline(pass, password, '\n'))) {

			if (courseid != coursestr) {
				e << courseid << "," << name << "," << password << endl;
			}
			else {
				newpass = 1;
				//	cout<<"record deleted"<<endl;
			}
		}
		e.close();
		pass.close();

		if (remove("T.data.csv") != 0) {
			cout << "File not removed" << endl;
		}
		else {
			//	cout<<"OKAY"<<endl;
		}
		if (rename("new.csv", "T.data.csv") != 0) {
			cout << "File not renamed" << endl;
		}
		else {
			//	cout<<"okay"<<endl;
		}
		cout << newpass << endl;
		if (newpass == 1) {
			ofstream savedfile("T.data.csv", ios_base::app);
			while (1) {

				savedfile << coursestr << "," << name << "," << "Abcd.123" << "\n";
				savedfile.close();
				newpass = 0;
				break;

			}
		}
	}
	
};


//Student Management System
bool RollExists(string rollno) {
	ifstream myfile;
	string line;
	myfile.open("data.csv");

	string S1;
	string roll;
	string name;
	string login;
	string password;
	string subject1;
	bool subject[11];

	while (myfile.good()) {
		getline(myfile, S1, ',');
		getline(myfile, roll, ',');
		getline(myfile, name, ',');
		getline(myfile, subject1, '\n');

		if (roll == rollno) {
			myfile.close();
			return true;
		}
	}
	myfile.close();
	return false;
}


class StudentManagement {

private:
	string S1;
	string roll;
	string name;
	string login;
	string password;
	string subject1;
	bool* subject = new bool[11];

public:
	StudentManagement(string rollno) {

		ifstream myfile;
		string line;
		myfile.open("data.csv");

		while (myfile.good()) {
			getline(myfile, S1, ',');
			getline(myfile, roll, ',');
			getline(myfile, name, ',');
			getline(myfile, subject1, '\n');

			if (roll == rollno) {
				break;
			}
		}
		myfile.close();
		login = roll + "@nu.edu.pk";
		password = getPassword(rollno);
		int c = 0;

		for (int f = 0; subject1[f] != '\0'; f++)
		{
			if (subject1[f] == '1') {
				subject[c] = 1;
				c++;
			}
			else if (subject1[f] == '0') {
				subject[c] = 0;
				c++;
			}

		}

	}


	~StudentManagement(){
		delete subject;
	}
	//getters

	string getRoll() {
		return roll;
	}

	string getName() {
		return name;
	}

	string getLogin() {
		return login;
	}

	string getPassword() {
		return password;
	}

	bool* getSubject() {

		return subject;
	}

	//functions

	//access password function
	string getPassword(string rolln) {

		string roll;
		string password;

		ifstream pass;
		pass.open("student.csv");

		while ((getline(pass, roll, ',')) && (getline(pass, password, '\n'))) {

			if (roll == rolln) {
				return password;
			}
		}

		pass.close();
		return "";
	}

	//change password function
	void changePassowrd(string rolln) {

		string roll;
		string password;
		string password1;
		int newpass;


		char rollnumber[30];
		char name[30];


		ifstream pass;
		pass.open("student.csv");

		ofstream e;
		e.open("new.csv");

		while ((getline(pass, roll, ',')) && (getline(pass, password, '\n'))) {

			//			getline(pass,roll,',');		
			//			getline(pass,password,'\n');

			if (roll != rolln) {
				e << roll << "," << password << endl;
			}
			else {
				newpass = 1;
				//cout<<"record deleted"<<endl;
			}
		}
		e.close();
		pass.close();

		if (remove("student.csv") != 0) {
			cout << "File not removed" << endl;
		}
		else {
			//	cout<<"OKAY"<<endl;
		}
		if (rename("new.csv", "student.csv") != 0) {
			cout << "File not renamed" << endl;
		}
		else {
			//	cout<<"okay"<<endl;
		}
		if (newpass == 1) {
			ofstream savedfile("student.csv", ios_base::app);
			while (1) {
				cout << "enter new password" << endl;
				cin >> password1;
				if (PasswordCheck(password1)) {
					savedfile << rolln << "," << password1 << "\n";
					savedfile.close();
					newpass = 0;
					break;
				}
				else {
					system("cls");
					cout << "Invalid Password " << endl;
					cout << "kindly Reenter password" << endl;
				}
			}
		}
	}

	//set password to default
	void changePassowrdDef(string rolln) {

		string roll;
		string password;
		string password1;
		int newpass;


		char rollnumber[30];
		char name[30];


		ifstream pass;
		pass.open("student.csv");

		ofstream e;
		e.open("new.csv");

		while ((getline(pass, roll, ',')) && (getline(pass, password, '\n'))) {

			//			getline(pass,roll,',');		
			//			getline(pass,password,'\n');

			if (roll != rolln) {
				e << roll << "," << password << endl;
			}
			else {
				newpass = 1;
				cout << "record deleted" << endl;
			}
		}
		e.close();
		pass.close();

		if (remove("student.csv") != 0) {
			cout << "File not removed" << endl;
		}
		else {
			cout << "OKAY" << endl;
		}
		if (rename("new.csv", "student.csv") != 0) {
			cout << "File not renamed" << endl;
		}
		else {
			cout << "okay" << endl;
		}
		if (newpass == 1) {
			ofstream savedfile("student.csv", ios_base::app);
			savedfile << rolln << "," << "Abcd.123" << "\n";
			savedfile.close();
			newpass = 0;
		}
	}



};


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
	//teacher
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


};


class Student : public User {

	string Rollno;
	int subject[11];
	int quizgiven[11];

public:
	Student(string rollno) : User(rollno) {
		Rollno = rollno;
		for (int i = 0; i < 11; i++) {
			quizgiven[i] = 0;
		}
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
		bool* Sub = new bool[11];
		for (int i = 0; i < 11; i++) {
			Sub[i] = temp.getSubject()[i];
		}
		return Sub;

	}

	//getter

	string getRoll() {
		return Rollno;
	}
	int* getquizgive() {
		return quizgiven;
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




int main() {
	QuestionBank* PF = new QuestionBank("C:\\Rought\\Questionbank\\PF.txt");
	QuestionBank* OOP = new QuestionBank("C:\\Rought\\Questionbank\\OOP.txt");
	QuestionBank *ICT=new QuestionBank("C:\\Rought\\Questionbank\\ICT.txt");
	QuestionBank *DS=new QuestionBank("C:\\Rought\\Questionbank\\DS.txt");
	QuestionBank *AOA=new QuestionBank("C:\\Rought\\Questionbank\\AOA.txt");
	QuestionBank *SRE=new QuestionBank("C:\\Rought\\Questionbank\\SRE.txt");
	QuestionBank *RM=new QuestionBank("C:\\Rought\\Questionbank\\RM.txt");
	QuestionBank *BDA=new QuestionBank("C:\\Rought\\Questionbank\\BDA.txt");
	QuestionBank *AI=new QuestionBank("C:\\Rought\\Questionbank\\AI.txt");
	QuestionBank *DL=new QuestionBank("C:\\Rought\\Questionbank\\DL.txt");
	QuestionBank *DIP=new QuestionBank("C:\\Rought\\Questionbank\\DIP.txt");

	////Course *course[11];
	////course[0]=new course()
	int courseids[11] = { 101,102,103,104,105,106,107,108,109,110,111 };
	string allcourses[11] = { "Programming Fundamentals","Object Oriented Programming","Introduction To Computing","Data Structures","Analysis of Algorithms","Software Requirements Engineering","Research Methodology","Big Data Analytics","Artificial Intelligence","Deep Learning","Digital Image Processing" };
	////string files[11]={""}
	////Course(string name,string top[], QuestionBank *q)
	Course* course[11];
	string topics[3] = { "General questions","C++ programming","Programming" };
	course[0] = new Course("PF", topics, PF);
	course[1] = new Course("OOP", topics, OOP);
	course[2]=new Course("ICT",topics,ICT);
	course[3]=new Course("DS",topics,DS);
	course[4]=new Course("AOA",topics,AOA);
	course[5]=new Course("SRE",topics,SRE);
	course[6]=new Course("RM",topics,RM);
	course[7]=new Course("BDA",topics,BDA);
	course[8]=new Course("AI",topics,AI);
	course[9]=new Course("DL",topics,DL);
	course[10]=new Course("DIP",topics,DIP);
	/*course[0]->makequiz();
	course[0]->Takequiz(0);*/

	int option = 0;

	while (1) {
		cout << "Press 1 for Student" << endl;
		cout << "Press 2 for Teacher" << endl;
		cout << "Press 3 to Exit" << endl;
		cin >> option;

		//while(option!=3){

		if (option == 1) {
			system("cls");
			while (1) {
				cout << "Press 1 for Login" << endl;
				cout << "Press 2 to change/forget Password" << endl;
				cout << "Press 3 to go back" << endl;
				cin >> option;

				if (option == 1) {
					string username;
					string check;
					string email = "@nu.edu.pk";
					int check1 = 1;

					while (1) {
						char roll[9];
						cout << "----Welcome To Student Login ----" << endl;
						cout << "Enter Your Login Id" << endl;
						cout << "22I-xxxx@nu.edu.pk" << endl;
						cout << "Enter 3 to go back" << endl;
						cin >> username;
							if (username == "3") {
							break;
						}
						if (username.length() < 8) 
						{
							system("cls");
							cout << "Invalid Email" << endl;
							break;
						}
						for (int i = 0; i < 8; i++) {
							roll[i] = username[i];
						}
						roll[8] = '\0';
						check = roll + email;
						if (check == username) {
							if (RollExists(roll)) {
								check1 = 0;
							}
							else {
								system("cls");
								cout << "Roll Doesnt Exist" << endl << endl;
							}

						}
						else {
							system("cls");
							cout << "Invalid email kindly re-enter" << endl << endl;
						}
						if (check1 == 0) {
							string password;
							int logged = 0;
							 password= getPassword();
							if (!PasswordCheck(password)) {
								cout << "Invalid Password kindly re-enter the details " << endl;
							}


							Student S1(roll);
							if (password == S1.getPassword()) {
								logged = 1;

								system("cls");
								while (1) {
									cout << "Current User Logged in " << endl;
									cout << "User id : " << S1.getLogin() << endl;
									cout << "Name : " << S1.getName() << endl;
									cout << endl << endl;

									cout << "Press 1 to see Registered Courses" << endl;
									cout << "Press 2 to to attempt Quiz" << endl;
									cout << "Press 3 to see Report" << endl;
									cout << "Press 4 to Logout" << endl;
									cin >> option;
									if (option == 1) {
										bool *subjects = new bool[11];
										
										for (int i = 0; i < 11; i++) {
											subjects[i]=S1.RegisteredCourses()[i];
										}
										int counter = 1;
										for (int i = 0; i < 11; i++) {
											if (subjects[i]==1) {
												cout << counter << ". " << allcourses[i] << endl;
												counter++;
											}
										}
									}
									else if (option == 2) {
											bool subjects[11];
											int quizatpt = 0;
											int quizgiven[11];
											for (int i = 0; i < 11; i++) {
												quizgiven[i] = S1.getquizgive()[i];
											}

											for (int i = 0; i < 11; i++) {
												subjects[i] = S1.RegisteredCourses()[i];
											}
											int registerarray[11] = { 0 };
											int counter = 0;
											for (int i = 0; i < 11; i++) {
												if (subjects[i]) {
													cout << counter + 1 << ". " << allcourses[i] << endl;
													registerarray[counter] = i;
													counter++;
												}
											}

											cout << "Enter Number Which Course Quiz You Wanna Attempt?" << endl;
											cin >> quizatpt;
											//if (((quizatpt - 1) < 0) || ((quizatpt - 1) >= counter)) {
											//	break;
											//}
											quizatpt = quizatpt - 1;
											string coursename = allcourses[registerarray[quizatpt]];
											course[registerarray[quizatpt]]->showquizes(quizgiven[quizatpt],S1.getRoll(),coursename);
									}

									else if (option == 3) {
										bool subjects[11];
										int quizatpt = 0;


										for (int i = 0; i < 11; i++) {
											subjects[i] = S1.RegisteredCourses()[i];
										}
										int registerarray[11] = { 0 };
										int counter = 0;
										for (int i = 0; i < 11; i++) {
											if (subjects[i]) {
												cout << counter + 1 << ". " << allcourses[i] << endl;
												registerarray[counter] = i;
												counter++;
											}
										}

										cout << "Enter Number Which Course You Wanna See Report of?" << endl;
										cin >> quizatpt;

										quizatpt = quizatpt - 1;
										course[registerarray[quizatpt]]->showReport();

									}

									else if (option == 4) {
										option = 0;
										break;
									}
								}
							}
							else {
								system("cls");
								cout << "Invalid Password Kindly Re-enter Details" << endl;
							}
						}
					}

				}
				else if (option == 2) {
					string username;
					string check;
					string email = "@nu.edu.pk";
					int check1 = 1;
					while (1) {
						char roll[9];
						cout << "---Welcome To Student Password Changer--" << endl;
						cout << "Enter Your Login Id" << endl;
						cout << "22I-xxxx@nu.edu.pk" << endl;
						cout << "Enter 3 to go back" << endl;
						cin >> username;
						if (username == "3") {
							break;
						}

						for (int i = 0; i < 8; i++) {
							roll[i] = username[i];
						}
						roll[8] = '\0';
						check = roll + email;

						if (check == username) {
							if (RollExists(roll)) {
								check1 = 0;
							}
							else {
								system("cls");
								cout << "Roll Doesnt Exist" << endl << endl;
							}

						}
						else {
							system("cls");
							cout << "Invalid email kindly re-enter" << endl << endl;
						}

						if (check1 == 0) {
							cout << "Press 1 to change password" << endl;
							cout << "Press 2 to change password to default (Abcd.123)" << endl;
							cout << "Press 3 to go back" << endl;
							cin >> option;
							if (option == 1) {
								Student temp(roll);
								temp.changePass(roll);
							}
							else if (option == 2) {
								Student temp(roll);
								temp.changePassDef(roll);
							}
							else if (option == 3) {
								option = 0;
								break;
							}
						}


					}
				}

				else if (option == 3) {
					option = 0;
					break;
				}
			}

		}
		else if (option == 2) {
			while (1) {
				cout << "Press 1 for Login" << endl;
				cout << "Press 2 to change/forget Password" << endl;
				cout << "Press 3 to go back" << endl;
				cin >> option;
				if (option == 1) {
					int courseid;
					while (1) {
						cout << "-----Welcome to Faculty Login----" << endl;
						cout << "Enter 3 to go back" << endl;
						cout << "Enter Your Course id" << endl;
						cin >> courseid;
						if (courseid == 3) {
							break;
						}
						else if (CourseExist(courseid) == 1) {
							string password;
							int logged = 0;
							password= getPassword();
							if (!PasswordCheck(password)) {
								system("cls");
								cout << "Invalid Password kindly re-enter the details " << endl;
							}
							Teacher T1(courseid);
							int index;
							for (int i = 0; i < 11; i++) {
								if (courseid == courseids[i]) {
									index = i;
									break;
								}
							}
							system("cls");
							if (T1.getPassword() == password) {
								while (1) {
									
									cout << " Logged In Faculty : " << T1.getName() << endl<<endl;
									cout << "-----Welcome to Faculty Management----" << endl;
									cout << "Press 1 to Make Quiz" << endl;
									cout << "Press 2 to see Report" << endl;
									cout << "Press 3 to see analytics " << endl;
									cout << "Press 4 to Logout" << endl;
									do
									{
										cin >> option;
									} while (option < 1 || option>4);
									if (option == 1) {
										course[index]->makequiz();
									}
									else if (option == 2) {
										course[index]->showReport();
									}
									else if (option == 3) {
										course[index]->showanalytics();
									}
									else if (option == 4) {
										option = 0;
										break;
									}
								}
							}

						}
						else {
							cout << "Course Does Not Exists" << endl;
						}
					}
				}
				else if (option == 2) {
					int courseid;
					while (1) {
						cout << "---Welcome To Faculty Password Changer--" << endl;
						cout << "Enter 3 to go back" << endl;
						cout << "Enter Your Course id" << endl;
						cin >> courseid;
						if (courseid == 3) {
							break;
						}
						else if (CourseExist(courseid) == 1) {
							cout << "Press 1 to change password" << endl;
							cout << "Press 2 to change password to default (Abcd.123)" << endl;
							cout << "Press 3 to go back" << endl;
							cin >> option;
							if (option == 1) {
								Teacher temp(courseid);
								temp.changePass(courseid);
							}
							else if (option == 2) {
								Teacher temp(courseid);
								temp.changePassDef(courseid);
							}
							else if (option == 3) {
								option = 0;
								break;
							}

						}

					}
				}
				else if (option == 3) {
					option = 0;
					break;
				}
			}
		}

		else if (option == 3) {
			option = 0;
			return 0;
		}

	}

	delete PF;
	delete OOP;
	delete ICT;
	delete DS;
	delete AOA;
	delete SRE;
	delete RM;
	delete  BDA;
	delete AI;
	delete DL;
	delete DIP;
	return 0;
}

//	cout<<Hamza.User("avs";)
//	string S1;
//	string roll;
//	string name;
//	string subject1;
//	int current_row=0;
//	int row_req=2;

//	while(myfile.good()){
//		
//			getline(myfile,S1,',');
//			getline(myfile,roll,',');
//			getline(myfile,name,',');
//			getline(myfile,subject1,'\n');
//			 
//			cout<<" S# : "<< S1<<" "<<endl;
//			cout<<" Roll "<< roll<<" "<<endl;
//			cout<<" Name : "<< name<<" "<<endl;
//			cout<<" subject1 : "<< subject1<<" "<<endl;
//			cout<<"--------------------"<<endl;
//			break;
//	
//	}
//	myfile.close();

//	cout<<"Total number of lines are "<<current_row <<endl;

