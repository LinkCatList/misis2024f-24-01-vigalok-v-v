#include <iostream>

class QueueL {
public:
    QueueL() try
    : Begin(0)
    , End(0)
    , Capacity(10)
    {
        Data = new float[Capacity];
    }
    catch (...) {
        delete[] Data;
    }

    QueueL(std::ptrdiff_t size) try
    : Begin(0)
    , End(size)
    , Capacity(size * 2)
    {
        Data = new float[Capacity];
        for (ptrdiff_t i = Begin; i < End; ++i) {
            Data[i] = 0;
        }
    }
    catch (...) {
        delete[] Data;
    }

    void Push(float Value) {
        Relax();
        Data[End] = Value;
        ++End; 
    }

    float Pop() {
        Relax();
        float value = Data[Begin];
        ++Begin;
        return value;
    }

    [[nodiscard]] bool Empty() const {
        return End - Begin == 0;
    }

    [[nodiscard]] std::ptrdiff_t Size() const {
        return End - Begin;
    }

    ~QueueL() {
        delete[] Data;
        Begin = 0;
        End = 0;
        Capacity = 0;
    }

private:
    void Relax() {
        if (Begin >= Size()) {
            ptrdiff_t oldSize = Size();
            for (ptrdiff_t i = Begin; i < End; ++i) {
                Data[i - Begin] = Data[i];
            }
            Begin = 0;
            End = oldSize;
        }
        if (Size() == Capacity) {
            Capacity = 2 * Size();
            float* oldData = new float[Size()];
            for (ptrdiff_t i = Begin; i < End; ++i) {
                oldData[i - Begin] = Data[i];
            }
            Data = new float[Capacity];
            for (ptrdiff_t i = Begin; i < End; ++i) {
                Data[i] = oldData[i - Begin];
            }
            delete[] oldData;
        }
    }

private:
    std::ptrdiff_t Begin;
    std::ptrdiff_t End;
    std::ptrdiff_t Capacity;

    float* Data;
};
