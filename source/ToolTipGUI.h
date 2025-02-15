#pragma once
#include "Unigine.h"
#include <UnigineWidgets.h>
#include <UnigineGui.h>

using namespace Unigine;
using namespace std;

class ToolTipGUI : public Unigine::ComponentBase
{
public:
	COMPONENT_DEFINE(ToolTipGUI, ComponentBase);

	COMPONENT_INIT(Init);
	COMPONENT_UPDATE(Update);

	PROP_PARAM(File, UI_file);
	PROP_PARAM(File, Crosshair_file);

	ObjectGuiPtr pObjGui;
	GuiPtr pGui;
	WidgetPtr pBody;
	UserInterfacePtr ui;

	WidgetLabelPtr pWLabelName, pWLabelDesc;
	WidgetVBoxPtr pVBox;
	PlayerPtr pPlayer;


	WorldIntersectionPtr intersection = WorldIntersection::create();
	ObjectPtr obj = NULL;

	Unigine::Math::Vec3 last_point;
	int last_surface = 0;
	ObjectPtr last_obj = NULL;
	float PhWidth, PhHeight;

	WidgetSpritePtr wSpriteCrosshair;

	ComponentVariableFile fFileSprite;
	WidgetSpritePtr wSprite;
	String sSprite;

protected:
	void Init();
	void Update();
};

