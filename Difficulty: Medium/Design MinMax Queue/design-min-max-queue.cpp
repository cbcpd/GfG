class SpecialQueue {
    queue<int> q1;
    deque<int> q2; // for min
    deque<int> q3; // for max
  public:

    void enqueue(int x) {
        q1.push(x);

        // Maintain q2 for minimum
        while (!q2.empty() && q2.back() > x) {
            q2.pop_back();
        }
        q2.push_back(x);

        // Maintain q3 for maximum
        while (!q3.empty() && q3.back() < x) {
            q3.pop_back();
        }
        q3.push_back(x);
    }

    void dequeue() {
        if (q1.empty()) return;

        int frontVal = q1.front();

        // Update min deque
        if (!q2.empty() && frontVal == q2.front()) {
            q2.pop_front();
        }

        // Update max deque
        if (!q3.empty() && frontVal == q3.front()) {
            q3.pop_front();
        }

        q1.pop();
    }

    int getFront() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    int getMin() {
        if (q1.empty()) return -1;
        return q2.front();
    }

    int getMax() {
        if (q1.empty()) return -1;
        return q3.front();
    }
};

