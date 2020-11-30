#include "BinaryTree.h"

Node::Node() : m_value(""), m_left(nullptr), m_right(nullptr)
{

}
Node::Node(std::string val) : m_value(val), m_left(nullptr), m_right(nullptr)
{

}
void Node::setItem(const std::string& val)
{
	m_value = val;
}
void Node::setLeftChildPtr(Node * new_m_left)
{
	m_left = new_m_left;
}
void Node::setRightChildPtr(Node * new_m_right)
{
	m_right = new_m_right;
}
std::string Node::getItem() const
{
	return m_value;
}
Node * Node::getLeftChildPtr() const
{
	return m_left;
}
Node * Node::getRightChildPtr() const
{
	return m_right;
}
Node::~Node()
{
	delete this;
}



BinaryNodeTree::BinaryNodeTree(){
	rootPtr = nullptr;
}
BinaryNodeTree::~BinaryNodeTree(){
	this->clear(this->getRoot());
}

// we don't need to define them all, we only need to define one. keep const otherwise the functions won't work
//pg. 486

Node * BinaryNodeTree::getRoot(){
	return rootPtr;
}

Node * BinaryNodeTree :: Find(Node * treePtr, std::string target) const{
    if(treePtr != nullptr){
        Find(treePtr->getLeftChildPtr(),target);
        std::string theItem = treePtr->getItem();
		if(theItem == target){
			return treePtr;
		}
        Find(treePtr->getRightChildPtr(),target);
    }
	return nullptr;
}


int BinaryNodeTree::getHeightHelper(Node * subTreePtr) const{
	int max = 0;
	if(subTreePtr == nullptr){
		return 0;
	}
	else{
		if(getHeightHelper(subTreePtr->getLeftChildPtr()) > getHeightHelper(subTreePtr->getRightChildPtr())){
			return 1 + getHeightHelper(subTreePtr->getLeftChildPtr()) + max;
		}else{
			return 1 + getHeightHelper(subTreePtr->getRightChildPtr()) + max;
		}
	}
}

int BinaryNodeTree::getHeight() const{
	return getHeightHelper(rootPtr);
}

Node * BinaryNodeTree::placeNode(Node * sub, Node * newNode){
	Node * tempPtr;
	if(sub == nullptr){
		return newNode;
	}
	else if(sub -> getItem() > newNode -> getItem()){
		tempPtr = placeNode(sub->getLeftChildPtr(), newNode);
		sub->setLeftChildPtr(tempPtr);
	}
	else{
		tempPtr = placeNode(sub->getRightChildPtr(), newNode);
		sub->setRightChildPtr(tempPtr);
	}
	return sub;
}
bool BinaryNodeTree::add(const std::string & newData){
	Node * newNodePtr = new Node();
	newNodePtr -> setItem(newData);
	rootPtr = placeNode(rootPtr, newNodePtr);
	return true;
}
bool BinaryNodeTree::isEmpty() const{
    if(rootPtr == nullptr){
		return true;
	}else{
		return false;
	}
}


std::vector<std::string> BinaryNodeTree :: getAllAscending(Node * treePtr){
	std::vector<std::string> storeVect;
	if(treePtr != nullptr){
		getAllAscending(treePtr->getLeftChildPtr());
		getAllAscending(treePtr->getRightChildPtr());
		storeVect.push_back(treePtr->getItem());
	}
	return storeVect;
}

std::vector<std::string> BinaryNodeTree :: getAllDescending(Node * treePtr){
	std::vector<std::string> storeVect;
	if(treePtr != nullptr){
		storeVect.push_back(treePtr->getItem());
		getAllDescending(treePtr->getLeftChildPtr());
		getAllDescending(treePtr->getRightChildPtr());
	}
	return storeVect;
}

void BinaryNodeTree::clear(Node * treePtr){
	if(treePtr != nullptr){
		clear(treePtr->getLeftChildPtr());
		clear(treePtr->getRightChildPtr());
		treePtr = nullptr;
		delete treePtr;
	}
}
