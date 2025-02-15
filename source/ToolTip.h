#pragma once
#include "Unigine.h"
#include <UnigineGui.h>
#include <UnigineComponentSystem.h>

using namespace Unigine;

class ToolTip : public Unigine::ComponentBase
{
public:
	COMPONENT_DEFINE(ToolTip, ComponentBase);

	PROP_PARAM(String, Name);
	PROP_PARAM(String, Description);
	PROP_PARAM(File, Sprite);
	PROP_PARAM(String, BackgroundColor, "#B4C3D4");
};

