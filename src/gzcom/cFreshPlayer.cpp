#include "classes/cFreshPlayer.h"
#include <algorithm>
#include <new>
#include "gzcom/cRZString.h"

// The critical section every player call takes (the original's variable); slots 1 and 2 enter and leave.
struct Lock_ad4b48 {
    virtual void Pad0_ad4b48();
    virtual void Enter_ad4b48();
    virtual void Leave_ad4b48();
    // STUB: 0x00930b35
    uint32_t EnterDirect_ad4b48();
    // STUB: 0x00930b6d
    uint32_t LeaveDirect_ad4b48();
};

// A scope guard over the lock: the constructor takes it, the destructor lets it go.
struct Guard_ad4b48 {
    uint32_t mPad;
    Lock_ad4b48* mpLock;

    // STUB: 0x0048c9f0
    Guard_ad4b48(Lock_ad4b48* lock);
    ~Guard_ad4b48() { mpLock->Leave_ad4b48(); }
};

// GLOBAL: 0x00b634ac
extern Lock_ad4b48 gB634ac;

// STUB: 0x009f58e2
int32_t Fn009f58e2(int32_t value);

// One cell player (vtable 0x00ad48a0); only the slots and flags used here are named.
struct Cell_ad4b48 {
    // STUB: 0x009458d6
    Cell_ad4b48(void* player);
    virtual void Pad00_ad4b48();
    virtual void Pad01_ad4b48();
    virtual void Pad02_ad4b48();
    virtual void Pad03_ad4b48();
    virtual void Init_ad4b48(void* record);
    virtual void Fn05_ad4b48();
    virtual void Fn06_ad4b48();
    virtual void Fn07_ad4b48();
    virtual void Pad08_ad4b48();
    virtual void Fn09_ad4b48(uint32_t value);
    virtual bool Fn0a_ad4b48();
    virtual bool Fn0b_ad4b48();
    virtual void Pad0c_ad4b48();
    virtual void Pad0d_ad4b48();
    virtual void Pad0e_ad4b48();
    virtual void Fn0f_ad4b48(uint32_t headRelative);
    virtual void Fn10_ad4b48(uint32_t a, uint32_t b, uint32_t c);
    virtual void Fn11_ad4b48(uint32_t a, uint32_t b);
    virtual void Pad12_ad4b48();
    virtual void Fn12_ad4b48(uint32_t value);
    uint8_t mPad04[0x20];
    struct Elem_ad4b48* mpElem_ad4b48;
    uint8_t mPad28[4];
    bool mbBusy_ad4b48;
    bool mbDying_ad4b48;
};

// A cell of the score (field 0x5c: its player group).
struct ListNode_ad4b48 {
    ListNode_ad4b48* mpNext;
    uint32_t mn04;
    int32_t mnCol;
    int32_t mnRow;
};
struct Elem_ad4b48 {
    uint8_t mPad[0x40];
    int32_t mnType;
    uint8_t mPad44[0x18];
    uint32_t mnGroup;
    uint8_t mPad60[4];
    ListNode_ad4b48* mpList;
};

// The score (vtable 0x00ad4818); only what the player reads.
struct Score_ad4b48 {
    virtual void Pad00_ad4b48();
    virtual void Pad01_ad4b48();
    virtual void Pad02_ad4b48();
    virtual void* Fn03_ad4b48(int32_t row, int32_t col, int32_t x);
    virtual void Destroy_ad4b48(uint32_t flag);
    uint8_t mPad04[4];
    uint32_t mn08;
    int32_t mn0c;
    int32_t mn10;
    int32_t mn14;
    int32_t mn18;
    int32_t mn1c;
    int32_t mn20;
    int32_t mn24;
    int32_t mnRows;
    int32_t mnCols;
    int32_t mn30;
    int32_t mn34;
    uint8_t mPad38[8];
    int32_t mn40;
    int32_t mn44;
    Elem_ad4b48* mpElems[4096];
};

// The timer (field 0x18).
struct Timer_ad4b48 {
    // STUB: 0x0088fedf
    Timer_ad4b48(uint32_t resolution);
    // STUB: 0x008905c4
    void Start_ad4b48();
    // STUB: 0x008905f0
    void Stop_ad4b48();
    // STUB: 0x0089058f
    void Restart_ad4b48();
    // STUB: 0x00890198
    uint32_t GetElapsedTime_ad4b48();
    // STUB: 0x00a6d837
    void Destroy_ad4b48();
};

// The sound system the player registers with.
struct SoundSystem_ad4b48 {
    virtual void Pad00_ad4b48();
    virtual void Pad01_ad4b48();
    virtual void Pad02_ad4b48();
    virtual void Pad03_ad4b48();
    virtual void Pad04_ad4b48();
    virtual void Pad05_ad4b48();
    virtual void Pad06_ad4b48();
    virtual void Pad07_ad4b48();
    virtual void Pad08_ad4b48();
    virtual void Pad09_ad4b48();
    virtual void Pad0a_ad4b48();
    virtual void Pad0b_ad4b48();
    virtual void Pad0c_ad4b48();
    virtual void Pad0d_ad4b48();
    virtual void Pad0e_ad4b48();
    virtual void Pad0f_ad4b48();
    virtual void Pad10_ad4b48();
    virtual void Pad11_ad4b48();
    virtual void Pad12_ad4b48();
    virtual void Pad13_ad4b48();
    virtual void Pad14_ad4b48();
    virtual void Pad15_ad4b48();
    virtual void Pad16_ad4b48();
    virtual void Pad17_ad4b48();
    virtual void Pad18_ad4b48();
    virtual void Pad19_ad4b48();
    virtual void Pad1a_ad4b48();
    virtual void Pad1b_ad4b48();
    virtual void Pad1c_ad4b48();
    virtual void Pad1d_ad4b48();
    virtual void Register_ad4b48(void* listener, uint32_t priority);
    virtual void Unregister_ad4b48(void* listener);
};

// STUB: 0x00913c9e
SoundSystem_ad4b48* Fn00913c9e();

// The cell player seen through its second base (at +4): slot 7 destroys it.
struct CellBase_ad4b48 {
    virtual void Pad00_ad4b48();
    virtual void Pad01_ad4b48();
    virtual void Pad02_ad4b48();
    virtual void Pad03_ad4b48();
    virtual void Pad04_ad4b48();
    virtual void Pad05_ad4b48();
    virtual void Pad06_ad4b48();
    virtual void Destroy_ad4b48(uint32_t flag);
};

// The object at +0x4140 (one STUB call).
struct Tail_ad4b48 {
    // STUB: 0x0094909a
    void Fn0094909a(uint32_t value);
};

// The fade player held while fading (field 0x4094).
struct Fade_ad4b48 {
    virtual void Fn00_ad4b48(uint32_t flag);
    virtual void Pad01_ad4b48();
    virtual void Pad02_ad4b48();
    virtual void Pad03_ad4b48();
    virtual void Pad04_ad4b48();
    virtual void Pad05_ad4b48();
    virtual void Pad06_ad4b48();
    virtual void Fn07_ad4b48();
};

#define SCORE_AD4B48 (static_cast<Score_ad4b48*>(mpScore))

// FUNCTION: 0x00946fe6
bool cFreshPlayer::QueryInterface(uint32_t id, void** out)
{
    if (id != 0xdc1cf595) {
        return false;
    }
    *out = this;
    AddRef();
    return true;
}

// FUNCTION: 0x00947004
unsigned int cFreshPlayer::Release()
{
    if (mnRefCount == 1) {
        delete this;
        return 0;
    }
    return --mnRefCount;
}

// FUNCTION: 0x00947150
void cFreshPlayer::Play_2(uint32_t volume)
{
    SetVolume(volume);
    Play();
}

// FUNCTION: 0x00947167
bool cFreshPlayer::Stop()
{
    Guard_ad4b48 guard(&gB634ac);
    return StopNoLock();
}

// FUNCTION: 0x00947197
void cFreshPlayer::StopFade()
{
    if (mbFading) {
        Fade_ad4b48* fade = static_cast<Fade_ad4b48*>(mpFade);
        fade->Fn07_ad4b48();
        gB634ac.EnterDirect_ad4b48();
        mbFading = false;
        gB634ac.LeaveDirect_ad4b48();
        static_cast<Fade_ad4b48*>(mpFade)->Fn07_ad4b48();
        Fade_ad4b48* old = static_cast<Fade_ad4b48*>(mpFade);
        if (old) {
            old->Fn00_ad4b48(1);
        }
        mpFade = 0;
    }
}

#ifdef OB_DRAFTS
// CLOSE: 0x009471ee score 8
bool cFreshPlayer::CellIsInSelectionArea(uint32_t row, uint32_t col)
{
    if (Fn009f58e2(static_cast<int32_t>(row) - mnRow) > mnMaxDistRow) {
        return false;
    }
    return Fn009f58e2(static_cast<int32_t>(col) - mnCol) <= mnMaxDistCol;
}
#endif

// FUNCTION: 0x00947519
void cFreshPlayer::SubtractCell(uint32_t row, uint32_t col)
{
    mnSelRow = row;
    mnSelCol = col;
    Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[(row << 6) + col]);
    if (!cell->Fn0b_ad4b48()) {
        cell->Fn0a_ad4b48();
    }
    if (cell->Fn0b_ad4b48()) {
        cell->Fn07_ad4b48();
    }
}

// FUNCTION: 0x00947559
bool cFreshPlayer::SetVolume(uint32_t volume)
{
    Guard_ad4b48 guard(&gB634ac);
    return SetVolumeNoLock(volume);
}

#ifdef OB_DRAFTS
// CLOSE: 0x0094758e score 15
bool cFreshPlayer::SetVolumeNoLock(uint32_t volume)
{
    if (mbInitialized) {
        int32_t r = 0;
        mnVolume = volume;
        if (SCORE_AD4B48->mnRows > 0) {
            void** row = &mpCells[0];
            do {
                int32_t c = 0;
                if (SCORE_AD4B48->mnCols > 0) {
                    void** p = row;
                    do {
                        Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(*p);
                        if (cell) {
                            cell->Fn09_ad4b48(mnVolume);
                        }
                        ++c;
                        ++p;
                    } while (c < SCORE_AD4B48->mnCols);
                }
                ++r;
                row += 64;
            } while (r < SCORE_AD4B48->mnRows);
        }
    }
    return true;
}
#endif

// FUNCTION: 0x009475fb
int32_t cFreshPlayer::Fn009475fb(uint32_t value)
{
    int32_t divisor = mnTempo;
    if (divisor == 0) {
        return -1;
    }
    return (static_cast<int32_t>(value) - mn44) * 60000 / divisor;
}

