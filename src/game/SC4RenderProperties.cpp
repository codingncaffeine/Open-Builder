#include <string>
#include <vector>
#include "common/types.h"

// The render settings: one record per setting (id, name, an unused text, then three values), filled in by the
// constructors of the little marker classes of cSC4RenderProperties::cProperties and pushed on a list per value type.
template <class T>
struct cSC4RenderProperty_ab3b00 {
    int mnId;
    std::string msName;
    std::string msText;
    T mValue;
    T mMin;
    T mMax;
};

// GLOBAL: 0x00b4e3a4
extern std::vector<cSC4RenderProperty_ab3b00<bool> > gm_boolProperties;
// GLOBAL: 0x00b4e3b0
extern std::vector<cSC4RenderProperty_ab3b00<int> > gm_intProperties;
// GLOBAL: 0x00b4e3bc
extern std::vector<cSC4RenderProperty_ab3b00<float> > gm_floatProperties;

class cSC4RenderProperties {
public:
    class cProperties {
    public:

        class cRegkForceSoftwareDriver {
        public:
            // STUB: 0x007deed0
            cRegkForceSoftwareDriver();
        };
        class cRegkRenderDynamicView {
        public:
            // STUB: 0x007defa0
            cRegkRenderDynamicView();
        };
        class cRegkRenderStaticView {
        public:
            // STUB: 0x007df080
            cRegkRenderStaticView();
        };
        class cRegkRenderWaterEffects {
        public:
            // STUB: 0x007df160
            cRegkRenderWaterEffects();
        };
        class cRegkRenderCloudsAndFog {
        public:
            // STUB: 0x007df240
            cRegkRenderCloudsAndFog();
        };
        class cRegkForcePointSampling {
        public:
            // STUB: 0x007df320
            cRegkForcePointSampling();
        };
        class cRegkForceBilinear {
        public:
            // STUB: 0x007df400
            cRegkForceBilinear();
        };
        class cRegkForceNoAlphaBlend {
        public:
            // STUB: 0x007df4e0
            cRegkForceNoAlphaBlend();
        };
        class cRegkForceNoAlphaTest {
        public:
            // STUB: 0x007df5c0
            cRegkForceNoAlphaTest();
        };
        class cRegkRenderShadows {
        public:
            // STUB: 0x007df6a0
            cRegkRenderShadows();
        };
        class cRegkRenderDecals {
        public:
            // STUB: 0x007df780
            cRegkRenderDecals();
        };
        class cRegkUseSecondStage {
        public:
            // STUB: 0x007df860
            cRegkUseSecondStage();
        };
        class cRegkForceDebugTexture {
        public:
            // STUB: 0x007df940
            cRegkForceDebugTexture();
        };
        class cRegkRenderParticleEffects {
        public:
            // STUB: 0x007dfa20
            cRegkRenderParticleEffects();
        };
        class cRegkRenderFloraShadows {
        public:
            // STUB: 0x007dfb00
            cRegkRenderFloraShadows();
        };
        class cRegkRenderTerrain {
        public:
            // STUB: 0x007dfbe0
            cRegkRenderTerrain();
        };
        class cRegkShowUpdateRegions {
        public:
            // STUB: 0x007dfcc0
            cRegkShowUpdateRegions();
        };
        class cRegkUseCursorEffects {
        public:
            // STUB: 0x007dfda0
            cRegkUseCursorEffects();
        };
        class cRegkDrawLotTextures {
        public:
            // STUB: 0x007dfe80
            cRegkDrawLotTextures();
        };
        class cRegkDrawLotFoundations {
        public:
            // STUB: 0x007dff60
            cRegkDrawLotFoundations();
        };
        class cRegkDrawLotWalls {
        public:
            // STUB: 0x007e0040
            cRegkDrawLotWalls();
        };
        class cRegkForceTextureRepeat {
        public:
            // STUB: 0x007e0120
            cRegkForceTextureRepeat();
        };
        class cRegkUseScreenShake {
        public:
            // STUB: 0x007e0200
            cRegkUseScreenShake();
        };
        class cRegkRenderUI {
        public:
            // STUB: 0x007e02e0
            cRegkRenderUI();
        };
        class cRegkUseUpdateRectClipping {
        public:
            // STUB: 0x007e03c0
            cRegkUseUpdateRectClipping();
        };
        class cRegkUseVertexBuffers {
        public:
            // STUB: 0x007e04a0
            cRegkUseVertexBuffers();
        };
        class cRegkShowBoundingBoxes {
        public:
            // STUB: 0x007e0580
            cRegkShowBoundingBoxes();
        };
        class cRegkUseOverlayCulling {
        public:
            // STUB: 0x007e0660
            cRegkUseOverlayCulling();
        };
        class cRegkRenderSnapshot {
        public:
            // STUB: 0x007e0740
            cRegkRenderSnapshot();
        };
        class cRegkNoAddSigned {
        public:
            // STUB: 0x007e0820
            cRegkNoAddSigned();
        };
        class cRegkNoPartialBackingStoreCopies {
        public:
            // STUB: 0x007e0900
            cRegkNoPartialBackingStoreCopies();
        };
        class cRegkUseScreenFlash {
        public:
            // STUB: 0x007e09e0
            cRegkUseScreenFlash();
        };
        class cRegkRenderAutomata {
        public:
            // STUB: 0x007e0ac0
            cRegkRenderAutomata();
        };
        class cRegkPreferOpaque {
        public:
            // STUB: 0x007e0ba0
            cRegkPreferOpaque();
        };
        class cRegkDisplayAlertBorders {
        public:
            // STUB: 0x007e0c80
            cRegkDisplayAlertBorders();
        };
        class cRegkDrawLotOpaqueTextures {
        public:
            // STUB: 0x007e0d60
            cRegkDrawLotOpaqueTextures();
        };
        class cRegkUseViewCleanup {
        public:
            // STUB: 0x007e0e40
            cRegkUseViewCleanup();
        };
        class cRegkDoAutoZoomAndRotationChanges {
        public:
            // STUB: 0x007e0f20
            cRegkDoAutoZoomAndRotationChanges();
        };
        class cRegkViewOffsetY {
        public:
            // STUB: 0x007e1000
            cRegkViewOffsetY();
        };
        class cRegkViewOffsetX {
        public:
            // STUB: 0x007e10d0
            cRegkViewOffsetX();
        };
        class cRegkTextureBits {
        public:
            // STUB: 0x007e11b0
            cRegkTextureBits();
        };
        class cRegkLODOffset {
        public:
            // STUB: 0x007e1290
            cRegkLODOffset();
        };
        class cRegkShadowDebug {
        public:
            // STUB: 0x007e1370
            cRegkShadowDebug();
        };
        class cRegkMaxParticlesTarget {
        public:
            // STUB: 0x007e1450
            cRegkMaxParticlesTarget();
        };
        class cRegkParticleLODOffset {
        public:
            // STUB: 0x007e1530
            cRegkParticleLODOffset();
        };
        class cRegkEffectPriorityLevel {
        public:
            // STUB: 0x007e1610
            cRegkEffectPriorityLevel();
        };
        class cRegkBackingStoreMaxZoomAll {
        public:
            // STUB: 0x007e16f0
            cRegkBackingStoreMaxZoomAll();
        };
        class cRegkBackingStoreMaxZoomBuildingsProps {
        public:
            // STUB: 0x007e17d0
            cRegkBackingStoreMaxZoomBuildingsProps();
        };
        class cRegkBackingStoreMaxZoomTerrain {
        public:
            // STUB: 0x007e18b0
            cRegkBackingStoreMaxZoomTerrain();
        };
        class cRegkBackingStoreMaxZoomFlora {
        public:
            // STUB: 0x007e1990
            cRegkBackingStoreMaxZoomFlora();
        };
        class cRegkShadowQuality {
        public:
            // STUB: 0x007e1a70
            cRegkShadowQuality();
        };
        class cRegkMinVehicleZoom {
        public:
            // STUB: 0x007e1b50
            cRegkMinVehicleZoom();
        };
        class cRegkMinPedZoom {
        public:
            // STUB: 0x007e1c30
            cRegkMinPedZoom();
        };
        class cRegkCursorType {
        public:
            // STUB: 0x007e1d10
            cRegkCursorType();
        };
        class cRegkDepthOffset {
        public:
            // STUB: 0x007e1df0
            cRegkDepthOffset();
        };
        class cRegkDebugTexture {
        public:
            // STUB: 0x007e1ed0
            cRegkDebugTexture();
        };
        class cRegkDirtyRectMergeFrames {
        public:
            // STUB: 0x007e1fb0
            cRegkDirtyRectMergeFrames();
        };
        class cRegkSoundDetail {
        public:
            // STUB: 0x007e2090
            cRegkSoundDetail();
        };
        class cRegkBuildingVariety {
        public:
            // STUB: 0x007e2170
            cRegkBuildingVariety();
        };
        class cRegkBuildingLoaderSpeed {
        public:
            // STUB: 0x007e2250
            cRegkBuildingLoaderSpeed();
        };
        class cRegkModelLODOffset {
        public:
            // STUB: 0x007e2330
            cRegkModelLODOffset();
        };
        class cRegkStringTextureCacheSize {
        public:
            // STUB: 0x007e2410
            cRegkStringTextureCacheSize();
        };
        class cRegkParticleEffectsLOD {
        public:
            // STUB: 0x007e24f0
            cRegkParticleEffectsLOD();
        };
        class cRegkSplatTextureScale {
        public:
            // STUB: 0x007e25d0
            cRegkSplatTextureScale();
        };
        class cRegkTexBindMaxFree {
        public:
            // STUB: 0x007e26b0
            cRegkTexBindMaxFree();
        };
        class cRegkParticleDensity {
        public:
            // STUB: 0x007e2790
            cRegkParticleDensity();
        };
        class cRegkParticleDamping {
        public:
            // STUB: 0x007e2870
            cRegkParticleDamping();
        };
        class cRegkParticleScale {
        public:
            // STUB: 0x007e2950
            cRegkParticleScale();
        };
        class cRegkLightingUpdateDelta {
        public:
            // STUB: 0x007e2a30
            cRegkLightingUpdateDelta();
        };
        class cRegkShadowModelThreshold {
        public:
            // STUB: 0x007e2b10
            cRegkShadowModelThreshold();
        };
        class cRegkDemolishModelThreshold {
        public:
            // STUB: 0x007e2bf0
            cRegkDemolishModelThreshold();
        };
        class cRegkRenderModelThreshold {
        public:
            // STUB: 0x007e2cd0
            cRegkRenderModelThreshold();
        };
        class cRegkRenderModelThresholdScroll {
        public:
            // STUB: 0x007e2db0
            cRegkRenderModelThresholdScroll();
        };
        class cRegkParticleSizeThreshold {
        public:
            // STUB: 0x007e2e90
            cRegkParticleSizeThreshold();
        };
        class cRegkMaxVehiclePct {
        public:
            // STUB: 0x007e2f70
            cRegkMaxVehiclePct();
        };
        class cRegkMaxPedPct {
        public:
            // STUB: 0x007e3050
            cRegkMaxPedPct();
        };
        class cRegkOpaqueUIAlphaValue {
        public:
            // STUB: 0x007e3130
            cRegkOpaqueUIAlphaValue();
        };
        cRegkForceSoftwareDriver mForceSoftwareDriver;
        cRegkRenderDynamicView mRenderDynamicView;
        cRegkRenderStaticView mRenderStaticView;
        cRegkRenderWaterEffects mRenderWaterEffects;
        cRegkRenderCloudsAndFog mRenderCloudsAndFog;
        cRegkForcePointSampling mForcePointSampling;
        cRegkForceBilinear mForceBilinear;
        cRegkForceNoAlphaBlend mForceNoAlphaBlend;
        cRegkForceNoAlphaTest mForceNoAlphaTest;
        cRegkRenderShadows mRenderShadows;
        cRegkRenderDecals mRenderDecals;
        cRegkUseSecondStage mUseSecondStage;
        cRegkForceDebugTexture mForceDebugTexture;
        cRegkRenderParticleEffects mRenderParticleEffects;
        cRegkRenderFloraShadows mRenderFloraShadows;
        cRegkRenderTerrain mRenderTerrain;
        cRegkShowUpdateRegions mShowUpdateRegions;
        cRegkUseCursorEffects mUseCursorEffects;
        cRegkDrawLotTextures mDrawLotTextures;
        cRegkDrawLotFoundations mDrawLotFoundations;
        cRegkDrawLotWalls mDrawLotWalls;
        cRegkForceTextureRepeat mForceTextureRepeat;
        cRegkUseScreenShake mUseScreenShake;
        cRegkRenderUI mRenderUI;
        cRegkUseUpdateRectClipping mUseUpdateRectClipping;
        cRegkUseVertexBuffers mUseVertexBuffers;
        cRegkShowBoundingBoxes mShowBoundingBoxes;
        cRegkUseOverlayCulling mUseOverlayCulling;
        cRegkRenderSnapshot mRenderSnapshot;
        cRegkNoAddSigned mNoAddSigned;
        cRegkNoPartialBackingStoreCopies mNoPartialBackingStoreCopies;
        cRegkUseScreenFlash mUseScreenFlash;
        cRegkRenderAutomata mRenderAutomata;
        cRegkPreferOpaque mPreferOpaque;
        cRegkDisplayAlertBorders mDisplayAlertBorders;
        cRegkDrawLotOpaqueTextures mDrawLotOpaqueTextures;
        cRegkUseViewCleanup mUseViewCleanup;
        cRegkDoAutoZoomAndRotationChanges mDoAutoZoomAndRotationChanges;
        cRegkViewOffsetY mViewOffsetY;
        cRegkViewOffsetX mViewOffsetX;
        cRegkTextureBits mTextureBits;
        cRegkLODOffset mLODOffset;
        cRegkShadowDebug mShadowDebug;
        cRegkMaxParticlesTarget mMaxParticlesTarget;
        cRegkParticleLODOffset mParticleLODOffset;
        cRegkEffectPriorityLevel mEffectPriorityLevel;
        cRegkBackingStoreMaxZoomAll mBackingStoreMaxZoomAll;
        cRegkBackingStoreMaxZoomBuildingsProps mBackingStoreMaxZoomBuildingsProps;
        cRegkBackingStoreMaxZoomTerrain mBackingStoreMaxZoomTerrain;
        cRegkBackingStoreMaxZoomFlora mBackingStoreMaxZoomFlora;
        cRegkShadowQuality mShadowQuality;
        cRegkMinVehicleZoom mMinVehicleZoom;
        cRegkMinPedZoom mMinPedZoom;
        cRegkCursorType mCursorType;
        cRegkDepthOffset mDepthOffset;
        cRegkDebugTexture mDebugTexture;
        cRegkDirtyRectMergeFrames mDirtyRectMergeFrames;
        cRegkSoundDetail mSoundDetail;
        cRegkBuildingVariety mBuildingVariety;
        cRegkBuildingLoaderSpeed mBuildingLoaderSpeed;
        cRegkModelLODOffset mModelLODOffset;
        cRegkStringTextureCacheSize mStringTextureCacheSize;
        cRegkParticleEffectsLOD mParticleEffectsLOD;
        cRegkSplatTextureScale mSplatTextureScale;
        cRegkTexBindMaxFree mTexBindMaxFree;
        cRegkParticleDensity mParticleDensity;
        cRegkParticleDamping mParticleDamping;
        cRegkParticleScale mParticleScale;
        cRegkLightingUpdateDelta mLightingUpdateDelta;
        cRegkShadowModelThreshold mShadowModelThreshold;
        cRegkDemolishModelThreshold mDemolishModelThreshold;
        cRegkRenderModelThreshold mRenderModelThreshold;
        cRegkRenderModelThresholdScroll mRenderModelThresholdScroll;
        cRegkParticleSizeThreshold mParticleSizeThreshold;
        cRegkMaxVehiclePct mMaxVehiclePct;
        cRegkMaxPedPct mMaxPedPct;
        cRegkOpaqueUIAlphaValue mOpaqueUIAlphaValue;
        cProperties();
    };
};

