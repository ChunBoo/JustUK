/**
 * Implement a MyCalendarThree class to store your events. A new event can always be added.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A K-booking happens when K events have some non-empty intersection (ie., there is some time that is common to all K events.)

For each call to the method MyCalendar.book, return an integer K representing the largest integer such that there exists a K-booking in the calendar.

Your class will be called like this: MyCalendarThree cal = new MyCalendarThree();MyCalendarThree.book(start, end)

Example 1:

MyCalendarThree();
MyCalendarThree.book(10, 20); // returns 1
MyCalendarThree.book(50, 60); // returns 1
MyCalendarThree.book(10, 40); // returns 2
MyCalendarThree.book(5, 15); // returns 3
MyCalendarThree.book(5, 10); // returns 3
MyCalendarThree.book(25, 55); // returns 3
Explanation: 
The first two events can be booked and are disjoint, so the maximum K-booking is a 1-booking.
The third event [10, 40) intersects the first event, and the maximum K-booking is a 2-booking.
The remaining events cause the maximum K-booking to be only a 3-booking.
Note that the last event locally causes a 2-booking, but the answer is still 3 because
eg. [10, 20), [10, 40), and [5, 15) are still triple booked.
Note:

The number of calls to MyCalendarThree.book per test case will be at most 400.
In calls to MyCalendarThree.book(start, end), start and end are integers in the range [0, 10^9].
Idea:

Similar to LeetCode 731 My Calendar II Use an ordered / tree map to track the number of event at current time.

For a new book event, increase the number of events at start, decrease the number of events at end.

Scan the timeline to find the maximum number of events.
*/

class MyCalendarThree {
public:
    MyCalendarThree() {
        counts_[INT_MIN]=0;
        counts_[INT_MAX]=0;
        max_count_=0;
    }
    
    int book(int startTime, int endTime) {
        // ++delta_[startTime];
        // --delta_[endTime];
        // int ans=0;
        // int curr=0;
        // for(const auto& kv:delta_)
        // {
        //     ans=max(ans,curr+=kv.second);
        // }
        // return ans;
        auto l=prev(counts_.upper_bound(startTime));
        auto r=counts_.lower_bound(endTime);
        for(auto curr=l, next=curr;curr!=r;curr=next){
            ++next;
            if(next->first>endTime)
                counts_[endTime]=curr->second;
            if(curr->first<=startTime&&next->first>startTime    )
                max_count_=max(max_count_,counts_[startTime]=curr->second+1);
            else
                max_count_=max(max_count_,++curr->second);
        }
        return max_count_;
    }
private:
//   map<int,int> delta_;
    map<int,int> counts_;
    int max_count_;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */