#include "AppWorldLogic.h"
#include <UnigineComponentSystem.h>
#include "UnigineConsole.h"
#include "UnigineVisualizer.h"

using namespace Unigine;

AppWorldLogic::AppWorldLogic()
{}

AppWorldLogic::~AppWorldLogic()
{}

int AppWorldLogic::init()
{
	Unigine::Console::setOnscreen(false);
	Unigine::Console::setMessageColor(Unigine::Math::vec4_green);
	Unigine::Console::setWarningColor(Unigine::Math::vec4_red);
	Unigine::Console::setErrorColor(Unigine::Math::vec4_blue);
	ComponentSystem::get()->initialize();
	World::setUnpackNodeReferences(true);	
	return 1;
}

int AppWorldLogic::update()
{
	return 1;
}

int AppWorldLogic::postUpdate()
{
	return 1;
}

int AppWorldLogic::updatePhysics()
{
	return 1;
}


int AppWorldLogic::shutdown()
{
	return 1;
}

int AppWorldLogic::save(const Unigine::StreamPtr &stream)
{
	UNIGINE_UNUSED(stream);
	return 1;
}

int AppWorldLogic::restore(const Unigine::StreamPtr &stream)
{
	// Write here code to be called when the world is restoring its state (i.e. state_restore is called): restore custom user data to a file here.
	UNIGINE_UNUSED(stream);
	return 1;
}
