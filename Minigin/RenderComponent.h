#pragma once
#include "Component.h"

namespace dae
{
	class RenderComponent : public BaseComponent
	{
	public:
		explicit RenderComponent(GameObject& parent);

		virtual void Update() override;
		virtual void Render() override;

		void SetTexture(std::shared_ptr<Texture2D> Texture);

	private:
		Transform m_transform{};
		std::shared_ptr<Texture2D> m_textTexture{};
	};
}