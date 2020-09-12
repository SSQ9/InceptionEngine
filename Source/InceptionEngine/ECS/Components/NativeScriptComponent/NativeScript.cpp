#include "NativeScript.h"

namespace inceptionengine
{
	NativeScript::NativeScript(std::reference_wrapper<Entity const> entity)
		:mEntity(entity)
	{
	}

	void NativeScript::Begin()
	{
		OnBegin();
	}

	void NativeScript::Tick()
	{
		OnTick();
	}
	void NativeScript::Destroy()
	{
		OnDestroy();
	}

	void NativeScript::OnBegin()
	{
	}

	void NativeScript::OnTick()
	{
	}

	void NativeScript::OnDestroy()
	{
	}


}

