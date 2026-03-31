/*
We are giving you guiding comments to help you fill out this header file.
The indentation of the comments serve as hints to how your code is structured. 

These are HINTS. PLEASE READ THE README.
Anything not specified here will be in the README.
For example, some functions may be const versions while others may not.
Some functions may throw exceptions while others are noexcept.
*/

/* Preprocessor directives. Guard the header file upon include */
#ifndef ICS_VECTOR_H
#define ICS_VECTOR_H
/*
Which include directives should you put here?
(hint: we may throw VectorExceptions. We also want to use ostream)
*/
#include <iosfwd>
#include "vector_exception.hpp"

/*
Templated Vector class definition with templated Iterator class member
The template type name can be T
*/

template <typename T> 
class Vector{
    
/* Begin by specifying private members of Vector */
private:
    /* We want to nest the Iterator class definition right here */
    size_t m_capacity;
    size_t m_size;
    T* buffer;

    class Iterator{
        friend class Vector<T>;

        
        friend Iterator operator+(const Iterator& it, size_t n) {
            if (!it.m_container || it.index + n > it.m_container->size())
                throw VectorException("out of bounds");
            return Iterator(it.m_container, it.index + n);
        }


        friend Iterator operator+(size_t n, const Iterator& it) {
            if (!it.m_container || it.index + n > it.m_container->size())
                throw VectorException("out of bounds");
            return Iterator(it.m_container, it.index + n);
        }

    /* Write out the private members of Iterator */
    private:
        Vector<T>* m_container;
        size_t index;
        Iterator(Vector<T>* c, size_t i) noexcept{
            m_container = c;
            index = i;
        }    
        /* there should be an m_container and an index */

    /* Here are our your public members of Iterator*/
    public:
        /* Write your constructors here */
        Iterator() noexcept{
            m_container = nullptr;
            index = 0;
        }

        /* Write your operator overloads here.*/
        
        /* Post and pre increment and decrement operators*/
        Iterator& operator++(){
            if(!m_container){
                throw VectorException("out of bounds");
            }
            if(index >= m_container->m_size){
                throw VectorException("out of bounds");
            }
            ++index;
            return *this;
        }

        Iterator operator++(int){
            if(!m_container){
                throw VectorException("out of bounds");
            }
            if(index >= m_container->m_size){
                throw VectorException("out of bounds");
            }
            Iterator copy = *this;
            ++index;
            return copy;
        }

        Iterator& operator--(){
            if(!m_container){
                throw VectorException("out of bounds");
            }
            if(index == 0){
                throw VectorException("out of bounds");
            }
            --index;
            return *this;
        }

        Iterator operator--(int){
            if(!m_container){
                throw VectorException("out of bounds");
            }
            if(index == 0){
                throw VectorException("out of bounds");
            }
            Iterator copy = *this;
            --index;
            return copy;
        }

        /* Overloaded += size_t operator */
        Iterator& operator +=(size_t n){
            for(size_t i = 0; i < n; i++){
                ++(*this);
            }

            return *this;
        }

        /* Overloaded -= size_t operator */
        Iterator& operator -=(size_t n){
            for(size_t i = 0; i < n; i++){
                --(*this);
            }

            return *this;
        }

        /* Overloaded - operator. The right hand side is a const Iterator& */
        Iterator operator-(size_t offset){
            Iterator copy = *this;
            copy -= offset;
            return copy;
        }

        /* Overloaded - operator.  The right hand side is a size_t */
        size_t operator-(const Iterator& other) const{
            if(m_container != other.m_container){
                throw VectorException("iterators point to different containers");
            }
            if(index >= other.index){
                return(index - other.index);
            }
            else{
                return(other.index - index);
            }
        }

        /* Overloaded == operator. The right hand side is a const Iterator& */
        bool operator==(const Iterator& other) const noexcept{
            return(m_container == other.m_container && index == other.index);
        }

        /* Overloaded != operator. The right hand side is const Iterator& */
        bool operator!=(const Iterator& other) const noexcept{
            return!(*this==other);
        }

        /* Overloaded star (*) operator to dereference. This returns a T& */
        T & operator*() const{
            if(index >= m_container->m_size){
                throw VectorException("out of bounds");
            }
            return m_container->buffer[index];
        }

