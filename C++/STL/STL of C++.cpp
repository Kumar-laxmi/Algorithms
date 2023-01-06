#include<bits/stdc++.h>
using namespace std;

int main()
{
    // ========== PAIR ===========

    pair<int, pair<int,int>> p = {1, {3, 4}};
    //    marked here->           -   -
    cout<<p.first<<"  "<<p.second.first<<"  ";

    pair<int,int> arr[] = { {1,2}, {2,5}, {5,1} };
    //  marked here->                 -
    cout<<arr[1].second;

    // ========== VECTOR ===========

    emplace_back(2); // faster than push_back();
    // it dynamically increase the size like push_back()

    vector<pair<int, int>>vec;
    
    // simply emplace_back(1,2); it automatically considers the pair
    
    vector<int> v{5, 100}; // {100,100,100,100,100}

    vector<int> v1(v); // copy the vector 

    // ========== Access VECTOR ===========

    vector<int>::iterator it=v.begin(); // points to the memory of the first element

    it++;
    cout<< *(it) << " ";

    // v[0] or v.at(0)  access through any one

    it+=2; // it shifts to two further positions

    // {10,20,30,40}

    vector<int>::iterator it=v.end(); // points to the memory of the element after 40

    vector<int>::iterator it=v.rend(); // points to the memory before 10 and it works in reverse order

    vector<int>::iterator it=v.rbegin(); // points to the memory of 40  it++ will move to 30 and it works as reverse

    // v.back(); gives last element

    //  to loop we can use simple approach or

    for(vector<int)::iterator it = v.begin(); it!=v.end();it++){
        cout<<*(it);
    }
    // short syntax
    for(auto it = v.begin(); it!= v.end(); it++){
        cout<<*(it)<<" ";
    }
    // another syntax
    for(auto it : v)
        cout<<it<<" ";

    // ========== Delete VECTOR ===========
    
    v.erase(v.begin()+1); // it will be reshuffled

    // to delete 20,30 in {10,20,30,40,50}
    v.erase(v.begin()+1, v.begin()+3); // now becomes {10,40,50}
    // +3 to show after the element of 30 i.e. after the last element to delete
    
    // ========== Insert Function ===========

    vector<int>v(2,100); // {100,100}
    v.insert(v.begin(), 300); // {300,100,100}
    v.insert(v.begin()+1, 2, 10); // {300,10,10,100,100}

    // inserting a vector into another vector

    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}

    v.size(); // gives size
    v1.swap(v2); // swaps both vector
    v.clear(); // clears whole vector

    v.empty(); // gives the boolean value


    // ========== LIST ===========

    list<int> ls;

    ls.push_back(2); // {2}
    ls.push_front(5); // {5, 2} very cheap in terms of time complexity

    // similar to vector

    // ========== DEQUE ===========

    // very similar to list and vector

    // ========== STACK ===========

    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2,1}
    .... {3,3,2,1}
    st.emplace(5); //similar

    cout<<st.top(); // prints 5

    st.pop(); // it looks like {3,3,2,1}

    st.size(); // 4

    st.empty(); // false

    // everything happens to be O(1)


    // ========== QUEUE ===========

    queue<int> q;
    q.push(1); // {1}
    q.push(1); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5

    cout<<q.back(); // prints 9
    // Q is {1,2,9}

    cout<<q.front(); // prints 1

    q.pop(); // {2,9}

    cout<< q.front(); // prints 2

    // size swap empty same as stack

    // everything happens to be O(1)
    

    // ========== PRIORITY QUEUE ===========

    priority_queue<int>pq;

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}

    cout<< pq.top(); // prints 10

    pq.pop(); // {8,5,2}

    cout<< pq.top(); // prints 8

    // size swap empty same as others

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.emplace(10); // {2,5,10}

    cout<< pq.top(); // prints 2

    // greater element at the bottom due to the declared syntax

    // push, pop -> O(log n)
    // top -> O(1)


    // ========== SET ===========

    // everything is sorted and unique
    // entire tree is maintained within the concept

    set<int>st;
    st.insert(1); // {1}
    st.emplace(2); // {1,2}
    st.insert(2); // {1,2}
    st.insert(4); // {1,2,4}
    st.insert(3); // {1,2,3,4} 
    
    auto it = st.find(3); // returns an iterator that points to this 3
    st.erase(it); // takes constant time

    auto it = st.find(6); // if an element is not in the set then it returns st.end()
     
    st.erase(5); // deletes 5 and maintains the sorted order

    st.count(1); // gives boolean value

    // {1,2,3,4,5}
    auto it1=st.find(2);
    auto it1=st.find(4);
    st.erase(it1, it2); // after erase {1,4,5}

    st.lower_bound(2);
    st.upper_bound(3);

    // everything takes O(logn) time


    // ========== MULTISET ===========

    multiset<int>ms;
    // can contain multiple instances

    ms.erase(1); // will erase all instances

    ms.erase(ms.find(1)); // only one is erased
    ms.erase(ms.find(1), ms.find(1)+2);

    // ========== UNORDERED SET ===========

    unordered_set<int> st;
    // unique elements but random order

    // time complexity is mostly O(1)

    // lower_bound & upper_bound doesn't work

    // in worst case which happens rarely the complexity becomes O(n)


    // ========== MAP ===========

    // it stores key and value where key is unique and value can be duplicate

    // the key can be of any data type while the value can be anything

    map<int, pair<int,int>>mpp;
    map<pair<int, int>,int>mpp;
    map<int, int> mpp; // this is considered below

    mpp[1]=2;
    mpp.emplace({3,1});
    mpp.insert({2,4});

    {
        {1, 2}
        {2, 4}
        {3, 1}     // sorted order is maintained
    }

    mpp[{2,3}]=10; 

    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<endl;   // to iterate in map
    }

    cout<<mpp[1];  // prints 0 if element doesn't exist

    auto it = mpp.find(3); // it points to end() if the element doesn't exist
    cout<<*(it).second;

    // erase, swap, size, empty, lower_bound and upper_bound is the same


    // ========== MULTIMAP ===========

    multimap<int,int> mpp;  // empty multimap container
    // eveything same as map, only it can store multiple keys
    // only mpp[key] cannot be used here

    // ========== UNORDEREDMAP ===========

    unordered_map<int,int> mpp;
    // unique but not sorted 
    // same as set and unordered_set difference



    // ========== ALGORITHMS ===========

    sort(arr,arr+n);
    sort(v.begin(), v.end());

    sort(arr,arr+n, greater<int>); // sort in descending order

    // RANDOM Sort

    bool comp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second<p2.second) return true;
        else if(p1.second > p2.second) return false;
        // they are same
        if(p1.first>p2.first) return true;
        return false;
    }   // used below for sorting
    
    sort(a,a+n, comp); // comp is the comparator  (custom sorting using STL comparator)

    // sort it according to second element                    {{2,1},{4,1},{1,2}};
    // if second element is same, then sort                   first and second element is the same
    // it according to first element but in descending order  {{4,1},{2,1},{1,2}} will be the result

    pair<int,int>a[]={{1,2},{2,1},{4,1}};

    int num=7;
    int cnt= _builtin_popcountll(); // if the number is long long and it returns number of set bits e.g. returns 2 in 6 number

    string s ="123";
    sort(s.begin(),s.end()); // very necessary to sort before applying the function

    do{
        cout<<s<<endl;
    } while(next_permutation(s.begin(),s.end()));  // until false or null
    
    int maxi=*max_element(a,a+n);   // to find max element in array 'a'


    return 0;
}
