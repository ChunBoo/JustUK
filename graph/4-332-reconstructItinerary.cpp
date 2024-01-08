/**
 * iven a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(const auto& ticket:tickets)
        {
            m_[ticket[0]].push_back(ticket[1]);
        }
        for( auto& kv:m_)//can not be const
        {
            auto& dests=kv.second;
            std::sort(dests.begin(),dests.end());
        }
        const string kStart="JFK";
        visit(kStart);
        return vector<string>(route_.crbegin(),route_.crend());
    }
private:
    unordered_map<string,deque<string>> m_;  //src-->{dst1,dst2,....dstn}
    vector<string> route_;
    void visit(const string& src)
    {
        auto& dests=m_[src];
        while(!dests.empty()){
            const string dest=dests.front();
            dests.pop_front();
            visit(dest);
        }
        route_.push_back(src);
    }
};