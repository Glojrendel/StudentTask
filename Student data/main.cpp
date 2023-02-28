#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <map>

using std::cout;
using std::cin;
using std::endl;

class Student
{
private:
	std::string m_lastname;
	int avg_score{};
	std::map<std::string, int>stud;

public:
	Student(){}
	Student(std::string lname, int scores) : m_lastname(lname), avg_score(scores){}
	virtual ~Student(){}

	int Menu();
	int AddStudent();
	int Sort_by_score();
	int ShowStudentList();
	
};

int Student::Menu()
{
	enum Select
	{
		ADD_STUDENT = 1,
		SHOW_STUDENTS,
		SORT_BY_VALUE
	};

	cout << "\n(1) | Add student |\n";
	cout << "(2) | Show students |\n";
	cout << "(3) | Sort by score |\n";
	cout << "(0) | Quit |\n";
	int sel;
	cout << "|-> "; cin >> sel;

	
	switch (sel)
	{
	case ADD_STUDENT:
		AddStudent();
		return Menu();

	case SHOW_STUDENTS:
		ShowStudentList();
		return Menu();

	case SORT_BY_VALUE:
		Sort_by_score();
		return Menu();

	case 0:
		cout << "\nQuit.\n";
		break;
	default:
		cout << "\nUnknown command, try again\n";
		return Menu();
	}
}

struct ValueComparator
{
	bool operator() (const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) const
	{
		return lhs.second > rhs.second;
	}
};

int Student::AddStudent()
{
	cout << "\nEnter a number of students (0 - to quit): ";
	int classRoom{}; cin >> classRoom;
	if (classRoom < 0)
	{
		cout << "Number cannot be less than 0.\n";
		return AddStudent();
	}
	else if (classRoom == 0)
	{
		cout << "Quit.";
		return 1;
	}
	do
	{
		cout << "\nEnter last name: "; cin >> m_lastname;
		cout << "Enter student's score: "; cin >> avg_score;
		stud.insert({ m_lastname, avg_score });

	} while (stud.size() < classRoom);
}

int Student::ShowStudentList()
{
	if (stud.empty())
	{
		cout << "\nNo students in data.\n";
		return Menu();
	}
	for (auto ipt = stud.begin(); ipt != stud.end(); ipt++)
	{
		cout <<"\nStudent: " << ipt->first << " [ " << ipt->second <<" ]";
	}
	cout << endl;
}

int Student::Sort_by_score()
{
	int count{0};

	if (stud.size() == 0) 
	{
		cout << "\nNo students added\n";
		return 1;
	}

	std::vector<std::pair<std::string, int> > sorted_stud(stud.begin(), stud.end());

	std::sort(sorted_stud.begin(), sorted_stud.end(), [](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	cout << "\n_____________________";
	cout << "\n| Student list | \n";
	for (const auto& p : sorted_stud) 
	{
		const auto& key = p.first;
		const auto& value = p.second;
		cout << "\n" << "(" << ++count << ") " << key << " [ " << value << " ]";
	}
	cout << "\n_____________________\n";
}

int main()
{
	Student math;
	math.Menu();
	
	cout << "\n\n"; return 0;
}