#ifdef OB_DRAFTS
// CLOSE: 0x0094776d score 4
bool cFreshPlayer::SetZoom(uint32_t zoom)
{
    if (!mbInitialized) {
        return false;
    }
    mnZoom = zoom;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0094777f score 4
bool cFreshPlayer::SetPlayPercent(uint32_t percent)
{
    if (!mbInitialized) {
        return false;
    }
    mnPlayPercent = percent;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00947794 score 4
bool cFreshPlayer::SetManual(bool manual)
{
    if (!mbInitialized) {
        return false;
    }
    mbManual = manual;
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009477a6 score 4
uint32_t cFreshPlayer::NumCellsBusy()
{
    uint32_t n = 0;
    int32_t r = 0;
    if (SCORE_AD4B48->mnRows > 0) {
        void** row = &mpCells[0];
        do {
            int32_t c = 0;
            if (SCORE_AD4B48->mnCols > 0) {
                void** p = row;
                do {
                    if (*p && static_cast<Cell_ad4b48*>(*p)->Fn0b_ad4b48()) {
                        ++n;
                    }
                    ++c;
                    ++p;
                } while (c < SCORE_AD4B48->mnCols);
            }
            ++r;
            row += 64;
        } while (r < SCORE_AD4B48->mnRows);
    }
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0094780d score 37
uint32_t cFreshPlayer::NumCellsDying()
{
    uint32_t n = 0;
    int32_t rows = SCORE_AD4B48->mnRows;
    if (rows > 0) {
        int32_t cols = SCORE_AD4B48->mnCols;
        void** row = &mpCells[0];
        do {
            void** p = row;
            int32_t c = cols;
            if (cols > 0) {
                do {
                    Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(*p);
                    if (cell && cell->mbDying_ad4b48) {
                        ++n;
                    }
                    ++p;
                    --c;
                } while (c != 0);
            }
            row += 64;
            --rows;
        } while (rows != 0);
    }
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00947858 score 4
uint32_t cFreshPlayer::NumCellsPlaying()
{
    uint32_t n = 0;
    int32_t r = 0;
    if (SCORE_AD4B48->mnRows > 0) {
        void** row = &mpCells[0];
        do {
            int32_t c = 0;
            if (SCORE_AD4B48->mnCols > 0) {
                void** p = row;
                do {
                    if (*p && static_cast<Cell_ad4b48*>(*p)->Fn0a_ad4b48()) {
                        ++n;
                    }
                    ++c;
                    ++p;
                } while (c < SCORE_AD4B48->mnCols);
            }
            ++r;
            row += 64;
        } while (r < SCORE_AD4B48->mnRows);
    }
    return n;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009478bf score 2
bool cFreshPlayer::ShowUsage()
{
    if (!mbInitialized) {
        return false;
    }
    if (!mbPlaying) {
        return false;
    }
    NumCellsBusy();
    NumCellsPlaying();
    return true;
}
#endif

// FUNCTION: 0x009478ea
bool cFreshPlayer::SetSelectionAreaMaxDistances(uint32_t rowDistance, uint32_t colDistance)
{
    mnMaxDistRow = rowDistance;
    mnMaxDistCol = colDistance;
    return true;
}

// FUNCTION: 0x009478fd
bool cFreshPlayer::GetSelectionAreaMaxDistances(uint32_t rowOut, uint32_t colOut)
{
    *OB_PTR(int32_t, rowOut) = mnMaxDistRow;
    *OB_PTR(int32_t, colOut) = mnMaxDistCol;
    return true;
}

// FUNCTION: 0x00947914
void cFreshPlayer::UpdateListener(uint32_t a, uint32_t b)
{
    mnListenerA = a;
    mnListenerB = b;
}

#ifdef OB_DRAFTS
// CLOSE: 0x00947925 score 21
uint32_t cFreshPlayer::GetMinCellsPlaying()
{
    int32_t a = mnPlayPercent * SCORE_AD4B48->mn10 / 100;
    int32_t d = SCORE_AD4B48->mnCols - 1;
    if (d == 0) {
        d = 1;
    }
    int32_t b = (mnCol + 1) * SCORE_AD4B48->mn18 / d;
    int32_t e = SCORE_AD4B48->mnRows - 1;
    if (e == 0) {
        e = 1;
    }
    int32_t total = a + ((mnRow + 1) * SCORE_AD4B48->mn1c / e + b);
    if (total > mnPlayersBusy) {
        total = mnPlayersBusy;
    }
    return total;
}
#endif

// FUNCTION: 0x00947982
uint32_t cFreshPlayer::GetMaxCellsPlaying()
{
    return SCORE_AD4B48->mn14 * mnPlayPercent / 100;
}

// FUNCTION: 0x00947996
uint32_t cFreshPlayer::GetFirstSelectableRow()
{
    int32_t v = mnRow - mnMaxDistRow;
    if (v < 0) {
        return 0;
    }
    return v;
}

// FUNCTION: 0x009479a1
uint32_t cFreshPlayer::GetLastSelectableRow()
{
    int32_t v = mnMaxDistRow + mnRow;
    int32_t rows = SCORE_AD4B48->mnRows;
    if (v < rows) {
        return v;
    }
    return rows - 1;
}

// FUNCTION: 0x009479b5
uint32_t cFreshPlayer::GetFirstSelectableColumn()
{
    int32_t v = mnCol - mnMaxDistCol;
    if (v < 0) {
        return 0;
    }
    return v;
}

// FUNCTION: 0x009479c0
uint32_t cFreshPlayer::GetLastSelectableColumn()
{
    int32_t v = mnMaxDistCol + mnCol;
    int32_t cols = SCORE_AD4B48->mnCols;
    if (v < cols) {
        return v;
    }
    return cols - 1;
}

// FUNCTION: 0x00947a2a
bool cFreshPlayer::SetDivisionEnabled(uint32_t x, uint32_t z, bool enabled)
{
    if (x >= 3 || z >= 3) {
        return false;
    }
    mbDivisionEnabled[z + x * 2 + x] = enabled;
    return true;
}

// FUNCTION: 0x00947a55
bool cFreshPlayer::SetDivision3DPosition(uint32_t x, uint32_t z, uint32_t px, uint32_t py, uint32_t pz)
{
    if (x >= 3 || z >= 3) {
        return false;
    }
    mnDivisionX[z + x * 2 + x] = px;
    mnDivisionY[z + x * 2 + x] = py;
    mnDivisionZ[z + x * 2 + x] = pz;
    return true;
}

// FUNCTION: 0x00947aa9
bool cFreshPlayer::SetNumDivisionsX(uint32_t n)
{
    if (n >= 3) {
        return false;
    }
    mnNumDivisionsX = n;
    return true;
}

// FUNCTION: 0x00947ac1
bool cFreshPlayer::SetNumDivisionsZ(uint32_t n)
{
    if (n >= 3) {
        return false;
    }
    mnNumDivisionsZ = n;
    return true;
}

// FUNCTION: 0x00948b89
void* cFreshPlayer::GetCellPlayer(uint32_t row, uint32_t col, uint32_t /*unused*/)
{
    return mpCells[(row << 6) + col];
}

// FUNCTION: 0x00948baa
bool cFreshPlayer::SetMinMaxDistance(uint32_t minDistance, uint32_t maxDistance)
{
    mnMinDistance = minDistance;
    mnMaxDistance = maxDistance;
    return true;
}

struct Key_ad4b48 {
    uint32_t a;
    uint32_t b;
    uint32_t c;
};

// FUNCTION: 0x00948bdd
void cFreshPlayer::SetKey(const void* key)
{
    Key_ad4b48* dest = reinterpret_cast<Key_ad4b48*>(&field4134[0]);
    const Key_ad4b48* source = static_cast<const Key_ad4b48*>(key);
    dest->a = source->a;
    dest->b = source->b;
    dest->c = source->c;
}

// FUNCTION: 0x00948e4e
bool cFreshPlayer::GetDataDir(void* out)
{
    *static_cast<cRZString*>(out) = mDataDir;
    return true;
}

// FUNCTION: 0x00948e0b
bool cFreshPlayer::Init_3(void* score, void* dataDir)
{
    Guard_ad4b48 guard(&gB634ac);
    mpScore = score;
    mDataDir = *static_cast<cRZString*>(dataDir);
    return Slot04_ad4b48();
}

// FUNCTION: 0x00948c11
bool cFreshPlayer::LoadScore(void* name, uint32_t /*unused*/)
{
    cRZString path(*static_cast<cIGZString*>(name));
    return Slot38_ad4b48(&path);
}

#ifdef OB_DRAFTS
// CLOSE: 0x00947db8 score 2
bool cFreshPlayer::Play()
{
    Guard_ad4b48 guard(&gB634ac);
    if (mbInitialized) {
        if (mbFading) {
            StopFade();
        }
        if (!mbPlaying) {
            Score_ad4b48* s = SCORE_AD4B48;
            mbManual = false;
            mnTempo = s->mn30;
            mn44 = s->mn34;
            if (s->mn34 > 2) {
                mn44 = s->mn34 - 1;
            }
            mn3c = mn44;
            mn40 = mn44;
            UpdatePlayerInfo();
            Timer_ad4b48* timer = new Timer_ad4b48(4);
            mpTimer = timer;
            timer->Start_ad4b48();
            SetXPos(SCORE_AD4B48->mn40);
            SetYPos(SCORE_AD4B48->mn44);
            mbPlaying = true;
            if (Fn00913c9e()) {
                Fn00913c9e()->Register_ad4b48(static_cast<cUnk00a943c0*>(this), 250);
            }
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00947e90 score 61
bool cFreshPlayer::StopNoLock()
{
    if (mbInitialized && mbPlaying) {
        if (Fn00913c9e()) {
            Fn00913c9e()->Unregister_ad4b48(static_cast<cUnk00a943c0*>(this));
        }
        StopFade();
        Timer_ad4b48* timer = static_cast<Timer_ad4b48*>(mpTimer);
        if (timer) {
            timer->Stop_ad4b48();
            Timer_ad4b48* dead = static_cast<Timer_ad4b48*>(mpTimer);
            if (dead) {
                dead->Destroy_ad4b48();
                operator delete(dead);
            }
            mpTimer = 0;
        }
        int32_t r = 0;
        if (SCORE_AD4B48->mnRows > 0) {
            void** row = &mpCells[0];
            do {
                int32_t c = 0;
                if (SCORE_AD4B48->mnCols > 0) {
                    void** p = row;
                    do {
                        Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(*p);
                        if (cell && cell->Fn0b_ad4b48()) {
                            cell->Fn07_ad4b48();
                        }
                        ++c;
                        ++p;
                    } while (c < SCORE_AD4B48->mnCols);
                }
                ++r;
                row += 64;
            } while (r < SCORE_AD4B48->mnRows);
        }
        mbPlaying = false;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00947d28 score 4
bool cFreshPlayer::Shutdown()
{
    StopFade();
    Guard_ad4b48 guard(&gB634ac);
    if (mbInitialized) {
        Stop();
        Score_ad4b48* s = SCORE_AD4B48;
        if (s) {
            s->Destroy_ad4b48(1);
            mpScore = 0;
        }
        void** p = &mpCells[0];
        int32_t outer = 64;
        do {
            int32_t inner = 64;
            do {
                if (*p) {
                    reinterpret_cast<CellBase_ad4b48*>(static_cast<char*>(*p) + 4)->Destroy_ad4b48(1);
                    *p = 0;
                }
                ++p;
                --inner;
            } while (inner != 0);
            --outer;
        } while (outer != 0);
        mbPlaying = false;
        mbInitialized = false;
        reinterpret_cast<Tail_ad4b48*>(reinterpret_cast<char*>(this) + 0x4140)->Fn0094909a(0);
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009482c5 score 35
bool cFreshPlayer::ToggleCell(uint32_t row, uint32_t col)
{
    uint32_t index = (row << 6) + col;
    if (static_cast<Cell_ad4b48*>(mpCells[index])->Fn0b_ad4b48()) {
        SubtractCell(row, col);
    } else {
        Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[index]);
        if (CalculateCellplayer3DPosition(cell)) {
            cell->Init_ad4b48(SCORE_AD4B48->mpElems[index]);
            cell->Fn05_ad4b48();
        }
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00948420 score 10
bool cFreshPlayer::SetTempo(uint32_t tempo)
{
    Guard_ad4b48 guard(&gB634ac);
    if (IsPlaying() && mnTempo != static_cast<int32_t>(tempo)) {
        mnTempo = tempo;
        static_cast<Timer_ad4b48*>(mpTimer)->Stop_ad4b48();
        static_cast<Timer_ad4b48*>(mpTimer)->Restart_ad4b48();
        mn40 = mn44 + mn3c;
        static_cast<Timer_ad4b48*>(mpTimer)->GetElapsedTime_ad4b48();
        int32_t target = mn40;
        Fn009475fb(target);
        Fn009475fb(target);
        static_cast<Timer_ad4b48*>(mpTimer)->GetElapsedTime_ad4b48();
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x009484a0 score 28
bool cFreshPlayer::SetXPos(uint32_t x)
{
    if (!mbInitialized) {
        return false;
    }
    Score_ad4b48* s = SCORE_AD4B48;
    int32_t cols = s->mnCols;
    int32_t v = cols * static_cast<int32_t>(x) / 1000;
    if (s->mn0c != 0) {
        int32_t d = mnMaxDistCol;
        int32_t span = d * 2 + 1;
        v = v / span * span + d;
    }
    int32_t d2 = mnMaxDistCol;
    int32_t hi = cols - d2;
    if (v >= hi) {
        v = hi - 1;
    }
    if (v < d2) {
        v = d2;
    }
    if (v < 0) {
        v = 0;
    }
    if (v >= cols) {
        v = cols - 1;
    }
    mnCol = v;
    UpdatePlayerInfo();
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00948504 score 26
bool cFreshPlayer::SetYPos(uint32_t y)
{
    if (!mbInitialized) {
        return false;
    }
    Score_ad4b48* s = SCORE_AD4B48;
    int32_t rows = s->mnRows;
    int32_t v = rows * static_cast<int32_t>(y) / 1000;
    if (s->mn0c != 0) {
        int32_t d = mnMaxDistRow;
        int32_t span = d * 2 + 1;
        v = v / span * span + d;
    }
    int32_t d2 = mnMaxDistRow;
    int32_t hi = rows - d2;
    if (v >= hi) {
        v = hi - 1;
    }
    if (v < d2) {
        v = d2;
    }
    if (v > rows - 1) {
        v = rows - 1;
    }
    if (v < 0) {
        v = 0;
    }
    mnRow = v;
    UpdatePlayerInfo();
    return true;
}
#endif

#define U32_AD4B48(off) (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this) + (off)))
#define U8_AD4B48(off) (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(this) + (off)))

// The random number source (field 0x10).
struct Random_ad4b48 {
    // STUB: 0x00913696
    uint32_t Uniform32();
    // STUB: 0x00913667
    void Seed(uint32_t seed);
    // STUB: 0x009136b1
    uint32_t Uniform(uint32_t limit);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009476c3 score 48
void cFreshPlayer::UpdatePlayerInfo()
{
    mnCellsBusy = 0;
    mnPlayersBusy = 0;
    uint8_t seen[32] = {0};
    int32_t row = GetFirstSelectableRow();
    while (row <= static_cast<int32_t>(GetLastSelectableRow())) {
        int32_t base = row << 6;
        int32_t col = GetFirstSelectableColumn();
        while (col <= static_cast<int32_t>(GetLastSelectableColumn())) {
            Elem_ad4b48* e = SCORE_AD4B48->mpElems[base + col];
            if (e) {
                uint32_t group = e->mnGroup;
                if (group == 0) {
                    ++mnPlayersBusy;
                } else if (!seen[group]) {
                    seen[group] = 1;
                    ++mnPlayersBusy;
                }
                ++mnCellsBusy;
            }
            ++col;
        }
        ++row;
    }
}
#endif

// FUNCTION: 0x009479d4
bool cFreshPlayer::Reseed(uint32_t seed)
{
    static_cast<Random_ad4b48*>(mpRandom)->Seed(seed);
    mn3c = 0;
    mn40 = 1;
    mn44 = 0;
    mn48 = 0;
    mn4c = 4;
    mnSelRow = 0;
    mnSelCol = 0;
    mn64 = 0;
    mn68 = 0;
    UpdatePlayerInfo();
    if (mbPlaying) {
        Stop();
        Play();
    }
    return true;
}

// The record stream handed to the score parser.
struct Stream_ad4b48 {
    virtual void Pad00_ad4b48();
    virtual void Pad01_ad4b48();
    virtual void Pad02_ad4b48();
    virtual void Pad03_ad4b48();
    virtual void Pad04_ad4b48();
    virtual void Fn05_ad4b48();
    virtual void Pad06_ad4b48();
    virtual uint32_t Fn07_ad4b48();
    virtual void Pad08_ad4b48();
    virtual void Pad09_ad4b48();
    virtual void Pad0a_ad4b48();
    virtual void Pad0b_ad4b48();
    virtual void Pad0c_ad4b48();
    virtual void Fn0e_ad4b48(char* buffer, uint32_t size);
};

// The score parser (the object built from the file; no vtable here, it is seen through offsets).
struct ScoreRaw_ad4b48 {
    uint32_t w[0x1012];
    // STUB: 0x00946039
    bool ParseScore(cRZString* text);
    // STUB: 0x00946a79
    bool Fn00946a79(Stream_ad4b48* stream);
    // STUB: 0x00946b30
    bool Fn00946b30(cRZString name, uint32_t a, uint32_t b);
    // STUB: 0x0094585f
    ScoreRaw_ad4b48* Fn0094585f();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0094585f score 30
ScoreRaw_ad4b48* ScoreRaw_ad4b48::Fn0094585f()
{
    w[5] = 4;
    w[10] = 4;
    w[11] = 4;
    w[14] = 1;
    w[15] = 1;
    w[1] = 0;
    w[3] = 0;
    w[4] = 0;
    w[6] = 0;
    w[7] = 0;
    w[16] = 0;
    w[17] = 0;
    w[8] = 2;
    w[9] = 2;
    for (int i = 0; i < 0x1000; ++i) {
        w[0x12 + i] = 0;
    }
    w[0] = 0xad4818;
    w[2] = 0x400;
    w[12] = 0x78;
    w[13] = 8;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00946a79 score 2
bool ScoreRaw_ad4b48::Fn00946a79(Stream_ad4b48* stream)
{
    cRZString text;
    uint32_t size = stream->Fn07_ad4b48();
    if (size == 0) {
        return false;
    }
    char* buffer = static_cast<char*>(operator new(size + 1));
    if (!buffer) {
        return false;
    }
    stream->Fn0e_ad4b48(buffer, size);
    stream->Fn05_ad4b48();
    buffer[size] = 0;
    text.FromChar(buffer);
    operator delete(buffer);
    return ParseScore(&text);
}
#endif

// A file handle used by the score loader.
struct ScoreFile_ad4b48 {
    uint32_t w[26];
    // STUB: 0x00918c00
    ScoreFile_ad4b48(cRZString* name);
    // STUB: 0x00919b00
    bool Open(uint32_t a, uint32_t b, uint32_t c);
    // STUB: 0x009186f5
    uint32_t Length();
    // STUB: 0x00918382
    bool Read(char* buffer, uint32_t size);
    // STUB: 0x009188a5
    bool Close();
    // STUB: 0x00918c70
    ~ScoreFile_ad4b48();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00946b30 score 91
bool ScoreRaw_ad4b48::Fn00946b30(cRZString name, uint32_t a, uint32_t b)
{
    cRZString text;
    ScoreFile_ad4b48 file(&name);
    if (file.Open(1, 2, 1)) {
        uint32_t length = file.Length();
        if (length) {
            char* buffer = static_cast<char*>(operator new(length + 1));
            if (buffer) {
                file.Read(buffer, length);
                file.Close();
                buffer[length] = 0;
                text.FromChar(buffer);
                operator delete(buffer);
                return ParseScore(&text);
            }
        }
    }
    return false;
}
#endif

// The base object with vtable 0x00ad8fa4 (a reference count and a flag).
struct RefBase_ad4b48 {
    uint32_t w[4];
    void Fn0097996d();
};

#ifdef OB_DRAFTS
// CLOSE: 0x0097996d score 13
void RefBase_ad4b48::Fn0097996d()
{
    w[0] = 0xad8fa4;
    w[1] = 0;
    reinterpret_cast<uint8_t*>(w)[8] = 1;
    reinterpret_cast<uint8_t*>(w)[9] = 0;
    w[3] = 0;
}
#endif

// The cell player object seen as words.
struct CellRaw_ad4b48 {
    uint32_t w[0x17];
    CellRaw_ad4b48* Fn009458d6(void* player);
};

#ifdef OB_DRAFTS
// CLOSE: 0x009458d6 score 52
CellRaw_ad4b48* CellRaw_ad4b48::Fn009458d6(void* player)
{
    w[0] = 0xad4830;
    reinterpret_cast<RefBase_ad4b48*>(&w[1])->Fn0097996d();
    w[6] = OB_ADDR(player);
    w[5] = 0;
    w[0] = 0xad48a0;
    w[1] = 0xad487c;
    w[7] = 0;
    w[8] = 0;
    w[9] = 0;
    reinterpret_cast<uint8_t*>(w)[0x2c] = 0;
    reinterpret_cast<uint8_t*>(w)[0x2d] = 0;
    reinterpret_cast<uint8_t*>(w)[0x3c] = 0;
    w[0x10] = 0;
    w[0x11] = 0;
    w[0xd] = 0x400;
    reinterpret_cast<uint8_t*>(w)[0x3d] = 1;
    w[0x12] = 100;
    w[0x13] = 1000;
    w[0x14] = 100;
    w[0x15] = 0;
    reinterpret_cast<uint8_t*>(w)[0x58] = 0;
    return this;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0094701e score 46
bool cFreshPlayer::Slot04_ad4b48()
{
    Guard_ad4b48 guard(&gB634ac);
    if (!mbInitialized) {
        mnSelRow = -1;
        mnSelCol = -1;
        mn64 = -1;
        mn68 = -1;
        Score_ad4b48* s = SCORE_AD4B48;
        mnVolume = s->mn08;
        mnRow = 1;
        mnCol = 1;
        mn30 = 1;
        mn48 = s->mn10;
        mn4c = s->mn14;
        mnMaxDistRow = s->mn20;
        mnMaxDistCol = s->mn24;
        for (int32_t r = 0; r < SCORE_AD4B48->mnRows; ++r) {
            for (int32_t c = 0; c < SCORE_AD4B48->mnCols; ++c) {
                void* rec = SCORE_AD4B48->Fn03_ad4b48(r, c, 0);
                if (rec) {
                    Cell_ad4b48* cell = new Cell_ad4b48(this);
                    cell->Init_ad4b48(rec);
                    mpCells[(r << 6) + c] = cell;
                }
            }
        }
        mnCellsBusy = 0;
        for (int32_t r = 0; r < SCORE_AD4B48->mnRows; ++r) {
            for (int32_t c = 0; c < SCORE_AD4B48->mnCols; ++c) {
                if (CellIsInSelectionArea(r, c)) {
                    ++mnCellsBusy;
                }
            }
        }
        mbInitialized = true;
    }
    return true;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00947ad9 score 144
bool cFreshPlayer::CalculateCellplayer3DPosition(void* cellPointer)
{
    uint32_t count = 0;
    for (uint32_t x = 0; x < mnNumDivisionsX + 1; ++x) {
        for (uint32_t z = 0; z < mnNumDivisionsZ + 1; ++z) {
            if (mbDivisionEnabled[x * 3 + z]) {
                ++count;
            }
        }
    }
    if (count == 0) {
        return false;
    }
    uint32_t pick = static_cast<Random_ad4b48*>(mpRandom)->Uniform(count * 1000);
    uint32_t chosenX = mnCurDivX;
    uint32_t chosenZ = mnCurDivZ;
    bool found = false;
    for (uint32_t x = 0; x < mnNumDivisionsX + 1; ++x) {
        for (uint32_t z = 0; z < mnNumDivisionsZ + 1; ++z) {
            if (found) {
                continue;
            }
            if (mbDivisionEnabled[x * 3 + z]) {
                if (x == mnCurDivX && z == mnCurDivZ) {
                    continue;
                }
                if (pick >= 1000) {
                    pick -= 1000;
                    continue;
                }
                chosenX = x;
                chosenZ = z;
                found = true;
            }
        }
    }
    mnCurDivX = chosenX;
    mnCurDivZ = chosenZ;
    Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(cellPointer);
    uint32_t index = mnCurDivZ + mnCurDivX * 3;
    cell->Fn0f_ad4b48(U32_AD4B48(0x40bc) & 0xff);
    cell->Fn11_ad4b48(mnMinDistance, mnMaxDistance);
    cell->Fn10_ad4b48(mnDivisionX[index], mnDivisionY[index], mnDivisionZ[index]);
    return true;
}
#endif

// STUB: 0x009efb9f
int32_t Fn009efb9f();

// GLOBAL: 0x00b16f30
extern int32_t gB16f30[21];

#ifdef OB_DRAFTS
// CLOSE: 0x00948573 score 195
uint32_t cFreshPlayer::ProbOfCellStarting(uint32_t row, uint32_t col, uint32_t group)
{
    uint32_t index = (row << 6) + col;
    Elem_ad4b48* elem = SCORE_AD4B48->mpElems[index];
    Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[index]);
    if (elem != 0 && !cell->Fn0b_ad4b48() && !cell->Fn0a_ad4b48() && CellIsInSelectionArea(row, col)
        && (static_cast<int32_t>(row) != mnSelRow || static_cast<int32_t>(col) != mnSelCol)) {
        if (elem->mnGroup != 0) {
            for (int32_t r = 0; r < SCORE_AD4B48->mnRows; ++r) {
                for (int32_t c = 0; c < SCORE_AD4B48->mnCols; ++c) {
                    Cell_ad4b48* other = static_cast<Cell_ad4b48*>(mpCells[(r << 6) + c]);
                    if (other && other->mpElem_ad4b48 && elem->mnGroup == other->mpElem_ad4b48->mnGroup
                        && other->Fn0b_ad4b48() && !other->mbDying_ad4b48) {
                        return 0;
                    }
                }
            }
        }
        ListNode_ad4b48* head = elem->mpList;
        for (ListNode_ad4b48* n = head->mpNext; n != head; n = n->mpNext) {
            if (n->mnRow < SCORE_AD4B48->mnRows && n->mnCol < SCORE_AD4B48->mnCols) {
                Cell_ad4b48* linked = static_cast<Cell_ad4b48*>(mpCells[(n->mnRow << 6) + n->mnCol]);
                if (linked->Fn0b_ad4b48() && !linked->mbDying_ad4b48) {
                    return 0;
                }
            }
        }
        if (elem->mnType > 0x14) {
            elem->mnType = 0x14;
        }
        if (elem->mnType < 0) {
            elem->mnType = 0;
        }
        if (elem->mnType != 0) {
            if (elem->mnType == 0x14) {
                if (group != 0 && elem->mnGroup == group) {
                    return 0x65;
                }
                return 100;
            }
            if (mnCellsBusy == 0) {
                mnCellsBusy = 10;
            }
            if (group != 0 && elem->mnGroup == group) {
                return 2;
            }
            int32_t limit = gB16f30[elem->mnType];
            return Fn009efb9f() < limit / mnCellsBusy;
        }
    }
    return 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00948719 score 182
bool cFreshPlayer::GetCellToAdd(uint32_t rowOut, uint32_t colOut, uint32_t group)
{
    int32_t best = 0;
    uint32_t random = static_cast<Random_ad4b48*>(mpRandom)->Uniform32();
    int32_t firstRow = GetFirstSelectableRow();
    int32_t firstCol = GetFirstSelectableColumn();
    int32_t lastRow = GetLastSelectableRow();
    int32_t lastCol = GetLastSelectableColumn();
    int32_t startRow = ((random >> 8 & 0xff) % (mnMaxDistRow * 2 + 1) + mnRow) - mnMaxDistRow;
    int32_t startCol = ((random & 0xff) % (mnMaxDistCol * 2 + 1) + mnCol) - mnMaxDistCol;
    if (startRow < 0) {
        startRow = 0;
    }
    if (startCol < 0) {
        startCol = 0;
    }
    if (startRow >= SCORE_AD4B48->mnRows) {
        startRow = SCORE_AD4B48->mnRows - 1;
    }
    if (startCol >= SCORE_AD4B48->mnCols) {
        startCol = SCORE_AD4B48->mnCols - 1;
    }
    int32_t* rowPtr = OB_PTR(int32_t, rowOut);
    int32_t* colPtr = OB_PTR(int32_t, colOut);
    for (int32_t r = startRow; r <= lastRow; ++r) {
        int32_t c = startCol;
        for (; c <= lastCol; ++c) {
            CellIsInSelectionArea(r, c);
            int32_t p = ProbOfCellStarting(r, c, group);
            if (best < p) {
                *rowPtr = r;
                *colPtr = c;
                static_cast<Cell_ad4b48*>(mpCells[(r << 6) + c])->Fn0b_ad4b48();
                best = p;
            }
        }
        for (c = firstCol; c < startCol; ++c) {
            CellIsInSelectionArea(r, c);
            int32_t p = ProbOfCellStarting(r, c, group);
            if (best < p) {
                *rowPtr = r;
                *colPtr = c;
                static_cast<Cell_ad4b48*>(mpCells[(r << 6) + c])->Fn0b_ad4b48();
                best = p;
            }
        }
    }
    for (int32_t r = firstRow; r < startRow; ++r) {
        int32_t c = startCol;
        for (; c <= lastCol; ++c) {
            CellIsInSelectionArea(r, c);
            int32_t p = ProbOfCellStarting(r, c, group);
            if (best < p) {
                *rowPtr = r;
                *colPtr = c;
                static_cast<Cell_ad4b48*>(mpCells[(r << 6) + c])->Fn0b_ad4b48();
                best = p;
            }
        }
        for (c = firstCol; c < startCol; ++c) {
            CellIsInSelectionArea(r, c);
            int32_t p = ProbOfCellStarting(r, c, group);
            if (best < p) {
                *rowPtr = r;
                *colPtr = c;
                static_cast<Cell_ad4b48*>(mpCells[(r << 6) + c])->Fn0b_ad4b48();
                best = p;
            }
        }
    }
    return best != 0;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00947220 score 179
bool cFreshPlayer::GetCellToSubtract(uint32_t rowOut, uint32_t colOut)
{
    int32_t* rowPtr = OB_PTR(int32_t, rowOut);
    int32_t* colPtr = OB_PTR(int32_t, colOut);
    uint32_t random = static_cast<Random_ad4b48*>(mpRandom)->Uniform32();
    int32_t startRow = (random >> 8 & 0xff) % SCORE_AD4B48->mnRows;
    int32_t startCol = (random & 0xff) % SCORE_AD4B48->mnCols;
    *rowPtr = startRow;
    for (; *rowPtr < SCORE_AD4B48->mnRows; ++*rowPtr) {
        for (*colPtr = startCol; *colPtr < SCORE_AD4B48->mnCols; ++*colPtr) {
            Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr]);
            if (cell->Fn0a_ad4b48() && !CellIsInSelectionArea(*rowPtr, *colPtr)
                && !static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr])->mbDying_ad4b48) {
                return true;
            }
        }
        for (*colPtr = 0; *colPtr < startCol; ++*colPtr) {
            Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr]);
            if (cell->Fn0a_ad4b48() && !CellIsInSelectionArea(*rowPtr, *colPtr)
                && !static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr])->mbDying_ad4b48) {
                return true;
            }
        }
    }
    for (*rowPtr = 0; *rowPtr < startRow; ++*rowPtr) {
        for (*colPtr = startCol; *colPtr < SCORE_AD4B48->mnCols; ++*colPtr) {
            Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr]);
            if (cell->Fn0a_ad4b48() && !CellIsInSelectionArea(*rowPtr, *colPtr)
                && !static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr])->mbDying_ad4b48) {
                return true;
            }
        }
        for (*colPtr = 0; *colPtr < startCol; ++*colPtr) {
            Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr]);
            if (cell->Fn0a_ad4b48() && !CellIsInSelectionArea(*rowPtr, *colPtr)
                && !static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr])->mbDying_ad4b48) {
                return true;
            }
        }
    }
    // Nothing outside the selection area: pick among the busy cells inside it at random.
    int32_t firstCol = mnRow - mnMaxDistRow;
    if (firstCol < 0) {
        firstCol = 0;
    }
    int32_t firstRow = mnCol - mnMaxDistCol;
    if (firstRow < 0) {
        firstRow = 0;
    }
    int32_t lastCol = mnMaxDistRow + mnRow;
    int32_t lastRow = mnMaxDistCol + mnCol;
    if (lastCol >= SCORE_AD4B48->mnRows) {
        lastCol = SCORE_AD4B48->mnRows - 1;
    }
    if (lastRow >= SCORE_AD4B48->mnCols) {
        lastRow = SCORE_AD4B48->mnCols - 1;
    }
    uint32_t span = (lastCol - firstCol + 1) * (lastRow - firstRow + 1);
    int32_t* rows = static_cast<int32_t*>(operator new(span * 4));
    int32_t* cols = static_cast<int32_t*>(operator new(span * 4));
    uint32_t count = 0;
    for (*rowPtr = firstCol; *rowPtr <= lastCol; ++*rowPtr) {
        for (*colPtr = firstRow; *colPtr <= lastRow; ++*colPtr) {
            Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[(*rowPtr << 6) + *colPtr]);
            if (cell->Fn0a_ad4b48() && cell->mpElem_ad4b48->mnType != 0x14 && !cell->mbDying_ad4b48) {
                rows[count] = *rowPtr;
                cols[count] = *colPtr;
                ++count;
            }
        }
    }
    if (count == 0) {
        return false;
    }
    uint32_t pick = static_cast<Random_ad4b48*>(mpRandom)->Uniform32() % count;
    *rowPtr = rows[pick];
    *colPtr = cols[pick];
    return true;
}
#endif

// The service that opens a record in the file (smart pointer filled by the 0x4496c0 accessor).
struct Opener_ad4b48 {
    uint32_t w[3];
    // STUB: 0x004496c0
    Opener_ad4b48();
    // STUB: 0x004495c0
    ~Opener_ad4b48();
};

struct RecordHandle_ad4b48 {
    virtual void Pad00_ad4b48();
    virtual void Pad01_ad4b48();
    virtual void Release_ad4b48();
};

struct Directory_ad4b48 {
    virtual bool Query_ad4b48(uint32_t id, void* out);
    virtual void Pad01_ad4b48();
    virtual void Release_ad4b48();
    virtual void Pad03_ad4b48();
    virtual void Pad04_ad4b48();
    virtual void Pad05_ad4b48();
    virtual void Pad06_ad4b48();
    virtual void Pad07_ad4b48();
    virtual void Pad08_ad4b48();
    virtual void Pad09_ad4b48();
    virtual void Pad0a_ad4b48();
    virtual void Pad0b_ad4b48();
    virtual void Pad0c_ad4b48();
    virtual void Pad0d_ad4b48();
    virtual void Pad0e_ad4b48();
    virtual void Pad0f_ad4b48();
    virtual void Pad10_ad4b48();
    virtual void Pad11_ad4b48();
    virtual void Pad12_ad4b48();
    virtual void Pad13_ad4b48();
    virtual void Pad14_ad4b48();
    virtual bool Fn15_ad4b48(uint32_t key, void** out, uint32_t flag);
};

struct Service_ad4b48 {
    virtual void Pad00_ad4b48();
    virtual void Pad01_ad4b48();
    virtual void Release_ad4b48();
    virtual void Pad03_ad4b48();
    virtual void Pad04_ad4b48();
    virtual void Pad05_ad4b48();
    virtual void Pad06_ad4b48();
    virtual void Pad07_ad4b48();
    virtual void Pad08_ad4b48();
    virtual void Pad09_ad4b48();
    virtual void Pad0a_ad4b48();
    virtual void Pad0b_ad4b48();
    virtual void Pad0c_ad4b48();
    virtual void Pad0d_ad4b48();
    virtual void Pad0e_ad4b48();
    virtual void Pad0f_ad4b48();
    virtual void Pad10_ad4b48();
    virtual void Pad11_ad4b48();
    virtual void Pad12_ad4b48();
    virtual void Pad13_ad4b48();
    virtual void Pad14_ad4b48();
    virtual void Pad15_ad4b48();
    virtual void Pad16_ad4b48();
    virtual void Pad17_ad4b48();
    virtual void Pad18_ad4b48();
    virtual void Pad19_ad4b48();
    virtual void Pad1a_ad4b48();
    virtual void Pad1b_ad4b48();
    virtual void Pad1c_ad4b48();
    virtual void Pad1d_ad4b48();
    virtual void Pad1e_ad4b48();
    virtual void Pad1f_ad4b48();
    virtual bool Fn20_ad4b48(uint32_t key, Directory_ad4b48** out);
};

// The serial record adapter built on the stack while the score is read.
struct SerialLocal_ad4b48 {
    uint32_t w[3];
    // STUB: 0x0096ec7c
    SerialLocal_ad4b48(void* record);
    // STUB: 0x0096dcbc
    void Close();
    // STUB: 0x0096e93a
    ~SerialLocal_ad4b48();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00947c38 score 33
bool cFreshPlayer::Init(uint32_t key)
{
    bool ok = false;
    SetKey(OB_PTR(const void, key));
    Opener_ad4b48 opener;
    Service_ad4b48* service = reinterpret_cast<Service_ad4b48*>(opener.w[1]);
    if (service) {
        Directory_ad4b48* directory = 0;
        if (service->Fn20_ad4b48(key, &directory)) {
            void* handle = 0;
            if (directory->Fn15_ad4b48(key, &handle, 1)) {
                void* record = 0;
                bool found = static_cast<Directory_ad4b48*>(handle)->Query_ad4b48(0xc56b8f08, &record);
                ok = false;
                if (found) {
                    SerialLocal_ad4b48 serial(record);
                    void* memory = operator new(0x4048);
                    mpScore = memory ? reinterpret_cast<ScoreRaw_ad4b48*>(memory)->Fn0094585f() : 0;
                    ok = reinterpret_cast<ScoreRaw_ad4b48*>(mpScore)->Fn00946a79(reinterpret_cast<Stream_ad4b48*>(&serial));
                    serial.Close();
                    static_cast<RecordHandle_ad4b48*>(record)->Release_ad4b48();
                }
                static_cast<RecordHandle_ad4b48*>(handle)->Release_ad4b48();
            }
            directory->Release_ad4b48();
            if (ok) {
                return Slot04_ad4b48();
            }
        }
    }
    return false;
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0094832a score 69
bool cFreshPlayer::FadeVolume(uint32_t target, uint32_t start, uint32_t stopAtEnd)
{
    Guard_ad4b48 guard(&gB634ac);
    Timer_ad4b48 scratch(4);
    if (!mbInitialized || mbPlaying) {
        // fall through to the cleanup below
    }
    if (!mbInitialized || !mbPlaying) {
        scratch.Destroy_ad4b48();
        return false;
    }
    int32_t step = (static_cast<int32_t>(start) - mnVolume) / 20;
    U8_AD4B48(0x40a0) = static_cast<uint8_t>(stopAtEnd);
    U32_AD4B48(0x409c) = start;
    U32_AD4B48(0x4098) = step;
    if (step == 0) {
        SetVolume(start);
        if (stopAtEnd & 0xff) {
            Stop();
        }
    } else if (!mbFading) {
        Fade_ad4b48* fade = 0;
        void* memory = operator new(0x28);
        mpFade = memory;
        (void)fade;
        mbFading = true;
    }
    scratch.Destroy_ad4b48();
    return true;
}
#endif

// GLOBAL: 0x00b634a8
extern uint32_t gB634a8;
// GLOBAL: 0x00b634b4
extern uint32_t gB634b4;
// GLOBAL: 0x00b634b8
extern uint32_t gB634b8;
// GLOBAL: 0x00b634bc
extern uint32_t gB634bc;
// GLOBAL: 0x00b634c0
extern uint32_t gB634c0;
// GLOBAL: 0x00b634c4
extern uint32_t gB634c4;
// GLOBAL: 0x00b634c8
extern uint32_t gB634c8;
// GLOBAL: 0x00b634cc
extern uint32_t gB634cc;

#ifdef OB_DRAFTS
// CLOSE: 0x00947f58 score 227
void cFreshPlayer::Slot13_ad3e48(uint32_t unused)
{
    int32_t minCells = GetMinCellsPlaying();
    int32_t maxCells = GetMaxCellsPlaying();
    int32_t group = 0;
    if (mbInitialized && mbPlaying && !U8_AD4B48(0x4090)) {
        Guard_ad4b48 guard(&gB634ac);
        Timer_ad4b48* timer = static_cast<Timer_ad4b48*>(mpTimer);
        ++gB634cc;
        if (!(gB634c8 & 1)) {
            gB634c8 |= 1;
            gB634c4 = timer->GetElapsedTime_ad4b48();
        }
        if (timer->GetElapsedTime_ad4b48() - gB634c4 > 10000) {
            gB634cc = 0;
            gB634c0 = 0;
            gB634bc = 0;
            gB634a8 = 0;
            gB634b8 = 0;
            gB634c4 = timer->GetElapsedTime_ad4b48();
        }
        uint32_t now = timer->GetElapsedTime_ad4b48();
        gB634b4 = now;
        uint32_t due = Fn009475fb(mn40);
        while (due <= now) {
            int32_t length = SCORE_AD4B48->mn34;
            if (now > 86400000) {
                mn44 = length;
                mn3c = length;
                mn40 = length;
                timer->Restart_ad4b48();
                timer->GetElapsedTime_ad4b48();
                break;
            }
            ++gB634c0;
            int32_t type = 0;
            int32_t row = 0;
            int32_t col = 0;
            if ((mnCellsBusy == length - 1 || mnCellsBusy == length - 6)) {
                int32_t playing = NumCellsPlaying();
                if (SCORE_AD4B48->mn0c != 0 && !mbManual && minCells <= playing
                    && GetCellToSubtract(OB_ADDR(&row), OB_ADDR(&col))) {
                    Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[(row << 6) + col]);
                    cell->mbDying_ad4b48 = true;
                    Elem_ad4b48* elem = cell->mpElem_ad4b48;
                    group = elem->mnGroup;
                    if (group != 0) {
                        type = elem->mnType;
                    }
                }
            }
            int32_t dying = NumCellsDying();
            int32_t busy = NumCellsBusy();
            length = SCORE_AD4B48->mn34;
            int32_t active = busy - dying;
            if ((mnCellsBusy == length - 1 || mnCellsBusy == length - 6) && !U8_AD4B48(0x4091) && !mbManual
                && active < maxCells && mnPlayPercent != 0) {
                bool found = GetCellToAdd(OB_ADDR(&row), OB_ADDR(&col), group);
                ++gB634bc;
                if (!found) {
                    if (group != 0 && type == 0x13) {
                        found = GetCellToAdd(OB_ADDR(&row), OB_ADDR(&col), group);
                    }
                    if (!found && active < minCells) {
                        found = GetCellToAdd(OB_ADDR(&row), OB_ADDR(&col), group);
                        ++gB634bc;
                    }
                }
                if (found) {
                    Cell_ad4b48* cell = static_cast<Cell_ad4b48*>(mpCells[(row << 6) + col]);
                    if (CalculateCellplayer3DPosition(cell)) {
                        ++gB634a8;
                        cell->Init_ad4b48(SCORE_AD4B48->mpElems[(row << 6) + col]);
                        cell->Fn12_ad4b48(U32_AD4B48(0x4140));
                        cell->Fn05_ad4b48();
                        mnSelRow = row;
                        mn64 = col;
                    }
                }
            }
            for (row = 0; row < SCORE_AD4B48->mnRows; ++row) {
                for (col = 0; col < SCORE_AD4B48->mnCols; ++col) {
                    if (mpCells[(row << 6) + col]) {
                        static_cast<Cell_ad4b48*>(mpCells[(row << 6) + col])->Fn06_ad4b48();
                    }
                }
            }
            ++mnCellsBusy;
            if (SCORE_AD4B48->mn34 < mnCellsBusy) {
                mnCellsBusy = 1;
            }
            ++mn40;
            due = Fn009475fb(mn40);
        }
    }
}
#endif

// STUB: 0x0091c2c5
void Fn0091c2c5(void* object, void* source);

// STUB: 0x0091c54d
cRZString Fn0091c54d(void* object);

// STUB: 0x00918da0
void Fn00918da0(void* object);

// A path split into directory and file name.
struct PathParts_ad4b48 {
    uint32_t w[0x10];
    cRZString* Fn0091c37e();
};

#ifdef OB_DRAFTS
// CLOSE: 0x00948cb4 score 55
bool cFreshPlayer::Slot38_ad4b48(void* path)
{
    PathParts_ad4b48 parts;
    Fn0091c2c5(&parts, path);
    cRZString directory(*parts.Fn0091c37e(), 0, 0xffffffff);
    cRZString name(Fn0091c54d(&parts), 0, 0xffffffff);
    return Init_2(OB_ADDR(&directory), OB_ADDR(&name));
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x00948d5f score 62
bool cFreshPlayer::Init_2(uint32_t directory, uint32_t name)
{
    void* memory = operator new(0x4048);
    mpScore = memory ? reinterpret_cast<ScoreRaw_ad4b48*>(memory)->Fn0094585f() : 0;
    const std::string* first = directory ? static_cast<const std::string*>(OB_PTR(const cRZString, directory)) : 0;
    const std::string* second = name ? static_cast<const std::string*>(OB_PTR(const cRZString, name)) : 0;
    cRZString joined(first ? *first : std::string(), 0, 0xffffffff);
    (void)second;
    reinterpret_cast<ScoreRaw_ad4b48*>(mpScore)->Fn00946b30(joined, 0, 0);
    return Init_3(mpScore, OB_PTR(void, name));
}
#endif

// STUB: 0x005f8fe0
bool Fn005f8fe0(int32_t character);

#ifdef OB_DRAFTS
// CLOSE: 0x0091c32d score 17
void Fn0091c32d(cRZString* path)
{
    std::string& text = *path;
    if (!text.empty()) {
        if (!Fn005f8fe0(text[0])) {
            text.insert(0, "\\");
        }
        if (!Fn005f8fe0(text[text.size() - 1])) {
            text.append("\\");
        }
    }
}
#endif

#ifdef OB_DRAFTS
// CLOSE: 0x0091c37e score 1
cRZString* PathParts_ad4b48::Fn0091c37e()
{
    cRZString* directory = reinterpret_cast<cRZString*>(&w[5]);
    Fn0091c32d(directory);
    return directory;
}
#endif
