class DynamicArray {
private:
    int *arr;
    int capacity;
    int len;
public:
    DynamicArray(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        len = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        // assert(this->len>=i);
        arr[i] = n;
    }

    void pushback(int n) {
        if(len == capacity){ resize(); }
        arr[len++] = n;
    }

    int popback() {
        if(len > 0){ len-=1; }
        return arr[len];
    }

    void resize() {
        capacity*=2;
        int *b = new int[capacity];
        for(int i=0;i<len;i++){ b[i] = arr[i]; }
        delete[] arr;
        arr = b;
    }

    int getSize() {
        return len;
    }

    int getCapacity() {
        return capacity;
    }
};
