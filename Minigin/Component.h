#pragma once
#include <memory>
#include <string>
#include <SDL3_ttf/SDL_ttf.h>
#include "Transform.h"
#include "Font.h"

namespace dae
{
	class GameObject;
	class Texture2D;
	class BaseComponent
	{
	public:
		BaseComponent(GameObject& owner);

		virtual ~BaseComponent() {}
		BaseComponent(const BaseComponent& comp) = delete;
		BaseComponent(BaseComponent&& comp) = delete;
		BaseComponent& operator=(const BaseComponent& comp) = delete;
		BaseComponent& operator=(BaseComponent&& comp) = delete;


		virtual void Update(const float) {}
		virtual void Render(){}

		//virtual void GetParent();

	protected:
		GameObject& m_owner;
	
	private:
	};
}