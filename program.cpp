
//imports for the assignment
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#1
double compute_pi(int nthTerm){
	double series = 1; //the first number is 1
	//loop to calculate the total of all series to the nthTerm
	int i;
	for(i = 1; i <= nthTerm - 1; i++){
		//contant is the double at ithTerm 
		double constant = 1.0/((2*i) + 1);
		
		//if it is at an evan location subtract the current constant from the total series
		if(i % 2 != 0)
			series = series - constant;
		else //if it is at an odd location add the current constant to the total series
			series = series + constant;
	}
	return 4 * series; //return the series multipled by 4
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#2
void process_scores(){
	//variables needed to proccess the scores
	double totalStudents=0.0, score, totalScores=0.0, minScore=10000.0, maxScore=0.0, avgScore=0.0;
	//display the direction for the user
	cout << "\nThe score must be a positive integer.";
	cout << "\nEnter -1 to Quit";
	
	//Infintie loop, stops when u enter -1
	while(1){
		//get the information from the user	
		cout << "\nEnter the score: ";
		cin >> score;
		if(score == -1)//if the user enters -1 it ends the loop
			break;
		cin >> score; 
		
		totalStudents++; //increment the number of students
		totalScores= totalScores + score; //gather up all the students scored
		
		//checking for the lowest score
		if(score < minScore)
			minScore=score; //make the minScore the lowest score
		
		//checking for the hightest score
		if(score > maxScore)
			maxScore=score; //make the Maxscore the highest score
			
	}
	//check if there is more than 0 students
	if(totalStudents > 0){
		avgScore= totalScores/totalStudents; //get the average of all scores
		//printing out all the information
		cout << "\nThe average score is " << avgScore; //print the out average score
		cout << "\n" <<"The lowest score is "  << minScore;  //print out lowest score
		cout << "\n" << "The highest score is " << maxScore;  //print out highest score
	}else{
		cout << "No students were entered"; //if no students were printed
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#3
void  file_sort(char  *infile,  char  *outfile){
	
	ifstream studentsInFile(infile); //opening the input file stream
	ofstream studentsOutFile (outfile); //opening the ouput file stream
	
	//check if the file is found
	if(studentsInFile == NULL){
		printf("[ERROR] Couldn't Open FIle");
		exit(0);
	}
	
	int students;
	studentsInFile >> students; //get the first line witht the number of students in the file

	//dynamic arrays for id, gpa, grade
	int studentId[students];
	string studentGrade[students];
	double studentGpa[students];
	
	
	int k;
	//a loop to read all the lines with data in the file
	for (k=0; k< students; k++){
		studentsInFile >> studentId[k]; //first is 1d
		studentsInFile >> studentGrade[k]; //second is grade
		studentsInFile >> studentGpa[k]; //third is gpa
	}
	studentsInFile.close(); //close the file
	//temp variable for swapping
	int tempId, i, x;
	double tempGpa;
	string tempGrade;

	//bubble sort to sort the data
	for (i = 0; i< students-1; i++) {
		
	    for ( x = 0; x <students-i-1; x++) {
	    	//sorting them on id asending
	        if (studentId[x] > studentId[x+1]) {
	        	//swapping the ids
	            tempId = studentId[x+1];
	            studentId[x+1] = studentId[x];
	            studentId[x] = tempId;
	            
				//swapping the Gpas
	            tempGpa = studentGpa[x+1];
	            studentGpa[x+1] = studentGpa[x];
	            studentGpa[x] = tempGpa;
	            
				//swapping the grades
	            tempGrade = studentGrade[x+1];
	            studentGrade[x+1]= studentGrade[x];
	            studentGrade[x] = tempGrade;
	        } 
	    }
	}
	
	//printing the first line to the file
	studentsOutFile << "The " << students <<" students are sorted in ascending order by their ID"<< endl; 
	
	int j;
	for (j = 0; j < students; j++) {
		//printing out each student's info on seperate lines
	   studentsOutFile << studentId[j] << " " <<  studentGrade[j] << " " <<  studentGpa[j] << endl; 
	}
	cout << "File " << infile << " has been sorted, the sorted data is in file " << outfile; //printing to consol that the file has been sorted
	studentsOutFile.close(); //close the output file
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#4
//Rectangle class
class Rectangle{
	private:
		int width, height; //private data members integers width and height
		
	public: // the public data members of the class
		Rectangle(); //no parameter constructor
		Rectangle(int size); //1 parameter constructor
		Rectangle(int width, int height); //2 parameter constructor
		void setWidth(int width); //setter method for width
		int getWidth(); //getter method for width
		void setHeight(int height); //setter method for height
		int getHeight(); //getter method for height
		int area(); //method to get the area
		void print(); //method to print the data
	};
	 //no parameter constructor
	Rectangle::Rectangle(){
		//set width and height 0
		width = 0;
		height = 0;
	}
	//1 parameter constructor
	Rectangle::Rectangle(int size){
		//set width and height the size passed in
		width = size;
		height = size;
	}
	//2 parameter constructor
	Rectangle::Rectangle(int width, int height){	
		//set width and height to the paramters passed in
		this->width = width;
		this->height = height;
	}
	//setter for the variable width
	void Rectangle::setWidth(int width){
		this->width = width;
	}
	//getter for the variable width
	int Rectangle::getWidth(){
		return width;
	}
	//setter for the variable height
	void Rectangle::setHeight(int height){
		this->height = height;
	}
	//getter for the variable height
	int Rectangle::getHeight(){
		return height;
	}
	//method to find the area and return it
	int Rectangle::area(){
		return (width * height);
	}
	//print method to print 
	void Rectangle::print(){
		cout << "width is " << width << " and the height is " << height << endl;
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#5
class Score{
	private: //private data memebers students and a double arraY of scores
		int students;
		double *scores;
	public: //public data members 
		Score(int students, double *array); //2 parameter constructor
		double average(); //method to get the average
		void display(); //method to display the data
		~Score(); //deconstructor 
};
	//Student constructor with 2 parameters, takes the number of sudents as an integer, and an array of scores
	Score::Score(int students, double *array){
		this->students = students; //set the number of students to students
		this->scores = new double[students]; //newly created array of scores the size of the number of students
		//copying the given array to the newly created array
		int j;
		for (j = 0; j < students; j++)
			scores[j] = array[j];
	}
	//method that returns the average of all the score as a double
	double Score::average(){
		int j;
		double total=0; //counter to hold the total of all the scores
		//loop to get the total of all scores
		for (j = 0; j < students; j++)
			total += scores[j];
		
		return (total/students); //return the total of all scores divided by the number of students
	}
	
	void Score::display(){
		//display averge to counsel
		cout << "The average is " << average();
		//loop to display the scores all the students
		int j;
		for (j = 0; j < students; j++)
			cout << scores[j] << endl;
	}
	//desconstructor to free memory allocations
	Score::~Score(){
		delete []scores;
	}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#6
// the person class
class Person{
    // the private data members 
	private:
		//two private data members name and age
	    string name;
	    int age;
	    
    // the public data members of the class
	public:
		Person(string name, int age); //2 parameter constructor
		void setName(string name); //setter method for name
		string getName(); //getter method for name
		void setAge(int age); //setter method for age
		int getAge(); //getter method for age
};
    // constructor that takes a name and an age and sets them to the name and age of the person
    Person::Person(string name, int age){
    	this->name = name; //set name to name of the person
    	this->age = age; //set age to age of the person
 	}
    // setter method for name
    void Person::setName(string name){
        this->name = name;
    }
    // getter method for name returns string
    string Person::getName(){
        return name; //return name
    }
    // setter method for age
    void Person::setAge(int age){
        this->age = age;
    }
    // getter for age returns int
    int Person::getAge(){
        return age; //return age
    }


// Student class that inherits from the Person class using public
class Student : public Person{
    // the private data members of the class
	private:
		// two private data members id and gpa
	    int id;
	    double gpa;
	    
	public: // the public data members of the class
		Student(string name, int age, int id, double gpa); //4 parameter constructors
		void setId(int id); //setter method for id
		int getId(); //getter method for id
		void setGpa(double gpa); //setter method for gpa
		double getGpa(); //getter method for gpa
		void show(); //method to show all trhe data
	};

    Student::Student(string name, int age, int id, double gpa) : Person(name,age){
	//call the 2 parameter constructor method to set name and age of the student
		//set id and gpa to the given variables passed in
        this->id = id;
        this->gpa = gpa;
    }
    
    // setter method for gpa
    void Student::setGpa(double gpa){
        this->gpa = gpa;
    }
    // getter method for gpa returns a double
    double Student::getGpa(){
        return gpa; //return gpa 
    }
    // setter method for id
    void Student::setId(int id){
        this->id = id;
    }
    // getter method for id returns an integer
    int Student::getId(){
        return id; //return id
    }
    
    // the method to print
    void Student::show(){
        // print all the student data
        cout << "Student " << endl;
        cout << "Name : " << getName() << endl;
        cout << "Age  : " << getAge() << endl;
        cout << "Id   : " << getId() << endl;
        cout << "Gpa  : " << getGpa() << endl;
    }


