#pragma once

#include "SceneUI.h"

#include <vector>

class SceneUI_Stats;

class SceneUI_Stats : public SceneUI {
public:
    SceneUI_Stats(Scene* scene);

    void AddDeltaTimeSample(float delta);
    void Update() override;

private:
    void CalculateAverage();

    int _maxSamples = 120;
    std::vector<float> _deltaTimeSamples;
    int _sampleIndex = 0;
    float _avgDeltaTime;
};