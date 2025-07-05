#pragma once
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;


namespace MyLib {
	// Enumerations for student major, info fields, search method, and menu choices
	enum enMajor { IT = 1, IS = 2, CS = 3, CYS = 4 };
	enum enInfoStudents { FristName = 1, LastName = 2, Major = 3, Level = 4, Marks = 5 };
	enum enSearchMethod { ID = 1, Name = 2 };
	enum enChoice { enAdd = 1, enEdit = 2, enDelete = 3, enSearch = 4, enDisplay = 5 };

	static int counter = 0; // Counter for number of students added
	const int Size = 6; // Number of marks per student
	static int id = 100; // Starting ID for students

	// Structure to hold student data
	struct stStudents
	{
		int id;
		string FirstName;
		string LastName;
		string FullName;

		string Major;
		int level;
		int marks[Size];
		int total_marks;
		float Grade;
	};

	// Reads an integer within a given range, with input validation
	int ReadNumberFromTo(int From, int To) {
		int number = 0;
		//cout << "Please enter number between (" << From << "-" << To << ") !?";
		cin >> number;


		while (number < From || number >To || cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Input ,Please enter number between (" << From << "-" << To << ") only " << endl;
			cin >> number;
		}
		cin.ignore();
		return number;
	}

	// Reads any integer from user input, validating input
	int ReadNumber(string Message) {
		int number = 0;
		cout << Message;
		cin >> number;


		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Input ,Please enter number only !" << endl;
			cin >> number;
		}
		cin.ignore();
		return number;
	}

	// Checks if a string contains only digits
	bool isValidateDigit(const string& Number) {
		for (char c : Number) {
			if (!(c >= '0' && c <= '9'))
				return false;
		}
		return true;
	}

	// Reads a number within a range using string input with validation
	int ReadNumber1(int From, int To) {
		string NumToStr;
		int Number;

		cout << setw(40) << "" << left << "Please enter number between (" << From << "-" << To << ") ?";
		getline(cin, NumToStr);

		while (!isValidateDigit(NumToStr)) {

			if (!isValidateDigit(NumToStr)) {
				cout << setw(40) << "" << left << "Invalid input! Please enter number between (" << From << "-" << To << ") ?";
			}
			getline(cin, NumToStr);

		}

		Number = stoi(NumToStr); 
		return Number;
	}

	// Checks if a string contains only alphabetic letters
	bool isValidateText(const string& Text) {
		for (char c : Text) {
			if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
				return false;
		}
		return true;
	}

	// Reads a text input from user, only alphabetic, with validation
	string ReadText(string Message) {
		string NumToStr;
		string text;

		do {
			cout << Message << endl;
			getline(cin, text);

			if (!isValidateText(text)) {
				cout << "Invalid input! Please enter Text only." << endl;
			}

		} while (!isValidateText(text));

		return text;
	}

	// Reads multiple marks from user input into an array
	void FillArray(int arr[Size]) {

		cout << "Please enter Number Of Subjects ?" << endl;

		for (int i = 0; i < Size; i++) {
			cout << "Please enter Subject " << i + 1 << " ?" << endl;

			arr[i] = ReadNumberFromTo(1, 100);
		}
		cout << endl;
	}

	// Calculates the sum of an array of integers
	int SumArray(int arr[Size]) {

		int Sum = 0;

		for (int i = 0; i < Size; i++) {

			Sum += arr[i];
		}

		return Sum;
	}

	// Converts enum major to its string representation
	string ReadMajor(enMajor Major) {
		switch (Major) {
		case enMajor::IT:return "IT";
		case enMajor::IS:return "IS";
		case enMajor::CS:return "CS";
		case enMajor::CYS:return "CYS";
		}
	}

	// Reads and validates a lowercase text input (currently validates alphabetic text)
	string ReadSmallLetters(string Message) {

		string text;

		do {
			//cout << "Please enter a number ? ";
			cout << Message << endl;
			getline(cin, text);

			if (!isValidateText(text)) {
				cout << "Invalid input! Please enter small letter only." << endl;
			}

		} while (!isValidateText(text));

		return text;
	}

	// Reads and formats a proper name (capitalized first letter)
	string ReadName(string Massage)
	{
		string Name = ReadText(Massage);

		for (int i = 0; i < Name.length(); i++)
		{
			if (i == 0)
				Name[i] = char(toupper(Name[i]));

			else
				Name[i] = char(tolower(Name[i]));
		}
		return Name;
	}

	// Reads full name (first + last), capitalizing first letters
	string ReadFullName(string Massage)
	{
		string FristName = ReadText("Please Enter Frist Name :");
		string LastName = ReadText("Please Enter Last Name : ");

		for (int i = 0; i < FristName.length(); i++)
		{
			if (i == 0)
				FristName[i] = char(toupper(FristName[i]));
			else
				FristName[i] = char(tolower(FristName[i]));
		}
		for (int i = 0; i < LastName.length(); i++)
		{
			if (i == 0)
				LastName[i] = char(toupper(LastName[i]));
			else
				LastName[i] = char(tolower(LastName[i]));
		}
		string FullName = FristName + " " + LastName;
		return FullName;
	}

	// Reads full student information from user input and fills a student struct
	void ReadInfo(stStudents& Student)
	{
		id++;
		Student.id = id;
		Student.FirstName = ReadName("Please enter Frist Name ?!");
		Student.LastName = ReadName("Please enter Last Name ?!");
		Student.FullName = Student.FirstName + " " + Student.LastName;

		int major;
		enMajor MyMajor;
		cout << "Please enter Major (IT = 1, IS = 2,CS = 3,CYS = 4) ?" << endl;
		major = ReadNumberFromTo(1, 4);
		MyMajor = (enMajor)major;
		Student.Major = ReadMajor(MyMajor);

		cout << "Please enter Level only between 1-4 ?" << endl;
		Student.level = ReadNumberFromTo(1, 4);
		FillArray(Student.marks);

		Student.total_marks = SumArray(Student.marks);
		Student.Grade = (float)Student.total_marks / Size;

	}

	// Reads new info to update an existing student by ID or Name in the vector
	void ReadInfo(vector <stStudents>& Student, int IdEdit, string NameSearch)
	{

		for (stStudents& Search : Student)
		{
			if (Search.id == IdEdit || Search.FullName == NameSearch)
			{
				Search.FirstName = ReadName("Please enter Frist Name ?!");
				Search.LastName = ReadName("Please enter Last Name ?!");
				Search.FullName = Search.FirstName + " " + Search.LastName;


				int major;
				enMajor MyMajor;
				cout << "Please enter Major (IT = 1, IS = 2,CS = 3,CYS = 4) ?" << endl;
				major = ReadNumberFromTo(1, 4);
				MyMajor = (enMajor)major;
				Search.Major = ReadMajor(MyMajor);

				cout << "Please enter Level only between 1-4 ?" << endl;
				Search.level = ReadNumberFromTo(1, 4);
				FillArray(Search.marks);

				Search.total_marks = SumArray(Search.marks);
				Search.Grade = (float)Search.total_marks / Size;
			}
		}
	}

	// Prints array of marks nicely formatted
	void PrintArray(int arr[Size]) {

		for (int i = 0; i < Size; i++) {
			cout << setw(40) << "" << left << "Mark " << i + 1 << " :";
			cout << arr[i] << endl;

		}
	}

	// Writes all students data from vector to a file
	void AddDataFromVectorToFile(vector <stStudents>& Students, string FileName) {

		fstream MyFile;
		MyFile.open(FileName, ios::out); //Read Mode

		if (MyFile.is_open()) {
			for (stStudents& Student : Students)
			{


				MyFile << Student.id << endl;
				MyFile << Student.FirstName << endl;
				MyFile << Student.LastName << endl;
				MyFile << Student.FullName << endl;
				MyFile << Student.Major << endl;
				MyFile << Student.level << endl;

				for (int i = 0; i < Size; i++) {

					MyFile << Student.marks[i] << endl;
				}
				MyFile << Student.total_marks << endl;
				MyFile << Student.Grade << endl;
				MyFile << "----------------------------------------" << endl << endl;

			}
			MyFile.close();
		}
	}

	// Loads students data from file into vector
	void LoadDataFromFileToVector(vector <stStudents>& Students) {
		string FileName = "MyFile.txt";
		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open()) {

			Students.clear();

			while (true) {
				stStudents Student;

				if (!(MyFile >> Student.id)) break;
				id = Student.id;

				MyFile.ignore();

				getline(MyFile, Student.FirstName);
				getline(MyFile, Student.LastName);
				getline(MyFile, Student.FullName);
				getline(MyFile, Student.Major);

				MyFile >> Student.level;
				MyFile.ignore();

				for (int i = 0; i < Size; i++) {

					MyFile >> Student.marks[i];

				}

				MyFile >> Student.total_marks;
				MyFile.ignore();

				MyFile >> Student.Grade;
				MyFile.ignore();

				string IgnoreLine;
				getline(MyFile, IgnoreLine);
				getline(MyFile, IgnoreLine);

				Students.push_back(Student);
			}
		}
		MyFile.close();

	}

	// Adds new student records repeatedly until user stops
	void AddanewStudentRecord(vector <stStudents>& Student)
	{
		counter++;
		static stStudents TempStudent;
		string FileName = "MyFile.txt";
		char ReadMore = 'Y';
		int Number;
		while (ReadMore == 'y' || ReadMore == 'Y')
		{

			LoadDataFromFileToVector(Student);
			ReadInfo(TempStudent);
			Student.push_back(TempStudent);
			AddDataFromVectorToFile(Student, FileName);
			cout << "\nDo you want to more students ? Y / N ? ";
			cin >> ReadMore;
			cin.ignore();
		}
	}

	// Edits part of a student record by given ID or name
	void EditPartOfrecord(vector <stStudents>& Student, int IdEdit, string NameSearch)
	{

		for (stStudents& Search : Student)
		{
			if (Search.id == IdEdit || Search.FullName == NameSearch)
			{
				system("cls");
				cout << "Which part do you  want to edit?" << endl;
				cout << "1) Frist Name ? " << endl;
				cout << "2) Last Name ? " << endl;
				cout << "3) Major ? " << endl;
				cout << "4) Level ? " << endl;
				cout << "5) Marks ? " << endl;

				int Choice = ReadNumberFromTo(1, 5);
				enInfoStudents InfoStudents = (enInfoStudents)Choice;
				switch (InfoStudents)
				{
				case FristName:
					Search.FirstName = ReadName("Please enter Frist Name ?!");
					Search.FullName = Search.FirstName + " " + Search.LastName;
					break;

				case LastName:
					Search.LastName = ReadName("Please enter Last Name ?!");
					Search.FullName = Search.FirstName + " " + Search.LastName;
					break;

				case Major:

					int major;
					enMajor MyMajor;
					cout << "Please enter Major (IT = 1, IS = 2,CS = 3,CYS = 4) ?" << endl;
					major = ReadNumberFromTo(1, 4);
					MyMajor = (enMajor)major;
					Search.Major = ReadMajor(MyMajor);
					break;

				case Level:

					cout << "Please enter Level only between 1-4 ?" << endl;
					Search.level = ReadNumberFromTo(1, 4);
					break;

				case Marks:
					FillArray(Search.marks);
					Search.total_marks = SumArray(Search.marks);
					Search.Grade = (float)Search.total_marks / Size;
					break;
				}
			}
		}



	}

	// Chooses to edit part or entire student record
	void EditaStudentRecord(vector <stStudents>& Student, int IdEdit, string NameSearch)
	{
		int Choice;
		cout << "\nDo you want to edit part of the student record or the entire record ?" << endl;
		cout << "1) Edit part of the record ?" << endl;
		cout << "2) Edit the entire record ?" << endl;
		cout << "Please enter number between (" << 1 << "-" << 2 << ") !?";

		Choice = ReadNumberFromTo(1, 2);

		if (Choice == 1) {
			EditPartOfrecord(Student, IdEdit, NameSearch);
		}
		else if (Choice == 2) {
			cout << "Please enter the new student information ... " << endl;
			ReadInfo(Student, IdEdit, NameSearch);
		}

	}

	// Deletes student record by ID from vector and file
	void DeleteStudentRecordById(vector <stStudents>& Student, int IdDelete) {
		stStudents info;
		vector <stStudents> ::iterator iter;
		bool Found = false;
		LoadDataFromFileToVector(Student);

		for (iter = Student.begin(); iter != Student.end(); iter++)
		{
			if (iter->id == IdDelete)
			{
				iter = Student.erase(iter);
				AddDataFromVectorToFile(Student, "MyFile.txt");
				cout << "\nThe Student's record has been deleted successfully.\n" << endl;
				return;


			}

			/*if (iter == Student.end())
				return;*/
		}
		if (!Found)
			cout << "\nThere ID does not exists or is inncorrect !.\n";;

	}

	// Searches for student name and returns it if found, else "NoMatch"
	string SearchByName(vector <stStudents>& Student, string Massage) {

		string NameFound = ReadFullName(Massage);


		for (stStudents& NameSearch : Student)
		{
			if (NameSearch.FullName == NameFound) {
				return NameFound;
			}
		}
		return "NoMatch";
	}

	// Searches for student ID and returns it if found, else -1
	int SearchById(vector <stStudents> Student, string Massege) {

		int IdFound = ReadNumber(Massege);


		for (stStudents& IdSearch : Student)
		{
			if (IdSearch.id == IdFound) {
				return IdFound;
			}
		}
		return -1;
	}

	// Handles user interaction to edit student record by ID or Name
	void EditRecord(vector <stStudents>& Student)
	{
		int choice = 0;

		cout << setw(40) << "" << left << "-------------------------------------------------------" << endl;
		cout << setw(40) << "" << left << "---------------- Edit Student Record ---------------" << endl;
		cout << setw(40) << "" << left << "-------------------------------------------------------" << endl;
		cout << setw(40) << "" << left << "1)By ID number." << endl;
		cout << setw(40) << "" << left << "2)By Name." << endl;
		//cout << "Please enter number between (" << From << "-" << To << ") !?";

		choice = ReadNumber1(1, 2);
		enSearchMethod SearchMethod = (enSearchMethod)choice;

		int choiceID = 0;
		string choiceName = "";
		LoadDataFromFileToVector(Student);
		switch (SearchMethod)
		{
		case ID:
		{
			system("cls");
			string Massage = "Please enter the student ID you want to edit:";
			choiceID = SearchById(Student, Massage);
			if (choiceID == -1)
			{
				cout << "Sorry ,The ID not Found !!" << endl << endl;
				return;
			}
			else
				system("cls");
			EditaStudentRecord(Student, choiceID, choiceName);
			AddDataFromVectorToFile(Student, "MyFile.txt");

			break;
		}
		case Name:
		{
			system("cls");
			string Massage = "Please enter the student Name you want to edit:";
			choiceName = SearchByName(Student, Massage);
			if (choiceName == "NoMatch")
			{
				cout << "Sorry ,The Name not Found !!" << endl << endl;
				return;
			}
			else
				EditaStudentRecord(Student, choiceID, choiceName);
			AddDataFromVectorToFile(Student, "MyFile.txt");
			break;


		}
		}

	}

	// Prints detailed student record by ID or Name
	void PrintStudentRecord(vector <stStudents>& Student, int IdEdit, string NameSearch) {

		for (stStudents& Search : Student)
		{
			if (Search.id == IdEdit || Search.FullName == NameSearch)
			{
				cout << setw(40) << "" << left << "-------------------------------------------------------" << endl;
				cout << setw(40) << "" << left << "---------------- Display Student Record ---------------" << endl;
				cout << setw(40) << "" << left << "-------------------------------------------------------" << endl;

				cout << setw(40) << "" << left << "ID :" << Search.id << endl;
				cout << setw(40) << "" << left << "First Name :" << Search.FirstName << endl;
				cout << setw(40) << "" << left << "Last Name  :" << Search.LastName << endl;
				cout << setw(40) << "" << left << "Full Name  :" << Search.FullName << endl;
				cout << setw(40) << "" << left << "Major :" << Search.Major << endl;
				cout << setw(40) << "" << left << "Level :" << Search.level << endl;
				cout << setw(40) << "" << left << "Marks :" << endl; PrintArray(Search.marks);
				cout << setw(40) << "" << left << "Total Marks :" << Search.total_marks << endl;
				cout << setw(40) << "" << left << "Grade :" << Search.Grade << endl;

				cout << setw(40) << "" << left << "-------------------------------------------------------" << endl << endl;
			}
		}
	}

	// Searches and displays student record by ID or Name
	void SearchforStudentRecord(vector <stStudents>& Student)
	{
		int choice = 0;
		cout << setw(40) << "" << "----------------------------------------------" << endl;
		cout << setw(40) << "" << "--------------- Student Record ---------------" << endl;
		cout << setw(40) << "" << "----------------------------------------------" << endl;
		cout << setw(40) << "" << "1)Search by the student’s id." << endl;
		cout << setw(40) << "" << "2)Search by the student’s name" << endl;
		cout << setw(40) << "" << "----------------------------------------------" << endl;
		cout << setw(40) << "" << "Please enter number between (1 - 2) ?";


		choice = ReadNumberFromTo(1, 2);
		enSearchMethod SearchMethod = (enSearchMethod)choice;

		int choiceID = 0;
		string choiceName = "";
		LoadDataFromFileToVector(Student);
		switch (SearchMethod)
		{
		case ID:
		{	
			system("cls");
			string Massage = "Enter the ID number of the student whose record you want to display:";
			choiceID = SearchById(Student, Massage);
			if (choiceID == -1)
			{
				cout << "Sorry, the ID was not found." << endl << endl;
				return;
			}
			else
				system("cls");
			PrintStudentRecord(Student, choiceID, choiceName);
			break;
		}
		case Name:
		{
			system("cls");
			string Massage = "Enter the name of the student whose record you want to display:";
			choiceName = SearchByName(Student, Massage);
			if (choiceName == "NoMatch")
			{
				cout << "Sorry ,The Name was not found !!" << endl << endl;
				return;
			}
			else
				system("cls");
			PrintStudentRecord(Student, choiceID, choiceName);
			break;


		}
		}

	}

	// Sorts student vector by ID, Name, or Grade
	void SortStudentsRecords(vector <stStudents>& Student, enSearchMethod SearchMethod)
	{
		stStudents info;
		vector <stStudents> ::iterator iter1;
		vector <stStudents> ::iterator iter2;
		stStudents temp;

		switch (SearchMethod)
		{
		case ID:

			for (iter1 = Student.begin(); iter1 != Student.end(); iter1++) {
				for (iter2 = iter1 + 1; iter2 != Student.end(); iter2++) {
					if (iter1->id > iter2->id) {
						temp = *iter1;
						*iter1 = *iter2;
						*iter2 = temp;
					}

				}
			}
			break;

		case Name:
			for (iter1 = Student.begin(); iter1 != Student.end(); iter1++) {
				for (iter2 = iter1 + 1; iter2 != Student.end(); iter2++) {
					if (iter1->FirstName > iter2->FirstName) {
						temp = *iter1;
						*iter1 = *iter2;
						*iter2 = temp;
					}

				}
			}
			break;

		default:

			for (iter1 = Student.begin(); iter1 != Student.end(); iter1++) {
				for (iter2 = iter1 + 1; iter2 != Student.end(); iter2++) {
					if (iter1->Grade < iter2->Grade) {
						temp = *iter1;
						*iter1 = *iter2;
						*iter2 = temp;
					}

				}
			}
			break;
		}

	}

	// Prints all students records in a formatted way
	void PrintStudentsRecords(vector <stStudents> Student)
	{
		system("cls");
		cout << setw(40) << "" << left << "-----------------------------------------------" << endl;
		cout << setw(40) << "" << left << "--------------- Students Records---------------" << endl;
		cout << setw(40) << "" << left << "-----------------------------------------------" << endl;

		for (stStudents& info : Student) {
			cout << setw(40) << "" << left << "--------------- Student Record---------------" << endl;

			cout << setw(40) << "" << left << "ID :" << info.id << endl;
			cout << setw(40) << "" << left << "First Name :" << info.FirstName << endl;
			cout << setw(40) << "" << left << "Last Name  :" << info.LastName << endl;
			cout << setw(40) << "" << left << "Full Name  :" << info.FullName << endl;
			cout << setw(40) << "" << left << "Major :" << info.Major << endl;
			cout << setw(40) << "" << left << "Level :" << info.level << endl;
			cout << setw(40) << "" << left << "Marks :" << endl; PrintArray(info.marks);
			cout << setw(40) << "" << left << "Total Marks :" << info.total_marks << endl;
			cout << setw(40) << "" << left << "Grade :" << info.Grade << endl;
		}
		cout << setw(40) << "" << left << "--------------------------------------------------" << endl << endl;
	}
	// Displays all student records with sorting options
	void DisplayStudentsRecords(vector <stStudents>& Student)
	{
		int choice = 0;
		system("cls");

		LoadDataFromFileToVector(Student);
		cout << setw(40) << "" << "----------------------------------------------" << endl;
		cout << setw(40) << "" << "--------------- Student Record ---------------" << endl;
		cout << setw(40) << "" << "----------------------------------------------" << endl;
		cout << setw(40) << "" << "1) Display the students ordered by id." << endl;
		cout << setw(40) << "" << "2) Display the students ordered by name." << endl;
		cout << setw(40) << "" << "3) Display the students ordered by grade." << endl;

		choice = ReadNumberFromTo(1, 3);
		enSearchMethod SearchMethod = (enSearchMethod)choice;
		SortStudentsRecords(Student, SearchMethod);
		AddDataFromVectorToFile(Student, "MyFile.txt");
		PrintStudentsRecords(Student);
	}

	// Main interactive menu loop for the student management system
	void MainMenu()
	{
		vector <stStudents> Student;
		int choice;

		while (true)
		{
			system("cls");
			cout << setw(40) << "" << "-----------------------------------------" << endl;
			cout << setw(40) << "" << "--------------- Main Menu ---------------" << endl;
			cout << setw(40) << "" << "-----------------------------------------" << endl;
			cout << setw(40) << "" << "1) Add a new Student Record." << endl;
			cout << setw(40) << "" << "2) Edit a Student Record." << endl;
			cout << setw(40) << "" << "3) Delete a Student Record." << endl;
			cout << setw(40) << "" << "4) Search for a Student Record." << endl;
			cout << setw(40) << "" << "5) Display All of the Students Records." << endl;
			cout << setw(40) << "" << "6) Exit." << endl;
			cout << setw(40) << "" << "-----------------------------------------" << endl;

			choice = ReadNumber1(1, 6);
			enChoice Choice = (enChoice)choice;
			string AnyKey;
			switch (Choice)
			{
			case enAdd:
				system("cls");
				AddanewStudentRecord(Student);


				cout << "Enter Any Key to come back to Main Menu .";
				system("pause>0");
				break;

			case enEdit:
			{
				system("cls");
				EditRecord(Student);


				cout << "\n\nEnter Any Key to come back to Main Menu .";
				system("pause>0");
				break;
			}
			case enDelete: {
				system("cls");
				int IdDelete = ReadNumber("Please enter the student ID you want to delete:");
				DeleteStudentRecordById(Student, IdDelete);


				cout << "\n\nEnter Any Key to come back to Main Menu .";
				system("pause>0");
				break;
			}
			case enSearch:
				system("cls");
				SearchforStudentRecord(Student);

				cout << "Enter Any Key to come back to Main Menu .";
				system("pause>0");

				break;


			case enDisplay:
				system("cls");
				DisplayStudentsRecords(Student);

				cout << "Enter Any Key to come back to Main Menu .";
				system("pause>0");
				break;

			}
		}
	}

}