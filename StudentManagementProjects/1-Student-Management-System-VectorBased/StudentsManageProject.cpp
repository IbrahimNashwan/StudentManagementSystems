#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;
// ====== Enums for student major, edit fields, and search methods ======
enum enMajor { IT = 1, IS = 2, CS = 3, CYS = 4 };
enum enInfoStudents { FristName = 1, LastName = 2, Major = 3, Level = 4, Marks = 5 };
enum enSearchMethod { ID = 1, eName = 2 };

// ====== Global counters and constants ======
static int counter = 0;
const int Size = 6;
static int id = 100;

// ====== Student structure to hold all student data ======
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

// ====== Read a number within a specified range ======
int ReadNumberFromTo(int From, int To) {
    int number = 0;
    cout << "Please enter number between (" << From << "-" << To << ") !?" << endl;
    cin >> number;


    while (number < From || number >To || cin.fail()) {

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid Input ,Please enter number between (" << From << "-" << To << ") only !" << endl;
        cin >> number;
    }
    cin.ignore();
    return number;
}

// ====== Validate that a string contains only digits ======
bool isValidateDigit(const string& Number) {
    for (char c : Number) {
        if (!(c >= '0' && c <= '9'))
            return false;
    }
    return true;
}

// ====== Read and convert a number from string input ======
int ReadNumber1(string Message) {
    string NumToStr;
    int Number;

    do {
        //cout << "Please enter a number ? ";
        cout << Message << endl;
        getline(cin, NumToStr);

        if (!isValidateDigit(NumToStr)) {
            cout << "Invalid input! Please enter digits only." << endl;
        }

    } while (!isValidateDigit(NumToStr));

    Number = stoi(NumToStr); // ÊÍæíá ÇáäÕ Åáì ÚÏÏ ÕÍíÍ
    return Number;
}

// ====== Validate that a string contains only letters and spaces ======
bool isValidateText(const string& Text) {
    for (char c : Text) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '))
            return false;
    }
    return true;
}

// ====== Read and validate text input ======
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

// ====== Read and format a name (capitalize first letter) ======
void FillArray(int arr[Size]) {

    cout << "Please enter Number Of Subjects ?" << endl;

    for (int i = 0; i < Size; i++) {
        cout << "Please enter Subject " << i + 1 << " ?" << endl;

        arr[i] = ReadNumberFromTo(1, 100);
    }
    cout << endl;
}

// ====== Sum all marks in the array ======
int SumArray(int arr[Size]) {

    int Sum = 0;

    for (int i = 0; i < Size; i++) {

        Sum += arr[i];
    }

    return Sum;
}

// ====== Convert major enum to string ======
string ReadMajor(enMajor Major) {
    switch (Major) {
    case enMajor::IT:return "IT";
    case enMajor::IS:return "IS";
    case enMajor::CS:return "CS";
    case enMajor::CYS:return "CYS";
    }
}


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

// ====== Read and fill full student information ======
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

// ====== Update student info by ID or FullName ======
void ReadInfo(vector <stStudents>& Student, int IdEdit, string NameSearch)
{


    /*  id++;
      info.id = id;*/
    for (stStudents& Search : Student)
    {
        if (Search.id == IdEdit || Search.FullName == NameSearch)
        {
            // Read and update first and last names
            Search.FirstName = ReadName("Please enter Frist Name ?!");
            Search.LastName = ReadName("Please enter Last Name ?!");
            Search.FullName = Search.FirstName + " " + Search.LastName;


            // Read and update major
            int major;
            enMajor MyMajor;
            cout << "Please enter Major (IT = 1, IS = 2,CS = 3,CYS = 4) ?" << endl;
            major = ReadNumberFromTo(1, 4);
            MyMajor = (enMajor)major;
            Search.Major = ReadMajor(MyMajor);

            // Read and update level
            cout << "Please enter Level only between 1-4 ?" << endl;
            Search.level = ReadNumberFromTo(1, 4);

            // Read and update marks
            FillArray(Search.marks);

            // Calculate total marks and grade
            Search.total_marks = SumArray(Search.marks);
            Search.Grade = (float)Search.total_marks / Size;
        }


    }
}

// ====== Search a string in a vector of strings ======
string arrSearchByText(vector <string> arr, string TextSearch) {
    for (string& name : arr) {
        if (name == TextSearch)
            return name;
    }
    return "No";
}

// ====== Simple name search example with fixed names ======
void SearchByName() {
    vector <string> arr = { "ibrahim","ismail","faiz","mohammed","Ali","Lama" };
    string IsTextFound = ReadText("Please enter Search Name ? ");


    if (arrSearchByText(arr, IsTextFound) != IsTextFound)
        cout << " Name not found " << endl;
    else
        cout << " Name found " << endl;
}


// ====== Print elements of marks array ======
void PrintArray(int arr[Size]) {

    for (int i = 0; i < Size; i++) {
        cout << "Subject " << i + 1 << " :";
        cout << arr[i] << endl;
    }
}

// ====== (Unused) Placeholder for adding students vector ======
void addvector() {
    vector <stStudents> Students;
    char AddAgain = 'Y';
    do {

    } while (AddAgain);
}

// ====== Add one or more new student records ======
void AddanewStudentRecord(vector <stStudents>& Student)
{
    counter++;
    stStudents TempStudent;
    char ReadMore = 'Y';
    int Number;
    while (ReadMore == 'y' || ReadMore == 'Y')
    {

        ReadInfo(TempStudent);
        Student.push_back(TempStudent);
        cout << "\nDo you want to more students ? Y / N ? ";
        cin >> ReadMore;
        cin.ignore();
    }
}

// ====== Edit a specific part of a student record ======
void EditPartOfrecord(vector <stStudents>& Student, int IdEdit, string NameSearch)
{
    for (stStudents& Search : Student)
    {
        if (Search.id == IdEdit || Search.FullName == NameSearch)
        {
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
                FillArray(Search.marks);
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

// ====== Edit full or part of a student record ======
void EditaStudentRecord(vector <stStudents>& Student, int IdEdit, string NameSearch)
{
    int Choice;
    cout << "\nDo you want to edit part of the student record or the entire record ?" << endl;
    cout << "1) Edit part of the record ?" << endl;
    cout << "2) Edit the entire record ?" << endl;
    Choice = ReadNumber1("Please enter your choice ( 1 or 2 ) ?");

    if (Choice == 1) {
        EditPartOfrecord(Student, IdEdit, NameSearch);
    }
    else if (Choice == 2) {
        cout << "Please enter the new student information ... " << endl;
        ReadInfo(Student, IdEdit, NameSearch);
    }

}

// ====== Delete a student record by ID ======
void DeleteStudentRecordById(vector <stStudents>& Student, int IdDelete) {
    stStudents info;
    vector <stStudents> ::iterator iter;
    bool Found = false;
    for (iter = Student.begin(); iter != Student.end(); iter++)
    {
        if (iter->id == IdDelete)
        {
            iter = Student.erase(iter);
            cout << "\nThe Student's record has been deleted .\n" << endl;;

        }

        if (iter == Student.end())
            return;
    }
    if (!Found)
        cout << "\nThere ID does not exists or is inncorrect !.\n";;

}

// ====== Search a student by name and return found name ======
string SearchByName(vector <stStudents>& Student, string Massage) {

    string NameFound = ReadName(Massage);


    for (stStudents& NameSearch : Student)
    {
        if (NameSearch.FirstName == NameFound) {
            return NameFound;
        }
    }
    return "NoMatch";
}

// ====== Search a student by ID and return found ID ======
int SearchById(vector <stStudents> Student, string Massage) {

    int IdFound = ReadNumber1(Massage);


    for (stStudents& IdSearch : Student)
    {
        if (IdSearch.id == IdFound) {
            return IdFound;
        }
    }
    return -1;
}

// ====== Edit a student record by ID or Name ======
void EditRecord(vector <stStudents>& Student)
{
    int choice = 0;

    cout << "\nChoose how you want to identify the student for editing:\n" << endl;
    cout << "1)By ID number." << endl;
    cout << "2)By Name." << endl;
    choice = ReadNumber1("Please enter your choice ( 1 or 2 ) ?");
    enSearchMethod SearchMethod = (enSearchMethod)choice;

    int choiceID = 0;
    string choiceName = "";

    switch (SearchMethod)
    {
    case ID:
    {
        string Massage = "Please enter the student ID you want to edit:";
        choiceID = SearchById(Student, Massage);
        if (choiceID == -1)
        {
            cout << "Sorry ,The ID not Found !!" << endl << endl;
            return;
        }
        else
            EditaStudentRecord(Student, choiceID, choiceName);
        break;
    }
    case eName:
    {
        string Massage = "Please enter the student Name you want to edit:";
        choiceName = SearchByName(Student, Massage);
        if (choiceName == "NoMatch")
        {
            cout << "Sorry ,The Name not Found !!" << endl << endl;
            return;
        }
        else
            EditaStudentRecord(Student, choiceID, choiceName);
        break;


    }
    }

}

// ====== Print a single student record by ID or name ======
void PrintStudentRecord(vector <stStudents>& Student, int IdEdit, string NameSearch) {

    for (stStudents& Search : Student)
    {
        if (Search.id == IdEdit || Search.FirstName == NameSearch)
        {
            cout << "----------------------------------------------" << endl;
            cout << "---------------- Student Record---------------" << endl;
            cout << "----------------------------------------------" << endl;

            cout << "ID :" << Search.id << endl;
            cout << "First Name :" << Search.FirstName << endl;
            cout << "Last Name  :" << Search.LastName << endl;
            cout << "Full Name  :" << Search.FullName << endl;
            cout << "Major :" << Search.Major << endl;
            cout << "Level :" << Search.level << endl;
            cout << "Marks :" << endl; PrintArray(Search.marks);
            cout << "Total Marks :" << Search.total_marks << endl;
            cout << "Grade :" << Search.Grade << endl;

            cout << "----------------------------------------" << endl << endl;
        }
    }
}

// ====== Search menu for student record ======
void SearchforStudentRecord(vector <stStudents>& Student)
{
    int choice = 0;

    cout << "\n4)Search for a Student Record:\n" << endl;
    cout << "1)Search by the student’s id." << endl;
    cout << "2)Search by the student’s name" << endl;
    choice = ReadNumber1("Please enter your choice ( 1 or 2 ) ?");
    enSearchMethod SearchMethod = (enSearchMethod)choice;

    int choiceID = 0;
    string choiceName = "";

    switch (SearchMethod)
    {
    case ID:
    {
        string Massage = "Enter the ID number of the student whose record you want to display:";
        choiceID = SearchById(Student, Massage);
        if (choiceID == -1)
        {
            cout << "Sorry, the ID was not found." << endl << endl;
            return;
        }
        else
            PrintStudentRecord(Student, choiceID, choiceName);
        break;
    }
    case eName:
    {
        string Massage = "Enter the name of the student whose record you want to display:";
        choiceName = SearchByName(Student, Massage);
        if (choiceName == "NoMatch")
        {
            cout << "Sorry ,The Name was not found !!" << endl << endl;
            return;
        }
        else
            PrintStudentRecord(Student, choiceID, choiceName);
        break;


    }
    }

}

// ====== Sort student records by ID, Name or Grade ======
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

    case eName:
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

// ====== Print all students records ======
void PrintStudentsRecords(vector <stStudents> Student)
{

    cout << "-----------------------------------------------" << endl;
    cout << "--------------- Students Records---------------" << endl;
    cout << "-----------------------------------------------" << endl;

    for (stStudents& info : Student) {
        cout << "--------------- Student Record---------------" << endl;

        cout << "ID :" << info.id << endl;
        cout << "First Name :" << info.FirstName << endl;
        cout << "Last Name  :" << info.LastName << endl;
        cout << "Full Name  :" << info.FullName << endl;
        cout << "Major :" << info.Major << endl;
        cout << "Level :" << info.level << endl;
        cout << "Marks :" << endl; PrintArray(info.marks);
        cout << "Total Marks :" << info.total_marks << endl;
        cout << "Grade :" << info.Grade << endl;
    }
    cout << "--------------------------------------------------" << endl << endl;
}

// ====== Display students records ordered by criteria ======
void DisplayStudentsRecords(vector <stStudents>& Student)
{
    int choice = 0;

    //cout << "5) Display All of the Students Records." << endl;
    cout << "\n1) Display the students ordered by id." << endl;
    cout << "2) Display the students ordered by name." << endl;
    cout << "3) Display the students ordered by grade." << endl;
    choice = ReadNumberFromTo(1, 3);
    enSearchMethod SearchMethod = (enSearchMethod)choice;
    SortStudentsRecords(Student, SearchMethod);
    PrintStudentsRecords(Student);
}

// ====== Main menu with options ======
void MainMenu()
{
    vector <stStudents> Student;
    int choice;

    while (true)
    {
        cout << "-----------------------------------------" << endl;
        cout << "--------------- Main Menu ---------------" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1) Add a new Student Record." << endl;
        cout << "2) Edit a Student Record." << endl;
        cout << "3) Delete a Student Record." << endl;
        cout << "4) Search for a Student Record." << endl;
        cout << "5) Display All of the Students Records." << endl;
        cout << "6) Exit." << endl;
        cout << "-----------------------------------------" << endl;


        choice = ReadNumberFromTo(1, 6);
        switch (choice)
        {
        case 1:
            AddanewStudentRecord(Student);
            break;

        case 2:
        {
            EditRecord(Student);
            break;
        }
        case 3: {
            int IdDelete = ReadNumber1("Please enter the student ID you want to delete:");
            DeleteStudentRecordById(Student, IdDelete);
            break;
        }
        case 4:
            SearchforStudentRecord(Student);
            break;


        case 5:
            DisplayStudentsRecords(Student);
            break;

        }
    }
}

int main() {
    //SearchById();
    //SearchByName();
    //stStudents Students;
    //FillArray(Students.marks);
    //SumArray(Students.marks);
    //PrintArray(Students.marks);
    //string name = ReadName("please enter Frist Name ?!");
    //cout << name << endl;
    MainMenu();
}