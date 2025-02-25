/* Copyright (C) 2005-2025, UNIGINE. All rights reserved.
*
* This file is a part of the UNIGINE 2 SDK.
*
* Your use and / or redistribution of this software in source and / or
* binary form, with or without modification, is subject to: (i) your
* ongoing acceptance of and compliance with the terms and conditions of
* the UNIGINE License Agreement; and (ii) your inclusion of this notice
* in any version of this software that you use or redistribute.
* A copy of the UNIGINE License Agreement is available by contacting
* UNIGINE. at http://unigine.com/
*/
// DO NOT EDIT DIRECTLY. This is an auto-generated file. Your changes will be lost.

#pragma once

#include "UniginePlayers.h"
#include "UnigineWorld.h"

namespace Unigine
{

//////////////////////////////////////////////////////////////////////////

class UNIGINE_API Editor
{
public:
	static bool isInitialized();
	static bool isLoaded();
	static void setEnabled(bool enabled);
	static bool isEnabled();
	static void setData(const char *data);
	static const char *getData();
	static void load(const char *script);
	static void quit();
	static void reload();
	static int needReload();
	static void setPlayer(const Ptr<Player> &player);
	static Ptr<Player> getPlayer();
	static void setVRPlayer(const Ptr<Player> &player);
	static Ptr<Player> getVRPlayer();
	static void addEditorPlayer(const Ptr<Player> &player);
	static void removeEditorPlayer(const Ptr<Player> &player);
	static bool isEditorPlayer(const Ptr<Player> &player);
	static Ptr<Node> getIntersection(const Math::Vec3 &p0, const Math::Vec3 &p1, CallbackBase2<Ptr<Node>, bool *> *node_filter, CallbackBase3<Ptr<Object>, int, bool *> *surface_filter, bool use_handlers = true);
	static Ptr<Node> getIntersection(const Math::Vec3 &p0, const Math::Vec3 &p1, CallbackBase2<Ptr<Node>, bool *> *node_filter, CallbackBase3<Ptr<Object>, int, bool *> *surface_filter, const Ptr<WorldIntersection> &intersection, bool use_handlers = true);
	static Ptr<Node> getIntersection(const Math::Vec3 &p0, const Math::Vec3 &p1, CallbackBase2<Ptr<Node>, bool *> *node_filter, CallbackBase3<Ptr<Object>, int, bool *> *surface_filter, const Ptr<WorldIntersectionNormal> &intersection, bool use_handlers = true);
	static Ptr<Node> getIntersection(const Math::Vec3 &p0, const Math::Vec3 &p1, CallbackBase2<Ptr<Node>, bool *> *node_filter, CallbackBase3<Ptr<Object>, int, bool *> *surface_filter, const Ptr<WorldIntersectionTexCoord> &intersection, bool use_handlers = true);
	static Ptr<Node> getIntersection(const Math::Vec3 &p0, const Math::Vec3 &p1, bool use_handlers = true);
	static Ptr<Node> getIntersection(const Math::Vec3 &p0, const Math::Vec3 &p1, const Ptr<WorldIntersection> &intersection, bool use_handlers = true);
	static Ptr<Node> getIntersection(const Math::Vec3 &p0, const Math::Vec3 &p1, const Ptr<WorldIntersectionNormal> &intersection, bool use_handlers = true);
	static Ptr<Node> getIntersection(const Math::Vec3 &p0, const Math::Vec3 &p1, const Ptr<WorldIntersectionTexCoord> &intersection, bool use_handlers = true);
	static bool getIntersection(const Math::WorldBoundFrustum &bs, Vector<Ptr<Node>> &nodes, bool use_handlers = true);
};

} // namespace Unigine
