class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> count;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        count[key] = val;
    }
    
    int sum(string prefix) {
        int answer = 0;
        for(map<string, int>::iterator i = count.begin(); i != count.end(); i++)
        {
            if(i->first.find(prefix) == 0)
                answer += i->second;
        }
        return answer;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */