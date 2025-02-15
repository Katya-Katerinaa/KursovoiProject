#pragma once
#include "Unigine.h"

using namespace Unigine;

class ModelAnimation : public Unigine::ComponentBase
{
public:
	COMPONENT_DEFINE(ModelAnimation, ComponentBase);
	
	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);

	PROP_PARAM(Node, nPress);
	PROP_PARAM(File, animPath_Razborka);
	PROP_PARAM(Node, AnimCamera);

	PlayerDummyPtr pdAnimCamera = NULL;
	Unigine::ObjectMeshSkinnedPtr omsPress = NULL;
	
	GuiPtr curGui;
	WidgetSpriteViewportPtr wViewport;

	int anim_dir = 0;
	

protected:
	void Update(),
		Init();

};