        /* Overloaded -> operator. This returns a T* */
        T * operator->() const{
            if(index >= m_container->m_size){
                throw VectorException("out of bounds");
            }
            return &(m_container->buffer[index]);
        }
        /*
        It is correct to add a size_t to an Iterator.
        What keyword should you use to specify these next two overloads? (It's in the README)
        Remember, using + on Iterators is commutative.
        1 + Iterator and Iterator + 1 both return an Iterator that is one forward.
        */
    /* Specify your private Vector member fields. There should be three */
    };


/* You will define your public Vector members here*/
public:
    /* Default constructor */
    Vector() noexcept{
        m_capacity = 0;
        m_size = 0;
        buffer = nullptr;
    }

    /* An overloaded constructor (see README) */
    Vector(size_t cap){
        m_capacity = cap;
        m_size = 0;
        if(cap <= 0){
            buffer = nullptr;
        }
        else{
            buffer = new T[cap];
        }
    }


    /* The begin() function */
    Iterator begin() noexcept{
        return Iterator(this, 0);
    }

    /* The const version of begin(). Note: it returns a const T* type */
    const T* begin() const noexcept{
        if(m_size == 0){
            return nullptr;
        }
        else{
            return buffer;
        }
    }
    
    /* The empty() function */
    bool empty() const noexcept{
        return (m_size==0);
    }

    /* The end() function */
    Iterator end() noexcept{
        return Iterator(this, m_size);
    }

    /* The const version of end(). Note: it returns a const T* */
    T const * end() const noexcept{
        if(m_size == 0){
            return nullptr;
        }
        else{
            return buffer+m_size;
        }
    }

    /* The front() function */
    T & front() noexcept{
        return buffer[0];
    }

    /* The const version of front(). Note it returns a const T& this is different from begin()! */
    T const & front() const noexcept{
        return buffer[0];
    }

    /* The back() function */
    T & back() noexcept{
        return buffer[m_size-1];
    }

    /* The const version of back(). Note: it returns a const T& */
    T const & back() const noexcept{
        return buffer[m_size-1];
    }

    /* The push_back() function */
    void push_back(const T& value){
        if(m_size >= m_capacity){
            size_t new_capacity;
            if(m_capacity == 0){
                new_capacity = m_capacity + 1;
            }
            else{
                new_capacity = m_capacity * 2;
            }
            resize(new_capacity);
        }
        buffer[m_size++] = value;
    }


    /* The push_back function that takes an RValue reference (Type of T&&) */
    void push_back(T&& value){
        if(m_size >= m_capacity){
            size_t new_capacity;
            if(m_capacity == 0){
                new_capacity = m_capacity + 1;
            }
            else{
                new_capacity = m_capacity * 2;
            }
            resize(new_capacity);
        }
        buffer[m_size++] = std::move(value);
    }

    /* The pop_back() function*/
    void pop_back(){
        if(m_size == 0){
            throw VectorException("popping from empty");
        }

        buffer[m_size - 1].~T();
        --m_size;
    }

    /* The capacity() function */
    size_t capacity() const noexcept{
        return m_capacity;
    }

    /* The size() function */
    size_t size() const noexcept{
        return m_size;
    }

    /* The data() function. Returns type T* */
    T * data() noexcept{
        return buffer;
    }

    /* The const version of data(). Returns type const T* */
    T const * data() const noexcept{
        return buffer;
    }

    /* 
    The erase function. It takes in a start and end Iterator
    Hints for implementation:
        0 1 2 3 4 5
    We want to delete 1 2 3 4
        0    1    2    3    4    5
             ^start         ^end
    Replace what is at start with what is at end and advance start and end until it reaches the vec.end()
        0    4    2    3    4    5
                  ^s             ^e
        0    4    2    5    4    5
                       ^s            e=vec.end()
    Is anything after what s is now including s used?
    Hint: resize the vector to include only 0 4 2. You will implement resize anyways.
    */
    void erase(Iterator start, Iterator end){
        if(start == end){
            return;
        }

        size_t erase_count = end.index - start.index;
        size_t begin = start.index;
        size_t ending = end.index;

        while (ending < m_size) {
            buffer[begin] = std::move(buffer[ending]);
            begin++;
            ending++;
        }

        m_size = m_size - erase_count;
    }

    /* swap_elements(). Takes two iterators. Use std::move ! */
    void swap_elements(Iterator lhs, Iterator rhs) noexcept{
        T temp = std::move(buffer[lhs.index]);
        buffer[lhs.index] = std::move(buffer[rhs.index]);
        buffer[rhs.index] = std::move(temp);
    }

