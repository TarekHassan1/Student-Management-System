#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
// using namespace std;
using std::basic_ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::getline;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::ostringstream;
using std::string;
using std::stringstream;
using std::vector;
using std::__cxx11::basic_string;
using std::__cxx11::to_string;

struct Student
{
    int rollnum;
    string stuName;
    int eng;
    int math;
    int science;
    int lang2nd;
    int CS;
};
void createStuRec();
void searchStuRec();
void displayAllStuRec();
void deleteStuRec();
void modifyStuRec();
int main()
{
    cout << " _____________Student-Report-Management-System___________\n";
    cout << "|                                                        |";
    cout << "\n| Choose What To Do Between These Options:               |";

    cout << "\n|                                                        |";
    cout << "\n| 1. Create a student record                             |\n";
    cout << "| 2. Search student record                               |\n";
    cout << "| 3. Display all students records                        |\n";
    cout << "| 4. Delete student record                               |\n";
    cout << "| 5. Modify student record                               |\n";
    cout << "| 6. Exit                                                |\n";
    int n;
    cout << "                          ";

    cin >> n;
    cout << "|________________________End_____________________________|\n";

    switch (n)
    {
    case 1:
        createStuRec();

        break;
    case 2:
        searchStuRec();
        break;
    case 3:
        displayAllStuRec();
        break;
    case 4:
        deleteStuRec();
        break;
    case 5:
        modifyStuRec();
        break;
    case 6:
        exit(0);
        break;
    default:
        main();
        break;
    }
    return 0;
}

