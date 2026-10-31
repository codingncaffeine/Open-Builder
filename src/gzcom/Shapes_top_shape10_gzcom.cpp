#include "common/types.h"

struct Elem_008750f7_top_shape10_gzcom {
    uint8_t mData[44];
    // STUB: 0x008750ae
    void CopyFrom(const Elem_008750f7_top_shape10_gzcom& src);
};

// FUNCTION: 0x008750f7
Elem_008750f7_top_shape10_gzcom* Fn008750f7(Elem_008750f7_top_shape10_gzcom* first, Elem_008750f7_top_shape10_gzcom* last, Elem_008750f7_top_shape10_gzcom* out)
{
    Elem_008750f7_top_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct View_00875287_top_shape10_gzcom {
    uint8_t mPad[116];
    uint32_t mnValue;
    uint32_t Fn00875287();
};

// FUNCTION: 0x00875287
uint32_t View_00875287_top_shape10_gzcom::Fn00875287()
{
    return mnValue;
}



struct View_008fe5f9_top_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x0090847a
    void Base(uint32_t type);
    View_008fe5f9_top_shape10_gzcom* Fn008fe5f9();
};

// FUNCTION: 0x008fe5f9
View_008fe5f9_top_shape10_gzcom* View_008fe5f9_top_shape10_gzcom::Fn008fe5f9()
{
    Base(0x16);
    mnVtable = 0xacd530;
    return this;
}

struct View_008fe63a_top_shape10_gzcom {
    uint32_t mnVtable;
    // STUB: 0x0090847a
    void Base(uint32_t type);
    View_008fe63a_top_shape10_gzcom* Fn008fe63a();
};

// FUNCTION: 0x008fe63a
View_008fe63a_top_shape10_gzcom* View_008fe63a_top_shape10_gzcom::Fn008fe63a()
{
    Base(0x1d);
    mnVtable = 0xacd588;
    return this;
}

struct View_0090d9ae_top_shape10_gzcom {
    virtual void Pad0() = 0;
    virtual void AddRef() = 0;
    bool Fn0090d9ae(uint32_t iid, void** ppv);
};

#ifdef OB_DRAFTS
// CLOSE: 0x0090d9ae score 8  (the original lays out the true path before the false one and shares one ret)
bool View_0090d9ae_top_shape10_gzcom::Fn0090d9ae(uint32_t iid, void** ppv)
{
    if (iid == 0x12e || iid == 0x1) {
        *ppv = this;
        AddRef();
        return true;
    }
    return false;
}
#endif

struct View_0090d9d3_top_shape10_gzcom {
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
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnPad4;
    uint32_t mnRefs;
    uint32_t Fn0090d9d3();
};

// FUNCTION: 0x0090d9d3
uint32_t View_0090d9d3_top_shape10_gzcom::Fn0090d9d3()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

// GLOBAL: 0xb628dc
extern void* gpb628dc_top_shape10_gzcom;
struct Ref_00913d7a_top_shape10_gzcom {
    void* mpService;
    // STUB: 0x00610800
    void Init();
    // STUB: 0x00610830
    void Done();
};

// FUNCTION: 0x00913d7a
void* Fn00913d7a()
{
    if (!gpb628dc_top_shape10_gzcom) {
        Ref_00913d7a_top_shape10_gzcom ref;
        ref.Init();
        gpb628dc_top_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb628dc_top_shape10_gzcom;
}

struct Elem_0091e782_top_shape10_gzcom {
    uint8_t mData[48];
    // STUB: 0x0091e618
    void CopyFrom(const Elem_0091e782_top_shape10_gzcom& src);
};

// FUNCTION: 0x0091e782
Elem_0091e782_top_shape10_gzcom* Fn0091e782(Elem_0091e782_top_shape10_gzcom* first, Elem_0091e782_top_shape10_gzcom* last, Elem_0091e782_top_shape10_gzcom* out)
{
    Elem_0091e782_top_shape10_gzcom* cur = out;
    for (; first != last; ++first, ++cur) {
        if (cur) {
            cur->CopyFrom(*first);
        }
    }
    return cur;
}

struct View_0092b2c8_top_shape10_gzcom {
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
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn0092b2c8();
};

// FUNCTION: 0x0092b2c8
uint32_t View_0092b2c8_top_shape10_gzcom::Fn0092b2c8()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}



// GLOBAL: 0xb63308
extern void* gpb63308_top_shape10_gzcom;
struct Ref_00933ce3_top_shape10_gzcom {
    void* mpService;
    // STUB: 0x00411840
    void Init();
    // STUB: 0x00411870
    void Done();
};

// FUNCTION: 0x00933ce3
void* Fn00933ce3()
{
    if (!gpb63308_top_shape10_gzcom) {
        Ref_00933ce3_top_shape10_gzcom ref;
        ref.Init();
        gpb63308_top_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb63308_top_shape10_gzcom;
}

// GLOBAL: 0xb6330c
extern void* gpb6330c_top_shape10_gzcom;
struct Ref_00933d0f_top_shape10_gzcom {
    void* mpService;
    // STUB: 0x00411840
    void Init();
    // STUB: 0x00411870
    void Done();
};

// FUNCTION: 0x00933d0f
void* Fn00933d0f()
{
    if (!gpb6330c_top_shape10_gzcom) {
        Ref_00933d0f_top_shape10_gzcom ref;
        ref.Init();
        gpb6330c_top_shape10_gzcom = ref.mpService;
        ref.Done();
    }
    return gpb6330c_top_shape10_gzcom;
}


struct View_0094a5e3_top_shape10_gzcom {
    uint8_t mPad[4352];
    uint32_t mnValue;
    uint32_t Fn0094a5e3();
};

// FUNCTION: 0x0094a5e3
uint32_t View_0094a5e3_top_shape10_gzcom::Fn0094a5e3()
{
    return mnValue;
}


struct View_0094bc46_top_shape10_gzcom {
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
    uint32_t mnPad4;
    uint32_t mnPad8;
    uint32_t mnPad12;
    uint32_t mnPad16;
    uint32_t mnPad20;
    uint32_t mnPad24;
    uint32_t mnPad28;
    uint32_t mnRefs;
    uint32_t Fn0094bc46();
};

// FUNCTION: 0x0094bc46
uint32_t View_0094bc46_top_shape10_gzcom::Fn0094bc46()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_00966919_top_shape10_gzcom {
    uint8_t mPad[224];
    uint32_t mnValue;
    uint32_t Fn00966919();
};

// FUNCTION: 0x00966919
uint32_t View_00966919_top_shape10_gzcom::Fn00966919()
{
    return mnValue;
}

struct View_009683d9_top_shape10_gzcom {
    uint8_t mPad[216];
    uint32_t mnValue;
    uint32_t Fn009683d9();
};

// FUNCTION: 0x009683d9
uint32_t View_009683d9_top_shape10_gzcom::Fn009683d9()
{
    return mnValue;
}

struct View_009944f2_top_shape10_gzcom {
    uint8_t mPad[232];
    uint32_t mnValue;
    uint32_t Fn009944f2();
};

// FUNCTION: 0x009944f2
uint32_t View_009944f2_top_shape10_gzcom::Fn009944f2()
{
    return mnValue;
}

struct View_00995dc6_top_shape10_gzcom {
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
    virtual void Destroy(uint32_t flag) = 0;
    uint32_t mnRefs;
    uint32_t Fn00995dc6();
};

// FUNCTION: 0x00995dc6
uint32_t View_00995dc6_top_shape10_gzcom::Fn00995dc6()
{
    if (mnRefs > 1) {
        return --mnRefs;
    }
    Destroy(1);
    return 0;
}

struct View_009a03b8_top_shape10_gzcom {
    uint8_t mPad[568];
    uint32_t mnValue;
    uint32_t Fn009a03b8();
};

// FUNCTION: 0x009a03b8
uint32_t View_009a03b8_top_shape10_gzcom::Fn009a03b8()
{
    return mnValue;
}

struct View_009a0465_top_shape10_gzcom {
    uint8_t mPad[604];
    uint32_t mnValue;
    uint32_t Fn009a0465();
};

// FUNCTION: 0x009a0465
uint32_t View_009a0465_top_shape10_gzcom::Fn009a0465()
{
    return mnValue;
}

struct View_009a0512_top_shape10_gzcom {
    uint8_t mPad[676];
    uint32_t mnValue;
    uint32_t Fn009a0512();
};

// FUNCTION: 0x009a0512
uint32_t View_009a0512_top_shape10_gzcom::Fn009a0512()
{
    return mnValue;
}

struct View_009a072a_top_shape10_gzcom {
    uint8_t mPad[712];
    uint32_t mnValue;
    uint32_t Fn009a072a();
};

// FUNCTION: 0x009a072a
uint32_t View_009a072a_top_shape10_gzcom::Fn009a072a()
{
    return mnValue;
}

struct View_009a0871_top_shape10_gzcom {
    uint8_t mPad[784];
    uint32_t mnValue;
    uint32_t Fn009a0871();
};

// FUNCTION: 0x009a0871
uint32_t View_009a0871_top_shape10_gzcom::Fn009a0871()
{
    return mnValue;
}

struct View_009a6333_top_shape10_gzcom {
    uint8_t mPad[520];
    uint32_t mnValue;
    uint32_t Fn009a6333();
};

// FUNCTION: 0x009a6333
uint32_t View_009a6333_top_shape10_gzcom::Fn009a6333()
{
    return mnValue;
}

struct View_009a6d43_top_shape10_gzcom {
    uint8_t mPad[616];
    uint32_t mnValue;
    uint32_t Fn009a6d43();
};

// FUNCTION: 0x009a6d43
uint32_t View_009a6d43_top_shape10_gzcom::Fn009a6d43()
{
    return mnValue;
}

struct Elem_009caec4_top_shape10_gzcom {
    uint32_t mnData;
};
struct Tag_009caec4_top_shape10_gzcom {};
// STUB: 0x009cac1d
Elem_009caec4_top_shape10_gzcom* Copy_009caec4_top_shape10_gzcom(Elem_009caec4_top_shape10_gzcom* first, Elem_009caec4_top_shape10_gzcom* last, Elem_009caec4_top_shape10_gzcom* out, Tag_009caec4_top_shape10_gzcom* tag);

// FUNCTION: 0x009caec4
Elem_009caec4_top_shape10_gzcom* Fn009caec4(Elem_009caec4_top_shape10_gzcom* first, Elem_009caec4_top_shape10_gzcom* last, Elem_009caec4_top_shape10_gzcom* out)
{
    Tag_009caec4_top_shape10_gzcom tag;
    return Copy_009caec4_top_shape10_gzcom(first, last, out, &tag);
}

struct View_009cfc0c_top_shape10_gzcom {
    uint8_t mPad[384];
    uint32_t mnValue;
    uint32_t Fn009cfc0c();
};

// FUNCTION: 0x009cfc0c
uint32_t View_009cfc0c_top_shape10_gzcom::Fn009cfc0c()
{
    return mnValue;
}