// FUNCTION: 0x007deed0
cSC4RenderProperties::cProperties::cRegkForceSoftwareDriver::cRegkForceSoftwareDriver()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 0;
    prop.msName = "kForceSoftwareDriver";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007defa0
cSC4RenderProperties::cProperties::cRegkRenderDynamicView::cRegkRenderDynamicView()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 1;
    prop.msName = "kRenderDynamicView";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df080
cSC4RenderProperties::cProperties::cRegkRenderStaticView::cRegkRenderStaticView()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 2;
    prop.msName = "kRenderStaticView";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df160
cSC4RenderProperties::cProperties::cRegkRenderWaterEffects::cRegkRenderWaterEffects()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 3;
    prop.msName = "kRenderWaterEffects";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df240
cSC4RenderProperties::cProperties::cRegkRenderCloudsAndFog::cRegkRenderCloudsAndFog()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 4;
    prop.msName = "kRenderCloudsAndFog";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df320
cSC4RenderProperties::cProperties::cRegkForcePointSampling::cRegkForcePointSampling()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 5;
    prop.msName = "kForcePointSampling";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df400
cSC4RenderProperties::cProperties::cRegkForceBilinear::cRegkForceBilinear()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 6;
    prop.msName = "kForceBilinear";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df4e0
cSC4RenderProperties::cProperties::cRegkForceNoAlphaBlend::cRegkForceNoAlphaBlend()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 7;
    prop.msName = "kForceNoAlphaBlend";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df5c0
