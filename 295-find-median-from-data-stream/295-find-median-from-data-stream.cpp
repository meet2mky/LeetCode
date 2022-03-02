class MedianFinder {
public:
    multiset<int> L;
    multiset<int> R;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        L.insert(num);
        if(L.size() - R.size() > 1){
            auto it = L.end();
            --it;
            R.insert(*it);
            L.erase(it);
        }
        if(L.size() && R.size()){
            while(*L.rbegin() > *R.begin()){
                auto lit = L.end();
                --lit;
                auto rit = R.begin();
                int r = *lit;
                int l = *rit;
                L.erase(lit);
                R.erase(rit);
                L.insert(l);
                R.insert(r);
            }
        }
    }
    
    double findMedian() {
        if(L.size() == R.size()){
            return (double)(*L.rbegin() + *R.begin())/2.0;
        }
        return (double)(*L.rbegin());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */