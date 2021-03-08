#include <iostream>
#include <vector>


class B1 {
public:
    void f() {
        std::cerr << "B1::f()\n";
    }

    virtual void vf() {
        std::cerr << "B1::vf()\n";
    }

    virtual void pvf() = 0;
};

class D1 : public B1 {
public:
    void f() {
        std::cerr << "D1::f()\n";
    }
    void vf() override {
        std::cerr << "D1::vf()\n";
    }

    void pvf() override {
        std::cerr << "D1::pvf()\n";
    };
};

class D2 : public D1 {
public:
    void vf() override {
        std::cerr << "D2::vf()\n";
    }
    void pvf() override {
        std::cerr << "D2::pvf()\n";
    };
};

class B2 {
public:
    virtual void pvf() = 0;
};

class D21 : public B2 {
public:
    void pvf() override {
        std::cerr << das_string;
    }

private:
    std::string das_string{"Lilla\n"};
};

class D22 : public B2 {
public:
    void pvf() override {
        std::cerr << der_int << std::endl;
    }

private:
    int der_int{0};
};

void f(B2 &bazis) {
    bazis.pvf();
}

int main() {

        D1 d;
        d.f();
        d.vf();
        d.pvf();
    
        B1 &b_ref = d;
        b_ref.f();
        b_ref.vf();
        b_ref.pvf();
    
        D2 dd;
        dd.f();
        dd.vf();
        dd.pvf();

    D21        bbd;
    D22	 bbdd;

    f(bbd);
    f(bbdd);
}