void createStuRec()
{
    system("cls");
    Student s1;
    cout << "Enter Your Roll Number:  ";
    cin >> s1.rollnum;
    cout << "\nEnter Your Name:  ";
    cin.get();
    getline(cin, s1.stuName);
    cout << "\nEnter Your Marks in English: ";
    cin >> s1.eng;
    cout << "\nEnter Your Marks in math: ";
    cin >> s1.math;
    cout << "\nEnter Your Marks in science: ";
    cin >> s1.science;
    cout << "\nEnter Your Marks in 2nd Language: ";
    cin >> s1.lang2nd;
    cout << "\nEnter Your Marks in Computer science: ";
    cin >> s1.CS;
    ofstream f1("student.txt", ios::app);
    f1 << s1.rollnum << " " << s1.stuName << " " << s1.eng << " " << s1.math << " " << s1.science << " " << s1.lang2nd << " " << s1.CS << endl;
    f1.close();
    cout << "\n\nYou Have Succsesfully Created a record For a Student\n\n\n";
    int choose;
    cout << "Want To Return to Main menu? \n";
    cout << "\n Type 1 If you Want to return to main menu \n";
    cout << "\n Type 2 If you Want to return to Make another Student record \n";
    cout << "\n Type 0 If you Want to exit ";
    cin >> choose;
    if (choose == 1)
    {
        system("cls");

        main();
    }
    else if (choose == 2)
    {
        createStuRec();
    }
    else
    {
        exit(0);
    }
}
void searchStuRec()
{
    system("cls");
    Student s1;
    cout << "What is your Roll Number? ";
    cin >> s1.rollnum;
    int f;
    string text;
    string word;

    stringstream s;

    ifstream f1("student.txt", ios::in);

    while (getline(f1, text))
    {
        word = text;
        s << word;
        s >> f;
        if (f == s1.rollnum)
        {
            cout << "We Found A Record With this RollNumber and its: \n";
            cout << word << endl;
            break;
        }
        else if (f != s1.rollnum)
        {
            s.clear();
            s.str("");
        }
        else
        {
            cout << "Sorry We Didnt Find any Student record with this rollnumber Sorry";
        }
    }

    int choose;
    cout << "\nWant To Return to Main menu Or To try again or to Exit?? \n";
    cout << "\n Type 1 If you Want to return to main menu \n";
    cout << "\n Type 2 If you Want to Serch again \n";
    cout << "\n Type 0 If you Want to exit ";
    cin >> choose;
    if (choose == 1)
    {
        system("cls");
        main();
    }
    else if (choose == 2)
    {
        searchStuRec();
    }
    else
    {
        exit(0);
    }
};
void displayAllStuRec()
{
    system("cls");
    string text;
    int i = 1;
    ifstream f2("student.txt", ios::in);
    while (getline(f2, text))
    {

        cout << "Student " << i++ << " : " << text << endl;
        cout << endl;
    }
    f2.close();
    int choose;
    cout << "\nWant To Return to Main menu Or To try again or to Exit?? \n";
    cout << "\n Type 1 If you Want to return to main menu \n";
    cout << "\n Type 2 If you Want to See Students record again \n";

    cout << "\n Type 0 If you Want to exit   ";
    cin >> choose;
    if (choose == 1)
    {
        system("cls");
        main();
    }
    if (choose == 2)
    {
        displayAllStuRec();
    }
    else
    {
        exit(0);
    }
};
void deleteStuRec()
{
    system("cls");
    Student s1;
    cout << "What is your Roll Number Of student record you want to delete: ";
    cin >> s1.rollnum;
    cout << "\nStudents Records after deleting your Record :\n";

    vector<string>
        v;
    vector<string> v2;
    vector<string>::iterator it;

    int choose, f, i = 0, z = 0;
    string line, emptystr = "";
    stringstream s;
    ifstream f1("student.txt", ios::in);
    while (getline(f1, line))
    {
        v.emplace_back(line);
    }
    f1.close();
    while (i < v.size())
    {
        s << v[i];
        s >> f;
        if (f == s1.rollnum)
        {
            v[i] = emptystr;
        }
        else
        {
            s.clear();
            s.str("");
            i++;
        }
    }

    for (int j = 0; j < v.size(); j++)
    {
        if (v[j] == "" || v[j] == "\n")
        {
            continue;
        }
        else
        {
            v2.emplace_back(v[j]);
        }
    }
    vector<string>::iterator itt = v2.begin();
    if (i == v.size())
    {

        for (; itt != v2.end(); itt++)
        {

            cout << *itt << endl;
        }
    }

    ofstream f2("student.txt", ios::out | ios::trunc);
    f2.close();
    ofstream f3("student.txt", ios::app | ios::out);
    for (it = v2.begin(); it != v2.end(); it++)
    {
        f3 << *it << endl;
    }
    f3.close();
    cout << "\n\nYou Have Succsefully Deleted This Student's Record\n";

    cout << "\nWant To Return to Main menu Or To try again or to Exit?? \n";
    cout << "\n Type 1 If you Want to return to main menu \n";
    cout << "\n Type 2 If you Want to Delete Another Record again \n";
    cout << "\n Type 0 If you Want to exit ";
    cin >> choose;
    if (choose == 1)
    {
        system("cls");
        main();
    }
    else if (choose == 2)
    {

        deleteStuRec();
    }
    else
    {
        exit(0);
    }
};
void modifyStuRec()
{
    system("cls");
    Student s1;
    cout << "Enter Your Roll Number:  ";
    cin >> s1.rollnum;
    string text, word, updatedword;
    cout << "\nEnter Your New Name:  ";
    cin.get();
    getline(cin, s1.stuName);
    cout << "\nEnter Your New Marks in English: ";
    cin >> s1.eng;
    cout << "\nEnter Your New Marks in math: ";
    cin >> s1.math;
    cout << "\nEnter Your New Marks in science: ";
    cin >> s1.science;
    cout << "\nEnter Your New Marks in 2nd Language: ";
    cin >> s1.lang2nd;
    cout << "\nEnter Your New Marks in Computer science: ";
    cin >> s1.CS;
    updatedword = to_string(s1.rollnum) + " " + s1.stuName + " " + to_string(s1.eng) + " " + to_string(s1.math) + " " + to_string(s1.science) + " " + to_string(s1.lang2nd) + " " + to_string(s1.CS);

    int f;
    int i = 0;
    stringstream s;
    vector<string> v;
    vector<string> v1;

    ifstream f1("student.txt", ios::in);
    cout << endl;
    while (getline(f1, text))
    {
        v.emplace_back(text);
    }

    while (i < v.size())
    {

        s << v.at(i);
        s >> f;

        if (f == s1.rollnum)
        {
            v.at(i) = updatedword;

            // cout << v[i];
        }
        else if (f != s1.rollnum)
        {
            s.clear();
            s.str("");
            i++;
            s << v.at(i);
            s >> f;

            if (f == s1.rollnum)
            {
                v.at(i) = updatedword;

                // cout << v[i];
            }
        }
        if (i == v.size() - 1)
        {
            cout << "Students Data After Modifying\n";

            for (auto it : v)
            {
                cout << it << endl;
            }
            break;
        }
    }
    f1.close();
    ofstream f2("student.txt", ios::out | ios::trunc);
    f2.close();
    ofstream f3("student.txt", ios::app | ios::out);
    vector<string>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        f3 << *it << endl;
    }
    f3.close();

    cout << "\n\nYou Have Succsefully Updated Your Record\n";
    int choose;

    cout << "\nWant To Return to Main menu Or To try again or to Exit?? \n";
    cout << "\n Type 1 If you Want to return to main menu \n";
    cout << "\n Type 2 If you Want to Modify Your Record again \n";
    cout << "\n Type 0 If you Want to exit ";
    cin >> choose;
    if (choose == 1)
    {
        system("cls");
        main();
    }
    else if (choose == 2)
    {

        modifyStuRec();
    }
    else
    {
        exit(0);
    }
};
