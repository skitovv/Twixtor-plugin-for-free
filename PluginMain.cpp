#include "AdobeSDKWrapper.h"
#include "FrameInterpolator.h"
#include "GPUAcceleration.h"

class TemporalFXPlugin {
private:
    FrameInterpolator* interpolator;
    GPUAcceleration* gpuAccel;
    PluginConfig config;
    
public:
    TemporalFXPlugin() : interpolator(nullptr), gpuAccel(nullptr) {}
    
    ASErr Initialize() {
        
        interpolator = new FrameInterpolator();
        gpuAccel = new GPUAcceleration();
        
        
        if (!LoadConfig("config/temporal_fx.json")) {
            return kASErrConfiguration;
        }
        
        return kASErrNone;
    }
    
    ASErr ProcessFrames(const FrameSequence& input, FrameSequence& output) {
        
        return interpolator->GenerateIntermediateFrames(input, output);
    }
};