cSC4RenderProperties::cProperties::cRegkForceNoAlphaTest::cRegkForceNoAlphaTest()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 8;
    prop.msName = "kForceNoAlphaTest";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df6a0
cSC4RenderProperties::cProperties::cRegkRenderShadows::cRegkRenderShadows()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 9;
    prop.msName = "kRenderShadows";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df780
cSC4RenderProperties::cProperties::cRegkRenderDecals::cRegkRenderDecals()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 10;
    prop.msName = "kRenderDecals";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df860
cSC4RenderProperties::cProperties::cRegkUseSecondStage::cRegkUseSecondStage()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 11;
    prop.msName = "kUseSecondStage";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007df940
cSC4RenderProperties::cProperties::cRegkForceDebugTexture::cRegkForceDebugTexture()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 12;
    prop.msName = "kForceDebugTexture";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007dfa20
cSC4RenderProperties::cProperties::cRegkRenderParticleEffects::cRegkRenderParticleEffects()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 13;
    prop.msName = "kRenderParticleEffects";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007dfb00
cSC4RenderProperties::cProperties::cRegkRenderFloraShadows::cRegkRenderFloraShadows()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 14;
    prop.msName = "kRenderFloraShadows";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007dfbe0
cSC4RenderProperties::cProperties::cRegkRenderTerrain::cRegkRenderTerrain()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 15;
    prop.msName = "kRenderTerrain";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007dfcc0
cSC4RenderProperties::cProperties::cRegkShowUpdateRegions::cRegkShowUpdateRegions()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 16;
    prop.msName = "kShowUpdateRegions";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007dfda0
cSC4RenderProperties::cProperties::cRegkUseCursorEffects::cRegkUseCursorEffects()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 17;
    prop.msName = "kUseCursorEffects";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007dfe80
cSC4RenderProperties::cProperties::cRegkDrawLotTextures::cRegkDrawLotTextures()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 18;
    prop.msName = "kDrawLotTextures";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007dff60
cSC4RenderProperties::cProperties::cRegkDrawLotFoundations::cRegkDrawLotFoundations()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 19;
    prop.msName = "kDrawLotFoundations";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0040
cSC4RenderProperties::cProperties::cRegkDrawLotWalls::cRegkDrawLotWalls()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 20;
    prop.msName = "kDrawLotWalls";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0120
cSC4RenderProperties::cProperties::cRegkForceTextureRepeat::cRegkForceTextureRepeat()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 21;
    prop.msName = "kForceTextureRepeat";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0200
cSC4RenderProperties::cProperties::cRegkUseScreenShake::cRegkUseScreenShake()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 22;
    prop.msName = "kUseScreenShake";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e02e0
cSC4RenderProperties::cProperties::cRegkRenderUI::cRegkRenderUI()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 23;
    prop.msName = "kRenderUI";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e03c0
