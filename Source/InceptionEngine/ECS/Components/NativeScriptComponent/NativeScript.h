#pragma once

/*
This class is used in native script component, we write it here, but in the
Runtime, because user need to inherite the class to use native script component,
so this class will be exposed to the dll
*/

#include "EngineGlobals/EngineApiPrefix.h"

#include "ECS/Entity/EntityID.h"

#include "KeyInputTypes.h"



namespace inceptionengine
{
	struct KeyInputCallbackRegistry;
	class Entity;
	class World;
	class WindowHandler;

	class IE_API NativeScript
	{
	public:
		NativeScript(EntityID entityID, std::reference_wrapper<World> world );

		virtual ~NativeScript();

		void BindKeyInputCallback(KeyInputTypes keyType, std::function<void(bool)> callback);

	protected:
		Entity const& GetEntity();

	private:
		/*
		System actually calls OnBegin and callback in KeyInputCallbackRegistry
		*/
		friend class NativeScriptSystem;

		/*
		Component exposes a function "BindKeyInputCallback" that register key input callback
		*/
		friend class NativeScriptComponent;

		virtual void OnBegin() { ; }

		virtual void OnTick(float dt) { ; }

		virtual void OnDestroy() { ; }

		virtual void OnMouseDeltaPos(MouseDeltaPos mouseDeltaPos) { ; }

		std::unique_ptr<KeyInputCallbackRegistry> mKeyInputCallbackRegistry;

		EntityID mEntityID;

		std::reference_wrapper<World> mWorld;


	};

}
