class MedianFinder {
public:
vector<double>v;
    MedianFinder() {}
    
    void addNum(int num) {
        auto it = lower_bound(v.begin(), v.end(), num);
        v.insert(it, num);
    }
    double findMedian() {
        if(v.size()%2==1){
            return v[v.size()/2];
        }
        return (v[v.size()/2] + v[(v.size()/2)-1])/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */