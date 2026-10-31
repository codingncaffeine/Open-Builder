#include "classes/cSC4BudgetSimulator.h"
#include "classes/cSC4DepartmentBudget.h"
#include "game/Globals.h"

#include <math.h>
#include <vector>

// One of the twelve per-tax-type rows at +0x70 (0x80 bytes each).
struct TaxRow_ab0908 {
    float mfRate;
    uint8_t mPad0[0x6c];
    int64_t mnWeightedAssessed;
    uint8_t mPad1[8];
};

// A node of the loan list at +0x780 (the head node is reached through the pointer).
struct LoanNode_ab0908 {
    LoanNode_ab0908* mpNext;
    LoanNode_ab0908* mpPrev;
    uint8_t mPad[0x28];
    int64_t mnMonthlyPayment;
};

// A department budget reached through a pointer (never constructed here); slots as far as this file calls them.
struct OB_NOVTABLE DeptView_ab0908 {
    virtual void Fn0() = 0;
    virtual void Fn1() = 0;
    virtual void Fn2() = 0;
    virtual void Fn3() = 0;
    virtual void Fn4() = 0;
    virtual void Fn5() = 0;
    virtual uint32_t GetBudgetGroup() = 0;
    virtual void Fn7() = 0;
    virtual void Fn8() = 0;
    virtual void Fn9() = 0;
    virtual void Fn10() = 0;
    virtual void Fn11() = 0;
    virtual void Fn12() = 0;
    virtual void Fn13() = 0;
    virtual void Fn14() = 0;
    virtual int64_t GetTotalExpenses() = 0;
    virtual void Fn16() = 0;
    virtual void Fn17() = 0;
    virtual void Fn18() = 0;
    virtual void Fn19() = 0;
    virtual void* GetLineItem(uint32_t) = 0;
};

// FUNCTION: 0x0068fd10
int64_t cSC4BudgetSimulator::GetTotalFunds()
{
    return mnTotalFunds;
}

// FUNCTION: 0x0068fd20
int64_t cSC4BudgetSimulator::GetMinAllowableFunds()
{
    return mnMinAllowableFunds;
}

// FUNCTION: 0x0068fd30
int64_t cSC4BudgetSimulator::GetTaxIncome_2()
{
    return mnTaxIncome;
}

// FUNCTION: 0x0068fd40
int64_t cSC4BudgetSimulator::GetFunding_2(uint32_t)
{
    return 0;
}

// FUNCTION: 0x0068fd90
int64_t cSC4BudgetSimulator::GetBondIncrement()
{
    return mnBondIncrement;
}

// FUNCTION: 0x0068fdc0
int64_t cSC4BudgetSimulator::GetCurrentBondLimit()
{
    return mnCurrentBondLimit;
}

// FUNCTION: 0x0068fdd0
int64_t cSC4BudgetSimulator::GetCurrentMaxOutstandingBondsLimit()
{
    return mnMaxOutstandingBonds;
}

// FUNCTION: 0x00694260
int64_t cSC4BudgetSimulator::GetTotalYearlyExpense()
{
    return mnYearlyExpense;
}

// FUNCTION: 0x00694270
int64_t cSC4BudgetSimulator::GetTotalYearlyIncome()
{
    return mnYearlyIncome;
}

// FUNCTION: 0x00694280
void cSC4BudgetSimulator::SetTotalMonthlyExpense(int64_t v)
{
    mnMonthlyExpense = v;
}

// FUNCTION: 0x006942a0
void cSC4BudgetSimulator::SetTotalYearlyExpense(int64_t v)
{
    mnYearlyExpense = v;
}

// FUNCTION: 0x006942c0
void cSC4BudgetSimulator::SetTotalMonthlyIncome(int64_t v)
{
    mnMonthlyIncome = v;
}

// FUNCTION: 0x006942e0
void cSC4BudgetSimulator::SetTotalYearlyIncome(int64_t v)
{
    mnYearlyIncome = v;
}

// FUNCTION: 0x0068fd70
void cSC4BudgetSimulator::SetTaxRate(int32_t type, float rate)
{
    if (type < 12) {
        reinterpret_cast<TaxRow_ab0908*>(mDeptRows)[type].mfRate = rate;
    }
}

// FUNCTION: 0x0068fd50
float cSC4BudgetSimulator::GetTaxRate(int32_t type)
{
    if (type < 12) {
        return reinterpret_cast<TaxRow_ab0908*>(mDeptRows)[type].mfRate;
    }
    return 0.0f;
}

// FUNCTION: 0x00691030
void cSC4BudgetSimulator::FundingPercentageChanged(void* pDept)
{
    if (pDept) {
        DoBudgetGroupChanged(static_cast<DeptView_ab0908*>(pDept)->GetBudgetGroup());
    }
}

// FUNCTION: 0x0068fda0
int64_t cSC4BudgetSimulator::GetCurrentBorrowingLimit()
{
    return static_cast<int64_t>(mnMaxOutstandingBonds) * mnCurrentBondLimit;
}

// FUNCTION: 0x0068fde0
int64_t cSC4BudgetSimulator::GetWeightedAssessedTaxValue(int32_t type)
{
    if (type < 12) {
        return reinterpret_cast<TaxRow_ab0908*>(mDeptRows)[type].mnWeightedAssessed;
    }
    return 0;
}

// FUNCTION: 0x00690500
int64_t cSC4BudgetSimulator::GetTotalMonthlyBondPayments()
{
    LoanNode_ab0908* head = static_cast<LoanNode_ab0908*>(mpLoanList);
    int64_t total = 0;
    for (LoanNode_ab0908* n = head->mpNext; n != head; n = n->mpNext) {
        total += n->mnMonthlyPayment;
    }
    return total;
}

// FUNCTION: 0x0068ff80
void* cSC4BudgetSimulator::GetLineItemFromBudgetItem(void* pItem)
{
    uint32_t* item = static_cast<uint32_t*>(pItem);
    DeptView_ab0908* dept = static_cast<DeptView_ab0908*>(GetDepartmentBudget_2(item[0]));
    if (dept) {
        return dept->GetLineItem(item[1]);
    }
    return 0;
}

// FUNCTION: 0x006900c0
uint32_t cSC4BudgetSimulator::Slot02_ab0908()
{
    if (mnRefCount > 1) {
        return --mnRefCount;
    }
    Shutdown();
    delete this;
    return 0;
}

// FUNCTION: 0x00690140
void cSC4BudgetSimulator::SetTotalFunds(int64_t v)
{
    if (mnTotalFunds != v) {
        mnTotalFunds = v;
        mnPreviousFunds = v;
        PostFundsChangedMessage();
    }
}

// The environment object at +0x18; only its slot 24 (the difficulty level) is called here.
struct OB_NOVTABLE EnvView_ab0908 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0; virtual void Pad06() = 0; virtual void Pad07() = 0;
    virtual void Pad08() = 0; virtual void Pad09() = 0; virtual void Pad10() = 0; virtual void Pad11() = 0;
    virtual void Pad12() = 0; virtual void Pad13() = 0; virtual void Pad14() = 0; virtual void Pad15() = 0;
    virtual void Pad16() = 0; virtual void Pad17() = 0; virtual void Pad18() = 0; virtual void Pad19() = 0;
    virtual void Pad20() = 0; virtual void Pad21() = 0; virtual void Pad22() = 0; virtual void Pad23() = 0;
    virtual uint32_t GetDifficulty() = 0;
};

// STUB: 0x009133da
void* Fn009133da(uint32_t size);