    /* Subscript operator[] overload */
    T & operator[](size_t index) noexcept{
        return buffer[index];
    }

    /* Const version of the subscript operator[] overload */
    T const & operator[](size_t index) const noexcept{
        return buffer[index];
    }

    /* 
    Overloaded == operator. The right hand side is another const<T>& vector.
    Make sure the sizes of the vectors are equal
    Also check the elements inside are equal.
    */
    bool operator==(const Vector & other) const noexcept{
        if(m_size != other.m_size){
            return false;
        }
        else{
            for(size_t i = 0; i < m_size; ++i){
                if(buffer[i] != other.buffer[i]){
                    return false;
                }
            }
        }
        return true;
    }

    /* Overloaded != operator. */
    bool operator!=(const Vector& other) const noexcept {
        return !(*this == other);
    }


    /* Vector copy constructor. Does a deep copy! */
    Vector(const Vector& otherVector){
        m_capacity = otherVector.m_capacity;
        m_size = otherVector.m_size;
        

        if(m_capacity > 0){
            buffer = new T[m_capacity];
            for(size_t i =0; i<m_size; ++i){
                new (&buffer[i]) T(otherVector.buffer[i]);
            }
        }
        else{
            buffer = nullptr;
        }
        
    }

    /* 
    Vector assignment operator.
    Make sure you don't leak memory here. 
    */
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        if (m_capacity != other.m_capacity) {
            delete[] buffer;
            m_capacity = other.m_capacity;
            buffer = (m_capacity > 0) ? new T[m_capacity] : nullptr;
        } 

        else {
            for (size_t i = 0; i < m_size; ++i) {
                buffer[i].~T();
            }
        }
    
        for (size_t i = 0; i < other.m_size; ++i) {
            new (&buffer[i]) T(other.buffer[i]);
        }

        m_size = other.m_size;

        return *this;
    }

    /* at() function. */
    T & at(size_t index){
        if(index >= m_size){
            throw VectorException("out of bounds");
        }
        return buffer[index];
    }

    /* const version of at() */
    T const & at(size_t index) const{
        if(index >= m_size){
            throw VectorException("out of bounds");
        }
        return buffer[index];
    }

    /* 
    operator<< 
    We want to write code that can write Vectors to an output stream
    like std::cout << v << std::endl;
    You should use the friend keyword somewhere in here. 
    */
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec){
        for(size_t i = 0; i < vec.m_size; ++i){
            os << vec.buffer[i] << ' ';  
        }
        return os;
    }

    /*
    Vector resize() function here.
    Allocate a new buffer to move all the old elements from the old one to.
    And then assign that new buffer to the `this`
    Make sure to use std::move() to move data from the old buffer to the new one.
    Make sure you don't leak memory!
    */
    void resize(size_t new_capacity){
        if(m_capacity == new_capacity){
            return;
        }
        if(new_capacity < m_size){
            m_size = new_capacity;
        }

        T* new_buffer = nullptr;

        if(new_capacity > 0){
            
            new_buffer = new T[new_capacity];

            for(size_t i = 0; i < m_size; ++i){
                new_buffer[i] = std::move(buffer[i]);
            }
        }

        delete[] buffer;
        buffer = new_buffer;
        m_capacity = new_capacity;
    }


    /*
    clear() function. Make sure the destructor of each element gets called.
    delete[] will automatically do this. 
    But there other ways of implementing this function.
    */
    void clear() noexcept {
    // call destructor for each element
        for (size_t i = 0; i < m_size; i++) {
            buffer[i].~T();
        }
        m_size = 0;
    }  


    /* Move constructor here */
    Vector(Vector&& rhs) noexcept{
        buffer = rhs.buffer;
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        rhs.m_size = 0;
        rhs.m_capacity = 0;
        rhs.buffer = nullptr;
    }

    /* 
    Move assignment here
    Make sure there are not memory leaks!
    */
    Vector& operator=(Vector&& other) noexcept{
        if (this == &other){
            return *this;
        }
        
        delete[] buffer;

        buffer = other.buffer;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        
        other.buffer = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
        
        return *this;

    }
    
    /* The Vector destructor goes here. Make sure there are no leaks */
    ~Vector() noexcept{
        delete [] buffer;
        m_size = 0;
        m_capacity = 0;
        buffer = nullptr;
    }
/* 
And we are finished with this header file! 
If you used an #ifndef #define, what should you add at the very end?
*/
};


#endif