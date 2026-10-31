#include "common/types.h"

struct View_0087527f_shapec01_gzcom {
    uint8_t mPad74[116];
    uint32_t mnCount;
    void Fn0087527f();
};

// FUNCTION: 0x0087527f
void View_0087527f_shapec01_gzcom::Fn0087527f()
{
    ++mnCount;
}

struct View_0087528b_shapec01_gzcom {
    uint8_t mPad78[120];
    uint32_t mnCount;
    void Fn0087528b();
};

// FUNCTION: 0x0087528b
void View_0087528b_shapec01_gzcom::Fn0087528b()
{
    ++mnCount;
}

struct View_00875784_shapec01_gzcom {
    uint8_t mPad20[32];
    uint32_t mnCount;
    void Fn00875784();
};

// FUNCTION: 0x00875784
void View_00875784_shapec01_gzcom::Fn00875784()
{
    ++mnCount;
}

struct View_0087578c_shapec01_gzcom {
    uint8_t mPad24[36];
    uint32_t mnCount;
    void Fn0087578c();
};

// FUNCTION: 0x0087578c
void View_0087578c_shapec01_gzcom::Fn0087578c()
{
    ++mnCount;
}

struct View_0091c264_shapec01_gzcom {
    uint8_t mPad28[40];
    uint8_t mData;
    void* Fn0091c264();
};

// FUNCTION: 0x0091c264
void* View_0091c264_shapec01_gzcom::Fn0091c264()
{
    return &mData;
}

struct View_0094a892_shapec01_gzcom {
    uint8_t mPad10ec[4332];
    uint8_t mData;
    void* Fn0094a892();
};

// FUNCTION: 0x0094a892
void* View_0094a892_shapec01_gzcom::Fn0094a892()
{
    return &mData;
}

struct View_00968337_shapec01_gzcom {
    uint8_t mPad60[96];
    uint8_t mData;
    void* Fn00968337();
};

// FUNCTION: 0x00968337
void* View_00968337_shapec01_gzcom::Fn00968337()
{
    return &mData;
}

struct View_0099bce1_shapec01_gzcom {
    uint8_t mPada8[168];
    uint8_t mData;
    void* Fn0099bce1();
};

// FUNCTION: 0x0099bce1
void* View_0099bce1_shapec01_gzcom::Fn0099bce1()
{
    return &mData;
}

struct View_00979426_shapec01_gzcom {
    uint32_t mnVtable;
    void Fn00979426();
};

// FUNCTION: 0x00979426
void View_00979426_shapec01_gzcom::Fn00979426()
{
    mnVtable = 0xad8fa4;
}

struct View_0087919f_shapec01_gzcom {
    uint32_t mnVtable;
    void Fn0087919f();
};

// FUNCTION: 0x0087919f
void View_0087919f_shapec01_gzcom::Fn0087919f()
{
    mnVtable = 0xac2f9c;
}

struct View_0090d964_shapec01_gzcom {
    uint32_t mnVtable;
    void Fn0090d964();
};

// FUNCTION: 0x0090d964
void View_0090d964_shapec01_gzcom::Fn0090d964()
{
    mnVtable = 0xace624;
}

struct View_0097538e_shapec01_gzcom {
    uint32_t mnVtable;
    void Fn0097538e();
};

// FUNCTION: 0x0097538e
void View_0097538e_shapec01_gzcom::Fn0097538e()
{
    mnVtable = 0xad8bec;
}

