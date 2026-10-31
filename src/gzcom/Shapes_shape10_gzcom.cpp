#include "common/types.h"

struct Elem_00944b33_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_00944b33_shape10_gzcom {};
// STUB: 0x00944874
Elem_00944b33_shape10_gzcom* Copy_00944b33_shape10_gzcom(Elem_00944b33_shape10_gzcom* first, Elem_00944b33_shape10_gzcom* last, Elem_00944b33_shape10_gzcom* out, Tag_00944b33_shape10_gzcom* tag);

// FUNCTION: 0x00944b33
Elem_00944b33_shape10_gzcom* Fn00944b33(Elem_00944b33_shape10_gzcom* first, Elem_00944b33_shape10_gzcom* last, Elem_00944b33_shape10_gzcom* out)
{
    Tag_00944b33_shape10_gzcom tag;
    return Copy_00944b33_shape10_gzcom(first, last, out, &tag);
}

struct View_0094c483_shape10_gzcom {
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
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnPad4;
    uint32_t mnPad8;
    uint32_t mnRefs;
    uint32_t Fn0094c483();
};

// FUNCTION: 0x0094c483
uint32_t View_0094c483_shape10_gzcom::Fn0094c483()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_0087b319_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn0087b319(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0087b319 score 8  (the original lays out the true path before the false one and shares one ret)
bool View_0087b319_shape10_gzcom::Fn0087b319(uint32_t iid, void** ppv)
{
    if (iid == 0x7d4922e || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif


struct Elem_00897599_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_00897599_shape10_gzcom {};
// STUB: 0x00896c19
Elem_00897599_shape10_gzcom* Copy_00897599_shape10_gzcom(Elem_00897599_shape10_gzcom* first, Elem_00897599_shape10_gzcom* last, Elem_00897599_shape10_gzcom* out, Tag_00897599_shape10_gzcom* tag);

// FUNCTION: 0x00897599
Elem_00897599_shape10_gzcom* Fn00897599(Elem_00897599_shape10_gzcom* first, Elem_00897599_shape10_gzcom* last, Elem_00897599_shape10_gzcom* out)
{
    Tag_00897599_shape10_gzcom tag;
    return Copy_00897599_shape10_gzcom(first, last, out, &tag);
}

struct Elem_009b684b_shape10_gzcom {
    uint8_t mData[12];
    // STUB: 0x00909b33
    void CopyFrom(const Elem_009b684b_shape10_gzcom& src);
};

// FUNCTION: 0x009b684b
Elem_009b684b_shape10_gzcom* Fn009b684b(Elem_009b684b_shape10_gzcom* first, Elem_009b684b_shape10_gzcom* last, Elem_009b684b_shape10_gzcom* out)
{
    Elem_009b684b_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct Elem_009b68dd_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_009b68dd_shape10_gzcom {};
// STUB: 0x009b6874
Elem_009b68dd_shape10_gzcom* Copy_009b68dd_shape10_gzcom(Elem_009b68dd_shape10_gzcom* first, Elem_009b68dd_shape10_gzcom* last, Elem_009b68dd_shape10_gzcom* out, Tag_009b68dd_shape10_gzcom* tag);

// FUNCTION: 0x009b68dd
Elem_009b68dd_shape10_gzcom* Fn009b68dd(Elem_009b68dd_shape10_gzcom* first, Elem_009b68dd_shape10_gzcom* last, Elem_009b68dd_shape10_gzcom* out)
{
    Tag_009b68dd_shape10_gzcom tag;
    return Copy_009b68dd_shape10_gzcom(first, last, out, &tag);
}

struct Elem_009b9a07_shape10_gzcom {
    uint8_t mData[40];
    // STUB: 0x009b974e
    void CopyFrom(const Elem_009b9a07_shape10_gzcom& src);
};

// FUNCTION: 0x009b9a07
Elem_009b9a07_shape10_gzcom* Fn009b9a07(Elem_009b9a07_shape10_gzcom* first, Elem_009b9a07_shape10_gzcom* last, Elem_009b9a07_shape10_gzcom* out)
{
    Elem_009b9a07_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct Elem_009b9a58_shape10_gzcom {
    uint8_t mData[40];
    // STUB: 0x009b978d
    void CopyFrom(const Elem_009b9a58_shape10_gzcom& src);
};

// FUNCTION: 0x009b9a58
Elem_009b9a58_shape10_gzcom* Fn009b9a58(Elem_009b9a58_shape10_gzcom* first, Elem_009b9a58_shape10_gzcom* last, Elem_009b9a58_shape10_gzcom* out)
{
    Elem_009b9a58_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct Elem_009b9aa9_shape10_gzcom {
    uint8_t mData[36];
    // STUB: 0x009b97c6
    void CopyFrom(const Elem_009b9aa9_shape10_gzcom& src);
};

// FUNCTION: 0x009b9aa9
Elem_009b9aa9_shape10_gzcom* Fn009b9aa9(Elem_009b9aa9_shape10_gzcom* first, Elem_009b9aa9_shape10_gzcom* last, Elem_009b9aa9_shape10_gzcom* out)
{
    Elem_009b9aa9_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct Elem_009b9afa_shape10_gzcom {
    uint8_t mData[28];
    // STUB: 0x009b97fb
    void CopyFrom(const Elem_009b9afa_shape10_gzcom& src);
};

// FUNCTION: 0x009b9afa
Elem_009b9afa_shape10_gzcom* Fn009b9afa(Elem_009b9afa_shape10_gzcom* first, Elem_009b9afa_shape10_gzcom* last, Elem_009b9afa_shape10_gzcom* out)
{
    Elem_009b9afa_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct Elem_009b9d69_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_009b9d69_shape10_gzcom {};
// STUB: 0x009b9a30
Elem_009b9d69_shape10_gzcom* Copy_009b9d69_shape10_gzcom(Elem_009b9d69_shape10_gzcom* first, Elem_009b9d69_shape10_gzcom* last, Elem_009b9d69_shape10_gzcom* out, Tag_009b9d69_shape10_gzcom* tag);

// FUNCTION: 0x009b9d69
Elem_009b9d69_shape10_gzcom* Fn009b9d69(Elem_009b9d69_shape10_gzcom* first, Elem_009b9d69_shape10_gzcom* last, Elem_009b9d69_shape10_gzcom* out)
{
    Tag_009b9d69_shape10_gzcom tag;
    return Copy_009b9d69_shape10_gzcom(first, last, out, &tag);
}

struct Elem_009b9d9c_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_009b9d9c_shape10_gzcom {};
// STUB: 0x009b9a81
Elem_009b9d9c_shape10_gzcom* Copy_009b9d9c_shape10_gzcom(Elem_009b9d9c_shape10_gzcom* first, Elem_009b9d9c_shape10_gzcom* last, Elem_009b9d9c_shape10_gzcom* out, Tag_009b9d9c_shape10_gzcom* tag);

// FUNCTION: 0x009b9d9c
Elem_009b9d9c_shape10_gzcom* Fn009b9d9c(Elem_009b9d9c_shape10_gzcom* first, Elem_009b9d9c_shape10_gzcom* last, Elem_009b9d9c_shape10_gzcom* out)
{
    Tag_009b9d9c_shape10_gzcom tag;
    return Copy_009b9d9c_shape10_gzcom(first, last, out, &tag);
}

struct Elem_009b9db7_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_009b9db7_shape10_gzcom {};
// STUB: 0x009b9ad2
Elem_009b9db7_shape10_gzcom* Copy_009b9db7_shape10_gzcom(Elem_009b9db7_shape10_gzcom* first, Elem_009b9db7_shape10_gzcom* last, Elem_009b9db7_shape10_gzcom* out, Tag_009b9db7_shape10_gzcom* tag);

// FUNCTION: 0x009b9db7
Elem_009b9db7_shape10_gzcom* Fn009b9db7(Elem_009b9db7_shape10_gzcom* first, Elem_009b9db7_shape10_gzcom* last, Elem_009b9db7_shape10_gzcom* out)
{
    Tag_009b9db7_shape10_gzcom tag;
    return Copy_009b9db7_shape10_gzcom(first, last, out, &tag);
}

struct Elem_009b9dd2_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_009b9dd2_shape10_gzcom {};
// STUB: 0x009b9b23
Elem_009b9dd2_shape10_gzcom* Copy_009b9dd2_shape10_gzcom(Elem_009b9dd2_shape10_gzcom* first, Elem_009b9dd2_shape10_gzcom* last, Elem_009b9dd2_shape10_gzcom* out, Tag_009b9dd2_shape10_gzcom* tag);

// FUNCTION: 0x009b9dd2
Elem_009b9dd2_shape10_gzcom* Fn009b9dd2(Elem_009b9dd2_shape10_gzcom* first, Elem_009b9dd2_shape10_gzcom* last, Elem_009b9dd2_shape10_gzcom* out)
{
    Tag_009b9dd2_shape10_gzcom tag;
    return Copy_009b9dd2_shape10_gzcom(first, last, out, &tag);
}


struct Elem_009a96e2_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_009a96e2_shape10_gzcom {};
// STUB: 0x009a8574
Elem_009a96e2_shape10_gzcom* Copy_009a96e2_shape10_gzcom(Elem_009a96e2_shape10_gzcom* first, Elem_009a96e2_shape10_gzcom* last, Elem_009a96e2_shape10_gzcom* out, Tag_009a96e2_shape10_gzcom* tag);

// FUNCTION: 0x009a96e2
Elem_009a96e2_shape10_gzcom* Fn009a96e2(Elem_009a96e2_shape10_gzcom* first, Elem_009a96e2_shape10_gzcom* last, Elem_009a96e2_shape10_gzcom* out)
{
    Tag_009a96e2_shape10_gzcom tag;
    return Copy_009a96e2_shape10_gzcom(first, last, out, &tag);
}


struct Elem_009cba81_shape10_gzcom {
    uint8_t mData[4];
    // STUB: 0x0099d8f3
    void CopyFrom(const Elem_009cba81_shape10_gzcom& src);
};

// FUNCTION: 0x009cba81
Elem_009cba81_shape10_gzcom* Fn009cba81(Elem_009cba81_shape10_gzcom* first, Elem_009cba81_shape10_gzcom* last, Elem_009cba81_shape10_gzcom* out)
{
    Elem_009cba81_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct Elem_009cbac7_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_009cbac7_shape10_gzcom {};
// STUB: 0x009cba0d
Elem_009cbac7_shape10_gzcom* Copy_009cbac7_shape10_gzcom(Elem_009cbac7_shape10_gzcom* first, Elem_009cbac7_shape10_gzcom* last, Elem_009cbac7_shape10_gzcom* out, Tag_009cbac7_shape10_gzcom* tag);

// FUNCTION: 0x009cbac7
Elem_009cbac7_shape10_gzcom* Fn009cbac7(Elem_009cbac7_shape10_gzcom* first, Elem_009cbac7_shape10_gzcom* last, Elem_009cbac7_shape10_gzcom* out)
{
    Tag_009cbac7_shape10_gzcom tag;
    return Copy_009cbac7_shape10_gzcom(first, last, out, &tag);
}

struct Elem_009d5874_shape10_gzcom {
    uint8_t mData[48];
    // STUB: 0x009d582b
    void CopyFrom(const Elem_009d5874_shape10_gzcom& src);
};

// FUNCTION: 0x009d5874
Elem_009d5874_shape10_gzcom* Fn009d5874(Elem_009d5874_shape10_gzcom* first, Elem_009d5874_shape10_gzcom* last, Elem_009d5874_shape10_gzcom* out)
{
    Elem_009d5874_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct Elem_009bfa92_shape10_gzcom {
    uint8_t mData[60];
    // STUB: 0x009bf530
    void CopyFrom(const Elem_009bfa92_shape10_gzcom& src);
};

// FUNCTION: 0x009bfa92
Elem_009bfa92_shape10_gzcom* Fn009bfa92(Elem_009bfa92_shape10_gzcom* first, Elem_009bfa92_shape10_gzcom* last, Elem_009bfa92_shape10_gzcom* out)
{
    Elem_009bfa92_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

// GLOBAL: 0xbac09c
extern void* gpbac09c_shape10_gzcom;
struct Ref_009d0747_shape10_gzcom {
    void* mpService;
    // STUB: 0x00411840
    void Init();
    // STUB: 0x00411870
    void Done();
};

// FUNCTION: 0x009d0747
void* Fn009d0747()
{
    if (!gpbac09c_shape10_gzcom) {
        Ref_009d0747_shape10_gzcom ref;
        ref.Init();
        gpbac09c_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpbac09c_shape10_gzcom;
}

struct View_009d5ceb_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn009d5ceb(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009d5ceb score 8  (the original lays out the true path before the false one and shares one ret)
bool View_009d5ceb_shape10_gzcom::Fn009d5ceb(uint32_t iid, void** ppv)
{
    if (iid == 0xe2c1b3c4 || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct Elem_008f74ac_shape10_gzcom {
    uint8_t mData[24];
    // STUB: 0x00818400
    void CopyFrom(const Elem_008f74ac_shape10_gzcom& src);
};

// FUNCTION: 0x008f74ac
Elem_008f74ac_shape10_gzcom* Fn008f74ac(Elem_008f74ac_shape10_gzcom* first, Elem_008f74ac_shape10_gzcom* last, Elem_008f74ac_shape10_gzcom* out)
{
    Elem_008f74ac_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct View_008fecf8_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fecf8_shape10_gzcom* Fn008fecf8();
};

// FUNCTION: 0x008fecf8
View_008fecf8_shape10_gzcom* View_008fecf8_shape10_gzcom::Fn008fecf8()
{
    Base(0x22);
    mnVtable = 0xacd640;
    return this;
}

struct View_008fed0c_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fed0c_shape10_gzcom* Fn008fed0c();
};

// FUNCTION: 0x008fed0c
View_008fed0c_shape10_gzcom* View_008fed0c_shape10_gzcom::Fn008fed0c()
{
    Base(0x14);
    mnVtable = 0xacd66c;
    return this;
}

struct View_008fed34_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fed34_shape10_gzcom* Fn008fed34();
};

// FUNCTION: 0x008fed34
View_008fed34_shape10_gzcom* View_008fed34_shape10_gzcom::Fn008fed34()
{
    Base(0x13);
    mnVtable = 0xacd6c4;
    return this;
}

struct View_008fed48_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fed48_shape10_gzcom* Fn008fed48();
};

// FUNCTION: 0x008fed48
View_008fed48_shape10_gzcom* View_008fed48_shape10_gzcom::Fn008fed48()
{
    Base(0x9);
    mnVtable = 0xacd6f0;
    return this;
}

struct View_008fed5c_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fed5c_shape10_gzcom* Fn008fed5c();
};

// FUNCTION: 0x008fed5c
View_008fed5c_shape10_gzcom* View_008fed5c_shape10_gzcom::Fn008fed5c()
{
    Base(0x1c);
    mnVtable = 0xacd71c;
    return this;
}

struct View_008fed84_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fed84_shape10_gzcom* Fn008fed84();
};

// FUNCTION: 0x008fed84
View_008fed84_shape10_gzcom* View_008fed84_shape10_gzcom::Fn008fed84()
{
    Base(0xc);
    mnVtable = 0xacd774;
    return this;
}

struct View_008fed98_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fed98_shape10_gzcom* Fn008fed98();
};

// FUNCTION: 0x008fed98
View_008fed98_shape10_gzcom* View_008fed98_shape10_gzcom::Fn008fed98()
{
    Base(0xc);
    mnVtable = 0xacd7a0;
    return this;
}

struct View_008fedc4_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fedc4_shape10_gzcom* Fn008fedc4();
};

// FUNCTION: 0x008fedc4
View_008fedc4_shape10_gzcom* View_008fedc4_shape10_gzcom::Fn008fedc4()
{
    Base(0x1f);
    mnVtable = 0xacd7f8;
    return this;
}

struct View_008fedd8_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fedd8_shape10_gzcom* Fn008fedd8();
};

// FUNCTION: 0x008fedd8
View_008fedd8_shape10_gzcom* View_008fedd8_shape10_gzcom::Fn008fedd8()
{
    Base(0x15);
    mnVtable = 0xacd824;
    return this;
}

struct View_008fedec_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fedec_shape10_gzcom* Fn008fedec();
};

// FUNCTION: 0x008fedec
View_008fedec_shape10_gzcom* View_008fedec_shape10_gzcom::Fn008fedec()
{
    Base(0x1e);
    mnVtable = 0xacd850;
    return this;
}

struct View_008fee36_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x008fecbd
    void Base(uint32_t type);
    View_008fee36_shape10_gzcom* Fn008fee36();
};

// FUNCTION: 0x008fee36
View_008fee36_shape10_gzcom* View_008fee36_shape10_gzcom::Fn008fee36()
{
    Base(0x11);
    mnVtable = 0xacd8d4;
    return this;
}

struct Elem_00900278_shape10_gzcom {
    uint8_t mData[40];
    // STUB: 0x008ffe11
    void CopyFrom(const Elem_00900278_shape10_gzcom& src);
};

// FUNCTION: 0x00900278
Elem_00900278_shape10_gzcom* Fn00900278(Elem_00900278_shape10_gzcom* first, Elem_00900278_shape10_gzcom* last, Elem_00900278_shape10_gzcom* out)
{
    Elem_00900278_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct View_0097944e_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn0097944e(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0097944e score 8  (the original lays out the true path before the false one and shares one ret)
bool View_0097944e_shape10_gzcom::Fn0097944e(uint32_t iid, void** ppv)
{
    if (iid == 0x1 || iid == 0xa56c8cfd) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_00979473_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Pad6() = 0;
    virtual void Pad7() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn00979473();
};

// FUNCTION: 0x00979473
uint32_t View_00979473_shape10_gzcom::Fn00979473()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}






struct View_0097458b_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn0097458b(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0097458b score 8  (the original lays out the true path before the false one and shares one ret)
bool View_0097458b_shape10_gzcom::Fn0097458b(uint32_t iid, void** ppv)
{
    if (iid == 0x8865cd89 || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_009745c7_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn009745c7(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009745c7 score 8  (the original lays out the true path before the false one and shares one ret)
bool View_009745c7_shape10_gzcom::Fn009745c7(uint32_t iid, void** ppv)
{
    if (iid == 0x656b8f12 || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_009745ec_shape10_gzcom {
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
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnPad4;
    uint32_t mnPad8;
    uint32_t mnPad12;
    uint32_t mnPad16;
    uint32_t mnRefs;
    uint32_t Fn009745ec();
};

// FUNCTION: 0x009745ec
uint32_t View_009745ec_shape10_gzcom::Fn009745ec()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_00975436_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn00975436(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00975436 score 8  (the original lays out the true path before the false one and shares one ret)
bool View_00975436_shape10_gzcom::Fn00975436(uint32_t iid, void** ppv)
{
    if (iid == 0xa56b8f17 || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_00892a2c_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn00892a2c(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00892a2c score 8  (the original lays out the true path before the false one and shares one ret)
bool View_00892a2c_shape10_gzcom::Fn00892a2c(uint32_t iid, void** ppv)
{
    if (iid == 0xa4b30150 || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_00930528_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn00930528(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00930528 score 8  (the original lays out the true path before the false one and shares one ret)
bool View_00930528_shape10_gzcom::Fn00930528(uint32_t iid, void** ppv)
{
    if (iid == 0x3ae4beaa || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_009223c9_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void Pad1() = 0;
    virtual void Pad2() = 0;
    virtual void Pad3() = 0;
    virtual void Pad4() = 0;
    virtual void Pad5() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn009223c9();
};

// FUNCTION: 0x009223c9
uint32_t View_009223c9_shape10_gzcom::Fn009223c9()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_0092ebfd_shape10_gzcom {
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
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnPad4;
    uint32_t mnPad8;
    uint32_t mnPad12;
    uint32_t mnPad16;
    uint32_t mnPad20;
    uint32_t mnRefs;
    uint32_t Fn0092ebfd();
};

// FUNCTION: 0x0092ebfd
uint32_t View_0092ebfd_shape10_gzcom::Fn0092ebfd()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

// GLOBAL: 0xb628b0
extern void* gpb628b0_shape10_gzcom;
struct Ref_00913b97_shape10_gzcom {
    void* mpService;
    // STUB: 0x004d7bb0
    void Init();
    // STUB: 0x004d7b60
    void Done();
};

// FUNCTION: 0x00913b97
void* Fn00913b97()
{
    if (!gpb628b0_shape10_gzcom) {
        Ref_00913b97_shape10_gzcom ref;
        ref.Init();
        gpb628b0_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628b0_shape10_gzcom;
}

// GLOBAL: 0xb628b8
extern void* gpb628b8_shape10_gzcom;
struct Ref_00913bee_shape10_gzcom {
    void* mpService;
    // STUB: 0x00602190
    void Init();
    // STUB: 0x006021c0
    void Done();
};

// FUNCTION: 0x00913bee
void* Fn00913bee()
{
    if (!gpb628b8_shape10_gzcom) {
        Ref_00913bee_shape10_gzcom ref;
        ref.Init();
        gpb628b8_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628b8_shape10_gzcom;
}

// GLOBAL: 0xb628bc
extern void* gpb628bc_shape10_gzcom;
struct Ref_00913c1a_shape10_gzcom {
    void* mpService;
    // STUB: 0x00449560
    void Init();
    // STUB: 0x004495c0
    void Done();
};

// FUNCTION: 0x00913c1a
void* Fn00913c1a()
{
    if (!gpb628bc_shape10_gzcom) {
        Ref_00913c1a_shape10_gzcom ref;
        ref.Init();
        gpb628bc_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628bc_shape10_gzcom;
}

// GLOBAL: 0xb628c0
extern void* gpb628c0_shape10_gzcom;
struct Ref_00913c46_shape10_gzcom {
    void* mpService;
    // STUB: 0x004177c0
    void Init();
    // STUB: 0x004177f0
    void Done();
};

// FUNCTION: 0x00913c46
void* Fn00913c46()
{
    if (!gpb628c0_shape10_gzcom) {
        Ref_00913c46_shape10_gzcom ref;
        ref.Init();
        gpb628c0_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628c0_shape10_gzcom;
}

// GLOBAL: 0xb628c4
extern void* gpb628c4_shape10_gzcom;
struct Ref_00913c72_shape10_gzcom {
    void* mpService;
    // STUB: 0x007b2480
    void Init();
    // STUB: 0x007b24b0
    void Done();
};

// FUNCTION: 0x00913c72
void* Fn00913c72()
{
    if (!gpb628c4_shape10_gzcom) {
        Ref_00913c72_shape10_gzcom ref;
        ref.Init();
        gpb628c4_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628c4_shape10_gzcom;
}

// GLOBAL: 0xb628c8
extern void* gpb628c8_shape10_gzcom;
struct Ref_00913c9e_shape10_gzcom {
    void* mpService;
    // STUB: 0x004302e0
    void Init();
    // STUB: 0x00430310
    void Done();
};

// FUNCTION: 0x00913c9e
void* Fn00913c9e()
{
    if (!gpb628c8_shape10_gzcom) {
        Ref_00913c9e_shape10_gzcom ref;
        ref.Init();
        gpb628c8_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628c8_shape10_gzcom;
}

// GLOBAL: 0xb628d0
extern void* gpb628d0_shape10_gzcom;
struct Ref_00913cf6_shape10_gzcom {
    void* mpService;
    // STUB: 0x004ed100
    void Init();
    // STUB: 0x004ed130
    void Done();
};

// FUNCTION: 0x00913cf6
void* Fn00913cf6()
{
    if (!gpb628d0_shape10_gzcom) {
        Ref_00913cf6_shape10_gzcom ref;
        ref.Init();
        gpb628d0_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628d0_shape10_gzcom;
}

// GLOBAL: 0xb628d4
extern void* gpb628d4_shape10_gzcom;
struct Ref_00913d22_shape10_gzcom {
    void* mpService;
    // STUB: 0x005d4920
    void Init();
    // STUB: 0x005d4950
    void Done();
};

// FUNCTION: 0x00913d22
void* Fn00913d22()
{
    if (!gpb628d4_shape10_gzcom) {
        Ref_00913d22_shape10_gzcom ref;
        ref.Init();
        gpb628d4_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628d4_shape10_gzcom;
}

// GLOBAL: 0xb628d8
extern void* gpb628d8_shape10_gzcom;
struct Ref_00913d4e_shape10_gzcom {
    void* mpService;
    // STUB: 0x004de430
    void Init();
    // STUB: 0x004de460
    void Done();
};

// FUNCTION: 0x00913d4e
void* Fn00913d4e()
{
    if (!gpb628d8_shape10_gzcom) {
        Ref_00913d4e_shape10_gzcom ref;
        ref.Init();
        gpb628d8_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628d8_shape10_gzcom;
}

struct Elem_0091cb44_shape10_gzcom {
    uint8_t mData[40];
    // STUB: 0x0091c9ec
    void CopyFrom(const Elem_0091cb44_shape10_gzcom& src);
};

// FUNCTION: 0x0091cb44
Elem_0091cb44_shape10_gzcom* Fn0091cb44(Elem_0091cb44_shape10_gzcom* first, Elem_0091cb44_shape10_gzcom* last, Elem_0091cb44_shape10_gzcom* out)
{
    Elem_0091cb44_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct View_009132c1_shape10_gzcom {
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
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Pad16() = 0;
    virtual void Pad17() = 0;
    virtual void Pad18() = 0;
    virtual void Pad19() = 0;
    virtual void Pad20() = 0;
    virtual void Pad21() = 0;
    virtual void Pad22() = 0;
    virtual void Pad23() = 0;
    virtual void Pad24() = 0;
    virtual void Pad25() = 0;
    virtual void Pad26() = 0;
    virtual void Pad27() = 0;
    virtual void Pad28() = 0;
    virtual void Pad29() = 0;
    virtual void Pad30() = 0;
    virtual void Pad31() = 0;
    virtual void Pad32() = 0;
    virtual void Pad33() = 0;
    virtual void Pad34() = 0;
    virtual void Pad35() = 0;
    virtual void Pad36() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn009132c1();
};

// FUNCTION: 0x009132c1
uint32_t View_009132c1_shape10_gzcom::Fn009132c1()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct Elem_0090e4bd_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_0090e4bd_shape10_gzcom {};
// STUB: 0x0090e3f6
Elem_0090e4bd_shape10_gzcom* Copy_0090e4bd_shape10_gzcom(Elem_0090e4bd_shape10_gzcom* first, Elem_0090e4bd_shape10_gzcom* last, Elem_0090e4bd_shape10_gzcom* out, Tag_0090e4bd_shape10_gzcom* tag);

// FUNCTION: 0x0090e4bd
Elem_0090e4bd_shape10_gzcom* Fn0090e4bd(Elem_0090e4bd_shape10_gzcom* first, Elem_0090e4bd_shape10_gzcom* last, Elem_0090e4bd_shape10_gzcom* out)
{
    Tag_0090e4bd_shape10_gzcom tag;
    return Copy_0090e4bd_shape10_gzcom(first, last, out, &tag);
}

struct Elem_0090e63c_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_0090e63c_shape10_gzcom {};
// STUB: 0x004622a0
Elem_0090e63c_shape10_gzcom* Copy_0090e63c_shape10_gzcom(Elem_0090e63c_shape10_gzcom* first, Elem_0090e63c_shape10_gzcom* last, Elem_0090e63c_shape10_gzcom* out, Tag_0090e63c_shape10_gzcom* tag);

// FUNCTION: 0x0090e63c
Elem_0090e63c_shape10_gzcom* Fn0090e63c(Elem_0090e63c_shape10_gzcom* first, Elem_0090e63c_shape10_gzcom* last, Elem_0090e63c_shape10_gzcom* out)
{
    Tag_0090e63c_shape10_gzcom tag;
    return Copy_0090e63c_shape10_gzcom(first, last, out, &tag);
}

struct View_0094578a_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn0094578a(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094578a score 8  (the original lays out the true path before the false one and shares one ret)
bool View_0094578a_shape10_gzcom::Fn0094578a(uint32_t iid, void** ppv)
{
    if (iid == 0x1 || iid == 0x1dd9c9de) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_009457fb_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn009457fb(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009457fb score 8  (the original lays out the true path before the false one and shares one ret)
bool View_009457fb_shape10_gzcom::Fn009457fb(uint32_t iid, void** ppv)
{
    if (iid == 0x1 || iid == 0x5dd9d787) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

// GLOBAL: 0xb63608
extern void* gpb63608_shape10_gzcom;
struct Ref_0096a49e_shape10_gzcom {
    void* mpService;
    // STUB: 0x00411840
    void Init();
    // STUB: 0x00411870
    void Done();
};

// FUNCTION: 0x0096a49e
void* Fn0096a49e()
{
    if (!gpb63608_shape10_gzcom) {
        Ref_0096a49e_shape10_gzcom ref;
        ref.Init();
        gpb63608_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb63608_shape10_gzcom;
}

struct View_00968b3b_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn00968b3b(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00968b3b score 8  (the original lays out the true path before the false one and shares one ret)
bool View_00968b3b_shape10_gzcom::Fn00968b3b(uint32_t iid, void** ppv)
{
    if (iid == 0x1b3637c6 || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_00969f0c_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn00969f0c(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x00969f0c score 8  (the original lays out the true path before the false one and shares one ret)
bool View_00969f0c_shape10_gzcom::Fn00969f0c(uint32_t iid, void** ppv)
{
    if (iid == 0x1 || iid == 0x5d4c6b90) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_0096ad83_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn0096ad83(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0096ad83 score 8  (the original lays out the true path before the false one and shares one ret)
bool View_0096ad83_shape10_gzcom::Fn0096ad83(uint32_t iid, void** ppv)
{
    if (iid == 0x1 || iid == 0x3afd825f) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_0094392e_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn0094392e(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094392e score 8  (the original lays out the true path before the false one and shares one ret)
bool View_0094392e_shape10_gzcom::Fn0094392e(uint32_t iid, void** ppv)
{
    if (iid == 0x1 || iid == 0xdb1acfb2) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

// GLOBAL: 0xb633bc
extern void* gpb633bc_shape10_gzcom;
struct Ref_0093af7e_shape10_gzcom {
    void* mpService;
    // STUB: 0x00411840
    void Init();
    // STUB: 0x00411870
    void Done();
};

// FUNCTION: 0x0093af7e
void* Fn0093af7e()
{
    if (!gpb633bc_shape10_gzcom) {
        Ref_0093af7e_shape10_gzcom ref;
        ref.Init();
        gpb633bc_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb633bc_shape10_gzcom;
}


struct Elem_008d50b2_shape10_gzcom {
    uint8_t mData[44];
    // STUB: 0x008d3c38
    void CopyFrom(const Elem_008d50b2_shape10_gzcom& src);
};

// FUNCTION: 0x008d50b2
Elem_008d50b2_shape10_gzcom* Fn008d50b2(Elem_008d50b2_shape10_gzcom* first, Elem_008d50b2_shape10_gzcom* last, Elem_008d50b2_shape10_gzcom* out)
{
    Elem_008d50b2_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct View_00891c72_shape10_gzcom {
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
    virtual void Pad13() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn00891c72();
};

// FUNCTION: 0x00891c72
uint32_t View_00891c72_shape10_gzcom::Fn00891c72()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_00891e08_shape10_gzcom {
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
    virtual void Pad13() = 0;
    virtual void Pad14() = 0;
    virtual void Pad15() = 0;
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnPad4;
    uint32_t mnRefs;
    uint32_t Fn00891e08();
};

// FUNCTION: 0x00891e08
uint32_t View_00891e08_shape10_gzcom::Fn00891e08()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

