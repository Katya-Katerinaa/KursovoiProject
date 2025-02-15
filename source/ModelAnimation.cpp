#include "ModelAnimation.h"
REGISTER_COMPONENT(ModelAnimation);

using namespace std;

void ModelAnimation::Init()
{
	omsPress = static_ptr_cast<ObjectMeshSkinned>(nPress.get());

	omsPress->setLayerFrame(0, 1, 1.0f);
	omsPress->setLayerAnimationFilePath(0, animPath_Razborka);

	pdAnimCamera = static_ptr_cast<PlayerDummy>(AnimCamera.get());

	curGui = Gui::getCurrent();
	wViewport = WidgetSpriteViewport::create(curGui, 300, 300);
	wViewport->setCamera(pdAnimCamera->getCamera());
	curGui->addChild(wViewport, Gui::ALIGN_OVERLAP);
}

void ModelAnimation::Update()
{
	if (Input::isKeyDown(Input::KEY_F)) {
		if (anim_dir == 0) anim_dir = 1;
		else anim_dir = 0;
	}
	if (Input::isKeyDown(Input::KEY_B)) {
		if (anim_dir == 0) anim_dir = -1;
		else anim_dir = 0;
	}

	omsPress->setLayerFrame(0, omsPress->getLayerFrame(0) + 24.0f * Game::getIFps() * anim_dir);
	//Console::writeLine(String::ftoa(omsPress->getFrame(0), 8 ));
	pdAnimCamera->setWorldPosition(omsPress->getBoneWorldTransform(19).getTranslate());
	pdAnimCamera->setWorldRotation(omsPress->
		getBoneWorldTransform(19).getRotate() * Math::quat(-0.0f, 1.0f, 1.0f, 180.0f));

	wViewport->setCamera(pdAnimCamera->getCamera());
}

