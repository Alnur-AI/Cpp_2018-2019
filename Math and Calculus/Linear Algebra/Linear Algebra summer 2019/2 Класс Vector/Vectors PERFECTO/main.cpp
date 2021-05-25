#include <iostream>
#include <cstdlib>
using namespace std;

template <typename anyType>
class vector{
private:///main structure
    int size;
    anyType *element;
public:///primary functions
    void resize (int new_size);
    void push_back(anyType item);
    void pop_back();
    void push_front(anyType item);
    void pop_front();
    void rand_fill(anyType min_size, anyType max_size);
    anyType at(int i);
    int get_size();
    void input_vector();
    void output_vector();
    vector add(const vector &other);
    vector sub(const vector &other);
public:///constructors and destructor
    vector(){
        cout << "what size of vector do you want to have? ";
        cin >> size;
        if (size <= 0)
            size = 1;
        element = new anyType[size];
        for (int i = 0; i < size; i++)
            element[i] = 0;
        input_vector();
    }
    vector(int n){
        if (n < 0)
            n *= -1;
        element = new anyType[n];
        if (n == 0)
            size = 1;
        size = n;
        for (int i = 0; i < size; i++)
            element[i] = 0;
    }
    ~vector(){
        delete [] element;
    }
public:///operators
    bool operator==(const vector &other){
        if (size != other.size)
            return false;
        for (int i = 0; i < size; i++)
            if (element[i] != other.element[i])
                return false;
        return true;
    };
};

int main(){
    vector <int> a;
    a.output_vector();
    return 0;
}
template <typename anyType>
    void vector<anyType>::resize (int new_size){
        anyType *new_vector = new anyType[new_size];
        for (int i = size - 1; i < new_size; i++)
            new_vector[i] = 0;
        for (int i = 0; i < size; i++)
            new_vector[i] = element[i];
        delete [] element;
        element = new_vector;
        size = new_size;
    }
template <typename anyType>
    void vector<anyType>::push_back(anyType item){
        resize(size + 1);
        element[size] = item;
    }
template <typename anyType>
    void vector<anyType>::pop_back(){
        if (size == 1){
            return;
        }
        resize (size - 1);
    }
template <typename anyType>
    void vector<anyType>::push_front(anyType item){
        anyType *new_vector = new anyType[size + 1];
        new_vector[0] = item;
        for (int i = 0; i < size; i++){
            new_vector[i + 1] = element[i];
        }
        delete [] element;
        element = new_vector;
        size++;
    }
template <typename anyType>
    void vector<anyType>::pop_front(){
        anyType *new_vector = new anyType[size - 1];
        for (int i = 0; i < size - 1; i++){
            new_vector[i] = element[i+1];
        }
        delete [] element;
        element = new_vector;
        size--;
    }
template <typename anyType>
    void vector<anyType>::rand_fill(anyType min_size, anyType max_size){
        for (int i = 0; i < size; i++)
            element[i] = (anyType)(rand() % (int)(max_size+1)) + min_size;
    }
template <typename anyType>
    anyType vector<anyType>::at(int i){
        return element[i];
    }
template <typename anyType>
    int vector<anyType>::get_size(){
        return size;
    }
template <typename anyType>
    void vector<anyType>::input_vector(){
        for (int i = 0; i < this->size; i++){
            std::cout << "Element #" << i + 1 << ": ";
            cin >> this->element[i];
        }
    }
template <typename anyType>
    void vector<anyType>::output_vector(){
        cout << "( " << this->element[0] << ", ";
        for (int i = 1; i < this->size - 1; i++)
            cout << this->element[i]<< ", " ;
        cout << this->element[this->size - 1] << " )";
    }

/*

friend ostream &operator<<(ostream &os, vector &v);
    friend istream &operator>>(istream &is, vector &v);

    template <typename anyType>
ostream &operator<<(ostream &os, vector<anyType>  &v){
    os << "( " << v.element[0] << ", ";
    for (int i = 1; i < v.size - 1; i++){
        os << v.element[i]<< ", " ;
    }
    os << v.element[v.size - 1] << " )";
    return os;
}
template <typename anyType>
istream &operator>>(istream &is, vector<anyType> &v){
    for (int i = 0; i < v.size; i++){
        std::cout << "Element #" << i + 1 << ": ";
        is >> v.element[i];
    }
    return is;
}
*/
