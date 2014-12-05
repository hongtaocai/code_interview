#include <stack>
#include <iostream>

using namespace std;

vector<int> st;

class IndexToValStack {
public:
    vector<int> indexSt;
    vector<int> valSt;
    
    IndexToValStack() {
    }
    
    void push(int x, int index) {
        if(index==0) {
            indexSt.push_back(index);
            valSt.push_back(x);
        } else {
            if(x!=valSt.back()) {
                indexSt.push_back(index);
                valSt.push_back(x);
            }
        }
    }
    void pop(int index) {
        if(index == indexSt.back()) {
            indexSt.pop();
            valSt.pop();
        }
    }
    
    int top() {
        return valSt.back();
    }
};

IndexToValStack mins;

class MinStack {
public:
    int min(int a, int b){
        if(a<b) {
            return a;
        }
        return b;
    }
    
    void push(int x) {
      if(st.size()>0) {
          mins.push(min(mins.back(), x), st.size());
      } else {
          mins.push(x, 0);
      }
      st.push_back(x);
    }

    void pop() {
      st.push_back();
      mins.pop(st.size());
    }

    int top() {
      return st.back();
    }

    int getMin() {
      return mins.top();
    }
};