cSC4RenderProperties::cProperties::cRegkUseUpdateRectClipping::cRegkUseUpdateRectClipping()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 24;
    prop.msName = "kUseUpdateRectClipping";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e04a0
cSC4RenderProperties::cProperties::cRegkUseVertexBuffers::cRegkUseVertexBuffers()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 25;
    prop.msName = "kUseVertexBuffers";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0580
cSC4RenderProperties::cProperties::cRegkShowBoundingBoxes::cRegkShowBoundingBoxes()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 26;
    prop.msName = "kShowBoundingBoxes";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0660
cSC4RenderProperties::cProperties::cRegkUseOverlayCulling::cRegkUseOverlayCulling()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 27;
    prop.msName = "kUseOverlayCulling";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0740
cSC4RenderProperties::cProperties::cRegkRenderSnapshot::cRegkRenderSnapshot()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 28;
    prop.msName = "kRenderSnapshot";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0820
cSC4RenderProperties::cProperties::cRegkNoAddSigned::cRegkNoAddSigned()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 29;
    prop.msName = "kNoAddSigned";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0900
cSC4RenderProperties::cProperties::cRegkNoPartialBackingStoreCopies::cRegkNoPartialBackingStoreCopies()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 30;
    prop.msName = "kNoPartialBackingStoreCopies";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e09e0
cSC4RenderProperties::cProperties::cRegkUseScreenFlash::cRegkUseScreenFlash()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 31;
    prop.msName = "kUseScreenFlash";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0ac0
cSC4RenderProperties::cProperties::cRegkRenderAutomata::cRegkRenderAutomata()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 32;
    prop.msName = "kRenderAutomata";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0ba0
cSC4RenderProperties::cProperties::cRegkPreferOpaque::cRegkPreferOpaque()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 33;
    prop.msName = "kPreferOpaque";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0c80
cSC4RenderProperties::cProperties::cRegkDisplayAlertBorders::cRegkDisplayAlertBorders()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 34;
    prop.msName = "kDisplayAlertBorders";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0d60
cSC4RenderProperties::cProperties::cRegkDrawLotOpaqueTextures::cRegkDrawLotOpaqueTextures()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 35;
    prop.msName = "kDrawLotOpaqueTextures";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0e40
cSC4RenderProperties::cProperties::cRegkUseViewCleanup::cRegkUseViewCleanup()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 36;
    prop.msName = "kUseViewCleanup";
    prop.mValue = false;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e0f20
cSC4RenderProperties::cProperties::cRegkDoAutoZoomAndRotationChanges::cRegkDoAutoZoomAndRotationChanges()
{
    cSC4RenderProperty_ab3b00<bool> prop;
    prop.mnId = 37;
    prop.msName = "kDoAutoZoomAndRotationChanges";
    prop.mValue = true;
    prop.mMin = false;
    prop.mMax = false;
    gm_boolProperties.push_back(prop);
}

// FUNCTION: 0x007e1000
cSC4RenderProperties::cProperties::cRegkViewOffsetY::cRegkViewOffsetY()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 0;
    prop.msName = "kViewOffsetY";
    prop.mValue = 0;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e10d0
cSC4RenderProperties::cProperties::cRegkViewOffsetX::cRegkViewOffsetX()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 1;
    prop.msName = "kViewOffsetX";
    prop.mValue = 0;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e11b0
cSC4RenderProperties::cProperties::cRegkTextureBits::cRegkTextureBits()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 2;
    prop.msName = "kTextureBits";
    prop.mValue = 32;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1290
cSC4RenderProperties::cProperties::cRegkLODOffset::cRegkLODOffset()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 3;
    prop.msName = "kLODOffset";
    prop.mValue = 0;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1370
cSC4RenderProperties::cProperties::cRegkShadowDebug::cRegkShadowDebug()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 4;
    prop.msName = "kShadowDebug";
    prop.mValue = 0;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1450
cSC4RenderProperties::cProperties::cRegkMaxParticlesTarget::cRegkMaxParticlesTarget()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 5;
    prop.msName = "kMaxParticlesTarget";
    prop.mValue = 10000;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1530
