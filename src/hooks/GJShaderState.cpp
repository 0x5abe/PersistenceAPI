#include "hooks/GJShaderState.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/GJValueTween.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAGJShaderState::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAGJShaderState::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAGJShaderState& o_value) {
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_someIntToValueTweenMap;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_someIntToDoubleMap;
    UMAP_SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_time;
        SEPARATOR_I
        i_stream >> o_value.m_prevTime;
        SEPARATOR_I
        i_stream >> o_value.m_startTime;
        SEPARATOR_I
        i_stream >> o_value.m_textureScaleX;
        SEPARATOR_I
        i_stream >> o_value.m_textureScaleY;
        SEPARATOR_I
        i_stream >> o_value.m_blurRefColor;
        SEPARATOR_I
        i_stream >> o_value.m_blurIntensity;
        SEPARATOR_I
        i_stream >> o_value.m_blurUnk60;
        SEPARATOR_I
        i_stream >> o_value.m_blurOnlyEmpty;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk68;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk6c;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk70;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk74;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk78;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk7c;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk80;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk84;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk88;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveInvert;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk90;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk94;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk98;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk9c;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveCenterMoving;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnk9e;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnka0;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveUnka4;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveCenterDirty;
        SEPARATOR_I
        i_stream >> o_value.m_shockWaveCenter;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkb8;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkc0;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkc4;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkc8;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineAxis;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineDirection;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineDual;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkcf;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkd0;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkd4;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkd8;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkdc;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnke0;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnke4;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnke8;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkec;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineCenterMoving;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkee;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkf0;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineUnkf4;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineCenterDirty;
        SEPARATOR_I
        i_stream >> o_value.m_shockLineCenter;
        SEPARATOR_I
        i_stream >> o_value.m_glitchUnk108;
        SEPARATOR_I
        i_stream >> o_value.m_glitchUnk10c;
        SEPARATOR_I
        i_stream >> o_value.m_glitchUnk110;
        SEPARATOR_I
        i_stream >> o_value.m_glitchUnk114;
        SEPARATOR_I
        i_stream >> o_value.m_glitchUnk118;
        SEPARATOR_I
        i_stream >> o_value.m_glitchUnk11c;
        SEPARATOR_I
        i_stream >> o_value.m_glitchUnk120;
        SEPARATOR_I
        i_stream >> o_value.m_chromaticUnk124;
        SEPARATOR_I
        i_stream >> o_value.m_chromaticUnk128;
        SEPARATOR_I
        i_stream >> o_value.m_chromaticUnk12c;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk130;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk134;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk138;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk13c;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk140;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk144;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk148;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk14c;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk150;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk151;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk152;
        SEPARATOR_I
        i_stream >> o_value.m_cGUnk153;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateTargetX;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateTargetY;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateSnapGrid;
        SEPARATOR_I
        i_stream >> o_value.m_pixelatePixelating;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateRelative;
        SEPARATOR_I
        i_stream >> o_value.m_pixelateHardEdges;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleUnk160;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleUnk164;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleStrength;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleUnk16c;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleUnk170;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleUnk174;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleAdditive;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleTintR;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleTintG;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleTintB;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleUnk17c;
        SEPARATOR_I
        i_stream >> o_value.m_lensCircleUnk184;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurUnk18c;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurUnk190;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurUnk194;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurUnk198;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurUnk19c;
        SEPARATOR_I
        i_stream >> o_value.m_radialBlurUnk1a4;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurUnk1ac;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurUnk1b0;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurSpeedX;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurSpeedY;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurUnk1bc;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurUnk1c0;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurUnk1c4;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurUnk1c8;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurDual;
        SEPARATOR_I
        i_stream >> o_value.m_motionBlurUnk1cd;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeValue;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeUnk1d4;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeUnk1d8;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeRadius;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeUnk1e0;
        SEPARATOR_I
        i_stream >> o_value.m_bulgeUnk1e8;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk1f0;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk1f4;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk1f8;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk1f9;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk1fc;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk200;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk204;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk20c;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk214;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk218;
        SEPARATOR_I
        i_stream >> o_value.m_pinchUnk21c;
        SEPARATOR_I
        i_stream >> o_value.m_grayscaleValue;
        SEPARATOR_I
        i_stream >> o_value.m_grayscaleUseLum;
        SEPARATOR_I
        i_stream >> o_value.m_grayscaleUnk22c;
        SEPARATOR_I
        i_stream >> o_value.m_grayscaleTint;
        SEPARATOR_I
        i_stream >> o_value.m_sepiaValue;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorEditRGB;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorR;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorG;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorB;
        SEPARATOR_I
        i_stream >> o_value.m_invertColorClampRGB;
        SEPARATOR_I
        i_stream >> o_value.m_hueShiftDegrees;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeCR;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeCG;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeCB;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeBR;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeBG;
        SEPARATOR_I
        i_stream >> o_value.m_colorChangeBB;
        SEPARATOR_I
        i_stream >> o_value.m_splitUnk268;
        SEPARATOR_I
        i_stream >> o_value.m_splitUnk26c;
        SEPARATOR_I
        i_stream >> o_value.m_splitUnk270;
        SEPARATOR_I
        i_stream >> o_value.m_minBlendingLayer;
        SEPARATOR_I
        i_stream >> o_value.m_maxBlendingLayer;
        SEPARATOR_I
        i_stream >> o_value.m_zLayerDirty;
        SEPARATOR_I
        i_stream >> o_value.m_somethingZLayerUnk27d;
        SEPARATOR_I
        i_stream >> o_value.m_usesShaders;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAGJShaderState,m_someIntToDoubleMap) + sizeof(gd::unordered_map<int, double>), 584);
    }
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAGJShaderState& i_value) {
    UMAP_SEPARATOR_O
    o_stream << i_value.m_someIntToValueTweenMap;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_someIntToDoubleMap;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_time;
    SEPARATOR_O
    o_stream << i_value.m_prevTime;
    SEPARATOR_O
    o_stream << i_value.m_startTime;
    SEPARATOR_O
    o_stream << i_value.m_textureScaleX;
    SEPARATOR_O
    o_stream << i_value.m_textureScaleY;
    SEPARATOR_O
    o_stream << i_value.m_blurRefColor;
    SEPARATOR_O
    o_stream << i_value.m_blurIntensity;
    SEPARATOR_O
    o_stream << i_value.m_blurUnk60;
    SEPARATOR_O
    o_stream << i_value.m_blurOnlyEmpty;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk68;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk6c;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk70;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk74;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk78;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk7c;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk80;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk84;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk88;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveInvert;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk90;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk94;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk98;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk9c;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveCenterMoving;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnk9e;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnka0;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveUnka4;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveCenterDirty;
    SEPARATOR_O
    o_stream << i_value.m_shockWaveCenter;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkb8;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkc0;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkc4;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkc8;
    SEPARATOR_O
    o_stream << i_value.m_shockLineAxis;
    SEPARATOR_O
    o_stream << i_value.m_shockLineDirection;
    SEPARATOR_O
    o_stream << i_value.m_shockLineDual;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkcf;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkd0;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkd4;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkd8;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkdc;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnke0;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnke4;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnke8;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkec;
    SEPARATOR_O
    o_stream << i_value.m_shockLineCenterMoving;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkee;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkf0;
    SEPARATOR_O
    o_stream << i_value.m_shockLineUnkf4;
    SEPARATOR_O
    o_stream << i_value.m_shockLineCenterDirty;
    SEPARATOR_O
    o_stream << i_value.m_shockLineCenter;
    SEPARATOR_O
    o_stream << i_value.m_glitchUnk108;
    SEPARATOR_O
    o_stream << i_value.m_glitchUnk10c;
    SEPARATOR_O
    o_stream << i_value.m_glitchUnk110;
    SEPARATOR_O
    o_stream << i_value.m_glitchUnk114;
    SEPARATOR_O
    o_stream << i_value.m_glitchUnk118;
    SEPARATOR_O
    o_stream << i_value.m_glitchUnk11c;
    SEPARATOR_O
    o_stream << i_value.m_glitchUnk120;
    SEPARATOR_O
    o_stream << i_value.m_chromaticUnk124;
    SEPARATOR_O
    o_stream << i_value.m_chromaticUnk128;
    SEPARATOR_O
    o_stream << i_value.m_chromaticUnk12c;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk130;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk134;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk138;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk13c;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk140;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk144;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk148;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk14c;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk150;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk151;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk152;
    SEPARATOR_O
    o_stream << i_value.m_cGUnk153;
    SEPARATOR_O
    o_stream << i_value.m_pixelateTargetX;
    SEPARATOR_O
    o_stream << i_value.m_pixelateTargetY;
    SEPARATOR_O
    o_stream << i_value.m_pixelateSnapGrid;
    SEPARATOR_O
    o_stream << i_value.m_pixelatePixelating;
    SEPARATOR_O
    o_stream << i_value.m_pixelateRelative;
    SEPARATOR_O
    o_stream << i_value.m_pixelateHardEdges;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleUnk160;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleUnk164;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleStrength;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleUnk16c;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleUnk170;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleUnk174;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleAdditive;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleTintR;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleTintG;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleTintB;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleUnk17c;
    SEPARATOR_O
    o_stream << i_value.m_lensCircleUnk184;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurUnk18c;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurUnk190;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurUnk194;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurUnk198;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurUnk19c;
    SEPARATOR_O
    o_stream << i_value.m_radialBlurUnk1a4;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurUnk1ac;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurUnk1b0;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurSpeedX;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurSpeedY;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurUnk1bc;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurUnk1c0;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurUnk1c4;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurUnk1c8;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurDual;
    SEPARATOR_O
    o_stream << i_value.m_motionBlurUnk1cd;
    SEPARATOR_O
    o_stream << i_value.m_bulgeValue;
    SEPARATOR_O
    o_stream << i_value.m_bulgeUnk1d4;
    SEPARATOR_O
    o_stream << i_value.m_bulgeUnk1d8;
    SEPARATOR_O
    o_stream << i_value.m_bulgeRadius;
    SEPARATOR_O
    o_stream << i_value.m_bulgeUnk1e0;
    SEPARATOR_O
    o_stream << i_value.m_bulgeUnk1e8;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk1f0;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk1f4;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk1f8;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk1f9;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk1fc;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk200;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk204;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk20c;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk214;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk218;
    SEPARATOR_O
    o_stream << i_value.m_pinchUnk21c;
    SEPARATOR_O
    o_stream << i_value.m_grayscaleValue;
    SEPARATOR_O
    o_stream << i_value.m_grayscaleUseLum;
    SEPARATOR_O
    o_stream << i_value.m_grayscaleUnk22c;
    SEPARATOR_O
    o_stream << i_value.m_grayscaleTint;
    SEPARATOR_O
    o_stream << i_value.m_sepiaValue;
    SEPARATOR_O
    o_stream << i_value.m_invertColorEditRGB;
    SEPARATOR_O
    o_stream << i_value.m_invertColorR;
    SEPARATOR_O
    o_stream << i_value.m_invertColorG;
    SEPARATOR_O
    o_stream << i_value.m_invertColorB;
    SEPARATOR_O
    o_stream << i_value.m_invertColorClampRGB;
    SEPARATOR_O
    o_stream << i_value.m_hueShiftDegrees;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeCR;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeCG;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeCB;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeBR;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeBG;
    SEPARATOR_O
    o_stream << i_value.m_colorChangeBB;
    SEPARATOR_O
    o_stream << i_value.m_splitUnk268;
    SEPARATOR_O
    o_stream << i_value.m_splitUnk26c;
    SEPARATOR_O
    o_stream << i_value.m_splitUnk270;
    SEPARATOR_O
    o_stream << i_value.m_minBlendingLayer;
    SEPARATOR_O
    o_stream << i_value.m_maxBlendingLayer;
    SEPARATOR_O
    o_stream << i_value.m_zLayerDirty;
    SEPARATOR_O
    o_stream << i_value.m_somethingZLayerUnk27d;
    SEPARATOR_O
    o_stream << i_value.m_usesShaders;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAGJShaderState::describe() {
    int l_size = m_someIntToValueTweenMap.size();
    log::info("[PAGJShaderState - describe] m_someIntToValueTweenMap.size(): {}", l_size);
    int i = 0;
    for (std::pair<int,GJValueTween> l_pair : m_someIntToValueTweenMap) {
        log::info("[PAGJShaderState - describe] m_someIntToValueTweenMap element {} key: {}", i, l_pair.first);
        log::info("[PAGJShaderState - describe] m_someIntToValueTweenMap element {} value:", i);
        reinterpret_cast<PAGJValueTween*>(&l_pair.second)->describe();
        i++;
    }
    i = 0;
    l_size = m_someIntToDoubleMap.size();
    log::info("[PAGJShaderState - describe] m_someIntToDoubleMap.size(): {}", l_size);
    for (std::pair<int,double> l_pair : m_someIntToDoubleMap) {
        log::info("[PAGJShaderState - describe] m_someIntToDoubleMap element {} key: {}", i, l_pair.first);
        log::info("[PAGJShaderState - describe] m_someIntToDoubleMap element {} value: [{}]", i, l_pair.second);
        i++;
    }
    log::info("[PAGJShaderState - describe] m_time: {}", m_time);
    log::info("[PAGJShaderState - describe] m_prevTime: {}", m_prevTime);
    log::info("[PAGJShaderState - describe] m_startTime: {}", m_startTime);
    log::info("[PAGJShaderState - describe] m_textureScaleX: {}", m_textureScaleX);
    log::info("[PAGJShaderState - describe] m_textureScaleY: {}", m_textureScaleY);
    log::info("[PAGJShaderState - describe] m_blurRefColor: {}", m_blurRefColor);
    log::info("[PAGJShaderState - describe] m_blurIntensity: {}", m_blurIntensity);
    log::info("[PAGJShaderState - describe] m_blurUnk60: {}", m_blurUnk60);
    log::info("[PAGJShaderState - describe] m_blurOnlyEmpty: {}", m_blurOnlyEmpty);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk68: {}", m_shockWaveUnk68);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk6c: {}", m_shockWaveUnk6c);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk70: {}", m_shockWaveUnk70);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk74: {}", m_shockWaveUnk74);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk78: {}", m_shockWaveUnk78);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk7c: {}", m_shockWaveUnk7c);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk80: {}", m_shockWaveUnk80);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk84: {}", m_shockWaveUnk84);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk88: {}", m_shockWaveUnk88);
    log::info("[PAGJShaderState - describe] m_shockWaveInvert: {}", m_shockWaveInvert);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk90: {}", m_shockWaveUnk90);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk94: {}", m_shockWaveUnk94);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk98: {}", m_shockWaveUnk98);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk9c: {}", m_shockWaveUnk9c);
    log::info("[PAGJShaderState - describe] m_shockWaveCenterMoving: {}", m_shockWaveCenterMoving);
    log::info("[PAGJShaderState - describe] m_shockWaveUnk9e: {}", m_shockWaveUnk9e);
    log::info("[PAGJShaderState - describe] m_shockWaveUnka0: {}", m_shockWaveUnka0);
    log::info("[PAGJShaderState - describe] m_shockWaveUnka4: {}", m_shockWaveUnka4);
    log::info("[PAGJShaderState - describe] m_shockWaveCenterDirty: {}", m_shockWaveCenterDirty);
    log::info("[PAGJShaderState - describe] m_shockWaveCenter: {}", m_shockWaveCenter);
    log::info("[PAGJShaderState - describe] m_shockLineUnkb8: {}", m_shockLineUnkb8);
    log::info("[PAGJShaderState - describe] m_shockLineUnkc0: {}", m_shockLineUnkc0);
    log::info("[PAGJShaderState - describe] m_shockLineUnkc4: {}", m_shockLineUnkc4);
    log::info("[PAGJShaderState - describe] m_shockLineUnkc8: {}", m_shockLineUnkc8);
    log::info("[PAGJShaderState - describe] m_shockLineAxis: {}", m_shockLineAxis);
    log::info("[PAGJShaderState - describe] m_shockLineDirection: {}", m_shockLineDirection);
    log::info("[PAGJShaderState - describe] m_shockLineDual: {}", m_shockLineDual);
    log::info("[PAGJShaderState - describe] m_shockLineUnkcf: {}", m_shockLineUnkcf);
    log::info("[PAGJShaderState - describe] m_shockLineUnkd0: {}", m_shockLineUnkd0);
    log::info("[PAGJShaderState - describe] m_shockLineUnkd4: {}", m_shockLineUnkd4);
    log::info("[PAGJShaderState - describe] m_shockLineUnkd8: {}", m_shockLineUnkd8);
    log::info("[PAGJShaderState - describe] m_shockLineUnkdc: {}", m_shockLineUnkdc);
    log::info("[PAGJShaderState - describe] m_shockLineUnke0: {}", m_shockLineUnke0);
    log::info("[PAGJShaderState - describe] m_shockLineUnke4: {}", m_shockLineUnke4);
    log::info("[PAGJShaderState - describe] m_shockLineUnke8: {}", m_shockLineUnke8);
    log::info("[PAGJShaderState - describe] m_shockLineUnkec: {}", m_shockLineUnkec);
    log::info("[PAGJShaderState - describe] m_shockLineCenterMoving: {}", m_shockLineCenterMoving);
    log::info("[PAGJShaderState - describe] m_shockLineUnkee: {}", m_shockLineUnkee);
    log::info("[PAGJShaderState - describe] m_shockLineUnkf0: {}", m_shockLineUnkf0);
    log::info("[PAGJShaderState - describe] m_shockLineUnkf4: {}", m_shockLineUnkf4);
    log::info("[PAGJShaderState - describe] m_shockLineCenterDirty: {}", m_shockLineCenterDirty);
    log::info("[PAGJShaderState - describe] m_shockLineCenter: {}", m_shockLineCenter);
    log::info("[PAGJShaderState - describe] m_glitchUnk108: {}", m_glitchUnk108);
    log::info("[PAGJShaderState - describe] m_glitchUnk10c: {}", m_glitchUnk10c);
    log::info("[PAGJShaderState - describe] m_glitchUnk110: {}", m_glitchUnk110);
    log::info("[PAGJShaderState - describe] m_glitchUnk114: {}", m_glitchUnk114);
    log::info("[PAGJShaderState - describe] m_glitchUnk118: {}", m_glitchUnk118);
    log::info("[PAGJShaderState - describe] m_glitchUnk11c: {}", m_glitchUnk11c);
    log::info("[PAGJShaderState - describe] m_glitchUnk120: {}", m_glitchUnk120);
    log::info("[PAGJShaderState - describe] m_chromaticUnk124: {}", m_chromaticUnk124);
    log::info("[PAGJShaderState - describe] m_chromaticUnk128: {}", m_chromaticUnk128);
    log::info("[PAGJShaderState - describe] m_chromaticUnk12c: {}", m_chromaticUnk12c);
    log::info("[PAGJShaderState - describe] m_cGUnk130: {}", m_cGUnk130);
    log::info("[PAGJShaderState - describe] m_cGUnk134: {}", m_cGUnk134);
    log::info("[PAGJShaderState - describe] m_cGUnk138: {}", m_cGUnk138);
    log::info("[PAGJShaderState - describe] m_cGUnk13c: {}", m_cGUnk13c);
    log::info("[PAGJShaderState - describe] m_cGUnk140: {}", m_cGUnk140);
    log::info("[PAGJShaderState - describe] m_cGUnk144: {}", m_cGUnk144);
    log::info("[PAGJShaderState - describe] m_cGUnk148: {}", m_cGUnk148);
    log::info("[PAGJShaderState - describe] m_cGUnk14c: {}", m_cGUnk14c);
    log::info("[PAGJShaderState - describe] m_cGUnk150: {}", m_cGUnk150);
    log::info("[PAGJShaderState - describe] m_cGUnk151: {}", m_cGUnk151);
    log::info("[PAGJShaderState - describe] m_cGUnk152: {}", m_cGUnk152);
    log::info("[PAGJShaderState - describe] m_cGUnk153: {}", m_cGUnk153);
    log::info("[PAGJShaderState - describe] m_pixelateTargetX: {}", m_pixelateTargetX);
    log::info("[PAGJShaderState - describe] m_pixelateTargetY: {}", m_pixelateTargetY);
    log::info("[PAGJShaderState - describe] m_pixelateSnapGrid: {}", m_pixelateSnapGrid);
    log::info("[PAGJShaderState - describe] m_pixelatePixelating: {}", m_pixelatePixelating);
    log::info("[PAGJShaderState - describe] m_pixelateRelative: {}", m_pixelateRelative);
    log::info("[PAGJShaderState - describe] m_pixelateHardEdges: {}", m_pixelateHardEdges);
    log::info("[PAGJShaderState - describe] m_lensCircleUnk160: {}", m_lensCircleUnk160);
    log::info("[PAGJShaderState - describe] m_lensCircleUnk164: {}", m_lensCircleUnk164);
    log::info("[PAGJShaderState - describe] m_lensCircleStrength: {}", m_lensCircleStrength);
    log::info("[PAGJShaderState - describe] m_lensCircleUnk16c: {}", m_lensCircleUnk16c);
    log::info("[PAGJShaderState - describe] m_lensCircleUnk170: {}", m_lensCircleUnk170);
    log::info("[PAGJShaderState - describe] m_lensCircleUnk174: {}", m_lensCircleUnk174);
    log::info("[PAGJShaderState - describe] m_lensCircleAdditive: {}", m_lensCircleAdditive);
    log::info("[PAGJShaderState - describe] m_lensCircleTintR: {}", static_cast<uint8_t>(m_lensCircleTintR));
    log::info("[PAGJShaderState - describe] m_lensCircleTintG: {}", static_cast<uint8_t>(m_lensCircleTintG));
    log::info("[PAGJShaderState - describe] m_lensCircleTintB: {}", static_cast<uint8_t>(m_lensCircleTintB));
    log::info("[PAGJShaderState - describe] m_lensCircleUnk17c: {}", m_lensCircleUnk17c);
    log::info("[PAGJShaderState - describe] m_lensCircleUnk184: {}", m_lensCircleUnk184);
    log::info("[PAGJShaderState - describe] m_radialBlurUnk18c: {}", m_radialBlurUnk18c);
    log::info("[PAGJShaderState - describe] m_radialBlurUnk190: {}", m_radialBlurUnk190);
    log::info("[PAGJShaderState - describe] m_radialBlurUnk194: {}", m_radialBlurUnk194);
    log::info("[PAGJShaderState - describe] m_radialBlurUnk198: {}", m_radialBlurUnk198);
    log::info("[PAGJShaderState - describe] m_radialBlurUnk19c: {}", m_radialBlurUnk19c);
    log::info("[PAGJShaderState - describe] m_radialBlurUnk1a4: {}", m_radialBlurUnk1a4);
    log::info("[PAGJShaderState - describe] m_motionBlurUnk1ac: {}", m_motionBlurUnk1ac);
    log::info("[PAGJShaderState - describe] m_motionBlurUnk1b0: {}", m_motionBlurUnk1b0);
    log::info("[PAGJShaderState - describe] m_motionBlurSpeedX: {}", m_motionBlurSpeedX);
    log::info("[PAGJShaderState - describe] m_motionBlurSpeedY: {}", m_motionBlurSpeedY);
    log::info("[PAGJShaderState - describe] m_motionBlurUnk1bc: {}", m_motionBlurUnk1bc);
    log::info("[PAGJShaderState - describe] m_motionBlurUnk1c0: {}", m_motionBlurUnk1c0);
    log::info("[PAGJShaderState - describe] m_motionBlurUnk1c4: {}", m_motionBlurUnk1c4);
    log::info("[PAGJShaderState - describe] m_motionBlurUnk1c8: {}", m_motionBlurUnk1c8);
    log::info("[PAGJShaderState - describe] m_motionBlurDual: {}", m_motionBlurDual);
    log::info("[PAGJShaderState - describe] m_motionBlurUnk1cd: {}", m_motionBlurUnk1cd);
    log::info("[PAGJShaderState - describe] m_bulgeValue: {}", m_bulgeValue);
    log::info("[PAGJShaderState - describe] m_bulgeUnk1d4: {}", m_bulgeUnk1d4);
    log::info("[PAGJShaderState - describe] m_bulgeUnk1d8: {}", m_bulgeUnk1d8);
    log::info("[PAGJShaderState - describe] m_bulgeRadius: {}", m_bulgeRadius);
    log::info("[PAGJShaderState - describe] m_bulgeUnk1e0: {}", m_bulgeUnk1e0);
    log::info("[PAGJShaderState - describe] m_bulgeUnk1e8: {}", m_bulgeUnk1e8);
    log::info("[PAGJShaderState - describe] m_pinchUnk1f0: {}", m_pinchUnk1f0);
    log::info("[PAGJShaderState - describe] m_pinchUnk1f4: {}", m_pinchUnk1f4);
    log::info("[PAGJShaderState - describe] m_pinchUnk1f8: {}", m_pinchUnk1f8);
    log::info("[PAGJShaderState - describe] m_pinchUnk1f9: {}", m_pinchUnk1f9);
    log::info("[PAGJShaderState - describe] m_pinchUnk1fc: {}", m_pinchUnk1fc);
    log::info("[PAGJShaderState - describe] m_pinchUnk200: {}", m_pinchUnk200);
    log::info("[PAGJShaderState - describe] m_pinchUnk204: {}", m_pinchUnk204);
    log::info("[PAGJShaderState - describe] m_pinchUnk20c: {}", m_pinchUnk20c);
    log::info("[PAGJShaderState - describe] m_pinchUnk214: {}", m_pinchUnk214);
    log::info("[PAGJShaderState - describe] m_pinchUnk218: {}", m_pinchUnk218);
    log::info("[PAGJShaderState - describe] m_pinchUnk21c: {}", m_pinchUnk21c);
    log::info("[PAGJShaderState - describe] m_grayscaleValue: {}", m_grayscaleValue);
    log::info("[PAGJShaderState - describe] m_grayscaleUseLum: {}", m_grayscaleUseLum);
    log::info("[PAGJShaderState - describe] m_grayscaleUnk22c: {}", m_grayscaleUnk22c);
    log::info("[PAGJShaderState - describe] m_grayscaleTint: {}", m_grayscaleTint);
    log::info("[PAGJShaderState - describe] m_sepiaValue: {}", m_sepiaValue);
    log::info("[PAGJShaderState - describe] m_invertColorEditRGB: {}", m_invertColorEditRGB);
    log::info("[PAGJShaderState - describe] m_invertColorR: {}", m_invertColorR);
    log::info("[PAGJShaderState - describe] m_invertColorG: {}", m_invertColorG);
    log::info("[PAGJShaderState - describe] m_invertColorB: {}", m_invertColorB);
    log::info("[PAGJShaderState - describe] m_invertColorClampRGB: {}", m_invertColorClampRGB);
    log::info("[PAGJShaderState - describe] m_hueShiftDegrees: {}", m_hueShiftDegrees);
    log::info("[PAGJShaderState - describe] m_colorChangeCR: {}", m_colorChangeCR);
    log::info("[PAGJShaderState - describe] m_colorChangeCG: {}", m_colorChangeCG);
    log::info("[PAGJShaderState - describe] m_colorChangeCB: {}", m_colorChangeCB);
    log::info("[PAGJShaderState - describe] m_colorChangeBR: {}", m_colorChangeBR);
    log::info("[PAGJShaderState - describe] m_colorChangeBG: {}", m_colorChangeBG);
    log::info("[PAGJShaderState - describe] m_colorChangeBB: {}", m_colorChangeBB);
    log::info("[PAGJShaderState - describe] m_splitUnk268: {}", m_splitUnk268);
    log::info("[PAGJShaderState - describe] m_splitUnk26c: {}", m_splitUnk26c);
    log::info("[PAGJShaderState - describe] m_splitUnk270: {}", m_splitUnk270);
    log::info("[PAGJShaderState - describe] m_minBlendingLayer: {}", m_minBlendingLayer);
    log::info("[PAGJShaderState - describe] m_maxBlendingLayer: {}", m_maxBlendingLayer);
    log::info("[PAGJShaderState - describe] m_zLayerDirty: {}", m_zLayerDirty);
    log::info("[PAGJShaderState - describe] m_somethingZLayerUnk27d: {}", m_somethingZLayerUnk27d);
    log::info("[PAGJShaderState - describe] m_usesShaders: {}", m_usesShaders);
}
#endif