struct View_00945994_shapec01_gzcom {
    uint8_t mPad4c[76];
    uint32_t mnA;
    uint32_t mnB;
    bool Fn00945994(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00945994
bool View_00945994_shapec01_gzcom::Fn00945994(uint32_t a, uint32_t b)
{
    mnA = a;
    mnB = b;
    return true;
}

struct View_00938cd7_shapec01_gzcom {
    uint8_t mPad8[8];
    uint32_t mnA;
    uint8_t mPad20[20];
    uint32_t mnB;
    bool Fn00938cd7(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00938cd7
bool View_00938cd7_shapec01_gzcom::Fn00938cd7(uint32_t a, uint32_t b)
{
    mnA = a;
    mnB = b;
    return true;
}

struct View_00932a4a_shapec01_gzcom {
    uint8_t mPad8[8];
    uint32_t mnA;
    uint32_t mnB;
    bool Fn00932a4a(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00932a4a
bool View_00932a4a_shapec01_gzcom::Fn00932a4a(uint32_t a, uint32_t b)
{
    mnA = a;
    mnB = b;
    return true;
}

struct View_00949b03_shapec01_gzcom {
    uint8_t mPadd4[212];
    uint32_t mnA;
    uint32_t mnB;
    bool Fn00949b03(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00949b03
bool View_00949b03_shapec01_gzcom::Fn00949b03(uint32_t a, uint32_t b)
{
    mnA = a;
    mnB = b;
    return true;
}

struct View_00893dd7_shapec01_gzcom {
    uint8_t mPadc[12];
    uint32_t mnRefs;
    // STUB: 0x893d68
    void Last();
    uint32_t Fn00893dd7();
};

// FUNCTION: 0x00893dd7
uint32_t View_00893dd7_shapec01_gzcom::Fn00893dd7()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Last();
    return 0;
}

struct View_009939ac_shapec01_gzcom {
    uint8_t mPad20[32];
    uint32_t mnRefs;
    // STUB: 0x9935b6
    void Last();
    uint32_t Fn009939ac();
};

// FUNCTION: 0x009939ac
uint32_t View_009939ac_shapec01_gzcom::Fn009939ac()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Last();
    return 0;
}

struct View_00993b0c_shapec01_gzcom {
    uint8_t mPad24[36];
    uint32_t mnRefs;
    // STUB: 0x99364c
    void Last();
    uint32_t Fn00993b0c();
};

// FUNCTION: 0x00993b0c
uint32_t View_00993b0c_shapec01_gzcom::Fn00993b0c()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Last();
    return 0;
}

struct View_009d5d73_shapec01_gzcom {
    uint8_t mPad4[4];
    uint32_t mnRefs;
    // STUB: 0x9d5d10
    void Last();
    uint32_t Fn009d5d73();
};

// FUNCTION: 0x009d5d73
uint32_t View_009d5d73_shapec01_gzcom::Fn009d5d73()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Last();
    return 0;
}

struct Holder_009dbc2d_shapec01_gzcom {
    uint32_t* mpData;
    uint32_t* Get() const { return mpData; }
};

// STUB: 0x9dbb42
Holder_009dbc2d_shapec01_gzcom* Make009dbc2d();

struct View_009dbc2d_shapec01_gzcom {
    Holder_009dbc2d_shapec01_gzcom* mpHolder;
    View_009dbc2d_shapec01_gzcom* Fn009dbc2d();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009dbc2d score 3
View_009dbc2d_shapec01_gzcom* View_009dbc2d_shapec01_gzcom::Fn009dbc2d()
{
    uint32_t* p = mpHolder->Get();
    if (!p) {
        mpHolder = Make009dbc2d();
    }
    return this;
}
#endif

struct Holder_008ff7e7_shapec01_gzcom {
    uint32_t* mpData;
    uint32_t* Get() const { return mpData; }
};

// STUB: 0x8ff123
Holder_008ff7e7_shapec01_gzcom* Make008ff7e7();

struct View_008ff7e7_shapec01_gzcom {
    Holder_008ff7e7_shapec01_gzcom* mpHolder;
    View_008ff7e7_shapec01_gzcom* Fn008ff7e7();
};

#ifdef OB_DRAFTS
// CLOSE: 0x008ff7e7 score 3
View_008ff7e7_shapec01_gzcom* View_008ff7e7_shapec01_gzcom::Fn008ff7e7()
{
    uint32_t* p = mpHolder->Get();
    if (!p) {
        mpHolder = Make008ff7e7();
    }
    return this;
}
#endif

struct Holder_008fc653_shapec01_gzcom {
    uint32_t* mpData;
    uint32_t* Get() const { return mpData; }
};

// STUB: 0x8fc5e4
Holder_008fc653_shapec01_gzcom* Make008fc653();

struct View_008fc653_shapec01_gzcom {
    Holder_008fc653_shapec01_gzcom* mpHolder;
    View_008fc653_shapec01_gzcom* Fn008fc653();
};

#ifdef OB_DRAFTS
// CLOSE: 0x008fc653 score 3
View_008fc653_shapec01_gzcom* View_008fc653_shapec01_gzcom::Fn008fc653()
{
    uint32_t* p = mpHolder->Get();
    if (!p) {
        mpHolder = Make008fc653();
    }
    return this;
}
#endif

struct Holder_00969127_shapec01_gzcom {
    uint32_t* mpData;
    uint32_t* Get() const { return mpData; }
};

// STUB: 0x879a0f
Holder_00969127_shapec01_gzcom* Make00969127();

struct View_00969127_shapec01_gzcom {
    Holder_00969127_shapec01_gzcom* mpHolder;
    View_00969127_shapec01_gzcom* Fn00969127();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00969127 score 3
View_00969127_shapec01_gzcom* View_00969127_shapec01_gzcom::Fn00969127()
{
    uint32_t* p = mpHolder->Get();
    if (!p) {
        mpHolder = Make00969127();
    }
    return this;
}
#endif

struct View_00892a51_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn00892a51();
};

// FUNCTION: 0x00892a51
uint32_t View_00892a51_shapec01_gzcom::Fn00892a51()
{
    if (mnRefs == 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_0096a465_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn0096a465();
};

// FUNCTION: 0x0096a465
uint32_t View_0096a465_shapec01_gzcom::Fn0096a465()
{
    if (mnRefs == 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_009385f3_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn009385f3();
};

// FUNCTION: 0x009385f3
uint32_t View_009385f3_shapec01_gzcom::Fn009385f3()
{
    if (mnRefs == 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_00935e89_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint8_t mPad4[4];
    uint32_t mnRefs;
    uint32_t Fn00935e89();
};

// FUNCTION: 0x00935e89
uint32_t View_00935e89_shapec01_gzcom::Fn00935e89()
{
    if (mnRefs == 1) {
        Destroy(1);
        return 0;
    }
    return --mnRefs;
}

struct View_00975402_shapec01_gzcom {
    uint8_t mPadc[12];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    bool Fn00975402(const uint32_t* p);
};

// FUNCTION: 0x00975402
bool View_00975402_shapec01_gzcom::Fn00975402(const uint32_t* p)
{
    mnA = p[0];
    mnB = p[1];
    mnC = p[2];
    return true;
}

struct View_0096c024_shapec01_gzcom {
    uint8_t mPad8[8];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    bool Fn0096c024(const uint32_t* p);
};

// FUNCTION: 0x0096c024
bool View_0096c024_shapec01_gzcom::Fn0096c024(const uint32_t* p)
{
    mnA = p[0];
    mnB = p[1];
    mnC = p[2];
    return true;
}

struct View_0096c43c_shapec01_gzcom {
    uint8_t mPad24[36];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    bool Fn0096c43c(const uint32_t* p);
};

// FUNCTION: 0x0096c43c
bool View_0096c43c_shapec01_gzcom::Fn0096c43c(const uint32_t* p)
{
    mnA = p[0];
    mnB = p[1];
    mnC = p[2];
    return true;
}

struct View_009377af_shapec01_gzcom {
    uint8_t mPad4[4];
    uint32_t mnA;
    uint32_t mnB;
    uint32_t mnC;
    bool Fn009377af(const uint32_t* p);
};

// FUNCTION: 0x009377af
bool View_009377af_shapec01_gzcom::Fn009377af(const uint32_t* p)
{
    mnA = p[0];
    mnB = p[1];
    mnC = p[2];
    return true;
}

struct Sub_00894762_shapec01_gzcom {
    // STUB: 0x51fe90
    void Init(uint32_t value);
};

struct View_00894762_shapec01_gzcom {
    // STUB: 0x408be0
    void Construct(const void* source, uint32_t position, uint32_t count);
    uint8_t mPad[20];
    Sub_00894762_shapec01_gzcom mSub;
    View_00894762_shapec01_gzcom* Fn00894762(const void* source, uint32_t value);
};

// FUNCTION: 0x00894762
View_00894762_shapec01_gzcom* View_00894762_shapec01_gzcom::Fn00894762(const void* source, uint32_t value)
{
    Construct(source, 0, 0xffffffff);
    mSub.Init(value);
    return this;
}

struct Sub_008ffd2d_shapec01_gzcom {
    // STUB: 0x8fef6a
    void Init(uint32_t value);
};

struct View_008ffd2d_shapec01_gzcom {
    // STUB: 0x408be0
    void Construct(const void* source, uint32_t position, uint32_t count);
    uint8_t mPad[20];
    Sub_008ffd2d_shapec01_gzcom mSub;
    View_008ffd2d_shapec01_gzcom* Fn008ffd2d(const void* source, uint32_t value);
};

// FUNCTION: 0x008ffd2d
View_008ffd2d_shapec01_gzcom* View_008ffd2d_shapec01_gzcom::Fn008ffd2d(const void* source, uint32_t value)
{
    Construct(source, 0, 0xffffffff);
    mSub.Init(value);
    return this;
}

struct Sub_00921d27_shapec01_gzcom {
    // STUB: 0x91c9ec
    void Init(uint32_t value);
};

struct View_00921d27_shapec01_gzcom {
    // STUB: 0x408be0
    void Construct(const void* source, uint32_t position, uint32_t count);
    uint8_t mPad[20];
    Sub_00921d27_shapec01_gzcom mSub;
    View_00921d27_shapec01_gzcom* Fn00921d27(const void* source, uint32_t value);
};

// FUNCTION: 0x00921d27
View_00921d27_shapec01_gzcom* View_00921d27_shapec01_gzcom::Fn00921d27(const void* source, uint32_t value)
{
    Construct(source, 0, 0xffffffff);
    mSub.Init(value);
    return this;
}

struct Sub_008fcb5d_shapec01_gzcom {
    // STUB: 0x8fc92d
    void Init(uint32_t value);
};

struct View_008fcb5d_shapec01_gzcom {
    // STUB: 0x408be0
    void Construct(const void* source, uint32_t position, uint32_t count);
    uint8_t mPad[20];
    Sub_008fcb5d_shapec01_gzcom mSub;
    View_008fcb5d_shapec01_gzcom* Fn008fcb5d(const void* source, uint32_t value);
};

// FUNCTION: 0x008fcb5d
View_008fcb5d_shapec01_gzcom* View_008fcb5d_shapec01_gzcom::Fn008fcb5d(const void* source, uint32_t value)
{
    Construct(source, 0, 0xffffffff);
    mSub.Init(value);
    return this;
}

struct Result_0087c05e_shapec01_gzcom {
    uint32_t* mpNode;
    bool mbInserted;
    Result_0087c05e_shapec01_gzcom(uint32_t* node, bool inserted) : mpNode(node), mbInserted(inserted) {}
};

struct View_0087c05e_shapec01_gzcom {
    // STUB: 0x87bfd4
    Result_0087c05e_shapec01_gzcom Insert(const uint32_t* pKey);
    Result_0087c05e_shapec01_gzcom Fn0087c05e(const uint32_t* pKey);
};

// FUNCTION: 0x0087c05e
Result_0087c05e_shapec01_gzcom View_0087c05e_shapec01_gzcom::Fn0087c05e(const uint32_t* pKey)
{
    Result_0087c05e_shapec01_gzcom r = Insert(pKey);
    return Result_0087c05e_shapec01_gzcom(r.mpNode, r.mbInserted);
}

struct Result_00934bd4_shapec01_gzcom {
    uint32_t* mpNode;
    bool mbInserted;
    Result_00934bd4_shapec01_gzcom(uint32_t* node, bool inserted) : mpNode(node), mbInserted(inserted) {}
};

struct View_00934bd4_shapec01_gzcom {
    // STUB: 0x93494a
    Result_00934bd4_shapec01_gzcom Insert(const uint32_t* pKey);
    Result_00934bd4_shapec01_gzcom Fn00934bd4(const uint32_t* pKey);
};

// FUNCTION: 0x00934bd4
Result_00934bd4_shapec01_gzcom View_00934bd4_shapec01_gzcom::Fn00934bd4(const uint32_t* pKey)
{
    Result_00934bd4_shapec01_gzcom r = Insert(pKey);
    return Result_00934bd4_shapec01_gzcom(r.mpNode, r.mbInserted);
}

struct Result_008fef47_shapec01_gzcom {
    uint32_t* mpNode;
    bool mbInserted;
    Result_008fef47_shapec01_gzcom(uint32_t* node, bool inserted) : mpNode(node), mbInserted(inserted) {}
};

struct View_008fef47_shapec01_gzcom {
    // STUB: 0x8fec39
    Result_008fef47_shapec01_gzcom Insert(const uint32_t* pKey);
    Result_008fef47_shapec01_gzcom Fn008fef47(const uint32_t* pKey);
};

// FUNCTION: 0x008fef47
Result_008fef47_shapec01_gzcom View_008fef47_shapec01_gzcom::Fn008fef47(const uint32_t* pKey)
{
    Result_008fef47_shapec01_gzcom r = Insert(pKey);
    return Result_008fef47_shapec01_gzcom(r.mpNode, r.mbInserted);
}

struct Result_008775fd_shapec01_gzcom {
    uint32_t* mpNode;
    bool mbInserted;
    Result_008775fd_shapec01_gzcom(uint32_t* node, bool inserted) : mpNode(node), mbInserted(inserted) {}
};

struct View_008775fd_shapec01_gzcom {
    // STUB: 0x87707e
    Result_008775fd_shapec01_gzcom Insert(const uint32_t* pKey);
    Result_008775fd_shapec01_gzcom Fn008775fd(const uint32_t* pKey);
};

// FUNCTION: 0x008775fd
Result_008775fd_shapec01_gzcom View_008775fd_shapec01_gzcom::Fn008775fd(const uint32_t* pKey)
{
    Result_008775fd_shapec01_gzcom r = Insert(pKey);
    return Result_008775fd_shapec01_gzcom(r.mpNode, r.mbInserted);
}

struct Base_00993872_shapec01_gzcom {
    // STUB: 0x998f83
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_00993872_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    Base_00993872_shapec01_gzcom mBase;
    bool Fn00993872(uint32_t iid, void** ppv);
};

// FUNCTION: 0x00993872
bool View_00993872_shapec01_gzcom::Fn00993872(uint32_t iid, void** ppv)
{
    if (iid == 0x2ac44a93) {
        *ppv = this;
        AddRef();
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

struct Base_0092d033_shapec01_gzcom {
    // STUB: 0x91dd67
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_0092d033_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    Base_0092d033_shapec01_gzcom mBase;
    bool Fn0092d033(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0092d033
bool View_0092d033_shapec01_gzcom::Fn0092d033(uint32_t iid, void** ppv)
{
    if (iid == 0x652294bc) {
        *ppv = this;
        AddRef();
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

struct Base_0091dd67_shapec01_gzcom {
    // STUB: 0x9457c6
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_0091dd67_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    Base_0091dd67_shapec01_gzcom mBase;
    bool Fn0091dd67(uint32_t iid, void** ppv);
};

// FUNCTION: 0x0091dd67
bool View_0091dd67_shapec01_gzcom::Fn0091dd67(uint32_t iid, void** ppv)
{
    if (iid == 0x287fb697) {
        *ppv = this;
        AddRef();
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

struct Base_009cb247_shapec01_gzcom {
    // STUB: 0x99b774
    bool QueryInterface(uint32_t iid, void** ppv);
};

struct View_009cb247_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    Base_009cb247_shapec01_gzcom mBase;
    bool Fn009cb247(uint32_t iid, void** ppv);
};

// FUNCTION: 0x009cb247
bool View_009cb247_shapec01_gzcom::Fn009cb247(uint32_t iid, void** ppv)
{
    if (iid == 0xe303e5ae) {
        *ppv = this;
        AddRef();
        return true;
    }
    return mBase.QueryInterface(iid, ppv);
}

struct View_00901149_shapec01_gzcom {
    uint8_t mPad10[16];
    uint32_t mnSize;
    // STUB: 0x8ff066
    void Reserve(uint32_t count);
    // STUB: 0x900f4c
    void Insert(uint32_t a, uint32_t b);
    uint32_t Fn00901149(uint32_t a, uint32_t b);
};

// FUNCTION: 0x00901149
uint32_t View_00901149_shapec01_gzcom::Fn00901149(uint32_t a, uint32_t b)
{
    Reserve(mnSize + 1);
    Insert(a, b);
    return a;
}

struct View_0090116d_shapec01_gzcom {
    uint8_t mPad10[16];
    uint32_t mnSize;
    // STUB: 0x8ff066
    void Reserve(uint32_t count);
    // STUB: 0x900fcc
    void Insert(uint32_t a, uint32_t b);
    uint32_t Fn0090116d(uint32_t a, uint32_t b);
};

// FUNCTION: 0x0090116d
uint32_t View_0090116d_shapec01_gzcom::Fn0090116d(uint32_t a, uint32_t b)
{
    Reserve(mnSize + 1);
    Insert(a, b);
    return a;
}

struct View_008fd705_shapec01_gzcom {
    uint8_t mPad10[16];
    uint32_t mnSize;
    // STUB: 0x8fc4f6
    void Reserve(uint32_t count);
    // STUB: 0x8fd309
    void Insert(uint32_t a, uint32_t b);
    uint32_t Fn008fd705(uint32_t a, uint32_t b);
};

// FUNCTION: 0x008fd705
uint32_t View_008fd705_shapec01_gzcom::Fn008fd705(uint32_t a, uint32_t b)
{
    Reserve(mnSize + 1);
    Insert(a, b);
    return a;
}

struct View_009dc4e6_shapec01_gzcom {
    uint8_t mPad10[16];
    uint32_t mnSize;
    // STUB: 0x9dc0c5
    void Reserve(uint32_t count);
    // STUB: 0x9dbc68
    void Insert(uint32_t a, uint32_t b);
    uint32_t Fn009dc4e6(uint32_t a, uint32_t b);
};

// FUNCTION: 0x009dc4e6
uint32_t View_009dc4e6_shapec01_gzcom::Fn009dc4e6(uint32_t a, uint32_t b)
{
    Reserve(mnSize + 1);
    Insert(a, b);
    return a;
}

struct View_008946f6_shapec01_gzcom;

struct Sub_008946f6_shapec01_gzcom {
    // STUB: 0x8945aa
    void Init(const Sub_008946f6_shapec01_gzcom* source);
};

struct View_008946f6_shapec01_gzcom {
    // STUB: 0x408be0
    void Construct(const View_008946f6_shapec01_gzcom* source, uint32_t position, uint32_t count);
    uint8_t mPad[20];
    Sub_008946f6_shapec01_gzcom mSub;
    View_008946f6_shapec01_gzcom* Fn008946f6(const View_008946f6_shapec01_gzcom* source);
};

// FUNCTION: 0x008946f6
View_008946f6_shapec01_gzcom* View_008946f6_shapec01_gzcom::Fn008946f6(const View_008946f6_shapec01_gzcom* source)
{
    Construct(source, 0, 0xffffffff);
    mSub.Init(&source->mSub);
    return this;
}

struct View_0089471b_shapec01_gzcom;

struct Sub_0089471b_shapec01_gzcom {
    // STUB: 0x51fe90
    void Init(const Sub_0089471b_shapec01_gzcom* source);
};

struct View_0089471b_shapec01_gzcom {
    // STUB: 0x408be0
    void Construct(const View_0089471b_shapec01_gzcom* source, uint32_t position, uint32_t count);
    uint8_t mPad[20];
    Sub_0089471b_shapec01_gzcom mSub;
    View_0089471b_shapec01_gzcom* Fn0089471b(const View_0089471b_shapec01_gzcom* source);
};

// FUNCTION: 0x0089471b
View_0089471b_shapec01_gzcom* View_0089471b_shapec01_gzcom::Fn0089471b(const View_0089471b_shapec01_gzcom* source)
{
    Construct(source, 0, 0xffffffff);
    mSub.Init(&source->mSub);
    return this;
}

struct View_008ffe6a_shapec01_gzcom;

struct Sub_008ffe6a_shapec01_gzcom {
    // STUB: 0x8fef6a
    void Init(const Sub_008ffe6a_shapec01_gzcom* source);
};

struct View_008ffe6a_shapec01_gzcom {
    // STUB: 0x408be0
    void Construct(const View_008ffe6a_shapec01_gzcom* source, uint32_t position, uint32_t count);
    uint8_t mPad[20];
    Sub_008ffe6a_shapec01_gzcom mSub;
    View_008ffe6a_shapec01_gzcom* Fn008ffe6a(const View_008ffe6a_shapec01_gzcom* source);
};

// FUNCTION: 0x008ffe6a
View_008ffe6a_shapec01_gzcom* View_008ffe6a_shapec01_gzcom::Fn008ffe6a(const View_008ffe6a_shapec01_gzcom* source)
{
    Construct(source, 0, 0xffffffff);
    mSub.Init(&source->mSub);
    return this;
}

struct View_00921d49_shapec01_gzcom;

struct Sub_00921d49_shapec01_gzcom {
    // STUB: 0x91c9ec
    void Init(const Sub_00921d49_shapec01_gzcom* source);
};

struct View_00921d49_shapec01_gzcom {
    // STUB: 0x408be0
    void Construct(const View_00921d49_shapec01_gzcom* source, uint32_t position, uint32_t count);
    uint8_t mPad[20];
    Sub_00921d49_shapec01_gzcom mSub;
    View_00921d49_shapec01_gzcom* Fn00921d49(const View_00921d49_shapec01_gzcom* source);
};

// FUNCTION: 0x00921d49
View_00921d49_shapec01_gzcom* View_00921d49_shapec01_gzcom::Fn00921d49(const View_00921d49_shapec01_gzcom* source)
{
    Construct(source, 0, 0xffffffff);
    mSub.Init(&source->mSub);
    return this;
}

struct Str_00900519_shapec01_gzcom {
    // STUB: 0x578390
    Str_00900519_shapec01_gzcom();
    // STUB: 0x424380
    Str_00900519_shapec01_gzcom* Assign(const Str_00900519_shapec01_gzcom* other);
    uint8_t mPad[20];
};

struct View_00900519_shapec01_gzcom {
    uint8_t mPad28[40];
    Str_00900519_shapec01_gzcom* mpStr;
    Str_00900519_shapec01_gzcom* Fn00900519(const Str_00900519_shapec01_gzcom* other);
};

// FUNCTION: 0x00900519
Str_00900519_shapec01_gzcom* View_00900519_shapec01_gzcom::Fn00900519(const Str_00900519_shapec01_gzcom* other)
{
    mpStr = new Str_00900519_shapec01_gzcom();
    return mpStr->Assign(other);
}

struct Str_0090053e_shapec01_gzcom {
    // STUB: 0x578390
    Str_0090053e_shapec01_gzcom();
    // STUB: 0x424380
    Str_0090053e_shapec01_gzcom* Assign(const Str_0090053e_shapec01_gzcom* other);
    uint8_t mPad[20];
};

struct View_0090053e_shapec01_gzcom {
    uint8_t mPad1c[28];
    Str_0090053e_shapec01_gzcom* mpStr;
    Str_0090053e_shapec01_gzcom* Fn0090053e(const Str_0090053e_shapec01_gzcom* other);
};

// FUNCTION: 0x0090053e
Str_0090053e_shapec01_gzcom* View_0090053e_shapec01_gzcom::Fn0090053e(const Str_0090053e_shapec01_gzcom* other)
{
    mpStr = new Str_0090053e_shapec01_gzcom();
    return mpStr->Assign(other);
}

struct Str_00900563_shapec01_gzcom {
    // STUB: 0x578390
    Str_00900563_shapec01_gzcom();
    // STUB: 0x424380
    Str_00900563_shapec01_gzcom* Assign(const Str_00900563_shapec01_gzcom* other);
    uint8_t mPad[20];
};

struct View_00900563_shapec01_gzcom {
    uint8_t mPad20[32];
    Str_00900563_shapec01_gzcom* mpStr;
    Str_00900563_shapec01_gzcom* Fn00900563(const Str_00900563_shapec01_gzcom* other);
};

// FUNCTION: 0x00900563
Str_00900563_shapec01_gzcom* View_00900563_shapec01_gzcom::Fn00900563(const Str_00900563_shapec01_gzcom* other)
{
    mpStr = new Str_00900563_shapec01_gzcom();
    return mpStr->Assign(other);
}

struct Str_00900588_shapec01_gzcom {
    // STUB: 0x578390
    Str_00900588_shapec01_gzcom();
    // STUB: 0x424380
    Str_00900588_shapec01_gzcom* Assign(const Str_00900588_shapec01_gzcom* other);
    uint8_t mPad[20];
};

struct View_00900588_shapec01_gzcom {
    uint8_t mPad24[36];
    Str_00900588_shapec01_gzcom* mpStr;
    Str_00900588_shapec01_gzcom* Fn00900588(const Str_00900588_shapec01_gzcom* other);
};

// FUNCTION: 0x00900588
Str_00900588_shapec01_gzcom* View_00900588_shapec01_gzcom::Fn00900588(const Str_00900588_shapec01_gzcom* other)
{
    mpStr = new Str_00900588_shapec01_gzcom();
    return mpStr->Assign(other);
}

struct View_00974d3d_shapec01_gzcom {
    uint8_t mPad[28];
    int32_t mnEnd;
    int32_t mnBegin;
    uint32_t mnCap;
    // STUB: 0x974aeb
    void Grow(uint32_t count, uint32_t flag);
    void Fn00974d3d(uint32_t count);
};

// FUNCTION: 0x00974d3d
void View_00974d3d_shapec01_gzcom::Fn00974d3d(uint32_t count)
{
    int32_t used = (mnEnd - mnBegin) >> 2;
    uint32_t room = mnCap - used;
    if (count + 1 > room) {
        Grow(count, 0);
    }
}

struct View_00982d6f_shapec01_gzcom {
    uint8_t mPad[28];
    int32_t mnEnd;
    int32_t mnBegin;
    uint32_t mnCap;
    // STUB: 0x982c25
    void Grow(uint32_t count, uint32_t flag);
    void Fn00982d6f(uint32_t count);
};

// FUNCTION: 0x00982d6f
void View_00982d6f_shapec01_gzcom::Fn00982d6f(uint32_t count)
{
    int32_t used = (mnEnd - mnBegin) >> 2;
    uint32_t room = mnCap - used;
    if (count + 1 > room) {
        Grow(count, 0);
    }
}

struct View_00982d95_shapec01_gzcom {
    uint8_t mPad[28];
    int32_t mnEnd;
    int32_t mnBegin;
    uint32_t mnCap;
    // STUB: 0x973c0e
    void Grow(uint32_t count, uint32_t flag);
    void Fn00982d95(uint32_t count);
};

// FUNCTION: 0x00982d95
void View_00982d95_shapec01_gzcom::Fn00982d95(uint32_t count)
{
    int32_t used = (mnEnd - mnBegin) >> 2;
    uint32_t room = mnCap - used;
    if (count + 1 > room) {
        Grow(count, 0);
    }
}

struct View_0092fb6a_shapec01_gzcom {
    uint8_t mPad[28];
    int32_t mnEnd;
    int32_t mnBegin;
    uint32_t mnCap;
    // STUB: 0x92f62a
    void Grow(uint32_t count, uint32_t flag);
    void Fn0092fb6a(uint32_t count);
};

// FUNCTION: 0x0092fb6a
void View_0092fb6a_shapec01_gzcom::Fn0092fb6a(uint32_t count)
{
    int32_t used = (mnEnd - mnBegin) >> 2;
    uint32_t room = mnCap - used;
    if (count + 1 > room) {
        Grow(count, 0);
    }
}

struct Obj_00893d91_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_00893d91_shapec01_gzcom {
    uint8_t mPad24[36];
    Obj_00893d91_shapec01_gzcom* mpObj;
    void Fn00893d91(Obj_00893d91_shapec01_gzcom* p);
};

// FUNCTION: 0x00893d91
void View_00893d91_shapec01_gzcom::Fn00893d91(Obj_00893d91_shapec01_gzcom* p)
{
    if (p) {
        p->AddRef();
    }
    if (mpObj) {
        mpObj->Release();
    }
    mpObj = p;
}

struct Obj_009b28a2_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_009b28a2_shapec01_gzcom {
    uint8_t mPad8[8];
    Obj_009b28a2_shapec01_gzcom* mpObj;
    void Fn009b28a2(Obj_009b28a2_shapec01_gzcom* p);
};

// FUNCTION: 0x009b28a2
void View_009b28a2_shapec01_gzcom::Fn009b28a2(Obj_009b28a2_shapec01_gzcom* p)
{
    if (p) {
        p->AddRef();
    }
    if (mpObj) {
        mpObj->Release();
    }
    mpObj = p;
}

struct Obj_008f69e5_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_008f69e5_shapec01_gzcom {
    uint8_t mPad34[52];
    Obj_008f69e5_shapec01_gzcom* mpObj;
    void Fn008f69e5(Obj_008f69e5_shapec01_gzcom* p);
};

// FUNCTION: 0x008f69e5
void View_008f69e5_shapec01_gzcom::Fn008f69e5(Obj_008f69e5_shapec01_gzcom* p)
{
    if (p) {
        p->AddRef();
    }
    if (mpObj) {
        mpObj->Release();
    }
    mpObj = p;
}

struct Obj_009779df_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_009779df_shapec01_gzcom {
    uint8_t mPad4[4];
    Obj_009779df_shapec01_gzcom* mpObj;
    void Fn009779df(Obj_009779df_shapec01_gzcom* p);
};

// FUNCTION: 0x009779df
void View_009779df_shapec01_gzcom::Fn009779df(Obj_009779df_shapec01_gzcom* p)
{
    if (p) {
        p->AddRef();
    }
    if (mpObj) {
        mpObj->Release();
    }
    mpObj = p;
}

struct Obj_0094b0c7_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_0094b0c7_shapec01_gzcom {
    uint8_t mPad5c[92];
    Obj_0094b0c7_shapec01_gzcom* mpObj;
    void Fn0094b0c7(Obj_0094b0c7_shapec01_gzcom* p);
};

// FUNCTION: 0x0094b0c7
void View_0094b0c7_shapec01_gzcom::Fn0094b0c7(Obj_0094b0c7_shapec01_gzcom* p)
{
    if (p != mpObj) {
        if (p) {
            p->AddRef();
        }
        if (mpObj) {
            mpObj->Release();
        }
        mpObj = p;
    }
}

struct Obj_00891e44_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_00891e44_shapec01_gzcom {
    uint8_t mPad40[64];
    Obj_00891e44_shapec01_gzcom* mpObj;
    void Fn00891e44(Obj_00891e44_shapec01_gzcom* p);
};

// FUNCTION: 0x00891e44
void View_00891e44_shapec01_gzcom::Fn00891e44(Obj_00891e44_shapec01_gzcom* p)
{
    if (p != mpObj) {
        if (p) {
            p->AddRef();
        }
        if (mpObj) {
            mpObj->Release();
        }
        mpObj = p;
    }
}

struct Obj_0094c375_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_0094c375_shapec01_gzcom {
    uint8_t mPad10[16];
    Obj_0094c375_shapec01_gzcom* mpObj;
    void Fn0094c375(Obj_0094c375_shapec01_gzcom* p);
};

// FUNCTION: 0x0094c375
void View_0094c375_shapec01_gzcom::Fn0094c375(Obj_0094c375_shapec01_gzcom* p)
{
    if (p != mpObj) {
        if (p) {
            p->AddRef();
        }
        if (mpObj) {
            mpObj->Release();
        }
        mpObj = p;
    }
}

struct Obj_0094c3a1_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct View_0094c3a1_shapec01_gzcom {
    uint8_t mPad8[8];
    Obj_0094c3a1_shapec01_gzcom* mpObj;
    void Fn0094c3a1(Obj_0094c3a1_shapec01_gzcom* p);
};

// FUNCTION: 0x0094c3a1
void View_0094c3a1_shapec01_gzcom::Fn0094c3a1(Obj_0094c3a1_shapec01_gzcom* p)
{
    if (p != mpObj) {
        if (p) {
            p->AddRef();
        }
        if (mpObj) {
            mpObj->Release();
        }
        mpObj = p;
    }
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Val_009540c8_shapec01_gzcom {
    // STUB: 0x94d163
    void Dtor();
};

struct Node_009540c8_shapec01_gzcom {
    Node_009540c8_shapec01_gzcom* mpNext;
    Node_009540c8_shapec01_gzcom* mpPrev;
    Val_009540c8_shapec01_gzcom mValue;
};

struct View_009540c8_shapec01_gzcom {
    Node_009540c8_shapec01_gzcom* mpHead;
    void Fn009540c8();
};

// FUNCTION: 0x009540c8
void View_009540c8_shapec01_gzcom::Fn009540c8()
{
    Node_009540c8_shapec01_gzcom* head = mpHead;
    Node_009540c8_shapec01_gzcom* cur = head->mpNext;
    if (cur != head) {
        do {
            Node_009540c8_shapec01_gzcom* node = cur;
            cur = cur->mpNext;
            node->mValue.Dtor();
            _STL::__stl_delete(node);
        } while (cur != mpHead);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Val_008f747b_shapec01_gzcom {
    // STUB: 0x8f729b
    void Dtor();
};

struct Node_008f747b_shapec01_gzcom {
    Node_008f747b_shapec01_gzcom* mpNext;
    Node_008f747b_shapec01_gzcom* mpPrev;
    Val_008f747b_shapec01_gzcom mValue;
};

struct View_008f747b_shapec01_gzcom {
    Node_008f747b_shapec01_gzcom* mpHead;
    void Fn008f747b();
};

// FUNCTION: 0x008f747b
void View_008f747b_shapec01_gzcom::Fn008f747b()
{
    Node_008f747b_shapec01_gzcom* head = mpHead;
    Node_008f747b_shapec01_gzcom* cur = head->mpNext;
    if (cur != head) {
        do {
            Node_008f747b_shapec01_gzcom* node = cur;
            cur = cur->mpNext;
            node->mValue.Dtor();
            _STL::__stl_delete(node);
        } while (cur != mpHead);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Val_009d769d_shapec01_gzcom {
    // STUB: 0x414250
    void Dtor();
};

struct Node_009d769d_shapec01_gzcom {
    Node_009d769d_shapec01_gzcom* mpNext;
    Node_009d769d_shapec01_gzcom* mpPrev;
    Val_009d769d_shapec01_gzcom mValue;
};

struct View_009d769d_shapec01_gzcom {
    Node_009d769d_shapec01_gzcom* mpHead;
    void Fn009d769d();
};

// FUNCTION: 0x009d769d
void View_009d769d_shapec01_gzcom::Fn009d769d()
{
    Node_009d769d_shapec01_gzcom* head = mpHead;
    Node_009d769d_shapec01_gzcom* cur = head->mpNext;
    if (cur != head) {
        do {
            Node_009d769d_shapec01_gzcom* node = cur;
            cur = cur->mpNext;
            node->mValue.Dtor();
            _STL::__stl_delete(node);
        } while (cur != mpHead);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

namespace _STL {
    // STUB: 0x0090cf63
    void __stl_delete(void* block);
}

struct Val_009341d6_shapec01_gzcom {
    // STUB: 0x91adec
    void Dtor();
};

struct Node_009341d6_shapec01_gzcom {
    Node_009341d6_shapec01_gzcom* mpNext;
    Node_009341d6_shapec01_gzcom* mpPrev;
    Val_009341d6_shapec01_gzcom mValue;
};

struct View_009341d6_shapec01_gzcom {
    Node_009341d6_shapec01_gzcom* mpHead;
    void Fn009341d6();
};

// FUNCTION: 0x009341d6
void View_009341d6_shapec01_gzcom::Fn009341d6()
{
    Node_009341d6_shapec01_gzcom* head = mpHead;
    Node_009341d6_shapec01_gzcom* cur = head->mpNext;
    if (cur != head) {
        do {
            Node_009341d6_shapec01_gzcom* node = cur;
            cur = cur->mpNext;
            node->mValue.Dtor();
            _STL::__stl_delete(node);
        } while (cur != mpHead);
    }
    mpHead->mpNext = mpHead;
    mpHead->mpPrev = mpHead;
}

struct View_00974a47_shapec01_gzcom {
    uint32_t mn[10];
    // STUB: 0x974759
    void Init(uint32_t value);
    View_00974a47_shapec01_gzcom* Fn00974a47(uint32_t /*a*/, uint32_t b);
};

// FUNCTION: 0x00974a47
View_00974a47_shapec01_gzcom* View_00974a47_shapec01_gzcom::Fn00974a47(uint32_t /*a*/, uint32_t b)
{
    mn[0] = 0;
    mn[1] = 0;
    mn[2] = 0;
    mn[3] = 0;
    mn[4] = 0;
    mn[5] = 0;
    mn[6] = 0;
    mn[7] = 0;
    mn[8] = 0;
    mn[9] = 0;
    Init(b);
    return this;
}

struct View_00982bf4_shapec01_gzcom {
    uint32_t mn[10];
    // STUB: 0x982a8e
    void Init(uint32_t value);
    View_00982bf4_shapec01_gzcom* Fn00982bf4(uint32_t /*a*/, uint32_t b);
};

// FUNCTION: 0x00982bf4
View_00982bf4_shapec01_gzcom* View_00982bf4_shapec01_gzcom::Fn00982bf4(uint32_t /*a*/, uint32_t b)
{
    mn[0] = 0;
    mn[1] = 0;
    mn[2] = 0;
    mn[3] = 0;
    mn[4] = 0;
    mn[5] = 0;
    mn[6] = 0;
    mn[7] = 0;
    mn[8] = 0;
    mn[9] = 0;
    Init(b);
    return this;
}

struct View_0092d9db_shapec01_gzcom {
    uint32_t mn[10];
    // STUB: 0x92d52a
    void Init(uint32_t value);
    View_0092d9db_shapec01_gzcom* Fn0092d9db(uint32_t /*a*/, uint32_t b);
};

// FUNCTION: 0x0092d9db
View_0092d9db_shapec01_gzcom* View_0092d9db_shapec01_gzcom::Fn0092d9db(uint32_t /*a*/, uint32_t b)
{
    mn[0] = 0;
    mn[1] = 0;
    mn[2] = 0;
    mn[3] = 0;
    mn[4] = 0;
    mn[5] = 0;
    mn[6] = 0;
    mn[7] = 0;
    mn[8] = 0;
    mn[9] = 0;
    Init(b);
    return this;
}

struct View_0092f54a_shapec01_gzcom {
    uint32_t mn[10];
    // STUB: 0x92f0ed
    void Init(uint32_t value);
    View_0092f54a_shapec01_gzcom* Fn0092f54a(uint32_t /*a*/, uint32_t b);
};

// FUNCTION: 0x0092f54a
View_0092f54a_shapec01_gzcom* View_0092f54a_shapec01_gzcom::Fn0092f54a(uint32_t /*a*/, uint32_t b)
{
    mn[0] = 0;
    mn[1] = 0;
    mn[2] = 0;
    mn[3] = 0;
    mn[4] = 0;
    mn[5] = 0;
    mn[6] = 0;
    mn[7] = 0;
    mn[8] = 0;
    mn[9] = 0;
    Init(b);
    return this;
}

struct View_00892076_shapec01_gzcom {
    uint32_t mn[10];
    // STUB: 0x891f37
    void Init(uint32_t value);
    View_00892076_shapec01_gzcom* Fn00892076(uint32_t /*a*/, uint32_t b);
};

// FUNCTION: 0x00892076
View_00892076_shapec01_gzcom* View_00892076_shapec01_gzcom::Fn00892076(uint32_t /*a*/, uint32_t b)
{
    mn[0] = 0;
    mn[1] = 0;
    mn[2] = 0;
    mn[3] = 0;
    mn[4] = 0;
    mn[5] = 0;
    mn[6] = 0;
    mn[7] = 0;
    mn[8] = 0;
    mn[9] = 0;
    Init(b);
    return this;
}

struct Node_0094481e_shapec01_gzcom {
    uint32_t mColor;
    Node_0094481e_shapec01_gzcom* mpParent;
    Node_0094481e_shapec01_gzcom* mpLeft;
    Node_0094481e_shapec01_gzcom* mpRight;
    uint32_t mKey;
};

struct Less_0094481e_shapec01_gzcom {
    // STUB: 0x9446c1
    bool Compare(const uint32_t* lhs, const uint32_t* rhs);
};

struct View_0094481e_shapec01_gzcom {
    Node_0094481e_shapec01_gzcom* mpHeader;
    uint32_t mnSize;
    Less_0094481e_shapec01_gzcom mLess;
    Node_0094481e_shapec01_gzcom* Fn0094481e(const uint32_t* key);
};

// FUNCTION: 0x0094481e
Node_0094481e_shapec01_gzcom* View_0094481e_shapec01_gzcom::Fn0094481e(const uint32_t* key)
{
    Node_0094481e_shapec01_gzcom* y = mpHeader;
    Node_0094481e_shapec01_gzcom* x = y->mpParent;
    while (x) {
        if (!mLess.Compare(&x->mKey, key)) {
            y = x;
            x = x->mpLeft;
        } else {
            x = x->mpRight;
        }
    }
    if (y == mpHeader || mLess.Compare(key, &y->mKey)) {
        y = mpHeader;
    }
    return y;
}

struct Node_0094ca22_shapec01_gzcom {
    uint32_t mColor;
    Node_0094ca22_shapec01_gzcom* mpParent;
    Node_0094ca22_shapec01_gzcom* mpLeft;
    Node_0094ca22_shapec01_gzcom* mpRight;
    uint32_t mKey;
};

struct Less_0094ca22_shapec01_gzcom {
    // STUB: 0x94c990
    bool Compare(const uint32_t* lhs, const uint32_t* rhs);
};

struct View_0094ca22_shapec01_gzcom {
    Node_0094ca22_shapec01_gzcom* mpHeader;
    uint32_t mnSize;
    Less_0094ca22_shapec01_gzcom mLess;
    Node_0094ca22_shapec01_gzcom* Fn0094ca22(const uint32_t* key);
};

// FUNCTION: 0x0094ca22
Node_0094ca22_shapec01_gzcom* View_0094ca22_shapec01_gzcom::Fn0094ca22(const uint32_t* key)
{
    Node_0094ca22_shapec01_gzcom* y = mpHeader;
    Node_0094ca22_shapec01_gzcom* x = y->mpParent;
    while (x) {
        if (!mLess.Compare(&x->mKey, key)) {
            y = x;
            x = x->mpLeft;
        } else {
            x = x->mpRight;
        }
    }
    if (y == mpHeader || mLess.Compare(key, &y->mKey)) {
        y = mpHeader;
    }
    return y;
}

struct Node_008feb1e_shapec01_gzcom {
    uint32_t mColor;
    Node_008feb1e_shapec01_gzcom* mpParent;
    Node_008feb1e_shapec01_gzcom* mpLeft;
    Node_008feb1e_shapec01_gzcom* mpRight;
    uint32_t mKey;
};

struct Less_008feb1e_shapec01_gzcom {
    // STUB: 0x4b5e10
    bool Compare(const uint32_t* lhs, const uint32_t* rhs);
};

struct View_008feb1e_shapec01_gzcom {
    Node_008feb1e_shapec01_gzcom* mpHeader;
    uint32_t mnSize;
    Less_008feb1e_shapec01_gzcom mLess;
    Node_008feb1e_shapec01_gzcom* Fn008feb1e(const uint32_t* key);
};

// FUNCTION: 0x008feb1e
Node_008feb1e_shapec01_gzcom* View_008feb1e_shapec01_gzcom::Fn008feb1e(const uint32_t* key)
{
    Node_008feb1e_shapec01_gzcom* y = mpHeader;
    Node_008feb1e_shapec01_gzcom* x = y->mpParent;
    while (x) {
        if (!mLess.Compare(&x->mKey, key)) {
            y = x;
            x = x->mpLeft;
        } else {
            x = x->mpRight;
        }
    }
    if (y == mpHeader || mLess.Compare(key, &y->mKey)) {
        y = mpHeader;
    }
    return y;
}

struct Node_00933d65_shapec01_gzcom {
    uint32_t mColor;
    Node_00933d65_shapec01_gzcom* mpParent;
    Node_00933d65_shapec01_gzcom* mpLeft;
    Node_00933d65_shapec01_gzcom* mpRight;
    uint32_t mKey;
};

struct Less_00933d65_shapec01_gzcom {
    // STUB: 0x933a0c
    bool Compare(const uint32_t* lhs, const uint32_t* rhs);
};

struct View_00933d65_shapec01_gzcom {
    Node_00933d65_shapec01_gzcom* mpHeader;
    uint32_t mnSize;
    Less_00933d65_shapec01_gzcom mLess;
    Node_00933d65_shapec01_gzcom* Fn00933d65(const uint32_t* key);
};

// FUNCTION: 0x00933d65
Node_00933d65_shapec01_gzcom* View_00933d65_shapec01_gzcom::Fn00933d65(const uint32_t* key)
{
    Node_00933d65_shapec01_gzcom* y = mpHeader;
    Node_00933d65_shapec01_gzcom* x = y->mpParent;
    while (x) {
        if (!mLess.Compare(&x->mKey, key)) {
            y = x;
            x = x->mpLeft;
        } else {
            x = x->mpRight;
        }
    }
    if (y == mpHeader || mLess.Compare(key, &y->mKey)) {
        y = mpHeader;
    }
    return y;
}

struct Elem_009ba6f7_shapec01_gzcom {
    // STUB: 0x9b97fb
    void Construct(const Elem_009ba6f7_shapec01_gzcom* source);
    uint8_t mData[28];
};

struct Flags_009ba6f7_shapec01_gzcom {
    bool mbFlag;
    uint8_t mPad[2];
    uint8_t mAlloc;
};

struct Mem_009ba6f7_shapec01_gzcom {
    Elem_009ba6f7_shapec01_gzcom* mpEndOfStorage;
    // STUB: 0x933516
    Elem_009ba6f7_shapec01_gzcom* Allocate(uint32_t count);
};

// STUB: 0x9b9afa
Elem_009ba6f7_shapec01_gzcom* Copy009ba6f7(Elem_009ba6f7_shapec01_gzcom* first, Elem_009ba6f7_shapec01_gzcom* last, Elem_009ba6f7_shapec01_gzcom* out, const void* alloc);
// STUB: 0x9b9b23
Elem_009ba6f7_shapec01_gzcom* Fill009ba6f7(Elem_009ba6f7_shapec01_gzcom* out, uint32_t count, const Elem_009ba6f7_shapec01_gzcom* value, const void* alloc);

inline const uint32_t& Max009ba6f7(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct View_009ba6f7_shapec01_gzcom {
    Elem_009ba6f7_shapec01_gzcom* mpBegin;
    Elem_009ba6f7_shapec01_gzcom* mpEnd;
    Mem_009ba6f7_shapec01_gzcom mMem;
    // STUB: 0x9b9d4b
    void Release();
    void Fn009ba6f7(Elem_009ba6f7_shapec01_gzcom* pos, const Elem_009ba6f7_shapec01_gzcom* value, uint32_t unused, uint32_t count, Flags_009ba6f7_shapec01_gzcom flags);
};

// FUNCTION: 0x009ba6f7
void View_009ba6f7_shapec01_gzcom::Fn009ba6f7(Elem_009ba6f7_shapec01_gzcom* pos, const Elem_009ba6f7_shapec01_gzcom* value, uint32_t /*unused*/, uint32_t count, Flags_009ba6f7_shapec01_gzcom flags)
{
    uint32_t size = static_cast<uint32_t>((mpEnd - mpBegin));
    uint32_t len = Max009ba6f7(size, count) + size;
    Elem_009ba6f7_shapec01_gzcom* newBegin = mMem.Allocate(len);
    Elem_009ba6f7_shapec01_gzcom* cur = Copy009ba6f7(mpBegin, pos, newBegin, &flags.mAlloc);
    if (count == 1) {
        if (cur) {
            cur->Construct(value);
        }
        cur = cur + 1;
    } else {
        cur = Fill009ba6f7(cur, count, value, &flags.mAlloc);
    }
    if (!flags.mbFlag) {
        cur = Copy009ba6f7(pos, mpEnd, cur, &flags.mAlloc);
    }
    Release();
    mpBegin = newBegin;
    mpEnd = cur;
    mMem.mpEndOfStorage = newBegin + len;
}

struct Elem_009bfe4b_shapec01_gzcom {
    // STUB: 0x9bf530
    void Construct(const Elem_009bfe4b_shapec01_gzcom* source);
    uint8_t mData[60];
};

struct Flags_009bfe4b_shapec01_gzcom {
    bool mbFlag;
    uint8_t mPad[2];
    uint8_t mAlloc;
};

struct Mem_009bfe4b_shapec01_gzcom {
    Elem_009bfe4b_shapec01_gzcom* mpEndOfStorage;
    // STUB: 0x9bde3e
    Elem_009bfe4b_shapec01_gzcom* Allocate(uint32_t count);
};

// STUB: 0x9bfa92
Elem_009bfe4b_shapec01_gzcom* Copy009bfe4b(Elem_009bfe4b_shapec01_gzcom* first, Elem_009bfe4b_shapec01_gzcom* last, Elem_009bfe4b_shapec01_gzcom* out, const void* alloc);
// STUB: 0x9bfabb
Elem_009bfe4b_shapec01_gzcom* Fill009bfe4b(Elem_009bfe4b_shapec01_gzcom* out, uint32_t count, const Elem_009bfe4b_shapec01_gzcom* value, const void* alloc);

inline const uint32_t& Max009bfe4b(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct View_009bfe4b_shapec01_gzcom {
    Elem_009bfe4b_shapec01_gzcom* mpBegin;
    Elem_009bfe4b_shapec01_gzcom* mpEnd;
    Mem_009bfe4b_shapec01_gzcom mMem;
    // STUB: 0x9bfa74
    void Release();
    void Fn009bfe4b(Elem_009bfe4b_shapec01_gzcom* pos, const Elem_009bfe4b_shapec01_gzcom* value, uint32_t unused, uint32_t count, Flags_009bfe4b_shapec01_gzcom flags);
};

// FUNCTION: 0x009bfe4b
void View_009bfe4b_shapec01_gzcom::Fn009bfe4b(Elem_009bfe4b_shapec01_gzcom* pos, const Elem_009bfe4b_shapec01_gzcom* value, uint32_t /*unused*/, uint32_t count, Flags_009bfe4b_shapec01_gzcom flags)
{
    uint32_t size = static_cast<uint32_t>((mpEnd - mpBegin));
    uint32_t len = Max009bfe4b(size, count) + size;
    Elem_009bfe4b_shapec01_gzcom* newBegin = mMem.Allocate(len);
    Elem_009bfe4b_shapec01_gzcom* cur = Copy009bfe4b(mpBegin, pos, newBegin, &flags.mAlloc);
    if (count == 1) {
        if (cur) {
            cur->Construct(value);
        }
        cur = cur + 1;
    } else {
        cur = Fill009bfe4b(cur, count, value, &flags.mAlloc);
    }
    if (!flags.mbFlag) {
        cur = Copy009bfe4b(pos, mpEnd, cur, &flags.mAlloc);
    }
    Release();
    mpBegin = newBegin;
    mpEnd = cur;
    mMem.mpEndOfStorage = newBegin + len;
}

struct Elem_008d63f3_shapec01_gzcom {
    // STUB: 0x8d3c38
    void Construct(const Elem_008d63f3_shapec01_gzcom* source);
    uint8_t mData[44];
};

struct Flags_008d63f3_shapec01_gzcom {
    bool mbFlag;
    uint8_t mPad[2];
    uint8_t mAlloc;
};

struct Mem_008d63f3_shapec01_gzcom {
    Elem_008d63f3_shapec01_gzcom* mpEndOfStorage;
    // STUB: 0x8d3376
    Elem_008d63f3_shapec01_gzcom* Allocate(uint32_t count);
};

// STUB: 0x8d50b2
Elem_008d63f3_shapec01_gzcom* Copy008d63f3(Elem_008d63f3_shapec01_gzcom* first, Elem_008d63f3_shapec01_gzcom* last, Elem_008d63f3_shapec01_gzcom* out, const void* alloc);
// STUB: 0x8d6230
Elem_008d63f3_shapec01_gzcom* Fill008d63f3(Elem_008d63f3_shapec01_gzcom* out, uint32_t count, const Elem_008d63f3_shapec01_gzcom* value, const void* alloc);

inline const uint32_t& Max008d63f3(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct View_008d63f3_shapec01_gzcom {
    Elem_008d63f3_shapec01_gzcom* mpBegin;
    Elem_008d63f3_shapec01_gzcom* mpEnd;
    Mem_008d63f3_shapec01_gzcom mMem;
    // STUB: 0x8d51fc
    void Release();
    void Fn008d63f3(Elem_008d63f3_shapec01_gzcom* pos, const Elem_008d63f3_shapec01_gzcom* value, uint32_t unused, uint32_t count, Flags_008d63f3_shapec01_gzcom flags);
};

// FUNCTION: 0x008d63f3
void View_008d63f3_shapec01_gzcom::Fn008d63f3(Elem_008d63f3_shapec01_gzcom* pos, const Elem_008d63f3_shapec01_gzcom* value, uint32_t /*unused*/, uint32_t count, Flags_008d63f3_shapec01_gzcom flags)
{
    uint32_t size = static_cast<uint32_t>((mpEnd - mpBegin));
    uint32_t len = Max008d63f3(size, count) + size;
    Elem_008d63f3_shapec01_gzcom* newBegin = mMem.Allocate(len);
    Elem_008d63f3_shapec01_gzcom* cur = Copy008d63f3(mpBegin, pos, newBegin, &flags.mAlloc);
    if (count == 1) {
        if (cur) {
            cur->Construct(value);
        }
        cur = cur + 1;
    } else {
        cur = Fill008d63f3(cur, count, value, &flags.mAlloc);
    }
    if (!flags.mbFlag) {
        cur = Copy008d63f3(pos, mpEnd, cur, &flags.mAlloc);
    }
    Release();
    mpBegin = newBegin;
    mpEnd = cur;
    mMem.mpEndOfStorage = newBegin + len;
}

struct Elem_00875337_shapec01_gzcom {
    // STUB: 0x8750ae
    void Construct(const Elem_00875337_shapec01_gzcom* source);
    uint8_t mData[44];
};

struct Flags_00875337_shapec01_gzcom {
    bool mbFlag;
    uint8_t mPad[2];
    uint8_t mAlloc;
};

struct Mem_00875337_shapec01_gzcom {
    Elem_00875337_shapec01_gzcom* mpEndOfStorage;
    // STUB: 0x8d3376
    Elem_00875337_shapec01_gzcom* Allocate(uint32_t count);
};

// STUB: 0x8750f7
Elem_00875337_shapec01_gzcom* Copy00875337(Elem_00875337_shapec01_gzcom* first, Elem_00875337_shapec01_gzcom* last, Elem_00875337_shapec01_gzcom* out, const void* alloc);
// STUB: 0x875120
Elem_00875337_shapec01_gzcom* Fill00875337(Elem_00875337_shapec01_gzcom* out, uint32_t count, const Elem_00875337_shapec01_gzcom* value, const void* alloc);

inline const uint32_t& Max00875337(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct View_00875337_shapec01_gzcom {
    Elem_00875337_shapec01_gzcom* mpBegin;
    Elem_00875337_shapec01_gzcom* mpEnd;
    Mem_00875337_shapec01_gzcom mMem;
    // STUB: 0x875161
    void Release();
    void Fn00875337(Elem_00875337_shapec01_gzcom* pos, const Elem_00875337_shapec01_gzcom* value, uint32_t unused, uint32_t count, Flags_00875337_shapec01_gzcom flags);
};

// FUNCTION: 0x00875337
void View_00875337_shapec01_gzcom::Fn00875337(Elem_00875337_shapec01_gzcom* pos, const Elem_00875337_shapec01_gzcom* value, uint32_t /*unused*/, uint32_t count, Flags_00875337_shapec01_gzcom flags)
{
    uint32_t size = static_cast<uint32_t>((mpEnd - mpBegin));
    uint32_t len = Max00875337(size, count) + size;
    Elem_00875337_shapec01_gzcom* newBegin = mMem.Allocate(len);
    Elem_00875337_shapec01_gzcom* cur = Copy00875337(mpBegin, pos, newBegin, &flags.mAlloc);
    if (count == 1) {
        if (cur) {
            cur->Construct(value);
        }
        cur = cur + 1;
    } else {
        cur = Fill00875337(cur, count, value, &flags.mAlloc);
    }
    if (!flags.mbFlag) {
        cur = Copy00875337(pos, mpEnd, cur, &flags.mAlloc);
    }
    Release();
    mpBegin = newBegin;
    mpEnd = cur;
    mMem.mpEndOfStorage = newBegin + len;
}

struct Elem_009ba538_shapec01_gzcom {
    // STUB: 0x9b978d
    void Construct(const Elem_009ba538_shapec01_gzcom* source);
    uint8_t mData[40];
};

struct Flags_009ba538_shapec01_gzcom {
    bool mbFlag;
    uint8_t mPad[2];
    uint8_t mAlloc;
};

struct Mem_009ba538_shapec01_gzcom {
    Elem_009ba538_shapec01_gzcom* mpEndOfStorage;
    // STUB: 0x9b3537
    Elem_009ba538_shapec01_gzcom* Allocate(uint32_t count, uint32_t zero);
};

// STUB: 0x9b9a58
Elem_009ba538_shapec01_gzcom* Copy009ba538(Elem_009ba538_shapec01_gzcom* first, Elem_009ba538_shapec01_gzcom* last, Elem_009ba538_shapec01_gzcom* out, const void* alloc);
// STUB: 0x9b9a81
Elem_009ba538_shapec01_gzcom* Fill009ba538(Elem_009ba538_shapec01_gzcom* out, uint32_t count, const Elem_009ba538_shapec01_gzcom* value, const void* alloc);

inline const uint32_t& Max009ba538(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct View_009ba538_shapec01_gzcom {
    Elem_009ba538_shapec01_gzcom* mpBegin;
    Elem_009ba538_shapec01_gzcom* mpEnd;
    Mem_009ba538_shapec01_gzcom mMem;
    // STUB: 0x9b9c2d
    void Release();
    void Fn009ba538(Elem_009ba538_shapec01_gzcom* pos, const Elem_009ba538_shapec01_gzcom* value, uint32_t unused, uint32_t count, Flags_009ba538_shapec01_gzcom flags);
};

// FUNCTION: 0x009ba538
void View_009ba538_shapec01_gzcom::Fn009ba538(Elem_009ba538_shapec01_gzcom* pos, const Elem_009ba538_shapec01_gzcom* value, uint32_t /*unused*/, uint32_t count, Flags_009ba538_shapec01_gzcom flags)
{
    uint32_t size = static_cast<uint32_t>((mpEnd - mpBegin));
    uint32_t len = Max009ba538(size, count) + size;
    Elem_009ba538_shapec01_gzcom* newBegin = mMem.Allocate(len, 0);
    Elem_009ba538_shapec01_gzcom* cur = Copy009ba538(mpBegin, pos, newBegin, &flags.mAlloc);
    if (count == 1) {
        if (cur) {
            cur->Construct(value);
        }
        cur = cur + 1;
    } else {
        cur = Fill009ba538(cur, count, value, &flags.mAlloc);
    }
    if (!flags.mbFlag) {
        cur = Copy009ba538(pos, mpEnd, cur, &flags.mAlloc);
    }
    Release();
    mpBegin = newBegin;
    mpEnd = cur;
    mMem.mpEndOfStorage = newBegin + len;
}

struct Elem_00900e91_shapec01_gzcom {
    // STUB: 0x8ffe11
    void Construct(const Elem_00900e91_shapec01_gzcom* source);
    uint8_t mData[40];
};

struct Flags_00900e91_shapec01_gzcom {
    bool mbFlag;
    uint8_t mPad[2];
    uint8_t mAlloc;
};

struct Mem_00900e91_shapec01_gzcom {
    Elem_00900e91_shapec01_gzcom* mpEndOfStorage;
    // STUB: 0x9b3537
    Elem_00900e91_shapec01_gzcom* Allocate(uint32_t count, uint32_t zero);
};

// STUB: 0x900278
Elem_00900e91_shapec01_gzcom* Copy00900e91(Elem_00900e91_shapec01_gzcom* first, Elem_00900e91_shapec01_gzcom* last, Elem_00900e91_shapec01_gzcom* out, const void* alloc);
// STUB: 0x9002a1
Elem_00900e91_shapec01_gzcom* Fill00900e91(Elem_00900e91_shapec01_gzcom* out, uint32_t count, const Elem_00900e91_shapec01_gzcom* value, const void* alloc);

inline const uint32_t& Max00900e91(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct View_00900e91_shapec01_gzcom {
    Elem_00900e91_shapec01_gzcom* mpBegin;
    Elem_00900e91_shapec01_gzcom* mpEnd;
    Mem_00900e91_shapec01_gzcom mMem;
    // STUB: 0x900492
    void Release();
    void Fn00900e91(Elem_00900e91_shapec01_gzcom* pos, const Elem_00900e91_shapec01_gzcom* value, uint32_t unused, uint32_t count, Flags_00900e91_shapec01_gzcom flags);
};

// FUNCTION: 0x00900e91
void View_00900e91_shapec01_gzcom::Fn00900e91(Elem_00900e91_shapec01_gzcom* pos, const Elem_00900e91_shapec01_gzcom* value, uint32_t /*unused*/, uint32_t count, Flags_00900e91_shapec01_gzcom flags)
{
    uint32_t size = static_cast<uint32_t>((mpEnd - mpBegin));
    uint32_t len = Max00900e91(size, count) + size;
    Elem_00900e91_shapec01_gzcom* newBegin = mMem.Allocate(len, 0);
    Elem_00900e91_shapec01_gzcom* cur = Copy00900e91(mpBegin, pos, newBegin, &flags.mAlloc);
    if (count == 1) {
        if (cur) {
            cur->Construct(value);
        }
        cur = cur + 1;
    } else {
        cur = Fill00900e91(cur, count, value, &flags.mAlloc);
    }
    if (!flags.mbFlag) {
        cur = Copy00900e91(pos, mpEnd, cur, &flags.mAlloc);
    }
    Release();
    mpBegin = newBegin;
    mpEnd = cur;
    mMem.mpEndOfStorage = newBegin + len;
}

struct Elem_0091d075_shapec01_gzcom {
    // STUB: 0x91c9ec
    void Construct(const Elem_0091d075_shapec01_gzcom* source);
    uint8_t mData[40];
};

struct Flags_0091d075_shapec01_gzcom {
    bool mbFlag;
    uint8_t mPad[2];
    uint8_t mAlloc;
};

struct Mem_0091d075_shapec01_gzcom {
    Elem_0091d075_shapec01_gzcom* mpEndOfStorage;
    // STUB: 0x9b3537
    Elem_0091d075_shapec01_gzcom* Allocate(uint32_t count, uint32_t zero);
};

// STUB: 0x91cb44
Elem_0091d075_shapec01_gzcom* Copy0091d075(Elem_0091d075_shapec01_gzcom* first, Elem_0091d075_shapec01_gzcom* last, Elem_0091d075_shapec01_gzcom* out, const void* alloc);
// STUB: 0x91cb6d
Elem_0091d075_shapec01_gzcom* Fill0091d075(Elem_0091d075_shapec01_gzcom* out, uint32_t count, const Elem_0091d075_shapec01_gzcom* value, const void* alloc);

inline const uint32_t& Max0091d075(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct View_0091d075_shapec01_gzcom {
    Elem_0091d075_shapec01_gzcom* mpBegin;
    Elem_0091d075_shapec01_gzcom* mpEnd;
    Mem_0091d075_shapec01_gzcom mMem;
    // STUB: 0x91ce50
    void Release();
    void Fn0091d075(Elem_0091d075_shapec01_gzcom* pos, const Elem_0091d075_shapec01_gzcom* value, uint32_t unused, uint32_t count, Flags_0091d075_shapec01_gzcom flags);
};

// FUNCTION: 0x0091d075
void View_0091d075_shapec01_gzcom::Fn0091d075(Elem_0091d075_shapec01_gzcom* pos, const Elem_0091d075_shapec01_gzcom* value, uint32_t /*unused*/, uint32_t count, Flags_0091d075_shapec01_gzcom flags)
{
    uint32_t size = static_cast<uint32_t>((mpEnd - mpBegin));
    uint32_t len = Max0091d075(size, count) + size;
    Elem_0091d075_shapec01_gzcom* newBegin = mMem.Allocate(len, 0);
    Elem_0091d075_shapec01_gzcom* cur = Copy0091d075(mpBegin, pos, newBegin, &flags.mAlloc);
    if (count == 1) {
        if (cur) {
            cur->Construct(value);
        }
        cur = cur + 1;
    } else {
        cur = Fill0091d075(cur, count, value, &flags.mAlloc);
    }
    if (!flags.mbFlag) {
        cur = Copy0091d075(pos, mpEnd, cur, &flags.mAlloc);
    }
    Release();
    mpBegin = newBegin;
    mpEnd = cur;
    mMem.mpEndOfStorage = newBegin + len;
}

struct Elem_009bac6c_shapec01_gzcom {
    // STUB: 0x9b974e
    void Construct(const Elem_009bac6c_shapec01_gzcom* source);
    uint8_t mData[40];
};

struct Flags_009bac6c_shapec01_gzcom {
    bool mbFlag;
    uint8_t mPad[2];
    uint8_t mAlloc;
};

struct Mem_009bac6c_shapec01_gzcom {
    Elem_009bac6c_shapec01_gzcom* mpEndOfStorage;
    // STUB: 0x9b3537
    Elem_009bac6c_shapec01_gzcom* Allocate(uint32_t count, uint32_t zero);
};

// STUB: 0x9b9a07
Elem_009bac6c_shapec01_gzcom* Copy009bac6c(Elem_009bac6c_shapec01_gzcom* first, Elem_009bac6c_shapec01_gzcom* last, Elem_009bac6c_shapec01_gzcom* out, const void* alloc);
// STUB: 0x9b9a30
Elem_009bac6c_shapec01_gzcom* Fill009bac6c(Elem_009bac6c_shapec01_gzcom* out, uint32_t count, const Elem_009bac6c_shapec01_gzcom* value, const void* alloc);

inline const uint32_t& Max009bac6c(const uint32_t& a, const uint32_t& b)
{
    return a < b ? b : a;
}

struct View_009bac6c_shapec01_gzcom {
    Elem_009bac6c_shapec01_gzcom* mpBegin;
    Elem_009bac6c_shapec01_gzcom* mpEnd;
    Mem_009bac6c_shapec01_gzcom mMem;
    // STUB: 0x9b9c2d
    void Release();
    void Fn009bac6c(Elem_009bac6c_shapec01_gzcom* pos, const Elem_009bac6c_shapec01_gzcom* value, uint32_t unused, uint32_t count, Flags_009bac6c_shapec01_gzcom flags);
};

// FUNCTION: 0x009bac6c
void View_009bac6c_shapec01_gzcom::Fn009bac6c(Elem_009bac6c_shapec01_gzcom* pos, const Elem_009bac6c_shapec01_gzcom* value, uint32_t /*unused*/, uint32_t count, Flags_009bac6c_shapec01_gzcom flags)
{
    uint32_t size = static_cast<uint32_t>((mpEnd - mpBegin));
    uint32_t len = Max009bac6c(size, count) + size;
    Elem_009bac6c_shapec01_gzcom* newBegin = mMem.Allocate(len, 0);
    Elem_009bac6c_shapec01_gzcom* cur = Copy009bac6c(mpBegin, pos, newBegin, &flags.mAlloc);
    if (count == 1) {
        if (cur) {
            cur->Construct(value);
        }
        cur = cur + 1;
    } else {
        cur = Fill009bac6c(cur, count, value, &flags.mAlloc);
    }
    if (!flags.mbFlag) {
        cur = Copy009bac6c(pos, mpEnd, cur, &flags.mAlloc);
    }
    Release();
    mpBegin = newBegin;
    mpEnd = cur;
    mMem.mpEndOfStorage = newBegin + len;
}

struct Base_008906b4_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Load() = 0;
};

struct View_008906b4_shapec01_gzcom {
    uint8_t mPad[6];
    bool mbLoaded;
    uint8_t mPad2[5];
    uint32_t mnValue;
    uint32_t Fn008906b4();
};

// FUNCTION: 0x008906b4
uint32_t View_008906b4_shapec01_gzcom::Fn008906b4()
{
    if (!mbLoaded) {
        reinterpret_cast<Base_008906b4_shapec01_gzcom*>(reinterpret_cast<char*>(this) - 28)->Load();
        mbLoaded = true;
    }
    return mnValue;
}

struct Base_008906ce_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Load() = 0;
};

struct View_008906ce_shapec01_gzcom {
    uint8_t mPad[6];
    bool mbLoaded;
    uint8_t mPad2[25];
    uint32_t mnValue;
    uint32_t Fn008906ce();
};

// FUNCTION: 0x008906ce
uint32_t View_008906ce_shapec01_gzcom::Fn008906ce()
{
    if (!mbLoaded) {
        reinterpret_cast<Base_008906ce_shapec01_gzcom*>(reinterpret_cast<char*>(this) - 28)->Load();
        mbLoaded = true;
    }
    return mnValue;
}

struct Base_008906e8_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Load() = 0;
};

struct View_008906e8_shapec01_gzcom {
    uint8_t mPad[6];
    bool mbLoaded;
    uint8_t mPad2[45];
    uint32_t mnValue;
    uint32_t Fn008906e8();
};

// FUNCTION: 0x008906e8
uint32_t View_008906e8_shapec01_gzcom::Fn008906e8()
{
    if (!mbLoaded) {
        reinterpret_cast<Base_008906e8_shapec01_gzcom*>(reinterpret_cast<char*>(this) - 28)->Load();
        mbLoaded = true;
    }
    return mnValue;
}

struct Base_00890702_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Pad8() = 0;
    virtual void Pad9() = 0;
    virtual void Pad10() = 0;
    virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void Load() = 0;
};

struct View_00890702_shapec01_gzcom {
    uint8_t mPad[6];
    bool mbLoaded;
    uint8_t mPad2[65];
    uint32_t mnValue;
    uint32_t Fn00890702();
};

// FUNCTION: 0x00890702
uint32_t View_00890702_shapec01_gzcom::Fn00890702()
{
    if (!mbLoaded) {
        reinterpret_cast<Base_00890702_shapec01_gzcom*>(reinterpret_cast<char*>(this) - 28)->Load();
        mbLoaded = true;
    }
    return mnValue;
}

struct Obj_00922394_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

struct View_00922394_shapec01_gzcom {
    uint32_t mnVtable;
    uint8_t mPadc[8];
    Obj_00922394_shapec01_gzcom* mpObj;
    void Fn00922394();
};

// FUNCTION: 0x00922394
void View_00922394_shapec01_gzcom::Fn00922394()
{
    mnVtable = 0xacfdcc;
    if (mpObj) {
        mpObj->Release();
    }
}

struct Obj_0092b62d_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

struct View_0092b62d_shapec01_gzcom {
    uint32_t mnVtable;
    uint8_t mPadc[8];
    Obj_0092b62d_shapec01_gzcom* mpObj;
    void Fn0092b62d();
};

// FUNCTION: 0x0092b62d
void View_0092b62d_shapec01_gzcom::Fn0092b62d()
{
    mnVtable = 0xad1818;
    if (mpObj) {
        mpObj->Release();
    }
}

struct Obj_0092b79f_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

struct View_0092b79f_shapec01_gzcom {
    uint32_t mnVtable;
    uint8_t mPadc[8];
    Obj_0092b79f_shapec01_gzcom* mpObj;
    void Fn0092b79f();
};

// FUNCTION: 0x0092b79f
void View_0092b79f_shapec01_gzcom::Fn0092b79f()
{
    mnVtable = 0xad1878;
    if (mpObj) {
        mpObj->Release();
    }
}

struct Obj_0097598d_shapec01_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Release() = 0;
};

struct View_0097598d_shapec01_gzcom {
    uint32_t mnVtable;
    uint8_t mPad14[16];
    Obj_0097598d_shapec01_gzcom* mpObj;
    void Fn0097598d();
};

// FUNCTION: 0x0097598d
void View_0097598d_shapec01_gzcom::Fn0097598d()
{
    mnVtable = 0xad8d48;
    if (mpObj) {
        mpObj->Release();
    }
}

struct View_009561dc_shapec01_gzcom {
    // STUB: 0x94cb8b
    void Init(void* unused, void* alloc);
    View_009561dc_shapec01_gzcom* Fn009561dc();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009561dc score 1
View_009561dc_shapec01_gzcom* View_009561dc_shapec01_gzcom::Fn009561dc()
{
    uint8_t unused;
    Init(&unused, &unused);
    return this;
}
#endif

struct View_0092e6c9_shapec01_gzcom {
    // STUB: 0x892017
    void Init(void* unused, void* alloc);
    View_0092e6c9_shapec01_gzcom* Fn0092e6c9();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0092e6c9 score 1
View_0092e6c9_shapec01_gzcom* View_0092e6c9_shapec01_gzcom::Fn0092e6c9()
{
    uint8_t unused;
    Init(&unused, &unused);
    return this;
}
#endif

struct View_009348e8_shapec01_gzcom {
    // STUB: 0x933eff
    void Init(void* unused, void* alloc);
    View_009348e8_shapec01_gzcom* Fn009348e8();
};

#ifdef OB_DRAFTS
// CLOSE: 0x009348e8 score 1
View_009348e8_shapec01_gzcom* View_009348e8_shapec01_gzcom::Fn009348e8()
{
    uint8_t unused;
    Init(&unused, &unused);
    return this;
}
#endif

struct View_0090d343_shapec01_gzcom {
    // STUB: 0x90d291
    void Init(void* unused, void* alloc);
    View_0090d343_shapec01_gzcom* Fn0090d343();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0090d343 score 1
View_0090d343_shapec01_gzcom* View_0090d343_shapec01_gzcom::Fn0090d343()
{
    uint8_t unused;
    Init(&unused, &unused);
    return this;
}
#endif
