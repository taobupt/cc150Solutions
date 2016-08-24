//class Animal{
//public:
//	string name;
//	int order;
//	Animal(string name) :name(name){}
//	void setOrder(int order){ order = order; }
//	int getOrder(){ return order; }
//	string getName(){ return name; }
//	bool isOlderThan(Animal a)
//	{
//		return order < a.order;
//	}
//	virtual int id(){ return 0; }
//};
//
//class Dog :public Animal{
//	Dog(string name) :Animal(name){}
//	int id(){ return 1; }
//};
//
//class Cat :public Animal{
//	Cat(string name) :Animal(name){}
//	int id(){ return 2; }
//};
//
//class AnimalQueue{
//public:
//	AnimalQueue(){ order = 0; }
//	list<Dog>dog;
//	list<Cat>cat;
//	void enqueue(Animal a);
//	Animal dequeueAny();
//	Dog dequeueDog();
//	Cat dequeueCat();
//private:
//	int order;
//};
//
//void AnimalQueue::enqueue(Animal a)
//{
//	a.setOrder(order++);
//	if (a.id() == 1)dog.push_back(*a);
//	else cat.push_back(a);
//}

class animal{
public:
	animal(){ order = 0; }
	void enqueue(string name);
	int dequeueAny();
	int dequeueDog();
	int dequeueCat();
private:
	string name;
	int order;
	queue<int>dog, cat;
};

void animal::enqueue(string name)
{
	if (name == "dog")
	{
		dog.push(order++);
	}
	else
	{
		cat.push(order++);
	}
}

int animal::dequeueAny()
{
	assert(!(dog.empty() && cat.empty()));
	int val;
	if (dog.empty()||dog.front() > cat.front())
	{
		val = cat.front();
		cat.pop();
	}
	else
	{
		val = dog.front();
		dog.pop();
	}
	return val;
}

int animal::dequeueDog()
{
	if (cat.empty())return INT_MIN;
	int val = dog.front();
	dog.pop();
	return val;
}

int animal::dequeueCat()
{
	if (cat.empty())return INT_MIN;
	int val = cat.front();
	cat.pop();
	return val;
}