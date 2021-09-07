
#include <iostream>
#include<cassert>

using namespace std;

class arrayListTy
{
public:
    bool isEmpty() const; //checks of list is empty

    bool isFull() const;//checks if list is full

    int listSize() const;//checks the length of list

    int maxListSize() const;//checks the total size of the list

    void print() const;//prints the members of the list

    bool isItemAtEqual(int location, int item) const;//checks for the item equality at the given location

    void insertAt(int location, int insertItem);

    void insertEnd(int insertItem);

    void removeAt(int location);

    void retrieveAt(int location, int& retItem);

    void replaceAt(int location, int repItem);

    void clearList();

    int seqSearch(int item) const;

    void insert(int insertItem);

    void remove(int removeItem);

    arrayListType(int size = 100);

    arrayListType (const arrayListType& otherList);

    ~arrayListType();


protected:
    int *list;    //array to hold the list elements
    int length;   //variable to store the length of the list
    int maxSize;  //variable to store the maximum
                  //size of the list
};

bool arrayListType::isEmpty() const
{
	return (length == 0);
}

bool arrayListType::isFull() const
{
	return (length == maxSize);
}

int arrayListType::listSize() const
{
	return length;
}

int arrayListType::maxListSize() const
{
	return maxSize;
}

void arrayListType::print() const
{
	int i;

	for (i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}

bool arrayListType::isItemAtEqual(int location, int item) const
{
	return(list[location] == item);
}

void arrayListType::insertAt(int location, int insertItem)
{
    int i;

    if (location < 0 || location >= maxSize)
        cout << "The position of the item to be inserted "
             << "is out of range." << endl;
    else
        if (length >= maxSize)  //list is full
            cout << "Cannot insert in a full list." << endl;
        else
        {
            for (i = length; i > location; i--)
                list[i] = list[i - 1]; //move the elements down

            list[location] = insertItem; //insert insertItem
                                         //at the specified
                                         //position

            length++;	//increment the length
        }
} //end insertAt


void arrayListType::insertEnd(int insertItem)
{
	if (length >= maxSize)  //the list is full
		cout << "Cannot insert in a full list." << endl;
	else
	{
		list[length] = insertItem;	//insert the item at the end
		length++;	//increment length
	}
} //end insertEnd


void arrayListType::removeAt(int location)
{
	int i;

	if (location < 0 || location >= length)
    	cout << "The location of the item to be removed "
			 << "is out of range." << endl;
	else
	{
   		for (i = location; i < length - 1; i++)
	 		list[i] = list[i+1];

		length--;
	}
} //end removeAt

void arrayListType::retrieveAt(int location, int& retItem)
{
	if (location < 0 || location >= length)
    	cout << "The location of the item to be retrieved is "
			 << "out of range." << endl;
	else
		retItem = list[location];
} // retrieveAt


void arrayListType::replaceAt(int location, int repItem)
{
	if (location < 0 || location >= length)
    	cout << "The location of the item to be replaced is "
			 << "out of range." << endl;
	else
		list[location] = repItem;

} //end replaceAt

void arrayListType::clearList()
{
	length = 0;
} // end clearList

arrayListType::arrayListType(int size)
{
    if (size <= 0)
    {
        cout << "The array size must be positive. Creating "
             << "an array of size 100. " << endl;

        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;
    list = new int[maxSize];
    assert(list != NULL);
}

arrayListType::~arrayListType()
{
	delete [] list;
}

	//copy constructor
arrayListType::arrayListType(const arrayListType& otherList)
{
    int j;

    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new int[maxSize];  //create the array
    assert(list != NULL);   //terminate if unable to allocate
                            //memory space

    for (j = 0; j < length; j++)  //copy otherList
        list [j] = otherList.list[j];
}//end copy constructor

int arrayListType::seqSearch(int item)  const
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length; loc++)
	   if (list[loc] == item)
	   {
			found = true;
			break;
	   }

	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

void arrayListType::insert(int insertItem)
{
    int loc;

    if (length == 0)     //list is empty
        list[length++] = insertItem; //insert the item and
                                     //increment the length
    else
        if (length == maxSize)
            cout << "Cannot insert in a full list." << endl;
        else
        {
            loc = seqSearch(insertItem);

            if (loc == -1)   //the item to be inserted
                             //does not exist in the list
                list[length++] = insertItem;
            else
                cout << "the item to be inserted is already "
                     << "in the list. No duplicates are "
                     << "allowed." << endl;
	}
} //end insert

void arrayListType::remove(int removeItem)
{
	int loc;

	if (length == 0)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);

		if (loc != -1)
			removeAt(loc);
		else
			cout << "The tem to be deleted is not in the list."
				 << endl;
	}

} //end remove


void testCopyConstructor(arrayListType testList);

int main()
{
	arrayListType list;									//Line 1
	int num;											//Line 2

	cout << "Line 3: Enter numbers ending with -999"
         << endl;										//Line 3

	cin >> num;											//Line 4

	while(num != -999)									//Line 5
	{
		list.insert(num);								//Line 6
		cin >> num;										//Line 7
	}

	cout << "Line 8: The list you entered is: "
  	     << endl;										//Line 8
	list.print();										//Line 9
	cout << "Line 10: The list size is: "
	     << list.listSize() << endl;					//Line 10

	cout << "Line 11: Enter the item to be deleted: ";	//Line 11
	cin >> num;											//Line 12
	cout << endl;										//Line 13

	list.remove(num);									//Line 14

	cout << "Line 15: After removing " << num
	     << " the list is: " << endl;					//Line 15
	list.print();										//Line 16
	cout << "Line 16: The list size is: "
	     << list.listSize() << endl;					//Line 17

	  //test copy constructor

	testCopyConstructor(list);							//Line 18

	cout << "Line 19: The list after the copy "
	     << "constructor." << endl;						//Line 19
	list.print();										//Line 20
	cout << "Line 21: The list size is: "
	     << list.listSize() << endl;					//Line 21

	return 0;											//Line 22
}

void testCopyConstructor(arrayListType testList)
{
	cout << "Line 23: Inside the function "
	     << "testCopyConstructor." << endl;				//Line 23

	testList.print();									//Line 24

	cout << "Line 25: The list size is: "
	     << testList.listSize() << endl;				//Line 25
}