cSC4RenderProperties::cProperties::cRegkParticleLODOffset::cRegkParticleLODOffset()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 6;
    prop.msName = "kParticleLODOffset";
    prop.mValue = 0;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1610
cSC4RenderProperties::cProperties::cRegkEffectPriorityLevel::cRegkEffectPriorityLevel()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 7;
    prop.msName = "kEffectPriorityLevel";
    prop.mValue = 5;
    prop.mMin = 1;
    prop.mMax = 5;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e16f0
cSC4RenderProperties::cProperties::cRegkBackingStoreMaxZoomAll::cRegkBackingStoreMaxZoomAll()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 8;
    prop.msName = "kBackingStoreMaxZoomAll";
    prop.mValue = 5;
    prop.mMin = 0;
    prop.mMax = 5;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e17d0
cSC4RenderProperties::cProperties::cRegkBackingStoreMaxZoomBuildingsProps::cRegkBackingStoreMaxZoomBuildingsProps()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 9;
    prop.msName = "kBackingStoreMaxZoomBuildingsProps";
    prop.mValue = 5;
    prop.mMin = 0;
    prop.mMax = 5;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e18b0
cSC4RenderProperties::cProperties::cRegkBackingStoreMaxZoomTerrain::cRegkBackingStoreMaxZoomTerrain()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 10;
    prop.msName = "kBackingStoreMaxZoomTerrain";
    prop.mValue = 5;
    prop.mMin = 0;
    prop.mMax = 5;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1990
cSC4RenderProperties::cProperties::cRegkBackingStoreMaxZoomFlora::cRegkBackingStoreMaxZoomFlora()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 11;
    prop.msName = "kBackingStoreMaxZoomFlora";
    prop.mValue = 5;
    prop.mMin = 0;
    prop.mMax = 5;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1a70
cSC4RenderProperties::cProperties::cRegkShadowQuality::cRegkShadowQuality()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 12;
    prop.msName = "kShadowQuality";
    prop.mValue = 2;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1b50
cSC4RenderProperties::cProperties::cRegkMinVehicleZoom::cRegkMinVehicleZoom()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 13;
    prop.msName = "kMinVehicleZoom";
    prop.mValue = 3;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1c30
cSC4RenderProperties::cProperties::cRegkMinPedZoom::cRegkMinPedZoom()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 14;
    prop.msName = "kMinPedZoom";
    prop.mValue = 4;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1d10
cSC4RenderProperties::cProperties::cRegkCursorType::cRegkCursorType()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 15;
    prop.msName = "kCursorType";
    prop.mValue = 1;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1df0
cSC4RenderProperties::cProperties::cRegkDepthOffset::cRegkDepthOffset()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 16;
    prop.msName = "kDepthOffset";
    prop.mValue = 2;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1ed0
cSC4RenderProperties::cProperties::cRegkDebugTexture::cRegkDebugTexture()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 17;
    prop.msName = "kDebugTexture";
    prop.mValue = 0;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e1fb0
cSC4RenderProperties::cProperties::cRegkDirtyRectMergeFrames::cRegkDirtyRectMergeFrames()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 18;
    prop.msName = "kDirtyRectMergeFrames";
    prop.mValue = 4;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e2090
cSC4RenderProperties::cProperties::cRegkSoundDetail::cRegkSoundDetail()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 19;
    prop.msName = "kSoundDetail";
    prop.mValue = 2;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e2170
cSC4RenderProperties::cProperties::cRegkBuildingVariety::cRegkBuildingVariety()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 20;
    prop.msName = "kBuildingVariety";
    prop.mValue = 2;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e2250
cSC4RenderProperties::cProperties::cRegkBuildingLoaderSpeed::cRegkBuildingLoaderSpeed()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 21;
    prop.msName = "kBuildingLoaderSpeed";
    prop.mValue = 1;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e2330
cSC4RenderProperties::cProperties::cRegkModelLODOffset::cRegkModelLODOffset()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 22;
    prop.msName = "kModelLODOffset";
    prop.mValue = 0;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e2410
