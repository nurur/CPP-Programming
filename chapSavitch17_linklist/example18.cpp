// Example 17.36, 17.37, 17.38
// Self-Test exercise 25
// Tree Template Class


#include <cstdlib>
#include <cstddef>
#include <iostream>
using namespace std;



//Forward Declaration 
template<class T>
class SearchTree;



//TreeNode Class
template<class T>
class TreeNode
{
  friend class SearchTree<T>;

public:
  TreeNode() : leftLink(NULL), rightLink(NULL) { }
  TreeNode(const T& theData, TreeNode<T>* theLeft, TreeNode<T>* theRight)
    : data(theData), leftLink(theLeft), rightLink(theRight) { }

private:
  T data;
  TreeNode<T>* leftLink;
  TreeNode<T>* rightLink;
};




//SearchTree 
template<class T>
class SearchTree
{
public:
  SearchTree() : root(NULL) { }
  virtual ~SearchTree();
  void insert(T item);
  bool inTree(T item) const;
  void inorderShow()  const;

private:
  void insert(T item, TreeNode<T>*& subTreeRoot);
  bool inTree(T item, TreeNode<T>* subTreeRoot) const;
  void inorderShow(TreeNode<T>* subTreeRoot)    const;
  void deleteSubtree(TreeNode<T>*& subTreeRoot);

  TreeNode<T>* root;
};



template<class T>
void SearchTree<T> :: insert(T item, TreeNode<T>*& subTreeRoot)
{
  if (subTreeRoot == NULL)
    subTreeRoot = new TreeNode<T>(item, NULL, NULL);
  else if (item < subTreeRoot->data)
    insert(item, subTreeRoot->leftLink);
  else 
    insert(item, subTreeRoot->rightLink);
}



template<class T>
void SearchTree<T> :: insert(T item)
{
  insert(item, root);
}


template<class T>
bool SearchTree<T> :: inTree(T item, TreeNode<T>* subTreeRoot) const
{
  if (subTreeRoot == NULL)
    return false; 
  else if (subTreeRoot->data == item)
    return true;
  
  if (item < subTreeRoot->data)
    return inTree(item, subTreeRoot->leftLink);
  else if (item > subTreeRoot->data)
    return inTree(item, subTreeRoot->rightLink);
}


template<class T>
bool SearchTree<T> :: inTree(T item) const
{
  return inTree(item, root);
}



template<class T>
void SearchTree<T> :: inorderShow(TreeNode<T>* subTreeRoot) const 
{
  if (subTreeRoot != NULL)
    {
      inorderShow(subTreeRoot->leftLink); 
      cout << subTreeRoot->data << " ";  
      inorderShow(subTreeRoot->rightLink);
    }
}


template<class T>
void SearchTree<T> :: inorderShow() const 
{
  inorderShow(root);
}


template<class T>
void SearchTree<T> :: deleteSubtree(TreeNode<T>*& subTreeRoot) 
{
  if (subTreeRoot != NULL)
    {
      deleteSubtree(subTreeRoot->leftLink);
 
      deleteSubtree(subTreeRoot->rightLink); 

      delete subTreeRoot;
      subTreeRoot = NULL;
    }
}


template<class T>
SearchTree<T>:: ~SearchTree() 
{
  deleteSubtree(root); 
}






int main()
{
  SearchTree<int> t;
  cout << "Enter a list of nonnegative integers.\n"
       << "Place a negative integer at the end.\n";
  
  int next;
  cin >> next;
  while (next > 0)
    {
      t.insert(next);
      cin >> next;
    }
  cout << endl;
  

  cout << "In sorted order: \n";
  t.inorderShow();
  cout << endl;

  return 0;
}
