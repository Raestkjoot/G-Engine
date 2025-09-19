#include "SceneUI_SceneView.h"

#include "OpenGL/FrameBufferObject.h"

#include <imgui.h>

// TODO: Update size and placement
//       + Background color
void SceneUI_SceneView::Update() {
    ImGui::Begin("Scene");
	{
		ImGui::BeginChild("GameRender");
		
		ImGui::Image(
			(ImTextureID)_fbo->GetFrameTexture(), 
			ImGui::GetContentRegionAvail(), 
			ImVec2(0, 1), 
			ImVec2(1, 0)
		);
	}
	ImGui::EndChild();
	ImGui::End();
}