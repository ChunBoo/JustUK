/**
 * 
 * You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
*/
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for(const auto& event:booked_){
            int s=event.first;
            int e=event.second;
            if(max(s,start)<min(e,end))
                return false;
            // booked_.emplace_back(start, end); //if put here, then each time will not be insert to the booked array
        } 
        booked_.emplace_back(start,end);
        return true;
    }
private:
    vector<pair<int,int>> booked_;
};
class MyCalendar2 {
public:
    MyCalendar2() {

    }
    
    bool book(int start, int end) {
        auto it=booked_.lower_bound(start); //the first element which >=start,ceiling element
        if(it!=booked_.cend()&&it->first<end)
            return false;
        if(it!=booked_.cbegin()&&(--it)->second>start)  //the floor element
            return false;
        booked_[start]=end;
        return true;
    }
private:
    map<int,int> booked_;  //start->end
};

int main() { 
    vector<int>  v1{10, 20}, v2{ 15, 25 }, v3{20, 30};
    MyCalendar m{};
    m.book(v1[0],v1[1]);
    m.book(v2[0],v2[1]);
    m.book(v3[0],v3[1]);
 }
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */