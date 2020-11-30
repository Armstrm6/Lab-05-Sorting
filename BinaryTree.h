#include <string>
#include <vector>
//pulled both the interface class and the Node class from Lab 01: Linked List


class Node
{
private:
	std::string m_value;
	Node * m_left;
	Node * m_right;
	std::vector<std::string> nodeValsVector;
public:
	Node();
	Node(const std::string val);
	Node(const std::string val, Node * leftPtr, Node * rightPtr);
	void setItem(const std::string& val);
	//void setNext(Node* nextNodePtr);
	std::string getItem() const;
	bool isLeaf() const;

	Node * getLeftChildPtr() const;
	Node * getRightChildPtr() const;

	void setLeftChildPtr(Node * new_m_left);
	void setRightChildPtr(Node * new_m_right);
	
	
	Node * getNext() const;
	virtual ~Node();
	
};




class BSTInterface
{
public:
BSTInterface();
virtual ~BSTInterface();
//returns true if binary tree is empty, false otherwise
virtual bool isEmpty();
//returns the height of the binary tree
virtual int getHeight() const = 0;
//adds given data to a binary tree. returns true if successful, false if not
virtual bool add(const std::string newData);
//clears the tree completely
virtual void clear(Node * treePtr) = 0;
//retrieves specified data from a binary tree. data is returned without altering tree, throws an exception if not
virtual std::string getEntry(const std::string targetData);
//traverses this binary tree in a specified order and calls the function visit once at each node
virtual void inOrderTraverse(Node * treePtr);//Do you remeber the code to change a node to int static_cast<int>() why do you need it?
//constructor and destructor
};



class BinaryNodeTree : public BSTInterface {

private:
	Node * rootPtr;
protected:
	//functions that are meant to help work with the binary tree. not meant to be seen by the user. may use them or may not
	int getHeightHelper(Node * subTreePtr) const;
	int getNumberOfNodesHelper(Node * subTreePtr) const;
	std::string balancedAdd(Node * subTreePtr, Node * newNodePtr);
	virtual std::string removeValue(Node * subTreePtr, const std::string targetData, bool& isSuccessful);
	std::string moveValuesUpTree(Node * subTreePtr);
	virtual std::string findNode(Node * treePtr, const std::string, bool& isSuccessful);
	void destroyTree(Node * subTreePtr);

public:

	BinaryNodeTree();
	~BinaryNodeTree();

	bool isEmpty() const; //done
	int getHeight() const; //getting there
	//int getNumberOfNodes() const; may need this
	bool add(const std::string & newData); //need this, done
	void clear(Node * treePtr); //need this
    std::vector<std::string> getAllAscending(Node * treePtr);
	std::vector<std::string> getAllDescending(Node * treePtr);
	Node * placeNode(Node * sub, Node * newNode); //need this, done
	std::string getEntry(const std::string& targetData); //need this, maybe
	//bool contains(const std::string& entry) const;
	Node * Find(Node * treePtr, std::string target) const;
	Node * getRoot();
	BinaryNodeTree& operator = (const BinaryNodeTree& rightHandSide);

};







