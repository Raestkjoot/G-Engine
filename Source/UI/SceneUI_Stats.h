#pragma once

#include <vector>

class SceneUI_Stats;

class SceneUI_Stats {
public:
    SceneUI_Stats();

    void AddDeltaTimeSample(float delta);
    void Update();

private:
    void CalculateAverage();

    int _maxSamples = 20;
    std::vector<float> _deltaTimeSamples;
    int _sampleIndex = 0;
    float _avgDeltaTime;
};