// The 0x2c-byte message object (the allocator and constructor are the original's; no virtuals of ours).
struct MsgObj_ab0908 {
    uint8_t mData[0x2c];
    // STUB: 0x009134d6
    MsgObj_ab0908();
    static void* operator new(size_t size) { return Fn009133da(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// The same object through its vtable slots.
struct OB_NOVTABLE MsgView_ab0908 {
    virtual void Pad00() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void Pad03() = 0;
    virtual void Pad04() = 0;
    virtual void SetType(uint32_t) = 0;
    virtual void Pad06() = 0; virtual void Pad07() = 0; virtual void Pad08() = 0; virtual void Pad09() = 0;
    virtual void Pad10() = 0; virtual void Pad11() = 0;
    virtual void SetVoid1(void*) = 0;
    virtual void Pad13() = 0; virtual void Pad14() = 0; virtual void Pad15() = 0; virtual void Pad16() = 0;
    virtual void Pad17() = 0; virtual void Pad18() = 0; virtual void Pad19() = 0; virtual void Pad20() = 0;
    virtual void Pad21() = 0; virtual void Pad22() = 0; virtual void Pad23() = 0; virtual void Pad24() = 0;
    virtual void Pad25() = 0; virtual void Pad26() = 0; virtual void Pad27() = 0; virtual void Pad28() = 0;
    virtual void Pad29() = 0; virtual void Pad30() = 0; virtual void Pad31() = 0; virtual void Pad32() = 0;
    virtual void SetUnknown(void*) = 0;
};

// A node of the department map's tree (links, then the key and the department).
struct DeptNode_ab0908 {
    uint8_t mPad[0x10];
    uint32_t mnKey;
    void* mpDepartment;
};

// The department map (a red-black tree), seen from its header pointer.
struct DeptTree_ab0908 {
    DeptNode_ab0908* mpHeader;
    // STUB: 0x00497520
    void Fn00497520(DeptNode_ab0908** pResult, const uint32_t* pKey);
};

// Any object with AddRef in slot 1 and Release in slot 2.
struct OB_NOVTABLE RefView_ab0908 {
    virtual void Pad00() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

// The window procedures ShowBudgetWindow creates (constructors are the original's).
struct ExpenseWinProc_ab0908 {
    uint8_t mData[0x28];
    // STUB: 0x007638e0
    ExpenseWinProc_ab0908();
};
struct IncomeWinProc_ab0908 {
    uint8_t mData[0x60];
    // STUB: 0x00764030
    IncomeWinProc_ab0908();
};

static const int64_t kMaxFunds_ab0908 = (static_cast<int64_t>(0x7fffffff) << 32) | 0xffffffffu;

// FUNCTION: 0x00691000
void* cSC4BudgetSimulator::GetDepartmentBudget_2(uint32_t id)
{
    DeptTree_ab0908* tree = reinterpret_cast<DeptTree_ab0908*>(reinterpret_cast<char*>(this) + 0x54);
    DeptNode_ab0908* found;
    tree->Fn00497520(&found, &id);
    if (found != tree->mpHeader) {
        return found->mpDepartment;
    }
    return 0;
}

// FUNCTION: 0x0068ff50
int64_t cSC4BudgetSimulator::GetFullCostOfLoan(int64_t principal)
{
    return GetMonthlyPaymentForLoan(principal) * static_cast<int64_t>(mnLoanTimeInMonths);
}

// FUNCTION: 0x0068fef0
int64_t cSC4BudgetSimulator::GetMonthlyPaymentForLoan(int64_t principal)
{
    double monthly = mfLoanInterest * (1.0 / 12.0);
    double growth = pow(monthly + 1.0, -static_cast<double>(mnLoanTimeInMonths));
    return static_cast<int64_t>(static_cast<double>(principal) * monthly / (1.0 - growth));
}

#ifdef OB_DRAFTS
// CLOSE: 0x00690170 score 62
bool cSC4BudgetSimulator::DepositFunds(int64_t value)
{
    if (value <= 0) {
        if (value >= 0) {
            return true;
        }
        return WithdrawFunds(-value);
    }
    int64_t current = mnTotalFunds;
    if (current < 0 || value < kMaxFunds_ab0908 - current) {
        mnTotalFunds = current + value;
    } else {
        mnTotalFunds = kMaxFunds_ab0908;
    }
    mnPreviousFunds = mnTotalFunds;
    PostFundsChangedMessage();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00690200 score 54
bool cSC4BudgetSimulator::WithdrawFunds(int64_t value)
{
    if (value <= 0) {
        if (value >= 0) {
            return true;
        }
        return DepositFunds(-value);
    }
    int64_t current = mnTotalFunds;
    if (current < value) {
        return false;
    }
    mnTotalFunds = current - value;
    mnPreviousFunds = mnTotalFunds;
    PostFundsChangedMessage();
    return true;
}
#endif

// FUNCTION: 0x0068fe10
void cSC4BudgetSimulator::PostFundsChangedMessage()
{
    if (mpMessageServer) {
        MsgView_ab0908* m = reinterpret_cast<MsgView_ab0908*>(new MsgObj_ab0908());
        m->AddRef();
        m->SetType(0x772fad4);
        m->SetVoid1(this);
        m->SetUnknown(this);
        static_cast<cIGZMessageServer2*>(mpMessageServer)->MessagePost(m, false);
        m->Release();
    }
}

// FUNCTION: 0x0068fe80
void cSC4BudgetSimulator::PostSimMessage(uint32_t type)
{
    if (mpMessageServer) {
        MsgView_ab0908* m = reinterpret_cast<MsgView_ab0908*>(new MsgObj_ab0908());
        m->AddRef();
        m->SetType(type);
        m->SetVoid1(this);
        m->SetUnknown(this);
        static_cast<cIGZMessageServer2*>(mpMessageServer)->MessagePost(m, false);
        m->Release();
    }
}

// FUNCTION: 0x00690450
void cSC4BudgetSimulator::ResetFundsToStartingLevel()
{
    uint32_t level = static_cast<EnvView_ab0908*>(mpEnvironment)->GetDifficulty();
    int64_t* p = static_cast<int64_t*>(mpMonthFunds) + level;
    mnTotalFunds = *p;
    mnPreviousFunds = *p;
    PostFundsChangedMessage();
}

// FUNCTION: 0x00690490
void cSC4BudgetSimulator::ReadDifficultyTaxRates()
{
    TaxRow_ab0908* row = reinterpret_cast<TaxRow_ab0908*>(mDeptRows);
    for (int32_t i = 12; i != 0; --i) {
        row->mfRate = mpDifficultyTaxRates[static_cast<EnvView_ab0908*>(mpEnvironment)->GetDifficulty()];
        ++row;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x006904c0 score 4
int64_t cSC4BudgetSimulator::GetTaxIncome(int32_t type)
{
    uint32_t level = static_cast<EnvView_ab0908*>(mpEnvironment)->GetDifficulty();
    TaxRow_ab0908* rows = reinterpret_cast<TaxRow_ab0908*>(mDeptRows);
    return static_cast<int64_t>(static_cast<float>(rows[type].mnWeightedAssessed) * mpTaxFactors[level] * rows[type].mfRate * (1.0f / 1200.0f));
}
#endif

// FUNCTION: 0x00690330
void cSC4BudgetSimulator::ShowBudgetWindow()
{
    if (mbExpenseWindow) {
        RefView_ab0908* w = reinterpret_cast<RefView_ab0908*>(new ExpenseWinProc_ab0908());
        if (w) {
            w->AddRef();
            w->Release();
        }
    } else {
        RefView_ab0908* w = reinterpret_cast<RefView_ab0908*>(new IncomeWinProc_ab0908());
        if (w) {
            w->AddRef();
            w->Release();
        }
    }
}

// A node of the red-black trees (STLport): colour, parent, left, right, then the key and the value.
struct TreeNode_ab0908 {
    uint32_t mnColor;
    TreeNode_ab0908* mpParent;
    TreeNode_ab0908* mpLeft;
    TreeNode_ab0908* mpRight;
    uint32_t mnKey;
    void* mpValue;
};

// The ordinance simulator at +0x24: only the slots the budget reads.
struct OB_NOVTABLE OrdinanceView_ab0908 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0; virtual void Pad06() = 0; virtual void Pad07() = 0;
    virtual void Pad08() = 0; virtual void Pad09() = 0; virtual void Pad10() = 0; virtual void Pad11() = 0;
    virtual void Pad12() = 0; virtual void Pad13() = 0; virtual void Pad14() = 0; virtual void Pad15() = 0;
    virtual void Pad16() = 0; virtual void Pad17() = 0; virtual void Pad18() = 0; virtual void Pad19() = 0;
    virtual void Pad20() = 0; virtual void Pad21() = 0;
    virtual int64_t GetMonthlyExpense() = 0;
    virtual int64_t GetMonthlyIncome() = 0;
};

// The neighbours simulator (a global): only the slots the budget reads.
struct OB_NOVTABLE NeighborsView_ab0908 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0; virtual void Pad06() = 0; virtual void Pad07() = 0;
    virtual void Pad08() = 0; virtual void Pad09() = 0; virtual void Pad10() = 0; virtual void Pad11() = 0;
    virtual void Pad12() = 0; virtual void Pad13() = 0; virtual void Pad14() = 0; virtual void Pad15() = 0;
    virtual void Pad16() = 0; virtual void Pad17() = 0; virtual void Pad18() = 0; virtual void Pad19() = 0;
    virtual void Pad20() = 0; virtual void Pad21() = 0; virtual void Pad22() = 0; virtual void Pad23() = 0;
    virtual void Pad24() = 0; virtual void Pad25() = 0; virtual void Pad26() = 0; virtual void Pad27() = 0;
    virtual void Pad28() = 0; virtual void Pad29() = 0; virtual void Pad30() = 0; virtual void Pad31() = 0;
    virtual int64_t GetIncome() = 0;
    virtual int64_t GetExpense() = 0;
};

// GLOBAL: 0x00b43d8c
extern NeighborsView_ab0908* gpB43d8c;

// A line item reached through a pointer; only the slot that adds to its expenses.
struct OB_NOVTABLE LineItemView_ab0908 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0; virtual void Pad06() = 0; virtual void Pad07() = 0;
    virtual void Pad08() = 0; virtual void Pad09() = 0; virtual void Pad10() = 0; virtual void Pad11() = 0;
    virtual void Pad12() = 0;
    virtual void AddToExpenses(int64_t) = 0;
};

// One entry of the list GetBudgetItemInfo fills (0x20 bytes).
struct BudgetItem_ab0908 {
    uint32_t mnDepartment;
    uint32_t mnLineItem;
    uint32_t mnPurpose;
    uint32_t mnUnknownC;
    int64_t mnCost;
    uint32_t mUnknown18[2];
};

// The vector of budget items (three pointers; the storage is freed with the STL's deleter).
struct ItemList_ab0908 {
    BudgetItem_ab0908* mpBegin;
    BudgetItem_ab0908* mpEnd;
    BudgetItem_ab0908* mpCap;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00690990 score 57
int64_t cSC4BudgetSimulator::GetTotalMonthlyExpense()
{
    int64_t total = static_cast<OrdinanceView_ab0908*>(mpOrdinanceSim)->GetMonthlyExpense();
    total += gpB43d8c->GetExpense();
    TreeNode_ab0908* header = static_cast<TreeNode_ab0908*>(mpDeptTreeHeader);
    for (TreeNode_ab0908* n = header->mpLeft; n != header; ) {
        total += static_cast<DeptView_ab0908*>(n->mpValue)->GetTotalExpenses();
        if (n->mpRight) {
            n = n->mpRight;
            while (n->mpLeft) {
                n = n->mpLeft;
            }
        } else {
            TreeNode_ab0908* parent = n->mpParent;
            while (n == parent->mpRight) {
                n = parent;
                parent = parent->mpParent;
            }
            if (n->mpRight != parent) {
                n = parent;
            }
        }
    }
    LoanNode_ab0908* loans = static_cast<LoanNode_ab0908*>(mpLoanList);
    for (LoanNode_ab0908* l = loans->mpNext; l != loans; l = l->mpNext) {
        total += l->mnMonthlyPayment;
    }
    return total;
}
#endif

// FUNCTION: 0x00691880
bool cSC4BudgetSimulator::GetBudgetItemForPurpose(void* holder, uint32_t purpose, void* pItem)
{
    std::vector<BudgetItem_ab0908> items;
    if (GetBudgetItemInfo(holder, &items)) {
        for (BudgetItem_ab0908* p = &*items.begin(); p != &*items.end(); ++p) {
            if (p->mnPurpose == purpose) {
                *static_cast<BudgetItem_ab0908*>(pItem) = *p;
                return true;
            }
        }
    }
    return false;
}

// FUNCTION: 0x00691910
void cSC4BudgetSimulator::AddBudgetItemToBudget(void* holder, uint32_t purpose)
{
    std::vector<BudgetItem_ab0908> items;
    if (GetBudgetItemInfo(holder, &items)) {
        if (purpose < items.size()) {
            BudgetItem_ab0908* item = &items[purpose];
            DeptView_ab0908* dept = static_cast<DeptView_ab0908*>(GetDepartmentBudget_2(item->mnDepartment));
            if (dept) {
                LineItemView_ab0908* line = static_cast<LineItemView_ab0908*>(dept->GetLineItem(item->mnLineItem));
                if (line) {
                    line->AddToExpenses(item->mnCost);
                }
            }
        }
    }
}

// FUNCTION: 0x006919b0
void cSC4BudgetSimulator::RemoveBudgetItemFromBudget(void* holder, uint32_t purpose)
{
    std::vector<BudgetItem_ab0908> items;
    if (GetBudgetItemInfo(holder, &items)) {
        if (purpose < items.size()) {
            BudgetItem_ab0908* item = &items[purpose];
            DeptView_ab0908* dept = static_cast<DeptView_ab0908*>(GetDepartmentBudget_2(item->mnDepartment));
            if (dept) {
                LineItemView_ab0908* line = static_cast<LineItemView_ab0908*>(dept->GetLineItem(item->mnLineItem));
                if (line) {
                    line->AddToExpenses(-item->mnCost);
                }
            }
        }
    }
}

// A property holder reached through a pointer; only the slot that stores a property object.
struct OB_NOVTABLE HolderView_ab0908 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0; virtual void Pad06() = 0; virtual void Pad07() = 0;
    virtual void Pad08() = 0; virtual void Pad09() = 0; virtual void Pad10() = 0; virtual void Pad11() = 0;
    virtual void Pad12() = 0; virtual void Pad13() = 0; virtual void Pad14() = 0;
    virtual void SetProperty(void* pProperty, bool bFlag) = 0;
};

// STUB: 0x005fd840
void* Fn005fd840(uint32_t size);

// A 0x1c-byte property object (allocator and constructor are the original's).
struct PropObj_ab0908 {
    uint8_t mData[0x1c];
    // STUB: 0x005fde50
    PropObj_ab0908(uint32_t id);
    static void* operator new(size_t size) { return Fn005fd840(static_cast<uint32_t>(size)); }
    static void operator delete(void*) {}
};

// STUB: 0x005ff510
bool Fn005ff510(void* holder, uint32_t id, void* pVec);
// STUB: 0x005fe6b0
void Fn005fe6b0(void* holder, uint32_t id, void* pVec);
// STUB: 0x005ffd80
bool Fn005ffd80(void* holder, uint32_t id, void* pVec);
// STUB: 0x005fe7f0
void Fn005fe7f0(void* holder, uint32_t id, void* pVec);
// STUB: 0x005ffcc0
bool Fn005ffcc0(void* holder, uint32_t id, void* pVec);
// STUB: 0x005fe750
void Fn005fe750(void* holder, uint32_t id, void* pVec);

#ifdef OB_DRAFTS
// CLOSE: 0x00691050 score 4
void cSC4BudgetSimulator::ChangeBudgetItemLine(void* holder, uint32_t purpose, uint32_t lineItem)
{
    std::vector<uint32_t> lines;
    Fn005ff510(holder, 0xea54d284, &lines);
    if (purpose < lines.size()) {
        lines[purpose] = lineItem;
        PropObj_ab0908* prop = new PropObj_ab0908(0xea54d284);
        static_cast<HolderView_ab0908*>(holder)->SetProperty(prop, false);
        Fn005fe6b0(holder, 0xea54d284, &lines);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00691100 score 24
void cSC4BudgetSimulator::ChangeBudgetItemCost(void* holder, uint32_t purpose, int64_t cost)
{
    std::vector<int64_t> costs;
    Fn005ffd80(holder, 0xea54d286, &costs);
    if (purpose < costs.size()) {
        costs[purpose] = cost;
        PropObj_ab0908* prop = new PropObj_ab0908(0xea54d286);
        static_cast<HolderView_ab0908*>(holder)->SetProperty(prop, false);
        Fn005fe7f0(holder, 0xea54d286, &costs);
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00692d50 score 13
void cSC4BudgetSimulator::ChangeBudgetItemLocalFunding(void* holder, uint32_t purpose, float funding)
{
    std::vector<float> values;
    Fn005ffcc0(holder, 0xea54d287, &values);
    if (purpose >= values.size()) {
        values.resize(purpose + 1, 0.0f);
    }
    values[purpose] = funding * 100.0f;
    PropObj_ab0908* prop = new PropObj_ab0908(0xea54d287);
    static_cast<HolderView_ab0908*>(holder)->SetProperty(prop, false);
    Fn005fe750(holder, 0xea54d287, &values);
}
#endif

// The simulator (a global): only the slot that reads the date.
struct OB_NOVTABLE SimulatorView_ab0908 {
    virtual void Pad00() = 0; virtual void Pad01() = 0; virtual void Pad02() = 0; virtual void Pad03() = 0;
    virtual void Pad04() = 0; virtual void Pad05() = 0;
    virtual void GetDate(int32_t* pYear, int32_t* pMonth, uint32_t, uint32_t, uint32_t) = 0;
};

// GLOBAL: 0x00b43d5c
extern SimulatorView_ab0908* gpB43d5c;

// One loan as the budget window wants it (0x20 bytes).
struct LoanInfo_ab0908 {
    int32_t mnMonthsLeft;
    int32_t mnYearsLeft;
    int64_t mnPrincipal;
    int64_t mnRemaining;
    int64_t mnMonthlyPayment;
};

// A node of the loan list: links, then the due month and year and the amounts.
struct Loan_ab0908 {
    Loan_ab0908* mpNext;
    Loan_ab0908* mpPrev;
    int32_t mnMonth;
    int32_t mnYear;
    int64_t mnPrincipal;
    uint8_t mPad18[0x18];
    int64_t mnMonthlyPayment;
    int64_t mnRemaining;
};

#ifdef OB_DRAFTS
// CLOSE: 0x00692c70 score 68
void cSC4BudgetSimulator::GetAllLoans(void* pOut)
{
    std::vector<LoanInfo_ab0908>* out = static_cast<std::vector<LoanInfo_ab0908>*>(pOut);
    out->clear();
    Loan_ab0908* head = static_cast<Loan_ab0908*>(mpLoanList);
    for (Loan_ab0908* loan = head->mpNext; loan != head; loan = loan->mpNext) {
        int32_t year, month;
        gpB43d5c->GetDate(&year, &month, 0, 0, 0);
        LoanInfo_ab0908 info;
        int32_t diff = loan->mnMonth - month;
        info.mnMonthsLeft = diff < 0 ? diff + 12 : diff;
        info.mnYearsLeft = loan->mnYear - year - (diff < 0 ? 1 : 0);
        info.mnPrincipal = loan->mnPrincipal;
        info.mnRemaining = loan->mnRemaining;
        info.mnMonthlyPayment = loan->mnMonthlyPayment;
        out->push_back(info);
    }
}
#endif

// STUB: 0x0040daf0
TreeNode_ab0908* Fn0040daf0(TreeNode_ab0908* pNode, TreeNode_ab0908** pRoot, TreeNode_ab0908** pLeftmost, TreeNode_ab0908** pRightmost);

// The tree object (header pointer, then the element count).
struct Tree_ab0908 {
    TreeNode_ab0908* mpHeader;
    uint32_t mnCount;
    // STUB: 0x00497520
    void Fn00497520(TreeNode_ab0908** pResult, const uint32_t* pKey);
    // STUB: 0x00497a00
    void** Fn00497a00(const uint32_t* pKey);
};

// A set of department ids (a tree), seen from the group record.
struct IdSet_ab0908 {
    // STUB: 0x0046fab0
    void Fn0046fab0(const uint32_t* pKey);
    // STUB: 0x0049a050
    void Fn0049a050(void* pResult, const uint32_t* pKey);
};

// A department budget's non-virtual methods the budget calls directly.
struct DeptDirect_ab0908 {
    // STUB: 0x006aa300
    void Fn006aa300();
    // STUB: 0x0045e110
    bool Fn0045e110();
    // STUB: 0x008b6de0
    void Fn008b6de0(uint32_t id);
};

// A department as the budget drives it through the interface.
struct OB_NOVTABLE DeptCtl_ab0908 {
    virtual void Pad00() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void Pad03() = 0; virtual void Pad04() = 0; virtual void Pad05() = 0;
    virtual uint32_t GetBudgetGroup() = 0;
    virtual void SetBudgetGroup(uint32_t) = 0;
    virtual void Pad08() = 0; virtual void Pad09() = 0; virtual void Pad10() = 0;
    virtual void SetFundingPercentage(const void* pPercent, uint32_t flag) = 0;
};

// GLOBAL: 0x00b0d1c4
extern uint32_t g00b0d1c4[2];

#ifdef OB_DRAFTS
// CLOSE: 0x00692ba0 score 16
bool cSC4BudgetSimulator::RemoveDepartmentBudget(uint32_t id)
{
    Tree_ab0908* tree = reinterpret_cast<Tree_ab0908*>(reinterpret_cast<char*>(this) + 0x54);
    TreeNode_ab0908* it;
    tree->Fn00497520(&it, &id);
    if (it == tree->mpHeader) {
        return false;
    }
    DeptCtl_ab0908* dept = static_cast<DeptCtl_ab0908*>(it->mpValue);
    uint32_t groupId = dept->GetBudgetGroup();
    Tree_ab0908* groups = reinterpret_cast<Tree_ab0908*>(reinterpret_cast<char*>(this) + 0x60);
    TreeNode_ab0908* group;
    groups->Fn00497520(&group, &groupId);
    if (group != groups->mpHeader) {
        reinterpret_cast<IdSet_ab0908*>(reinterpret_cast<char*>(group) + 0x40)->Fn0046fab0(&id);
        DoBudgetGroupChanged(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(group) + 0x18));
    }
    TreeNode_ab0908* header = tree->mpHeader;
    TreeNode_ab0908* freed = Fn0040daf0(it, &header->mpParent, &header->mpLeft, &header->mpRight);
    if (freed) {
        ::operator delete(freed);
    }
    --tree->mnCount;
    reinterpret_cast<DeptDirect_ab0908*>(dept)->Fn006aa300();
    dept->Release();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x006951a0 score 45
void* cSC4BudgetSimulator::CreateDepartmentBudget(uint32_t id, uint32_t group)
{
    Tree_ab0908* tree = reinterpret_cast<Tree_ab0908*>(reinterpret_cast<char*>(this) + 0x54);
    TreeNode_ab0908* found;
    tree->Fn00497520(&found, &id);
    if (found != tree->mpHeader) {
        return found->mpValue;
    }
    cSC4DepartmentBudget* dept = new cSC4DepartmentBudget();
    DeptCtl_ab0908* ctl = reinterpret_cast<DeptCtl_ab0908*>(dept);
    ctl->AddRef();
    reinterpret_cast<DeptDirect_ab0908*>(dept)->Fn0045e110();
    *tree->Fn00497a00(&id) = dept;
    reinterpret_cast<DeptDirect_ab0908*>(dept)->Fn008b6de0(id);
    ctl->SetFundingPercentage(g00b0d1c4, 0);
    char dummy[8];
    reinterpret_cast<IdSet_ab0908*>(static_cast<char*>(GetBudgetGroup(group)) + 0x28)->Fn0049a050(dummy, &id);
    ctl->SetBudgetGroup(group);
    DoBudgetGroupChanged(group);
    return dept;
}
#endif

// The data of one loan (0x38 bytes, the list node's payload).
struct LoanData_ab0908 {
    int32_t mnMonth;
    int32_t mnYear;
    int64_t mnPrincipal;
    int64_t mnFullCost;
    int64_t mnRemaining;
    int64_t mnPaid;
    int64_t mnMonthlyPayment;
    int64_t mnRemainingPrincipal;
};

// The list of loans, seen from its head pointer.
struct LoanList_ab0908 {
    // STUB: 0x00691410
    void Fn00691410(const LoanData_ab0908& loan);
};

#ifdef OB_DRAFTS
// CLOSE: 0x006916f0 score 158
bool cSC4BudgetSimulator::IssueBond(uint32_t amount)
{
    if (amount == 0 || mnLoanCount >= mnMaxOutstandingBonds) {
        return false;
    }
    uint32_t principal = static_cast<uint32_t>(static_cast<int64_t>(amount) / mnBondIncrement) * static_cast<uint32_t>(mnBondIncrement);
    if (principal == 0) {
        principal = static_cast<uint32_t>(mnBondIncrement);
    }
    if (static_cast<int64_t>(principal) > mnCurrentBondLimit) {
        return false;
    }
    if (mnTotalBorrowed + static_cast<int64_t>(principal) > GetCurrentBorrowingLimit()) {
        return false;
    }
    int64_t fullCost = static_cast<int32_t>(GetFullCostOfLoan(principal));
    int64_t monthly = GetMonthlyPaymentForLoan(principal);
    int32_t year, month;
    gpB43d5c->GetDate(&year, &month, 0, 0, 0);
    LoanData_ab0908 loan;
    uint32_t extra = mnLoanTimeInMonths % 12;
    loan.mnMonth = month + extra;
    loan.mnYear = year + mnLoanTimeInMonths / 12;
    if (loan.mnMonth > 12) {
        loan.mnMonth -= 12;
        ++loan.mnYear;
    }
    ++mnLoanCount;
    loan.mnPrincipal = principal;
    loan.mnFullCost = fullCost;
    loan.mnRemaining = fullCost;
    loan.mnPaid = 0;
    loan.mnMonthlyPayment = monthly;
    loan.mnRemainingPrincipal = principal;
    reinterpret_cast<LoanList_ab0908*>(reinterpret_cast<char*>(this) + 0x780)->Fn00691410(loan);
    PostSimMessage(0xc772fada);
    mnTotalBorrowed += principal;
    DepositFunds(principal);
    return true;
}
#endif
