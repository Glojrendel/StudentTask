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

 //streambuf <- ios <- ios_base <- istream\ostream <- iostream 

void BinTree()
{
	/*template<typename T>
class BinaryTree
{
private:
	struct Node
	{
		T data;

		Node* left;
		Node* right;
	};
	Node* root = nullptr;

	template<typename Func>
	void DoForNode(const Node* node, Func finction) const;
	void RemoveSubTree(Node* node);
	Node* Delete(Node* node, const T& value);
	Node* FindMinimum(Node* node);
	size_t Size(const Node* node) const;
	void CopyTree(Node*& tree1, Node*& const tree2);

public:
	BinaryTree() = default;
	BinaryTree(std::initializer_list<T> initList);
	BinaryTree(const BinaryTree& other);
	BinaryTree(BinaryTree&& other) noexcept;

	~BinaryTree();

};

template<typename T>
void ShowValue(const T& value)
{
	cout << value << "\n";
}

template<typename T>
void Show(const BinaryTree<T>& tree)
{
	cout << "Tree elements: ";

}

int main()
{
	cout << "-------Constructors-------";
	BinaryTree<int> tree;
	Show(tree);

	BinaryTree<int>tree1{ 1,2,5,10,26 };
	cout << "\nInitializer_list\n";
	Show(tree1);

	BinaryTree<int>tree2(tree1);
	cout << "\n\nCopy constructor\n";
	Show(tree2);

	BinaryTree<int>tree3(std::move(tree2));
	cout << "\n\nMove constuctor\n";
	Show(tree3);

	cout << endl; return 0;
}

template<typename T>
BinaryTree<T>::BinaryTree(std::initializer_list<T> initList)
{
	for (const T* value = initList.begin(); value != initList.end(); ++value)
	{
		Insert(*value);
	}
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other)
{
	CopyTree(this->root, other.root);
}

template<typename T>
BinaryTree<T>::BinaryTree(BinaryTree&& other) noexcept : root(other.root)
{
	other.root = nullptr;
}*/
}

//system(std::string("start " + std::string(" ")).c_str()); Statement for calling any website 
