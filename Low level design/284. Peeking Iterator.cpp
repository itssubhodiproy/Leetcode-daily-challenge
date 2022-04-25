class PeekingIterator : public Iterator {
        vector<int> v;int i=0,n;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
	{v=nums;n = v.size();} 
	int peek(){return v[i];}
	int next(){return v[i++];} 
	bool hasNext() const {return i<n;}	    
};
