#include <iostream>
using namespace std; 
class Faculty{
	string name;
string post;
	int age;
	public:
		void setName(string name){
			this->name= name;
		}
		void setPost(string post){
			this->post= post;
		}
		void setAge(int age){
			this->age=age;
		}
		string getName(){
			return name;
		}
		string getPost(){
			return post;
		} 
		int getAge(){
			return age;
		}
};
class Node { 
 public: 
 Faculty get() {
 return object;
 } 
 void set(Faculty object){
 this->object.setName(object.getName());
 this->object.setPost(object.getPost());
 this->object.setAge(object.getAge());
 }
 Node * getNext(){
 return nextNode;
 } 
 void setNext(Node * nextNode){
 this->nextNode = nextNode;
 }
 private: 
 Faculty object; 
 Node * nextNode; 
}; 
/* The List class */ 
class List { 
public: 
 List(); 
 void add (Faculty addObject); 
 Faculty get(); 
 bool next(); 
 friend void traverse(List list); 
private: 
 int size; 
 Node * headNode; 
 Node * currentNode;  
}; 
/* Constructor */ 
List::List() { 
headNode = new Node(); 
 headNode->setNext(nullptr); 
 currentNode = nullptr; 
 size = 0; 
} 
/* add() class method */ 
void List::add (Faculty addObject) { 
 Node * newNode = new Node(); 
 newNode->set(addObject); 
 if( currentNode != nullptr ) 
 { 
 newNode->setNext(currentNode->getNext()); 
 currentNode->setNext( newNode ); 
 currentNode = newNode; 
 } 
 else 
 {  
 newNode->setNext(nullptr); 
 headNode->setNext(newNode); 
 currentNode = newNode; 
 } 
 size ++; 
} 

/* get() class method */ 
Faculty List::get() { 
if (currentNode != nullptr) 
 return currentNode->get(); 
} 

/* next() class method */ 
bool List::next() { 
 if (currentNode == nullptr) return false; 
 currentNode = currentNode->getNext(); 
 if (currentNode == nullptr || size == 0) 
return false; 
 else 
 return true; 
} 

/* Friend function to traverse linked list */
void traverse(List list) { 
 Node* savedCurrentNode = list.currentNode; 
 list.currentNode = list.headNode; 
 cout<<"=============Display Faculty Information================="<<endl<<endl;
 for(int i = 1; list.next(); i++) 
 { 
 Faculty member;
 member=list.get();
 cout << "Name : " << member.getName()<<endl; 
 cout << "Age : " << member.getAge()<<endl; 
 cout << "Post : " << member.getPost()<<endl; 
 } 
 list.currentNode = savedCurrentNode; 
} 
int main() { 
Faculty member;
string name,post;
List list; 
int age;
cout<<"==============Enter Faculty Information================="<<endl;
for(int a=0;a<5;a++){
	cout<<"Enter Faculty Member Age: "<<endl;
	cin>>age;
	cout<<"Enter Faculty Member Name: "<<endl;
	cin>>name;
	if(age>=25 && age<=35){
		post="Lecturer";
	}
	else if(age>=36 && age<=45){
		post="Assistant Professor";
	}
	else if(age>=46 && age<=60){
		post="Professor";
	}
	member.setName(name);
	member.setAge(age);
	member.setPost(post);
	list.add(member);
}
 traverse(list); 
}
