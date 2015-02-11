// Copyright © 2008-2015 Pioneer Developers. See AUTHORS.txt for details
// Licensed under the terms of the GPL v3. See licenses/GPL-3.txt

#ifndef _LUASERIALIZER_H
#define _LUASERIALIZER_H

#include "LuaManager.h"
#include "LuaObject.h"
#include "LuaRef.h"
#include "DeleteEmitter.h"
#include "Serializer.h"

class LuaSerializer : public DeleteEmitter {
	friend class LuaObject<LuaSerializer>;
	friend void LuaRef::Save(Serializer::Writer &wr);
	friend void LuaRef::SaveToJson(Json::Value &jsonObj); // npw - new code
	friend void LuaRef::Load(Serializer::Reader &rd);
	friend void LuaRef::LoadFromJson(const Json::Value &jsonObj); // npw - new code

public:
	void Serialize(Serializer::Writer &wr);
	void ToJson(Json::Value &jsonObj); // npw - new code
	void Unserialize(Serializer::Reader &rd);
	void FromJson(const Json::Value &jsonObj); // npw - new code (under construction)
	void InitTableRefs();
	void UninitTableRefs();

private:
	static int l_register(lua_State *l);
	static int l_register_class(lua_State *l);

	static void pickle(lua_State *l, int idx, std::string &out, const char *key = 0);
	static const char *unpickle(lua_State *l, const char *pos);
};

#endif
