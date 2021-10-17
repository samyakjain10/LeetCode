class Bank {
public:
    map<int,long long>mp;
    int size;
    Bank(vector<long long>& balance) {
        int i = 1;
        for(auto x:balance) mp[i++] = x;
        size = i-1;
    }
    
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>size || account2>size) return false;
        if(mp[account1]>=money){
            mp[account2]+=money;
            mp[account1]-=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>size) return false;
        mp[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>size) return false;
        if(mp[account]>=money){
            mp[account]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */