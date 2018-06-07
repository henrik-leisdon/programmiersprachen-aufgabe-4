# ifndef BUW_LIST_HPP
# define BUW_LIST_HPP
# include <cstddef>
#include <initializer_list>


// List .hpp

template <typename T>
class List ;

template <typename T>
struct ListNode
{
    T value = T();
    ListNode * prsev = nullptr ;
    ListNode * next = nullptr ;
};

template <typename T>
class ListIterator
{
public :

    ListIterator():
        node(nullptr)
    {};

    ListIterator(ListNode<T>* n):
        node{n}
    {};

private :
    ListNode <T >* node ;

    ListNode<T>& getListNode()
    {
    return *node;
    }

};

template <typename T>
class ListConstIterator
{
public :


// not implemented yet
// do not forget about the initialiser lists !
private :
ListNode <T >* node ;
};

template <typename T>
class List
{
public :
using value_type = T;
using pointer = T*;
using const_ponter = T const *;
using reference = T&;
using const_reference = T const &;
using iterator = ListIterator <T >;
using const_iterator = ListConstIterator <T >;



List():
    last_{nullptr},
    first_{nullptr},
    size_{0}
    {};

List(ListNode<T>* first):
    first_{first},
    last_{first},
    size_{1}
    {}



List(List<T> const& list):
    first_{nullptr},
    last_{nullptr},
    size_{0}
{
    for(auto it = list.begin(); it!=list.end(); it++){
        push_back(*it);
    }
}



bool empty() const
{
    return size_==0;
}

std::size_t size() const
{
    return size_;
}

T front() const{
    if(empty()){
         std::cout<<"list is empty";
         return 0;
    }
    else
    {
        return (*first_).value;
    }
}

T back() const{
    if(empty()){
        std::cout<<"list is empty";
        return 0;
    }
    else
    {
        return (*last_).value;
    }
}

//modifyer Functions:

void push_front(T const data){
    ListNode<T>* node = new ListNode<T>;
    (*node).value = data;

    if(!empty()){
        (*first_).prsev = node;
        (*node).next = first_;
    }
    else
    {
        last_=node;
    }
    first_ = node;
    size_++;
    node = nullptr;
}

void push_back(T const data){
    ListNode<T>* node = new ListNode<T>;
    (*node).value = data;

    if(!empty()){
        last_->next = node;
        node->prsev = last_;
    }
    else
    {
        first_=node;

    }
    last_ = node;
    size_++;
    node = nullptr;
}




private :
std::size_t size_ ;
ListNode <T >* first_ ;
ListNode <T >* last_ ;
};


# endif // # define BUW_LIST_HPP