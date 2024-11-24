#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue
{
    struct Node
    {
        int priority;
        T value;
    };

    Node* data;
    int maxSize;
    int currentSize;

public:
    PriorityQueue(int maxSize) : maxSize(maxSize), currentSize(0)
    {
        data = new Node[maxSize];
    }

    ~PriorityQueue()
    {
        delete[] data;
    }

    bool IsEmpty() const
    {
        return currentSize == 0;
    }

    bool IsFull() const
    {
        return currentSize == maxSize;
    }

    void InsertWithPriority(int priority, const T& value)
    {
        if (IsFull()) {
            cout << "Null!\n";
            return;
        }

        data[currentSize].priority = priority;
        data[currentSize].value = value;
        currentSize++;

        for (int i = currentSize - 1; i > 0; --i)
        {
            if (data[i].priority > data[i - 1].priority)
            {
                Node temp = data[i];
                data[i] = data[i - 1];
                data[i - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }

    T PullHighestPriorityElement()
    {
        if (IsEmpty())
        {
            throw "Null!";
        }

        T highestPriorityValue = data[0].value;

        for (int i = 0; i < currentSize - 1; ++i)
        {
            data[i] = data[i + 1];
        }

        currentSize--;
        return highestPriorityValue;
    }

    T Peek() const
    {
        if (IsEmpty())
        {
            throw "Null!";
        }

        return data[0].value;
    }

    void Show() const
    {
        if (IsEmpty())
        {
            cout << "Null!\n";
            return;
        }

        cout << "Queue:\n";
        for (int i = 0; i < currentSize; ++i)
        {
            cout << "Priority: " << data[i].priority << ", Meaning: " << data[i].value << "\n";
        }
    }
};

int main()
{
    PriorityQueue<string> pq(5);

    pq.InsertWithPriority(10, "Alice");
    pq.InsertWithPriority(20, "Bob");
    pq.InsertWithPriority(15, "Charlie");

    pq.Show();

    cout << "Highest Element priority (Peek): " << pq.Peek() << "\n";

    cout << "Element extracted: " << pq.PullHighestPriorityElement() << "\n";

    pq.Show();

}
