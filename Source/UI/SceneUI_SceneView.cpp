#include "SceneUI_SceneView.h"

#include "OpenGL/FrameBufferObject.h"

#include <imgui.h>


void SceneUI_SceneView::Update() {
    ImGui::Begin("Scene");
	

	_fbo.RescaleFrameBuffer(
		ImGui::GetContentRegionAvail().x,
		ImGui::GetContentRegionAvail().y
	);

	ImGui::Image(
		(ImTextureID)_fbo.GetFrameTexture(), 
		ImGui::GetContentRegionAvail(), 
		ImVec2(0, 1), 
		ImVec2(1, 0)
	);
	
	ImGui::End();
}

void SceneUI_SceneView::BindFrameBuffer() {
	_fbo.Bind();
}

void SceneUI_SceneView::UnbindFrameBuffer() {
	_fbo.Unbind();
}
