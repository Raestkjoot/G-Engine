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
	ImGui::Text("FPS:    %.0f", 1000.0f / _avgDeltaTime);
	ImGui::Text("Delta:  %f ms", _avgDeltaTime);
	ImGui::End();
}

void SceneUI_Stats::CalculateAverage() {
    _avgDeltaTime = 0.0f;
    for (int i = 0; i < _maxSamples; ++i) {
        _avgDeltaTime += _deltaTimeSamples[i];
    }
    // Save the average delta time and convert seconds -> milliseconds
    _avgDeltaTime /= _maxSamples * 1000.0f;

}