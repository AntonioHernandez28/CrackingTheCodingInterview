#include <iostream> 
#include <stack> 
using namespace std; 

class MyQueue{
    private:
     stack<int> A;
    public:
     MyQueue(){
         stack<int> a = A; 
     };
     int front(); 
     void push(int num); 
     void pop(); 
};

int MyQueue::front(){
    stack<int> helper; 
    stack<int> copy; 
    copy = A; 
    while(!copy.empty()){
        helper.push(copy.top()); 
        copy.pop(); 
    }

    return helper.top(); 
}

void MyQueue::push(int num){
    A.push(num); 
    return; 
}

void MyQueue::pop(){
    stack<int> helper; 
    while(!A.empty()){
        helper.push(A.top()); 
        A.pop();
    }
    helper.pop(); 
    while(!helper.empty()){
        A.push(helper.top()); 
        helper.pop(); 
    }
}


int main(){
    MyQueue queue =  MyQueue(); 


    for(int i = 0; i < 6; i++){
        int n;
        cin >> n; 
        queue.push(n); 
    }

    for(int i = 0; i < 6; i++){
        cout << queue.front() << endl; 
        queue.pop(); 
    }
}