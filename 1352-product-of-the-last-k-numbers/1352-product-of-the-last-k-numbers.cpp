class ProductOfNumbers {
public:


    
    
    vector<int> prod;

    ProductOfNumbers() {
        prod = {1}; 
    }
    void add(int num) {
        if(num == 0){
            prod = {1};
        } else {
            prod.push_back(prod.back() * num);
        }
    }
    int getProduct(int k) {
        int n = prod.size() - 1;
        if(k > n) return 0;
        return prod[n] / prod[n-k]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */