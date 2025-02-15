#include "ToolTipGUI.h"
#include <string>

REGISTER_COMPONENT(ToolTipGUI);

using namespace Unigine::Math;

template <typename T> string tostr(const T& t) {
	ostringstream os;
	os << t;
	return os.str();
}

void ToolTipGUI::Init() {
	pPlayer = Game::getPlayer();

	pObjGui = checked_ptr_cast<ObjectGui>(node);
	pGui = pObjGui->getGui();

	PhHeight = pObjGui->getPhysicalHeight();
	PhWidth = pObjGui->getPhysicalWidth();

	ui = UserInterface::create(pGui, UI_file);


	pBody = ui->getWidget(ui->findWidget("vbox1"));
	pBody->arrange();
	pGui->addChild(pBody, Gui::ALIGN_OVERLAP | Gui::ALIGN_CENTER);

	pWLabelName = checked_ptr_cast<WidgetLabel>(ui->
				getWidget(ui->findWidget("Object_name")));
	pWLabelDesc = checked_ptr_cast<WidgetLabel>(ui->
				getWidget(ui->findWidget("Object_description")));
	wSprite = checked_ptr_cast<WidgetSprite>(ui->
				getWidget(ui->findWidget("Object_Sprite")));
	pVBox = checked_ptr_cast<WidgetVBox>(ui->
				getWidget(ui->findWidget("vbox1")));

	wSpriteCrosshair = WidgetSprite::create();
	wSpriteCrosshair->setTexture(Crosshair_file);
	wSpriteCrosshair->setWidth(15);
	wSpriteCrosshair->setHeight(15);

	Gui::getCurrent()->
		addChild(wSpriteCrosshair, Gui::ALIGN_OVERLAP | Gui::ALIGN_CENTER);
}

void ToolTipGUI::Update() {
	Mat4 currentModelview = pPlayer->getCamera()->getIModelview();
	
	obj = World::getIntersection(
		pPlayer->getCamera()->getPosition(),
		pPlayer->getCamera()->getPosition() + Unigine::Math::Vec3(
			pPlayer->getRotation().getTangent().x,
			pPlayer->getRotation().getTangent().y,
			-currentModelview.getAxisZ().z) * Math::Vec3(10.0f),
		1,intersection);

	if (obj)
	{
		for (int i = 0; i < obj->getNumSurfaces(); i++)
			obj->setMaterialState("auxiliary", 0, i);
	}

	if (Input::isMouseButtonDown(Input::MOUSE_BUTTON_LEFT) && obj) {
		last_point = intersection->getPoint();
		last_surface = intersection->getSurface();
		last_obj = obj;

		if (last_obj->getSurfaceProperty(last_surface).isNull()) {
			last_obj = NULL;
		}
	}
	if (last_obj && last_obj->getSurfacePropertyName(last_surface) != "") {
		// enable new outline
		last_obj->setMaterialState("auxiliary", 1, last_surface);
		//Console::onscreenWriteLine(obj->getSurfaceName(intersection->getSurface()));
		for (int i = 0; i < last_obj->getNumProperties(); i++) {
			if (String(last_obj->getSurfacePropertyName(i)) == "ToolTip") {
				pWLabelName->setText(last_obj->getSurfaceProperty(last_surface)->
											getParameterPtr("Name")->getValueString());
				string enter = last_obj->getSurfaceProperty(last_surface)->
											getParameterPtr("Description")->getValueString();
				std::string target = "\\n"; // Что ищем
				std::string replacement = "\n"; // На что заменяем
				size_t pos = 0;
				// Пока находим последовательность \\n
				while ((pos = enter.find(target, pos)) != std::string::npos) {
					enter.replace(pos, target.length(), replacement);
					pos += replacement.length(); // Сдвигаемся на длину новой подстроки
				}
				const char* result = enter.c_str();
				pWLabelDesc->setText(result);

				auto property = last_obj->getSurfaceProperty(last_surface);
				auto sprite = property->getParameterPtr("Sprite")->getValueFile();
				sSprite = sprite;
				wSprite->setTexture(sSprite);
				//Log::message("Val: %s")

				String colorValue = last_obj->getSurfaceProperty(last_surface)->
										getParameterPtr("BackgroundColor")->getValueString();
				if (colorValue.size() > 4000 || colorValue.size() < 0) return;
				pVBox->setColor(Math::vec4::parseColor(colorValue));

				pObjGui->setPhysicalSize(
					Math::lerp(pObjGui->getPhysicalWidth(), PhWidth * 5, 5.0f * Game::getIFps()),
					Math::lerp(pObjGui->getPhysicalHeight(), PhHeight * 3.6f, 5.0f * Game::getIFps())
				);

				node->setWorldPosition(
					Math::lerp(node->getWorldPosition(),
						last_point + Vec3(0.0f, 0.0f, 0.2f) - Unigine::Math::Vec3(
							pPlayer->getRotation().getTangent().x,
							pPlayer->getRotation().getTangent().y,
							-currentModelview.getAxisZ().z) * Math::Vec3(0.18f),
						5.0f * Game::getIFps()));
			}
		}

	}
	else {
		pObjGui->setPhysicalSize(
			Math::lerpZero(pObjGui->getPhysicalWidth(), 5.0f * Game::getIFps()),
			Math::lerpZero(pObjGui->getPhysicalHeight(), 5.0f * Game::getIFps())
		);
	}
}