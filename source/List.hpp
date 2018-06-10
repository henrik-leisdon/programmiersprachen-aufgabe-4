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
    using Self = ListIterator<T>;

    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;

    ListIterator(): 
        node{nullptr}
    {}; 

    ListIterator(ListNode<T>* n):
        node{n}
    {};

    reference operator*() const {
        return node -> value;
    } 
    pointer operator->() const {
        return *node;
    } 
    Self& operator++() {
        node = node->next;
        return *this;
    } 
    Self operator++(int) {
        Self it(*this);
        ++(*this);
        return it;
    } 
    bool operator==(Self const& x) const {
        return node==x.node;
    } 
    bool operator!=(Self const& x) const {
        return node!=x.node;
    } 
    Self next() const
    {
    if (node)
        return ListIterator(node->next);
    else
        return ListIterator(nullptr);
    }


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
    {};



List(List<T> const& list):
    first_{nullptr},
    last_{nullptr},
    size_{0}
{
    for(auto it = list.begin(); it!=list.end(); it++){
        push_back(*it);
    }
};

List(List<T>&& list):
    first_(list.first_),
    last_(list.last_),
    size_(list.size_)
    {
       list.first_=nullptr;
       list.last_=nullptr;
       list.size-=0; 
    }

List(std::initializer_list<T> list)
{
    for(auto it : list)
    {
        push_back(it);
    }
};

~List()
{
    clear();
}

//size usw..


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

//modifier Functions:

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

void pop_front(){
    if(size() == 1)
    {
        assert(first_!=nullptr);
        delete first_;
        first_=nullptr;
        size_ = 0;
    }
    else if(size() > 1)
    {
        ListNode<T>* destroy = first_;
        first_=(*first_).next;
        (*first_).prsev = nullptr;
        delete destroy;
        destroy = nullptr;
        size_--;
    
    }
    else
    {
        std::cout << "list is already empty";
    }

}



void pop_back(){
    if(empty()){
        std::cout << "list is already empty";        
    }
    else if(size() == 1)
    {
        assert(last_!=nullptr);
        delete last_;
        last_=nullptr;
        size_ = 0;
    }    
    else
    {
        ListNode<T>* destroy = last_;
        last_=(*last_).prsev;
        (*last_).next = nullptr;
        delete destroy;
        destroy = nullptr;
        size_--;
    }

}

void clear() 
{
    if(empty()){
         std::cout << "list is already empty"; 
    }
    else
    {
        while(!empty())
        {
            pop_back();
        }
    }
}

ListIterator<T> begin() const
{
    return ListIterator<T>{first_};
}

ListIterator<T> end() const
{
    return ListIterator<T>{last_}.next();
}

List<T>& operator=(List<T>const& list)
{
    clear();
    for(ListIterator<T> it = list.begin();it!=list.end(); it++)
    {
        push_back(*it);
    }
}

private :
std::size_t size_ ;
ListNode <T >* first_ ;
ListNode <T >* last_ ;
};


template<typename T>
bool operator==(List<T> const& xs, List<T> const& ys)
{
    ListIterator<T> a = xs.begin();
    ListIterator<T> b = ys.begin();
    if(xs.size()!=ys.size())
    {
        return false;
    }
    else
    {
        int c = 0;
        while(c<xs.size())
        {
            if(*a == *b){
                a++;
                b++;
                c++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }


}

template<typename T>
bool operator!=(List<T> const& xs, List<T> const& ys)
{
    return !(xs == ys);
}


# endif

//#define BUW_LIST_HPP 