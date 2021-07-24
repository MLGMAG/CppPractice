#include <string>
#include <iostream>
#include <deque>

struct Operation {
    char operation;
    int32_t number;
};

std::istream& operator>>(std::istream& s, Operation& op) {
    s >> op.operation >> op.number;
    return s;
}

class ArithmeticExpresion {
public:
    explicit ArithmeticExpresion(int32_t base);
    void AddOperation(const Operation& op);
    void Print();
private:

    std::deque<char> line_;
    void AddInt(int32_t number);
};

ArithmeticExpresion::ArithmeticExpresion(int32_t base) {
    AddInt(base);
}

void ArithmeticExpresion::AddOperation(const Operation &op) {
    line_.emplace_front('(');
    line_.emplace_back(')');
    line_.emplace_back(' ');
    line_.push_back(op.operation);
    line_.emplace_back(' ');
    AddInt(op.number);
}

void ArithmeticExpresion::Print() {
    while (line_.size()) {
        std::cout << line_.front();
        line_.pop_front();
    }
}

void ArithmeticExpresion::AddInt(int32_t number) {
    if (number < 0) {
        line_.emplace_back('-');
        number = abs(number);
    }
    std::string str = std::to_string(abs(number));
    for (const auto& c : str) {
        line_.push_back(c);
    }
}

int main() {
    int basic, n;
    std::cin >> basic >> n;
    ArithmeticExpresion ae(basic);
    for (int i = 0; i < n; ++i) {
        Operation o;
        std::cin >> o;
        ae.AddOperation(o);
    }
    ae.Print();
    return 0;
}
