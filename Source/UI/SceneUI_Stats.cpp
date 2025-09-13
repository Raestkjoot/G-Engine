#include "SceneUI_Stats.h"

#include <imgui.h>

SceneUI_Stats::SceneUI_Stats(Scene* scene) : SceneUI(scene) {
    _deltaTimeSamples.resize(_maxSamples);
}

void SceneUI_Stats::AddDeltaTimeSample(float delta) {
    _deltaTimeSamples[_sampleIndex++] = delta;

    if (_sampleIndex == _maxSamples) {
        _sampleIndex = 0;
        CalculateAverage();
    }
}

void SceneUI_Stats::Update() {
    ImGui::Begin("Stats");
	ImGui::Text("FPS:    %.0f", 1.0f / _avgDeltaTime);
	ImGui::Text("Delta:  %.4f sec", _avgDeltaTime);
	ImGui::End();
}

void SceneUI_Stats::CalculateAverage() {
    _avgDeltaTime = 0.0f;
    for (int i = 0; i < _maxSamples; ++i) {
        _avgDeltaTime += _deltaTimeSamples[i];
    }

    _avgDeltaTime /= _maxSamples;
}