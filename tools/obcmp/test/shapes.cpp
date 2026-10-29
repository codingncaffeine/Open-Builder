// Spellings obshape reads back (tools/obcmp/test/shapes.sh); the shape each compiles to is in shapes.O1.expected and
// shapes.O2.expected.
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
class C {
public:
    virtual uint32_t GetD();
    virtual bool GetB();
    virtual uint8_t GetUB();
    virtual uint32_t GetBZ();
    virtual uint32_t GetBS();
    virtual uint16_t GetW();
    virtual uint32_t GetWZ();
    virtual uint32_t GetWS();
    virtual float GetF();
    virtual double GetQ();
    virtual void* GetA();
    virtual void SetD(uint32_t);
    virtual void SetB(bool);
    virtual void SetW(uint16_t);
    virtual void SetF(float);
    virtual void SetD2(uint32_t, uint32_t);
    virtual bool SetDRet(uint32_t);
    virtual uint32_t K0();
    virtual uint32_t K1();
    virtual uint32_t Km1();
    virtual uint32_t K5(uint32_t);
    virtual bool KT();
    virtual bool KF();
    virtual float KF0();
    virtual float KF1();
    virtual float KF2();
    virtual void E(uint32_t, uint32_t);
    virtual C* This();
    uint32_t d; bool b; uint8_t ub; signed char sb; uint16_t w; short sw; float f; double q; char arr[4];
};
uint32_t C::GetD() { return d; }
bool C::GetB() { return b; }
uint8_t C::GetUB() { return ub; }
uint32_t C::GetBZ() { return ub; }
uint32_t C::GetBS() { return sb; }
uint16_t C::GetW() { return w; }
uint32_t C::GetWZ() { return w; }
uint32_t C::GetWS() { return sw; }
float C::GetF() { return f; }
double C::GetQ() { return q; }
void* C::GetA() { return arr; }
void C::SetD(uint32_t v) { d = v; }
void C::SetB(bool v) { b = v; }
void C::SetW(uint16_t v) { w = v; }
void C::SetF(float v) { f = v; }
void C::SetD2(uint32_t, uint32_t v) { d = v; }
bool C::SetDRet(uint32_t v) { d = v; return true; }
uint32_t C::K0() { return 0; }
uint32_t C::K1() { return 1; }
uint32_t C::Km1() { return 0xffffffff; }
uint32_t C::K5(uint32_t) { return 5; }
bool C::KT() { return true; }
bool C::KF() { return false; }
float C::KF0() { return 0.0f; }
float C::KF1() { return 1.0f; }
float C::KF2() { return 2.5f; }
void C::E(uint32_t, uint32_t) {}
C* C::This() { return this; }