cSC4RenderProperties::cProperties::cRegkStringTextureCacheSize::cRegkStringTextureCacheSize()
{
    cSC4RenderProperty_ab3b00<int> prop;
    prop.mnId = 23;
    prop.msName = "kStringTextureCacheSize";
    prop.mValue = 1024;
    prop.mMin = 0;
    prop.mMax = 0;
    gm_intProperties.push_back(prop);
}

// FUNCTION: 0x007e24f0
cSC4RenderProperties::cProperties::cRegkParticleEffectsLOD::cRegkParticleEffectsLOD()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 0;
    prop.msName = "kParticleEffectsLOD";
    prop.mValue = 5.0f;
    prop.mMin = 1.0f;
    prop.mMax = 10.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e25d0
cSC4RenderProperties::cProperties::cRegkSplatTextureScale::cRegkSplatTextureScale()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 1;
    prop.msName = "kSplatTextureScale";
    prop.mValue = 50.0f;
    prop.mMin = 1.0f;
    prop.mMax = 128.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e26b0
cSC4RenderProperties::cProperties::cRegkTexBindMaxFree::cRegkTexBindMaxFree()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 2;
    prop.msName = "kTexBindMaxFree";
    prop.mValue = 2.0f;
    prop.mMin = 0.0f;
    prop.mMax = 32.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2790
cSC4RenderProperties::cProperties::cRegkParticleDensity::cRegkParticleDensity()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 3;
    prop.msName = "kParticleDensity";
    prop.mValue = 1.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2870
cSC4RenderProperties::cProperties::cRegkParticleDamping::cRegkParticleDamping()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 4;
    prop.msName = "kParticleDamping";
    prop.mValue = 0.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2950
cSC4RenderProperties::cProperties::cRegkParticleScale::cRegkParticleScale()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 5;
    prop.msName = "kParticleScale";
    prop.mValue = 1.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2a30
cSC4RenderProperties::cProperties::cRegkLightingUpdateDelta::cRegkLightingUpdateDelta()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 6;
    prop.msName = "kLightingUpdateDelta";
    prop.mValue = 9.99999975e-05f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2b10
cSC4RenderProperties::cProperties::cRegkShadowModelThreshold::cRegkShadowModelThreshold()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 7;
    prop.msName = "kShadowModelThreshold";
    prop.mValue = 12.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2bf0
cSC4RenderProperties::cProperties::cRegkDemolishModelThreshold::cRegkDemolishModelThreshold()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 8;
    prop.msName = "kDemolishModelThreshold";
    prop.mValue = 12.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2cd0
cSC4RenderProperties::cProperties::cRegkRenderModelThreshold::cRegkRenderModelThreshold()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 9;
    prop.msName = "kRenderModelThreshold";
    prop.mValue = 6.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2db0
cSC4RenderProperties::cProperties::cRegkRenderModelThresholdScroll::cRegkRenderModelThresholdScroll()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 10;
    prop.msName = "kRenderModelThresholdScroll";
    prop.mValue = 40.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2e90
cSC4RenderProperties::cProperties::cRegkParticleSizeThreshold::cRegkParticleSizeThreshold()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 11;
    prop.msName = "kParticleSizeThreshold";
    prop.mValue = 300.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e2f70
cSC4RenderProperties::cProperties::cRegkMaxVehiclePct::cRegkMaxVehiclePct()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 12;
    prop.msName = "kMaxVehiclePct";
    prop.mValue = 1.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e3050
cSC4RenderProperties::cProperties::cRegkMaxPedPct::cRegkMaxPedPct()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 13;
    prop.msName = "kMaxPedPct";
    prop.mValue = 1.0f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e3130
cSC4RenderProperties::cProperties::cRegkOpaqueUIAlphaValue::cRegkOpaqueUIAlphaValue()
{
    cSC4RenderProperty_ab3b00<float> prop;
    prop.mnId = 14;
    prop.msName = "kOpaqueUIAlphaValue";
    prop.mValue = 0.550000012f;
    prop.mMin = 0.0f;
    prop.mMax = 0.0f;
    gm_floatProperties.push_back(prop);
}

// FUNCTION: 0x007e3210
cSC4RenderProperties::cProperties::cProperties()
{
}
