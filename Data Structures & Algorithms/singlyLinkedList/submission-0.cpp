class LinkedList {
private:
    vector<int> linkedList;
public:
    LinkedList() { }

    int get(int index) { 
        if(index >= linkedList.size()){ return -1; }
        return linkedList[index]; 
    }

    void insertHead(int val) {
        linkedList.insert(linkedList.begin(),val);
    }
    
    void insertTail(int val) {
        linkedList.push_back(val);
    }

    bool remove(int index) {
        if(index >= linkedList.size()){ return false; }
        linkedList.erase(linkedList.begin()+index);
        return true;
    }

    vector<int> getValues() {
        // vector<int>
        return linkedList;
    }
};
